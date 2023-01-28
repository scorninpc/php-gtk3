
#ifndef _PHPGTK_GTKHEADERBAR_H_
#define _PHPGTK_GTKHEADERBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkWidget.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkHeaderBar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkHeaderBar.html
     */
    class GtkHeaderBar_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkHeaderBar_();
            ~GtkHeaderBar_();

            void __construct();

            void set_title(Php::Parameters &parameters);

            Php::Value get_title();

            void set_subtitle(Php::Parameters &parameters);

            Php::Value get_subtitle();

            void set_has_subtitle(Php::Parameters &parameters);

            Php::Value get_has_subtitle();

            void set_custom_title(Php::Parameters &parameters);

            Php::Value get_custom_title();

            void pack_start(Php::Parameters &parameters);

            void pack_end(Php::Parameters &parameters);

            void set_show_close_button(Php::Parameters &parameters);

            Php::Value get_show_close_button();

            void set_decoration_layout(Php::Parameters &parameters);

            Php::Value get_decoration_layout();
    };

#endif
