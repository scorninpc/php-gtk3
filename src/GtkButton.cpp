
#include "GtkButton.h"

GtkButton_::GtkButton_()
{
    // Php::out << "GtkButton: 1" << std::endl;
    widget = gtk_button_new();
    // Php::out << "GtkButton: 2" << std::endl;
}
GtkButton_::~GtkButton_() = default;

/**
 * Set button label
 */
void GtkButton_::set_label(Php::Parameters &parameters)
{
	std::string label = parameters[0];

	gtk_button_set_label(GTK_BUTTON(widget), label.c_str());
}

/**
 * new_with_label
 */
Php::Value GtkButton_::new_with_label(Php::Parameters &parameters)
{
	GtkButton_ *button = new GtkButton_();

	button->set_label(parameters);

	return Php::Object("GtkButton", button);
}