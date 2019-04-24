
#ifndef _PHPGTK_GTKWINDOW_H_
#define _PHPGTK_GTKWINDOW_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>

    #include "GtkBin.h"

    /**
     *  
     */
    class GtkWindow_ : public GtkBin_
    {
        
        /**
         * Publics
         */
        public:
            /**
             * C++ constructor/destructor
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-new
             */
            GtkWindow_();
            virtual ~GtkWindow_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Sets the title of the GtkWindow
             *      https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-title
             */
            void set_title(Php::Parameters &parameters);

            /**
             * Retrieves the title of the window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-title
             */
            Php::Value get_title();

            /**
             * Sets the default size of a window
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-default-size
             */
            void set_default_size(Php::Parameters &parameters);

            /**
             * Gets the default size of the window
             * 
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-default-size
             */
            Php::Value get_default_size();

            /**
             * Sets whether the user can resize a window.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-resizable
             */
            void set_resizable(Php::Parameters &parameters);

            /**
             * Sets whether the user can resize a window.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-resizable
             */
            Php::Value get_resizable();

            /**
             * Activates the current focused widget within the window.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-activate-focus
             */
            Php::Value activate_focus();

            /**
             * Activates the default widget for the window, unless the current focused widget has been configured to receive the default action, in which case the focused widget is activated.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-activate-default
             */
            Php::Value activate_default();

            /**
             * Sets a window modal or non-modal
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-modal
             */
            void set_modal(Php::Parameters &parameters);

            /**
             * Gets a window modal or non-modal
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-modal
             */
            Php::Value get_modal();

            /**
             * Sets a position constraint for this window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-position
             */
            void set_position(Php::Parameters &parameters);

            /**
             *  Gets a position coordinates for this window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-position
             */
            Php::Value get_position();
    };

#endif