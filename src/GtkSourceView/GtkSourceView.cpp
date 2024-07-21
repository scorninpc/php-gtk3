
#include "GtkSourceView.h"

/**
 * Constructor
 */
GtkSourceView_::GtkSourceView_() = default;

/**
 * Destructor
 */
GtkSourceView_::~GtkSourceView_() = default;

void GtkSourceView_::__construct()
{
	// instance = (gpointer *)gtk_source_view_new ();

	GtkSourceBuffer *buffer = gtk_source_buffer_new (NULL);
	GtkSourceLanguageManager *langm = gtk_source_language_manager_new ();
	GtkSourceLanguage *lang = gtk_source_language_manager_get_language (langm, "php");
	gtk_source_buffer_set_language(buffer, lang);

	instance = (gpointer *)gtk_source_view_new_with_buffer (buffer);



}

Php::Value GtkSourceView_::new_with_buffer(Php::Parameters &parameters)
{
// // 	GtkSourceBuffer *buffer;
// 	if(parameters.size() > 0) {
// 		Php::Value object_buffer = parameters[0];
// 		GtkSourceBuffer_ *phpgtk_buffer = (GtkSourceBuffer_ *)object_buffer.implementation();
// 		buffer = GTK_WIDGET(phpgtk_buffer->get_instance());
// 	}

// 	GtkWidget *ret = gtk_source_view_new_with_buffer (buffer);

// 	GtkWidget_ *return_parsed = new GtkWidget_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkWidget", return_parsed);
	 throw Php::Exception("GtkSourceView_::new_with_buffer not implemented");}

void GtkSourceView_::set_show_line_numbers(Php::Parameters &parameters)
{
	gboolean show = (gboolean)parameters[0];

	gtk_source_view_set_show_line_numbers (GTK_SOURCE_VIEW(instance), show);

}

Php::Value GtkSourceView_::get_show_line_numbers()
{
	bool ret = gtk_source_view_get_show_line_numbers (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_show_right_margin(Php::Parameters &parameters)
{
	gboolean show = (gboolean)parameters[0];

	gtk_source_view_set_show_right_margin (GTK_SOURCE_VIEW(instance), show);

}

Php::Value GtkSourceView_::get_show_right_margin()
{
	bool ret = gtk_source_view_get_show_right_margin (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_right_margin_position(Php::Parameters &parameters)
{
	guint pos = (int)parameters[0];

	gtk_source_view_set_right_margin_position (GTK_SOURCE_VIEW(instance), pos);

}

Php::Value GtkSourceView_::get_right_margin_position()
{
	int ret = gtk_source_view_get_right_margin_position (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_highlight_current_line(Php::Parameters &parameters)
{
	gboolean highlight = (gboolean)parameters[0];

	gtk_source_view_set_highlight_current_line (GTK_SOURCE_VIEW(instance), highlight);

}

Php::Value GtkSourceView_::get_highlight_current_line()
{
	bool ret = gtk_source_view_get_highlight_current_line (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_auto_indent(Php::Parameters &parameters)
{
	gboolean enable = (gboolean)parameters[0];

	gtk_source_view_set_auto_indent (GTK_SOURCE_VIEW(instance), enable);

}

Php::Value GtkSourceView_::get_auto_indent()
{
	bool ret = gtk_source_view_get_auto_indent (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_indent_on_tab(Php::Parameters &parameters)
{
	gboolean enable = (gboolean)parameters[0];

	gtk_source_view_set_indent_on_tab (GTK_SOURCE_VIEW(instance), enable);

}

Php::Value GtkSourceView_::get_indent_on_tab()
{
	bool ret = gtk_source_view_get_indent_on_tab (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_tab_width(Php::Parameters &parameters)
{
	guint width = (int)parameters[0];

	gtk_source_view_set_tab_width (GTK_SOURCE_VIEW(instance), width);

}

Php::Value GtkSourceView_::get_tab_width()
{
	int ret = gtk_source_view_get_tab_width (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_indent_width(Php::Parameters &parameters)
{
	gint width = (gint)parameters[0];

	gtk_source_view_set_indent_width (GTK_SOURCE_VIEW(instance), width);

}

Php::Value GtkSourceView_::get_indent_width()
{
	gint ret = gtk_source_view_get_indent_width (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_insert_spaces_instead_of_tabs(Php::Parameters &parameters)
{
	gboolean enable = (gboolean)parameters[0];

	gtk_source_view_set_insert_spaces_instead_of_tabs (GTK_SOURCE_VIEW(instance), enable);

}

Php::Value GtkSourceView_::get_insert_spaces_instead_of_tabs()
{
	bool ret = gtk_source_view_get_insert_spaces_instead_of_tabs (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::indent_lines(Php::Parameters &parameters)
{
	GtkTextIter start;
	if(parameters.size() > 0) {
		Php::Value object_start = parameters[0];
		GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
		start = (phpgtk_start->get_instance());
	}

	GtkTextIter end;
	if(parameters.size() > 1) {
		Php::Value object_end = parameters[1];
		GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
		end = (phpgtk_end->get_instance());
	}

	gtk_source_view_indent_lines (GTK_SOURCE_VIEW(instance), &start, &end);

}

void GtkSourceView_::unindent_lines(Php::Parameters &parameters)
{
	GtkTextIter start;
	if(parameters.size() > 0) {
		Php::Value object_start = parameters[0];
		GtkTextIter_ *phpgtk_start = (GtkTextIter_ *)object_start.implementation();
		start = (phpgtk_start->get_instance());
	}

	GtkTextIter end;
	if(parameters.size() > 1) {
		Php::Value object_end = parameters[1];
		GtkTextIter_ *phpgtk_end = (GtkTextIter_ *)object_end.implementation();
		end = (phpgtk_end->get_instance());
	}

	gtk_source_view_unindent_lines (GTK_SOURCE_VIEW(instance), &start, &end);

}

Php::Value GtkSourceView_::get_visual_column(Php::Parameters &parameters)
{
	GtkTextIter iter;
	if(parameters.size() > 0) {
		Php::Value object_iter = parameters[0];
		GtkTextIter_ *phpgtk_iter = (GtkTextIter_ *)object_iter.implementation();
		iter = (phpgtk_iter->get_instance());
	}

	int ret = gtk_source_view_get_visual_column (GTK_SOURCE_VIEW(instance), &iter);

	return ret;
}

void GtkSourceView_::set_smart_backspace(Php::Parameters &parameters)
{
	gboolean smart_backspace = (gboolean)parameters[0];

	gtk_source_view_set_smart_backspace (GTK_SOURCE_VIEW(instance), smart_backspace);

}

Php::Value GtkSourceView_::get_smart_backspace()
{
	bool ret = gtk_source_view_get_smart_backspace (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_smart_home_end(Php::Parameters &parameters)
{
	int int_smart_home_end = (int)parameters[0];
	GtkSourceSmartHomeEndType smart_home_end = (GtkSourceSmartHomeEndType)int_smart_home_end;

	gtk_source_view_set_smart_home_end (GTK_SOURCE_VIEW(instance), smart_home_end);

}

Php::Value GtkSourceView_::get_smart_home_end()
{
	GtkSourceSmartHomeEndType ret = gtk_source_view_get_smart_home_end (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_mark_attributes(Php::Parameters &parameters)
{
// // 	std::string s_category = parameters[0];
// 	gchar *category = (gchar *)s_category.c_str();

// // 	GtkSourceMarkAttributes *attributes;
// 	if(parameters.size() > 1) {
// 		Php::Value object_attributes = parameters[1];
// 		GtkSourceMarkAttributes_ *phpgtk_attributes = (GtkSourceMarkAttributes_ *)object_attributes.implementation();
// 		attributes = GTK_WIDGET(phpgtk_attributes->get_instance());
// 	}

// // 	gint priority = (gint)parameters[2];

// 	gtk_source_view_set_mark_attributes (GTK_SOURCE_VIEW(instance), category, attributes, priority);

	 throw Php::Exception("GtkSourceView_::set_mark_attributes not implemented");}

Php::Value GtkSourceView_::get_mark_attributes(Php::Parameters &parameters)
{
// // 	std::string s_category = parameters[0];
// 	gchar *category = (gchar *)s_category.c_str();

// // 	gint priority = (gint)parameters[1];

// 	GtkSourceMarkAttributes *ret = gtk_source_view_get_mark_attributes (GTK_SOURCE_VIEW(instance), category, priority);

// 	GtkSourceMarkAttributes_ *return_parsed = new GtkSourceMarkAttributes_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkSourceMarkAttributes", return_parsed);
	 throw Php::Exception("GtkSourceView_::get_mark_attributes not implemented");}

void GtkSourceView_::set_show_line_marks(Php::Parameters &parameters)
{
	gboolean show = (gboolean)parameters[0];

	gtk_source_view_set_show_line_marks (GTK_SOURCE_VIEW(instance), show);

}

Php::Value GtkSourceView_::get_show_line_marks()
{
	bool ret = gtk_source_view_get_show_line_marks (GTK_SOURCE_VIEW(instance));

	return ret;
}

void GtkSourceView_::set_draw_spaces(Php::Parameters &parameters)
{
	// int int_flags = (int)parameters[0];
	// GtkSourceDrawSpacesFlags flags = (GtkSourceDrawSpacesFlags)int_flags;

	// gtk_source_view_set_draw_spaces (GTK_SOURCE_VIEW(instance), flags);

	// Deprecated
	Php::deprecated << "set_draw_spaces is deprecated on Gtk 3.24" << std::endl;

}

Php::Value GtkSourceView_::get_draw_spaces()
{
	// GtkSourceDrawSpacesFlags ret = gtk_source_view_get_draw_spaces (GTK_SOURCE_VIEW(instance));

	// Deprecated
	Php::deprecated << "get_draw_spaces is deprecated on Gtk 3.24" << std::endl;

	return 1;
}

Php::Value GtkSourceView_::get_completion()
{
// 	GtkSourceCompletion *ret = gtk_source_view_get_completion (GTK_SOURCE_VIEW(instance));

// 	GtkSourceCompletion_ *return_parsed = new GtkSourceCompletion_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkSourceCompletion", return_parsed);
	 throw Php::Exception("GtkSourceView_::get_completion not implemented");}

Php::Value GtkSourceView_::get_gutter(Php::Parameters &parameters)
{
// // 	int int_window_type = (int)parameters[0];
// 	GtkTextWindowType window_type = (GtkTextWindowType)int_window_type;

// 	GtkSourceGutter *ret = gtk_source_view_get_gutter (GTK_SOURCE_VIEW(instance), window_type);

// 	GtkSourceGutter_ *return_parsed = new GtkSourceGutter_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkSourceGutter", return_parsed);
	 throw Php::Exception("GtkSourceView_::get_gutter not implemented");}

void GtkSourceView_::set_background_pattern(Php::Parameters &parameters)
{
	int int_background_pattern = (int)parameters[0];
	GtkSourceBackgroundPatternType background_pattern = (GtkSourceBackgroundPatternType)int_background_pattern;

	gtk_source_view_set_background_pattern (GTK_SOURCE_VIEW(instance), background_pattern);

}

Php::Value GtkSourceView_::get_background_pattern()
{
	GtkSourceBackgroundPatternType ret = gtk_source_view_get_background_pattern (GTK_SOURCE_VIEW(instance));

	return ret;
}

