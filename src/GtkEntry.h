
#ifndef _PHPGTK_GTKENTRY_H_
#define _PHPGTK_GTKENTRY_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkWidget.h"
    #include "GtkEntryBuffer.h"

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
             * Sets the character to use in place of the actual text when gtk_entry_set_visibility()
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-set-invisible-char
             */
            void set_invisible_char(Php::Parameters &parameters);

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
    };

#endif