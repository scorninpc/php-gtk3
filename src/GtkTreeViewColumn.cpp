
#include "GtkTreeViewColumn.h"

/**
 * Return original GtkTreeViewColumn
 */
GtkTreeViewColumn *GtkTreeViewColumn_::get_column()
{
    return column;
}

/**
 * Set the original GtkTreeViewColumn
 */
void GtkTreeViewColumn_::set_column(GtkTreeViewColumn *column)
{
    column = column;
}

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

    column =  gtk_tree_view_column_new_with_attributes(title.c_str(), passedRenderer->get_renderer(), t_column.c_str(), n_column, NULL);
}

/**
 * Sets the title of the tree_column
 */
void GtkTreeViewColumn_::set_title(Php::Parameters &parameters)
{
    std::string title = parameters[0];

    gtk_tree_view_column_set_title(column, title.c_str());
}

/**
 * Gets the title of the tree_column
 */
Php::Value GtkTreeViewColumn_::get_title()
{
    // 
    return gtk_tree_view_column_get_title(column);
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


    gtk_tree_view_column_pack_start(column, passedRenderer->get_renderer(), parameters[1]);
}