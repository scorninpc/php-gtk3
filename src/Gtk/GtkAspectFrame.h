
#ifndef _PHPGTK_GTKASPECTFRAME_H_
#define _PHPGTK_GTKASPECTFRAME_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkFrame.h"

    /**
     * GtkAspectFrame_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkAspectFrame.html
     */
    class GtkAspectFrame_ : public GtkFrame_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkAspectFrame_();
            ~GtkAspectFrame_();

            void __construct(Php::Parameters &parameters);

            void set(Php::Parameters &parameters);
    };

#endif
