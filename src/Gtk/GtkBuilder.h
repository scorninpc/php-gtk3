
#ifndef _PHPGTK_GTKBUILDER_H_
#define _PHPGTK_GTKBUILDER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include <sstream>
    #include <string>

	#include "../G/GObject.h"
	#include "GtkWidget.h"
    #include "../../main.h"

    /**
     * GtkBuilder_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkBuilder.html
     */
    class GtkBuilder_ : public GObject_
    {
        /**
         * Privates
         */
        private:
            struct st_callback;
            
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkBuilder_();
            ~GtkBuilder_();

            void __construct();

            static Php::Value new_from_file(Php::Parameters &parameters);

            static Php::Value new_from_resource(Php::Parameters &parameters);

            static Php::Value new_from_string(Php::Parameters &parameters);

            static void add_callback_symbol(Php::Parameters &parameters);

            static void add_callback_symbols(Php::Parameters &parameters);

            static void lookup_callback_symbol(Php::Parameters &parameters);

            Php::Value add_from_file(Php::Parameters &parameters);

            Php::Value add_from_resource(Php::Parameters &parameters);

            Php::Value add_from_string(Php::Parameters &parameters);

            static Php::Value add_objects_from_file(Php::Parameters &parameters);

            static Php::Value add_objects_from_string(Php::Parameters &parameters);

            static Php::Value add_objects_from_resource(Php::Parameters &parameters);

            static Php::Value extend_with_template(Php::Parameters &parameters);

            Php::Value get_object(Php::Parameters &parameters);

            static Php::Value get_objects();

            static void expose_object(Php::Parameters &parameters);

            static void connect_signals(Php::Parameters &parameters);

            void connect_signals_full(Php::Parameters &parameters);
            static void connect_signals_full_callback(GtkBuilder *builder, GObject *object, const gchar *signal_name, const char *handler_name, GObject *connect_object, GConnectFlags flags, gpointer data);
            static void connect_signals_full_callback1(gpointer user_data, ...);

            static void set_translation_domain(Php::Parameters &parameters);

            static Php::Value get_translation_domain();

            static Php::Value get_application();

            static void set_application(Php::Parameters &parameters);

            Php::Value get_type_from_name(Php::Parameters &parameters);

            static Php::Value value_from_string(Php::Parameters &parameters);

            static Php::Value value_from_string_type(Php::Parameters &parameters);
    };

#endif
