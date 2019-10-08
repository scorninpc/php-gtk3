
#ifndef _PHPGTK_GTKCELLRENDERER_H_
#define _PHPGTK_GTKCELLRENDERER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "../G/GObject.h"

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

            /**
             * Sets the renderer’s alignment within its available space.
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRenderer.html#gtk-cell-renderer-set-alignment
             */
            void set_alignment(Php::Parameters &parameters);

            /**
             * Fills in xalign and yalign with the appropriate values of cell.
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRenderer.html#gtk-cell-renderer-get-alignment
             */
            Php::Value get_alignment();
    };

#endif