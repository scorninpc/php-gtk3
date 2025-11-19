
#ifndef _PHPGTK_GDKEVENTCROSSING_H_
#define _PHPGTK_GDKEVENTCROSSING_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     *
     */
    class GdkEventCrossing_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEventCrossing_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Populate GdkEventCrossing to PHPGTK::GdkEventCrossing
             */
            void populate(GdkEventCrossing event);
    };

#endif
