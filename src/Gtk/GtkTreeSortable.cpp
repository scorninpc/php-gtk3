

#include "GtkTreeSortable.h"

GtkTreeSortable_::GtkTreeSortable_() = default;
GtkTreeSortable_::~GtkTreeSortable_() = default;

void GtkTreeSortable_::sort_column_changed()
{
	gtk_tree_sortable_sort_column_changed(GTK_TREE_SORTABLE(instance));
}

Php::Value GtkTreeSortable_::get_sort_column_id(Php::Parameters &parameters)
{
	gint* sort_column_id;

	int int_order = parameters[0];
	GtkSortType *order = (GtkSortType*)int_order;

	gtk_tree_sortable_get_sort_column_id(GTK_TREE_SORTABLE(instance), sort_column_id, order);

	return sort_column_id;

}

void GtkTreeSortable_::set_sort_column_id(Php::Parameters &parameters)
{
	gint sort_column_id = (gint)parameters[0];

	int int_order = parameters[1];
	GtkSortType order = (GtkSortType) int_order;

	gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(instance), sort_column_id, order);
}

Php::Value GtkTreeSortable_::has_default_sort_func()
{
	gboolean ret = gtk_tree_sortable_has_default_sort_func(GTK_TREE_SORTABLE(instance));

	return ret;
}

void GtkTreeSortable_::set_sort_func(Php::Parameters& parameters)
{
	gint sort_column_id = (gint)parameters[0];

	int int_order = parameters[1];
	GtkSortType order = (GtkSortType)int_order;

	int int_sort_func = parameters[2];
	GtkTreeIterCompareFunc sort_func = (GtkTreeIterCompareFunc)int_sort_func;

	int int_user_data = parameters[3];
	gpointer user_data = (gpointer)int_user_data;

	int int_destroy = parameters[4];
	GDestroyNotify destroy = (GDestroyNotify)int_destroy;

	gtk_tree_sortable_set_sort_func(GTK_TREE_SORTABLE(instance), sort_column_id, sort_func, user_data, destroy);
}



