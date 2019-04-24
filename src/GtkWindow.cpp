
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