
#ifndef _PHPGTK_GTKCHECKMENUITEM_H_
#define _PHPGTK_GTKCHECKMENUITEM_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkMenuItem.h"

    /**
     * GtkCheckMenuItem_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCheckMenuItem.html
     */
    class GtkCheckMenuItem_ : public GtkMenuItem_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCheckMenuItem_();
            ~GtkCheckMenuItem_();

            void __construct();

            static Php::Value new_with_label(Php::Parameters &parameters);

            static Php::Value new_with_mnemonic(Php::Parameters &parameters);

            Php::Value get_active();

            void set_active(Php::Parameters &parameters);

            void toggled();

            Php::Value get_inconsistent();

            void set_inconsistent(Php::Parameters &parameters);

            Php::Value get_draw_as_radio();

            void set_draw_as_radio(Php::Parameters &parameters);
    };

#endif
