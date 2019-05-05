
#ifndef _PHPGTK_GTKNOTEBOOK_H_
#define _PHPGTK_GTKNOTEBOOK_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"

    /**
     * GtkNotebook_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkNotebook.html
     */
    class GtkNotebook_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkNotebook_();
            ~GtkNotebook_();

            void __construct();

            Php::Value append_page(Php::Parameters &parameters);

            Php::Value insert_page(Php::Parameters &parameters);

            void remove_page(Php::Parameters &parameters);

            void detach_tab(Php::Parameters &parameters);

            Php::Value page_num(Php::Parameters &parameters);

            void next_page();

            void prev_page();

            void reorder_child(Php::Parameters &parameters);

            void set_tab_pos(Php::Parameters &parameters);

            void set_show_tabs(Php::Parameters &parameters);

            void set_show_border(Php::Parameters &parameters);

            void set_scrollable(Php::Parameters &parameters);

            void popup_enable();

            void popup_disable();

            Php::Value get_current_page();

            Php::Value get_menu_label(Php::Parameters &parameters);

            Php::Value get_nth_page(Php::Parameters &parameters);

            Php::Value get_n_pages();

            Php::Value get_tab_label(Php::Parameters &parameters);

            void set_menu_label(Php::Parameters &parameters);

            void set_menu_label_text(Php::Parameters &parameters);

            void set_tab_label(Php::Parameters &parameters);

            void set_tab_label_text(Php::Parameters &parameters);

            void set_tab_reorderable(Php::Parameters &parameters);

            void set_tab_detachable(Php::Parameters &parameters);

            Php::Value get_menu_label_text(Php::Parameters &parameters);

            Php::Value get_scrollable();

            Php::Value get_show_border();

            Php::Value get_show_tabs();

            Php::Value get_tab_label_text(Php::Parameters &parameters);

            Php::Value get_tab_pos();
    };

#endif
