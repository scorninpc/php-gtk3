
#ifndef _PHPGTK_GTKMENUITEM_H_
#define _PHPGTK_GTKMENUITEM_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"

    /**
     * GtkMenuItem_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkMenuItem.html
     */
    class GtkMenuItem_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkMenuItem_();
            ~GtkMenuItem_();

            void __construct();

            static Php::Value  new_with_label(Php::Parameters &parameters);

            static Php::Value  new_with_mnemonic(Php::Parameters &parameters);

            Php::Value get_label();

            void set_label(Php::Parameters &parameters);

            Php::Value get_use_underline();

            void set_use_underline(Php::Parameters &parameters);

            void set_submenu(Php::Parameters &parameters);

            Php::Value get_submenu();

            void set_accel_path(Php::Parameters &parameters);

            Php::Value get_accel_path();

            void select();

            void deselect();

            void activate();

            Php::Value toggle_size_request(Php::Parameters &parameters);

            void size_allocate(Php::Parameters &parameters);

            Php::Value get_reserve_indicator();

            void set_reserve_indicator(Php::Parameters &parameters);
    };

#endif
