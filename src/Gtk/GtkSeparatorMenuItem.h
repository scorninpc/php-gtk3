
#ifndef _PHPGTK_GTKSEPARATORMENUITEM_H_
#define _PHPGTK_GTKSEPARATORMENUITEM_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkMenuItem.h"

    /**
     * GtkSeparatorMenuItem_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkSeparatorMenuItem.html
     */
    class GtkSeparatorMenuItem_ : public GtkMenuItem_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSeparatorMenuItem_();
            ~GtkSeparatorMenuItem_();

            void __construct();
    };

#endif
