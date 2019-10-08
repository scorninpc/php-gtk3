
#ifndef _PHPGTK_GLADEAPP_H_
#define _PHPGTK_GLADEAPP_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
	#include "../Gtk/GtkWidget.h"
	#include "GladeProject.h"

    /**
     * GladeApp_
     * 
     * https://developer.gnome.org/gtk3/stable/GladeApp.html
     */
    class GladeApp_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GladeApp_();
            ~GladeApp_();

            void __construct();

            static Php::Value get();

            void set_window();

            Php::Value get_window();

            Php::Value get_clipboard();

            void add_project();

            void remove_project();

            Php::Value get_projects();

            Php::Value get_config();

            Php::Value is_project_loaded();

            Php::Value get_project_by_path();

            Php::Value config_save();

            void set_accel_group();

            Php::Value get_catalogs_dir();

            Php::Value get_modules_dir();

            Php::Value get_pixmaps_dir();

            Php::Value get_locale_dir();
    };

#endif
