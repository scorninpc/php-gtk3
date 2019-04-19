
#ifndef _PHPGTK_GTKBUTTON_H_
#define _PHPGTK_GTKBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkBin.h"

    /**
     * 
     */
    class GtkButton_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkButton_();
            virtual ~GtkButton_();
    };

#endif