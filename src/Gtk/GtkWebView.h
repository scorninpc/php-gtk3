
#ifndef _PHPGTK_GTKWEBVIEW_H_
#define _PHPGTK_GTKWEBVIEW_H_

    #include <phpcpp.h>
    #include "../WebKit/WebKitWebView.h"

    /**
     * GtkWebView_
     *
     * Convenience alias for WebKitWebView for consistent GTK-style naming.
     * This is a simple wrapper around WebKitWebView that provides the same
     * functionality with a more familiar GTK widget name.
     *
     * All methods are inherited from WebKitWebView.
     */
    class GtkWebView_ : public WebKitWebView_
    {
        public:
            GtkWebView_() : WebKitWebView_() {}
    };

#endif
