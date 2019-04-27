
#ifndef _PHPGTK_GTKCELLRENDERERTEXT_H_
#define _PHPGTK_GTKCELLRENDERERTEXT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkCellRenderer.h"

    /**
     * GtkCellRendererText_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCellRendererText.html
     */
    class GtkCellRendererText_ : public GtkCellRenderer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCellRendererText_();
            ~GtkCellRendererText_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif