
#ifndef _PHPGTK_GTKREVEALER_H_
#define _PHPGTK_GTKREVEALER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"

    /**
     * GtkRevealer_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkRevealer.html
     */
    class GtkRevealer_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkRevealer_();
            ~GtkRevealer_();

            void __construct();

            Php::Value get_reveal_child();

            void set_reveal_child(Php::Parameters &parameters);

            Php::Value get_child_revealed();

            Php::Value get_transition_duration();

            void set_transition_duration(Php::Parameters &parameters);

            Php::Value get_transition_type();

            void set_transition_type(Php::Parameters &parameters);
    };

#endif
