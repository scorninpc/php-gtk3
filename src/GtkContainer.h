
#ifndef _PHPGTK_GTKCONTAINER_H_
#define _PHPGTK_GTKCONTAINER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkWidget.h"

    /**
     * 
     */
    class GtkContainer_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkContainer_();
            virtual ~GtkContainer_();

            /**
             * Adds widget to container
             *      https://developer.gnome.org/gtk3/stable/GtkContainer.html#gtk-container-add
             */
            void add(Php::Parameters &parameters);
    };

#endif