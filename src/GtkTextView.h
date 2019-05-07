
#ifndef _PHPGTK_GTKTEXTVIEW_H_
#define _PHPGTK_GTKTEXTVIEW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"

    /**
     * GtkTextView_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextView.html
     */
    class GtkTextView_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTextView_();
            ~GtkTextView_();

            void __construct();
    };

#endif
