
#ifndef _PHPGTK_GTKTEXTBUFFER_H_
#define _PHPGTK_GTKTEXTBUFFER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkTextIter.h"
	#include "GtkTextTag.h"
    #include "GtkTextTagTable.h"

    /**
     * GtkTextBuffer_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextBuffer.html
     */
    class GtkTextBuffer_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTextBuffer_();
            ~GtkTextBuffer_();

            void __construct();

            Php::Value get_line_count();

            Php::Value get_char_count();

            Php::Value get_tag_table();

            void insert(Php::Parameters &parameters);

            void insert_at_cursor(Php::Parameters &parameters);

            Php::Value insert_interactive(Php::Parameters &parameters);

            Php::Value insert_interactive_at_cursor(Php::Parameters &parameters);

            void insert_range(Php::Parameters &parameters);

            Php::Value insert_range_interactive(Php::Parameters &parameters);

            void insert_with_tags(Php::Parameters &parameters);

            void insert_with_tags_by_name(Php::Parameters &parameters);

            void insert_markup(Php::Parameters &parameters);

            void delete_(Php::Parameters &parameters);

            Php::Value delete_interactive(Php::Parameters &parameters);

            Php::Value backspace(Php::Parameters &parameters);

            void set_text(Php::Parameters &parameters);

            Php::Value get_text(Php::Parameters &parameters);

            Php::Value get_slice(Php::Parameters &parameters);

            void insert_pixbuf(Php::Parameters &parameters);

            Php::Value create_mark(Php::Parameters &parameters);

            void move_mark(Php::Parameters &parameters);

            void move_mark_by_name(Php::Parameters &parameters);

            void add_mark(Php::Parameters &parameters);

            void delete_mark(Php::Parameters &parameters);

            void delete_mark_by_name(Php::Parameters &parameters);

            Php::Value get_mark(Php::Parameters &parameters);

            Php::Value get_insert(Php::Parameters &parameters);

            Php::Value get_selection_bound(Php::Parameters &parameters);

            Php::Value get_has_selection(Php::Parameters &parameters);

            void place_cursor(Php::Parameters &parameters);

            void select_range(Php::Parameters &parameters);

            void apply_tag(Php::Parameters &parameters);

            void remove_tag(Php::Parameters &parameters);

            void apply_tag_by_name(Php::Parameters &parameters);

            void remove_tag_by_name(Php::Parameters &parameters);

            void remove_all_tags(Php::Parameters &parameters);

            Php::Value create_tag(Php::Parameters &parameters);

            Php::Value get_iter_at_line_offset(Php::Parameters &parameters);

            Php::Value get_iter_at_offset(Php::Parameters &parameters);

            Php::Value get_iter_at_line(Php::Parameters &parameters);

            Php::Value get_iter_at_line_index(Php::Parameters &parameters);

            Php::Value get_iter_at_mark(Php::Parameters &parameters);

            Php::Value get_start_iter();

            Php::Value get_end_iter();

            Php::Value get_bounds();

            Php::Value get_modified();

            void set_modified(Php::Parameters &parameters);

            Php::Value delete_selection(Php::Parameters &parameters);

            void paste_clipboard(Php::Parameters &parameters);

            void copy_clipboard(Php::Parameters &parameters);

            void cut_clipboard(Php::Parameters &parameters);

            Php::Value get_selection_bounds(Php::Parameters &parameters);

            void begin_user_action();

            void end_user_action();

            void remove_selection_clipboard(Php::Parameters &parameters);

            Php::Value deserialize(Php::Parameters &parameters);

            Php::Value deserialize_get_can_create_tags(Php::Parameters &parameters);

            Php::Value deserialize_set_can_create_tags(Php::Parameters &parameters);

            Php::Value get_copy_target_list(Php::Parameters &parameters);

            Php::Value get_deserialize_formats(Php::Parameters &parameters);

            Php::Value get_paste_target_list(Php::Parameters &parameters);

            Php::Value get_serialize_formats(Php::Parameters &parameters);

            Php::Value register_deserialize_format(Php::Parameters &parameters);

            Php::Value register_serialize_format(Php::Parameters &parameters);

            Php::Value register_serialize_tagset(Php::Parameters &parameters);

            Php::Value serialize(Php::Parameters &parameters);

            Php::Value unregister_deserialize_format(Php::Parameters &parameters);

            Php::Value unregister_serialize_format(Php::Parameters &parameters);
    };

#endif
