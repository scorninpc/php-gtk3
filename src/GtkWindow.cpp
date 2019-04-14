#include <phpcpp.h>
#include <iostream>

#include <gtk/gtk.h>

#include "GtkWidget.cpp"

/**
 *  
 */
class GtkWindow_ : public GtkWidget_
{
    public:
        /**
         *  C++ constructor
         *      https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-new
         */
        GtkWindow_()
        {
            // Php::out << "GtkWindow: 1" << std::endl;
            widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
            // Php::out << "GtkWindow: 2" << std::endl;
        }
};