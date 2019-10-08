
#ifndef _PHPGTK_GTKENTRYBUFFER_H_
#define _PHPGTK_GTKENTRYBUFFER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "../G/GObject.h"

    /**
     * GtkEntryBuffer_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html
     */
    class GtkEntryBuffer_ : public GObject_
    {
        /**
         * Publics
         */
        public:
            GtkEntryBuffer *buffer;

            /**
             *  C++ constructor and destructor
             */
            GtkEntryBuffer_();
            ~GtkEntryBuffer_();

            /**
             * Return original GtkEntryBuffer
             */
            GtkEntryBuffer *get_buffer();

            /**
             * Set the original GtkEntryBuffer
             */
            void set_buffer(GtkEntryBuffer *pased_buffer);

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Retrieves the contents of the buffer.
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html#gtk-entry-buffer-get-text
             */
            Php::Value get_text();

            /**
             * Sets the text in the buffer.
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html#gtk-entry-buffer-set-text
             */
            void set_text(Php::Parameters &parameters);

            /**
             * Retrieves the length in bytes of the buffer
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html#gtk-entry-buffer-get-bytes
             */
            Php::Value get_bytes();

            /**
             * Retrieves the length in characters of the buffer.
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html#gtk-entry-buffer-get-length
             */
            Php::Value get_length();

            /**
             * Retrieves the maximum allowed length of the text in buffer.
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html#gtk-entry-buffer-get-max-length
             */
            Php::Value get_max_length();

            /**
             * Inserts n_chars characters of chars into the contents of the buffer, at position position .
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html#gtk-entry-buffer-insert-text
             */
            Php::Value insert_text(Php::Parameters &parameters);

            /**
             * Deletes a sequence of characters from the buffer.
             *
             * https://developer.gnome.org/gtk3/stable/GtkEntryBuffer.html#gtk-entry-buffer-delete-text
             */
            void delete_text(Php::Parameters &parameters);

    };

#endif