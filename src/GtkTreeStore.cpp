
#include "GtkTreeStore.h"

/**
 * Constructor
 */
GtkTreeStore_::GtkTreeStore_() = default;

/**
 * Destructor
 */
GtkTreeStore_::~GtkTreeStore_() = default;

void GtkTreeStore_::__construct(Php::Parameters &parameters)
{
	
	gint n_columns = (gint) parameters.size();

    GType *types;
    types = g_new(GType, n_columns);
    
    for(int index=0; index < (int)parameters.size(); index++) {
        int a = parameters[index];

        types[index] = (GType)a;
    }

    // Create the store
    model = GTK_TREE_MODEL(gtk_tree_store_newv(n_columns, types));

}

void GtkTreeStore_::set_column_types(Php::Parameters &parameters)
{
	// gint n_columns = (gint)parameters[0];


	// gtk_tree_store_set_column_types (GTK_TREE_STORE(model), n_columns, types);

	throw Php::Exception("GtkTreeStore->set_column_types() not implemented yet");

}

void GtkTreeStore_::set_value(Php::Parameters &parameters)
{
	GtkTreeIter iter;
    Php::Value object_iter = parameters[0];
    GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
    iter = phpgtk_iter->get_instance();

    gint column = (int)parameters[1];


    // Get column type
    GType type_column = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model), column);

    // Populate the column var with correct type
    GValue value = {0};
    switch(type_column) {
        case G_TYPE_INT:{
             // Cast
            int b = (int)parameters[2];

            g_value_init(&value, G_TYPE_INT);
            g_value_set_int(&value, b);

            break;
        }
        case G_TYPE_BOOLEAN:
        {
            // Cast
            bool b = (bool)parameters[2];

            g_value_init(&value, G_TYPE_BOOLEAN);
            g_value_set_boolean(&value, b);

            break;
        }
        case G_TYPE_DOUBLE:
        {
            // Cast
            double b = (double)parameters[2];

            g_value_init(&value, G_TYPE_DOUBLE);
            g_value_set_double(&value, b);

            break;
        }
        case G_TYPE_FLOAT:
        {
            // Cast
            double b = (double)parameters[2];

            g_value_init(&value, G_TYPE_FLOAT);
            g_value_set_float(&value, b);

            break;
        }
        case G_TYPE_STRING:
        {
            // Cast
            std::string b = parameters[2];

            g_value_init(&value, G_TYPE_STRING);
            g_value_set_string(&value, b.c_str());

            break;
        }
    }

    gtk_tree_store_set_value(GTK_TREE_STORE(model), &iter, column, &value);

}

Php::Value GtkTreeStore_::remove(Php::Parameters &parameters)
{
	GtkTreeIter iter;
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	iter = phpgtk_iter->get_instance();

	gboolean ret = gtk_tree_store_remove (GTK_TREE_STORE(model), &iter);

	return ret;
}

Php::Value GtkTreeStore_::insert(Php::Parameters &parameters)
{
	GtkTreeIter iter;

	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter parent = phpgtk_iter->get_instance();

	gint position = (gint)parameters[1];

	gtk_tree_store_insert (GTK_TREE_STORE(model), &iter, &parent, position);
	
	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);
}

Php::Value GtkTreeStore_::insert_before(Php::Parameters &parameters)
{
	GtkTreeIter iter;

	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter parent = phpgtk_iter->get_instance();

	Php::Value object_sibling = parameters[0];
	GtkTreeIter_ *phpgtk_sibling = (GtkTreeIter_ *)object_sibling.implementation();
	GtkTreeIter sibling = phpgtk_sibling->get_instance();


	gtk_tree_store_insert_before (GTK_TREE_STORE(model), &iter, &parent, &sibling);
	
	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);
}

Php::Value GtkTreeStore_::insert_after(Php::Parameters &parameters)
{
	GtkTreeIter iter;

	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter parent = phpgtk_iter->get_instance();

	Php::Value object_sibling = parameters[0];
	GtkTreeIter_ *phpgtk_sibling = (GtkTreeIter_ *)object_sibling.implementation();
	GtkTreeIter sibling = phpgtk_sibling->get_instance();

	gtk_tree_store_insert_after (GTK_TREE_STORE(model), &iter, &parent, &sibling);
	
	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);
}

Php::Value GtkTreeStore_::insert_with_values(Php::Parameters &parameters)
{
	// GtkTreeIter iter;

	// Php::Value object_iter = parameters[0];
	// GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	// GtkTreeIter parent = phpgtk_iter->get_instance();

	// gint position = (gint)parameters[1];

	// gboolean ret = gtk_tree_store_insert_with_valuesv (GTK_TREE_STORE(model), &iter, &parent, position, columns, values, g_values);
	// if(!ret) {
	// 	return false;
	// }

	// GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	// return_parsed->set_instance(iter);
	// return Php::Object("GtkTreeIter", return_parsed);
	throw Php::Exception("GtkTreeStore->insert_with_values() not implemented yet");
}

Php::Value GtkTreeStore_::prepend(Php::Parameters &parameters)
{
	GtkTreeIter iter;

	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter parent = phpgtk_iter->get_instance();

	gtk_tree_store_prepend (GTK_TREE_STORE(model), &iter, &parent);
	
	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);
}

Php::Value GtkTreeStore_::append(Php::Parameters &parameters)
{
	GtkTreeIter localIter;

	GtkTreeIter parent;
	if(parameters[0]) {
		Php::Value object_parent = parameters[0];
		GtkTreeIter_ *phpgtk_parent = (GtkTreeIter_ *)object_parent.implementation();
		parent = phpgtk_parent->get_instance();
		gtk_tree_store_append (GTK_TREE_STORE(model), &localIter, &parent);
	}
	else {
		gtk_tree_store_append (GTK_TREE_STORE(model), &localIter, NULL);
	}

	// Get param
    Php::Value arr = parameters[1];

    // Loop columns of param
    for(int index=0; index < (int)arr.size(); index++) {

        // Get column type
        GType type_column = gtk_tree_model_get_column_type(GTK_TREE_MODEL(model), index);

        // Populate the column var with correct type
        GValue a = {0};
        switch(type_column) {
            case G_TYPE_INT:{
                 // Cast
                int b = (int)arr[index];

                g_value_init(&a, G_TYPE_INT);
                g_value_set_int(&a, b);

                break;
            }
            case G_TYPE_BOOLEAN:
            {
                // Cast
                bool b = (bool)arr[index];

                g_value_init(&a, G_TYPE_BOOLEAN);
                g_value_set_boolean(&a, b);

                break;
            }
            case G_TYPE_DOUBLE:
            {
                // Cast
                double b = (double)arr[index];

                g_value_init(&a, G_TYPE_DOUBLE);
                g_value_set_double(&a, b);

                break;
            }
            case G_TYPE_FLOAT:
            {
                // Cast
                double b = (double)arr[index];

                g_value_init(&a, G_TYPE_FLOAT);
                g_value_set_float(&a, b);

                break;
            }
            case G_TYPE_STRING:
            {
                // Cast
                std::string b = arr[index];

                g_value_init(&a, G_TYPE_STRING);
                g_value_set_string(&a, b.c_str());

                Php::call("var_dump", b.c_str());

                break;
            }
        }

        // Set the value
        gtk_tree_store_set_value(GTK_TREE_STORE(model), &localIter, index, &a);
    }


	
	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(localIter);
	return Php::Object("GtkTreeIter", return_parsed);
}

Php::Value GtkTreeStore_::is_ancestor(Php::Parameters &parameters)
{
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();

	Php::Value object_descendant = parameters[0];
	GtkTreeIter_ *phpgtk_descendant = (GtkTreeIter_ *)object_descendant.implementation();
	GtkTreeIter descendant = phpgtk_descendant->get_instance();
	

	gboolean ret = gtk_tree_store_is_ancestor (GTK_TREE_STORE(model), &iter, &descendant);

	return ret;
}

Php::Value GtkTreeStore_::iter_depth(Php::Parameters &parameters)
{
	
		Php::Value object_iter = parameters[0];
		GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
		GtkTreeIter iter = phpgtk_iter->get_instance();

	gint ret = gtk_tree_store_iter_depth (GTK_TREE_STORE(model), &iter);

	return ret;
}

void GtkTreeStore_::clear()
{
	gtk_tree_store_clear (GTK_TREE_STORE(model));

}

void GtkTreeStore_::reorder(Php::Parameters &parameters)
{
	// GtkTreeIter parent;
	// Php::Value object_iter = parameters[0];
	// GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();

	// gint new_order = (gint)parameters[1];

	// gtk_tree_store_reorder (GTK_TREE_STORE(model), &parent, new_order);

	throw Php::Exception("GtkTreeStore->reorder() not implemented yet");
}

void GtkTreeStore_::swap(Php::Parameters &parameters)
{
	
	Php::Value object_a = parameters[0];
	GtkTreeIter_ *phpgtk_a = (GtkTreeIter_ *)object_a.implementation();
	GtkTreeIter a = phpgtk_a->get_instance();

	
	Php::Value object_b = parameters[1];
	GtkTreeIter_ *phpgtk_b = (GtkTreeIter_ *)object_b.implementation();
	GtkTreeIter b = phpgtk_b->get_instance();

	gtk_tree_store_swap (GTK_TREE_STORE(model), &a, &b);

}

void GtkTreeStore_::move_before(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();

	
	Php::Value object_position = parameters[1];
	GtkTreeIter_ *phpgtk_position = (GtkTreeIter_ *)object_position.implementation();
	GtkTreeIter position = phpgtk_position->get_instance();

	gtk_tree_store_move_before (GTK_TREE_STORE(model), &iter, &position);

}

void GtkTreeStore_::move_after(Php::Parameters &parameters)
{
	
	Php::Value object_iter = parameters[0];
	GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
	GtkTreeIter iter = phpgtk_iter->get_instance();

	
	Php::Value object_position = parameters[1];
	GtkTreeIter_ *phpgtk_position = (GtkTreeIter_ *)object_position.implementation();
	GtkTreeIter position = phpgtk_position->get_instance();

	gtk_tree_store_move_after (GTK_TREE_STORE(model), &iter, &position);

}

