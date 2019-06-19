
#include "GtkAppChooserDialog.h"

/**
 * Constructor
 */
GtkAppChooserDialog_::GtkAppChooserDialog_() = default;

/**
 * Destructor
 */
GtkAppChooserDialog_::~GtkAppChooserDialog_() = default;

void GtkAppChooserDialog_::__construc(Php::Parameters &parameters)
{
	GtkWindow *parent;
	if(parameters.size() > 0) {
		Php::Value object_parent = parameters[0];
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	}

	int int_flags = (int)parameters[1];
	GtkDialogFlags flags = (GtkDialogFlags)int_flags;

	std::string s_file = parameters[2];
	gchar *path = (gchar *)s_file.c_str();

	GFile *file = g_file_new_for_path(path);

	instance = (gpointer *)gtk_app_chooser_dialog_new (parent, flags, file);

}

Php::Value GtkAppChooserDialog_::new_for_content_type(Php::Parameters &parameters)
{
	GtkWindow *parent;
	if(parameters.size() > 0) {
		Php::Value object_parent = parameters[0];
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	}

	int int_flags = (int)parameters[1];
	GtkDialogFlags flags = (GtkDialogFlags)int_flags;

	std::string s_content_type = parameters[2];
	gchar *content_type = (gchar *)s_content_type.c_str();

	GtkWidget *ret = gtk_app_chooser_dialog_new_for_content_type (parent, flags, content_type);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkAppChooserDialog", return_parsed);
}

Php::Value GtkAppChooserDialog_::get_widget()
{
	GtkWidget *ret = gtk_app_chooser_dialog_get_widget (GTK_APP_CHOOSER_DIALOG(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkAppChooserDialog_::set_heading(Php::Parameters &parameters)
{
	std::string s_heading = parameters[0];
	gchar *heading = (gchar *)s_heading.c_str();

	gtk_app_chooser_dialog_set_heading (GTK_APP_CHOOSER_DIALOG(instance), heading);

}

Php::Value GtkAppChooserDialog_::get_heading()
{
	std::string ret = gtk_app_chooser_dialog_get_heading (GTK_APP_CHOOSER_DIALOG(instance));

	return ret;
}

