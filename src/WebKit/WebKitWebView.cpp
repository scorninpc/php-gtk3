
#include "WebKitWebView.h"

/**
 * Constructor
 */
WebKitWebView_::WebKitWebView_() : user_content_manager(nullptr) {}

/**
 * Destructor
 */
WebKitWebView_::~WebKitWebView_()
{
	// Clear the user_content_manager pointer to prevent any potential
	// dangling pointer issues after the WebView is destroyed
	user_content_manager = nullptr;
	
	// Do nothing else - let GTK/PHP-CPP handle cleanup
	// The instance will be managed by the framework
}

void WebKitWebView_::__construct()
{
	// Create the WebView with the default UserContentManager
	// We'll get the manager from the WebView when we need it
	instance = (gpointer *)webkit_web_view_new();
	
	if (instance == nullptr) {
		throw Php::Exception("Failed to create WebKitWebView");
	}
	
	// Get the UserContentManager from the WebView (we don't own it)
	user_content_manager = webkit_web_view_get_user_content_manager(WEBKIT_WEB_VIEW(instance));
	
	if (user_content_manager == nullptr) {
		throw Php::Exception("Failed to get UserContentManager from WebKitWebView");
	}
}

void WebKitWebView_::load_uri(Php::Parameters &parameters)
{
	if (parameters.size() == 0) {
		throw Php::Exception("load_uri() expects at least 1 parameter, 0 given");
	}

	std::string s_uri = parameters[0];
	const gchar *uri = (const gchar *)s_uri.c_str();

	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(instance), uri);
}

Php::Value WebKitWebView_::get_uri()
{
	const gchar *ret = webkit_web_view_get_uri(WEBKIT_WEB_VIEW(instance));

	if (ret == nullptr) {
		return nullptr;
	}

	return std::string(ret);
}

void WebKitWebView_::reload()
{
	webkit_web_view_reload(WEBKIT_WEB_VIEW(instance));
}

void WebKitWebView_::stop_loading()
{
	webkit_web_view_stop_loading(WEBKIT_WEB_VIEW(instance));
}

Php::Value WebKitWebView_::can_go_back()
{
	gboolean ret = webkit_web_view_can_go_back(WEBKIT_WEB_VIEW(instance));

	return (bool)ret;
}

void WebKitWebView_::go_back()
{
	webkit_web_view_go_back(WEBKIT_WEB_VIEW(instance));
}

Php::Value WebKitWebView_::can_go_forward()
{
	gboolean ret = webkit_web_view_can_go_forward(WEBKIT_WEB_VIEW(instance));

	return (bool)ret;
}

void WebKitWebView_::go_forward()
{
	webkit_web_view_go_forward(WEBKIT_WEB_VIEW(instance));
}

Php::Value WebKitWebView_::get_title()
{
	const gchar *ret = webkit_web_view_get_title(WEBKIT_WEB_VIEW(instance));

	if (ret == nullptr) {
		return nullptr;
	}

	return std::string(ret);
}

Php::Value WebKitWebView_::is_loading()
{
	gboolean ret = webkit_web_view_is_loading(WEBKIT_WEB_VIEW(instance));

	return (bool)ret;
}

void WebKitWebView_::load_html(Php::Parameters &parameters)
{
    if (parameters.size() == 0) {
        throw Php::Exception("load_html() expects at least 1 parameter, 0 given");
    }

    // First parameter: HTML content
    std::string s_content = parameters[0].stringValue();
    const gchar *content = s_content.c_str();

    // Optional second parameter: base URI
    std::string s_base_uri;
    const gchar *base_uri = nullptr;

    if (parameters.size() > 1 && !parameters[1].isNull()) {
        s_base_uri = parameters[1].stringValue();
        base_uri = s_base_uri.c_str();
    }

    webkit_web_view_load_html(WEBKIT_WEB_VIEW(instance), content, base_uri);
}

void WebKitWebView_::run_javascript(Php::Parameters &parameters)
{
	if (parameters.size() == 0) {
		throw Php::Exception("run_javascript() expects at least 1 parameter, 0 given");
	}

	std::string s_script = parameters[0];
	const gchar *script = (const gchar *)s_script.c_str();

	webkit_web_view_evaluate_javascript(WEBKIT_WEB_VIEW(instance), script, -1, nullptr, nullptr, nullptr, nullptr, nullptr);
}

// Structure to hold callback data for script message handler
struct ScriptMessageData {
	Php::Value callback;
	std::string handler_name;
};

// Callback when JavaScript sends a message
static void script_message_received_cb(WebKitUserContentManager *manager, WebKitJavascriptResult *js_result, gpointer user_data)
{
	ScriptMessageData *data = (ScriptMessageData *)user_data;
	
	// Call the PHP callback
	try {
		// Extract the JSCValue from the WebKitJavascriptResult
		char *str_value = nullptr;
		
		if (js_result != nullptr) {
			// Get the JSCValue from the result
			JSCValue *value = webkit_javascript_result_get_js_value(js_result);
			
			if (value != nullptr && jsc_value_is_string(value)) {
				str_value = jsc_value_to_string(value);
			} else if (value != nullptr) {
				// Try to convert non-string values to string
				str_value = jsc_value_to_string(value);
			}
		}
		
		if (str_value != nullptr) {
			data->callback(str_value);
			g_free(str_value);
		} else {
			data->callback();
		}
	} catch (const std::exception &e) {
		g_warning("Exception in script message handler callback: %s", e.what());
		fflush(stderr);
	} catch (...) {
		g_warning("Unknown exception in script message handler callback");
		fflush(stderr);
	}
}

void WebKitWebView_::register_script_message_handler(Php::Parameters &parameters)
{
	if (parameters.size() == 0) {
		throw Php::Exception("register_script_message_handler() expects at least 1 parameter, 0 given");
	}

	std::string s_name = parameters[0];
	const gchar *name = (const gchar *)s_name.c_str();

	// Check that we have a user content manager
	if (user_content_manager == nullptr) {
		g_warning("User content manager is null!");
		fflush(stderr);
		throw Php::Exception("Failed to get user content manager");
	}
	
	// Register the script message handler
	webkit_user_content_manager_register_script_message_handler(user_content_manager, name);
	
	// If a callback was provided as second parameter, connect it
	if (parameters.size() > 1 && parameters[1].isCallable()) {
		// Build the signal name: "script-message-received::handlerName"
		std::string signal_name = "script-message-received::" + s_name;
		
		// Create data structure to pass to callback
		ScriptMessageData *data = new ScriptMessageData();
		data->callback = parameters[1];
		data->handler_name = s_name;
		
		// Connect the signal to the user content manager (not the webview)
		// and store the handler ID so we can disconnect it later
		gulong handler_id = g_signal_connect_data(user_content_manager, signal_name.c_str(), 
		                      G_CALLBACK(script_message_received_cb), 
		                      data, 
		                      [](gpointer user_data, GClosure *closure) {
		                          delete (ScriptMessageData *)user_data;
		                      },
		                      (GConnectFlags)0);
		
		// Store the handler ID for cleanup in destructor
		signal_handler_ids.push_back(handler_id);
	}
}

void WebKitWebView_::enable_developer_extras()
{
	// Get the WebView's settings
	WebKitSettings *settings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(instance));
	
	if (settings == nullptr) {
		g_warning("Failed to get WebKit settings!");
		fflush(stderr);
		return;
	}
	
	// Enable developer extras (Web Inspector)
	webkit_settings_set_enable_developer_extras(settings, TRUE);
}

Php::Value WebKitWebView_::get_settings()
{
	// Get the WebView's settings
	WebKitSettings *settings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(instance));
	
	if (settings == nullptr) {
		return nullptr;
	}
	
	// Return true to indicate settings are available
	// This is safer than returning a raw pointer
	return true;
}
