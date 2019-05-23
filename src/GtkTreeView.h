
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

            Php::Value get_selection();
    };

#endif