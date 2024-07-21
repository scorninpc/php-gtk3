
#include "GtkTreeSelection.h"

/**
 * Constructor
 */
GtkTreeSelection_::GtkTreeSelection_() = default;

/**
 * Destructor
 */
GtkTreeSelection_::~GtkTreeSelection_() = default;

void GtkTreeSelection_::set_mode(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GtkSelectionMode type = (GtkSelectionMode)int_type;

	gtk_tree_selection_set_mode (GTK_TREE_SELECTION(instance), type);

}

Php::Value GtkTreeSelection_::get_mode()
{
	GtkSelectionMode ret = gtk_tree_selection_get_mode (GTK_TREE_SELECTION(instance));

	return ret;
}

void GtkTreeSelection_::set_select_function(Php::Parameters &parameters)
{
	// GtkTreeIter *iter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_iter = parameters[0];
	// 	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	// 	iter = GTK_WIDGET(phpgtk_iter->get_instance());
	// }

	// gtk_tree_selection_set_select_function (GTK_TREE_SELECTION(instance), iter);

	throw Php::Exception("GtkTreeSelection_->set_select_function() not implemented yet");

}

void GtkTreeSelection_::get_select_function(Php::Parameters &parameters)
{
	// GtkTreeIter *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkTreeIter_ *phpgtk_parent = (GtkTreeIter_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// gint position = (gint)parameters[1];

	// gtk_tree_selection_get_select_function (GTK_TREE_SELECTION(instance), parent, position);

	throw Php::Exception("GtkTreeSelection_->get_select_function() not implemented yet");

}

Php::Value GtkTreeSelection_::get_user_data(Php::Parameters &parameters)
{
	// GtkTreeIter *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkTreeIter_ *phpgtk_parent = (GtkTreeIter_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// GtkTreeIter *sibling;
	// if(parameters.size() > 1) {
	// 	Php::Value object_sibling = parameters[1];
	// 	GtkTreeIter_ *phpgtk_sibling = (GtkTreeIter_ *)object_sibling.implementation();
	// 	sibling = GTK_WIDGET(phpgtk_sibling->get_instance());
	// }

	// gpointer ret = gtk_tree_selection_get_user_data (GTK_TREE_SELECTION(instance), parent, sibling);

	// return ret;

	throw Php::Exception("GtkTreeSelection_->get_user_data() not implemented yet");
}

Php::Value GtkTreeSelection_::get_tree_view()
{
	GtkTreeView *ret = gtk_tree_selection_get_tree_view (GTK_TREE_SELECTION(instance));

	GtkTreeView_ *return_parsed = new GtkTreeView_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTreeView", return_parsed);
}

Php::Value GtkTreeSelection_::get_selected(Php::Parameters &parameters)
{
	GtkTreeModel *model;
	GtkTreeIter iter;

	bool ret = gtk_tree_selection_get_selected (GTK_TREE_SELECTION(instance), &model, &iter);
	if(!ret) {
		return false;
	}

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
    return_parsed->set_instance(iter);

	GtkTreeModel_* return_parsed_model = new GtkTreeModel_();
	return_parsed_model->set_model(model);

	Php::Value result;
	result[0] = Php::Object("GtkTreeModel", return_parsed_model);
	result[1] = Php::Object("GtkTreeIter", return_parsed);

    return result;
}

void GtkTreeSelection_::selected_foreach(Php::Parameters &parameters)
{
	// GtkTreeIter *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkTreeIter_ *phpgtk_parent = (GtkTreeIter_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// gint position = (gint)parameters[1];

	// GtkTreeIter *ret = gtk_tree_selection_selected_foreach (GTK_TREE_SELECTION(instance), parent, position);

	// GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkTreeIter", return_parsed);



	/**
	 * on the caller
	 * 
	 * - create a struct with CALLBACK_SPEC, SELF_OBJECT, PHP_FUNCTION_TO_CALL, USER_PARAMETERS
	 * - fetch specs from callback function, and store it on struct
	 * - call the default callback
	 * 
	 * on the default callback
	 * 
	 * - start create Php::parameters, add self object
	 * - read CALLBACK_SPEC and loop between paramters and parse to Php::value
	 * - append user parameters
	 * - call PHP_FUNCTION_TO_CALL
	 * - return the result of PHP_FUNCTION_TO_CALL
	 */

	// Php::call("var_dump", "OK 1.0");

	// create a object to populate and pass to generic callback
    struct generic_st_callback *callback_object = (struct generic_st_callback *)malloc(sizeof(struct generic_st_callback));
    memset(callback_object, 0, sizeof(struct generic_st_callback));

	callback_object->callback_name = parameters[0];

// Php::call("var_dump", "OK 1.1");

	// add paramters
	callback_object->parameters = parameters;

// Php::call("var_dump", "OK 1.2");

	// add self object
	callback_object->self_widget = cobject_to_phpobject((gpointer *)instance);

// Php::call("var_dump", "OK 1.3");

	// mount the function params, like showed ini https://docs.gtk.org/gtk3/callback.TreeSelectionForeachFunc.html
	callback_object->n_params = 3;
	callback_object->return_type = 0;

// Php::call("var_dump", "OK 1.4");

	// // add type of each param
	callback_object->param_types = (GType *) malloc(sizeof(GType) * callback_object->n_params);
// Php::call("var_dump", "OK 1.5");
	callback_object->param_types[0] = g_type_from_name("GtkTreeModel");
// Php::call("var_dump", "OK 1.6");
	callback_object->param_types[1] = g_type_from_name("GtkTreePath");
// Php::call("var_dump", "OK 1.7");
	callback_object->param_types[2] = g_type_from_name("GtkTreeIter");
// Php::call("var_dump", "OK 1.8");

// Php::call("var_dump", "OK 1.9");

	// GClosure  *closure;
    // closure = g_cclosure_new_swap (G_CALLBACK (generic_callback), callback_object, NULL);

	// // test
	

	gtk_tree_selection_selected_foreach(GTK_TREE_SELECTION(instance), (GtkTreeSelectionForeachFunc)generic_callback, callback_object);
	// Php::call("var_dump", "OK 1.10");
}

Php::Value GtkTreeSelection_::get_selected_rows()
{
	GtkTreeModel *model;

	GList *ret = gtk_tree_selection_get_selected_rows (GTK_TREE_SELECTION(instance), &model);

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		ret_arr[index] = gtk_tree_path_to_string((GtkTreePath*)item->data);
	}

	GtkTreeModel_* return_parsed_model = new GtkTreeModel_();
	return_parsed_model->set_model(model);

	Php::Value result;
	result[0] = Php::Object("GtkTreeModel", return_parsed_model);
	result[1] = ret_arr;

	return result;
}

Php::Value GtkTreeSelection_::count_selected_rows()
{
	gint ret = gtk_tree_selection_count_selected_rows (GTK_TREE_SELECTION(instance));

	return ret;
}

void GtkTreeSelection_::select_path(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	gtk_tree_selection_select_path (GTK_TREE_SELECTION(instance), path);

}

void GtkTreeSelection_::unselect_path(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	gtk_tree_selection_unselect_path (GTK_TREE_SELECTION(instance), path);

}

Php::Value GtkTreeSelection_::path_is_selected(Php::Parameters &parameters)
{
	std::string param_path = parameters[0];
	GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

	bool ret = gtk_tree_selection_path_is_selected (GTK_TREE_SELECTION(instance), path);

	return ret;
}

void GtkTreeSelection_::select_iter(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();
	
	gtk_tree_selection_select_iter (GTK_TREE_SELECTION(instance), &iter);

}

void GtkTreeSelection_::unselect_iter(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();

	gtk_tree_selection_unselect_iter (GTK_TREE_SELECTION(instance), &iter);

}

Php::Value GtkTreeSelection_::iter_is_selected(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();

	bool ret = gtk_tree_selection_iter_is_selected (GTK_TREE_SELECTION(instance), &iter);

	return ret;
}

void GtkTreeSelection_::select_all()
{
	gtk_tree_selection_select_all (GTK_TREE_SELECTION(instance));

}

void GtkTreeSelection_::unselect_all()
{
	gtk_tree_selection_unselect_all (GTK_TREE_SELECTION(instance));

}

void GtkTreeSelection_::unselect_range(Php::Parameters &parameters)
{
	std::string param_start_path = parameters[0];
	GtkTreePath *start_path = gtk_tree_path_new_from_string(param_start_path.c_str());

	std::string param_end_path = parameters[0];
	GtkTreePath *end_path = gtk_tree_path_new_from_string(param_end_path.c_str());

	gtk_tree_selection_unselect_range (GTK_TREE_SELECTION(instance), start_path, end_path);

}

