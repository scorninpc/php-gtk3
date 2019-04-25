
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
             *
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

            /**
             * Dialog windows should be set transient for the main application window they were spawned from
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-transient-for
             */
            void set_transient_for(Php::Parameters &parameters);

            /**
             * Fetches the transient parent for this window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-transient-for
             */
            Php::Value get_transient_for();

            /**
             * If setting is TRUE, then destroying the transient parent of window will also destroy window itself
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-destroy-with-parent
             */
            void set_destroy_with_parent(Php::Parameters &parameters);

            /**
             * Returns whether the window will be destroyed with its transient parent
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-destroy-with-parent
             */
            Php::Value get_destroy_with_parent();

            /**
             * If setting is TRUE, then window will request that it’s titlebar should be hidden when maximized
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-hide-titlebar-when-maximized
             */
            void set_hide_titlebar_when_maximized(Php::Parameters &parameters);

            /**
             * Returns whether the window has requested to have its titlebar hidden when maximized
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-hide-titlebar-when-maximized
             */
            Php::Value get_hide_titlebar_when_maximized();

            /**
             * Returns whether the window is part of the current active toplevel.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-is-active
             */
            Php::Value is_active();

            /**
             * Retrieves the current maximized state of window .
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-is-maximized
             */
            Php::Value is_maximized();

            /**
             * Returns whether the input focus is within this GtkWindow.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-has-toplevel-focus
             */
            Php::Value has_toplevel_focus();

            /**
             * Adds a mnemonic to this window.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-add-mnemonic
             */
            void add_mnemonic(Php::Parameters &parameters);

            /**
             * Removes a mnemonic to this window.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-remove-mnemonic
             */
            void remove_mnemonic(Php::Parameters &parameters);

            /**
             * Activates the targets associated with the mnemonic.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-mnemonic-activate
             */
            Php::Value mnemonic_activate(Php::Parameters &parameters);

            /**
             * Sets the mnemonic modifier for this window.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-mnemonic-modifier
             */
            void set_mnemonic_modifier(Php::Parameters &parameters);

            /**
             * If focus is not the current focus widget, and is focusable, sets it as the focus widget for the window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-focus
             */
            void set_focus(Php::Parameters &parameters);

            /**
             * Retrieves the current focused widget within the window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-focus
             */
            Php::Value get_focus();

            /**
             * If focus is not the current focus widget, and is focusable, sets it as the focus widget for the window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-default
             */
            void set_default(Php::Parameters &parameters);

            /**
             * Retrieves the current focused widget within the window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-default-widget
             */
            Php::Value get_default_widget();

            /**
             * Requests that the window is closed, similar to what happens when a window manager close button is clicked.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-close
             */
            void close();

            /**
             * Asks to iconify (i.e. minimize) the specified window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-iconify
             */
            void iconify();

            /**
             * Asks to deiconify (i.e. unminimize) the specified window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-deiconify
             */
            void deiconify();

            /**
             * Asks to stick window , which means that it will appear on all user desktops
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-stick
             */
            void stick();

            /**
             * Asks to unstick window , which means that it will appear on only one of the user’s desktops.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-unstick
             */
            void unstick();

            /**
             * Asks to maximize window , so that it becomes full-screen.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-maximize
             */
            void maximize();

            /**
             * Asks to unmaximize window
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-unmaximize
             */
            void unmaximize();

            /**
             * Asks to place window in the fullscreen state.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-fullscreen
             */
            void fullscreen();

            /**
             * Asks to toggle off the fullscreen state for window .
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-unfullscreen
             */
            void unfullscreen();

            /**
             * Asks to keep window above, so that it stays on top.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-keep-above
             */
            void set_keep_above(Php::Parameters &parameters);

            /**
             * Asks to keep window below, so that it stays in bottom.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-keep-below
             */
            void set_keep_below(Php::Parameters &parameters);

            /**
             * By default, windows are decorated with a title bar, resize controls, etc. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-decorated
             */
            void set_decorated(Php::Parameters &parameters);

            /**
             * Returns whether the window has been set to have decorations such as a title bar via gtk_window_set_decorated().
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-decorated
             */
            Php::Value get_decorated();

            /**
             * By default, windows have a close button in the window frame. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-deletable
             */
            void set_deletable(Php::Parameters &parameters);

            /**
             * Returns whether the window has been set to have a close button via gtk_window_set_deletable().
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-deletable
             */
            Php::Value get_deletable();

            /**
             * By setting the type hint for the window, you allow the window manager to decorate and handle the window in a way which is suitable to the function of the window in your application.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-type-hint
             */
            void set_type_hint(Php::Parameters &parameters);

            /**
             * Gets the type hint for this window. See gtk_window_set_type_hint().
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-type-hint
             */
            Php::Value get_type_hint();

            /**
             * Windows may set a hint asking the desktop environment not to display the window in the task bar. This function sets this hint.
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-skip-taskbar-hint
             */
            void set_skip_taskbar_hint(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_window_set_skip_taskbar_hint()
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-skip-taskbar-hint
             */
            Php::Value get_skip_taskbar_hint();

            /**
             * Windows may set a hint asking the desktop environment not to display the window in the pager. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-skip-pager-hint
             */
            void set_skip_pager_hint(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_window_set_skip_pager_hint()
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-skip-pager-hint
             */
            Php::Value get_skip_pager_hint();

            /**
             * Windows may set a hint asking the desktop environment to draw the users attention to the window. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-urgency-hint
             */
            void set_urgency_hint(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_window_set_urgency_hint()
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-urgency-hint
             */
            Php::Value get_urgency_hint();

            /**
             * Windows may set a hint asking the desktop environment not to receive the input focus. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-accept-focus
             */
            void set_accept_focus(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_window_set_accept_focus()
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-accept-focus
             */
            Php::Value get_accept_focus();

            /**
             * Windows may set a hint asking the desktop environment not to receive the input focus when the window is mapped. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-focus-on-map
             */
            void set_focus_on_map(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_window_set_focus_on_map()
             *
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-focus-on-map
             */
            Php::Value get_focus_on_map();
    };

#endif