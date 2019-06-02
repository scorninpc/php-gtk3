
#ifndef _PHPGTK_GTKLISTBOX_H_
#define _PHPGTK_GTKLISTBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"
	#include "GtkSelectionMode.h"
	#include "GtkAdjustment.h"
    #include "GtkListBoxRow.h"
    #include "GtkLabel.h"

    /**
     * GtkListBox_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkListBox.html
     */
    class GtkListBox_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkListBox_();
            ~GtkListBox_();

            void __construct();

            void prepend(Php::Parameters &parameters);

            void insert(Php::Parameters &parameters);

            void select_row(Php::Parameters &parameters);

            void unselect_row(Php::Parameters &parameters);

            void select_all();

            void unselect_all();

            Php::Value get_selected_row();

            void selected_foreach(Php::Parameters &parameters);

            Php::Value get_selected_rows();

            void set_selection_mode(Php::Parameters &parameters);

            Php::Value get_selection_mode();

            void set_activate_on_single_click(Php::Parameters &parameters);

            Php::Value get_activate_on_single_click();

            Php::Value get_adjustment();

            void set_adjustment(Php::Parameters &parameters);

            void set_placeholder(Php::Parameters &parameters);

            Php::Value get_row_at_index(Php::Parameters &parameters);

            Php::Value get_row_at_y(Php::Parameters &parameters);

            void invalidate_filter();

            void invalidate_headers();

            void invalidate_sort();

            void set_filter_func(Php::Parameters &parameters);

            void set_header_func(Php::Parameters &parameters);

            void set_sort_func(Php::Parameters &parameters);

            void drag_highlight_row(Php::Parameters &parameters);

            void drag_unhighlight_row();

            void bind_model(Php::Parameters &parameters);
    };

#endif
