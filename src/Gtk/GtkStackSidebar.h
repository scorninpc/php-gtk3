
#ifndef _PHPGTK_GTKSTACKSIDEBAR_H_
#define _PHPGTK_GTKSTACKSIDEBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkStack.h"

    /**
     * GtkStackSidebar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkStackSidebar.html
     */
    class GtkStackSidebar_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkStackSidebar_();
            ~GtkStackSidebar_();

            void __construct();

            void set_stack(Php::Parameters &parameters);

            Php::Value get_stack();
    };

#endif
