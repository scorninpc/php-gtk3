
#include "GtkListBox.h"

/**
 * Constructor
 */
GtkListBox_::GtkListBox_() = default;

/**
 * Destructor
 */
GtkListBox_::~GtkListBox_() = default;

void GtkListBox_::__construct()
{
	instance = (gpointer *)gtk_list_box_new ();

}

void GtkListBox_::prepend(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_list_box_prepend (GTK_LIST_BOX(instance), child);

}

void GtkListBox_::insert(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint position = (gint)parameters[1];

	gtk_list_box_insert (GTK_LIST_BOX(instance), child, position);

}

void GtkListBox_::select_row(Php::Parameters &parameters)
{
	GtkListBoxRow *row;
	if(parameters.size() > 0) {
		Php::Value object_row = parameters[0];
		GtkListBoxRow_ *phpgtk_row = (GtkListBoxRow_ *)object_row.implementation();
		row = phpgtk_row->get_row();
	}

	gtk_list_box_select_row (GTK_LIST_BOX(instance), row);

}

void GtkListBox_::unselect_row(Php::Parameters &parameters)
{
	GtkListBoxRow *row;
	if(parameters.size() > 0) {
		Php::Value object_row = parameters[0];
		GtkListBoxRow_ *phpgtk_row = (GtkListBoxRow_ *)object_row.implementation();
		row = phpgtk_row->get_row();
	}

	gtk_list_box_unselect_row (GTK_LIST_BOX(instance), row);

}

void GtkListBox_::select_all()
{
	gtk_list_box_select_all (GTK_LIST_BOX(instance));

}

void GtkListBox_::unselect_all()
{
	gtk_list_box_unselect_all (GTK_LIST_BOX(instance));

}

Php::Value GtkListBox_::get_selected_row()
{
	GtkListBoxRow *ret = gtk_list_box_get_selected_row (GTK_LIST_BOX(instance));

	GtkListBoxRow_ *return_parsed = new GtkListBoxRow_();
	return_parsed->set_row(ret);
	return Php::Object("GtkListBoxRow", return_parsed);
}

void GtkListBox_::selected_foreach(Php::Parameters &parameters)
{
	// std::string s_func = parameters[0];
	// gchar *func = (gchar *)s_func.c_str();

	// gpointer data = (gpointer)parameters[1];

	// gtk_list_box_selected_foreach (GTK_LIST_BOX(instance), func, data);

	throw Php::Exception("GtkListBox_::selected_foreach not implemented");

}

Php::Value GtkListBox_::get_selected_rows()
{
	// GList ret = gtk_list_box_get_selected_rows (GTK_LIST_BOX(instance));

	// return ret;
	throw Php::Exception("GtkListBox_::get_selected_rows not implemented");
}

void GtkListBox_::set_selection_mode(Php::Parameters &parameters)
{
	int int_mode = (int)parameters[0];
	GtkSelectionMode mode = (GtkSelectionMode)int_mode;

	gtk_list_box_set_selection_mode (GTK_LIST_BOX(instance), mode);

}

Php::Value GtkListBox_::get_selection_mode()
{
	GtkSelectionMode ret = gtk_list_box_get_selection_mode (GTK_LIST_BOX(instance));

	return ret;
}

void GtkListBox_::set_activate_on_single_click(Php::Parameters &parameters)
{
	gboolean single = (gboolean)parameters[0];

	gtk_list_box_set_activate_on_single_click (GTK_LIST_BOX(instance), single);

}

Php::Value GtkListBox_::get_activate_on_single_click()
{
	gboolean ret = gtk_list_box_get_activate_on_single_click (GTK_LIST_BOX(instance));

	return ret;
}

Php::Value GtkListBox_::get_adjustment()
{
	GtkAdjustment *ret = gtk_list_box_get_adjustment (GTK_LIST_BOX(instance));

	GtkAdjustment_ *return_parsed = new GtkAdjustment_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkAdjustment", return_parsed);
}

void GtkListBox_::set_adjustment(Php::Parameters &parameters)
{
	GtkAdjustment *adjustment;
	if(parameters.size() > 0) {
		Php::Value object_adjustment = parameters[0];
		GtkAdjustment_ *phpgtk_adjustment = (GtkAdjustment_ *)object_adjustment.implementation();
		adjustment = GTK_ADJUSTMENT(phpgtk_adjustment->get_instance());
	}

	gtk_list_box_set_adjustment (GTK_LIST_BOX(instance), adjustment);

}

void GtkListBox_::set_placeholder(Php::Parameters &parameters)
{
	GtkWidget *placeholder;
	if(parameters.size() > 0) {
		Php::Value object_placeholder = parameters[0];
		GtkWidget_ *phpgtk_placeholder = (GtkWidget_ *)object_placeholder.implementation();
		placeholder = GTK_WIDGET(phpgtk_placeholder->get_instance());
	}

	gtk_list_box_set_placeholder (GTK_LIST_BOX(instance), placeholder);

}

Php::Value GtkListBox_::get_row_at_index(Php::Parameters &parameters)
{
	gint index_ = (gint)parameters[0];

	GtkListBoxRow *ret = gtk_list_box_get_row_at_index (GTK_LIST_BOX(instance), index_);

	GtkListBoxRow_ *return_parsed = new GtkListBoxRow_();
	return_parsed->set_row(ret);
	return Php::Object("GtkListBoxRow", return_parsed);
}

Php::Value GtkListBox_::get_row_at_y(Php::Parameters &parameters)
{
	gint y = (gint)parameters[0];

	GtkListBoxRow *ret = gtk_list_box_get_row_at_y (GTK_LIST_BOX(instance), y);

	GtkListBoxRow_ *return_parsed = new GtkListBoxRow_();
	return_parsed->set_row(ret);
	return Php::Object("GtkListBoxRow", return_parsed);
}

void GtkListBox_::invalidate_filter()
{
	gtk_list_box_invalidate_filter (GTK_LIST_BOX(instance));

}

void GtkListBox_::invalidate_headers()
{
	gtk_list_box_invalidate_headers (GTK_LIST_BOX(instance));

}

void GtkListBox_::invalidate_sort()
{
	gtk_list_box_invalidate_sort (GTK_LIST_BOX(instance));

}

void GtkListBox_::set_filter_func(Php::Parameters &parameters)
{
	// std::string s_func = parameters[0];
	// gchar *func = (gchar *)s_func.c_str();

	// gpointer data = (gpointer)parameters[1];

	// std::string s_destroy = parameters[2];
	// gchar *destroy = (gchar *)s_destroy.c_str();

	// gtk_list_box_set_filter_func (GTK_LIST_BOX(instance), func, data, destroy);

	throw Php::Exception("GtkListBox_::set_filter_func not implemented");

}

void GtkListBox_::set_header_func(Php::Parameters &parameters)
{
	// std::string s_func = parameters[0];
	// gchar *func = (gchar *)s_func.c_str();

	// gpointer data = (gpointer)parameters[1];

	// std::string s_destroy = parameters[2];
	// gchar *destroy = (gchar *)s_destroy.c_str();

	// gtk_list_box_set_header_func (GTK_LIST_BOX(instance), func, data, destroy);

	throw Php::Exception("GtkListBox_::set_header_func not implemented");

}

void GtkListBox_::set_sort_func(Php::Parameters &parameters)
{
	// std::string s_func = parameters[0];
	// gchar *func = (gchar *)s_func.c_str();

	// gpointer data = (gpointer)parameters[1];

	// std::string s_destroy = parameters[2];
	// gchar *destroy = (gchar *)s_destroy.c_str();

	// gtk_list_box_set_sort_func (GTK_LIST_BOX(instance), func, data, destroy);

	throw Php::Exception("GtkListBox_::set_sort_func not implemented");

}

void GtkListBox_::drag_highlight_row(Php::Parameters &parameters)
{
	GtkListBoxRow *row;
	if(parameters.size() > 0) {
		Php::Value object_row = parameters[0];
		GtkListBoxRow_ *phpgtk_row = (GtkListBoxRow_ *)object_row.implementation();
		row = phpgtk_row->get_row();
	}

	gtk_list_box_drag_highlight_row (GTK_LIST_BOX(instance), row);

}

void GtkListBox_::drag_unhighlight_row()
{
	gtk_list_box_drag_unhighlight_row (GTK_LIST_BOX(instance));

}

void GtkListBox_::bind_model(Php::Parameters &parameters)
{
	// std::string s_create_widget_func = parameters[0];
	// gchar *create_widget_func = (gchar *)s_create_widget_func.c_str();

	// gpointer user_data = (gpointer)parameters[1];

	// std::string s_user_data_free_func = parameters[2];
	// gchar *user_data_free_func = (gchar *)s_user_data_free_func.c_str();

	// gtk_list_box_bind_model (GTK_LIST_BOX(instance), create_widget_func, user_data, user_data_free_func);

	throw Php::Exception("GtkListBox_::bind_model not implemented");

}

