
#ifndef _PHPGTK_GTKFIXED_H_
#define _PHPGTK_GTKFIXED_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"

    /**
     * GtkFixed_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFixed.html
     */
    class GtkFixed_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFixed_();
            ~GtkFixed_();

            void __construct();

            void put(Php::Parameters &parameters);

            void move(Php::Parameters &parameters);
    };

#endif
