
#ifndef _PHPGTK_GDKEVENTSCROLL_H_
#define _PHPGTK_GDKEVENTSCROLL_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     *
     */
    class GdkEventScroll_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEventScroll_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Populate GdkEventScroll to PHPGTK::GdkEventScroll
             */
            void populate(GdkEventScroll event);
    };

#endif
