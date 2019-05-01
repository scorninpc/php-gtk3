
#ifndef _PHPGTK_GTKCELLRENDERER_H_
#define _PHPGTK_GTKCELLRENDERER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GObject.h"

    /**
     * GtkCellRenderer_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCellRenderer.html
     */
    class GtkCellRenderer_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCellRenderer_();
            ~GtkCellRenderer_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif