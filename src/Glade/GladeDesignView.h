
#ifndef _PHPGTK_GLADEDESIGNVIEW_H_
#define _PHPGTK_GLADEDESIGNVIEW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    #include <gladeui/glade.h>

	#include "../Gtk/GtkBox.h"
	#include "../Gtk/GtkWidget.h"
	#include "GladeProject.h"

    /**
     * GladeDesignView_
     * 
     * https://developer.gnome.org/gtk3/stable/GladeDesignView.html
     */
    class GladeDesignView_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GladeDesignView_();
            ~GladeDesignView_();

            void __construct(Php::Parameters &parameters);

            Php::Value get_project();

            Php::Value get_from_project(Php::Parameters &parameters);
    };

#endif
