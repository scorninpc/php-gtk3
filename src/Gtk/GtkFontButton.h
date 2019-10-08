
#ifndef _PHPGTK_GTKFONTBUTTON_H_
#define _PHPGTK_GTKFONTBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkButton.h"

    /**
     * GtkFontButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFontButton.html
     */
    class GtkFontButton_ : public GtkButton_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFontButton_();
            ~GtkFontButton_();

            void __construct();

            static Php::Value new_with_font(Php::Parameters &parameters);

            Php::Value set_font_name(Php::Parameters &parameters);
            void set_font(Php::Parameters &parameters);

            Php::Value get_font_name();
            Php::Value get_font();

            void set_show_style(Php::Parameters &parameters);

            Php::Value get_show_style();

            void set_show_size(Php::Parameters &parameters);

            Php::Value get_show_size();

            void set_use_font(Php::Parameters &parameters);

            Php::Value get_use_font();

            void set_use_size(Php::Parameters &parameters);

            Php::Value get_use_size();

            void set_title(Php::Parameters &parameters);

            Php::Value get_title();
    };

#endif
