
#ifndef _PHPGTK_GTKCELLRENDERERTOGGLE_H_
#define _PHPGTK_GTKCELLRENDERERTOGGLE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkCellRenderer.h"

    /**
     * GtkCellRendererToggle_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html
     */
    class GtkCellRendererToggle_ : public GtkCellRenderer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCellRendererToggle_();
            ~GtkCellRendererToggle_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            void set_activatable(Php::Parameters &parameters);
    };

#endif