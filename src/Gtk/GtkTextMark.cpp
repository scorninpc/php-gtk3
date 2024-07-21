
#include "GtkTextMark.h"

/**
 * Constructor
 */
GtkTextMark_::GtkTextMark_() = default;

/**
 * Destructor
 */
GtkTextMark_::~GtkTextMark_() = default;

void GtkTextMark_::__construct(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gboolean left_gravity = (gboolean)parameters[1];

	instance = (gpointer *)gtk_text_mark_new (name, left_gravity);

}

void GtkTextMark_::set_visible(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_text_mark_set_visible (GTK_TEXT_MARK(instance), setting);

}

Php::Value GtkTextMark_::set_buffer()
{
	bool ret = gtk_text_mark_get_visible (GTK_TEXT_MARK(instance));

	return ret;
}

Php::Value GtkTextMark_::get_deleted()
{
	bool ret = gtk_text_mark_get_deleted (GTK_TEXT_MARK(instance));

	return ret;
}

Php::Value GtkTextMark_::get_name()
{
	std::string ret = gtk_text_mark_get_name (GTK_TEXT_MARK(instance));

	return ret;
}

Php::Value GtkTextMark_::get_buffer()
{
	GtkTextBuffer *ret = gtk_text_mark_get_buffer (GTK_TEXT_MARK(instance));

	GtkTextBuffer_ *return_parsed = new GtkTextBuffer_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextBuffer", return_parsed);
}

Php::Value GtkTextMark_::get_left_gravity()
{
	bool ret = gtk_text_mark_get_left_gravity (GTK_TEXT_MARK(instance));

	return ret;
}

