
#ifndef _PHPGTK_GDKSCREEN_H_
#define _PHPGTK_GDKSCREEN_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>


    #include "GdkVisual.h"
    #include "GdkWindow.h"


    /**
     * GdkScreen_
     * 
     * https://developer.gnome.org/gtk3/stable/GdkScreen.html
     */
    class GdkScreen_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GdkScreen *instance;

            /**
             *  C++ constructor and destructor
             */
            GdkScreen_();
            ~GdkScreen_();

            /**
             * Return original GdkScreen
             */
            GdkScreen *get_instance();

            /**
             * Set the original GdkScreen
             */
            void set_instance(GdkScreen *screen);
            Php::Value get_rgba_visual();
            Php::Value get_window_stack();


    };

#endif
