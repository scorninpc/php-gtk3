
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
    // if (!object.instanceOf("GtkCellRenderer")) throw Php::Exception("parameter expect GtkCellRenderer instance");
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
    // if (!object.instanceOf("GtkCellRenderer")) throw Php::Exception("parameter expect GtkCellRenderer instance");
    GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();


    gtk_tree_view_column_pack_start(GTK_TREE_VIEW_COLUMN(instance), GTK_CELL_RENDERER(passedRenderer->get_instance()), parameters[1]);
}

/**
 * Packs the cell into the end of the column.
 */
void GtkTreeViewColumn_::pack_end(Php::Parameters &parameters)
{
    // Get the renderer
    Php::Value object = parameters[0];
    // if (!object.instanceOf("GtkCellRenderer")) throw Php::Exception("parameter expect GtkCellRenderer instance");
    GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();


    gtk_tree_view_column_pack_end(GTK_TREE_VIEW_COLUMN(instance), GTK_CELL_RENDERER(passedRenderer->get_instance()), parameters[1]);
}

/**
 * If resizable is TRUE, then the user can explicitly resize the column by grabbing the outer edge of the column button.
 */
void GtkTreeViewColumn_::set_resizable(Php::Parameters &parameters)
{
    gtk_tree_view_column_set_resizable(GTK_TREE_VIEW_COLUMN(instance), parameters[0]);
}

/**
 * Returns TRUE if the tree_column can be resized by the end user.
 */
Php::Value GtkTreeViewColumn_::get_resizable()
{
    // 
    return gtk_tree_view_column_get_resizable(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * Returns the current size of tree_column in pixels.
 */
Php::Value GtkTreeViewColumn_::get_width()
{
    // 
    return gtk_tree_view_column_get_width(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * Gets the fixed width of the column.
 */
Php::Value GtkTreeViewColumn_::get_fixed_width()
{
    // 
    return gtk_tree_view_column_get_fixed_width(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * If fixed_width is not -1, sets the fixed width of tree_column ; otherwise unsets it.
 */
void GtkTreeViewColumn_::set_fixed_width(Php::Parameters &parameters)
{
    gtk_tree_view_column_set_fixed_width(GTK_TREE_VIEW_COLUMN(instance), parameters[0]);
}

/**
 * Returns the button used in the treeview column header
 *
 * @todo need to test
 */
Php::Value GtkTreeViewColumn_::get_button()
{
    // Create the gtk button
    GtkWidget *widget = gtk_tree_view_column_get_button(GTK_TREE_VIEW_COLUMN(instance));
    
    // Create the PHP-GTK object and set GTK object
    GtkButton_ *widget_ = new GtkButton_();
    widget_->set_instance((gpointer *)widget);

    // Return PHP-GTK object
    return Php::Object("GtkButton", widget_);
}

/**
 * Sets the alignment of the title or custom widget inside the column header.
 */
void GtkTreeViewColumn_::set_alignment(Php::Parameters &parameters)
{
    double xalign = parameters[0];
    gtk_tree_view_column_set_alignment(GTK_TREE_VIEW_COLUMN(instance), xalign);
}

/**
 * Returns the current x alignment of tree_column . This value can range between 0.0 and 1.0.
 */
Php::Value GtkTreeViewColumn_::get_alignment()
{
    return gtk_tree_view_column_get_alignment(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * If reorderable is TRUE, then the column can be reordered by the end user dragging the header.
 */
void GtkTreeViewColumn_::set_reorderable(Php::Parameters &parameters)
{
    gtk_tree_view_column_set_reorderable(GTK_TREE_VIEW_COLUMN(instance), parameters[0]);
}

/**
 * Returns TRUE if the tree_column can be reordered by the user.
 */
Php::Value GtkTreeViewColumn_::get_reorderable()
{
    return gtk_tree_view_column_get_reorderable(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * Returns the GtkWidget in the button on the column header. If a custom widget has not been set then NULL is returned.
 *
 * @todo need to test
 */
Php::Value GtkTreeViewColumn_::get_widget()
{
    // Create the gtk button
    GtkWidget *widget = gtk_tree_view_column_get_widget(GTK_TREE_VIEW_COLUMN(instance));
    
    // Create the PHP-GTK object and set GTK object
    GtkWidget_ *widget_ = new GtkWidget_();
    widget_->set_instance((gpointer *)widget);

    // Return PHP-GTK object
    return Php::Object("GtkWidget", widget_);
}

/**
 * Sets the widget in the header to be widget 
 *
 * @todo need to test
 */
void GtkTreeViewColumn_::set_widget(Php::Parameters &parameters)
{
    // Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    // Pack the widget
    gtk_tree_view_column_set_widget(GTK_TREE_VIEW_COLUMN(instance), GTK_WIDGET(passedWidget->get_instance()));
}

/**
 * Sets the logical sort_column_id that this column sorts on when this column is selected for sorting. Doing so makes the column header clickable.
 */
void GtkTreeViewColumn_::set_sort_column_id(Php::Parameters &parameters)
{
    gtk_tree_view_column_set_sort_column_id(GTK_TREE_VIEW_COLUMN(instance), parameters[0]);
}

/**
 * Gets the logical sort_column_id that the model sorts on when this column is selected for sorting.
 */
Php::Value GtkTreeViewColumn_::get_sort_column_id()
{
    // 
    return gtk_tree_view_column_get_sort_column_id(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * Call this function with a setting of TRUE to display an arrow in the header button indicating the column is sorted. 
 */
void GtkTreeViewColumn_::set_sort_indicator(Php::Parameters &parameters)
{
    gtk_tree_view_column_set_sort_indicator(GTK_TREE_VIEW_COLUMN(instance), (bool)parameters[0]);
}

/**
 * Gets the value set by gtk_tree_view_column_set_sort_indicator().
 */
Php::Value GtkTreeViewColumn_::get_sort_indicator()
{
    // 
    return gtk_tree_view_column_get_sort_indicator(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * Changes the appearance of the sort indicator.
 */
void GtkTreeViewColumn_::set_sort_order(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GtkSortType passedCasted = (GtkSortType)a;

    gtk_tree_view_column_set_sort_order(GTK_TREE_VIEW_COLUMN(instance), passedCasted);
}

/**
 * Gets the value set by gtk_tree_view_column_set_sort_order().
 */
Php::Value GtkTreeViewColumn_::get_sort_order()
{
    // 
    return gtk_tree_view_column_get_sort_order(GTK_TREE_VIEW_COLUMN(instance));
}

/**
 * Returns the GtkTreeView wherein tree_column has been inserted. 
 */
Php::Value GtkTreeViewColumn_::get_tree_view()
{
    // Create the gtk button
    GtkWidget *widget = gtk_tree_view_column_get_tree_view(GTK_TREE_VIEW_COLUMN(instance));
    
    // Create the PHP-GTK object and set GTK object
    GtkTreeView_ *widget_ = new GtkTreeView_();
    widget_->set_instance((gpointer *)widget);

    // Return PHP-GTK object
    return Php::Object("GtkTreeView", widget_);
}