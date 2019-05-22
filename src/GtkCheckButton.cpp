
#include "GtkCheckButton.h"

/**
 * Constructor
 */
GtkCheckButton_::GtkCheckButton_() = default;

/**
 * Destructor
 */
GtkCheckButton_::~GtkCheckButton_() = default;

void GtkCheckButton_::__construct()
{
	instance = (gpointer *)gtk_check_button_new ();

}

Php::Value GtkCheckButton_::new_with_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_check_button_new_with_label (label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkCheckButton_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_check_button_new_with_mnemonic (label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

