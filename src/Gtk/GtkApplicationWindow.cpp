

#include "GtkApplicationWindow.h"

GtkApplicationWindow_::GtkApplicationWindow_() = default;
GtkApplicationWindow_::~GtkApplicationWindow_() = default;

void GtkApplicationWindow_::set_show_menubar(Php::Parameters &parameters)
{
	gboolean show_menubar = (gboolean)parameters[0];

	gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(instance), show_menubar);
}

Php::Value GtkApplicationWindow_::get_show_menubar()
{
	bool ret = gtk_application_window_get_show_menubar(GTK_APPLICATION_WINDOW(instance));

	return ret;
}