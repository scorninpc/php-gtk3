
#ifndef _PHPGTK_GDKEVENTKEY_H_
#define _PHPGTK_GDKEVENTKEY_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     *
     */
    class GdkEventKey_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEventKey_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Populate GdkEventKey to PHPGTK::GdkEventKey
             */
            void populate(GdkEventKey event);
    };

#endif