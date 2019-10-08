
#ifndef _PHPGTK_GTKOVERLAY_H_
#define _PHPGTK_GTKOVERLAY_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"

    /**
     * GtkOverlay_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkOverlay.html
     */
    class GtkOverlay_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkOverlay_();
            ~GtkOverlay_();

            void __construct();

            void add_overlay(Php::Parameters &parameters);

            void reorder_overlay(Php::Parameters &parameters);

            Php::Value get_overlay_pass_through(Php::Parameters &parameters);

            void set_overlay_pass_through(Php::Parameters &parameters);
    };

#endif
