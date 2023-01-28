
#ifndef _PHPGTK_GTKINFOBAR_H_
#define _PHPGTK_GTKINFOBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBox.h"
	#include "GtkWidget.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkInfoBar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkInfoBar.html
     */
    class GtkInfoBar_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkInfoBar_();
            ~GtkInfoBar_();

            void __construct();

            static Php::Value new_with_buttons(Php::Parameters &parameters);

            void add_action_widget(Php::Parameters &parameters);

            Php::Value add_button(Php::Parameters &parameters);

            void add_buttons(Php::Parameters &parameters);

            void set_response_sensitive(Php::Parameters &parameters);

            void set_default_response(Php::Parameters &parameters);

            void response(Php::Parameters &parameters);

            void set_message_type(Php::Parameters &parameters);

            Php::Value get_message_type();

            Php::Value get_action_area();

            Php::Value get_content_area();

            Php::Value get_show_close_button();

            void set_show_close_button(Php::Parameters &parameters);
    };

#endif
