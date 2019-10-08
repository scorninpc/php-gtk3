
#ifndef _PHPGTK_GTKPAGESETUP_H_
#define _PHPGTK_GTKPAGESETUP_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
    #include "GtkPaperSize.h"

    /**
     * GtkPageSetup_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkPageSetup.html
     */
    class GtkPageSetup_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkPageSetup_();
            ~GtkPageSetup_();

            void __construct();

            static Php::Value new_from_file(Php::Parameters &parameters);

            static Php::Value new_from_key_file(Php::Parameters &parameters);

            Php::Value copy();

            Php::Value get_orientation();

            void set_orientation(Php::Parameters &parameters);

            Php::Value get_paper_size();

            void set_paper_size(Php::Parameters &parameters);

            Php::Value get_top_margin(Php::Parameters &parameters);

            void set_top_margin(Php::Parameters &parameters);

            Php::Value get_bottom_margin(Php::Parameters &parameters);

            void set_bottom_margin(Php::Parameters &parameters);

            Php::Value get_left_margin(Php::Parameters &parameters);

            void set_left_margin(Php::Parameters &parameters);

            Php::Value get_right_margin(Php::Parameters &parameters);

            void set_right_margin(Php::Parameters &parameters);

            void set_paper_size_and_default_margins(Php::Parameters &parameters);

            Php::Value get_paper_width(Php::Parameters &parameters);

            Php::Value get_paper_height(Php::Parameters &parameters);

            Php::Value get_page_width(Php::Parameters &parameters);

            Php::Value get_page_height(Php::Parameters &parameters);

            Php::Value load_file(Php::Parameters &parameters);

            Php::Value load_key_file(Php::Parameters &parameters);

            Php::Value to_file(Php::Parameters &parameters);

            void to_key_file(Php::Parameters &parameters);
    };

#endif
