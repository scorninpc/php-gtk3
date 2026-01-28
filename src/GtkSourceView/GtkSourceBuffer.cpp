
#include "GtkSourceBuffer.h"

/**
 * Constructor
 */
GtkSourceBuffer_::GtkSourceBuffer_() = default;

/**
 * Destructor
 */
GtkSourceBuffer_::~GtkSourceBuffer_() = default;

void GtkSourceBuffer_::__construct()
{
	instance = (gpointer *)gtk_source_buffer_new (NULL);
}

void GtkSourceBuffer_::set_language(Php::Parameters &parameters)
{
	GtkSourceLanguage *language;
	if(parameters.size() > 0) {
		Php::Value object_language = parameters[0];
		GtkSourceLanguage_ *phpgtk_language = (GtkSourceLanguage_ *)object_language.implementation();
		language = GTK_SOURCE_LANGUAGE(phpgtk_language->get_instance());
	}

	gtk_source_buffer_set_language(GTK_SOURCE_BUFFER(instance), language);
}