
#ifndef _PHPGTK_GTKFILEFILTER_H_
#define _PHPGTK_GTKFILEFILTER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GObject.h"

    /**
     * GtkFileFilter_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFileFilter.html
     */
    class GtkFileFilter_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFileFilter_();
            ~GtkFileFilter_();

            void __construct();

            void set_name(Php::Parameters &parameters);

            Php::Value get_name();

            void add_mime_type(Php::Parameters &parameters);

            void add_pattern(Php::Parameters &parameters);

            void add_pixbuf_formats();

            Php::Value get_needed();

            Php::Value filter(Php::Parameters &parameters);
    };

#endif
