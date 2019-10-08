
#ifndef _PHPGTK_GTKMENUSHELL_H_
#define _PHPGTK_GTKMENUSHELL_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkWidget.h"

    /**
     * GtkMenuShell_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkMenuShell.html
     */
    class GtkMenuShell_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkMenuShell_();
            ~GtkMenuShell_();

            void append(Php::Parameters &parameters);

            void prepend(Php::Parameters &parameters);

            void insert(Php::Parameters &parameters);

            void deactivate();

            void select_item(Php::Parameters &parameters);

            void select_first(Php::Parameters &parameters);

            void deselect();

            void activate_item(Php::Parameters &parameters);

            void cancel();

            void set_take_focus(Php::Parameters &parameters);

            Php::Value get_take_focus();

            Php::Value get_selected_item();

            Php::Value get_parent_shell();

            void bind_model(Php::Parameters &parameters);
    };

#endif
