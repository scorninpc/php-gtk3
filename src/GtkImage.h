
#ifndef _PHPGTK_GTKIMAGE_H_
#define _PHPGTK_GTKIMAGE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkMisc.h"
	#include "GtkWidget.h"
    #include "GdkPixbuf.h"

    /**
     * GtkImage_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkImage.html
     */
    class GtkImage_ : public GtkMisc_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkImage_();
            ~GtkImage_();

            void __construct();

            Php::Value new_from_file(Php::Parameters &parameters);

            Php::Value new_from_icon_set(Php::Parameters &parameters);

            void get_icon_set(Php::Parameters &parameters);

            Php::Value get_pixbuf();

            void get_stock(Php::Parameters &parameters);

            Php::Value get_animation();

            Php::Value get_icon_name(Php::Parameters &parameters);

            void get_gicon(Php::Parameters &parameters);

            Php::Value get_storage_type();

            Php::Value new_from_pixbuf(Php::Parameters &parameters);

            Php::Value new_from_stock(Php::Parameters &parameters);

            Php::Value new_from_animation();

            Php::Value new_from_icon_name(Php::Parameters &parameters);

            Php::Value new_from_gicon(Php::Parameters &parameters);

            Php::Value new_from_resource(Php::Parameters &parameters);

            Php::Value new_from_surface();

            void set_from_file(Php::Parameters &parameters);

            void set_from_icon_set(Php::Parameters &parameters);

            void set_from_pixbuf(Php::Parameters &parameters);

            void set_from_stock(Php::Parameters &parameters);

            void set_from_animation(Php::Parameters &parameters);

            void set_from_icon_name(Php::Parameters &parameters);

            void set_from_gicon(Php::Parameters &parameters);

            void set_from_resource(Php::Parameters &parameters);

            void set_from_surface(Php::Parameters &parameters);

            void clear();

            void set_pixel_size(Php::Parameters &parameters);

            Php::Value get_pixel_size();
    };

#endif
