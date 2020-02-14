
#ifndef _PHPGTK_GTKOSXAPPLICATION_H_
#define _PHPGTK_GTKOSXAPPLICATION_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    #include "../G/GObject.h"

    #include "gtkmacintegration/gtkosxapplication.h"


    /**
     * GtkosxApplication_
     * 
     * http://gtk-osx.sourceforge.net/gtk-mac-integration/GtkosxApplication.html
     */
    class GtkosxApplication_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkosxApplication_();
            ~GtkosxApplication_();

            void __construct(Php::Parameters &parameters);
            void set_dock_icon_pixbuf(Php::Parameters &parameters);
            void set_use_quartz_accelerators(Php::Parameters &parameters);
            Php::Value use_quartz_accelerators();
            void ready();
            void set_menu_bar(Php::Parameters &parameters);
            void sync_menubar();
            void insert_app_menu_item(Php::Parameters &parameters);
            void set_window_menu(Php::Parameters &parameters);
            void set_help_menu(Php::Parameters &parameters);
            void set_dock_menu(Php::Parameters &parameters);
            void set_dock_icon_resource(Php::Parameters &parameters);
            void attention_request(Php::Parameters &parameters);
            void cancel_attention_request(Php::Parameters &parameters);
            Php::Value get_bundle_path();
            Php::Value get_resource_path();
            Php::Value get_executable_path();
            Php::Value get_bundle_id();
            Php::Value get_bundle_info(Php::Parameters &parameters);
    };

#endif  