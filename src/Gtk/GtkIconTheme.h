
#ifndef _PHPGTK_GTKICONTHEME_H_
#define _PHPGTK_GTKICONTHEME_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkIconTheme
     * 
     * https://docs.gtk.org/gtk3/class.IconTheme.html
     */
    class GtkIconTheme_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkIconTheme_();
            ~GtkIconTheme_();

            void __construct();
			static Php::Value get_default();
			static Php::Value get_for_screen(Php::Parameters &parameters);
            Php::Value has_icon(Php::Parameters &parameters);
            Php::Value list_icons(Php::Parameters &parameters);
            void add_resource_path(Php::Parameters &parameters);
            void append_search_path(Php::Parameters &parameters);
            void prepend_search_path(Php::Parameters &parameters);
    };

#endif

