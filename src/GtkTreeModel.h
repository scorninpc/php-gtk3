
#ifndef _PHPGTK_TREEMODEL_H_
#define _PHPGTK_TREEMODEL_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkTreeModel_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeModel.html
     */
    class GtkTreeModel_ : public Php::Base
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
    };

#endif