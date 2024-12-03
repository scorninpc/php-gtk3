
#ifndef _PHPGTK_GTKTREESELECTION_H_
#define _PHPGTK_GTKTREESELECTION_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
	#include "GtkTreeView.h"
	#include "GtkTreeIter.h"
	#include "GtkTreeModel.h"

    /**
     * GtkTreeSelection_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeSelection.html
     */
    class GtkTreeSelection_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTreeSelection_();
            ~GtkTreeSelection_();

            void set_mode(Php::Parameters &parameters);

            Php::Value get_mode();

            void set_select_function(Php::Parameters &parameters);

            void get_select_function(Php::Parameters &parameters);

            Php::Value get_user_data(Php::Parameters &parameters);

            Php::Value get_tree_view();

            Php::Value get_selected(Php::Parameters &parameters);

            void selected_foreach(Php::Parameters &parameters);

            Php::Value get_selected_rows();

            Php::Value count_selected_rows();

            void select_path(Php::Parameters &parameters);

            void unselect_path(Php::Parameters &parameters);

            Php::Value path_is_selected(Php::Parameters &parameters);

            void select_iter(Php::Parameters &parameters);

            void unselect_iter(Php::Parameters &parameters);

            Php::Value iter_is_selected(Php::Parameters &parameters);

            void select_all();

            void unselect_all();

            void unselect_range(Php::Parameters &parameters);

            void select_range(Php::Parameters& parameters);
    };

#endif
