
#ifndef _PHPGTK_GTKEXPANDER_H_
#define _PHPGTK_GTKEXPANDER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkExpander_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkExpander.html
     */
    class GtkExpander_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkExpander_();
            ~GtkExpander_();

            void __construct(Php::Parameters &parameters);

            static Php::Value new_with_mnemonic(Php::Parameters &parameters);

            void set_expanded(Php::Parameters &parameters);

            Php::Value get_expanded();

            void set_spacing(Php::Parameters &parameters);

            Php::Value get_spacing();

            void set_label(Php::Parameters &parameters);

            Php::Value get_label();

            void set_use_underline(Php::Parameters &parameters);

            Php::Value get_use_underline();

            void set_use_markup(Php::Parameters &parameters);

            Php::Value get_use_markup();

            void set_label_widget(Php::Parameters &parameters);

            Php::Value get_label_widget();

            void set_label_fill(Php::Parameters &parameters);

            Php::Value get_label_fill();

            void set_resize_toplevel(Php::Parameters &parameters);

            Php::Value get_resize_toplevel();
    };

#endif
