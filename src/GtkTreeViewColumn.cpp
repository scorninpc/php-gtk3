
#include "GtkTreeViewColumn.h"

/**
 * Constructor
 */
GtkTreeViewColumn_::GtkTreeViewColumn_() = default;

/**
 * Destructor
 */
GtkTreeViewColumn_::~GtkTreeViewColumn_() = default;

/**
 *  PHP Constructor
 */
void GtkTreeViewColumn_::__construct(Php::Parameters &parameters)
{
    std::string title = parameters[0];

    // Get the renderer
    Php::Value object = parameters[1];
    if (!object.instanceOf("GtkCellRenderer")) throw Php::Exception("parameter expect GtkCellRenderer instance");
    GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();

    // Get type and column
    std::string t_column = parameters[2];
    int n_column = parameters[3];

    instance = (gpointer *)gtk_tree_view_column_new_with_attributes(title.c_str(), GTK_CELL_RENDERER(passedRenderer->get_instance()), t_column.c_str(), n_column, NULL);
}

/**
 * Sets the title of the tree_column
 */
void GtkTreeViewColumn_::set_title(Php::Parameters &parameters)
{
    std::string title = parameters[0];

    gtk_tree_view_column_set_title(GTK_TREE_VIEW_COLUMN(instance), title.c_str());
}

/**
 * Gets the title of the tree_column
 */
Php::Value GtkTreeViewColumn_::get_title()
{
    // 
    return gtk_tree_view_column_get_title(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * Packs the cell into the beginning of the column.
 */
void GtkTreeViewColumn_::pack_start(Php::Parameters &parameters)
{
    // Get the renderer
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkCellRenderer")) throw Php::Exception("parameter expect GtkCellRenderer instance");
    GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();


    gtk_tree_view_column_pack_start(GTK_TREE_VIEW_COLUMN(instance), GTK_CELL_RENDERER(passedRenderer->get_instance()), parameters[1]);
}