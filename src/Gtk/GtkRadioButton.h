
#ifndef _PHPGTK_GTKRADIOBUTTON_H_
#define _PHPGTK_GTKRADIOBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkCheckButton.h"

    /**
     * GtkRadioButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkRadioButton.html
     */
    class GtkRadioButton_ : public GtkCheckButton_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkRadioButton_();
            ~GtkRadioButton_();

            void __construct(Php::Parameters &parameters);

            static Php::Value new_from_widget(Php::Parameters &parameters);

            static Php::Value new_with_label(Php::Parameters &parameters);

            static Php::Value new_with_label_from_widget(Php::Parameters &parameters);

            static Php::Value new_with_mnemonic(Php::Parameters &parameters);

            static Php::Value new_with_mnemonic_from_widget(Php::Parameters &parameters);

            void set_group(Php::Parameters &parameters);

            Php::Value get_group();

            void join_group(Php::Parameters &parameters);
    };

#endif
