
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


Php::Value GtkTreeView_::get_selection()
{
	// 
	GtkTreeSelection *ret = gtk_tree_view_get_selection(GTK_TREE_VIEW(instance));

	GtkTreeSelection_ *return_parsed = new GtkTreeSelection_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTreeSelection", return_parsed);
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