
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

            /**
             * Sets the height of a renderer to explicitly be determined by the “font” and “y_pad” property set on it.
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRendererText.html#gtk-cell-renderer-text-set-fixed-height-from-font
             */
            void set_fixed_height_from_font(Php::Parameters &parameters);
    };

#endif