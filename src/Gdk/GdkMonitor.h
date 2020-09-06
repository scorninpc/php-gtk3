
#ifndef _PHPGTK_GDKMONITOR_H_
#define _PHPGTK_GDKMONITOR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GdkMonitor_
     * 
     * https://developer.gnome.org/gdk3/stable/GdkMonitor.html
     */
    class GdkMonitor_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GdkMonitor *instance;

            /**
             *  C++ constructor and destructor
             */
            GdkMonitor_();
            ~GdkMonitor_();

            /**
             * Return original GdkMonitor
             */
            GdkMonitor *get_instance();
            void set_instance(GdkMonitor *monitor);

            Php::Value get_width_mm();
            Php::Value get_height_mm();
            Php::Value get_workarea();


    };

#endif
