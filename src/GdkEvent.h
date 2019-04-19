
#ifndef _PHPGTK_GDKEVENT_H_
#define _PHPGTK_GDKEVENT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * @todo Add all properties
     */
    class GdkEvent_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkEvent_();

            /**
             * Populate GdkEvent to PHPGTK::GDKEVENT
             */
            void populate(GdkEvent *event);
    };

#endif