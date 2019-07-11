
#ifndef _PHPGTK_GTKBOX_H_
#define _PHPGTK_GTKBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "../php-gtk.h"

    #include "GtkContainer.h"
	#include "GtkWidget.h"

    /**
     * GtkBox_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkBox.html
     */
    class GtkBox_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkBox_();
            ~GtkBox_();

            void __construct(Php::Parameters &parameters);

            void pack_start(Php::Parameters &parameters);

            void pack_end(Php::Parameters &parameters);

            Php::Value get_homogeneous();

            void set_homogeneous(Php::Parameters &parameters);

            Php::Value get_spacing();

            void set_spacing(Php::Parameters &parameters);

            void reorder_child(Php::Parameters &parameters);

            Php::Value query_child_packing(Php::Parameters &parameters);

            void set_child_packing(Php::Parameters &parameters);

            Php::Value get_baseline_position();

            void set_baseline_position(Php::Parameters &parameters);

            Php::Value get_center_widget();

            void set_center_widget(Php::Parameters &parameters);
    };

#endif
