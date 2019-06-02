
#ifndef _PHPGTK_GTKSTATUSBAR_H_
#define _PHPGTK_GTKSTATUSBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBox.h"

    /**
     * GtkStatusbar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkStatusbar.html
     */
    class GtkStatusbar_ : public GtkBox_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkStatusbar_();
            ~GtkStatusbar_();

            void __construct();

            Php::Value get_context_id(Php::Parameters &parameters);

            Php::Value push(Php::Parameters &parameters);

            void pop(Php::Parameters &parameters);

            void remove(Php::Parameters &parameters);

            void remove_all(Php::Parameters &parameters);

            Php::Value get_message_area();
    };

#endif
