
#ifndef _PHPGTK_GTKWIDGET_H_
#define _PHPGTK_GTKWIDGET_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>

    #include "GdkEvent.h"

    /**
     *  
     */
    class GtkWidget_ : public Php::Base
    {
        
        /**
         * Privates
         */
        private:
            struct st_callback;

        /**
         * Publics
         */
        public:
            GtkWidget *widget;

            /**
             *  C++ constructor and destructor
             */
            GtkWidget_();

            /**
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show-all
             */
            void show_all();

            /**
             * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
             *
             * @todo Verify if callback are callable with Php::Callable::Callable
             */
            Php::Value connect(Php::Parameters &parameters);

            /**
             * Class to abstract php callback for connect method, to call PHP function
             */
            static void connect_callback(GtkWidget * widget, GdkEvent user_event, gpointer user_data);

            /**
             * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-handler-disconnect
             *
             * Disconnect signal by handle
             */
            void handler_disconnect(Php::Parameters &parameters);
    };

#endif