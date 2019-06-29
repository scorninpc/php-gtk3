
#ifndef _PHPGTK_GDKWINDOW_H_
#define _PHPGTK_GDKWINDOW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GObject.h"

    /**
     * GdkWindow_
     * 
     * https://developer.gnome.org/gtk3/stable/GdkWindow.html
     */
    class GdkWindow_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkWindow_();
            ~GdkWindow_();

            void beep();
            void maximize();
            static Php::Value get_default_root_window();
    };

#endif
