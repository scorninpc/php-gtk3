
#ifndef _PHPGTK_GAPPLICATION_H_
#define _PHPGTK_GAPPLICATION_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GObject.h"

    /**
     * GApplication_
     * 
     * https://developer.gnome.org/gtk3/stable/GApplication.html
     */
    class GApplication_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GApplication_();
            ~GApplication_();

            static Php::Value id_is_valid();

            static Php::Value __construct(Php::Parameters &parameters);

            static Php::Value get_application_id();

            static void set_application_id(Php::Parameters &parameters);

            static Php::Value get_inactivity_timeout();

            static void set_inactivity_timeout(Php::Parameters &parameters);

            static Php::Value get_flags();

            static void set_flags(Php::Parameters &parameters);

            static Php::Value get_resource_base_path();

            static void set_resource_base_path(Php::Parameters &parameters);

            static Php::Value get_dbus_connection();

            static Php::Value get_dbus_object_path();

            static void set_action_group(Php::Parameters &parameters);

            static Php::Value get_is_registered();

            static Php::Value get_is_remote();

            static Php::Value _register(Php::Parameters &parameters);

            static void hold();

            static void release();

            static void quit();

            static void activate();

            static void open(Php::Parameters &parameters);

            static void send_notification(Php::Parameters &parameters);

            static void withdraw_notification(Php::Parameters &parameters);

            static Php::Value run(Php::Parameters &parameters);

            static void add_main_option_entries(Php::Parameters &parameters);

            static void add_main_option(Php::Parameters &parameters);

            static void add_option_group(Php::Parameters &parameters);

            static void set_option_context_parameter_string(Php::Parameters &parameters);

            static void set_option_context_summary(Php::Parameters &parameters);

            static void set_option_context_description(Php::Parameters &parameters);

            static void set_default();

            static Php::Value get_default();

            static void mark_busy();

            static void unmark_busy();

            static Php::Value get_is_busy();

            static void bind_busy_property(Php::Parameters &parameters);

            static void unbind_busy_property(Php::Parameters &parameters);
    };

#endif
