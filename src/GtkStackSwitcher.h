
#ifndef _PHPGTK_GTKSTACKSWITCHER_H_
#define _PHPGTK_GTKSTACKSWITCHER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBox.h"
	#include "GtkStack.h"

    /**
     * GtkStackSwitcher_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkStackSwitcher.html
     */
    class GtkStackSwitcher_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkStackSwitcher_();
            ~GtkStackSwitcher_();

            void __construct();

            void set_stack(Php::Parameters &parameters);

            Php::Value get_stack();
            void set_orientation(Php::Parameters &parameters);
            Php::Value get_orientation();
    };

#endif
