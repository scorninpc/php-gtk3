
#ifndef _PHPGTK_GTKTREEVIEW_H_
#define _PHPGTK_GTKTREEVIEW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkContainer.h"
    #include "GtkTreeViewColumn.h"
    #include "GtkTreeModel.h"
    #include "GtkTreeSelection.h"

    /**
     * GtkTreeView_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeView.html
     */
    class GtkTreeView_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            bool liststore_type;
            
            /**
             *  C++ constructor and destructor
             */
            GtkTreeView_();
            ~GtkTreeView_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Appends column to the list of columns
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeView.html#gtk-tree-view-append-column
             */
            Php::Value append_column(Php::Parameters &parameters);

            /**
             * Sets the model for a GtkTreeView
             *
             * https://developer.gnome.org/gtk3/stable/GtkTreeView.html#gtk-tree-view-set-model
             */
            void set_model(Php::Parameters &parameters);
            Php::Value get_model();

            void autosize();

            void collapse_all();
            void expand_all();
            Php::Value expand_row(Php::Parameters &parameters);

            Php::Value get_selection();

            void set_level_indentation(Php::Parameters &parameters);
            void set_show_expanders(Php::Parameters &parameters);

            void set_enable_tree_lines(Php::Parameters &parameters);
            Php::Value get_enable_tree_lines();

            Php::Value row_expanded(Php::Parameters &parameters);
            Php::Value collapse_row(Php::Parameters &parameters);

            void set_reorderable(Php::Parameters &parameters);
            Php::Value get_reorderable();

            void set_enable_search(Php::Parameters &parameters);
            Php::Value get_enable_search();

            void set_fixed_height_mode(Php::Parameters &parameters);
            Php::Value get_fixed_height_mode();
            
            Php::Value get_n_columns();

            void set_headers_visible(Php::Parameters &parameters);

            void select_all();

            void unselect_all();
            void scroll_to_cell(Php::Parameters& parameters);

            Php::Value get_columns();
            Php::Value get_column(Php::Parameters& parameters);

            void move_column_after(Php::Parameters& parameters);

            Php::Value get_path_at_pos(Php::Parameters& parameters);

            Php::Value get_bin_window();

            Php::Value get_visible_rect();


            Php::Value convert_widget_to_bin_window_coords(Php::Parameters& parameters);

            Php::Value convert_widget_to_tree_coords(Php::Parameters& parameters);

            Php::Value convert_tree_to_widget_coords(Php::Parameters& parameters);

            Php::Value convert_tree_to_bin_window_coords(Php::Parameters& parameters);

            Php::Value convert_bin_window_to_widget_coords(Php::Parameters& parameters);

            Php::Value convert_bin_window_to_tree_coords(Php::Parameters& parameters);
    };

#endif