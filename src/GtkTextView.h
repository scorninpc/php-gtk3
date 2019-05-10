
#ifndef _PHPGTK_GTKTEXTVIEW_H_
#define _PHPGTK_GTKTEXTVIEW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkTextBuffer.h"
	#include "GtkTextMark.h"
	#include "GtkTextIter.h"
	#include "GtkInputPurpose.h"

    /**
     * GtkTextView_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextView.html
     */
    class GtkTextView_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTextView_();
            ~GtkTextView_();

            void __construct();

            static Php::Value new_with_buffer(Php::Parameters &parameters);

            void set_buffer(Php::Parameters &parameters);

            Php::Value get_buffer();

            void scroll_to_mark(Php::Parameters &parameters);

            void scroll_to_iter(Php::Parameters &parameters);

            void scroll_mark_onscreen(Php::Parameters &parameters);

            Php::Value move_mark_onscreen(Php::Parameters &parameters);

            Php::Value place_cursor_onscreen();

            Php::Value get_line_at_y(Php::Parameters &parameters);

            Php::Value get_line_yrange(Php::Parameters &parameters);

            Php::Value get_iter_at_location(Php::Parameters &parameters);

            Php::Value get_iter_at_position(Php::Parameters &parameters);

            Php::Value buffer_to_window_coords(Php::Parameters &parameters);

            Php::Value window_to_buffer_coords(Php::Parameters &parameters);

            Php::Value get_window(Php::Parameters &parameters);

            Php::Value get_window_type(Php::Parameters &parameters);

            void set_border_window_size(Php::Parameters &parameters);

            Php::Value get_border_window_size(Php::Parameters &parameters);

            Php::Value forward_display_line(Php::Parameters &parameters);

            Php::Value backward_display_line(Php::Parameters &parameters);

            Php::Value forward_display_line_end(Php::Parameters &parameters);

            Php::Value backward_display_line_start(Php::Parameters &parameters);

            Php::Value starts_display_line(Php::Parameters &parameters);

            Php::Value move_visually(Php::Parameters &parameters);

            void add_child_in_window(Php::Parameters &parameters);

            void move_child(Php::Parameters &parameters);

            void set_wrap_mode(Php::Parameters &parameters);

            Php::Value get_wrap_mode();

            void set_editable(Php::Parameters &parameters);

            Php::Value get_editable();

            void set_cursor_visible(Php::Parameters &parameters);

            Php::Value get_cursor_visible();

            void overwrite(Php::Parameters &parameters);

            Php::Value get_overwrite();

            void set_pixels_above_lines(Php::Parameters &parameters);

            Php::Value get_pixels_above_lines();

            void set_pixels_below_lines(Php::Parameters &parameters);

            Php::Value get_pixels_below_lines();

            void set_pixels_inside_wrap(Php::Parameters &parameters);

            Php::Value get_pixels_inside_wrap();

            void set_justification(Php::Parameters &parameters);

            Php::Value get_justification();

            void set_left_margin(Php::Parameters &parameters);

            Php::Value get_left_margin();

            void set_right_margin(Php::Parameters &parameters);

            Php::Value get_right_margin();

            void set_top_margin(Php::Parameters &parameters);

            Php::Value get_top_margin();

            void set_bottom_margin(Php::Parameters &parameters);

            Php::Value get_bottom_margin();

            void set_indent(Php::Parameters &parameters);

            Php::Value get_indent();

            void set_accepts_tab(Php::Parameters &parameters);

            Php::Value get_accepts_tab();

            Php::Value im_context_filter_keypress(Php::Parameters &parameters);

            void reset_im_context();

            void set_input_purpose(Php::Parameters &parameters);

            Php::Value get_input_purpose();

            void set_input_hints(Php::Parameters &parameters);

            Php::Value get_input_hints();

            void set_monospace(Php::Parameters &parameters);

            Php::Value get_monospace();
    };

#endif
