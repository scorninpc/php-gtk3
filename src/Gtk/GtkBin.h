
#ifndef _PHPGTK_GTKBIN_H_
#define _PHPGTK_GTKBIN_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkContainer.h"

    /**
     * 
     */
    class GtkBin_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkBin_();
            virtual ~GtkBin_();

            void test3();
    };

#endif