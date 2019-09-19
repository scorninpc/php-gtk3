
#ifndef _PHPGTK_GLADEPROJECT_H_
#define _PHPGTK_GLADEPROJECT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    #include <gladeui/glade.h>

	#include "GObject.h"
	#include "GtkWidget.h"
	#include "GladeProject.h"
    #include "GladeWidget.h"

    /**
     * GladeProject_
     * 
     * https://developer.gnome.org/gtk3/stable/GladeProject.html
     */
    class GladeProject_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            // GladeProject *project;

            // void set_project(GladeProject *passed_project);
            // GladeProject *get_project();

            /**
             *  C++ constructor and destructor
             */
            GladeProject_();
            ~GladeProject_();

            void __construct();

            Php::Value selection_get();
    };

#endif
