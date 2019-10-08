
#ifndef _PHPGTK_GTKTEXTMARK_H_
#define _PHPGTK_GTKTEXTMARK_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
    #include "GtkTextBuffer.h"

    /**
     * GtkTextMark_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextMark.html
     */
    class GtkTextMark_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTextMark_();
            ~GtkTextMark_();

            void __construct(Php::Parameters &parameters);

            void set_visible(Php::Parameters &parameters);

            Php::Value set_buffer();

            Php::Value get_deleted();

            Php::Value get_name();

            Php::Value get_buffer();

            Php::Value get_left_gravity();
    };

#endif
