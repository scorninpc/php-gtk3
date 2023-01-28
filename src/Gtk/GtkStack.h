
#ifndef _PHPGTK_GTKSTACK_H_
#define _PHPGTK_GTKSTACK_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkStack_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkStack.html
     */
    class GtkStack_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkStack_();
            ~GtkStack_();

            void __construct();

            void add_named(Php::Parameters &parameters);

            void add_titled(Php::Parameters &parameters);

            Php::Value get_child_by_name(Php::Parameters &parameters);

            void set_visible_child(Php::Parameters &parameters);

            Php::Value get_visible_child();

            void set_visible_child_name(Php::Parameters &parameters);

            Php::Value get_visible_child_name();

            void set_visible_child_full(Php::Parameters &parameters);

            void set_homogeneous(Php::Parameters &parameters);

            Php::Value get_homogeneous();

            void set_hhomogeneous(Php::Parameters &parameters);

            Php::Value get_hhomogeneous();

            void set_vhomogeneous(Php::Parameters &parameters);

            Php::Value get_vhomogeneous();

            void set_transition_duration(Php::Parameters &parameters);

            Php::Value get_transition_duration();

            void set_transition_type(Php::Parameters &parameters);

            Php::Value get_transition_type();

            Php::Value get_transition_running();

            Php::Value get_interpolate_size();

            void set_interpolate_size(Php::Parameters &parameters);
    };

#endif
