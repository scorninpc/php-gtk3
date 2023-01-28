
#ifndef _PHPGTK_GTKACTIONBAR_H_
#define _PHPGTK_GTKACTIONBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkActionBar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkActionBar.html
     */
    class GtkActionBar_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkActionBar_();
            ~GtkActionBar_();

            void __construct();

            void pack_start(Php::Parameters &parameters);

            void pack_end(Php::Parameters &parameters);

            Php::Value get_center_widget();

            void set_center_widget(Php::Parameters &parameters);
    };

#endif
