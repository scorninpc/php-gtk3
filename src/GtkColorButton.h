
#ifndef _PHPGTK_GTKCOLORBUTTON_H_
#define _PHPGTK_GTKCOLORBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkButton.h"
	#include "GdkRGBA.h"

    /**
     * GtkColorButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkColorButton.html
     */
    class GtkColorButton_ : public GtkButton_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkColorButton_();
            ~GtkColorButton_();

            void __construct();

            Php::Value new_with_color();

            static Php::Value new_with_rgba(Php::Parameters &parameters);

            void set_color(Php::Parameters &parameters);

            void get_color(Php::Parameters &parameters);

            void set_alpha(Php::Parameters &parameters);
            void get_alpha(Php::Parameters &parameters);

            void set_rgba(Php::Parameters &parameters);

            Php::Value get_rgba(Php::Parameters &parameters);

            void set_use_alpha(Php::Parameters &parameters);

            Php::Value get_use_alpha();

            void set_title(Php::Parameters &parameters);

            Php::Value get_title();
    };

#endif
