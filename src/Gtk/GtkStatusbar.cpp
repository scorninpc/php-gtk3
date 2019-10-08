
#include "GtkStatusbar.h"

/**
 * Constructor
 */
GtkStatusbar_::GtkStatusbar_() = default;

/**
 * Destructor
 */
GtkStatusbar_::~GtkStatusbar_() = default;

void GtkStatusbar_::__construct()
{
	instance = (gpointer *)gtk_statusbar_new ();

}

Php::Value GtkStatusbar_::get_context_id(Php::Parameters &parameters)
{
	std::string s_context_description = parameters[0];
	gchar *context_description = (gchar *)s_context_description.c_str();

	int ret = gtk_statusbar_get_context_id (GTK_STATUSBAR(instance), context_description);

	return ret;
}

Php::Value GtkStatusbar_::push(Php::Parameters &parameters)
{
	guint context_id = (int)parameters[0];

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	int ret = gtk_statusbar_push (GTK_STATUSBAR(instance), context_id, text);

	return ret;
}

void GtkStatusbar_::pop(Php::Parameters &parameters)
{
	guint context_id = (int)parameters[0];

	gtk_statusbar_pop (GTK_STATUSBAR(instance), context_id);

}

void GtkStatusbar_::remove(Php::Parameters &parameters)
{
	guint context_id = (int)parameters[0];

	guint message_id = (int)parameters[1];

	gtk_statusbar_remove (GTK_STATUSBAR(instance), context_id, message_id);

}

void GtkStatusbar_::remove_all(Php::Parameters &parameters)
{
	guint context_id = (int)parameters[0];

	gtk_statusbar_remove_all (GTK_STATUSBAR(instance), context_id);

}

Php::Value GtkStatusbar_::get_message_area()
{
	GtkWidget *ret = gtk_statusbar_get_message_area (GTK_STATUSBAR(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

