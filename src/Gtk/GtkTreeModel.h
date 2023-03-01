
#ifndef _PHPGTK_TREEMODEL_H_
#define _PHPGTK_TREEMODEL_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkTreeIter.h"

    #include "../G/GObject.h"

    /**
     * GtkTreeModel_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeModel.html
     */
    class GtkTreeModel_ : public GObject_
    {
        
        /**
         * Publics
         */
        public:

            GtkTreeModel *model;

            /**
             *  C++ constructor and destructor
             */
            GtkTreeModel_();
            ~GtkTreeModel_();

            /**
             * Return original GtkTreeModel
             */
            GtkTreeModel *get_model();

            /**
             * Set the original GtkTreeModel
             */
            void set_model(GtkTreeModel *passed_model);

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            
            Php::Value get_iter(Php::Parameters &parameters);
            Php::Value get_value(Php::Parameters &parameters);
            Php::Value get_path(Php::Parameters &parameters);
            Php::Value get_iter_from_string(Php::Parameters &parameters);
    };

#endif