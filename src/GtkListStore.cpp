
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
    model = GTK_TREE_MODEL(gtk_list_store_newv(n_columns, types));
}

/**
 * Sets the data in the cell specified by iter and column . The type of value must be convertible to the type of the column.
 */
void GtkListStore_::set_value(Php::Parameters &parameters)
{
    

    

    //gtk_list_store_set(GTK_LIST_STORE(store), a, parameters[1], parameters[2], -1);
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



    // GValue a = {0};
    // g_value_init(&a, G_TYPE_INT);
    // g_value_set_int(&a, 42);
    // gtk_list_store_set_value(GTK_LIST_STORE(model), &localIter, 0, &a);

    // GValue b = {0};
    // g_value_init(&b, G_TYPE_STRING);
    // g_value_set_string(&b, "OK");
    // gtk_list_store_set_value(GTK_LIST_STORE(model), &localIter, 1, &b);

    // Loop columns of param
    for(int index=0; index < (int)arr.size(); index++) {

        // Get column type
        GType type_column = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model), index);

        // Populate the column var with correct type
        GValue a = {0};
        if(type_column == G_TYPE_STRING) {
            // Cast
            std::string b = arr[index];

            g_value_init(&a, G_TYPE_STRING);
            g_value_set_string(&a, b.c_str());

        }
        else if(type_column == G_TYPE_INT) {
            // Cast
            int b = (int)arr[index];

            g_value_init(&a, G_TYPE_INT);
            g_value_set_int(&a, b);

        }
        else if(type_column == G_TYPE_BOOLEAN) {
            // Cast
            bool b = (bool)arr[index];

            g_value_init(&a, G_TYPE_BOOLEAN);
            g_value_set_boolean(&a, b);

        }

        // Set the value
        // gtk_list_store_set(GTK_LIST_STORE(model), &localIter, index, &a, -1);
        gtk_list_store_set_value(GTK_LIST_STORE(model), &localIter, index, &a);
    }
}