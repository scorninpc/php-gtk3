
#include "GtkApplication.h"
#include "../../main.h"

/**
 * Constructor
 */
GtkApplication_::GtkApplication_() = default;

/**
 * Destructor
 */
GtkApplication_::~GtkApplication_() = default;

void GtkApplication_::__construct(Php::Parameters &parameters)
{
	std::string s_application_id = parameters[0];
	gchar *application_id = (gchar *)s_application_id.c_str();

	// ----
	phpgtk_check_parameter(parameters, 2, Php::Type::Numeric, TRUE, NULL);
	int int_flags = (int)parameters[1];
	GApplicationFlags flags = (GApplicationFlags)int_flags;


	instance = (gpointer *)gtk_application_new (application_id, flags);

}

void GtkApplication_::add_window(Php::Parameters &parameters)
{
	GtkWindow *window;
	if(parameters.size() > 0) {
		Php::Value object_window = parameters[0];
		GtkWindow_ *phpgtk_window = (GtkWindow_ *)object_window.implementation();
		window = GTK_WINDOW(phpgtk_window->get_instance());
	}

	gtk_application_add_window (GTK_APPLICATION(instance), window);

}

void GtkApplication_::remove_window(Php::Parameters &parameters)
{
	GtkWindow *window;
	if(parameters.size() > 0) {
		Php::Value object_window = parameters[0];
		GtkWindow_ *phpgtk_window = (GtkWindow_ *)object_window.implementation();
		window = GTK_WINDOW(phpgtk_window->get_instance());
	}

	gtk_application_remove_window (GTK_APPLICATION(instance), window);

}

Php::Value GtkApplication_::get_windows()
{
	GList *ret = gtk_application_get_windows (GTK_APPLICATION(instance));

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		
		ret_arr[index] = cobject_to_phpobject((gpointer *)item->data);
	}

	return ret_arr;
}

Php::Value GtkApplication_::get_window_by_id(Php::Parameters &parameters)
{
	guint id = (int)parameters[0];

	GtkWindow *ret = gtk_application_get_window_by_id (GTK_APPLICATION(instance), id);

	GtkWindow_ *return_parsed = new GtkWindow_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWindow", return_parsed);
}

Php::Value GtkApplication_::get_active_window()
{
	GtkWindow *ret = gtk_application_get_active_window (GTK_APPLICATION(instance));

	GtkWindow_ *return_parsed = new GtkWindow_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWindow", return_parsed);
}

Php::Value GtkApplication_::inhibit(Php::Parameters &parameters)
{
	GtkWindow *window;
	if(parameters.size() > 0) {
		Php::Value object_window = parameters[0];
		GtkWindow_ *phpgtk_window = (GtkWindow_ *)object_window.implementation();
		window = GTK_WINDOW(phpgtk_window->get_instance());
	}

	int int_flags = (int)parameters[1];
	GtkApplicationInhibitFlags flags = (GtkApplicationInhibitFlags)int_flags;

	std::string s_reason = parameters[2];
	gchar *reason = (gchar *)s_reason.c_str();

	int ret = gtk_application_inhibit (GTK_APPLICATION(instance), window, flags, reason);

	return ret;
}

void GtkApplication_::uninhibit(Php::Parameters &parameters)
{
	guint cookie = (int)parameters[0];

	gtk_application_uninhibit (GTK_APPLICATION(instance), cookie);

}

Php::Value GtkApplication_::is_inhibited(Php::Parameters &parameters)
{
	int int_flags = (int)parameters[0];
	GtkApplicationInhibitFlags flags = (GtkApplicationInhibitFlags)int_flags;

	bool ret = gtk_application_is_inhibited (GTK_APPLICATION(instance), flags);

	return ret;
}

Php::Value GtkApplication_::prefers_app_menu()
{
	bool ret = gtk_application_prefers_app_menu (GTK_APPLICATION(instance));

	return ret;
}

Php::Value GtkApplication_::get_app_menu()
{
	// GMenuModel ret = gtk_application_get_app_menu (GTK_APPLICATION(instance));

	// return ret;

	throw Php::Exception("GtkApplication_::get_app_menu not implemented");

	return 1;
}

void GtkApplication_::set_app_menu(Php::Parameters &parameters)
{
// 
// 	gtk_application_set_app_menu (GTK_APPLICATION(instance), app_menu);

	 throw Php::Exception("GtkApplication_::set_app_menu not implemented");
}

Php::Value GtkApplication_::get_menubar()
{
// 	GMenuModel ret = gtk_application_get_menubar (GTK_APPLICATION(instance));

// 	return ret;
	 throw Php::Exception("GtkApplication_::get_menubar not implemented");
}

void GtkApplication_::set_menubar(Php::Parameters &parameters)
{
// 
// 	gtk_application_set_menubar (GTK_APPLICATION(instance), menubar);

	 throw Php::Exception("GtkApplication_::set_menubar not implemented");
}

Php::Value GtkApplication_::get_menu_by_id(Php::Parameters &parameters)
{
// // 	std::string s_id = parameters[0];
// 	gchar *id = (gchar *)s_id.c_str();

// 	GMenu ret = gtk_application_get_menu_by_id (GTK_APPLICATION(instance), id);

// 	return ret;
	 throw Php::Exception("GtkApplication_::get_menu_by_id not implemented");
}

void GtkApplication_::add_accelerator(Php::Parameters &parameters)
{
// // 	std::string s_accelerator = parameters[0];
// 	gchar *accelerator = (gchar *)s_accelerator.c_str();

// // 	std::string s_action_name = parameters[1];
// 	gchar *action_name = (gchar *)s_action_name.c_str();

// 
// 	gtk_application_add_accelerator (GTK_APPLICATION(instance), accelerator, action_name, parameter);

	 Php::deprecated << "GtkApplication_::add_accelerator  is deprecated on Gtk 3.14";
}

void GtkApplication_::remove_accelerator(Php::Parameters &parameters)
{
// // 	std::string s_action_name = parameters[0];
// 	gchar *action_name = (gchar *)s_action_name.c_str();

// 
// 	gtk_application_remove_accelerator (GTK_APPLICATION(instance), action_name, parameter);

	 Php::deprecated << "GtkApplication_::remove_accelerator  is deprecated on Gtk 3.14";
}

Php::Value GtkApplication_::list_action_descriptions()
{
	std::string ret = *gtk_application_list_action_descriptions (GTK_APPLICATION(instance));

	return ret;
}

Php::Value GtkApplication_::get_accels_for_action(Php::Parameters &parameters)
{
	std::string s_detailed_action_name = parameters[0];
	gchar *detailed_action_name = (gchar *)s_detailed_action_name.c_str();

	std::string ret = *gtk_application_get_accels_for_action (GTK_APPLICATION(instance), detailed_action_name);

	return ret;
}

void GtkApplication_::set_accels_for_action(Php::Parameters &parameters)
{
	// std::string s_detailed_action_name = parameters[0];
	// gchar *detailed_action_name = (gchar *)s_detailed_action_name.c_str();

	// std::string s_accel = parameters[1];

	// gchar* a = (gchar*)s_accel.c_str();
	// const gchar*  accels = (const gchar* )a;

	// gtk_application_set_accels_for_action (GTK_APPLICATION(instance), detailed_action_name, accels);


	Php::deprecated << "GtkApplication_::set_accels_for_action not implemented";

}

Php::Value GtkApplication_::get_actions_for_accel(Php::Parameters &parameters)
{
	// std::string s_accel = parameters[0];

	// gchar* a = (gchar*)s_accel.c_str();
	// const gchar*  b = (const gchar* )a;



	// std::string ret = *gtk_application_get_actions_for_accel (GTK_APPLICATION(instance), b);

	// return ret;


	 Php::deprecated << "GtkApplication_::get_actions_for_accel not implemented";

	 return 1;
}

Php::Value GtkApplication_::window_new()
{
	GtkWidget *ret = gtk_application_window_new (GTK_APPLICATION(instance));

	GtkWindow_ *return_parsed = new GtkWindow_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWindow", return_parsed);
}