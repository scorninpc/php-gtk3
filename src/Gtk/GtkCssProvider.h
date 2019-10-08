
#ifndef _PHPGTK_GTKCSSPROVIDER_H_
#define _PHPGTK_GTKCSSPROVIDER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"

    /**
     * GtkCssProvider_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCssProvider.html
     */
    class GtkCssProvider_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCssProvider_();
            ~GtkCssProvider_();

            static Php::Value get_named(Php::Parameters &parameters);

            Php::Value load_from_data(Php::Parameters &parameters);

            Php::Value load_from_file(Php::Parameters &parameters);

            Php::Value load_from_path(Php::Parameters &parameters);

            void load_from_resource(Php::Parameters &parameters);

            void __construct();

            Php::Value to_string();

            Php::Value gtk_css_section_get_end_line();

            Php::Value gtk_css_section_get_end_position();

            Php::Value gtk_css_section_get_file();

            Php::Value gtk_css_section_get_parent();

            Php::Value gtk_css_section_get_section_type();

            Php::Value gtk_css_section_get_start_line();

            Php::Value gtk_css_section_get_start_position();

            Php::Value gtk_css_section_ref();

            void gtk_css_section_unref();
    };

#endif
