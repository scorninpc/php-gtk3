
#ifndef _PHPGTK_GTKLISTSTORE_H_
#define _PHPGTK_GTKLISTSTORE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkTreeModel.h"
	#include "GtkTreeIter.h"
    #include "../main.h"

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

            void __construct(Php::Parameters &parameters);

            void set_column_types(Php::Parameters &parameters);

            void set(Php::Parameters &parameters);

            void set_valist(Php::Parameters &parameters);

            void set_value(Php::Parameters &parameters);

            void set_valuesv(Php::Parameters &parameters);

            Php::Value remove(Php::Parameters &parameters);

            Php::Value insert(Php::Parameters &parameters);

            Php::Value insert_before(Php::Parameters &parameters);

            Php::Value insert_after(Php::Parameters &parameters);

            void insert_with_values(Php::Parameters &parameters);

            void insert_with_valuesv(Php::Parameters &parameters);

            Php::Value prepend(Php::Parameters &parameters);

            Php::Value append(Php::Parameters &parameters);

            void clear();

            Php::Value iter_is_valid(Php::Parameters &parameters);

            void reorder(Php::Parameters &parameters);

            void swap(Php::Parameters &parameters);

            void move_before(Php::Parameters &parameters);

            void move_after(Php::Parameters &parameters);
    };

#endif
