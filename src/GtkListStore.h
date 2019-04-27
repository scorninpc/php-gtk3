
#ifndef _PHPGTK_GTKLISTSTORE_H_
#define _PHPGTK_GTKLISTSTORE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkListStore_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkListStore.html
     */
    class GtkListStore_ : public Php::Base
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
    };

#endif