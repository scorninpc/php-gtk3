
#ifndef _PHPGTK_GTKTOGGLEBUTTON_H_
#define _PHPGTK_GTKTOGGLEBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkButton.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkToggleButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkToggleButton.html
     */
    class GtkToggleButton_ : public GtkButton_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkToggleButton_();
            ~GtkToggleButton_();

            void __construct();

            static Php::Value new_with_label(Php::Parameters &parameters);

            static Php::Value new_with_mnemonic(Php::Parameters &parameters);

            void set_mode(Php::Parameters &parameters);

            Php::Value get_mode();

            void toggled();

            Php::Value get_active();

            void set_active(Php::Parameters &parameters);

            Php::Value get_inconsistent();

            void set_inconsistent(Php::Parameters &parameters);
    };

#endif
