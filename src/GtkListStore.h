
#ifndef _PHPGTK_GTKLISTSTORE_H_
#define _PHPGTK_GTKLISTSTORE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkTreeIter.h"
    #include "GtkTreeModel.h"

    /**
     * GtkListStore_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkListStore.html
     */
    class GtkListStore_ : public GtkTreeModel_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkListStore_();
            ~GtkListStore_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Sets the data in the cell specified by iter and column . The type of value must be convertible to the type of the column.
             *
             * https://developer.gnome.org/gtk3/stable/GtkListStore.html#gtk-list-store-set-value
             */
            void set_value(Php::Parameters &parameters);

            /**
             * Appends a new row to list_store
             *
             * https://developer.gnome.org/gtk3/stable/GtkListStore.html#gtk-list-store-append
             */
            void append(Php::Parameters &parameters);
    };

#endif