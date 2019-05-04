
#ifndef _PHPGTK_GTKPOLICYTYPE_H_
#define _PHPGTK_GTKPOLICYTYPE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkPolicyType_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkPolicyType.html
     */
    class GtkPolicyType_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkPolicyType_();
            ~GtkPolicyType_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif