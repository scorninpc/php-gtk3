
#ifndef _PHPGTK_GTKMENU_H_
#define _PHPGTK_GTKMENU_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkMenuShell.h"
	#include "GtkWidget.h"

    /**
     * GtkMenu_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkMenu.html
     */
    class GtkMenu_ : public GtkMenuShell_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkMenu_();
            ~GtkMenu_();

            void __construct();

            static void new_from_model(Php::Parameters &parameters);

            void set_screen(Php::Parameters &parameters);

            void reorder_child(Php::Parameters &parameters);

            void attach(Php::Parameters &parameters);

            void popup_at_rect(Php::Parameters &parameters);

            void popup_at_widget(Php::Parameters &parameters);

            void popup_at_pointer (Php::Parameters &parameters);

            void set_accel_group(Php::Parameters &parameters);

            Php::Value get_accel_group();

            void set_accel_path(Php::Parameters &parameters);

            Php::Value get_accel_path();

            void set_monitor(Php::Parameters &parameters);

            Php::Value get_monitor();

            void place_on_monitor(Php::Parameters &parameters);

            void set_reserve_toggle_size(Php::Parameters &parameters);

            Php::Value get_reserve_toggle_size();

            void popdown();

            void reposition();

            Php::Value get_active();

            void set_active(Php::Parameters &parameters);

            void attach_to_widget(Php::Parameters &parameters);

            void detach();

            Php::Value get_attach_widget();

            Php::Value get_for_attach_widget();
    };

#endif
