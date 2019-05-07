
#ifndef _PHPGTK_GTKDIALOG_H_
#define _PHPGTK_GTKDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWindow.h"
    #include "GtkBox.h"

    /**
     * GtkDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkDialog.html
     */
    class GtkDialog_ : public GtkWindow_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkDialog_();
            virtual ~GtkDialog_();

            void __construct();

            static Php::Value new_with_buttons(Php::Parameters &parameters);

            Php::Value run();

            void response(Php::Parameters &parameters);

            void add_button(Php::Parameters &parameters);

            void add_buttons(Php::Parameters &parameters);

            void add_action_widget(Php::Parameters &parameters);

            void set_default_response(Php::Parameters &parameters);

            void set_response_sensitive(Php::Parameters &parameters);

            void get_response_for_widget(Php::Parameters &parameters);

            Php::Value get_widget_for_response(Php::Parameters &parameters);

            Php::Value get_content_area();

            Php::Value get_header_bar();
    };

#endif
