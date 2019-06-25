
#ifndef _PHPGTK_GTKPAGESETUPUNIXDIALOG_H_
#define _PHPGTK_GTKPAGESETUPUNIXDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"
	#include "GtkPageSetup.h"
    #include "GtkWidget.h"
    #include "GtkContainer.h"

    /**
     * GtkPageSetupUnixDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkPageSetupUnixDialog.html
     */
    class GtkPageSetupUnixDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkPageSetupUnixDialog_();
            ~GtkPageSetupUnixDialog_();

            void __construct(Php::Parameters &parameters);

            void set_page_setup(Php::Parameters &parameters);

            Php::Value get_page_setup();

            void set_print_settings(Php::Parameters &parameters);

            Php::Value get_print_settings();
    };

#endif
