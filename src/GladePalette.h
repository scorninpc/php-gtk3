
#ifndef _PHPGTK_GLADEPALETTE_H_
#define _PHPGTK_GLADEPALETTE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    #include <gladeui/glade.h>

	#include "GtkBox.h"
	#include "GtkWidget.h"

    /**
     * GladePalette_
     * 
     * https://developer.gnome.org/gtk3/stable/GladePalette.html
     */
    class GladePalette_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GladePalette_();
            ~GladePalette_();

            void __construct();

            Php::Value get_item_appearance();

            void set_item_appearance(Php::Parameters &parameters);

            Php::Value get_use_small_item_icons();

            void set_use_small_item_icons(Php::Parameters &parameters);

            Php::Value get_show_selector_button();

            void set_show_selector_button(Php::Parameters &parameters);
    };

#endif
