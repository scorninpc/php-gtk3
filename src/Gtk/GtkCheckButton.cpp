
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

	GtkCheckButton_ *return_parsed = new GtkCheckButton_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkCheckButton", return_parsed);
}

Php::Value GtkCheckButton_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_check_button_new_with_mnemonic (label);

	GtkCheckButton_ *return_parsed = new GtkCheckButton_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkCheckButton", return_parsed);
}

Php::Value GtkCheckButton_::get_active()
{
	bool ret = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(instance));

	return ret;
}

void GtkCheckButton_::set_active(Php::Parameters& parameters)
{
	gboolean is_active = (gboolean)parameters[0];

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(instance), is_active);

}

void GtkCheckButton_::toggled()
{
	gtk_toggle_button_toggled(GTK_TOGGLE_BUTTON(instance));

}