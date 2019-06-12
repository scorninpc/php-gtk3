
#include "GtkAppChooserButton.h"

/**
 * Constructor
 */
GtkAppChooserButton_::GtkAppChooserButton_() = default;

/**
 * Destructor
 */
GtkAppChooserButton_::~GtkAppChooserButton_() = default;

void GtkAppChooserButton_::__construct(Php::Parameters &parameters)
{
	std::string s_content_type = parameters[0];
	gchar *content_type = (gchar *)s_content_type.c_str();

	instance = (gpointer *)gtk_app_chooser_button_new (content_type);
}

void GtkAppChooserButton_::append_custom_item(Php::Parameters &parameters)
{
	// std::string s_name = parameters[0];
	// gchar *name = (gchar *)s_name.c_str();

	// std::string s_label = parameters[1];
	// gchar *label = (gchar *)s_label.c_str();


	// gtk_app_chooser_button_append_custom_item (GTK_APP_CHOOSER_BUTTON(instance), name, label, icon);

	throw Php::Exception("GtkAppChooserButton_::append_custom_item not implemented");

}

void GtkAppChooserButton_::append_separator()
{
	gtk_app_chooser_button_append_separator (GTK_APP_CHOOSER_BUTTON(instance));

}

void GtkAppChooserButton_::set_active_custom_item(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_app_chooser_button_set_active_custom_item (GTK_APP_CHOOSER_BUTTON(instance), name);

}

Php::Value GtkAppChooserButton_::get_show_default_item()
{
	gboolean ret = gtk_app_chooser_button_get_show_default_item (GTK_APP_CHOOSER_BUTTON(instance));

	return ret;
}

void GtkAppChooserButton_::set_show_default_item(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_app_chooser_button_set_show_default_item (GTK_APP_CHOOSER_BUTTON(instance), setting);

}

Php::Value GtkAppChooserButton_::get_show_dialog_item()
{
	gboolean ret = gtk_app_chooser_button_get_show_dialog_item (GTK_APP_CHOOSER_BUTTON(instance));

	return ret;
}

void GtkAppChooserButton_::set_show_dialog_item(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_app_chooser_button_set_show_dialog_item (GTK_APP_CHOOSER_BUTTON(instance), setting);

}

Php::Value GtkAppChooserButton_::get_heading()
{
	std::string ret = gtk_app_chooser_button_get_heading (GTK_APP_CHOOSER_BUTTON(instance));

	return ret;
}

void GtkAppChooserButton_::set_heading(Php::Parameters &parameters)
{
	std::string s_heading = parameters[0];
	gchar *heading = (gchar *)s_heading.c_str();

	gtk_app_chooser_button_set_heading (GTK_APP_CHOOSER_BUTTON(instance), heading);

}

