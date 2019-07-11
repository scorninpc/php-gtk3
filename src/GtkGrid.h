
#ifndef _PHPGTK_GTKGRID_H_
#define _PHPGTK_GTKGRID_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkWidget.h"

    /**
     * GtkGrid_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkGrid.html
     */
    class GtkGrid_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkGrid_();
            ~GtkGrid_();

            void __construct();

            void attach(Php::Parameters &parameters);

            void attach_next_to(Php::Parameters &parameters);

            Php::Value get_child_at(Php::Parameters &parameters);

            void insert_row(Php::Parameters &parameters);

            void insert_column(Php::Parameters &parameters);

            void remove_row(Php::Parameters &parameters);

            void remove_column(Php::Parameters &parameters);

            void insert_next_to(Php::Parameters &parameters);

            void set_row_homogeneous(Php::Parameters &parameters);

            Php::Value get_row_homogeneous();

            void set_row_spacing(Php::Parameters &parameters);

            Php::Value get_row_spacing();

            void set_column_homogeneous(Php::Parameters &parameters);

            Php::Value get_column_homogeneous();

            void set_column_spacing(Php::Parameters &parameters);

            Php::Value get_column_spacing();

            void set_baseline_row(Php::Parameters &parameters);

            Php::Value get_baseline_row();

            void set_row_baseline_position(Php::Parameters &parameters);

            Php::Value get_row_baseline_position(Php::Parameters &parameters);
    };

#endif
