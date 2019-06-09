
#ifndef _PHPGTK_GTKFLOWBOX_H_
#define _PHPGTK_GTKFLOWBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkFlowBoxChild.h"
	#include "GtkWidget.h"
	#include "GtkAdjustment.h"

    /**
     * GtkFlowBox_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFlowBox.html
     */
    class GtkFlowBox_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFlowBox_();
            ~GtkFlowBox_();

            void __construct();

            void insert(Php::Parameters &parameters);

            Php::Value get_child_at_index(Php::Parameters &parameters);

            void set_hadjustment(Php::Parameters &parameters);

            void set_vadjustment(Php::Parameters &parameters);

            void set_homogeneous(Php::Parameters &parameters);

            Php::Value get_homogeneous();

            void set_row_spacing(Php::Parameters &parameters);

            Php::Value get_row_spacing();

            void set_column_spacing(Php::Parameters &parameters);

            Php::Value get_column_spacing();

            void set_min_children_per_line(Php::Parameters &parameters);

            Php::Value get_min_children_per_line();

            void set_max_children_per_line(Php::Parameters &parameters);

            Php::Value get_max_children_per_line();

            void set_activate_on_single_click(Php::Parameters &parameters);

            Php::Value get_activate_on_single_click();

            void selected_foreach(Php::Parameters &parameters);

            Php::Value get_selected_children();

            void select_child(Php::Parameters &parameters);

            void unselect_child(Php::Parameters &parameters);

            void select_all();

            void unselect_all();

            void set_selection_mode(Php::Parameters &parameters);

            Php::Value get_selection_mode();

            void set_filter_func(Php::Parameters &parameters);

            void invalidate_filter();

            void set_sort_func(Php::Parameters &parameters);

            void invalidate_sort();

            void bind_model(Php::Parameters &parameters);
    };

#endif
