
#include "GtkTextBuffer.h"

/**
 * Constructor
 */
GtkTextBuffer_::GtkTextBuffer_() = default;

/**
 * Destructor
 */
GtkTextBuffer_::~GtkTextBuffer_() = default;

void GtkTextBuffer_::__construct()
{
	instance = (gpointer *)gtk_text_buffer_new (NULL);

}

Php::Value GtkTextBuffer_::get_line_count()
{
	gint ret = gtk_text_buffer_get_line_count (GTK_TEXT_BUFFER(instance));

	return ret;
}

Php::Value GtkTextBuffer_::get_char_count()
{
	gint ret = gtk_text_buffer_get_char_count (GTK_TEXT_BUFFER(instance));

	return ret;
}

Php::Value GtkTextBuffer_::get_tag_table()
{
	GtkTextTagTable *ret = gtk_text_buffer_get_tag_table (GTK_TEXT_BUFFER(instance));

	GtkTextTagTable_ *return_parsed = new GtkTextTagTable_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextTagTable", return_parsed);
}

void GtkTextBuffer_::insert(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gint len = (gint)parameters[2];

	gtk_text_buffer_insert (GTK_TEXT_BUFFER(instance), &iter, text, len);

}

void GtkTextBuffer_::insert_at_cursor(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gint len = (gint)parameters[1];

	gtk_text_buffer_insert_at_cursor (GTK_TEXT_BUFFER(instance), text, len);

}

Php::Value GtkTextBuffer_::insert_interactive(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gint len = (gint)parameters[2];

	gboolean default_editable = (gboolean)parameters[3];

	gboolean ret = gtk_text_buffer_insert_interactive (GTK_TEXT_BUFFER(instance), &iter, text, len, default_editable);

	return ret;
}

Php::Value GtkTextBuffer_::insert_interactive_at_cursor(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gint len = (gint)parameters[1];

	gboolean default_editable = (gboolean)parameters[2];

	gboolean ret = gtk_text_buffer_insert_interactive_at_cursor (GTK_TEXT_BUFFER(instance), text, len, default_editable);

	return ret;
}

void GtkTextBuffer_::insert_range(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();

	Php::Value object_start = parameters[1];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();

	Php::Value object_end = parameters[2];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gtk_text_buffer_insert_range (GTK_TEXT_BUFFER(instance), &iter, &start, &end);

}

Php::Value GtkTextBuffer_::insert_range_interactive(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();



	Php::Value object_start = parameters[1];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();

	Php::Value object_end = parameters[2];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gboolean default_editable = (gboolean)parameters[3];

	gboolean ret = gtk_text_buffer_insert_range_interactive (GTK_TEXT_BUFFER(instance), &iter, &start, &end, default_editable);

	return ret;
}

void GtkTextBuffer_::insert_with_tags(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();
	
	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gint len = (gint)parameters[2];

	GtkTextTag *first_tag;
	if(parameters.size() > 3) {
		Php::Value object_first_tag = parameters[3];
		GtkTextTag_ *phpgtk_first_tag = (GtkTextTag_ *)object_first_tag.implementation();
		first_tag = (phpgtk_first_tag->get_tag());
	}

	gtk_text_buffer_insert_with_tags (GTK_TEXT_BUFFER(instance), &iter, text, len, first_tag, NULL);

}

void GtkTextBuffer_::insert_with_tags_by_name(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();
	

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gint len = (gint)parameters[2];

	std::string s_first_tag_name = parameters[3];
	const gchar *first_tag_name = s_first_tag_name.c_str();

	gtk_text_buffer_insert_with_tags_by_name (GTK_TEXT_BUFFER(instance), &iter, text, len, first_tag_name, NULL);

}

void GtkTextBuffer_::insert_markup(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();
	

	std::string s_markup = parameters[1];
	gchar *markup = (gchar *)s_markup.c_str();

	gint len = (gint)parameters[2];

	gtk_text_buffer_insert_markup (GTK_TEXT_BUFFER(instance), &iter, markup, len);

}

void GtkTextBuffer_::delete_(Php::Parameters &parameters)
{

	Php::Value object_start = parameters[0];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[1];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gtk_text_buffer_delete (GTK_TEXT_BUFFER(instance), &start, &end);

}

Php::Value GtkTextBuffer_::delete_interactive(Php::Parameters &parameters)
{

	Php::Value object_start = parameters[0];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[1];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gboolean default_editable = (gboolean)parameters[2];

	gboolean ret = gtk_text_buffer_delete_interactive (GTK_TEXT_BUFFER(instance), &start, &end, default_editable);

	return ret;
}

Php::Value GtkTextBuffer_::backspace(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
	GtkTextIter iter = phpgtk_iter->get_instance();
	

	gboolean interactive = (gboolean)parameters[1];

	gboolean default_editable = (gboolean)parameters[2];

	gboolean ret = gtk_text_buffer_backspace (GTK_TEXT_BUFFER(instance), &iter, interactive, default_editable);

	return ret;
}

void GtkTextBuffer_::set_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gint len = s_text.length();
	if(parameters.size() >= 2)
		len = (gint)parameters[1];

	gtk_text_buffer_set_text (GTK_TEXT_BUFFER(instance), text, len);

}

Php::Value GtkTextBuffer_::get_text(Php::Parameters &parameters)
{

	Php::Value object_start = parameters[0];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[1];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gboolean include_hidden_chars = (gboolean)parameters[2];

	std::string ret = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(instance), &start, &end, include_hidden_chars);

	return ret;
}

Php::Value GtkTextBuffer_::get_slice(Php::Parameters &parameters)
{

	Php::Value object_start = parameters[0];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[1];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gboolean include_hidden_chars = (gboolean)parameters[2];

	std::string ret = gtk_text_buffer_get_slice (GTK_TEXT_BUFFER(instance), &start, &end, include_hidden_chars);

	return ret;
}

void GtkTextBuffer_::insert_pixbuf(Php::Parameters &parameters)
{
	
// 	Php::Value object_iter = parameters[0];
// 	GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
// GtkTextIter iter	iter = phpgtk_iter->get_instance();
// }


	// gtk_text_buffer_insert_pixbuf (GTK_TEXT_BUFFER(instance), &iter, pixbuf);

	throw Php::Exception("GtkTextBuffer_::insert_pixbuf not implemented");
}

Php::Value GtkTextBuffer_::create_mark(Php::Parameters &parameters)
{
	std::string s_mark_name = parameters[0];
	gchar *mark_name = (gchar *)s_mark_name.c_str();

	Php::Value object_where = parameters[1];
	GtkTextIter_ *phpgtk_where = (GtkTextIter_ *)object_where.implementation();
	GtkTextIter where = phpgtk_where->get_instance();

	gboolean left_gravity = (gboolean)parameters[2];

	GtkTextMark *ret = gtk_text_buffer_create_mark (GTK_TEXT_BUFFER(instance), mark_name, &where, left_gravity);

	GtkTextMark_ *return_parsed = new GtkTextMark_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextMark", return_parsed);
}

void GtkTextBuffer_::move_mark(Php::Parameters &parameters)
{
	GtkTextMark *mark;
	if(parameters.size() > 0) {
		Php::Value object_mark = parameters[0];
		GtkTextMark_ *phpgtk_mark = (GtkTextMark_ *)object_mark.implementation();
		mark = GTK_TEXT_MARK(phpgtk_mark->get_instance());
	}


	Php::Value object_where = parameters[1];
	GtkTextIter_ *phpgtk_where = (GtkTextIter_ *)object_where.implementation();
	GtkTextIter where = phpgtk_where->get_instance();

	gtk_text_buffer_move_mark (GTK_TEXT_BUFFER(instance), mark, &where);

}

void GtkTextBuffer_::move_mark_by_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();


	Php::Value object_where = parameters[1];
	GtkTextIter_ *phpgtk_where = (GtkTextIter_ *)object_where.implementation();
	GtkTextIter where = (phpgtk_where->get_instance());

	gtk_text_buffer_move_mark_by_name (GTK_TEXT_BUFFER(instance), name, &where);

}

void GtkTextBuffer_::add_mark(Php::Parameters &parameters)
{
	GtkTextMark *mark;
	if(parameters.size() > 0) {
		Php::Value object_mark = parameters[0];
		GtkTextMark_ *phpgtk_mark = (GtkTextMark_ *)object_mark.implementation();
		mark = GTK_TEXT_MARK(phpgtk_mark->get_instance());
	}


	Php::Value object_where = parameters[1];
	GtkTextIter_ *phpgtk_where = (GtkTextIter_ *)object_where.implementation();
	GtkTextIter where = phpgtk_where->get_instance();

	gtk_text_buffer_add_mark (GTK_TEXT_BUFFER(instance), mark, &where);

}

void GtkTextBuffer_::delete_mark(Php::Parameters &parameters)
{
	GtkTextMark *mark;
	if(parameters.size() > 0) {
		Php::Value object_mark = parameters[0];
		GtkTextMark_ *phpgtk_mark = (GtkTextMark_ *)object_mark.implementation();
		mark = GTK_TEXT_MARK(phpgtk_mark->get_instance());
	}

	gtk_text_buffer_delete_mark (GTK_TEXT_BUFFER(instance), mark);

}

void GtkTextBuffer_::delete_mark_by_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_text_buffer_delete_mark_by_name (GTK_TEXT_BUFFER(instance), name);

}

Php::Value GtkTextBuffer_::get_mark(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	GtkTextMark *ret = gtk_text_buffer_get_mark (GTK_TEXT_BUFFER(instance), name);

	GtkTextMark_ *return_parsed = new GtkTextMark_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextMark", return_parsed);
}

Php::Value GtkTextBuffer_::get_insert(Php::Parameters &parameters)
{
	GtkTextMark *ret = gtk_text_buffer_get_insert (GTK_TEXT_BUFFER(instance));

	GtkTextMark_ *return_parsed = new GtkTextMark_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextMark", return_parsed);
}

Php::Value GtkTextBuffer_::get_selection_bound(Php::Parameters &parameters)
{
	GtkTextMark *ret = gtk_text_buffer_get_selection_bound (GTK_TEXT_BUFFER(instance));

	GtkTextMark_ *return_parsed = new GtkTextMark_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextMark", return_parsed);
}

Php::Value GtkTextBuffer_::get_has_selection(Php::Parameters &parameters)
{
	gboolean ret = gtk_text_buffer_get_has_selection (GTK_TEXT_BUFFER(instance));

	return ret;
}

void GtkTextBuffer_::place_cursor(Php::Parameters &parameters)
{

	Php::Value object_where = parameters[0];
	GtkTextIter_ *phpgtk_where = (GtkTextIter_ *)object_where.implementation();
	GtkTextIter where = phpgtk_where->get_instance();

	gtk_text_buffer_place_cursor (GTK_TEXT_BUFFER(instance), &where);

}

void GtkTextBuffer_::select_range(Php::Parameters &parameters)
{

	Php::Value object_ins = parameters[0];
	GtkTextIter_ *phpgtk_ins = (GtkTextIter_ *)object_ins.implementation();
	GtkTextIter ins = phpgtk_ins->get_instance();


	Php::Value object_bound = parameters[1];
	GtkTextIter_ *phpgtk_bound = (GtkTextIter_ *)object_bound.implementation();
	GtkTextIter bound = phpgtk_bound->get_instance();

	gtk_text_buffer_select_range (GTK_TEXT_BUFFER(instance), &ins, &bound);

}

void GtkTextBuffer_::apply_tag(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = phpgtk_tag->get_tag();
	}


	Php::Value object_start = parameters[1];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[2];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gtk_text_buffer_apply_tag (GTK_TEXT_BUFFER(instance), tag, &start, &end);

}

void GtkTextBuffer_::remove_tag(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = phpgtk_tag->get_tag();
	}


	Php::Value object_start = parameters[1];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[2];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gtk_text_buffer_remove_tag (GTK_TEXT_BUFFER(instance), tag, &start, &end);

}

void GtkTextBuffer_::apply_tag_by_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();


	Php::Value object_start = parameters[1];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[2];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gtk_text_buffer_apply_tag_by_name (GTK_TEXT_BUFFER(instance), name, &start, &end);

}

void GtkTextBuffer_::remove_tag_by_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();


	Php::Value object_start = parameters[1];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[2];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gtk_text_buffer_remove_tag_by_name (GTK_TEXT_BUFFER(instance), name, &start, &end);

}

void GtkTextBuffer_::remove_all_tags(Php::Parameters &parameters)
{

	Php::Value object_start = parameters[0];
	GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
	GtkTextIter start = phpgtk_start->get_instance();


	Php::Value object_end = parameters[1];
	GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
	GtkTextIter end = phpgtk_end->get_instance();

	gtk_text_buffer_remove_all_tags (GTK_TEXT_BUFFER(instance), &start, &end);

}

Php::Value GtkTextBuffer_::create_tag(Php::Parameters &parameters)
{
	std::string s_tag_name = parameters[0];
	gchar *tag_name = (gchar *)s_tag_name.c_str();

	std::string s_first_property_name = parameters[1];
	gchar *first_property_name = (gchar *)s_first_property_name.c_str();

	GtkTextTag *ret = gtk_text_buffer_create_tag (GTK_TEXT_BUFFER(instance), tag_name, first_property_name);

	GtkTextTag_ *return_parsed = new GtkTextTag_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextTag", return_parsed);
}

Php::Value GtkTextBuffer_::get_iter_at_line_offset(Php::Parameters &parameters)
{
	GtkTextIter iter;

	gint line_number = (gint)parameters[0];

	gint char_offset = (gint)parameters[1];

	gtk_text_buffer_get_iter_at_line_offset (GTK_TEXT_BUFFER(instance), &iter, line_number, char_offset);



	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextBuffer_::get_iter_at_offset(Php::Parameters &parameters)
{
	GtkTextIter iter;
	
	gint char_offset = (gint)parameters[0];

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(instance), &iter, char_offset);

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextBuffer_::get_iter_at_line(Php::Parameters &parameters)
{
	GtkTextIter iter;

	gint line_number = (gint)parameters[0];

	gtk_text_buffer_get_iter_at_line (GTK_TEXT_BUFFER(instance), &iter, line_number);

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextBuffer_::get_iter_at_line_index(Php::Parameters &parameters)
{
	GtkTextIter iter;

	gint line_number = (gint)parameters[0];

	gint byte_index = (gint)parameters[1];

	gtk_text_buffer_get_iter_at_line_index (GTK_TEXT_BUFFER(instance), &iter, line_number, byte_index);

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextBuffer_::get_iter_at_mark(Php::Parameters &parameters)
{
	GtkTextIter iter;

	GtkTextMark *mark;
	Php::Value object_mark = parameters[0];
	GtkTextMark_ *phpgtk_mark = (GtkTextMark_ *)object_mark.implementation();
	mark = GTK_TEXT_MARK(phpgtk_mark->get_instance());

	gtk_text_buffer_get_iter_at_mark (GTK_TEXT_BUFFER(instance), &iter, mark);

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextBuffer_::get_start_iter()
{
	GtkTextIter iter;

	gtk_text_buffer_get_start_iter (GTK_TEXT_BUFFER(instance), &iter);

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextBuffer_::get_end_iter()
{
	GtkTextIter iter;

	gtk_text_buffer_get_end_iter (GTK_TEXT_BUFFER(instance), &iter);

	GtkTextIter_ *return_parsed = new GtkTextIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTextIter", return_parsed);
}

Php::Value GtkTextBuffer_::get_bounds()
{
	GtkTextIter start;
	GtkTextIter end;
	
	gtk_text_buffer_get_bounds (GTK_TEXT_BUFFER(instance), &start, &end);


	Php::Value arr;

	GtkTextIter_ *return_parsed_start = new GtkTextIter_();
	return_parsed_start->set_instance(start);
	arr["start"] = Php::Object("GtkTextIter", return_parsed_start);
	arr[0] = arr["start"];

	GtkTextIter_ *return_parsed_end = new GtkTextIter_();
	return_parsed_end->set_instance(start);
	arr["end"] = Php::Object("GtkTextIter", return_parsed_end);
	arr[1] = arr["end"];

	return arr;
}

Php::Value GtkTextBuffer_::get_modified()
{
	gboolean ret = gtk_text_buffer_get_modified (GTK_TEXT_BUFFER(instance));

	return ret;
}

void GtkTextBuffer_::set_modified(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_text_buffer_set_modified (GTK_TEXT_BUFFER(instance), setting);

}

Php::Value GtkTextBuffer_::delete_selection(Php::Parameters &parameters)
{
	gboolean interactive = (gboolean)parameters[0];

	gboolean default_editable = (gboolean)parameters[1];

	gboolean ret = gtk_text_buffer_delete_selection (GTK_TEXT_BUFFER(instance), interactive, default_editable);

	return ret;
}

void GtkTextBuffer_::paste_clipboard(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::paste_clipboard not implemented");
}

void GtkTextBuffer_::copy_clipboard(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::copy_clipboard not implemented");
}

void GtkTextBuffer_::cut_clipboard(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::cut_clipboard not implemented");
}

Php::Value GtkTextBuffer_::get_selection_bounds(Php::Parameters &parameters)
{
	GtkTextIter start;
	GtkTextIter end;

	gboolean ret = gtk_text_buffer_get_selection_bounds (GTK_TEXT_BUFFER(instance), &start, &end);
	if(!ret) 
		return ret;

	Php::Value arr;

	GtkTextIter_ *return_parsed_start = new GtkTextIter_();
	return_parsed_start->set_instance(start);
	arr["start"] = Php::Object("GtkTextIter", return_parsed_start);
	arr[0] = arr["start"];

	GtkTextIter_ *return_parsed_end = new GtkTextIter_();
	return_parsed_end->set_instance(start);
	arr["end"] = Php::Object("GtkTextIter", return_parsed_end);
	arr[1] = arr["end"];

	return arr;
}

void GtkTextBuffer_::begin_user_action()
{
	gtk_text_buffer_begin_user_action (GTK_TEXT_BUFFER(instance));

}

void GtkTextBuffer_::end_user_action()
{
	gtk_text_buffer_end_user_action (GTK_TEXT_BUFFER(instance));

}

void GtkTextBuffer_::remove_selection_clipboard(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::remove_selection_clipboard not implemented");
}

Php::Value GtkTextBuffer_::deserialize(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::deserialize not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::deserialize_get_can_create_tags(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::deserialize_get_can_create_tags not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::deserialize_set_can_create_tags(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::deserialize_set_can_create_tags not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::get_copy_target_list(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::get_copy_target_list not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::get_deserialize_formats(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::get_deserialize_formats not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::get_paste_target_list(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::get_paste_target_list not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::get_serialize_formats(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::get_serialize_formats not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::register_deserialize_format(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::register_deserialize_format not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::register_serialize_format(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::register_serialize_format not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::register_serialize_tagset(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::register_serialize_tagset not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::serialize(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::serialize not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::unregister_deserialize_format(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::unregister_deserialize_format not implemented");
	return -1;
}

Php::Value GtkTextBuffer_::unregister_serialize_format(Php::Parameters &parameters)
{
	throw Php::Exception("GtkTextBuffer_::unregister_serialize_format not implemented");
	return -1;
}

