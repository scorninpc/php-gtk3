
#ifndef _PHPGTK_GTKREQUISITION_H_
#define _PHPGTK_GTKREQUISITION_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>

    /**
     *  
     */
    class GtkRequisition_ : public Php::Base
    {
        
        /**
         * Publics
         */
        public:

            int width;
            int height;

            /**
             *  C++ constructor and destructor
             */
            GtkRequisition_();
            virtual ~GtkRequisition_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif