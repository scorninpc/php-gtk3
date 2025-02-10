
#include "GtkTreeView.h"

/**
 * Constructor
 */
GtkTreeView_::GtkTreeView_() = default;

/**
 * Destructor
 */
GtkTreeView_::~GtkTreeView_() = default;

/**
 *  PHP Constructor
 */
void GtkTreeView_::__construct(Php::Parameters &parameters)
{
	instance = (gpointer *)gtk_tree_view_new();
	liststore_type = false;

	// if(parameters.size() >= 1) {


	//  // Get the model
	//     Php::Value object = parameters[0];
	//     if (!object.instanceOf("GtkTreeModel")) throw Php::Exception("parameter expect GtkTreeModel instance");
	//     GtkTreeModel_ *passedModel = (GtkTreeModel_ *)object.implementation();

	//  gtk_tree_view_set_model(GTK_TREE_VIEW(widget), GTK_TREE_MODEL(passedModel.get_model()));

	// }
}

/**
 * Appends column to the list of columns
 */
Php::Value GtkTreeView_::append_column(Php::Parameters &parameters)
{
	// Get the column
	Php::Value object = parameters[0];
	if (!object.instanceOf("GtkTreeViewColumn")) throw Php::Exception("parameter expect GtkTreeViewColumn instance");
	GtkTreeViewColumn_ *passedColumn = (GtkTreeViewColumn_ *)object.implementation();

	// 
	return gtk_tree_view_append_column(GTK_TREE_VIEW(instance), GTK_TREE_VIEW_COLUMN(passedColumn->get_instance()));
}

/**
 * Sets the model for a GtkTreeView
 */
void GtkTreeView_::set_model(Php::Parameters &parameters)
{
	// Get the column
	Php::Value object = parameters[0];
	// if (!object.instanceOf("GtkTreeModel")) throw Php::Exception("parameter expect GtkTreeModel instance");
	GtkTreeModel_ *passedModel = (GtkTreeModel_ *)object.implementation();

	// Store the Model type
	liststore_type = false;
	if(object.instanceOf("GtkListStore")) {
		liststore_type = true;
	}

	// 
	gtk_tree_view_set_model(GTK_TREE_VIEW(instance), passedModel->get_model());
}

Php::Value GtkTreeView_::get_model()
{
	// 
	GtkTreeModel *ret = gtk_tree_view_get_model(GTK_TREE_VIEW(instance));

	GtkTreeModel_ *return_parsed = new GtkTreeModel_();
	return_parsed->set_model(ret);

	if(liststore_type) {
		return Php::Object("GtkListStore", return_parsed);
	}
	
	return Php::Object("GtkTreeStore", return_parsed);
}

void GtkTreeView_::autosize()
{
	// 
	gtk_tree_view_columns_autosize(GTK_TREE_VIEW(instance));
}

Php::Value GtkTreeView_::get_selection()
{
	// 
	GtkTreeSelection *ret = gtk_tree_view_get_selection(GTK_TREE_VIEW(instance));

	GtkTreeSelection_ *return_parsed = new GtkTreeSelection_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTreeSelection", return_parsed);
}

void GtkTreeView_::collapse_all()
{
	// 
	gtk_tree_view_collapse_all(GTK_TREE_VIEW(instance));
}

void GtkTreeView_::expand_all()
{
	// 
	gtk_tree_view_expand_all(GTK_TREE_VIEW(instance));
}

Php::Value GtkTreeView_::expand_row(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	bool open_all = false;
	if(parameters.size() > 1) {
		open_all = (bool)parameters[1];
	}

	// 
	bool ret = gtk_tree_view_expand_row(GTK_TREE_VIEW(instance), path, open_all);

	return ret;
}

Php::Value GtkTreeView_::row_expanded(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	// 
	bool ret = gtk_tree_view_row_expanded(GTK_TREE_VIEW(instance), path);

	return ret;
}

Php::Value GtkTreeView_::collapse_row(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	// 
	bool ret = gtk_tree_view_collapse_row(GTK_TREE_VIEW(instance), path);

	return ret;
}


void GtkTreeView_::set_level_indentation(Php::Parameters &parameters)
{
	gint indentation = (int)parameters[0];

	gtk_tree_view_set_level_indentation(GTK_TREE_VIEW(instance), indentation);
}

void GtkTreeView_::set_show_expanders(Php::Parameters &parameters)
{
	bool enabled = (bool)parameters[0];

	gtk_tree_view_set_show_expanders(GTK_TREE_VIEW(instance), enabled);
}

void GtkTreeView_::set_enable_tree_lines(Php::Parameters &parameters)
{
	bool enabled = (bool)parameters[0];

	gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(instance), enabled);
}

Php::Value GtkTreeView_::get_enable_tree_lines()
{
    // 
    return gtk_tree_view_get_enable_tree_lines(GTK_TREE_VIEW(instance));
}

void GtkTreeView_::set_reorderable(Php::Parameters &parameters)
{
	bool enabled = (bool)parameters[0];

	gtk_tree_view_set_reorderable(GTK_TREE_VIEW(instance), enabled);
}

Php::Value GtkTreeView_::get_reorderable()
{
    // 
    return gtk_tree_view_get_reorderable(GTK_TREE_VIEW(instance));
}

void GtkTreeView_::set_enable_search(Php::Parameters &parameters)
{
	bool enabled = (bool)parameters[0];

	gtk_tree_view_set_enable_search(GTK_TREE_VIEW(instance), enabled);
}

Php::Value GtkTreeView_::get_enable_search()
{
    // 
    return gtk_tree_view_get_enable_search(GTK_TREE_VIEW(instance));
}

Php::Value GtkTreeView_::get_n_columns()
{
	guint ret = gtk_tree_view_get_n_columns(GTK_TREE_VIEW(instance));
    // 
    return (int)ret;
}

void GtkTreeView_::set_headers_visible(Php::Parameters &parameters)
{
	bool enabled = (bool)parameters[0];

	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(instance), enabled);
}

void GtkTreeView_::select_all()
{
	gtk_tree_selection_select_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(instance)));

}

void GtkTreeView_::unselect_all()
{
	gtk_tree_selection_unselect_all(gtk_tree_view_get_selection(GTK_TREE_VIEW(instance)));

}

// Basic implementaion
void GtkTreeView_::scroll_to_cell(Php::Parameters& parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath* path = gtk_tree_path_new_from_string(param_path.c_str());

	gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(instance), path, NULL, FALSE, 0,0);
}

// Basic implementaion
Php::Value GtkTreeView_::get_columns()
{
	GList* ret = gtk_tree_view_get_columns(GTK_TREE_VIEW(instance));

	Php::Value ret_arr;

	for (int index = 0; GList * item = g_list_nth(ret, index); index++) {

		GtkTreeViewColumn_* column_ = new GtkTreeViewColumn_();
		column_->set_instance((gpointer*)item->data);
		ret_arr[index] = Php::Object("GtkTreeViewColumn", column_);
	}

	return ret_arr;
}

// Basic implementaion
Php::Value GtkTreeView_::get_column(Php::Parameters& parameters)
{

	gint number_column = (gint)parameters[0];

	GtkTreeViewColumn* ret = gtk_tree_view_get_column(GTK_TREE_VIEW(instance), number_column);

	GtkTreeViewColumn_* column_ = new GtkTreeViewColumn_();
	column_->set_instance((gpointer*) ret);
	return Php::Object("GtkTreeViewColumn", column_);
}

void GtkTreeView_::move_column_after(Php::Parameters& parameters)
{
	Php::Value phpColumn = parameters[0];
	Php::Value phpBaseColumn = parameters[1];

	GtkTreeViewColumn_* column = (GtkTreeViewColumn_*)phpColumn.implementation();
	GtkTreeViewColumn_* baseColumn = (GtkTreeViewColumn_*)phpBaseColumn.implementation();

	gtk_tree_view_move_column_after(GTK_TREE_VIEW(instance), GTK_TREE_VIEW_COLUMN(column->get_instance()), GTK_TREE_VIEW_COLUMN(baseColumn->get_instance()));

}

Php::Value GtkTreeView_::get_path_at_pos(Php::Parameters& parameters)
{
	gint x = (gint)parameters[0];
	gint y = (gint)parameters[1];

	GtkTreePath* path = gtk_tree_path_new();
	GtkTreeViewColumn* column = new GtkTreeViewColumn();
	gint cell_x = 0;
	gint cell_y = 0;

	bool ret = gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(instance), x, y, &path, &column, &cell_x, &cell_y);

	if (!ret || column == NULL) {
		// Ensure we return NULL for header clicks
		return Php::Value();
	}

	Php::Value phpPathArray;
	if(path != NULL) {
		gint depth = gtk_tree_path_get_depth(path);
		gint* pathArray = gtk_tree_path_get_indices_with_depth(path, &depth);

		for (int index = 0; index < (int)depth; index++) {
			phpPathArray[index] = pathArray[index];
		}

		gtk_tree_path_free(path);
	}

	GtkTreeViewColumn_* return_parsed = new GtkTreeViewColumn_();
	return_parsed->set_instance((gpointer*)column);

	Php::Value ret_arr;
	ret_arr[0] = phpPathArray;
	ret_arr[1] = Php::Object("GtkTreeViewColumn", return_parsed);
	ret_arr[2] = (int)cell_x;
	ret_arr[3] = (int)cell_y;

	return ret_arr;
}

Php::Value GtkTreeView_::get_bin_window()
{
	gpointer *ret =(gpointer *)gtk_tree_view_get_bin_window(GTK_TREE_VIEW(instance));


	return Php::Object("GdkWindow", ret);
}

Php::Value GtkTreeView_::get_visible_rect()
{
    GdkRectangle rect;
    gtk_tree_view_get_visible_rect(GTK_TREE_VIEW(instance), &rect);

    Php::Value result;
    result["x"] = rect.x;
    result["y"] = rect.y;
    result["width"] = rect.width;
    result["height"] = rect.height;

    return result;
}


Php::Value GtkTreeView_::convert_widget_to_bin_window_coords(Php::Parameters& parameters)
{
	if (parameters.size() < 2) {
        throw Php::Exception("Expected two parameters: widget_x, widget_y");
    }

	gint widget_x = (gint)parameters[0];
	gint widget_y = (gint)parameters[1];
	gint bin_x = 0;
	gint bin_y = 0;

	gtk_tree_view_convert_widget_to_bin_window_coords(GTK_TREE_VIEW(instance), widget_x, widget_y, &bin_x, &bin_y);

	Php::Value ret;
	ret["x"] = (int)bin_x;
	ret["y"] = (int)bin_y;

	return ret;
}

Php::Value GtkTreeView_::convert_widget_to_tree_coords(Php::Parameters& parameters)
{
    if (parameters.size() < 2) {
        throw Php::Exception("Expected two parameters: widget_x, widget_y");
    }

    gint widget_x = (gint)parameters[0];
    gint widget_y = (gint)parameters[1];
    gint tree_x = 0, tree_y = 0;

    gtk_tree_view_convert_widget_to_tree_coords(GTK_TREE_VIEW(instance), widget_x, widget_y, &tree_x, &tree_y);

    Php::Value ret;
    ret["x"] = (int)tree_x;
    ret["y"] = (int)tree_y;
    return ret;
}

Php::Value GtkTreeView_::convert_tree_to_widget_coords(Php::Parameters& parameters)
{
    if (parameters.size() < 2) {
        throw Php::Exception("Expected two parameters: tree_x, tree_y");
    }

    gint tree_x = (gint)parameters[0];
    gint tree_y = (gint)parameters[1];
    gint widget_x = 0, widget_y = 0;

    gtk_tree_view_convert_tree_to_widget_coords(GTK_TREE_VIEW(instance), tree_x, tree_y, &widget_x, &widget_y);

    Php::Value ret;
    ret["x"] = (int)widget_x;
    ret["y"] = (int)widget_y;
    return ret;
}

Php::Value GtkTreeView_::convert_tree_to_bin_window_coords(Php::Parameters& parameters)
{
    if (parameters.size() < 2) {
        throw Php::Exception("Expected two parameters: tree_x, tree_y");
    }

    gint tree_x = (gint)parameters[0];
    gint tree_y = (gint)parameters[1];
    gint bin_x = 0, bin_y = 0;

    gtk_tree_view_convert_tree_to_bin_window_coords(GTK_TREE_VIEW(instance), tree_x, tree_y, &bin_x, &bin_y);

    Php::Value ret;
    ret["x"] = (int)bin_x;
    ret["y"] = (int)bin_y;
    return ret;
}

Php::Value GtkTreeView_::convert_bin_window_to_widget_coords(Php::Parameters& parameters)
{
    if (parameters.size() < 2) {
        throw Php::Exception("Expected two parameters: bin_x, bin_y");
    }

    gint bin_x = (gint)parameters[0];
    gint bin_y = (gint)parameters[1];
    gint widget_x = 0, widget_y = 0;

    gtk_tree_view_convert_bin_window_to_widget_coords(GTK_TREE_VIEW(instance), bin_x, bin_y, &widget_x, &widget_y);

    Php::Value ret;
    ret["x"] = (int)widget_x;
    ret["y"] = (int)widget_y;
    return ret;
}

Php::Value GtkTreeView_::convert_bin_window_to_tree_coords(Php::Parameters& parameters)
{
    if (parameters.size() < 2) {
        throw Php::Exception("Expected two parameters: bin_x, bin_y");
    }

    gint bin_x = (gint)parameters[0];
    gint bin_y = (gint)parameters[1];
    gint tree_x = 0, tree_y = 0;

    gtk_tree_view_convert_bin_window_to_tree_coords(GTK_TREE_VIEW(instance), bin_x, bin_y, &tree_x, &tree_y);

    Php::Value ret;
    ret["x"] = (int)tree_x;
    ret["y"] = (int)tree_y;
    return ret;
}
