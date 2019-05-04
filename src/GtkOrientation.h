
#ifndef _PHPGTK_GTKORIENTATION_H_
#define _PHPGTK_GTKORIENTATION_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkOrientation_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkOrientation.html
     */
    class GtkOrientation_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkOrientation_();
            ~GtkOrientation_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif