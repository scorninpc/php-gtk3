
#ifndef _PHPGTK_GTKMESSAGEDIALOG_H_
#define _PHPGTK_GTKMESSAGEDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"

    /**
     * GtkMessageDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkMessageDialog.html
     */
    class GtkMessageDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkMessageDialog_();
            ~GtkMessageDialog_();

            void __construct(Php::Parameters &parameters);

            static Php::Value new_with_markup(Php::Parameters &parameters);

            void set_markup(Php::Parameters &parameters);

            void format_secondary_text(Php::Parameters &parameters);

            void format_secondary_markup(Php::Parameters &parameters);

            Php::Value get_message_area();
    };

#endif
