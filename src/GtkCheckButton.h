
#ifndef _PHPGTK_GTKCHECKBUTTON_H_
#define _PHPGTK_GTKCHECKBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkToggleButton.h"

    /**
     * GtkCheckButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCheckButton.html
     */
    class GtkCheckButton_ : public GtkToggleButton_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCheckButton_();
            ~GtkCheckButton_();

            void __construct();

            static Php::Value new_with_label(Php::Parameters &parameters);

            static Php::Value new_with_mnemonic(Php::Parameters &parameters);
    };

#endif
