
#ifndef _PHPGTK_GTKSIZEGROUP_H_
#define _PHPGTK_GTKSIZEGROUP_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
	#include "GtkWidget.h"

    /**
     * GtkSizeGroup_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkSizeGroup.html
     */
    class GtkSizeGroup_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSizeGroup_();
            ~GtkSizeGroup_();

            void __construct(Php::Parameters &parameters);

            void set_mode(Php::Parameters &parameters);

            Php::Value get_mode();

            void add_widget(Php::Parameters &parameters);

            void remove_widget(Php::Parameters &parameters);

            Php::Value get_widgets();
    };

#endif
