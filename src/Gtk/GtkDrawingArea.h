
#ifndef _PHPGTK_GTKDRAWINGAREA_H_
#define _PHPGTK_GTKDRAWINGAREA_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkWidget.h"

    class GtkDrawingArea_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkDrawingArea_();
            ~GtkDrawingArea_();

            void __construct();
    };

#endif
