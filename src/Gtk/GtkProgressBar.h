
#ifndef _PHPGTK_GTKPROGRESSBAR_H_
#define _PHPGTK_GTKPROGRESSBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWidget.h"

    /**
     * GtkProgressBar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkProgressBar.html
     */
    class GtkProgressBar_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkProgressBar_();
            ~GtkProgressBar_();

            void __construct();

            void pulse();

            void set_fraction(Php::Parameters &parameters);

            Php::Value get_fraction();

            void set_inverted(Php::Parameters &parameters);

            Php::Value get_inverted();

            void set_show_text(Php::Parameters &parameters);

            Php::Value get_show_text();

            void set_text(Php::Parameters &parameters);

            Php::Value get_text();

            void set_ellipsize(Php::Parameters &parameters);

            Php::Value get_ellipsize();

            void set_pulse_step(Php::Parameters &parameters);

            Php::Value get_pulse_step();
    };

#endif
