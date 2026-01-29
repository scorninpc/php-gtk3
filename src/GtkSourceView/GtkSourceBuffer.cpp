
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

Php::Value GtkSourceBuffer_::new_with_language(Php::Parameters &parameters)
{
	if(parameters.size() < 1) {
		throw Php::Exception("Parameter language is required");
	}

	// unpack object
	Php::Value object_language = parameters[0];
	GtkSourceLanguage_ *phpgtk_language = (GtkSourceLanguage_ *)object_language.implementation();
	GtkSourceLanguage *language = GTK_SOURCE_LANGUAGE(phpgtk_language->get_instance());


	// create the GtkSourceBuffer
	GtkSourceBuffer *ret = gtk_source_buffer_new_with_language(language);
	if(ret == nullptr) {
		return Php::Value();
	}

	// pack and return object
	GtkSourceBuffer_ *return_parsed = new GtkSourceBuffer_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkSourceBuffer", return_parsed);
}

void GtkSourceBuffer_::change_case(Php::Parameters &parameters)
{
	if(parameters.size() < 3) {
		throw Php::Exception("parameters case_type, start and end are required");
	}

	// unpack case_type (enum or int)
	GtkSourceChangeCaseType case_type = (GtkSourceChangeCaseType)(int)parameters[0];

	// unpack start GtkTextIter object
	Php::Value object_start = parameters[1];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = (GtkTextIter ) phpgtk_start->get_instance();

	// unpack end GtkTextIter object
	Php::Value object_end = parameters[2];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = (GtkTextIter ) phpgtk_end->get_instance();

	// call gtk function
	gtk_source_buffer_change_case(
		GTK_SOURCE_BUFFER(instance),
		case_type,
		&start,
		&end
	);
}
