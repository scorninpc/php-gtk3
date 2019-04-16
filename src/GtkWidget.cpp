#include <phpcpp.h>
#include <iostream>

#include <gtk/gtk.h>

#include "GdkEvent.cpp"

/**
 *  
 */
class GtkWidget_ : public Php::Base
{
    
    private:
        struct st_callback {
            Php::Value callback_name;
            Php::Array callback_params;
            Php::Object self_widget;
        };

    public:
        GtkWidget *widget;

        /**
         *  C++ constructor and destructor
         */
        GtkWidget_()
        {
            
        }

        // ~GtkWidget_()
        // {
        //  free(widget);
        // }

        

        /**
         * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show-all
         */
        void show_all()
        {
            gtk_widget_show_all(widget);
        }

        /**
         * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
         *
         * @todo Verify if callback are callable with Php::Callable::Callable
         */
        Php::Value connect(Php::Parameters &parameters)
        {
            Php::Value callback_event = parameters[0];
            Php::Value callback_name = parameters[1];
            Php::Array callback_params = parameters;

            // Create gpoint param
            st_callback *callback_object = (st_callback *)malloc(sizeof(st_callback));
            memset(callback_object, 0, sizeof(st_callback));
            
            callback_object->callback_name = callback_name;
            callback_object->callback_params = callback_params;
            callback_object->self_widget = Php::Object("GtkWidget", this);

            // Create the CPP callback
            int ret = g_signal_connect(widget, callback_event, G_CALLBACK (&connect_callback), (gpointer) callback_object);

            return ret;
        }

        /**
         * Class to abstract php callback for connect method, to call PHP function
         */
        static void connect_callback(GtkWidget * widget, GdkEvent event, gpointer user_data)
        {
            // Return to st_callback
            st_callback *callback_object = (st_callback *) user_data;

            // Create event from callback
            GdkEvent_ *aa = new GdkEvent_();
            Php::Value gdkevent = Php::Object("GdkEvent", aa);
            aa->populate(&event);

            // Create PHP params return
            Php::Value php_callback_param;
            php_callback_param[0] = callback_object->self_widget;
            php_callback_param[1] = gdkevent;

            // Call php function with parameters
            Php::call("call_user_func_array", callback_object->callback_name, php_callback_param);

        }

        /**
         * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-handler-disconnect
         *
         * Disconnect signal by handle
         */
        void handler_disconnect(Php::Parameters &parameters)
        {
            Php::Value callback_handle = parameters[0];

            g_signal_handler_disconnect(widget, (int)callback_handle);
        }
};