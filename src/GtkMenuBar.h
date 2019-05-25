
#ifndef _PHPGTK_GTKMENUBAR_H_
#define _PHPGTK_GTKMENUBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkMenuShell.h"
	#include "GtkWidget.h"

    /**
     * GtkMenuBar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkMenuBar.html
     */
    class GtkMenuBar_ : public GtkMenuShell_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkMenuBar_();
            ~GtkMenuBar_();

            void __construct();

            static void new_from_model(Php::Parameters &parameters);

            void set_pack_direction(Php::Parameters &parameters);

            Php::Value get_pack_direction();

            void set_child_pack_direction(Php::Parameters &parameters);

            void child_pack_direction();
    };

#endif
