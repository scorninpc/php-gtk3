
#include "GtkWindow.h"

/**
 *  C++ constructor
 *      https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-new
 */
GtkWindow_::GtkWindow_() = default;
GtkWindow_::~GtkWindow_() = default;

/**
 *  PHP Constructor
 */
void GtkWindow_::__construct(Php::Parameters &parameters)
{
    // Verify if has window type parameter
    int int_window_type = 0;
    if(parameters.size() >= 1) {
        int_window_type = parameters[0];
    }

    // Create the box
    widget = gtk_window_new((GtkWindowType)int_window_type);
}

/**
 * Sets the title of the GtkWindow
 */
void GtkWindow_::set_title(Php::Parameters &parameters)
{
    std::string title = parameters[0];

    gtk_window_set_title(GTK_WINDOW(widget), title.c_str());
}

/**
 * Retrieves the title of the window
 *
 * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-get-title
 */
Php::Value GtkWindow_::get_title()
{
    // 
    return gtk_window_get_title(GTK_WINDOW(widget));
}

/**
 * Sets the default size of a window
 */
void GtkWindow_::set_default_size(Php::Parameters &parameters)
{
    // Verify sizes
    int width = parameters[0];
    int height = parameters[1];

    // Set default size
    gtk_window_set_default_size(GTK_WINDOW(widget), width, height);
}

/**
 * Gets the default size of the window
 */
Php::Value GtkWindow_::get_default_size()
{
    // Verify sizes
    int width = -1;
    int height = -1;

    // Set default size
    gtk_window_get_default_size(GTK_WINDOW(widget), &width, &height);

    // Cria o retorno
    Php::Value arr;
    arr["width"] = width;
    arr["height"] = height;

    return arr;
}

/**
 * Sets whether the user can resize a window.
 */
void GtkWindow_::set_resizable(Php::Parameters &parameters)
{
    //
    gtk_window_set_resizable(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Sets whether the user can resize a window.
 */
Php::Value GtkWindow_::get_resizable()
{
    // 
    return gtk_window_get_resizable(GTK_WINDOW(widget));
}

/**
 * Activates the current focused widget within the window.
 */
Php::Value GtkWindow_::activate_focus()
{
    // 
    return gtk_window_activate_focus(GTK_WINDOW(widget));
}

/**
 * Activates the default widget for the window
 */
Php::Value GtkWindow_::activate_default()
{
    // 
    return gtk_window_activate_default(GTK_WINDOW(widget));
}

/**
 * Sets a window modal or non-modal
 */
void GtkWindow_::set_modal(Php::Parameters &parameters)
{
    //
    gtk_window_set_modal(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Gets a window modal or non-modal
 */
Php::Value GtkWindow_::get_modal()
{
    // 
    return gtk_window_get_modal(GTK_WINDOW(widget));
}

/**
 * Sets a position constraint for this window
 */
void GtkWindow_::set_position(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GtkWindowPosition passedCasted = (GtkWindowPosition)a;

    //
    gtk_window_set_position(GTK_WINDOW(widget), passedCasted);
}

/**
 *  Gets a position coordinates for this window
 */
Php::Value GtkWindow_::get_position()
{
    // Verify sizes
    int x = -1;
    int y = -1;

    // Set default size
    gtk_window_get_position(GTK_WINDOW(widget), &x, &y);

    // Cria o retorno
    Php::Value arr;
    arr["x"] = x;
    arr["y"] = y;

    return arr;
}

/**
 * Dialog windows should be set transient for the main application window they were spawned from
 *
 */
void GtkWindow_::set_transient_for(Php::Parameters &parameters)
{
    // Get the window to set transient
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWindow")) throw Php::Exception("parameter expect GtkWindow instance");
    GtkWindow_ *passedWindow = (GtkWindow_ *)object.implementation();

    gtk_window_set_transient_for(GTK_WINDOW(widget), GTK_WINDOW(passedWindow->get_widget()));
}

/**
 * Fetches the transient parent for this window
 */
Php::Value GtkWindow_::get_transient_for()
{
    GtkWindow *returnedWindow = gtk_window_get_transient_for(GTK_WINDOW(widget));

    GtkWindow_ *returnWindow = new GtkWindow_();
    returnWindow->set_widget(GTK_WIDGET(returnedWindow));

    return Php::Object("GtkWindow", returnWindow);
}

/**
 * If setting is TRUE, then destroying the transient parent of window will also destroy window itself
 *
 * @todo not tested
 */
void GtkWindow_::set_destroy_with_parent(Php::Parameters &parameters)
{
    gtk_window_set_destroy_with_parent(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Returns whether the window will be destroyed with its transient parent
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_destroy_with_parent()
{
    return gtk_window_get_destroy_with_parent(GTK_WINDOW(widget));
}

/**
 * If setting is TRUE, then window will request that it’s titlebar should be hidden when maximized
 *
 * @todo not tested
 */
void GtkWindow_::set_hide_titlebar_when_maximized(Php::Parameters &parameters)
{
    gtk_window_set_hide_titlebar_when_maximized(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Returns whether the window has requested to have its titlebar hidden when maximized
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_hide_titlebar_when_maximized()
{
    return gtk_window_get_hide_titlebar_when_maximized(GTK_WINDOW(widget));
}

/**
 * Returns whether the window is part of the current active toplevel.
 *
 * @todo not tested
 */
Php::Value GtkWindow_::is_active()
{
    return gtk_window_is_active(GTK_WINDOW(widget));
}

/**
 * Retrieves the current maximized state of window .
 *
 * @todo not tested
 */
Php::Value GtkWindow_::is_maximized()
{
    return gtk_window_is_maximized(GTK_WINDOW(widget));
}

/**
 * Returns whether the input focus is within this GtkWindow.
 *
 * @todo not tested
 */
Php::Value GtkWindow_::has_toplevel_focus()
{
    return gtk_window_has_toplevel_focus(GTK_WINDOW(widget));
}

/**
 * Adds a mnemonic to this window.
 *
 * @todo not tested
 */
void GtkWindow_::add_mnemonic(Php::Parameters &parameters)
{
    // Get keyval
    int keyval = parameters[0];

    // Convert object to PHP-GTK 
    Php::Value object = parameters[1];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWindow = (GtkWidget_ *)object.implementation();

    gtk_window_add_mnemonic(GTK_WINDOW(widget), keyval, passedWindow->get_widget());
}

/**
 * Removes a mnemonic to this window.
 *
 * @todo not tested
 */
void GtkWindow_::remove_mnemonic(Php::Parameters &parameters)
{
    // Get keyval
    int keyval = parameters[0];

    // Convert object to PHP-GTK 
    Php::Value object = parameters[1];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWindow = (GtkWidget_ *)object.implementation();

    gtk_window_remove_mnemonic(GTK_WINDOW(widget), keyval, passedWindow->get_widget());
}

/**
 * Activates the targets associated with the mnemonic.
 *
 * @todo not tested
 */
Php::Value GtkWindow_::mnemonic_activate(Php::Parameters &parameters)
{
    // Get keyval
    int keyval = parameters[0];

    // Cast GdkModifierType param
    int a = parameters[1];
    GdkModifierType passedCasted = (GdkModifierType)a;

    return gtk_window_mnemonic_activate(GTK_WINDOW(widget), keyval, passedCasted);
}

/**
 * Sets the mnemonic modifier for this window.
 *
 * @todo not tested
 */
void GtkWindow_::set_mnemonic_modifier(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GdkModifierType passedCasted = (GdkModifierType)a;

    return gtk_window_set_mnemonic_modifier(GTK_WINDOW(widget), passedCasted);
}

/**
 * If focus is not the current focus widget, and is focusable, sets it as the focus widget for the window
 *
 * @todo not tested
 */
void GtkWindow_::set_focus(Php::Parameters &parameters)
{
    // Convert object to PHP-GTK 
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    gtk_window_set_focus(GTK_WINDOW(widget), passedWidget->get_widget());
}

/**
 * Retrieves the current focused widget within the window
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_focus()
{
    GtkWidget *returnedWidget = gtk_window_get_focus(GTK_WINDOW(widget));

    GtkWidget_ *returnWidget = new GtkWidget_();
    returnWidget->set_widget(GTK_WIDGET(returnedWidget));

    return Php::Object("GtkWidget", returnWidget);
}

/**
 * If focus is not the current focus widget, and is focusable, sets it as the focus widget for the window
 *
 * @todo not tested
 */
void GtkWindow_::set_default(Php::Parameters &parameters)
{
    // Convert object to PHP-GTK 
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    gtk_window_set_default(GTK_WINDOW(widget), passedWidget->get_widget());
}

/**
 * Retrieves the current focused widget within the window
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_default_widget()
{
    GtkWidget *returnedWidget = gtk_window_get_default_widget(GTK_WINDOW(widget));

    GtkWidget_ *returnWidget = new GtkWidget_();
    returnWidget->set_widget(GTK_WIDGET(returnedWidget));

    return Php::Object("GtkWidget", returnWidget);
}

/**
 * Requests that the window is closed, similar to what happens when a window manager close button is clicked.
 */
void GtkWindow_::close()
{
    gtk_window_close(GTK_WINDOW(widget));
}

/**
 * Asks to iconify (i.e. minimize) the specified window
 */
void GtkWindow_::iconify()
{
    gtk_window_iconify(GTK_WINDOW(widget));
}

/**
 * Asks to deiconify (i.e. unminimize) the specified window
 */
void GtkWindow_::deiconify()
{
    gtk_window_deiconify(GTK_WINDOW(widget));
}

/**
 * Asks to stick window , which means that it will appear on all user desktops
 */
void GtkWindow_::stick()
{
    gtk_window_stick(GTK_WINDOW(widget));
}

/**
 * Asks to unstick window , which means that it will appear on only one of the user’s desktops.
 */
void GtkWindow_::unstick()
{
    gtk_window_unstick(GTK_WINDOW(widget));
}

/**
 * Asks to maximize window , so that it becomes full-screen.
 */
void GtkWindow_::maximize()
{
    gtk_window_maximize(GTK_WINDOW(widget));
}

/**
 * Asks to unmaximize window
 */
void GtkWindow_::unmaximize()
{
    gtk_window_unmaximize(GTK_WINDOW(widget));
}

/**
 * Asks to place window in the fullscreen state.
 */
void GtkWindow_::fullscreen()
{
    gtk_window_fullscreen(GTK_WINDOW(widget));
}

/**
 * Asks to toggle off the fullscreen state for window.
 */
void GtkWindow_::unfullscreen()
{
    gtk_window_unfullscreen(GTK_WINDOW(widget));
}

/**
 * Asks to keep window above, so that it stays on top.
 */
void GtkWindow_::set_keep_above(Php::Parameters &parameters)
{
    // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }

    gtk_window_set_keep_above(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Asks to keep window below, so that it stays in bottom.
 */
void GtkWindow_::set_keep_below(Php::Parameters &parameters)
{
     // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }

    gtk_window_set_keep_below(GTK_WINDOW(widget), parameters[0]);
}

/**
 * By default, windows are decorated with a title bar, resize controls, etc. 
 */
void GtkWindow_::set_decorated(Php::Parameters &parameters)
{
     // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }

    gtk_window_set_decorated(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Returns whether the window has been set to have decorations such as a title bar via gtk_window_set_decorated().
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_decorated()
{
    return gtk_window_get_decorated(GTK_WINDOW(widget));
}

/**
 * By default, windows have a close button in the window frame. 
 */
void GtkWindow_::set_deletable(Php::Parameters &parameters)
{
     // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }
    
    gtk_window_set_deletable(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Returns whether the window has been set to have a close button via gtk_window_set_deletable().
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_deletable()
{
    return gtk_window_get_deletable(GTK_WINDOW(widget));
}

/**
 * By setting the type hint for the window, you allow the window manager to decorate and handle the window in a way which is suitable to the function of the window in your application.
 */
void GtkWindow_::set_type_hint(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GdkWindowTypeHint passedCasted = (GdkWindowTypeHint)a;

    return gtk_window_set_type_hint(GTK_WINDOW(widget), passedCasted);
}

/**
 * Gets the type hint for this window. See gtk_window_set_type_hint().
 */
Php::Value GtkWindow_::get_type_hint()
{
    // 
    return gtk_window_get_type_hint(GTK_WINDOW(widget));
}

/**
 * Windows may set a hint asking the desktop environment not to display the window in the task bar. This function sets this hint.
 */
void GtkWindow_::set_skip_taskbar_hint(Php::Parameters &parameters)
{
     // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }
    
    gtk_window_set_skip_taskbar_hint(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Gets the value set by gtk_window_set_skip_taskbar_hint()
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_skip_taskbar_hint()
{
    return gtk_window_get_skip_taskbar_hint(GTK_WINDOW(widget));
}

/**
 * Windows may set a hint asking the desktop environment not to display the window in the pager. 
 *
 * @todo not tested
 */
void GtkWindow_::set_skip_pager_hint(Php::Parameters &parameters)
{
     // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }
    
    gtk_window_set_skip_pager_hint(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Gets the value set by gtk_window_set_skip_pager_hint()
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_skip_pager_hint()
{
    return gtk_window_get_skip_pager_hint(GTK_WINDOW(widget));
}

/**
 * Windows may set a hint asking the desktop environment to draw the users attention to the window. 
 *
 * @todo not tested
 */
void GtkWindow_::set_urgency_hint(Php::Parameters &parameters)
{
     // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }
    
    gtk_window_set_urgency_hint(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Gets the value set by gtk_window_set_urgency_hint()
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_urgency_hint()
{
    return gtk_window_get_urgency_hint(GTK_WINDOW(widget));
}

/**
 * Windows may set a hint asking the desktop environment not to receive the input focus. 
 *
 * @todo not tested
 */
void GtkWindow_::set_accept_focus(Php::Parameters &parameters)
{
     // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }
    
    gtk_window_set_accept_focus(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Gets the value set by gtk_window_set_accept_focus()
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_accept_focus()
{
    return gtk_window_get_accept_focus(GTK_WINDOW(widget));
}

/**
 * Windows may set a hint asking the desktop environment not to receive the input focus when the window is mapped. 
 *
 * @todo not tested
 */
void GtkWindow_::set_focus_on_map(Php::Parameters &parameters)
{
    // Verify parameter
    if(parameters.size() == 1) {
        throw Php::Exception("parameter 1 must be a boolean");
    }
    
    gtk_window_set_focus_on_map(GTK_WINDOW(widget), parameters[0]);
}

/**
 * Gets the value set by gtk_window_set_focus_on_map()
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_focus_on_map()
{
    return gtk_window_get_focus_on_map(GTK_WINDOW(widget));
}

/**
 * Sets up the icon representing a GtkWindow.
 */
void GtkWindow_::set_icon(Php::Parameters &parameters)
{
    // Get the window to set transient
    Php::Value object = parameters[0];
    if (!object.instanceOf("GdkPixbuf")) throw Php::Exception("parameter expect GdkPixbuf instance");
    GdkPixbuf_ *passedPixbuf = (GdkPixbuf_ *)object.implementation();

    gtk_window_set_icon(GTK_WINDOW(widget), passedPixbuf->get_pixbuf());
}

/**
 * Gets up the icon representing a GtkWindow.
 *
 * @todo not tested
 */
Php::Value GtkWindow_::get_icon()
{
    GdkPixbuf *returnedPixbuf = gtk_window_get_icon(GTK_WINDOW(widget));

    GdkPixbuf_ *returnPixbuf = new GdkPixbuf_();
    returnPixbuf->set_pixbuf(returnedPixbuf);

    return Php::Object("GdkPixbuf", returnPixbuf);
}

/*
 * Sets the icon for window from file
 */
Php::Value GtkWindow_::set_icon_from_file(Php::Parameters &parameters)
{
   

    std::string filename = parameters[0];

    return gtk_window_set_icon_from_file(GTK_WINDOW(widget), filename.c_str(), NULL);
}