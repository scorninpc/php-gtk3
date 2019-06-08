
#ifndef _PHPGTK_GTKWIDGET_H_
#define _PHPGTK_GTKWIDGET_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>

    #include "GdkEvent.h"
    #include "GObject.h"


    /**
     *  @todo Create a method to verify if widget exists, and implement on all methods, if not exists, throw a exception
     */
    class GtkWidget_ : public GObject_
    {
        
        /**
         * Publics
         */
        public:
            GtkWidget *widget;

            /**
             * Return original GtkWidget
             */
            gpointer *get_widget();

            /**
             * Set the original gpointer
             */
            void set_widget(gpointer *pased_widget);

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
             * Retrieves the internal scale factor that maps from window coordinates to the actual device pixels.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-scale-factor
             */
            Php::Value get_scale_factor();

            /**
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-activate
             *
             * @todo not tested
             */
            Php::Value activate();

            /**
             * Determines if the widget is the focus widget within its toplevel.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-is-focus
             */
            Php::Value is_focus();

            /**
             * Causes widget to have the keyboard focus for the GtkWindow it's inside
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-grab-focus
             */
            void grab_focus();

            /**
             * Determines if the widget has the global input focus.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-has-focus
             */
            Php::Value has_focus();

            /**
             * Causes widget to become the default widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-grab-default
             */
            void grab_default();

            /**
             * Widgets can be named, which allows you to refer to them from a CSS file.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-name
             */
            void set_name(Php::Parameters &parameters);

            /**
             * Retrieves the name of a widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-name
             */
            Php::Value get_name();

            /**
             * Sets the sensitivity of a widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-sensitive
             */
            void set_sensitive(Php::Parameters &parameters);

            /**
             * Gets the sensitivity of a widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-sensitive
             */
            Php::Value get_sensitive();

            /**
             * If widget are sensitivity, include if parent is sensitive
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-is-sensitive
             */
            Php::Value is_sensitive();

            /**
             * Sets the sensitivity of a widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-mnemonic-activate
             */
            Php::Value mnemonic_activate(Php::Parameters &parameters);

            /**
             * Returns the parent container of widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-parent
             */
            Php::Value get_parent();
            void set_parent(Php::Parameters &parameters);

            /**
             * Sets text as the contents of the tooltip
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-tooltip-text
             */
            void set_tooltip_text(Php::Parameters &parameters);

            /**
             * Gets text as the contents of the tooltip
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-tooltip-text
             */
            Php::Value get_tooltip_text();

            /**
             * Returns the current value of the has-tooltip property
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-has-tooltip
             */
            Php::Value get_has_tooltip();

            /**
             * Returns the width that has currently been allocated to widget
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-allocated-width
             */
            Php::Value get_allocated_width();

            /**
             * Returns the height that has currently been allocated to widget
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-allocated-height
             */
            Php::Value get_allocated_height();

            /**
             * Sets whether the widget should grab focus when it is clicked with the mouse.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-focus-on-click
             */
            void set_focus_on_click(Php::Parameters &parameters);

            /**
             * Sets the visibility state of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-visible
             */
            void set_visible(Php::Parameters &parameters);

            /**
             * Gets the visibility state of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-visible
             */
            Php::Value get_visible();

            /**
             * Sets the opacity of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-opacity
             */
            void set_opacity(Php::Parameters &parameters);

            /**
             * Gets the opacity of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-opacity
             */
            Php::Value get_opacity();

            /**
             * Sets the vertical align of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-valign
             */
            void set_valign(Php::Parameters &parameters);

            /**
             * Gets the vertical align of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-valign
             */
            Php::Value get_valign();

            /**
             * Sets the horizontal align of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-halign
             */
            void set_halign(Php::Parameters &parameters);

            /**
             * Gets the horizontal align of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-halign
             */
            Php::Value get_halign();

            /**
             * Sets the start margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-margin_start
             */
            void set_margin_start(Php::Parameters &parameters);

            /**
             * Gets the start margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-margin_start
             */
            Php::Value get_margin_start();

            /**
             * Sets the end margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-margin_end
             */
            void set_margin_end(Php::Parameters &parameters);

            /**
             * Gets the end margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-margin_end
             */
            Php::Value get_margin_end();

            /**
             * Sets the top margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-margin_top
             */
            void set_margin_top(Php::Parameters &parameters);

            /**
             * Gets the top margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-margin_top
             */
            Php::Value get_margin_top();

            /**
             * Sets the bottom margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-margin_bottom
             */
            void set_margin_bottom(Php::Parameters &parameters);

            /**
             * Gets the bottom margin of widget
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-get-margin_bottom
             */
            Php::Value get_margin_bottom();

            void set_size_request(Php::Parameters &parameters);
            Php::Value get_size_request(Php::Parameters &parameters);
        };

#endif