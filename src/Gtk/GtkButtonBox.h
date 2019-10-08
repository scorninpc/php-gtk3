
#ifndef _PHPGTK_GTKBUTTONBOX_H_
#define _PHPGTK_GTKBUTTONBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBox.h"
	#include "GtkBox.h"

    /**
     * GtkButtonBox_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkButtonBox.html
     */
    class GtkButtonBox_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkButtonBox_();
            ~GtkButtonBox_();

            void __construct(Php::Parameters &parameters);

            Php::Value get_layout();

            Php::Value get_child_secondary(Php::Parameters &parameters);

            Php::Value get_child_non_homogeneous(Php::Parameters &parameters);

            void set_layout(Php::Parameters &parameters);

            void set_child_secondary(Php::Parameters &parameters);

            void set_child_non_homogeneous(Php::Parameters &parameters);
    };

#endif
