
#ifndef _PHPGTK_GTKTOOLBAR_H_
#define _PHPGTK_GTKTOOLBAR_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkWidget.h"
	#include "GtkToolItem.h"
	#include "GtkToolbarStyle.h"
	#include "GtkIconSize.h"
	#include "GtkReliefStyle.h"

    /**
     * GtkToolbar_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkToolbar.html
     */
    class GtkToolbar_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkToolbar_();
            ~GtkToolbar_();

            void __construct();

            void insert(Php::Parameters &parameters);

            Php::Value get_item_index(Php::Parameters &parameters);

            Php::Value get_n_items();

            Php::Value get_nth_item(Php::Parameters &parameters);

            Php::Value get_drop_index(Php::Parameters &parameters);

            void set_drop_highlight_item(Php::Parameters &parameters);

            void set_show_arrow(Php::Parameters &parameters);

            void unset_icon_size();

            Php::Value get_show_arrow();

            Php::Value get_style();

            Php::Value get_icon_size();

            Php::Value get_relief_style();

            void set_style(Php::Parameters &parameters);

            void set_icon_size(Php::Parameters &parameters);

            void unset_style();
    };

#endif
