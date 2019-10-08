
#ifndef _PHPGTK_GTKAPPLICATION_H_
#define _PHPGTK_GTKAPPLICATION_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GApplication.h"
	#include "GtkWindow.h"

    /**
     * GtkApplication_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkApplication.html
     */
    class GtkApplication_ : public GApplication_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkApplication_();
            ~GtkApplication_();

            void __construct(Php::Parameters &parameters);

            void add_window(Php::Parameters &parameters);

            void remove_window(Php::Parameters &parameters);

            Php::Value get_windows();

            Php::Value get_window_by_id(Php::Parameters &parameters);

            Php::Value get_active_window();

            Php::Value inhibit(Php::Parameters &parameters);

            void uninhibit(Php::Parameters &parameters);

            Php::Value is_inhibited(Php::Parameters &parameters);

            Php::Value prefers_app_menu();

            Php::Value get_app_menu();

            void set_app_menu(Php::Parameters &parameters);

            Php::Value get_menubar();

            void set_menubar(Php::Parameters &parameters);

            Php::Value get_menu_by_id(Php::Parameters &parameters);

            void add_accelerator(Php::Parameters &parameters);

            void remove_accelerator(Php::Parameters &parameters);

            Php::Value list_action_descriptions();

            Php::Value get_accels_for_action(Php::Parameters &parameters);

            void set_accels_for_action(Php::Parameters &parameters);

            Php::Value get_actions_for_accel(Php::Parameters &parameters);




            Php::Value window_new();
    };

#endif
