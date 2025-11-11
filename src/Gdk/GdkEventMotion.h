
#ifndef _PHPGTK_GDKEVENTMOTION_H_
#define _PHPGTK_GDKEVENTMOTION_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     *
     */
    class GdkEventMotion_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEventMotion_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Populate GdkEventMotion to PHPGTK::GdkEventMotion
             */
            void populate(GdkEventMotion event);
    };

#endif
