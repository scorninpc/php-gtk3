
#ifndef _PHPGTK_GTKTOOLITEM_H_
#define _PHPGTK_GTKTOOLITEM_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"
	#include "GtkWidget.h"
	#include "GtkIconSize.h"
	#include "GtkOrientation.h"
	#include "GtkToolbarStyle.h"
	#include "GtkReliefStyle.h"
	#include "GtkSizeGroup.h"

    /**
     * GtkToolItem_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkToolItem.html
     */
    class GtkToolItem_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkToolItem_();
            ~GtkToolItem_();

            void __construct();

            void set_homogeneous(Php::Parameters &parameters);

            Php::Value get_homogeneous();

            void set_expand(Php::Parameters &parameters);

            Php::Value get_expand();

            void set_tooltip_text(Php::Parameters &parameters);

            void set_tooltip_markup(Php::Parameters &parameters);

            void set_use_drag_window(Php::Parameters &parameters);

            Php::Value get_use_drag_window();

            void set_visible_horizontal(Php::Parameters &parameters);

            Php::Value get_visible_horizontal();

            void set_visible_vertical(Php::Parameters &parameters);

            Php::Value get_visible_vertical();

            void set_is_important(Php::Parameters &parameters);

            Php::Value get_is_important();

            Php::Value get_icon_size();

            Php::Value get_orientation();

            Php::Value get_toolbar_style();

            Php::Value get_relief_style();

            Php::Value get_text_alignment();

            Php::Value get_text_orientation();

            Php::Value retrieve_proxy_menu_item();

            void set_proxy_menu_item(Php::Parameters &parameters);

            Php::Value get_proxy_menu_item(Php::Parameters &parameters);

            void rebuild_menu();

            void toolbar_reconfigured();

            void get_text_size_group();
    };

#endif
