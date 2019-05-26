
#ifndef _PHPGTK_GDKEVENT_H_
#define _PHPGTK_GDKEVENT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GdkEventButton.h"

    /**
     * 
     */
    class GdkEvent_ : public Php::Base
    {
        /**
         * Publics
         */
        public:
            GdkEvent *instance;

            /**
             *  C++ constructor and destructor
             */
            GdkEvent_();

            GdkEvent *get_instance();

            // 
            void set_instance(GdkEvent *event);

            /**
             * Populate GdkEvent to PHPGTK::GDKEVENT
             */
            void populate(GdkEvent *event);
    };

#endif