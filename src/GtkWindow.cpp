
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
 * Sets the default size of a window
 *      https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-default-size
 */
void GtkWindow_::set_default_size(Php::Parameters &parameters)
{
  // Verify sizes
    int width = parameters[0];
    int height = parameters[1];

     // Set default size
    gtk_window_set_default_size(GTK_WINDOW(widget), width, height);
}