
#ifndef _PHPGTK_GTKSOURCEVIEW_H_
#define _PHPGTK_GTKSOURCEVIEW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    #include <gtksourceview/gtksource.h>

	#include "../Gtk/GtkTextView.h"
	#include "../Gtk/GtkTextIter.h"
	#include "GtkSourceBuffer.h"

    /**
     * GtkSourceView_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkSourceView.html
     */
    class GtkSourceView_ : public GtkTextView_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSourceView_();
            ~GtkSourceView_();

            void __construct();

            static Php::Value new_with_buffer(Php::Parameters &parameters);

            void set_show_line_numbers(Php::Parameters &parameters);

            Php::Value get_show_line_numbers();

            void set_show_right_margin(Php::Parameters &parameters);

            Php::Value get_show_right_margin();

            void set_right_margin_position(Php::Parameters &parameters);

            Php::Value get_right_margin_position();

            void set_highlight_current_line(Php::Parameters &parameters);

            Php::Value get_highlight_current_line();

            void set_auto_indent(Php::Parameters &parameters);

            Php::Value get_auto_indent();

            void set_indent_on_tab(Php::Parameters &parameters);

            Php::Value get_indent_on_tab();

            void set_tab_width(Php::Parameters &parameters);

            Php::Value get_tab_width();

            void set_indent_width(Php::Parameters &parameters);

            Php::Value get_indent_width();

            void set_insert_spaces_instead_of_tabs(Php::Parameters &parameters);

            Php::Value get_insert_spaces_instead_of_tabs();

            void indent_lines(Php::Parameters &parameters);

            void unindent_lines(Php::Parameters &parameters);

            Php::Value get_visual_column(Php::Parameters &parameters);

            void set_smart_backspace(Php::Parameters &parameters);

            Php::Value get_smart_backspace();

            void set_smart_home_end(Php::Parameters &parameters);

            Php::Value get_smart_home_end();

            void set_mark_attributes(Php::Parameters &parameters);

            Php::Value get_mark_attributes(Php::Parameters &parameters);

            void set_show_line_marks(Php::Parameters &parameters);

            Php::Value get_show_line_marks();

            void set_draw_spaces(Php::Parameters &parameters);

            Php::Value get_draw_spaces();

            Php::Value get_completion();

            Php::Value get_gutter(Php::Parameters &parameters);

            void set_background_pattern(Php::Parameters &parameters);

            Php::Value get_background_pattern();
    };

#endif
