
#ifndef _PHPGTK_GDKCURSOR_H_
#define _PHPGTK_GDKCURSOR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "../../php-gtk.h"
    #include "../G/GObject.h"
    #include "GdkDisplay.h"
    #include "GdkPixbuf.h"

    /**
     * GdkCursor_
     */
    class GdkCursor_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkCursor_();
            ~GdkCursor_();

            void __construct(Php::Parameters &parameters);
            static Php::Value new_for_display(Php::Parameters &parameters);
            static Php::Value new_from_name(Php::Parameters &parameters);
            static Php::Value new_from_pixbuf(Php::Parameters &parameters);
            Php::Value get_cursor_type();
            Php::Value get_display();
            Php::Value get_image();
            // gdk_cursor_new_from_name
            // gdk_cursor_new_from_pixbuf
            // gdk_cursor_get_cursor_type
            // gdk_cursor_get_display
            // gdk_cursor_get_image



    };

#endif
