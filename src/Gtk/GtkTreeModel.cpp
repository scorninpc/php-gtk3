
#include "GtkTreeModel.h"

/**
 * Constructor
 */
GtkTreeModel_::GtkTreeModel_() = default;

/**
 * Destructor
 */
GtkTreeModel_::~GtkTreeModel_() = default;

/**
 * Return original GtkTreeModel
 */
GtkTreeModel *GtkTreeModel_::get_model()
{
    return model;
}

/**
 * Set the original GtkTreeModel
 */
void GtkTreeModel_::set_model(GtkTreeModel *passed_model)
{
    model = passed_model;
}

/**
 *  PHP Constructor
 */
void GtkTreeModel_::__construct(Php::Parameters &parameters)
{
    
}

Php::Value GtkTreeModel_::get_iter(Php::Parameters &parameters)
{

    std::string param_path = parameters[0];
    gchar* data = (gchar*)param_path.c_str();

    gssize length = param_path.length();

    if (length == 0) {
        return false;
    }

    GtkTreeIter iter;
    GtkTreePath *path = gtk_tree_path_new_from_string(param_path.c_str());

    bool ret = gtk_tree_model_get_iter(GTK_TREE_MODEL(model), &iter, path);
    if(!ret) {
        return false;
    }

    GtkTreeIter_ *return_parsed = new GtkTreeIter_();
    return_parsed->set_instance(iter);
    return Php::Object("GtkTreeIter", return_parsed);
}


Php::Value GtkTreeModel_::get_value(Php::Parameters &parameters)
{
    // Cast iter back
    Php::Value object_iter = parameters[0];

    if (object_iter == false) {
        return false;
    }

    GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
    GtkTreeIter iter = phpgtk_iter->get_instance();

    // Column
    gint column = (int)parameters[1];

    // Value
    GValue value = {0};

    // Retrieve
    gtk_tree_model_get_value(GTK_TREE_MODEL(model), &iter, column, &value);

    // Verify the type
    switch (G_VALUE_TYPE(&value)) {
        case G_TYPE_INT:{
            return g_value_get_int(&value);
        }
        case G_TYPE_BOOLEAN:
        {
            return g_value_get_boolean(&value);
        }
        case G_TYPE_DOUBLE:
        {
            return g_value_get_double(&value);
        }
        case G_TYPE_LONG:
        {
            return (int64_t) g_value_get_long(&value);
        }
        case G_TYPE_ULONG:
        {
            return (int64_t)g_value_get_int64(&value);
        }
        case G_TYPE_FLOAT:
        {
            return g_value_get_float(&value);
        }
        case G_TYPE_STRING:
        {
            const gchar* cstr = g_value_get_string(&value);
            if (cstr != nullptr) {
                std::string ret = std::string(cstr);
                return ret;
            } else {
                return Php::Value(nullptr);
            }
        }
        case G_TYPE_OBJECT:
        {
            GObject* object = G_OBJECT(g_value_get_object(&value));
            // Check if the object is NULL
            if (!object) {
                return Php::Value(nullptr);
            }

            // Proceed with non-NULL object
            std::string gtype_name = g_type_name(G_TYPE_FROM_INSTANCE(object));

            // Return PHPGTK Object
            GObject_* phpgtk_widget = new GObject_();
            phpgtk_widget->set_instance((gpointer*)object);
            return Php::Object(gtype_name.c_str(), phpgtk_widget);
        }
    }

    return false;
}

Php::Value GtkTreeModel_::get_path(Php::Parameters &parameters)
{
    // Cast iter back
    Php::Value object_iter = parameters[0];
    GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
    GtkTreeIter iter = phpgtk_iter->get_instance();

    GtkTreePath *path = gtk_tree_model_get_path(GTK_TREE_MODEL(model), &iter);

    return gtk_tree_path_to_string(path);
}

Php::Value GtkTreeModel_::get_iter_from_string(Php::Parameters &parameters)
{
    std::string param_path = parameters[0];
    
    // 
    GtkTreeIter iter;

    bool ret = gtk_tree_model_get_iter_from_string(GTK_TREE_MODEL(model), &iter, (gchar *)param_path.c_str());

    if(!ret) {
        return ret;
    }
    else {
        GtkTreeIter_ *return_parsed = new GtkTreeIter_();
        return_parsed->set_instance(iter);
        return Php::Object("GtkTreeIter", return_parsed);
    }
}

