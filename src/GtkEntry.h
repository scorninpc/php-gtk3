
#ifndef _PHPGTK_GTKENTRY_H_
#define _PHPGTK_GTKENTRY_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkWidget.h"

    /**
     * 
     */
    class GtkEntry_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkEntry_();
            virtual ~GtkEntry_();

            /**
             * PHP Construct
             * 
             * https://developer.gnome.org/gtk3/stable/GtkEntry.html#gtk-entry-new
             */
            void __construct();
    };

#endif