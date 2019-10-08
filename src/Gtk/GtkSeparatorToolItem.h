
#ifndef _PHPGTK_GTKSEPARATORTOOLITEM_H_
#define _PHPGTK_GTKSEPARATORTOOLITEM_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkToolItem.h"

    /**
     * GtkSeparatorToolItem_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkSeparatorToolItem.html
     */
    class GtkSeparatorToolItem_ : public GtkToolItem_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSeparatorToolItem_();
            ~GtkSeparatorToolItem_();

            void __construct();

            void set_draw(Php::Parameters &parameters);

            Php::Value get_draw();
    };

#endif
