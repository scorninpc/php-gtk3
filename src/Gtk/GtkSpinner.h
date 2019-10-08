
#ifndef _PHPGTK_GTKSPINNER_H_
#define _PHPGTK_GTKSPINNER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWidget.h"

    /**
     * GtkSpinner_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkSpinner.html
     */
    class GtkSpinner_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSpinner_();
            ~GtkSpinner_();

            void __construct();

            void start();

            void stop();
    };

#endif
