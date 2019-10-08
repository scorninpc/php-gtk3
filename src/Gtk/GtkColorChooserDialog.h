
#ifndef _PHPGTK_GTKCOLORCHOOSERDIALOG_H_
#define _PHPGTK_GTKCOLORCHOOSERDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"
	#include "../Gdk/GdkRGBA.h"

    /**
     * GtkColorChooserDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkColorChooserDialog.html
     */
    class GtkColorChooserDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkColorChooserDialog_();
            ~GtkColorChooserDialog_();

            void __construct(Php::Parameters &parameters);

            Php::Value get_rgba();

            void set_rgba(Php::Parameters &parameters);

            Php::Value get_use_alpha();

            void set_use_alpha(Php::Parameters &parameters);

            void add_palette(Php::Parameters &parameters);
    };

#endif
