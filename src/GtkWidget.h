
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
             * Return original GtkWidget
             */
            GtkWidget *get_widget();

            /**
             *  C++ constructor and destructor
             */
            GtkWidget_();
            virtual ~GtkWidget_();

            /**
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show-all
             */
            void show_all();

            /**
             * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
             */
            Php::Value connect(Php::Parameters &parameters);

            /**
             * Class to abstract php callback for connect method, to call PHP function
             */
            static void connect_callback(GtkWidget * widget, GdkEvent user_event, gpointer user_data);

            /**
             * Disconnect signal by handle
             *
             * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-handler-disconnect
             */
            void handler_disconnect(Php::Parameters &parameters);

            /**
             * Destroys a widget
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-destroy
             */
            void destroy();

            /**
             * Returns whether the widget is currently being destroyed
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-in-destruction
             */
            Php::Value in_destruction();

            /**
             * This function sets *widget_pointer to NULL if widget_pointer != NULL
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-destroyed
             */
            void destroyed(Php::Parameters &parameters);

            /**
             * Should be called by implementations of the remove method on GtkContainer, to dissociate a child from the container
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-unparent
             */
            void unparent();

            /**
             * Flags a widget to be displayed
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show
             */
            void show();

            /**
             * Shows a widget
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show-now
             */
            void show_now();

            /**
             * Reverses the effects of gtk_widget_show(), causing the widget to be hidden
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-hide
             */
            void hide();

            /**
             * Causes a widget to be mapped if it isn’t already
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-map
             */
            void map();

            /**
             * Causes a widget to be unmapped if it’s currently mapped.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-unmap
             */
            void unmap();

            /**
             * if you show a widget and all its parent containers, then the widget will be realized and mapped automatically.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-realize
             */
            void realize();

            /**
             * Causes a widget to be unrealized
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-unrealize
             */
            void unrealize();

            /**
             * You should pass a cairo context as cr argument that is in an original state
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-draw
             */
            void draw();

            /**
             * Equivalent to calling queue_draw_area() for the entire area of a widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-queue-draw
             */
            void queue_draw();

            /**
             * Flags a widget to have its size renegotiated.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-queue-resize
             */
            void queue_resize();

            /**
             * This function works like queue_resize(), except that the widget is not invalidated.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-queue-resize-no-redraw
             */
            void queue_resize_no_redraw();

            /**
             * Flags the widget for a rerun of the GtkWidgetClass::size_allocate function
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-queue-allocate
             */
            void queue_allocate();

            /**
             * Obtains the frame clock for a widget
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-frame-clock
             */
            void get_frame_clock();

            /**
             * Retrieves the internal scale factor that maps from window coordinates to the actual device pixels.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-scale-factor
             */
            Php::Value get_scale_factor();

            /**
             * Callback type for adding a function to update animations
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#GtkTickCallback
             */
            Php::Value GtkTickCallback();

            /**
             * Queues an animation frame update and adds a callback to be called before each frame.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-add-tick-callback
             */
            Php::Value add_tick_callback();

            /**
             * Removes a tick callback previously registered with add_tick_callback()
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-remove-tick-callback
             */
            void remove_tick_callback();

            /**
             * Obtains the preferred size of a widget. 
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-size-request
             */
            void size_request();
            
    };

#endif