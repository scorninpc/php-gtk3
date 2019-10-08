
#ifndef _PHPGTK_GTKWIDGETPATH_H_
#define _PHPGTK_GTKWIDGETPATH_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkWidget.h"

    /**
     * GtkWidgetPath_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkWidgetPath.html
     */
    class GtkWidgetPath_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GtkWidgetPath *instance;
            GtkWidgetPath *get_instance();
            void set_instance(GtkWidgetPath *pased_instance);

            /**
             *  C++ constructor and destructor
             */
            GtkWidgetPath_();
            ~GtkWidgetPath_();

            void __construct();

            Php::Value append_type(Php::Parameters &parameters);

            Php::Value append_with_siblings(Php::Parameters &parameters);

            Php::Value append_for_widget(Php::Parameters &parameters);

            Php::Value copy();

            Php::Value ref();

            void unref();

            void free();

            Php::Value get_object_type();

            Php::Value has_parent(Php::Parameters &parameters);

            Php::Value is_type(Php::Parameters &parameters);

            void iter_add_class(Php::Parameters &parameters);

            void iter_add_region(Php::Parameters &parameters);

            void iter_clear_classes(Php::Parameters &parameters);

            void iter_clear_regions(Php::Parameters &parameters);

            Php::Value iter_get_name(Php::Parameters &parameters);

            Php::Value iter_get_object_name(Php::Parameters &parameters);

            Php::Value iter_get_object_type(Php::Parameters &parameters);

            Php::Value iter_get_siblings(Php::Parameters &parameters);

            Php::Value iter_get_sibling_index(Php::Parameters &parameters);

            Php::Value iter_get_state(Php::Parameters &parameters);

            Php::Value iter_has_class(Php::Parameters &parameters);

            Php::Value iter_has_name(Php::Parameters &parameters);

            Php::Value iter_has_qclass(Php::Parameters &parameters);

            Php::Value iter_has_qname(Php::Parameters &parameters);

            Php::Value iter_has_qregion(Php::Parameters &parameters);

            Php::Value iter_has_region(Php::Parameters &parameters);

            Php::Value iter_list_classes(Php::Parameters &parameters);

            Php::Value iter_list_regions(Php::Parameters &parameters);

            void iter_remove_class(Php::Parameters &parameters);

            void iter_remove_region(Php::Parameters &parameters);

            void iter_set_name(Php::Parameters &parameters);

            void iter_set_object_name(Php::Parameters &parameters);

            void iter_set_object_type(Php::Parameters &parameters);

            void iter_set_state(Php::Parameters &parameters);

            Php::Value length();

            void prepend_type(Php::Parameters &parameters);

            Php::Value to_string();
    };

#endif
