
#ifndef _PHPGTK_GTKLAYOUT_H_
#define _PHPGTK_GTKLAYOUT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkWindow.h"
	#include "GtkAdjustment.h"

    /**
     * GtkLayout_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkLayout.html
     */
    class GtkLayout_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkLayout_();
            ~GtkLayout_();

            void __construct(Php::Parameters &parameters);

            void put(Php::Parameters &parameters);

            void move(Php::Parameters &parameters);

            void set_size(Php::Parameters &parameters);

            Php::Value get_size(Php::Parameters &parameters);

            Php::Value get_hadjustment();

            Php::Value get_vadjustment();

            void set_hadjustment(Php::Parameters &parameters);

            void set_vadjustment(Php::Parameters &parameters);

            Php::Value get_bin_window();
    };

#endif
