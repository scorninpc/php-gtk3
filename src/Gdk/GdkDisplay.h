
#ifndef _PHPGTK_GDKDISPLAY_H_
#define _PHPGTK_GDKDISPLAY_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GdkMonitor.h"
    #include "GdkScreen.h"

    /**
     * GdkDisplay_
     * 
     * https://developer.gnome.org/gtk3/stable/GdkDisplay.html
     */
    class GdkDisplay_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GdkDisplay *instance;

            /**
             *  C++ constructor and destructor
             */
            GdkDisplay_();
            ~GdkDisplay_();

            /**
             * Return original GdkDisplay
             */
            GdkDisplay *get_instance();
            void set_instance(GdkDisplay *screen);

            static Php::Value get_default();
            Php::Value get_primary_monitor();
            Php::Value get_default_screen();


    };

#endif
