
#ifndef _PHPGTK_GTKCOMBOBOXTEXT_H_
#define _PHPGTK_GTKCOMBOBOXTEXT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkComboBox.h"
	#include "GtkWidget.h"

    /**
     * GtkComboBoxText_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkComboBoxText.html
     */
    class GtkComboBoxText_ : public GtkComboBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkComboBoxText_();
            ~GtkComboBoxText_();

            void __construct();

            static Php::Value new_with_entry();

            void append(Php::Parameters &parameters);

            void prepend(Php::Parameters &parameters);

            void insert(Php::Parameters &parameters);

            void append_text(Php::Parameters &parameters);

            void prepend_text(Php::Parameters &parameters);

            void insert_text(Php::Parameters &parameters);

            void remove(Php::Parameters &parameters);

            void remove_all();

            Php::Value get_active_text();
    };

#endif
