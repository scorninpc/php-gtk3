
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
    widget = gtk_tree_view_new();

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
    return gtk_tree_view_append_column(GTK_TREE_VIEW(widget), passedColumn->get_column());
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

    // 
    gtk_tree_view_set_model(GTK_TREE_VIEW(widget), passedModel->get_model());
}