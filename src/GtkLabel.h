
#ifndef _PHPGTK_GTKLABEL_H_
#define _PHPGTK_GTKLABEL_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWidget.h"
	#include "GtkJustification.h"

    /**
     * GtkLabel_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkLabel.html
     */
    class GtkLabel_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkLabel_();
            ~GtkLabel_();

            void __construct(Php::Parameters &parameters);

            void set_text(Php::Parameters &parameters);

            void set_markup(Php::Parameters &parameters);

            void set_markup_with_mnemonic(Php::Parameters &parameters);

            void set_pattern(Php::Parameters &parameters);

            void set_justify(Php::Parameters &parameters);

            void set_xalign(Php::Parameters &parameters);

            void set_yalign(Php::Parameters &parameters);

            void set_width_chars(Php::Parameters &parameters);

            void set_max_width_chars(Php::Parameters &parameters);

            void set_line_wrap(Php::Parameters &parameters);

            void set_lines(Php::Parameters &parameters);

            Php::Value get_mnemonic_keyval();

            Php::Value get_selectable();

            Php::Value get_text();

            void set_mnemonic_widget(Php::Parameters &parameters);

            void set_selectable(Php::Parameters &parameters);

            void set_text_with_mnemonic(Php::Parameters &parameters);

            Php::Value get_justify();

            Php::Value get_xalign();

            Php::Value get_yalign();

            Php::Value get_width_chars();

            Php::Value get_max_width_chars();

            Php::Value get_label();

            Php::Value get_line_wrap();

            Php::Value get_lines();

            Php::Value get_mnemonic_widget();

            Php::Value get_use_markup();

            Php::Value get_use_underline();

            Php::Value get_single_line_mode();

            Php::Value get_angle();

            void set_label(Php::Parameters &parameters);

            void set_use_markup(Php::Parameters &parameters);

            void set_use_underline(Php::Parameters &parameters);

            void set_single_line_mode(Php::Parameters &parameters);

            void set_angle(Php::Parameters &parameters);

            Php::Value get_current_uri();

            void set_track_visited_links(Php::Parameters &parameters);

            Php::Value get_track_visited_links();
    };

#endif
