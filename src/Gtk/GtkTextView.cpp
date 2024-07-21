
#include "GtkTextView.h"

/**
 * Constructor
 */
GtkTextView_::GtkTextView_() = default;

/**
 * Destructor
 */
GtkTextView_::~GtkTextView_() = default;

void GtkTextView_::__construct()
{
	instance = (gpointer *)gtk_text_view_new ();

}

Php::Value GtkTextView_::new_with_buffer(Php::Parameters &parameters)
{
	GtkTextBuffer *buffer;
	if(parameters.size() > 0) {
		Php::Value object_buffer = parameters[0];
		GtkTextBuffer_ *phpgtk_buffer = (GtkTextBuffer_ *)object_buffer.implementation();
		buffer = GTK_TEXT_BUFFER(phpgtk_buffer->get_instance());
	}

	gpointer *a = (gpointer *)gtk_text_view_new_with_buffer (buffer);

	GtkTextView_ *return_parsed = new GtkTextView_();
	return_parsed->set_instance(a);
	return Php::Object("GtkTextView", return_parsed);

}

void GtkTextView_::set_buffer(Php::Parameters &parameters)
{
	GtkTextBuffer *buffer;
	if(parameters.size() > 0) {
		Php::Value object_buffer = parameters[0];
		GtkTextBuffer_ *phpgtk_buffer = (GtkTextBuffer_ *)object_buffer.implementation();
		buffer = GTK_TEXT_BUFFER(phpgtk_buffer->get_instance());
	}

	gtk_text_view_set_buffer (GTK_TEXT_VIEW(instance), buffer);

}

Php::Value GtkTextView_::get_buffer()
{
	GtkTextBuffer *ret = gtk_text_view_get_buffer (GTK_TEXT_VIEW(instance));

	GtkTextBuffer_ *return_parsed = new GtkTextBuffer_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextBuffer", return_parsed);
}

void GtkTextView_::scroll_to_mark(Php::Parameters &parameters)
{
	GtkTextMark *mark;
	if(parameters.size() > 0) {
		Php::Value object_mark = parameters[0];
		GtkTextMark_ *phpgtk_mark = (GtkTextMark_ *)object_mark.implementation();
		mark = GTK_TEXT_MARK(phpgtk_mark->get_instance());
	}

	gdouble within_margin = (gdouble)parameters[1];

	gboolean use_align = (gboolean)parameters[2];

	gdouble xalign = (gdouble)parameters[3];

	gdouble yalign = (gdouble)parameters[4];

	gtk_text_view_scroll_to_mark (GTK_TEXT_VIEW(instance), mark, within_margin, use_align, xalign, yalign);

}

void GtkTextView_::scroll_to_iter(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = (phpgtk_iter->get_instance());

	gdouble within_margin = (gdouble)parameters[1];

	gboolean use_align = (gboolean)parameters[2];

	gdouble xalign = (gdouble)parameters[3];

	gdouble yalign = (gdouble)parameters[4];

	gtk_text_view_scroll_to_iter (GTK_TEXT_VIEW(instance), &iter, within_margin, use_align, xalign, yalign);

}

void GtkTextView_::scroll_mark_onscreen(Php::Parameters &parameters)
{
	GtkTextMark *mark;
	if(parameters.size() > 0) {
		Php::Value object_mark = parameters[0];
		GtkTextMark_ *phpgtk_mark = (GtkTextMark_ *)object_mark.implementation();
		mark = GTK_TEXT_MARK(phpgtk_mark->get_instance());
	}

	gtk_text_view_scroll_mark_onscreen (GTK_TEXT_VIEW(instance), mark);

}

Php::Value GtkTextView_::move_mark_onscreen(Php::Parameters &parameters)
{
	GtkTextMark *mark;
	if(parameters.size() > 0) {
		Php::Value object_mark = parameters[0];
		GtkTextMark_ *phpgtk_mark = (GtkTextMark_ *)object_mark.implementation();
		mark = GTK_TEXT_MARK(phpgtk_mark->get_instance());
	}

	bool ret = gtk_text_view_move_mark_onscreen (GTK_TEXT_VIEW(instance), mark);

	return ret;
}

Php::Value GtkTextView_::place_cursor_onscreen()
{
	bool ret = gtk_text_view_place_cursor_onscreen (GTK_TEXT_VIEW(instance));

	return ret;
}

Php::Value GtkTextView_::get_line_at_y(Php::Parameters &parameters)
{
	
	Php::Value object_target_iter = parameters[0];
	GtkTextIter_ *phpgtk_target_iter = (GtkTextIter_ *)object_target_iter.implementation();
	GtkTextIter target_iter = (phpgtk_target_iter->get_instance());

	gint y = (gint)parameters[1];

	gint line_top;


	gint ret;

	gtk_text_view_get_line_at_y (GTK_TEXT_VIEW(instance), &target_iter, y, &line_top);

	ret = line_top;

	return ret;
}

Php::Value GtkTextView_::get_line_yrange(Php::Parameters &parameters)
{
	
	Php::Value object_target_iter = parameters[0];
	GtkTextIter_ *phpgtk_target_iter = (GtkTextIter_ *)object_target_iter.implementation();
	GtkTextIter target_iter = (phpgtk_target_iter->get_instance());

	gint y;
	gint height;

	gtk_text_view_get_line_yrange (GTK_TEXT_VIEW(instance), &target_iter, &y, &height);

	Php::Value ret;
	ret[0] = ret["y"] = y;
	ret[1] = ret["height"] = height;

	return ret;
}

Php::Value GtkTextView_::get_iter_at_location(Php::Parameters &parameters)
{
	GtkTextIter target_iter;

	gint x = (gint)parameters[0];
	gint y = (gint)parameters[1];

	gint ret = gtk_text_view_get_iter_at_location (GTK_TEXT_VIEW(instance), &target_iter, x, y);
	if(!ret)
		return ret;

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(target_iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextView_::get_iter_at_position(Php::Parameters &parameters)
{
	
	gint x = (gint)parameters[0];
	gint y = (gint)parameters[1];
	GtkTextIter target_iter;

	bool ret = gtk_text_view_get_iter_at_position (GTK_TEXT_VIEW(instance), &target_iter, NULL, x, y);
	if(!ret)
		return ret;

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(target_iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextView_::buffer_to_window_coords(Php::Parameters &parameters)
{
	int int_win = (int)parameters[0];
	GtkTextWindowType win = (GtkTextWindowType)int_win;

	gint buffer_x = (gint)parameters[1];
	gint buffer_y = (gint)parameters[2];

	gint window_x;
	gint window_y;

	gtk_text_view_buffer_to_window_coords (GTK_TEXT_VIEW(instance), win, buffer_x, buffer_y, &window_x, &window_y);

	Php::Value ret;
	ret[0] = ret["window_x"] = window_x;
	ret[1] = ret["window_y"] = window_y;

	return ret;
}

Php::Value GtkTextView_::window_to_buffer_coords(Php::Parameters &parameters)
{
	int int_win = (int)parameters[0];
	GtkTextWindowType win = (GtkTextWindowType)int_win;

	gint window_x = (gint)parameters[1];
	gint window_y = (gint)parameters[2];

	gint buffer_x;
	gint buffer_y;

	gtk_text_view_window_to_buffer_coords (GTK_TEXT_VIEW(instance), win, window_x, window_y, &buffer_x, &buffer_y);

	Php::Value ret;
	ret[0] = ret["buffer_x"] = buffer_x;
	ret[1] = ret["buffer_y"] = buffer_y;

	return ret;
}

Php::Value GtkTextView_::get_window(Php::Parameters &parameters)
{
	// int int_win = (int)parameters[0];
	// GtkTextWindowType win = (GtkTextWindowType)int_win;
 
	// GdkWindow ret = gtk_text_view_get_window (GTK_TEXT_VIEW(instance), win);


	// GdkWindow_ *return_parsed = new GdkWindow_();
	// return_parsed->set_instance(ret);
	// return Php::Object("GdkWindow", return_parsed);

	throw Php::Exception("GtkTextView_::get_window not implemented");
	return -1;
}

Php::Value GtkTextView_::get_window_type(Php::Parameters &parameters)
{
	// int int_win = (int)parameters[0];
	// GtkTextWindowType win = (GtkTextWindowType)int_win;

	// GtkTextWindowType ret = gtk_text_view_get_window_type (GTK_TEXT_VIEW(instance), win);

	// return ret;
	throw Php::Exception("GtkTextView_::get_window_type not implemented");
	return -1;
}

void GtkTextView_::set_border_window_size(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GtkTextWindowType type = (GtkTextWindowType)int_type;

	gint size = (gint)parameters[1];

	gtk_text_view_set_border_window_size (GTK_TEXT_VIEW(instance), type, size);

}

Php::Value GtkTextView_::get_border_window_size(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GtkTextWindowType type = (GtkTextWindowType)int_type;

	gint ret = gtk_text_view_get_border_window_size (GTK_TEXT_VIEW(instance), type);

	return ret;
}

Php::Value GtkTextView_::forward_display_line(Php::Parameters &parameters)
{
	
	Php::Value object_type = parameters[0];
	GtkTextIter_ *phpgtk_type = (GtkTextIter_ *)object_type.implementation();
	GtkTextIter type = (phpgtk_type->get_instance());

	bool ret = gtk_text_view_forward_display_line (GTK_TEXT_VIEW(instance), &type);

	return ret;
}

Php::Value GtkTextView_::backward_display_line(Php::Parameters &parameters)
{
	
	Php::Value object_type = parameters[0];
	GtkTextIter_ *phpgtk_type = (GtkTextIter_ *)object_type.implementation();
	GtkTextIter type = (phpgtk_type->get_instance());

	bool ret = gtk_text_view_backward_display_line (GTK_TEXT_VIEW(instance), &type);

	return ret;
}

Php::Value GtkTextView_::forward_display_line_end(Php::Parameters &parameters)
{
	
	Php::Value object_type = parameters[0];
	GtkTextIter_ *phpgtk_type = (GtkTextIter_ *)object_type.implementation();
	GtkTextIter type = (phpgtk_type->get_instance());

	bool ret = gtk_text_view_forward_display_line_end (GTK_TEXT_VIEW(instance), &type);

	return ret;
}

Php::Value GtkTextView_::backward_display_line_start(Php::Parameters &parameters)
{
	
	Php::Value object_type = parameters[0];
	GtkTextIter_ *phpgtk_type = (GtkTextIter_ *)object_type.implementation();
	GtkTextIter type = (phpgtk_type->get_instance());

	bool ret = gtk_text_view_backward_display_line_start (GTK_TEXT_VIEW(instance), &type);

	return ret;
}

Php::Value GtkTextView_::starts_display_line(Php::Parameters &parameters)
{
	
	Php::Value object_type = parameters[0];
	GtkTextIter_ *phpgtk_type = (GtkTextIter_ *)object_type.implementation();
	GtkTextIter type = (phpgtk_type->get_instance());

	bool ret = gtk_text_view_starts_display_line (GTK_TEXT_VIEW(instance), &type);

	return ret;
}

Php::Value GtkTextView_::move_visually(Php::Parameters &parameters)
{
	
	Php::Value object_type = parameters[0];
	GtkTextIter_ *phpgtk_type = (GtkTextIter_ *)object_type.implementation();
	GtkTextIter type = (phpgtk_type->get_instance());

	gint count = (gint)parameters[1];

	bool ret = gtk_text_view_move_visually (GTK_TEXT_VIEW(instance), &type, count);

	return ret;
}

void GtkTextView_::add_child_in_window(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	int int_which_window = (int)parameters[1];
	GtkTextWindowType which_window = (GtkTextWindowType)int_which_window;

	gint xpos = (gint)parameters[2];

	gint ypos = (gint)parameters[3];

	gtk_text_view_add_child_in_window (GTK_TEXT_VIEW(instance), child, which_window, xpos, ypos);

}

void GtkTextView_::move_child(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint xpos = (gint)parameters[1];

	gint ypos = (gint)parameters[2];

	gtk_text_view_move_child (GTK_TEXT_VIEW(instance), child, xpos, ypos);

}

void GtkTextView_::set_wrap_mode(Php::Parameters &parameters)
{
	int int_wrap_mode = (int)parameters[0];
	GtkWrapMode wrap_mode = (GtkWrapMode)int_wrap_mode;

	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW(instance), wrap_mode);

}

Php::Value GtkTextView_::get_wrap_mode()
{
	GtkWrapMode ret = gtk_text_view_get_wrap_mode (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_editable(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_text_view_set_editable (GTK_TEXT_VIEW(instance), setting);

}

Php::Value GtkTextView_::get_editable()
{
	bool ret = gtk_text_view_get_editable (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_cursor_visible(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW(instance), setting);

}

Php::Value GtkTextView_::get_cursor_visible()
{
	bool ret = gtk_text_view_get_cursor_visible (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::overwrite(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_text_view_set_overwrite (GTK_TEXT_VIEW(instance), setting);

}

Php::Value GtkTextView_::get_overwrite()
{
	bool ret = gtk_text_view_get_overwrite (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_pixels_above_lines(Php::Parameters &parameters)
{
	gint pixels_above_lines = (gint)parameters[0];

	gtk_text_view_set_pixels_above_lines (GTK_TEXT_VIEW(instance), pixels_above_lines);

}

Php::Value GtkTextView_::get_pixels_above_lines()
{
	gint ret = gtk_text_view_get_pixels_above_lines (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_pixels_below_lines(Php::Parameters &parameters)
{
	gint pixels_below_lines = (gint)parameters[0];

	gtk_text_view_set_pixels_below_lines (GTK_TEXT_VIEW(instance), pixels_below_lines);

}

Php::Value GtkTextView_::get_pixels_below_lines()
{
	gint ret = gtk_text_view_get_pixels_below_lines (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_pixels_inside_wrap(Php::Parameters &parameters)
{
	gint pixels_inside_wrap = (gint)parameters[0];

	gtk_text_view_set_pixels_inside_wrap (GTK_TEXT_VIEW(instance), pixels_inside_wrap);

}

Php::Value GtkTextView_::get_pixels_inside_wrap()
{
	gint ret = gtk_text_view_get_pixels_inside_wrap (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_justification(Php::Parameters &parameters)
{
	int int_justification = (int)parameters[0];
	GtkJustification justification = (GtkJustification)int_justification;

	gtk_text_view_set_justification (GTK_TEXT_VIEW(instance), justification);

}

Php::Value GtkTextView_::get_justification()
{
	GtkJustification ret = gtk_text_view_get_justification (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_left_margin(Php::Parameters &parameters)
{
	gint left_margin = (gint)parameters[0];

	gtk_text_view_set_left_margin (GTK_TEXT_VIEW(instance), left_margin);

}

Php::Value GtkTextView_::get_left_margin()
{
	gint ret = gtk_text_view_get_left_margin (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_right_margin(Php::Parameters &parameters)
{
	gint right_margin = (gint)parameters[0];

	gtk_text_view_set_right_margin (GTK_TEXT_VIEW(instance), right_margin);

}

Php::Value GtkTextView_::get_right_margin()
{
	gint ret = gtk_text_view_get_right_margin (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_top_margin(Php::Parameters &parameters)
{
	gint top_margin = (gint)parameters[0];

	gtk_text_view_set_top_margin (GTK_TEXT_VIEW(instance), top_margin);

}

Php::Value GtkTextView_::get_top_margin()
{
	gint ret = gtk_text_view_get_top_margin (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_bottom_margin(Php::Parameters &parameters)
{
	gint bottom_margin = (gint)parameters[0];

	gtk_text_view_set_bottom_margin (GTK_TEXT_VIEW(instance), bottom_margin);

}

Php::Value GtkTextView_::get_bottom_margin()
{
	gint ret = gtk_text_view_get_bottom_margin (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_indent(Php::Parameters &parameters)
{
	gint indent = (gint)parameters[0];

	gtk_text_view_set_indent (GTK_TEXT_VIEW(instance), indent);

}

Php::Value GtkTextView_::get_indent()
{
	gint ret = gtk_text_view_get_indent (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_accepts_tab(Php::Parameters &parameters)
{
	gboolean accepts_tab = (gboolean)parameters[0];

	gtk_text_view_set_accepts_tab (GTK_TEXT_VIEW(instance), accepts_tab);

}

Php::Value GtkTextView_::get_accepts_tab()
{
	bool ret = gtk_text_view_get_accepts_tab (GTK_TEXT_VIEW(instance));

	return ret;
}

Php::Value GtkTextView_::im_context_filter_keypress(Php::Parameters &parameters)
{
	// bool ret = gtk_text_view_im_context_filter_keypress (GTK_TEXT_VIEW(instance), event);
	// return ret;

	throw Php::Exception("GtkTextView_::im_context_filter_keypress not implemented");
	return -1;
}

void GtkTextView_::reset_im_context()
{
	gtk_text_view_reset_im_context (GTK_TEXT_VIEW(instance));

}

void GtkTextView_::set_input_purpose(Php::Parameters &parameters)
{
	int int_purpose = (int)parameters[0];
	GtkInputPurpose purpose = (GtkInputPurpose)int_purpose;

	gtk_text_view_set_input_purpose (GTK_TEXT_VIEW(instance), purpose);

}

Php::Value GtkTextView_::get_input_purpose()
{
	GtkInputPurpose ret = gtk_text_view_get_input_purpose (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_input_hints(Php::Parameters &parameters)
{
	int int_hints = (int)parameters[0];
	GtkInputHints hints = (GtkInputHints)int_hints;

	gtk_text_view_set_input_hints (GTK_TEXT_VIEW(instance), hints);

}

Php::Value GtkTextView_::get_input_hints()
{
	GtkInputHints ret = gtk_text_view_get_input_hints (GTK_TEXT_VIEW(instance));

	return ret;
}

void GtkTextView_::set_monospace(Php::Parameters &parameters)
{
	gboolean monospace = (gboolean)parameters[0];

	gtk_text_view_set_monospace (GTK_TEXT_VIEW(instance), monospace);

}

Php::Value GtkTextView_::get_monospace()
{
	bool ret = gtk_text_view_get_monospace (GTK_TEXT_VIEW(instance));

	return ret;
}

