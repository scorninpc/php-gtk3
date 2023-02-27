
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
	instance = (gpointer *)gtk_entry_new();
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
	GtkEntryBuffer *buffer = gtk_entry_get_buffer(GTK_ENTRY(instance));

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

    gtk_entry_set_buffer(GTK_ENTRY(instance), passedBuffer->get_buffer());
}

/**
 * Retrieves the contents of the entry widget
 */
Php::Value GtkEntry_::get_text()
{
	return gtk_entry_get_text(GTK_ENTRY(instance));
}

/**
 * Sets the text in the widget to the given value, replacing the current contents.
 */
void GtkEntry_::set_text(Php::Parameters &parameters)
{
	std::string text = parameters[0];
	gtk_entry_set_text(GTK_ENTRY(instance), text.c_str());
}

/**
 * Retrieves the current length of the text in entry.
 */
Php::Value GtkEntry_::get_text_length()
{
	return gtk_entry_get_text_length(GTK_ENTRY(instance));
}

/**
 * Sets whether the contents of the entry are visible or not
 */
void GtkEntry_::set_visibility(Php::Parameters &parameters)
{
	gtk_entry_set_visibility(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Get whether the contents of the entry are visible or not
 */
Php::Value GtkEntry_::get_visibility()
{
	return gtk_entry_get_visibility(GTK_ENTRY(instance));
}

void GtkEntry_::set_completion(Php::Parameters &parameters)
{
	GtkEntryCompletion *completion;
	if(parameters.size() > 0) {
		Php::Value object_completion = parameters[0];
		GtkEntryCompletion_ *phpgtk_completion = (GtkEntryCompletion_ *)object_completion.implementation();
		completion = GTK_ENTRY_COMPLETION(phpgtk_completion->get_instance());
	}

	gtk_entry_set_completion(GTK_ENTRY(instance), completion);
}


Php::Value GtkEntry_::get_completion()
{
	GtkEntryCompletion *ret = gtk_entry_get_completion(GTK_ENTRY(instance));

	// Create the PHP-GTK object and set GTK object
	GtkEntryCompletion_ *widget_ = new GtkEntryCompletion_();
	widget_->set_instance((gpointer *)ret);
	return Php::Object("GtkEntryCompletion", widget_);
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
	

	gtk_entry_set_invisible_char(GTK_ENTRY(instance), ch);
}

/**
 * Retrieves the character displayed in place of the real characters for entries with visibility set to false
 */
Php::Value GtkEntry_::get_invisible_char()
{
	gunichar ch = gtk_entry_get_invisible_char(GTK_ENTRY(instance));
	
	char a;
	g_unichar_to_utf8(ch, &a);

	return a;
}

/**
 * Unsets the invisible char previously set with gtk_entry_set_invisible_char()
 *
 * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-unset-invisible-char
 */
void GtkEntry_::unset_invisible_char()
{
	gtk_entry_unset_invisible_char(GTK_ENTRY(instance));
}

/**
 * Sets the maximum allowed length of the contents of the widget
 */
void GtkEntry_::set_max_length(Php::Parameters &parameters)
{
	gtk_entry_set_max_length(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Retrieves the maximum allowed length of the text in entry 
 */
Php::Value GtkEntry_::get_max_length()
{
	return gtk_entry_get_max_length(GTK_ENTRY(instance));
}

/**
 * If setting is TRUE, pressing Enter in the entry will activate the default widget for the window containing the entry.
 */
void GtkEntry_::set_activates_default(Php::Parameters &parameters)
{
	gtk_entry_set_activates_default(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Retrieves the value set by gtk_entry_set_activates_default().
 */
Php::Value GtkEntry_::get_activates_default()
{
	return gtk_entry_get_activates_default(GTK_ENTRY(instance));
}

/**
 * Sets whether the entry has a beveled frame around it.
 */
void GtkEntry_::set_has_frame(Php::Parameters &parameters)
{
	gtk_entry_set_has_frame(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Gets the value set by gtk_entry_set_has_frame().
 */
Php::Value GtkEntry_::get_has_frame()
{
	return gtk_entry_get_has_frame(GTK_ENTRY(instance));
}

/**
 * Changes the size request of the entry to be about the right size for n_chars characters.
 */
void GtkEntry_::set_width_chars(Php::Parameters &parameters)
{
	gtk_entry_set_width_chars(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Gets the value set by gtk_entry_set_width_chars().
 */
Php::Value GtkEntry_::get_width_chars()
{
	return gtk_entry_get_width_chars(GTK_ENTRY(instance));
}

/**
 * Changes the max size request of the entry to be about the right size for n_chars characters.
 */
void GtkEntry_::set_max_width_chars(Php::Parameters &parameters)
{
	gtk_entry_set_max_width_chars(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Gets the value set by gtk_entry_set_max_width_chars().
 */
Php::Value GtkEntry_::get_max_width_chars()
{
	return gtk_entry_get_max_width_chars(GTK_ENTRY(instance));
}

/**
 * Sets the alignment for the contents of the entry. This controls the horizontal positioning of the contents when the displayed text is shorter than the width of the entry.
 */
void GtkEntry_::set_alignment(Php::Parameters &parameters)
{
	double xalign = parameters[0];

	gtk_entry_set_alignment(GTK_ENTRY(instance), (float)xalign);
}

/**
 * Gets the value set by gtk_entry_set_alignment().
 */
Php::Value GtkEntry_::get_alignment()
{
	return gtk_entry_get_alignment(GTK_ENTRY(instance));
}

/**
 * Sets text to be displayed in entry when it is empty and unfocused.
 */
void GtkEntry_::set_placeholder_text(Php::Parameters &parameters)
{
	gtk_entry_set_placeholder_text(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Retrieves the text that will be displayed when entry is empty and unfocused
 */
Php::Value GtkEntry_::get_placeholder_text()
{
	return gtk_entry_get_placeholder_text(GTK_ENTRY(instance));
}

/**
 * Sets whether the text is overwritten when typing in the GtkEntry.
 */
void GtkEntry_::set_overwrite_mode(Php::Parameters &parameters)
{
	return gtk_entry_set_overwrite_mode(GTK_ENTRY(instance), parameters[0]);
}

/**
 * Gets the value set by gtk_entry_set_overwrite_mode().
 */
Php::Value GtkEntry_::get_overwrite_mode()
{
	return gtk_entry_get_overwrite_mode(GTK_ENTRY(instance));
}

/**
 * Causes the entry’s progress indicator to “fill in” the given fraction of the bar. The fraction should be between 0.0 and 1.0, inclusive.
 */
void GtkEntry_::set_progress_fraction(Php::Parameters &parameters)
{
	double fraction = parameters[0];

	gtk_entry_set_progress_fraction(GTK_ENTRY(instance), (float)fraction);
}

/**
 * Returns the current fraction of the task that’s been completed. See gtk_entry_set_progress_fraction().
 */
Php::Value GtkEntry_::get_progress_fraction()
{
	return gtk_entry_get_progress_fraction(GTK_ENTRY(instance));
}

/**
 * Sets the fraction of total entry width to move the progress bouncing block for each call to gtk_entry_progress_pulse().
 */
void GtkEntry_::set_progress_pulse_step(Php::Parameters &parameters)
{
	double fraction = parameters[0];

	gtk_entry_set_progress_pulse_step(GTK_ENTRY(instance), (float)fraction);
}

/**
 * Retrieves the pulse step set with gtk_entry_set_progress_pulse_step().
 */
Php::Value GtkEntry_::get_progress_pulse_step()
{
	return gtk_entry_get_progress_pulse_step(GTK_ENTRY(instance));
}

/**
 * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-progress-pulse
 */
void GtkEntry_::progress_pulse()
{
	return gtk_entry_progress_pulse(GTK_ENTRY(instance));
}


void GtkEntry_::set_editable(Php::Parameters& parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_editable_set_editable(GTK_EDITABLE(instance), setting);

}

Php::Value GtkEntry_::get_selection_bounds()
{
	gint start_pos, end_pos;;

	gboolean ret = gtk_editable_get_selection_bounds (GTK_EDITABLE(instance), &start_pos, &end_pos);

	if(!ret) {
		return ret;
	}

	Php::Value arr;

	arr[0] = start_pos;
	arr[1] = end_pos;

	return arr;
}


void GtkEntry_::set_position(Php::Parameters& parameters)
{
	// Cast GtkAlign param
	int a = parameters[0];
	GtkWindowPosition passedCasted = (GtkWindowPosition)a;

	//
	gtk_editable_set_position(GTK_EDITABLE(instance), passedCasted);
}

void GtkEntry_::select_region(Php::Parameters& parameters)
{
	gint start_pos = parameters[0]; 
	gint end_pos = parameters[1];

	gtk_editable_select_region(GTK_EDITABLE(instance), start_pos, end_pos);
}

void GtkEntry_::delete_selection()
{
	gtk_editable_delete_selection(GTK_EDITABLE(instance));
}