
#ifndef _PHPGTK_GLADEEDITOR_H_
#define _PHPGTK_GLADEEDITOR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    
    #include <gladeui/glade.h>

	#include "../Gtk/GtkBox.h"
	#include "../Gtk/GtkWidget.h"
	#include "GladeProject.h"
    #include "GladeWidget.h"

    /**
     * GladeEditor_
     * 
     * https://developer.gnome.org/gtk3/stable/GladeEditor.html
     */
    class GladeEditor_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GladeEditor_();
            ~GladeEditor_();

            void __construct();

            void load_widget(Php::Parameters &parameters);

            Php::Value query_dialog(Php::Parameters &parameters);
    };

#endif
