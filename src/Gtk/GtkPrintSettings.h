
#ifndef _PHPGTK_GTKPRINTSETTINGS_H_
#define _PHPGTK_GTKPRINTSETTINGS_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
    #include "GtkPaperSize.h"

    /**
     * GtkPrintSettings_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkPrintSettings.html
     */
    class GtkPrintSettings_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkPrintSettings_();
            ~GtkPrintSettings_();

            void __construct();

            Php::Value copy();

            Php::Value has_key(Php::Parameters &parameters);

            Php::Value get(Php::Parameters &parameters);

            void set(Php::Parameters &parameters);

            void unset(Php::Parameters &parameters);

            void foreach(Php::Parameters &parameters);

            Php::Value get_bool(Php::Parameters &parameters);

            void set_bool(Php::Parameters &parameters);

            Php::Value get_double(Php::Parameters &parameters);

            Php::Value get_double_with_default(Php::Parameters &parameters);

            void set_double(Php::Parameters &parameters);

            Php::Value get_length(Php::Parameters &parameters);

            void set_length(Php::Parameters &parameters);

            Php::Value get_int(Php::Parameters &parameters);

            Php::Value get_int_with_default(Php::Parameters &parameters);

            void set_int(Php::Parameters &parameters);

            Php::Value get_printer();

            void set_printer(Php::Parameters &parameters);

            Php::Value get_orientation();

            void set_orientation(Php::Parameters &parameters);

            Php::Value get_paper_size();

            void set_paper_size(Php::Parameters &parameters);

            Php::Value get_paper_width(Php::Parameters &parameters);

            void set_paper_width(Php::Parameters &parameters);

            Php::Value get_paper_height(Php::Parameters &parameters);

            void set_paper_height(Php::Parameters &parameters);

            Php::Value get_use_color();

            void set_use_color(Php::Parameters &parameters);

            Php::Value get_collate();

            void set_collate(Php::Parameters &parameters);

            Php::Value get_reverse();

            void set_reverse(Php::Parameters &parameters);

            Php::Value get_duplex();

            void set_duplex(Php::Parameters &parameters);

            Php::Value get_quality();

            void set_quality(Php::Parameters &parameters);

            Php::Value get_n_copies();

            void set_n_copies(Php::Parameters &parameters);

            Php::Value get_number_up();

            void set_number_up(Php::Parameters &parameters);

            Php::Value get_number_up_layout();

            void set_number_up_layout(Php::Parameters &parameters);

            Php::Value get_resolution();

            void set_resolution(Php::Parameters &parameters);

            void set_resolution_xy(Php::Parameters &parameters);

            Php::Value get_resolution_x();

            Php::Value get_resolution_y();

            Php::Value get_printer_lpi();

            void set_printer_lpi(Php::Parameters &parameters);

            Php::Value get_scale();

            void set_scale(Php::Parameters &parameters);

            Php::Value get_print_pages();

            void set_print_pages(Php::Parameters &parameters);

            Php::Value get_page_ranges(Php::Parameters &parameters);

            void set_page_ranges(Php::Parameters &parameters);

            Php::Value get_page_set();

            void set_page_set(Php::Parameters &parameters);

            Php::Value get_default_source();

            void set_default_source(Php::Parameters &parameters);

            Php::Value get_media_type();

            void set_media_type(Php::Parameters &parameters);

            Php::Value get_dither();

            void set_dither(Php::Parameters &parameters);

            Php::Value get_finishings();

            void set_finishings(Php::Parameters &parameters);

            Php::Value get_output_bin();

            void set_output_bin(Php::Parameters &parameters);

            Php::Value new_from_file(Php::Parameters &parameters);

            Php::Value new_from_key_file(Php::Parameters &parameters);

            Php::Value load_file(Php::Parameters &parameters);

            Php::Value load_key_file(Php::Parameters &parameters);

            Php::Value to_file(Php::Parameters &parameters);

            void to_key_file(Php::Parameters &parameters);
    };

#endif
