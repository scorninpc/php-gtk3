
#ifndef _PHPGTK_GTKTREEVIEWCOLUMN_H_
#define _PHPGTK_GTKTREEVIEWCOLUMN_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkCellRenderer.h"

    /**
     * GtkTreeViewColumn_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeViewColumn.html
     */
    class GtkTreeViewColumn_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GtkTreeViewColumn *column;

            /**
             * Return original GtkTreeViewColumn
             */
            GtkTreeViewColumn *get_column();

            /**
             * Set the original GtkTreeViewColumn
             */
            void set_column(GtkTreeViewColumn *pased_column);


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
    };

#endif