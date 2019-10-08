
#ifndef _PHPGTK_GTKFLOWBOXCHILD_H_
#define _PHPGTK_GTKFLOWBOXCHILD_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"

    /**
     * GtkFlowBoxChild_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFlowBoxChild.html
     */
    class GtkFlowBoxChild_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFlowBoxChild_();
            ~GtkFlowBoxChild_();

            void __construct();

            Php::Value get_index();

            Php::Value is_selected();

            void changed();
    };

#endif
