
#ifndef _PHPGTK_GdkEVENTBUTTON_H_
#define _PHPGTK_GdkEVENTBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     *
     */
    class GdkEventButton_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEventButton_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Populate GdkEventButton to PHPGTK::GdkEventButton
             */
            void populate(GdkEventButton event);
    };

#endif