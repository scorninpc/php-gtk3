
#ifndef _PHPGTK_GLADEWIDGET_H_
#define _PHPGTK_GLADEWIDGET_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    
    #include <gladeui/glade.h>

	#include "../Gtk/GtkBox.h"
	#include "../Gtk/GtkWidget.h"
	#include "GladeProject.h"

    /**
     * GladeWidget_
     * 
     * https://developer.gnome.org/gtk3/stable/GladeWidget.html
     */
    class GladeWidget_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GladeWidget_();
            ~GladeWidget_();

            void __construct();
    };

#endif
