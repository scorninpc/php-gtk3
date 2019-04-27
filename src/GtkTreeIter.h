
#ifndef _PHPGTK_GTKTREEITER_H_
#define _PHPGTK_GTKTREEITER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkTreeIter_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTreeModel.html#GtkTreeIter-struct
     */
    class GtkTreeIter_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GtkTreeIter *iter;

            /**
             *  C++ constructor and destructor
             */
            GtkTreeIter_();
            ~GtkTreeIter_();

            /**
             * Return original GtkTreeIter
             */
            GtkTreeIter *get_iter();

            /**
             * Set the original GtkTreeIter
             */
            void set_iter(GtkTreeIter *passed_iter);
    };

#endif