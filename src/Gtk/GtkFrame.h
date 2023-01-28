
#ifndef _PHPGTK_GTKFRAME_H_
#define _PHPGTK_GTKFRAME_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkFrame_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFrame.html
     */
    class GtkFrame_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFrame_();
            ~GtkFrame_();

            void __construct(Php::Parameters &parameters);

            void set_label(Php::Parameters &parameters);

            void set_label_widget(Php::Parameters &parameters);

            void set_label_align(Php::Parameters &parameters);

            void set_shadow_type(Php::Parameters &parameters);

            Php::Value get_label();

            Php::Value get_label_align(Php::Parameters &parameters);

            Php::Value get_label_widget();

            Php::Value get_shadow_type();
    };

#endif
