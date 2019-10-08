
#ifndef _PHPGTK_GTKAPPCHOOSERBUTTON_H_
#define _PHPGTK_GTKAPPCHOOSERBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkComboBox.h"

    /**
     * GtkAppChooserButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkAppChooserButton.html
     */
    class GtkAppChooserButton_ : public GtkComboBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkAppChooserButton_();
            ~GtkAppChooserButton_();

            void __construct(Php::Parameters &parameters);

            void append_custom_item(Php::Parameters &parameters);

            void append_separator();

            void set_active_custom_item(Php::Parameters &parameters);

            Php::Value get_show_default_item();

            void set_show_default_item(Php::Parameters &parameters);

            Php::Value get_show_dialog_item();

            void set_show_dialog_item(Php::Parameters &parameters);

            Php::Value get_heading();

            void set_heading(Php::Parameters &parameters);
            
            Php::Value get_app_info();
    };

#endif
