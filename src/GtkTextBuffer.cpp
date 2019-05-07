
#include "GtkTextBuffer.h"

/**
 * Constructor
 */
GtkTextBuffer_::GtkTextBuffer_() = default;

/**
 * Destructor
 */
GtkTextBuffer_::~GtkTextBuffer_() = default;

void GtkTextBuffer_::__construct()
{
	instance = (gpointer *)gtk_text_view_new ();

}

Php::Value GtkTextBuffer_::get_line_count()
{
	gint ret = gtk_text_buffer_get_line_count (GTK_TEXT_BUFFER(instance));

	return ret;
}

Php::Value GtkTextBuffer_::get_char_count()
{
	gint ret = gtk_text_buffer_get_char_count (GTK_TEXT_BUFFER(instance));

	return ret;
}

void GtkTextBuffer_::insert(Php::Parameters &parameters)
{
	GtkTextIter *iter;
	if(parameters.size() > 0) {
		Php::Value object_iter = parameters[0];
		GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
		iter = phpgtk_iter->get_instance();
	}

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gint len = (gint)parameters[2];

	gtk_text_buffer_insert (GTK_TEXT_BUFFER(instance), iter, text, len);

}

