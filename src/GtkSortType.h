
#ifndef _PHPGTK_GTKSORTTYPE_H_
#define _PHPGTK_GTKSORTTYPE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkSortType_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkSortType.html
     */
    class GtkSortType_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSortType_();
            ~GtkSortType_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif