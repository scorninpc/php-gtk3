
#include "GtkTextIter.h"

/**
 * Constructor
 */
GtkTextIter_::GtkTextIter_() = default;

/**
 * Destructor
 */
GtkTextIter_::~GtkTextIter_() = default;

/**
 * Return original instance
 */
GtkTextIter *GtkTextIter_::get_instance()
{
    return instance;
}

/**
 * Set the original GtkTextIter
 */
void GtkTextIter_::set_instance(GtkTextIter *pased_instance)
{
    instance = pased_instance;
}

Php::Value GtkTextIter_::get_buffer()
{
	GtkTextBuffer *ret = gtk_text_iter_get_buffer (instance);

	GtkTextBuffer_ *return_parsed = new GtkTextBuffer_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextBuffer", return_parsed);
}

Php::Value GtkTextIter_::copy()
{
	GtkTextIter *ret = gtk_text_iter_copy (instance);

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkTextIter", return_parsed);
}

void GtkTextIter_::assign(Php::Parameters &parameters)
{
	
	Php::Value object_other = parameters[0];
	GtkTextIter_ *phpgtk_other = (GtkTextIter_ *)object_other.implementation();
	GtkTextIter *other = (phpgtk_other->get_instance());

	gtk_text_iter_assign (instance, other);
}

void GtkTextIter_::free()
{
	gtk_text_iter_free (instance);

}

Php::Value GtkTextIter_::get_offset()
{
	gint ret = gtk_text_iter_get_offset (instance);

	return ret;
}

Php::Value GtkTextIter_::get_line()
{
	gint ret = gtk_text_iter_get_line (instance);

	return ret;
}

Php::Value GtkTextIter_::get_line_offset()
{
	gint ret = gtk_text_iter_get_line_offset (instance);

	return ret;
}

Php::Value GtkTextIter_::get_line_index()
{
	gint ret = gtk_text_iter_get_line_index (instance);

	return ret;
}

Php::Value GtkTextIter_::get_visible_line_offset()
{
	gint ret = gtk_text_iter_get_visible_line_offset (instance);

	return ret;
}

Php::Value GtkTextIter_::get_char()
{
	gunichar ch = gtk_text_iter_get_char (instance);

	char a;
	g_unichar_to_utf8(ch, &a);
	
	return 1;
}

Php::Value GtkTextIter_::get_slice(Php::Parameters &parameters)
{
	GtkTextIter *end;
	if(parameters.size() > 0) {
		Php::Value object_end = parameters[0];
		GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
		end = phpgtk_end->get_instance();
	}

	std::string ret = gtk_text_iter_get_slice (instance, end);

	return ret;
}

Php::Value GtkTextIter_::get_text(Php::Parameters &parameters)
{
	GtkTextIter *end;
	if(parameters.size() > 0) {
		Php::Value object_end = parameters[0];
		GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
		end = phpgtk_end->get_instance();
	}

	std::string ret = gtk_text_iter_get_text (instance, end);

	return ret;
}

Php::Value GtkTextIter_::get_visible_slice(Php::Parameters &parameters)
{
	GtkTextIter *end;
	if(parameters.size() > 0) {
		Php::Value object_end = parameters[0];
		GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
		end = phpgtk_end->get_instance();
	}

	std::string ret = gtk_text_iter_get_visible_slice (instance, end);

	return ret;
}

Php::Value GtkTextIter_::get_visible_text(Php::Parameters &parameters)
{
	GtkTextIter *end;
	if(parameters.size() > 0) {
		Php::Value object_end = parameters[0];
		GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
		end = phpgtk_end->get_instance();
	}

	std::string ret = gtk_text_iter_get_visible_text (instance, end);

	return ret;
}

Php::Value GtkTextIter_::get_marks()
{
	GSList *ret = gtk_text_iter_get_marks (instance);

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		 
		GtkTextMark_ *return_parsed = new GtkTextMark_();
		return_parsed->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("GtkTextMark", return_parsed);
	}

	return ret_arr;
}

Php::Value GtkTextIter_::get_toggled_tags(Php::Parameters &parameters)
{
	gboolean toggled_on = (gboolean)parameters[0];

	GSList *ret = gtk_text_iter_get_toggled_tags (instance, toggled_on);

	
	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		 
		GtkTextTag_ *return_parsed = new GtkTextTag_();
		return_parsed->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("GtkTextTag", return_parsed);
	}

	return ret_arr;
}

Php::Value GtkTextIter_::starts_tag(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = GTK_TEXT_TAG(phpgtk_tag->get_instance());
	}

	gboolean ret = gtk_text_iter_starts_tag (instance, tag);

	return ret;
}

Php::Value GtkTextIter_::ends_tag(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = GTK_TEXT_TAG(phpgtk_tag->get_instance());
	}

	gboolean ret = gtk_text_iter_ends_tag (instance, tag);

	return ret;
}

Php::Value GtkTextIter_::toggles_tag(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = GTK_TEXT_TAG(phpgtk_tag->get_instance());
	}

	gboolean ret = gtk_text_iter_toggles_tag (instance, tag);

	return ret;
}

Php::Value GtkTextIter_::has_tag(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = GTK_TEXT_TAG(phpgtk_tag->get_instance());
	}

	gboolean ret = gtk_text_iter_has_tag (instance, tag);

	return ret;
}

Php::Value GtkTextIter_::get_tags()
{
	GSList *ret = gtk_text_iter_get_tags (instance);

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		 
		GtkTextTag_ *return_parsed = new GtkTextTag_();
		return_parsed->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("GtkTextTag", return_parsed);
	}

	return ret_arr;
}

Php::Value GtkTextIter_::editable(Php::Parameters &parameters)
{
	gboolean default_setting = (gboolean)parameters[0];

	gboolean ret = gtk_text_iter_editable (instance, default_setting);

	return ret;
}

Php::Value GtkTextIter_::can_insert(Php::Parameters &parameters)
{
	gboolean default_editability = (gboolean)parameters[0];

	gboolean ret = gtk_text_iter_can_insert (instance, default_editability);

	return ret;
}

Php::Value GtkTextIter_::starts_word()
{
	gboolean ret = gtk_text_iter_starts_word (instance);

	return ret;
}

Php::Value GtkTextIter_::ends_word()
{
	gboolean ret = gtk_text_iter_ends_word (instance);

	return ret;
}

Php::Value GtkTextIter_::inside_word()
{
	gboolean ret = gtk_text_iter_inside_word (instance);

	return ret;
}

Php::Value GtkTextIter_::starts_line()
{
	gboolean ret = gtk_text_iter_starts_line (instance);

	return ret;
}

Php::Value GtkTextIter_::ends_line()
{
	gboolean ret = gtk_text_iter_ends_line (instance);

	return ret;
}

Php::Value GtkTextIter_::starts_sentence()
{
	gboolean ret = gtk_text_iter_starts_sentence (instance);

	return ret;
}

Php::Value GtkTextIter_::ends_sentence()
{
	gboolean ret = gtk_text_iter_ends_sentence (instance);

	return ret;
}

Php::Value GtkTextIter_::inside_sentence()
{
	gboolean ret = gtk_text_iter_inside_sentence (instance);

	return ret;
}

Php::Value GtkTextIter_::is_cursor_position()
{
	gboolean ret = gtk_text_iter_is_cursor_position (instance);

	return ret;
}

Php::Value GtkTextIter_::get_chars_in_line()
{
	gint ret = gtk_text_iter_get_chars_in_line (instance);

	return ret;
}

Php::Value GtkTextIter_::get_bytes_in_line()
{
	gint ret = gtk_text_iter_get_bytes_in_line (instance);

	return ret;
}

Php::Value GtkTextIter_::is_end()
{
	gboolean ret = gtk_text_iter_is_end (instance);

	return ret;
}

Php::Value GtkTextIter_::is_start()
{
	gboolean ret = gtk_text_iter_is_start (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_char()
{
	gboolean ret = gtk_text_iter_forward_char (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_char()
{
	gboolean ret = gtk_text_iter_backward_char (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_chars(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_chars (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_chars(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_chars (instance, count);

	return ret;
}

Php::Value GtkTextIter_::forward_line()
{
	gboolean ret = gtk_text_iter_forward_line (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_line()
{
	gboolean ret = gtk_text_iter_backward_line (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_lines(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_lines (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_lines(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_lines (instance, count);

	return ret;
}

Php::Value GtkTextIter_::forward_word_ends(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_word_ends (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_word_starts(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_word_starts (instance, count);

	return ret;
}

Php::Value GtkTextIter_::forward_word_end()
{
	gboolean ret = gtk_text_iter_forward_word_end (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_word_start()
{
	gboolean ret = gtk_text_iter_backward_word_start (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_cursor_position()
{
	gboolean ret = gtk_text_iter_forward_cursor_position (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_cursor_position()
{
	gboolean ret = gtk_text_iter_backward_cursor_position (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_cursor_positions(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_cursor_positions (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_cursor_positions(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_cursor_positions (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_sentence_start()
{
	gboolean ret = gtk_text_iter_backward_sentence_start (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_sentence_starts(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_sentence_starts (instance, count);

	return ret;
}

Php::Value GtkTextIter_::forward_sentence_end()
{
	gboolean ret = gtk_text_iter_forward_sentence_end (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_sentence_ends(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_sentence_ends (instance, count);

	return ret;
}

Php::Value GtkTextIter_::forward_visible_word_ends(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_visible_word_ends (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_visible_word_starts(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_visible_word_starts (instance, count);

	return ret;
}

Php::Value GtkTextIter_::forward_visible_word_end()
{
	gboolean ret = gtk_text_iter_forward_visible_word_end (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_visible_word_start()
{
	gboolean ret = gtk_text_iter_backward_visible_word_start (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_visible_cursor_position()
{
	gboolean ret = gtk_text_iter_forward_visible_cursor_position (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_visible_cursor_position()
{
	gboolean ret = gtk_text_iter_backward_visible_cursor_position (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_visible_cursor_positions(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_visible_cursor_positions (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_visible_cursor_positions(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_visible_cursor_positions (instance, count);

	return ret;
}

Php::Value GtkTextIter_::forward_visible_line()
{
	gboolean ret = gtk_text_iter_forward_visible_line (instance);

	return ret;
}

Php::Value GtkTextIter_::backward_visible_line()
{
	gboolean ret = gtk_text_iter_backward_visible_line (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_visible_lines(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_forward_visible_lines (instance, count);

	return ret;
}

Php::Value GtkTextIter_::backward_visible_lines(Php::Parameters &parameters)
{
	gint count = (gint)parameters[0];

	gboolean ret = gtk_text_iter_backward_visible_lines (instance, count);

	return ret;
}

void GtkTextIter_::set_offset(Php::Parameters &parameters)
{
	gint char_offset = (gint)parameters[0];

	gtk_text_iter_set_offset (instance, char_offset);

}

void GtkTextIter_::set_line(Php::Parameters &parameters)
{
	gint line_number = (gint)parameters[0];

	gtk_text_iter_set_line (instance, line_number);

}

void GtkTextIter_::set_line_offset(Php::Parameters &parameters)
{
	gint char_on_line = (gint)parameters[0];

	gtk_text_iter_set_line_offset (instance, char_on_line);

}

void GtkTextIter_::set_line_index(Php::Parameters &parameters)
{
	gint byte_on_line = (gint)parameters[0];

	gtk_text_iter_set_line_index (instance, byte_on_line);

}

void GtkTextIter_::set_visible_line_index(Php::Parameters &parameters)
{
	gint byte_on_line = (gint)parameters[0];

	gtk_text_iter_set_visible_line_index (instance, byte_on_line);

}

void GtkTextIter_::set_visible_line_offset(Php::Parameters &parameters)
{
	gint char_on_line = (gint)parameters[0];

	gtk_text_iter_set_visible_line_offset (instance, char_on_line);

}

void GtkTextIter_::forward_to_end()
{
	gtk_text_iter_forward_to_end (instance);

}

Php::Value GtkTextIter_::forward_to_line_end()
{
	gboolean ret = gtk_text_iter_forward_to_line_end (instance);

	return ret;
}

Php::Value GtkTextIter_::forward_to_tag_toggle(Php::Parameters &parameters)
{
	Php::Value object_tag = parameters[0];
	GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
	GtkTextTag *tag = phpgtk_tag->get_tag();
	
	gboolean ret = gtk_text_iter_forward_to_tag_toggle (instance, tag);

	return ret;
}

Php::Value GtkTextIter_::backward_to_tag_toggle(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = phpgtk_tag->get_tag();
	}

	gboolean ret = gtk_text_iter_backward_to_tag_toggle (instance, tag);

	return ret;
}

Php::Value GtkTextIter_::iter_equal(Php::Parameters &parameters)
{
	GtkTextIter *rhs;
	if(parameters.size() > 0) {
		Php::Value object_rhs = parameters[0];
		GtkTextIter_ *phpgtk_rhs = (GtkTextIter_ *)object_rhs.implementation();
		rhs = phpgtk_rhs->get_instance();
	}

	gboolean ret = gtk_text_iter_equal (instance, rhs);

	return ret;
}

Php::Value GtkTextIter_::iter_compare(Php::Parameters &parameters)
{
	GtkTextIter *rhs;
	if(parameters.size() > 0) {
		Php::Value object_rhs = parameters[0];
		GtkTextIter_ *phpgtk_rhs = (GtkTextIter_ *)object_rhs.implementation();
		rhs = phpgtk_rhs->get_instance();
	}

	gboolean ret = gtk_text_iter_compare (instance, rhs);

	return ret;
}

Php::Value GtkTextIter_::in_range(Php::Parameters &parameters)
{
	GtkTextIter *start;
	Php::Value object_start = parameters[0];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	start = phpgtk_start->get_instance();

	GtkTextIter *end;
	if(parameters.size() > 1) {
		Php::Value object_end = parameters[1];
		GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
		end = phpgtk_end->get_instance();
	}

	gboolean ret = gtk_text_iter_in_range (instance, start, end);

	return ret;
}

void GtkTextIter_::order(Php::Parameters &parameters)
{
	GtkTextIter *end;
	Php::Value object_end = parameters[0];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	end = phpgtk_end->get_instance();

	gtk_text_iter_order (instance, end);
}

