
#ifndef _PHPGTK_GTKABOUTDIALOG_H_
#define _PHPGTK_GTKABOUTDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"
	#include "GdkPixbuf.h"

    /**
     * GtkAboutDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkAboutDialog.html
     */
    class GtkAboutDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkAboutDialog_();
            ~GtkAboutDialog_();

            void __construct();

            Php::Value get_program_name();

            void set_program_name(Php::Parameters &parameters);

            Php::Value get_version();

            void set_version(Php::Parameters &parameters);

            Php::Value get_copyright();

            void set_copyright(Php::Parameters &parameters);

            Php::Value get_comments();

            void set_comments(Php::Parameters &parameters);

            Php::Value get_license();

            void set_license(Php::Parameters &parameters);

            Php::Value get_wrap_license();

            void set_wrap_license(Php::Parameters &parameters);

            Php::Value get_license_type();

            void set_license_type(Php::Parameters &parameters);

            Php::Value get_website();

            void set_website(Php::Parameters &parameters);

            Php::Value get_website_label();

            void set_website_label(Php::Parameters &parameters);

            Php::Value get_authors();

            void set_authors(Php::Parameters &parameters);

            Php::Value get_artists();

            void set_artists(Php::Parameters &parameters);

            Php::Value get_documenters();

            void set_documenters(Php::Parameters &parameters);

            Php::Value get_translator_credits();

            void set_translator_credits(Php::Parameters &parameters);

            Php::Value get_logo();

            void set_logo(Php::Parameters &parameters);

            Php::Value get_logo_icon_name();

            void set_logo_icon_name(Php::Parameters &parameters);

            void add_credit_section(Php::Parameters &parameters);

            void gtk_show_about_dialog(Php::Parameters &parameters);
    };

#endif
