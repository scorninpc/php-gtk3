#ifndef _PHPGTK_GDKEVENTCONFIGURE_H_
#define _PHPGTK_GDKEVENTCONFIGURE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     *
     */
    class GdkEventConfigure_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEventConfigure_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Populate GdkEventConfigure to PHPGTK::GdkEventConfigure
             */
            void populate(GdkEventConfigure event);
    };

#endif
