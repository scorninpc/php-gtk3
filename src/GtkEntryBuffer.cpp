
#include "GtkEntryBuffer.h"

/**
 * Constructor
 */
GtkEntryBuffer_::GtkEntryBuffer_() = default;

/**
 * Destructor
 */
GtkEntryBuffer_::~GtkEntryBuffer_() = default;

/**
 * Return original GtkEntryBuffer
 */
GtkEntryBuffer *GtkEntryBuffer_::get_buffer()
{
    return buffer;
}

/**
 * Set the original GtkEntryBuffer
 */
void GtkEntryBuffer_::set_buffer(GtkEntryBuffer *pased_buffer)
{
    buffer = pased_buffer;
}

/**
 *  PHP Constructor
 */
void GtkEntryBuffer_::__construct(Php::Parameters &parameters)
{
	// Cast the param
	std::string passed_text = parameters[0];
	gchar *text = (gchar *)passed_text.c_str();

	// Create the buffer
	buffer = gtk_entry_buffer_new(text, -1);
}

/**
 * Retrieves the contents of the buffer.
 */
Php::Value GtkEntryBuffer_::get_text()
{
	return gtk_entry_buffer_get_text(buffer);
}

/**
 * Sets the text in the buffer.
 */
void GtkEntryBuffer_::set_text(Php::Parameters &parameters)
{
	// Cast the param
	std::string passed_text = parameters[0];
	gchar *text = (gchar *)passed_text.c_str();

	// Create the buffer
	buffer = gtk_entry_buffer_new(text, -1);
}

/**
 * Retrieves the length in bytes of the buffer
 */
Php::Value GtkEntryBuffer_::get_bytes()
{
	long int bytes = (long int)gtk_entry_buffer_get_bytes(buffer);
	return bytes;
}

/**
 * Retrieves the length in characters of the buffer.
 */
Php::Value GtkEntryBuffer_::get_length()
{
	long int length = (long int)gtk_entry_buffer_get_length(buffer);
	return length;
}

/**
 * Retrieves the maximum allowed length of the text in buffer.
 */
Php::Value GtkEntryBuffer_::get_max_length()
{
	int length = (long int)gtk_entry_buffer_get_max_length(buffer);
	return length;
}

/**
 * Inserts n_chars characters of chars into the contents of the buffer, at position position.
 */
Php::Value GtkEntryBuffer_::insert_text(Php::Parameters &parameters)
{
	long int position = (long int) parameters[0];

	long int length = (long int) gtk_entry_buffer_insert_text (buffer, position, parameters[1], -1);
	return length;
}

/**
 * Deletes a sequence of characters from the buffer.
 */
void GtkEntryBuffer_::delete_text(Php::Parameters &parameters)
{
	long int position = (long int) parameters[0];
	long int n_chars = (long int) parameters[1];

	gtk_entry_buffer_delete_text (buffer, position, n_chars);
}