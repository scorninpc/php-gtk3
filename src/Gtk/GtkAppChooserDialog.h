
#ifndef _PHPGTK_GTKAPPCHOOSERDIALOG_H_
#define _PHPGTK_GTKAPPCHOOSERDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"
	#include "GtkWindow.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkAppChooserDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkAppChooserDialog.html
     */
    class GtkAppChooserDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkAppChooserDialog_();
            ~GtkAppChooserDialog_();

            void __construc(Php::Parameters &parameters);

            static Php::Value new_for_content_type(Php::Parameters &parameters);

            Php::Value get_widget();

            void set_heading(Php::Parameters &parameters);

            Php::Value get_heading();
            
            Php::Value get_app_info();
    };

#endif
