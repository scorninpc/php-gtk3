
#ifndef _PHPGTK_GTKFONTCHOOSERDIALOG_H_
#define _PHPGTK_GTKFONTCHOOSERDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"
	#include "GtkWindow.h"

    /**
     * GtkFontChooserDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFontChooserDialog.html
     */
    class GtkFontChooserDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFontChooserDialog_();
            ~GtkFontChooserDialog_();

            void __construct(Php::Parameters &parameters);

            Php::Value get_font_size();

            Php::Value get_font();

            Php::Value get_preview_text();

            void set_preview_text(Php::Parameters &parameters);

            Php::Value get_show_preview_entry();

            void set_show_preview_entry(Php::Parameters &parameters);
    };

#endif
