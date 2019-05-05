
#ifndef _PHPGTK_GTKLABEL_H_
#define _PHPGTK_GTKLABEL_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWidget.h"

    /**
     * GtkLabel_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkLabel.html
     */
    class GtkLabel_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkLabel_();
            ~GtkLabel_();

            void __construct(Php::Parameters &parameters);
    };

#endif
