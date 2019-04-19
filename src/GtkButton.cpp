
#include "GtkButton.h"

GtkButton_::GtkButton_(){
    // Php::out << "GtkButton: 1" << std::endl;
    widget = gtk_button_new();
    // Php::out << "GtkButton: 2" << std::endl;
}
GtkButton_::~GtkButton_() = default;