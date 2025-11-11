
#ifdef _WIN32

#include "WebKitWebView.h"
#include <windows.h>
#include <wrl.h>
#include "WebView2.h"
#include <gdk/gdkwin32.h>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <vector>

using namespace Microsoft::WRL;

// WebView2 implementation for Windows
// This provides the same API as WebKitWebView but uses Microsoft Edge WebView2

// Helper structure to store WebView2 state
struct WebView2State
{
    ComPtr<ICoreWebView2Controller> controller;
    ComPtr<ICoreWebView2> webview;
    HWND hwnd;
    std::string current_uri;
    std::string current_title;
    std::string pending_uri;                  // URI to load once WebView is initialized
    std::string pending_html;                 // HTML to load once WebView is initialized
    std::vector<std::string> pending_scripts; // Scripts to run once WebView is initialized
    std::string user_data_folder;             // Custom user data folder path
    std::wstring user_data_folder_wide;       // Wide string version for async WebView2 creation
    bool is_loading;
    std::map<std::string, Php::Value> message_handlers;
    gulong realize_signal_handler_id; // Signal handler ID for cleanup

    WebView2State() : hwnd(nullptr), is_loading(false), realize_signal_handler_id(0) {}
};

static std::map<gpointer *, WebView2State *> webview_states;

// Helper to get WebView2 state for a widget
static WebView2State *get_webview_state(gpointer *instance)
{
    auto it = webview_states.find(instance);
    if (it != webview_states.end())
    {
        return it->second;
    }
    return nullptr;
}

// Helper to validate handler names: only allow [A-Za-z0-9_]
static bool is_valid_handler_name(const std::string &name)
{
    return !name.empty() && std::all_of(name.begin(), name.end(), [](char c)
                                        { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c == '_'); });
}

// Callback when widget is realized and we have a window handle
static void on_widget_realized(GtkWidget *widget, gpointer user_data)
{
    WebView2State *state = (WebView2State *)user_data;

    // Get the GDK window
    GdkWindow *gdk_window = gtk_widget_get_window(widget);
    if (!gdk_window)
    {
        g_warning("WebView2: Failed to get GDK window");
        return;
    }

// Get native Windows HWND
#ifdef GDK_WINDOWING_WIN32
    state->hwnd = (HWND)gdk_win32_window_get_handle(gdk_window);
#else
    g_warning("WebView2: Not compiled with GDK Win32 support");
    return;
#endif

    if (!state->hwnd)
    {
        g_warning("WebView2: Failed to get HWND");
        return;
    }

    // Create WebView2 environment (async)
    // Use custom user data folder if set, otherwise default to ./tmp
    // Store wide string in state to ensure lifetime for async callback
    const wchar_t *userDataFolder = nullptr;
    std::string folder_path = state->user_data_folder.empty() ? "./tmp" : state->user_data_folder;

    int required_size = MultiByteToWideChar(CP_UTF8, 0, folder_path.c_str(), -1, nullptr, 0);
    if (required_size > 0)
    {
        state->user_data_folder_wide.resize(required_size);
        MultiByteToWideChar(CP_UTF8, 0, folder_path.c_str(), -1, &state->user_data_folder_wide[0], required_size);
        userDataFolder = state->user_data_folder_wide.c_str();
    }

    CreateCoreWebView2EnvironmentWithOptions(
        nullptr, userDataFolder, nullptr,
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>([state](HRESULT result,
                                                                                     ICoreWebView2Environment *env)
                                                                                 -> HRESULT
                                                                             {
            if (FAILED(result)) {
                g_warning("WebView2: Failed to create environment: 0x%lx", result);
                return result;
            }

            // Create controller (async)
            env->CreateCoreWebView2Controller(
                state->hwnd,
                Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>([state](HRESULT result,
                                                                                            ICoreWebView2Controller *
                                                                                                controller) -> HRESULT {
                    if (FAILED(result)) {
                        g_warning("WebView2: Failed to create controller: 0x%lx", result);
                        return result;
                    }

                    state->controller = controller;
                    controller->get_CoreWebView2(&state->webview);

                    // Set bounds to fill parent
                    RECT bounds;
                    GetClientRect(state->hwnd, &bounds);
                    controller->put_Bounds(bounds);

                    // Register for navigation events
                    state->webview->add_NavigationStarting(
                        Callback<ICoreWebView2NavigationStartingEventHandler>(
                            [state](ICoreWebView2 *sender, ICoreWebView2NavigationStartingEventArgs *args) -> HRESULT {
                                state->is_loading = true;
                                LPWSTR uri;
                                args->get_Uri(&uri);
                                if (uri) {
                                    int required_size =
                                        WideCharToMultiByte(CP_UTF8, 0, uri, -1, nullptr, 0, nullptr, nullptr);
                                    if (required_size > 0) {
                                        std::vector<char> buffer(required_size);
                                        WideCharToMultiByte(CP_UTF8, 0, uri, -1, buffer.data(), required_size, nullptr,
                                                            nullptr);
                                        state->current_uri = std::string(buffer.data());
                                    }
                                    CoTaskMemFree(uri);
                                }
                                return S_OK;
                            })
                            .Get(),
                        nullptr);

                    state->webview->add_NavigationCompleted(
                        Callback<ICoreWebView2NavigationCompletedEventHandler>(
                            [state](ICoreWebView2 *sender, ICoreWebView2NavigationCompletedEventArgs *args) -> HRESULT {
                                state->is_loading = false;
                                // Update title
                                LPWSTR title;
                                sender->get_DocumentTitle(&title);
                                if (title) {
                                    int required_size =
                                        WideCharToMultiByte(CP_UTF8, 0, title, -1, nullptr, 0, nullptr, nullptr);
                                    if (required_size > 0) {
                                        std::vector<char> buffer(required_size);
                                        WideCharToMultiByte(CP_UTF8, 0, title, -1, buffer.data(), required_size,
                                                            nullptr, nullptr);
                                        state->current_title = std::string(buffer.data());
                                    }
                                    CoTaskMemFree(title);
                                }

                                // Re-inject message handler compatibility layer after navigation
                                // This is necessary because page navigation clears all injected scripts
                                for (const auto &handler : state->message_handlers) {
                                    const std::string &handlerName = handler.first;
                                    if (!is_valid_handler_name(handlerName)) {
                                        g_warning("WebView2: Skipping re-injection of invalid handler name: %s", handlerName.c_str());
                                        continue;  // skip unsafe handler names
                                    }

                                    // Use bracket notation for safe injection
                                    std::string inject_script =
                                        "(function() {"
                                        "  if (!window.webkit) window.webkit = {};"
                                        "  if (!window.webkit.messageHandlers) window.webkit.messageHandlers = {};"
                                        "  window.webkit.messageHandlers[" +
                                        std::string("\"") + handlerName + std::string("\"") +
                                        "] = {"
                                        "    postMessage: function(msg) {"
                                        "      window.chrome.webview.postMessage(\"" +
                                        handlerName +
                                        ":\" + JSON.stringify(msg));"
                                        "    }"
                                        "  };"
                                        "})();";

                                    int required_size =
                                        MultiByteToWideChar(CP_UTF8, 0, inject_script.c_str(), -1, nullptr, 0);
                                    if (required_size > 0) {
                                        std::vector<wchar_t> w_script(required_size);
                                        MultiByteToWideChar(CP_UTF8, 0, inject_script.c_str(), -1, w_script.data(),
                                                            required_size);

                                        state->webview->ExecuteScript(
                                            w_script.data(),
                                            Callback<ICoreWebView2ExecuteScriptCompletedHandler>(
                                                [](HRESULT errorCode, LPCWSTR resultObjectAsJson) -> HRESULT {
                                                    return S_OK;
                                                })
                                                .Get());
                                    }
                                }

                                return S_OK;
                            })
                            .Get(),
                        nullptr);

                    // Register for web messages (for script message handlers)
                    state->webview->add_WebMessageReceived(
                        Callback<ICoreWebView2WebMessageReceivedEventHandler>(
                            [state](ICoreWebView2 *sender, ICoreWebView2WebMessageReceivedEventArgs *args) -> HRESULT {
                                LPWSTR message;
                                args->TryGetWebMessageAsString(&message);
                                if (message) {
                                    int required_size =
                                        WideCharToMultiByte(CP_UTF8, 0, message, -1, nullptr, 0, nullptr, nullptr);
                                    if (required_size > 0) {
                                        std::vector<char> buffer(required_size);
                                        WideCharToMultiByte(CP_UTF8, 0, message, -1, buffer.data(), required_size,
                                                            nullptr, nullptr);

                                        // Parse message format: "handlerName:jsonData"
                                        std::string msg_str(buffer.data());
                                        size_t colon_pos = msg_str.find(':');
                                        if (colon_pos != std::string::npos) {
                                            std::string handler_name = msg_str.substr(0, colon_pos);
                                            std::string json_data = msg_str.substr(colon_pos + 1);

                                            // Remove JSON quotes if present (e.g., "\"message\"" -> "message")
                                            std::string data = json_data;
                                            if (data.length() >= 2 && data.front() == '"' && data.back() == '"') {
                                                data = data.substr(1, data.length() - 2);
                                            }

                                            auto it = state->message_handlers.find(handler_name);
                                            if (it != state->message_handlers.end() && it->second.isCallable()) {
                                                try {
                                                    it->second(data);
                                                } catch (...) {
                                                    g_warning("WebView2: Exception in message handler");
                                                }
                                            }
                                        }
                                    }
                                    CoTaskMemFree(message);
                                }
                                return S_OK;
                            })
                            .Get(),
                        nullptr);

                    // Load pending content if set
                    if (!state->pending_uri.empty()) {
                        int required_size = MultiByteToWideChar(CP_UTF8, 0, state->pending_uri.c_str(), -1, nullptr, 0);
                        if (required_size > 0) {
                            std::vector<wchar_t> w_uri(required_size);
                            MultiByteToWideChar(CP_UTF8, 0, state->pending_uri.c_str(), -1, w_uri.data(),
                                                required_size);
                            state->webview->Navigate(w_uri.data());
                            state->pending_uri.clear();
                        }
                    } else if (!state->pending_html.empty()) {
                        int required_size =
                            MultiByteToWideChar(CP_UTF8, 0, state->pending_html.c_str(), -1, nullptr, 0);
                        if (required_size > 0) {
                            std::vector<wchar_t> w_html(required_size);
                            MultiByteToWideChar(CP_UTF8, 0, state->pending_html.c_str(), -1, w_html.data(),
                                                required_size);
                            state->webview->NavigateToString(w_html.data());
                            state->pending_html.clear();
                        }
                    }

                    // Run pending scripts if any
                    if (!state->pending_scripts.empty()) {
                        for (const auto &script : state->pending_scripts) {
                            int required_size = MultiByteToWideChar(CP_UTF8, 0, script.c_str(), -1, nullptr, 0);
                            if (required_size > 0) {
                                std::vector<wchar_t> w_script(required_size);
                                MultiByteToWideChar(CP_UTF8, 0, script.c_str(), -1, w_script.data(), required_size);
                                state->webview->ExecuteScript(
                                    w_script.data(),
                                    Callback<ICoreWebView2ExecuteScriptCompletedHandler>(
                                        [](HRESULT errorCode, LPCWSTR resultObjectAsJson) -> HRESULT { return S_OK; })
                                        .Get());
                            }
                        }
                        state->pending_scripts.clear();
                    }

                    return S_OK;
                }).Get());

            return S_OK; })
            .Get());
}

/**
 * Constructor
 */
WebKitWebView_::WebKitWebView_() : user_content_manager(nullptr) {}

/**
 * Destructor
 */
WebKitWebView_::~WebKitWebView_()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state)
    {
        // Disconnect the realize signal handler to prevent dangling pointer access
        if (state->realize_signal_handler_id != 0 && instance != nullptr && GTK_IS_WIDGET(instance))
        {
            g_signal_handler_disconnect(GTK_WIDGET(instance), state->realize_signal_handler_id);
            state->realize_signal_handler_id = 0;
        }

        webview_states.erase((gpointer *)instance);
        delete state;
    }
    user_content_manager = nullptr;
}

void WebKitWebView_::__construct()
{
    // Create a GTK drawing area as the container
    instance = (gpointer *)gtk_drawing_area_new();

    if (instance == nullptr)
    {
        throw Php::Exception("Failed to create WebView widget on Windows");
    }

    // Create WebView2 state
    WebView2State *state = new WebView2State();
    webview_states[(gpointer *)instance] = state;

    // Set up minimum size
    gtk_widget_set_size_request(GTK_WIDGET(instance), 100, 100);

    // Connect to realize signal to initialize WebView2 when window is created
    // Store the handler ID so we can disconnect it in the destructor
    state->realize_signal_handler_id = g_signal_connect(GTK_WIDGET(instance), "realize", G_CALLBACK(on_widget_realized), state);
}

void WebKitWebView_::load_uri(Php::Parameters &parameters)
{
    if (parameters.size() == 0)
    {
        throw Php::Exception("load_uri() expects at least 1 parameter, 0 given");
    }

    std::string s_uri = parameters[0];
    WebView2State *state = get_webview_state((gpointer *)instance);

    if (!state)
    {
        // WebView state not available
        return;
    }

    if (!state->webview)
    {
        // WebView not initialized yet, store URI to load once initialized
        state->pending_uri = s_uri;
        return;
    }

    // Convert UTF-8 to wide string
    int required_size = MultiByteToWideChar(CP_UTF8, 0, s_uri.c_str(), -1, nullptr, 0);
    if (required_size > 0)
    {
        std::vector<wchar_t> w_uri(required_size);
        MultiByteToWideChar(CP_UTF8, 0, s_uri.c_str(), -1, w_uri.data(), required_size);
        state->webview->Navigate(w_uri.data());
    }
    else
    {
        g_warning("WebView2: Failed to convert URI to wide string: %s", s_uri.c_str());
        return;
    }
}

Php::Value WebKitWebView_::get_uri()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && !state->current_uri.empty())
    {
        return state->current_uri;
    }
    return nullptr;
}

void WebKitWebView_::reload()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        state->webview->Reload();
    }
}

void WebKitWebView_::stop_loading()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        state->webview->Stop();
    }
}

Php::Value WebKitWebView_::can_go_back()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        BOOL can_go_back = FALSE;
        state->webview->get_CanGoBack(&can_go_back);
        return (bool)can_go_back;
    }
    return false;
}

void WebKitWebView_::go_back()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        state->webview->GoBack();
    }
}

Php::Value WebKitWebView_::can_go_forward()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        BOOL can_go_forward = FALSE;
        state->webview->get_CanGoForward(&can_go_forward);
        return (bool)can_go_forward;
    }
    return false;
}

void WebKitWebView_::go_forward()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        state->webview->GoForward();
    }
}

Php::Value WebKitWebView_::get_title()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && !state->current_title.empty())
    {
        return state->current_title;
    }
    return nullptr;
}

Php::Value WebKitWebView_::is_loading()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state)
    {
        return state->is_loading;
    }
    return false;
}

void WebKitWebView_::load_html(Php::Parameters &parameters)
{
    if (parameters.size() == 0)
    {
        throw Php::Exception("load_html() expects at least 1 parameter, 0 given");
    }

    std::string s_content = parameters[0].stringValue();
    WebView2State *state = get_webview_state((gpointer *)instance);

    if (!state)
    {
        // WebView state not available
        return;
    }

    if (!state->webview)
    {
        // WebView not initialized yet, store HTML to load once initialized
        state->pending_html = s_content;
        state->pending_uri.clear(); // Clear any pending URI
        return;
    }

    // Convert UTF-8 to wide string
    int required_size = MultiByteToWideChar(CP_UTF8, 0, s_content.c_str(), -1, nullptr, 0);
    if (required_size > 0)
    {
        std::vector<wchar_t> w_content(required_size);
        MultiByteToWideChar(CP_UTF8, 0, s_content.c_str(), -1, w_content.data(), required_size);
        state->webview->NavigateToString(w_content.data());
    }
}

void WebKitWebView_::run_javascript(Php::Parameters &parameters)
{
    if (parameters.size() == 0)
    {
        throw Php::Exception("run_javascript() expects at least 1 parameter, 0 given");
    }

    std::string s_script = parameters[0];
    WebView2State *state = get_webview_state((gpointer *)instance);

    if (!state)
    {
        // WebView state not available, cannot run or store script
        return;
    }

    if (!state->webview)
    {
        // WebView not initialized yet, store script to run once initialized
        state->pending_scripts.push_back(s_script);
        return;
    }

    // Convert UTF-8 to wide string
    int required_size = MultiByteToWideChar(CP_UTF8, 0, s_script.c_str(), -1, nullptr, 0);
    if (required_size > 0)
    {
        std::vector<wchar_t> w_script(required_size);
        MultiByteToWideChar(CP_UTF8, 0, s_script.c_str(), -1, w_script.data(), required_size);

        state->webview->ExecuteScript(
            w_script.data(),
            Callback<ICoreWebView2ExecuteScriptCompletedHandler>([](HRESULT errorCode,
                                                                    LPCWSTR resultObjectAsJson) -> HRESULT
                                                                 { return S_OK; })
                .Get());
    }
}

void WebKitWebView_::register_script_message_handler(Php::Parameters &parameters)
{
    if (parameters.size() == 0)
    {
        throw Php::Exception("register_script_message_handler() expects at least 1 parameter, 0 given");
    }

    std::string s_name = parameters[0];
    WebView2State *state = get_webview_state((gpointer *)instance);

    if (!state)
    {
        g_warning("WebView2: WebView state not found");
        return;
    }

    // Validate handler name
    if (!is_valid_handler_name(s_name))
    {
        throw Php::Exception(
            "register_script_message_handler(): Invalid handler name. Only alphanumeric characters and underscores are "
            "allowed.");
    }

    // Store callback if provided
    if (parameters.size() > 1 && parameters[1].isCallable())
    {
        state->message_handlers[s_name] = parameters[1];
    }

    // Inject JavaScript to create WebKit-compatible API
    // This makes window.webkit.messageHandlers.handlerName.postMessage() work on WebView2
    if (state->webview)
    {
        // Use bracket notation for safe injection
        std::string inject_script =
            "(function() {"
            "  if (!window.webkit) window.webkit = {};"
            "  if (!window.webkit.messageHandlers) window.webkit.messageHandlers = {};"
            "  window.webkit.messageHandlers[" +
            std::string("\"") + s_name + std::string("\"") +
            "] = {"
            "    postMessage: function(msg) {"
            "      window.chrome.webview.postMessage(\"" +
            s_name +
            ":\" + JSON.stringify(msg));"
            "    }"
            "  };"
            "})();";

        int required_size = MultiByteToWideChar(CP_UTF8, 0, inject_script.c_str(), -1, nullptr, 0);
        if (required_size > 0)
        {
            std::vector<wchar_t> w_script(required_size);
            MultiByteToWideChar(CP_UTF8, 0, inject_script.c_str(), -1, w_script.data(), required_size);

            state->webview->ExecuteScript(
                w_script.data(),
                Callback<ICoreWebView2ExecuteScriptCompletedHandler>([](HRESULT errorCode,
                                                                        LPCWSTR resultObjectAsJson) -> HRESULT
                                                                     { return S_OK; })
                    .Get());
        }
    }
}

void WebKitWebView_::enable_developer_extras()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        ComPtr<ICoreWebView2Settings> settings;
        state->webview->get_Settings(&settings);
        if (settings)
        {
            settings->put_AreDevToolsEnabled(TRUE);
            settings->put_AreDefaultContextMenusEnabled(TRUE);
        }
    }
}

Php::Value WebKitWebView_::get_settings()
{
    WebView2State *state = get_webview_state((gpointer *)instance);
    if (state && state->webview)
    {
        return true;
    }
    return false;
}

void WebKitWebView_::set_user_data_folder(Php::Parameters &params)
{
    if (params.size() < 1)
    {
        throw Php::Exception("set_user_data_folder() requires 1 parameter: folder path");
    }

    std::string folder = params[0];
    
    // Validate folder path
    if (folder.empty())
    {
        throw Php::Exception("set_user_data_folder(): folder path cannot be empty");
    }

    WebView2State *state = get_webview_state((gpointer *)instance);

    if (!state)
    {
        throw Php::Exception("set_user_data_folder(): WebView state not found");
    }

    // Check if WebView2 is already initialized
    if (state->webview)
    {
        g_warning(
            "WebView2: set_user_data_folder() must be called before the widget is realized. Setting will take effect "
            "on next widget creation.");
    }

    state->user_data_folder = folder;
}

#endif // _WIN32
