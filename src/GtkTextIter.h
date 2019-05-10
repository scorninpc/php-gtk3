
#ifndef _PHPGTK_GTKTEXTITER_H_
#define _PHPGTK_GTKTEXTITER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkTextBuffer.h"
    #include "GtkTextTag.h"


    /**
     * GtkTextIter_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextIter.html
     */
    class GtkTextIter_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTextIter_();
            ~GtkTextIter_();

            GtkTextIter *instance;

            void set_instance(GtkTextIter *a);
            GtkTextIter *get_instance();

            Php::Value get_buffer();

            Php::Value copy();

            void assign(Php::Parameters &parameters);

            void free();

            Php::Value get_offset();

            Php::Value get_line();

            Php::Value get_line_offset();

            Php::Value get_line_index();

            Php::Value get_visible_line_offset();

            Php::Value get_char();

            Php::Value get_slice(Php::Parameters &parameters);

            Php::Value get_text(Php::Parameters &parameters);

            Php::Value get_visible_slice(Php::Parameters &parameters);

            Php::Value get_visible_text(Php::Parameters &parameters);

            Php::Value get_toggled_tags(Php::Parameters &parameters);

            Php::Value starts_tag(Php::Parameters &parameters);

            Php::Value ends_tag(Php::Parameters &parameters);

            Php::Value toggles_tag(Php::Parameters &parameters);

            Php::Value has_tag(Php::Parameters &parameters);

            Php::Value get_tags();

            Php::Value editable(Php::Parameters &parameters);

            Php::Value can_insert(Php::Parameters &parameters);

            Php::Value starts_word();

            Php::Value ends_word();

            Php::Value inside_word();

            Php::Value starts_line();

            Php::Value ends_line();

            Php::Value starts_sentence();

            Php::Value ends_sentence();

            Php::Value inside_sentence();

            Php::Value is_cursor_position();

            Php::Value get_chars_in_line();

            Php::Value get_bytes_in_line();

            Php::Value is_end();

            Php::Value is_start();

            Php::Value forward_char();

            Php::Value backward_char();

            Php::Value forward_chars(Php::Parameters &parameters);

            Php::Value backward_chars(Php::Parameters &parameters);

            Php::Value forward_line();

            Php::Value backward_line();

            Php::Value forward_lines(Php::Parameters &parameters);

            Php::Value backward_lines(Php::Parameters &parameters);

            Php::Value forward_word_ends(Php::Parameters &parameters);

            Php::Value backward_word_starts(Php::Parameters &parameters);

            Php::Value forward_word_end();

            Php::Value backward_word_start();

            Php::Value forward_cursor_position();

            Php::Value backward_cursor_position();

            Php::Value forward_cursor_positions(Php::Parameters &parameters);

            Php::Value backward_cursor_positions(Php::Parameters &parameters);

            Php::Value backward_sentence_start();

            Php::Value backward_sentence_starts(Php::Parameters &parameters);

            Php::Value forward_sentence_end();

            Php::Value forward_sentence_ends(Php::Parameters &parameters);

            Php::Value forward_visible_word_ends(Php::Parameters &parameters);

            Php::Value backward_visible_word_starts(Php::Parameters &parameters);

            Php::Value forward_visible_word_end();

            Php::Value backward_visible_word_start();

            Php::Value forward_visible_cursor_position();

            Php::Value backward_visible_cursor_position();

            Php::Value forward_visible_cursor_positions(Php::Parameters &parameters);

            Php::Value backward_visible_cursor_positions(Php::Parameters &parameters);

            Php::Value forward_visible_line();

            Php::Value backward_visible_line();

            Php::Value forward_visible_lines(Php::Parameters &parameters);

            Php::Value backward_visible_lines(Php::Parameters &parameters);

            void set_offset(Php::Parameters &parameters);

            void set_line(Php::Parameters &parameters);

            void set_line_offset(Php::Parameters &parameters);

            void set_line_index(Php::Parameters &parameters);

            void set_visible_line_index(Php::Parameters &parameters);

            void set_visible_line_offset(Php::Parameters &parameters);

            void forward_to_end();

            Php::Value forward_to_line_end();

            Php::Value forward_to_tag_toggle(Php::Parameters &parameters);

            Php::Value backward_to_tag_toggle(Php::Parameters &parameters);

            Php::Value iter_equal(Php::Parameters &parameters);

            Php::Value iter_compare(Php::Parameters &parameters);

            Php::Value in_range(Php::Parameters &parameters);

            void order(Php::Parameters &parameters);
    };

#endif
