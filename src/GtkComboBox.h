
#ifndef _PHPGTK_GTKCOMBOBOX_H_
#define _PHPGTK_GTKCOMBOBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"
	#include "GtkTreeModel.h"
	#include "GtkTreeIter.h"
    #include "GtkCellRenderer.h"

    /**
     * GtkComboBox_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkComboBox.html
     */
    class GtkComboBox_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            bool liststore_type;

            /**
             *  C++ constructor and destructor
             */
            GtkComboBox_();
            ~GtkComboBox_();

            void __construct();

            static Php::Value new_with_entry();

            static Php::Value new_with_model(Php::Parameters &parameters);

            static Php::Value new_with_model_and_entry(Php::Parameters &parameters);

            static Php::Value new_with_area(Php::Parameters &parameters);

            static Php::Value new_with_area_and_entry(Php::Parameters &parameters);

            Php::Value get_wrap_width();

            void set_wrap_width(Php::Parameters &parameters);

            Php::Value get_row_span_column();

            void set_row_span_column(Php::Parameters &parameters);

            Php::Value get_column_span_column();

            void set_column_span_column(Php::Parameters &parameters);

            Php::Value get_active();

            void set_active(Php::Parameters &parameters);

            Php::Value get_active_iter();

            void set_active_iter(Php::Parameters &parameters);

            Php::Value get_id_column();

            void set_id_column(Php::Parameters &parameters);

            Php::Value get_active_id();

            void set_active_id(Php::Parameters &parameters);

            Php::Value get_model();

            void set_model(Php::Parameters &parameters);

            void popup_for_device(Php::Parameters &parameters);

            void popup();

            void popdown();

            Php::Value get_popup_accessible();

            Php::Value get_row_separator_func();

            void set_row_separator_func(Php::Parameters &parameters);

            void set_button_sensitivity(Php::Parameters &parameters);

            Php::Value get_button_sensitivity();

            Php::Value get_has_entry();

            Php::Value get_entry_text_column();

            void set_entry_text_column(Php::Parameters &parameters);

            Php::Value get_popup_fixed_width();

            void set_popup_fixed_width(Php::Parameters &parameters);


            // From Interface
            void pack_start(Php::Parameters &parameters);
            void pack_end(Php::Parameters &parameters);
            void reorder(Php::Parameters &parameters);
            void clear(Php::Parameters &parameters);
            void add_attribute(Php::Parameters &parameters);

    };

#endif
