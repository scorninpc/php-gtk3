
#ifndef _PHPGTK_GTKBUTTON_H_
#define _PHPGTK_GTKBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkButton.html
     */
    class GtkButton_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkButton_();
            ~GtkButton_();

            void __construct();

            static Php::Value new_with_label(Php::Parameters &parameters);

            static Php::Value new_with_mnemonic(Php::Parameters &parameters);

            static Php::Value new_from_icon_name(Php::Parameters &parameters);

            static Php::Value new_from_stock();

            void pressed();

            void released();

            void clicked();

            void enter();

            void leave();

            void set_relief(Php::Parameters &parameters);

            Php::Value get_relief();

            Php::Value get_label();

            void set_label(Php::Parameters &parameters);

            Php::Value get_use_stock();

            void set_use_stock(Php::Parameters &parameters);

            Php::Value get_use_underline();

            void set_use_underline(Php::Parameters &parameters);

            void set_focus_on_click(Php::Parameters &parameters);

            Php::Value get_focus_on_click();

            void set_alignment(Php::Parameters &parameters);

            void get_alignment(Php::Parameters &parameters);

            void set_image(Php::Parameters &parameters);

            Php::Value get_image();

            void set_image_position(Php::Parameters &parameters);

            Php::Value get_image_position();

            void set_always_show_image(Php::Parameters &parameters);

            Php::Value get_always_show_image();

            Php::Value get_event_window();

            Php::Value get_child();
    };

#endif
