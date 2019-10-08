
#ifndef _PHPGTK_GTKLISTBOXROW_H_
#define _PHPGTK_GTKLISTBOXROW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkBin.h"

    /**
     * GtkListBoxRow_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkListBoxRow.html
     */
    class GtkListBoxRow_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            GtkListBoxRow *row;

            /**
             * Set/Get original row
             */
            GtkListBoxRow *get_row();
            void set_row(GtkListBoxRow *pased_row);

            /**
             *  C++ constructor and destructor
             */
            GtkListBoxRow_();
            ~GtkListBoxRow_();

            void __construct();
    };

#endif
