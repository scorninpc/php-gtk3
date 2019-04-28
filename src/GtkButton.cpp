
#include "GtkButton.h"

GtkButton_::GtkButton_() = default;
GtkButton_::~GtkButton_() = default;

/**
 *  PHP Constructor
 */
void GtkButton_::__construct()
{
    instance = (gpointer *)gtk_button_new();
}

/**
 * Set button label
 */
void GtkButton_::set_label(Php::Parameters &parameters)
{
	std::string label = parameters[0];

	gtk_button_set_label(GTK_BUTTON(instance), label.c_str());
}

/**
 * Fetches the text from the label of the button, as set by gtk_button_set_label()
 */
Php::Value GtkButton_::get_label()
{
	return gtk_button_get_label(GTK_BUTTON(instance));
}

/**
 * new_with_label
 */
Php::Value GtkButton_::new_with_label(Php::Parameters &parameters)
{
	GtkButton_ *button = new GtkButton_();
	button->__construct();

	button->set_label(parameters);

	return Php::Object("GtkButton", button);
}

/**
 * Creates a new GtkButton containing a label. If characters in label are preceded by an underscore, they are underlined.
 */
Php::Value GtkButton_::new_with_mnemonic(Php::Parameters &parameters)
{
	// Create the gtk button
	GtkWidget *button = gtk_button_new_with_mnemonic(parameters[0]);
	
	// Create the PHP-GTK object and set GTK object
	GtkButton_ *button_ = new GtkButton_();
	button_->set_instance((gpointer *)button);

	// Return PHP-GTK object
	return Php::Object("GtkButton", button_);
}

/**
 * Emits a “clicked” signal to the given GtkButton.
 */
void GtkButton_::clicked()
{
	gtk_button_clicked(GTK_BUTTON(instance));
}


/**
 * If true, an underline in the text of the button label indicates the next character should be used for the mnemonic accelerator key.
 */
void GtkButton_::set_use_underline(Php::Parameters &parameters)
{
	gtk_button_set_use_underline(GTK_BUTTON(instance), parameters[0]);
}

/**
 * Returns whether an embedded underline in the button label indicates a mnemonic
 */
Php::Value GtkButton_::get_use_underline()
{
	return gtk_button_get_use_underline(GTK_BUTTON(instance));
}