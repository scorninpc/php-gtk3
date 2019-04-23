
#include "GtkEntry.h"

/**
 *  C++ constructor and destructor
 */
GtkEntry_::GtkEntry_() = default;
GtkEntry_::~GtkEntry_() = default;

/**
 *  PHP Constructor
 */
void GtkEntry_::__construct()
{
	// Create the GtkEntry
	widget = gtk_entry_new();
}

/**
 * Creates a new entry with the specified text buffer.
 */
Php::Value GtkEntry_::new_with_buffer(Php::Parameters &parameters)
{
	GtkEntry_ *entry = new GtkEntry_();
	entry->__construct();

	entry->set_buffer(parameters);

	return Php::Object("GtkEntry", entry);
}

/**
 * Get the GtkEntryBuffer object which holds the text for this widget.
 */
Php::Value GtkEntry_::get_buffer()
{
	GtkEntryBuffer *buffer = gtk_entry_get_buffer(GTK_ENTRY(widget));

	GtkEntryBuffer_ *returnedBuffer = new GtkEntryBuffer_();
	returnedBuffer->set_buffer(buffer);

	return Php::Object("GtkEntryBuffer", returnedBuffer);
}

/**
 * Set the GtkEntryBuffer object which holds the text for this widget.
 */
void GtkEntry_::set_buffer(Php::Parameters &parameters)
{
	// Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkEntryBuffer")) throw Php::Exception("parameter expect GtkEntryBuffer instance");
    GtkEntryBuffer_ *passedBuffer = (GtkEntryBuffer_ *)object.implementation();

    gtk_entry_set_buffer(GTK_ENTRY(widget), passedBuffer->get_buffer());
}

/**
 * Retrieves the contents of the entry widget
 */
Php::Value GtkEntry_::get_text()
{
	return gtk_entry_get_text(GTK_ENTRY(widget));
}

/**
 * Sets the text in the widget to the given value, replacing the current contents.
 */
void GtkEntry_::set_text(Php::Parameters &parameters)
{
	gtk_entry_set_text(GTK_ENTRY(widget), parameters[0]);
}

/**
 * Retrieves the current length of the text in entry.
 */
Php::Value GtkEntry_::get_text_length()
{
	return gtk_entry_get_text_length(GTK_ENTRY(widget));
}

/**
 * Sets whether the contents of the entry are visible or not
 */
void GtkEntry_::set_visibility(Php::Parameters &parameters)
{
	gtk_entry_set_visibility(GTK_ENTRY(widget), parameters[0]);
}

/**
 * Sets the character to use in place of the actual text when gtk_entry_set_visibility()
 */
void GtkEntry_::set_invisible_char(Php::Parameters &parameters)
{
	// Cast string to gunichar
	std::string string = parameters[0];
	char *a = (char *)string.c_str();
	gunichar ch = g_utf8_get_char(a);
	

	gtk_entry_set_invisible_char(GTK_ENTRY(widget), ch);
}

/**
 * Unsets the invisible char previously set with gtk_entry_set_invisible_char()
 *
 * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-unset-invisible-char
 */
void GtkEntry_::unset_invisible_char()
{
	gtk_entry_unset_invisible_char(GTK_ENTRY(widget));
}

/**
 * Sets the maximum allowed length of the contents of the widget
 */
void GtkEntry_::set_max_length(Php::Parameters &parameters)
{
	gtk_entry_set_max_length(GTK_ENTRY(widget), parameters[0]);
}

/**
 * If setting is TRUE, pressing Enter in the entry will activate the default widget for the window containing the entry.
 */
void GtkEntry_::set_activates_default(Php::Parameters &parameters)
{
	gtk_entry_set_activates_default(GTK_ENTRY(widget), parameters[0]);
}

/**
 * Retrieves the value set by gtk_entry_set_activates_default().
 */
Php::Value GtkEntry_::get_activates_default()
{
	return gtk_entry_get_activates_default(GTK_ENTRY(widget));
}

/**
 * Sets whether the entry has a beveled frame around it.
 */
void GtkEntry_::set_has_frame(Php::Parameters &parameters)
{
	gtk_entry_set_has_frame(GTK_ENTRY(widget), parameters[0]);
}

/**
 * Gets the value set by gtk_entry_set_has_frame().
 */
Php::Value GtkEntry_::get_has_frame()
{
	return gtk_entry_get_has_frame(GTK_ENTRY(widget));
}