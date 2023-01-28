
#ifndef _PHPGTK_GTKTREEVIEWCOLUMN_H_
#define _PHPGTK_GTKTREEVIEWCOLUMN_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkCellRenderer.h"
    #include "../G/GObject.h"
    #include "GtkWidget.h"
    #include "GtkButton.h"
    #include "GtkTreeView.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkTreeViewColumn_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html
     */
    class GtkTreeViewColumn_ : public GObject_
    {
        private:
            struct st_request_callback;
        
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTreeViewColumn_();
            ~GtkTreeViewColumn_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Sets the title of the tree_column
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-title
             */
            void set_title(Php::Parameters &parameters);

            /**
             * Gets the title of the tree_column
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-title
             */
            Php::Value get_title();

            /**
             * Packs the cell into the beginning of the column.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-pack-start
             */
            void pack_start(Php::Parameters &parameters);

            /**
             * Adds the cell to end of the column
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-pack-end
             */
            void pack_end(Php::Parameters &parameters);

            /**
             * If resizable is TRUE, then the user can explicitly resize the column by grabbing the outer edge of the column button.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-resizable
             */
            void set_resizable(Php::Parameters &parameters);

            /**
             * Returns TRUE if the tree_column can be resized by the end user.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-resizable
             */
            Php::Value get_resizable();

            /**
             * Returns the current size of tree_column in pixels.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-width
             */
            Php::Value get_width();

            /**
             * Gets the fixed width of the column.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-fixed-width
             */
            Php::Value get_fixed_width();

            /**
             * If fixed_width is not -1, sets the fixed width of tree_column ; otherwise unsets it.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-fixed-width
             */
            void set_fixed_width(Php::Parameters &parameters);

            /**
             * Returns the button used in the treeview column header
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-button
             */
            Php::Value get_button();

            /**
             * Sets the alignment of the title or custom widget inside the column header.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-alignment
             */
            void set_alignment(Php::Parameters &parameters);

            /**
             * Returns the current x alignment of tree_column . This value can range between 0.0 and 1.0.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-alignment
             */
            Php::Value get_alignment();

            /**
             * If reorderable is TRUE, then the column can be reordered by the end user dragging the header.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-reorderable
             */
            void set_reorderable(Php::Parameters &parameters);

            /**
             * Returns TRUE if the tree_column can be reordered by the user.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-reorderable
             */
            Php::Value get_reorderable();

            /**
             * Returns the GtkWidget in the button on the column header. If a custom widget has not been set then NULL is returned.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-widget
             */
            Php::Value get_widget();

            /**
             * Sets the widget in the header to be widget 
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-widget
             */
            void set_widget(Php::Parameters &parameters);

            /**
             * Sets the logical sort_column_id that this column sorts on when this column is selected for sorting. Doing so makes the column header clickable.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-sort-column-id
             */
            void set_sort_column_id(Php::Parameters &parameters);

            /**
             * Gets the logical sort_column_id that the model sorts on when this column is selected for sorting.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-sort-column-id
             */
            Php::Value get_sort_column_id();

            /**
             * Call this function with a setting of TRUE to display an arrow in the header button indicating the column is sorted. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-sort-indicator
             */
            void set_sort_indicator(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_tree_view_column_set_sort_indicator().
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-sort-indicator
             */
            Php::Value get_sort_indicator();

            /**
             * Changes the appearance of the sort indicator.
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-set-sort-order
             */
            void set_sort_order(Php::Parameters &parameters);

            /**
             * Gets the value set by gtk_tree_view_column_set_sort_order().
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-sort-order
             */
            Php::Value get_sort_order();

            /**
             * Returns the GtkTreeView wherein tree_column has been inserted. 
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html#gtk-tree-view-column-get-tree-view
             */
            Php::Value get_tree_view();

            void set_max_width(Php::Parameters &parameters);

            void set_cell_data_func(Php::Parameters &parameters);
            static void set_cell_data_func_callback(GtkTreeViewColumn* tree_column, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer user_data);
    };

#endif