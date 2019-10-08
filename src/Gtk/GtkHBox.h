
#ifndef _PHPGTK_GTKHBOX_H_
#define _PHPGTK_GTKHBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkBox.h"

    /**
     * 
     */
    class GtkHBox_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkHBox_();
            virtual ~GtkHBox_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &params);
    };

#endif