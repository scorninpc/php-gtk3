
#ifndef _PHPGTK_GTKTREESTORE_H_
#define _PHPGTK_GTKTREESTORE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkTreeModel.h"

    /**
     * GtkTreeStore_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeStore.html
     */
    class GtkTreeStore_ : public GtkTreeModel_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTreeStore_();
            ~GtkTreeStore_();

            void __construct(Php::Parameters &parameters);

            void set_column_types(Php::Parameters &parameters);

            void set_value(Php::Parameters &parameters);

            Php::Value remove(Php::Parameters &parameters);

            Php::Value insert(Php::Parameters &parameters);

            Php::Value insert_before(Php::Parameters &parameters);

            Php::Value insert_after(Php::Parameters &parameters);

            Php::Value insert_with_values(Php::Parameters &parameters);

            Php::Value prepend(Php::Parameters &parameters);

            Php::Value append(Php::Parameters &parameters);

            Php::Value is_ancestor(Php::Parameters &parameters);

            Php::Value iter_depth(Php::Parameters &parameters);

            void clear();

            void reorder(Php::Parameters &parameters);

            void swap(Php::Parameters &parameters);

            void move_before(Php::Parameters &parameters);

            void move_after(Php::Parameters &parameters);
    };

#endif
