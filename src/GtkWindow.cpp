
#include "GtkWindow.h"

/**
 *  C++ constructor
 *      https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-new
 */
GtkWindow_::GtkWindow_()
{
    // Php::out << "GtkWindow: 1" << std::endl;
    widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Php::out << "GtkWindow: 2" << std::endl;
}