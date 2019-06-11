
#ifndef _PHPGTK_GTKCALENDAR_H_
#define _PHPGTK_GTKCALENDAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWidget.h"

    /**
     * GtkCalendar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCalendar.html
     */
    class GtkCalendar_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCalendar_();
            ~GtkCalendar_();

            void __construct();

            void select_month(Php::Parameters &parameters);

            void select_day(Php::Parameters &parameters);

            void mark_day(Php::Parameters &parameters);

            void unmark_day(Php::Parameters &parameters);

            Php::Value get_day_is_marked(Php::Parameters &parameters);

            void clear_marks();

            Php::Value get_display_options();

            void set_display_options(Php::Parameters &parameters);

            Php::Value get_date(Php::Parameters &parameters);

            void set_detail_func(Php::Parameters &parameters);

            Php::Value get_detail_width_chars();

            void set_detail_width_chars(Php::Parameters &parameters);

            Php::Value get_detail_height_rows();

            void set_detail_height_rows(Php::Parameters &parameters);
    };

#endif
