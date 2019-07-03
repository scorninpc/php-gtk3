
#ifndef _PHPGTK_GTKRECENTCHOOSERDIALOG_H_
#define _PHPGTK_GTKRECENTCHOOSERDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"
	#include "GtkWindow.h"

    /**
     * GtkRecentChooserDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkRecentChooserDialog.html
     */
    class GtkRecentChooserDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkRecentChooserDialog_();
            ~GtkRecentChooserDialog_();

            void __construct(Php::Parameters &parameters);

            Php::Value new_for_manager(Php::Parameters &parameters);

            void set_show_private(Php::Parameters &parameters);

            Php::Value get_show_private();

            void set_show_not_found(Php::Parameters &parameters);

            Php::Value get_show_not_found();

            void set_show_icons(Php::Parameters &parameters);

            Php::Value get_show_icons();

            void set_select_multiple(Php::Parameters &parameters);

            Php::Value get_select_multiple();

            void set_local_only(Php::Parameters &parameters);

            Php::Value get_local_only();

            void set_limit(Php::Parameters &parameters);

            Php::Value get_limit();

            void set_show_tips(Php::Parameters &parameters);

            Php::Value get_show_tips();

            void set_sort_type(Php::Parameters &parameters);

            Php::Value get_sort_type();

            void set_sort_func(Php::Parameters &parameters);

            Php::Value set_current_uri(Php::Parameters &parameters);

            Php::Value get_current_uri();

            Php::Value get_current_item();

            Php::Value select_uri(Php::Parameters &parameters);

            void unselect_uri(Php::Parameters &parameters);

            void select_all();

            void unselect_all();

            Php::Value get_items();

            Php::Value get_uris(Php::Parameters &parameters);

            void add_filter(Php::Parameters &parameters);

            void remove_filter(Php::Parameters &parameters);

            Php::Value list_filters();

            void set_filter(Php::Parameters &parameters);

            Php::Value get_filter();
    };

#endif
