
#include "GtkosxApplication.h"
#include "../../main.h"

/**
 * Constructor
 */
GtkosxApplication_::GtkosxApplication_() = default;

/**
 * Destructor
 */
GtkosxApplication_::~GtkosxApplication_() = default;

void GtkosxApplication_::__construct(Php::Parameters &parameters)
{
	// instance = gtkosx_application_get();
	instance = (gpointer *) g_object_new(GTKOSX_TYPE_APPLICATION, NULL);
}

void GtkosxApplication_::set_dock_icon_pixbuf(Php::Parameters &parameters)
{
	// Get the window to set transient
	Php::Value object = parameters[0];
	if (!object.instanceOf("GdkPixbuf")) throw Php::Exception("parameter expect GdkPixbuf instance");
	GdkPixbuf_ *passedPixbuf = (GdkPixbuf_ *)object.implementation();

	gtkosx_application_set_dock_icon_pixbuf (GTKOSX_APPLICATION(instance), passedPixbuf->get_instance());
}

void GtkosxApplication_::set_use_quartz_accelerators(Php::Parameters &parameters)
{
	gboolean use_quartz_accelerators = parameters[0];

	gtkosx_application_set_use_quartz_accelerators (GTKOSX_APPLICATION(instance), use_quartz_accelerators);
}

void GtkosxApplication_::ready()
{
	gtkosx_application_ready (GTKOSX_APPLICATION(instance));
}

Php::Value GtkosxApplication_::use_quartz_accelerators()
{
	bool ret = gtkosx_application_use_quartz_accelerators (GTKOSX_APPLICATION(instance));

	return ret;
}

void GtkosxApplication_::set_menu_bar(Php::Parameters &parameters)
{
	// Get the window to set transient
	Php::Value object = parameters[0];
	if (!object.instanceOf("GtkMenuShell")) throw Php::Exception("parameter expect GtkMenuShell instance");
	GtkMenuShell_ *passedMenuShell = (GtkMenuShell_ *)object.implementation();

	gtkosx_application_set_menu_bar (GTKOSX_APPLICATION(instance), GTK_MENU_SHELL(passedMenuShell->get_instance()));
}

void GtkosxApplication_::sync_menubar()
{
	gtkosx_application_sync_menubar (GTKOSX_APPLICATION(instance));
}

void GtkosxApplication_::insert_app_menu_item(Php::Parameters &parameters)
{
	// Get the window to set transient
	Php::Value object = parameters[0];
	if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
	GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

	int index = parameters[1];

	gtkosx_application_insert_app_menu_item (GTKOSX_APPLICATION(instance), GTK_WIDGET(passedWidget->get_instance()), index);
}

void GtkosxApplication_::set_window_menu(Php::Parameters &parameters)
{
	// Get the window to set transient
	Php::Value object = parameters[0];
	if (!object.instanceOf("GtkMenuItem")) throw Php::Exception("parameter expect GtkMenuItem instance");
	GtkMenuItem_ *passedMenuItem = (GtkMenuItem_ *)object.implementation();

	gtkosx_application_set_window_menu (GTKOSX_APPLICATION(instance), GTK_MENU_ITEM(passedMenuItem->get_instance()));
}

void GtkosxApplication_::set_help_menu(Php::Parameters &parameters)
{
	// Get the window to set transient
	Php::Value object = parameters[0];
	if (!object.instanceOf("GtkMenuItem")) throw Php::Exception("parameter expect GtkMenuItem instance");
	GtkMenuItem_ *passedMenuItem = (GtkMenuItem_ *)object.implementation();

	gtkosx_application_set_help_menu (GTKOSX_APPLICATION(instance), GTK_MENU_ITEM(passedMenuItem->get_instance()));
}

void GtkosxApplication_::set_dock_menu(Php::Parameters &parameters)
{
	// Get the window to set transient
	Php::Value object = parameters[0];
	if (!object.instanceOf("GtkMenuShell")) throw Php::Exception("parameter expect GtkMenuShell instance");
	GtkMenuShell_ *passedMenuShell = (GtkMenuShell_ *)object.implementation();

	gtkosx_application_set_dock_menu (GTKOSX_APPLICATION(instance), GTK_MENU_SHELL(passedMenuShell->get_instance()));
}


void GtkosxApplication_::set_dock_icon_resource(Php::Parameters &parameters)
{
	
}

void GtkosxApplication_::attention_request(Php::Parameters &parameters)
{
	
}

void GtkosxApplication_::cancel_attention_request(Php::Parameters &parameters)
{
	int index = parameters[0];

	gtkosx_application_cancel_attention_request (GTKOSX_APPLICATION(instance), index);
}

Php::Value GtkosxApplication_::get_bundle_path()
{
	std::string ret = gtkosx_application_get_bundle_path ();

	return ret;
}

Php::Value GtkosxApplication_::get_resource_path()
{
	std::string ret = gtkosx_application_get_resource_path ();

	return ret;
}

Php::Value GtkosxApplication_::get_executable_path()
{
	std::string ret = gtkosx_application_get_executable_path ();

	return ret;
}


Php::Value GtkosxApplication_::get_bundle_id()
{
	std::string ret = gtkosx_application_get_bundle_id ();

	return ret;
}

Php::Value GtkosxApplication_::get_bundle_info(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *key = (gchar *)s_str.c_str();

	std::string ret = gtkosx_application_get_bundle_info (key);

	return ret;
}
