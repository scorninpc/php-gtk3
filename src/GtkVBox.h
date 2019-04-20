
#ifndef _PHPGTK_GTKVBOX_H_
#define _PHPGTK_GTKVBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkBox.h"

    /**
     * 
     */
    class GtkVBox_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkVBox_();
            virtual ~GtkVBox_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &params);
    };

#endif