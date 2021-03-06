
#include "GtkListStore.h"

/**
 * Constructor
 */
GtkListStore_::GtkListStore_() = default;

/**
 * Destructor
 */
GtkListStore_::~GtkListStore_() = default;

void GtkListStore_::__construct(Php::Parameters &parameters)
{

	gint n_columns = (gint) parameters.size();

    GType *types;
    types = g_new(GType, n_columns);
    
    for(int index=0; index < (int)parameters.size(); index++) {
        int a = parameters[index];

        types[index] = (GType)a;
    }

    // Create the store
    model = GTK_TREE_MODEL(gtk_list_store_newv(n_columns, types));

}

void GtkListStore_::set_column_types(Php::Parameters &parameters)
{
	// gint n_columns = (gint)parameters[0];


	// gtk_list_store_set_column_types (GTK_LIST_STORE(model), n_columns, types);

	throw Php::Exception("GtkListStore_::set_column_types not implemented yet");

}

void GtkListStore_::set(Php::Parameters &parameters)
{
	// GtkTreeIter *iter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_iter = parameters[0];
	// 	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	// 	iter = phpgtk_iter->get_instance();
	// }


	// gtk_list_store_set (GTK_LIST_STORE(model), iter, );

	throw Php::Exception("GtkListStore_::set not implemented yet");

}

void GtkListStore_::set_valist(Php::Parameters &parameters)
{
	// GtkTreeIter *iter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_iter = parameters[0];
	// 	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	// 	iter = phpgtk_iter->get_instance();
	// }


	// gtk_list_store_set_valist (GTK_LIST_STORE(model), iter, var_args);

	throw Php::Exception("GtkListStore_::set_valist not implemented yet");

}

void GtkListStore_::set_value(Php::Parameters &parameters)
{

	GtkTreeIter iter;
    Php::Value object_iter = parameters[0];
    GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
    iter = phpgtk_iter->get_instance();

    gint column = (int)parameters[1];


    // Get column type
    GType type_column = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model), column);

    // Populate the column var with correct type
    GValue value = phpgtk_get_gvalue(parameters[2], type_column);

    // Add the value
    gtk_list_store_set_value(GTK_LIST_STORE(model), &iter, column, &value);



}

void GtkListStore_::set_valuesv(Php::Parameters &parameters)
{
	// GtkTreeIter *iter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_iter = parameters[0];
	// 	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	// 	iter = phpgtk_iter->get_instance();
	// }

	// gint columns = (gint)parameters[1];


	// gint n_values = (gint)parameters[3];

	// gtk_list_store_set_valuesv (GTK_LIST_STORE(model), iter, columns, values, n_values);

	throw Php::Exception("GtkListStore_::set_valuesv not implemented yet");

}

Php::Value GtkListStore_::remove(Php::Parameters &parameters)
{
	GtkTreeIter iter;
	if(parameters.size() > 0) {
		Php::Value object_iter = parameters[0];
		GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
		iter = phpgtk_iter->get_instance();
	}

	gboolean ret = gtk_list_store_remove (GTK_LIST_STORE(model), &iter);

	return ret;
}

Php::Value GtkListStore_::insert(Php::Parameters &parameters)
{
	GtkTreeIter iter;

	gint position = (gint)parameters[0];

	gtk_list_store_insert (GTK_LIST_STORE(model), &iter, position);

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);

}

Php::Value GtkListStore_::insert_before(Php::Parameters &parameters)
{
	GtkTreeIter iter;

	GtkTreeIter sibling;
	Php::Value object_sibling = parameters[0];
	GtkTreeIter_ *phpgtk_sibling = (GtkTreeIter_ *)object_sibling.implementation();
	sibling = phpgtk_sibling->get_instance();

	gtk_list_store_insert_before (GTK_LIST_STORE(model), &iter, &sibling);

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);

}

Php::Value GtkListStore_::insert_after(Php::Parameters &parameters)
{
	GtkTreeIter iter;

	GtkTreeIter sibling;
	Php::Value object_sibling = parameters[0];
	GtkTreeIter_ *phpgtk_sibling = (GtkTreeIter_ *)object_sibling.implementation();
	sibling = phpgtk_sibling->get_instance();

	gtk_list_store_insert_after (GTK_LIST_STORE(model), &iter, &sibling);

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);

}

void GtkListStore_::insert_with_values(Php::Parameters &parameters)
{
	// GtkTreeIter *iter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_iter = parameters[0];
	// 	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	// 	iter = phpgtk_iter->get_instance();
	// }

	// gint position = (gint)parameters[1];


	// gtk_list_store_insert_with_values (GTK_LIST_STORE(model), iter, position, );

	throw Php::Exception("GtkListStore_::set_valuesv not implemented yet");

}

void GtkListStore_::insert_with_valuesv(Php::Parameters &parameters)
{
	throw Php::Exception("GtkListStore_::insert_with_valuesv implemented yet");
}

Php::Value GtkListStore_::prepend(Php::Parameters &parameters)
{
	
	// Add new line
    GtkTreeIter localIter;
    gtk_list_store_prepend(GTK_LIST_STORE(model), &localIter);

    // Get param
    Php::Value arr = parameters[0];

    // Loop columns of param
    for(int index=0; index < (int)arr.size(); index++) {

        // Get column type
        GType type_column = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model), index);

        // Populate the column var with correct type
        GValue a = phpgtk_get_gvalue(arr[index], type_column);

        // Set the value
        gtk_list_store_set_value(GTK_LIST_STORE(model), &localIter, index, &a);
    }

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(localIter);
	return Php::Object("GtkTreeIter", return_parsed);

}

Php::Value GtkListStore_::append(Php::Parameters &parameters)
{
	// Add new line
    GtkTreeIter localIter;
    gtk_list_store_append(GTK_LIST_STORE(model), &localIter);

    // Get param
    Php::Value arr = parameters[0];

    // Loop columns of param
    for(int index=0; index < (int)arr.size(); index++) {

        // Get column type
        GType type_column = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model), index);

        // Populate the column var with correct type
        GValue a = phpgtk_get_gvalue(arr[index], type_column);

        // Set the value
        gtk_list_store_set_value(GTK_LIST_STORE(model), &localIter, index, &a);
    }

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(localIter);
	return Php::Object("GtkTreeIter", return_parsed);

}

void GtkListStore_::clear()
{
	gtk_list_store_clear (GTK_LIST_STORE(model));

}

Php::Value GtkListStore_::iter_is_valid(Php::Parameters &parameters)
{
	GtkTreeIter iter;
	if(parameters.size() > 0) {
		Php::Value object_iter = parameters[0];
		GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
		iter = phpgtk_iter->get_instance();
	}

	gboolean ret = gtk_list_store_iter_is_valid (GTK_LIST_STORE(model), &iter);

	return ret;
}

void GtkListStore_::reorder(Php::Parameters &parameters)
{
	// gint new_order = (gint)parameters[0];

	// gtk_list_store_reorder (GTK_LIST_STORE(model), new_order);

	throw Php::Exception("GtkListStore_::reorder not implemented yet");

}

void GtkListStore_::swap(Php::Parameters &parameters)
{
	GtkTreeIter a;
	if(parameters.size() > 0) {
		Php::Value object_a = parameters[0];
		GtkTreeIter_ *phpgtk_a = (GtkTreeIter_ *)object_a.implementation();
		a = phpgtk_a->get_instance();
	}

	GtkTreeIter b;
	if(parameters.size() > 1) {
		Php::Value object_b = parameters[1];
		GtkTreeIter_ *phpgtk_b = (GtkTreeIter_ *)object_b.implementation();
		b = phpgtk_b->get_instance();
	}

	gtk_list_store_swap (GTK_LIST_STORE(model), &a, &b);

}

void GtkListStore_::move_before(Php::Parameters &parameters)
{
	GtkTreeIter iter;
	if(parameters.size() > 0) {
		Php::Value object_iter = parameters[0];
		GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
		iter = phpgtk_iter->get_instance();
	}

	GtkTreeIter position;
	if(parameters.size() > 1) {
		Php::Value object_position = parameters[1];
		GtkTreeIter_ *phpgtk_position = (GtkTreeIter_ *)object_position.implementation();
		position = phpgtk_position->get_instance();
	}

	gtk_list_store_move_before (GTK_LIST_STORE(model), &iter, &position);

}

void GtkListStore_::move_after(Php::Parameters &parameters)
{
	GtkTreeIter iter;
	if(parameters.size() > 0) {
		Php::Value object_iter = parameters[0];
		GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
		iter = phpgtk_iter->get_instance();
	}

	GtkTreeIter position;
	if(parameters.size() > 1) {
		Php::Value object_position = parameters[1];
		GtkTreeIter_ *phpgtk_position = (GtkTreeIter_ *)object_position.implementation();
		position = phpgtk_position->get_instance();
	}

	gtk_list_store_move_after (GTK_LIST_STORE(model), &iter, &position);

}

