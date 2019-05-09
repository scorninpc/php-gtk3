
#ifndef _PHPGTK_GTKTOOLBUTTON_H_
#define _PHPGTK_GTKTOOLBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkToolItem.h"
	#include "GtkWidget.h"

    /**
     * GtkToolButton_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkToolButton.html
     */
    class GtkToolButton_ : public GtkToolItem_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkToolButton_();
            ~GtkToolButton_();

            void __construct(Php::Parameters &parameters);

            void set_label(Php::Parameters &parameters);

            Php::Value get_label();

            void set_use_underline(Php::Parameters &parameters);

            Php::Value get_use_underline();

            void set_icon_name(Php::Parameters &parameters);

            Php::Value get_icon_name();

            void set_icon_widget(Php::Parameters &parameters);

            Php::Value get_icon_widget();

            void set_label_widget(Php::Parameters &parameters);

            Php::Value get_label_widget();
    };

#endif
