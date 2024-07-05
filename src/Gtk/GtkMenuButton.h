
#ifndef _PHPGTK_GTKMENUBUTTON_H_
#define _PHPGTK_GTKMENUBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkToggleButton.h"

	#include "../../php-gtk.h"

    /**
     * GtkMenuButton_
     *
     * https://developer.gnome.org/gtk3/stable/GtkMenuButton.html
     */
    class GtkMenuButton_ : public GtkToggleButton_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkMenuButton_();
            ~GtkMenuButton_();

            void __construct();

            void set_popup(Php::Parameters& parameters);
    };

#endif
