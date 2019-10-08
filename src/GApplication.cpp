
#include "GApplication.h"
#include "GtkApplication.h"

/**
 * Constructor
 */
GApplication_::GApplication_() = default;

/**
 * Destructor
 */
GApplication_::~GApplication_() = default;

Php::Value GApplication_::id_is_valid()
{
// 	gboolean ret = g_application_id_is_valid (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::id_is_valid not implemented");
}

Php::Value GApplication_::__construct(Php::Parameters &parameters)
{
// 
// 	GApplication ret = g_application_new (G_APPLICATION(instance), flags);

// 	return ret;
	 throw Php::Exception("GApplication_::new not implemented");
}

Php::Value GApplication_::get_application_id()
{
// 	std::string ret = g_application_get_application_id (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_application_id not implemented");
}

void GApplication_::set_application_id(Php::Parameters &parameters)
{
// // 	std::string s_application_id = parameters[0];
// 	gcharapplication_id = (gchar)s_application_id.c_str();

// 	g_application_set_application_id (G_APPLICATION(instance), application_id);

	 throw Php::Exception("GApplication_::set_application_id not implemented");
}

Php::Value GApplication_::get_inactivity_timeout()
{
// 	int ret = g_application_get_inactivity_timeout (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_inactivity_timeout not implemented");
}

void GApplication_::set_inactivity_timeout(Php::Parameters &parameters)
{
// // 	guint inactivity_timeout = (int)parameters[0];

// 	g_application_set_inactivity_timeout (G_APPLICATION(instance), inactivity_timeout);

	 throw Php::Exception("GApplication_::set_inactivity_timeout not implemented");
}

Php::Value GApplication_::get_flags()
{
// 	GApplicationFlags ret = g_application_get_flags (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_flags not implemented");
}

void GApplication_::set_flags(Php::Parameters &parameters)
{
// 
// 	g_application_set_flags (G_APPLICATION(instance), flags);

	 throw Php::Exception("GApplication_::set_flags not implemented");
}

Php::Value GApplication_::get_resource_base_path()
{
// 	std::string ret = g_application_get_resource_base_path (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_resource_base_path not implemented");
}

void GApplication_::set_resource_base_path(Php::Parameters &parameters)
{
// // 	std::string s_resource_path = parameters[0];
// 	gcharresource_path = (gchar)s_resource_path.c_str();

// 	g_application_set_resource_base_path (G_APPLICATION(instance), resource_path);

	 throw Php::Exception("GApplication_::set_resource_base_path not implemented");
}

Php::Value GApplication_::get_dbus_connection()
{
// 	GDBusConnection ret = g_application_get_dbus_connection (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_dbus_connection not implemented");
}

Php::Value GApplication_::get_dbus_object_path()
{
// 	std::string ret = g_application_get_dbus_object_path (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_dbus_object_path not implemented");
}

void GApplication_::set_action_group(Php::Parameters &parameters)
{
// 
// 	g_application_set_action_group (G_APPLICATION(instance), action_group);

	 throw Php::Exception("GApplication_::set_action_group not implemented");
}

Php::Value GApplication_::get_is_registered()
{
// 	gboolean ret = g_application_get_is_registered (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_is_registered not implemented");
}

Php::Value GApplication_::get_is_remote()
{
// 	gboolean ret = g_application_get_is_remote (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_is_remote not implemented");
}

Php::Value GApplication_::_register(Php::Parameters &parameters)
{
// 
// 
// 	gboolean ret = g_application_register (G_APPLICATION(instance), cancellable, error);

// 	return ret;
	 throw Php::Exception("GApplication_::register not implemented");
}

void GApplication_::hold()
{
// 	g_application_hold (G_APPLICATION(instance));

	 throw Php::Exception("GApplication_::hold not implemented");
}

void GApplication_::release()
{
// 	g_application_release (G_APPLICATION(instance));

	 throw Php::Exception("GApplication_::release not implemented");
}

void GApplication_::quit()
{
// 	g_application_quit (G_APPLICATION(instance));

	 throw Php::Exception("GApplication_::quit not implemented");
}

void GApplication_::activate()
{
// 	g_application_activate (G_APPLICATION(instance));

	 throw Php::Exception("GApplication_::activate not implemented");
}

void GApplication_::open(Php::Parameters &parameters)
{
// 
// // 	gint n_files = (gint)parameters[1];

// // 	std::string s_hint = parameters[2];
// 	gcharhint = (gchar)s_hint.c_str();

// 	g_application_open (G_APPLICATION(instance), files, n_files, hint);

	 throw Php::Exception("GApplication_::open not implemented");
}

void GApplication_::send_notification(Php::Parameters &parameters)
{
// // 	std::string s_id = parameters[0];
// 	gcharid = (gchar)s_id.c_str();

// 
// 	g_application_send_notification (G_APPLICATION(instance), id, notification);

	 throw Php::Exception("GApplication_::send_notification not implemented");
}

void GApplication_::withdraw_notification(Php::Parameters &parameters)
{
// // 	std::string s_id = parameters[0];
// 	gcharid = (gchar)s_id.c_str();

// 	g_application_withdraw_notification (G_APPLICATION(instance), id);

	 throw Php::Exception("GApplication_::withdraw_notification not implemented");
}

Php::Value GApplication_::run(Php::Parameters &parameters)
{
	GtkApplication *app;
	if(parameters.size() > 0) {
		Php::Value object_app = parameters[0];
		GtkApplication_ *phpgtk_app = (GtkApplication_ *)object_app.implementation();
		app = GTK_APPLICATION(phpgtk_app->get_instance());
	}

	int ret = g_application_run (G_APPLICATION(app), 0, NULL);

	return ret;
}

void GApplication_::add_main_option_entries(Php::Parameters &parameters)
{
// 
// 	g_application_add_main_option_entries (G_APPLICATION(instance), entries);

	 throw Php::Exception("GApplication_::add_main_option_entries not implemented");
}

void GApplication_::add_main_option(Php::Parameters &parameters)
{
// 
// 
// 
// 
// 
// 
// 	g_application_add_main_option (G_APPLICATION(instance), long_name, short_name, flags, arg, description, arg_description);

	 throw Php::Exception("GApplication_::add_main_option not implemented");
}

void GApplication_::add_option_group(Php::Parameters &parameters)
{
// 
// 	g_application_add_option_group (G_APPLICATION(instance), group);

	 throw Php::Exception("GApplication_::add_option_group not implemented");
}

void GApplication_::set_option_context_parameter_string(Php::Parameters &parameters)
{
// // 	std::string s_parameter_string = parameters[0];
// 	gcharparameter_string = (gchar)s_parameter_string.c_str();

// 	g_application_set_option_context_parameter_string (G_APPLICATION(instance), parameter_string);

	 throw Php::Exception("GApplication_::set_option_context_parameter_string not implemented");
}

void GApplication_::set_option_context_summary(Php::Parameters &parameters)
{
// // 	std::string s_summary = parameters[0];
// 	gcharsummary = (gchar)s_summary.c_str();

// 	g_application_set_option_context_summary (G_APPLICATION(instance), summary);

	 throw Php::Exception("GApplication_::set_option_context_summary not implemented");
}

void GApplication_::set_option_context_description(Php::Parameters &parameters)
{
// // 	std::string s_description = parameters[0];
// 	gchardescription = (gchar)s_description.c_str();

// 	g_application_set_option_context_description (G_APPLICATION(instance), description);

	 throw Php::Exception("GApplication_::set_option_context_description not implemented");
}

void GApplication_::set_default()
{
// 	g_application_set_default (G_APPLICATION(instance));

	 throw Php::Exception("GApplication_::set_default not implemented");
}

Php::Value GApplication_::get_default()
{
// 	GApplication ret = g_application_get_default (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_default not implemented");
}

void GApplication_::mark_busy()
{
// 	g_application_mark_busy (G_APPLICATION(instance));

	 throw Php::Exception("GApplication_::mark_busy not implemented");
}

void GApplication_::unmark_busy()
{
// 	g_application_unmark_busy (G_APPLICATION(instance));

	 throw Php::Exception("GApplication_::unmark_busy not implemented");
}

Php::Value GApplication_::get_is_busy()
{
// 	gboolean ret = g_application_get_is_busy (G_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GApplication_::get_is_busy not implemented");
}

void GApplication_::bind_busy_property(Php::Parameters &parameters)
{
// // 	gpointer object = (gpointer)parameters[0];

// // 	std::string s_property = parameters[1];
// 	gcharproperty = (gchar)s_property.c_str();

// 	g_application_bind_busy_property (G_APPLICATION(instance), object, property);

	 throw Php::Exception("GApplication_::bind_busy_property not implemented");
}

void GApplication_::unbind_busy_property(Php::Parameters &parameters)
{
// // 	gpointer object = (gpointer)parameters[0];

// // 	std::string s_property = parameters[1];
// 	gcharproperty = (gchar)s_property.c_str();

// 	g_application_unbind_busy_property (G_APPLICATION(instance), object, property);

	 throw Php::Exception("GApplication_::unbind_busy_property not implemented");
}

