
#include "GtkIconTheme.h"

/**
 * Constructor
 */
GtkIconTheme_::GtkIconTheme_() = default;

/**
 * Destructor
 */
GtkIconTheme_::~GtkIconTheme_() = default;

void GtkIconTheme_::__construct()
{
	instance = (gpointer *)gtk_icon_theme_new ();
}

Php::Value GtkIconTheme_::get_default()
{
	GtkIconTheme *ret = gtk_icon_theme_get_default();

	GtkIconTheme_ *return_parsed = new GtkIconTheme_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkIconTheme", return_parsed);
}

Php::Value GtkIconTheme_::get_for_screen(Php::Parameters &parameters)
{
	Php::Value object_screen = parameters[0];
	GdkScreen *screen;
	if (object_screen.instanceOf("GdkScreen")) {
		GdkScreen_ *phpgtk_screen = (GdkScreen_ *)object_screen.implementation();
		screen = GDK_SCREEN(phpgtk_screen->get_instance());
	}

	GtkIconTheme *ret = gtk_icon_theme_get_for_screen(screen);

	GtkIconTheme_ *return_parsed = new GtkIconTheme_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkIconTheme", return_parsed);
}

Php::Value GtkIconTheme_::has_icon(Php::Parameters &parameters)
{
	std::string s_icon_name = parameters[0];
	gchar* icon_name = (gchar*)s_icon_name.c_str();

	bool ret = gtk_icon_theme_has_icon(GTK_ICON_THEME(instance), icon_name);

	return ret;

}

Php::Value GtkIconTheme_::list_icons(Php::Parameters &parameters)
{
	gchar* context = NULL;
	if(parameters.size() > 0) {
		std::string s_context = parameters[0];
		context = (gchar*)s_context.c_str();
	}

	GList* ret = gtk_icon_theme_list_icons(GTK_ICON_THEME(instance), context);

	// convert array
	Php::Value ret_arr;
	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		ret_arr[index] = (char *) item->data;
	}

	return ret_arr;
}

void GtkIconTheme_::add_resource_path(Php::Parameters &parameters)
{
	std::string s_path = parameters[0];
	gchar* path = (gchar*)s_path.c_str();

	gtk_icon_theme_add_resource_path(GTK_ICON_THEME(instance), path);
}

void GtkIconTheme_::append_search_path(Php::Parameters &parameters)
{
	std::string s_path = parameters[0];
	gchar* path = (gchar*)s_path.c_str();

	gtk_icon_theme_append_search_path(GTK_ICON_THEME(instance), path);
}

void GtkIconTheme_::prepend_search_path(Php::Parameters &parameters)
{
	std::string s_path = parameters[0];
	gchar* path = (gchar*)s_path.c_str();

	gtk_icon_theme_prepend_search_path(GTK_ICON_THEME(instance), path);
}