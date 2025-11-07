#ifndef _PHPGTK_GDKEVENTFOCUS_H_
#define _PHPGTK_GDKEVENTFOCUS_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     *
     */
    class GdkEventFocus_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEventFocus_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Populate GdkEventFocus to PHPGTK::GdkEventFocus
             */
            void populate(GdkEventFocus event);
    };

#endif
