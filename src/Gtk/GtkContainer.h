
#ifndef _PHPGTK_GTKCONTAINER_H_
#define _PHPGTK_GTKCONTAINER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWidget.h"
	#include "GtkWidgetPath.h"
    #include "GtkAdjustment.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkContainer_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkContainer.html
     */
    class GtkContainer_ : public GtkWidget_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkContainer_();
            ~GtkContainer_();

            void add(Php::Parameters &parameters);

            void remove(Php::Parameters &parameters);

            void add_with_properties(Php::Parameters &parameters);

            Php::Value get_resize_mode();

            void set_resize_mode(Php::Parameters &parameters);

            void check_resize();

            void foreach(Php::Parameters &parameters);

            Php::Value get_children();

            Php::Value get_path_for_child(Php::Parameters &parameters);

            void set_reallocate_redraws(Php::Parameters &parameters);

            Php::Value get_focus_child();

            void set_focus_child(Php::Parameters &parameters);

            Php::Value get_focus_vadjustment();

            void set_focus_vadjustment(Php::Parameters &parameters);

            Php::Value get_focus_hadjustment();

            void set_focus_hadjustment(Php::Parameters &parameters);

            void resize_children();

            Php::Value child_type();

            void child_get(Php::Parameters &parameters);

            void child_set(Php::Parameters &parameters);

            void child_get_property(Php::Parameters &parameters);

            void child_set_property(Php::Parameters &parameters);

            void child_get_valist(Php::Parameters &parameters);

            void child_set_valist(Php::Parameters &parameters);

            void child_notify(Php::Parameters &parameters);

            void child_notify_by_pspec(Php::Parameters &parameters);

            void forall(Php::Parameters &parameters);

            Php::Value get_border_width();

            void set_border_width(Php::Parameters &parameters);

            void propagate_draw(Php::Parameters &parameters);

            Php::Value get_focus_chain(Php::Parameters &parameters);

            void set_focus_chain(Php::Parameters &parameters);

            void unset_focus_chain();

            Php::Value class_find_child_property(Php::Parameters &parameters);

            void class_install_child_property(Php::Parameters &parameters);

            void class_install_child_properties(Php::Parameters &parameters);

            Php::Value class_list_child_properties(Php::Parameters &parameters);

            void class_handle_border_width();
    };

#endif
