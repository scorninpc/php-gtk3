
#ifndef _PHPGTK_GTKENTRY_H_
#define _PHPGTK_GTKENTRY_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkWidget.h"
    #include "GtkEntryBuffer.h"
    #include "GtkEntryCompletion.h"

    /**
     * 
     */
    class GtkEntry_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkEntry_();
            virtual ~GtkEntry_();

            /**
             * PHP Construct
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-new
             */
            void __construct();

            /**
             * Creates a new entry with the specified text buffer.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-new-with-buffer
             */
            static Php::Value new_with_buffer(Php::Parameters &parameters);

            /**
             * Get the GtkEntryBuffer object which holds the text for this widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-buffer
             */
            Php::Value get_buffer();

            /**
             * Set the GtkEntryBuffer object which holds the text for this widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-buffer
             */
            void set_buffer(Php::Parameters &parameters);

            /**
             * Retrieves the contents of the entry widget
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-text
             */
            Php::Value get_text();

            /**
             * Sets the text in the widget to the given value, replacing the current contents.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-text
             */
            void set_text(Php::Parameters &parameters);

            /**
             * Retrieves the current length of the text in entry.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-text-length
             */
            Php::Value get_text_length();

            /**
             * Sets whether the contents of the entry are visible or not
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-visibility
             */
            void set_visibility(Php::Parameters &parameters);

            /**
             * Get whether the contents of the entry are visible or not
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-visibility
             */
            Php::Value get_visibility();

            void set_completion(Php::Parameters &parameters);
            Php::Value get_completion();

            /**
             * Sets the character to use in place of the actual text when gtk_entry_set_visibility()
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-invisible-char
             */
            void set_invisible_char(Php::Parameters &parameters);

            /**
             * Retrieves the character displayed in place of the real characters for entries with visibility set to false
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-invisible-char
             */
            Php::Value get_invisible_char();

            /**
             * Unsets the invisible char previously set with gtk_entry_set_invisible_char()
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-unset-invisible-char
             */
            void unset_invisible_char();

            /**
             * Sets the maximum allowed length of the contents of the widget
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-max-length
             */
            void set_max_length(Php::Parameters &parameters);

            /**
             * Retrieves the maximum allowed length of the text in entry 
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-max-length
             */
            Php::Value get_max_length();

            /**
             * If setting is TRUE, pressing Enter in the entry will activate the default widget for the window containing the entry.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-activates-default
             */
            void set_activates_default(Php::Parameters &parameters);

            /**
             * Retrieves the value set by gtk_entry_set_activates_default().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-activates-default
             */
            Php::Value get_activates_default();

            /**
             * Sets whether the entry has a beveled frame around it.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-has-frame
             */
            void set_has_frame(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_entry_set_has_frame().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-has-frame
             */
            Php::Value get_has_frame();

            /**
             * Changes the size request of the entry to be about the right size for n_chars characters.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-width-chars
             */
            void set_width_chars(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_entry_set_width_chars().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-width-chars
             */
            Php::Value get_width_chars();

            /**
             * Changes the max size request of the entry to be about the right size for n_chars characters.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-max-width-chars
             */
            void set_max_width_chars(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_entry_set_max_width_chars().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-max-width-chars
             */
            Php::Value get_max_width_chars();

            /**
             * Sets the alignment for the contents of the entry. This controls the horizontal positioning of the contents when the displayed text is shorter than the width of the entry.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-alignment
             */
            void set_alignment(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_entry_set_alignment().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-alignment
             */
            Php::Value get_alignment();

            /**
             * Sets text to be displayed in entry when it is empty and unfocused.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-placeholder-text
             */
            void set_placeholder_text(Php::Parameters &parameters);

            /**
             * Retrieves the text that will be displayed when entry is empty and unfocused
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-placeholder-text
             */
            Php::Value get_placeholder_text();

            /**
             * Sets whether the text is overwritten when typing in the GtkEntry.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-overwrite-mode
             */
            void set_overwrite_mode(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_entry_set_overwrite_mode().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-overwrite-mode
             */
            Php::Value get_overwrite_mode();

            /**
             * Causes the entry’s progress indicator to “fill in” the given fraction of the bar. The fraction should be between 0.0 and 1.0, inclusive.
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-progress-fraction
             */
            void set_progress_fraction(Php::Parameters &parameters);

            /**
             * Returns the current fraction of the task that’s been completed. See gtk_entry_set_progress_fraction().
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-progress-fraction
             */
            Php::Value get_progress_fraction();

            /**
             * Sets the fraction of total entry width to move the progress bouncing block for each call to gtk_entry_progress_pulse().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-progress-pulse-step
             */
            void set_progress_pulse_step(Php::Parameters &parameters);

            /**
             * Retrieves the pulse step set with gtk_entry_set_progress_pulse_step().
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-get-progress-pulse-step
             */
            Php::Value get_progress_pulse_step();

            /**
             * Indicates that some progress is made, but you don’t know how much.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-progress-pulse
             */
            void progress_pulse();
            
            void set_editable(Php::Parameters& parameters);

            Php::Value get_selection_bounds();

            void set_position(Php::Parameters& parameters);

            void select_region(Php::Parameters& parameters);
            void delete_selection();
    };

#endif