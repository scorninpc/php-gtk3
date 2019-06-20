
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

Php::Value GtkAppChooserDialog_::get_app_info()
{

	GAppInfo *appinfo = gtk_app_chooser_get_app_info(GTK_APP_CHOOSER(instance));

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["id"] = g_app_info_get_id(appinfo);
	arr[1] = arr["name"] = g_app_info_get_name(appinfo);
	arr[2] = arr["display_name"] = g_app_info_get_display_name(appinfo);
	arr[3] = arr["description"] = g_app_info_get_description(appinfo);
	arr[4] = arr["executable"] = g_app_info_get_executable(appinfo);
	arr[5] = arr["commandline"] = g_app_info_get_commandline(appinfo);
	arr[6] = arr["icon"] = g_icon_to_string(g_app_info_get_icon(appinfo));
	arr[7] = arr["supports_files"] = g_app_info_supports_files(appinfo);
	arr[8] = arr["supports_uris"] = g_app_info_supports_uris(appinfo);
	arr[9] = arr["should_show"] = g_app_info_should_show(appinfo);
	arr[10] = arr["can_delete"] = g_app_info_can_delete(appinfo);
	arr[11] = arr["can_remove_supports_type"] = g_app_info_can_remove_supports_type(appinfo);
	// arr[12] = arr["supported_types"] = g_app_info_get_supported_types(appinfo);

	return arr;
}