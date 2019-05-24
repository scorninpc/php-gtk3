
#include "GtkListStore.h"

/**
 * Constructor
 */
GtkListStore_::GtkListStore_() = default;

/**
 * Destructor
 */
GtkListStore_::~GtkListStore_() = default;

/**
 *  PHP Constructor
 */
void GtkListStore_::__construct(Php::Parameters &parameters)
{
    // Verify if has window type parameter
    // int int_window_type = 0;
    // if(parameters.size() >= 1) {
    //     int_window_type = parameters[0];
    // }

    gint n_columns = (gint) parameters.size();

    GType *types;
    types = g_new(GType, n_columns);
    
    for(int index=0; index < (int)parameters.size(); index++) {
        int a = parameters[index];

        types[index] = (GType)a;
    }

    // Create the store
    model = GTK_TREE_MODEL(gtk_list_store_newv(5, types));
}

/**
 * Sets the data in the cell specified by iter and column . The type of value must be convertible to the type of the column.
 */
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

/**
 * Appends a new row to list_store
 */
void GtkListStore_::append(Php::Parameters &parameters)
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
}