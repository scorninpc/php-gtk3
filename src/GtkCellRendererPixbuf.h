
#ifndef _PHPGTK_GTKCELLRENDERERPIXBUF_H_
#define _PHPGTK_GTKCELLRENDERERPIXBUF_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkCellRenderer.h"

    /**
     * GtkCellRendererPixbuf_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCellRendererPixbuf.html
     */
    class GtkCellRendererPixbuf_ : public GtkCellRenderer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCellRendererPixbuf_();
            ~GtkCellRendererPixbuf_();

            void __construct();
    };

#endif
