
#include "GladeApp.h"

/**
 * Constructor
 */
GladeApp_::GladeApp_() = default;

/**
 * Destructor
 */
GladeApp_::~GladeApp_() = default;

void GladeApp_::__construct()
{
// 	instance = (gpointer *)glade_app_new ();

	 throw Php::Exception("GladeApp_::__construct not implemented");}

Php::Value GladeApp_::get()
{
// 	GladeApp ret = glade_app_get ();

// 	return ret;
	 throw Php::Exception("GladeApp_::get not implemented");}

void GladeApp_::set_window()
{
// 	glade_app_set_window (GLADE_APP(instance));

	 throw Php::Exception("GladeApp_::set_window not implemented");}

Php::Value GladeApp_::get_window()
{
// 	GtkWidget *ret = glade_app_get_window (GLADE_APP(instance));

// 	GtkWidget_ *return_parsed = new GtkWidget_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkWidget", return_parsed);
	 throw Php::Exception("GladeApp_::get_window not implemented");}

Php::Value GladeApp_::get_clipboard()
{
// 	GladeClipboard ret = glade_app_get_clipboard (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_clipboard not implemented");}

void GladeApp_::add_project()
{
// 	glade_app_add_project (GLADE_APP(instance));

	 throw Php::Exception("GladeApp_::add_project not implemented");}

void GladeApp_::remove_project()
{
// 	glade_app_remove_project (GLADE_APP(instance));

	 throw Php::Exception("GladeApp_::remove_project not implemented");}

Php::Value GladeApp_::get_projects()
{
// 	GList ret = glade_app_get_projects (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_projects not implemented");}

Php::Value GladeApp_::get_config()
{
// 	GKeyFile ret = glade_app_get_config (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_config not implemented");}

Php::Value GladeApp_::is_project_loaded()
{
// 	gboolean ret = glade_app_is_project_loaded (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::is_project_loaded not implemented");}

Php::Value GladeApp_::get_project_by_path()
{
// 	GladeProject ret = glade_app_get_project_by_path (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_project_by_path not implemented");}

Php::Value GladeApp_::config_save()
{
// 	gint ret = glade_app_config_save (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::config_save not implemented");}

void GladeApp_::set_accel_group()
{
// 	glade_app_set_accel_group (GLADE_APP(instance));

	 throw Php::Exception("GladeApp_::set_accel_group not implemented");}

Php::Value GladeApp_::get_catalogs_dir()
{
// 	std::string ret = glade_app_get_catalogs_dir (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_catalogs_dir not implemented");}

Php::Value GladeApp_::get_modules_dir()
{
// 	std::string ret = glade_app_get_modules_dir (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_modules_dir not implemented");}

Php::Value GladeApp_::get_pixmaps_dir()
{
// 	std::string ret = glade_app_get_pixmaps_dir (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_pixmaps_dir not implemented");}

Php::Value GladeApp_::get_locale_dir()
{
// 	std::string ret = glade_app_get_locale_dir (GLADE_APP(instance));

// 	return ret;
	 throw Php::Exception("GladeApp_::get_locale_dir not implemented");}

