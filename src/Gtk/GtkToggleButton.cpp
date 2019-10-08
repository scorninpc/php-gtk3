
#include "GtkToggleButton.h"

/**
 * Constructor
 */
GtkToggleButton_::GtkToggleButton_() = default;

/**
 * Destructor
 */
GtkToggleButton_::~GtkToggleButton_() = default;

void GtkToggleButton_::__construct()
{
	instance = (gpointer *)gtk_toggle_button_new ();

}

Php::Value GtkToggleButton_::new_with_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_toggle_button_new_with_label (label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkToggleButton_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_toggle_button_new_with_mnemonic (label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkToggleButton_::set_mode(Php::Parameters &parameters)
{
	gboolean draw_indicator = (gboolean)parameters[0];

	gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON(instance), draw_indicator);

}

Php::Value GtkToggleButton_::get_mode()
{
	gboolean ret = gtk_toggle_button_get_mode (GTK_TOGGLE_BUTTON(instance));

	return ret;
}

void GtkToggleButton_::toggled()
{
	gtk_toggle_button_toggled (GTK_TOGGLE_BUTTON(instance));

}

Php::Value GtkToggleButton_::get_active()
{
	gboolean ret = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(instance));

	return ret;
}

void GtkToggleButton_::set_active(Php::Parameters &parameters)
{
	gboolean is_active = (gboolean)parameters[0];

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(instance), is_active);

}

Php::Value GtkToggleButton_::get_inconsistent()
{
	gboolean ret = gtk_toggle_button_get_inconsistent (GTK_TOGGLE_BUTTON(instance));

	return ret;
}

void GtkToggleButton_::set_inconsistent(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_toggle_button_set_inconsistent (GTK_TOGGLE_BUTTON(instance), setting);

}

