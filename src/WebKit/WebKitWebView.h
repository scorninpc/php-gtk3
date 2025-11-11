
#ifndef _PHPGTK_WEBKITWEBVIEW_H_
#define _PHPGTK_WEBKITWEBVIEW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    
    #ifndef _WIN32
        // Unix/Linux/macOS: WebKit2GTK headers
        #include <webkit2/webkit2.h>
        #include <jsc/jsc.h>
    #endif
    
    #include <vector>

    #include "../Gtk/GtkWidget.h"

    #include "../../php-gtk.h"

    /**
     * WebKitWebView_
     *
     * Cross-platform WebView widget:
     * - Unix/Linux/macOS: Uses WebKit2GTK
     * - Windows: Uses Microsoft Edge WebView2
     * 
     * https://webkitgtk.org/reference/webkit2gtk/stable/WebKitWebView.html
     * https://docs.microsoft.com/en-us/microsoft-edge/webview2/
     */
    class WebKitWebView_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            WebKitWebView_();
            ~WebKitWebView_();

            void __construct();

            void load_uri(Php::Parameters &parameters);

            Php::Value get_uri();

            void reload();

            void stop_loading();

            Php::Value can_go_back();

            void go_back();

            Php::Value can_go_forward();

            void go_forward();

            Php::Value get_title();

            Php::Value is_loading();

            void load_html(Php::Parameters &parameters);

            void run_javascript(Php::Parameters &parameters);

            void register_script_message_handler(Php::Parameters &parameters);

            void enable_developer_extras();

            Php::Value get_settings();
            
            void set_user_data_folder(Php::Parameters &parameters);

        /**
         * Private members
         */
        private:
            #ifndef _WIN32
                // Unix/Linux/macOS: WebKit2GTK specific members
                WebKitUserContentManager *user_content_manager;
                std::vector<gulong> signal_handler_ids;
            #else
                // Windows: WebView2 specific members
                // Note: WebView2 state (controller, environment, etc.) is managed 
                // in WebKitWebView_Windows.cpp via WebView2State structure
                void *user_content_manager;  // Placeholder for compatibility
                std::vector<unsigned long> signal_handler_ids;  // Placeholder
            #endif
    };

#endif
