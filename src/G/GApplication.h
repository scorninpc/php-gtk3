
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

            Php::Value id_is_valid();

            Php::Value __construct(Php::Parameters &parameters);

            Php::Value get_application_id();

            void set_application_id(Php::Parameters &parameters);

            Php::Value get_inactivity_timeout();

            void set_inactivity_timeout(Php::Parameters &parameters);

            Php::Value get_flags();

            void set_flags(Php::Parameters &parameters);

            Php::Value get_resource_base_path();

            void set_resource_base_path(Php::Parameters &parameters);

            Php::Value get_dbus_connection();

            Php::Value get_dbus_object_path();

            void set_action_group(Php::Parameters &parameters);

            Php::Value get_is_registered();

            Php::Value get_is_remote();

            Php::Value _register(Php::Parameters &parameters);

            void hold();

            void release();

            void quit();

            void activate();

            void open(Php::Parameters &parameters);

            void send_notification(Php::Parameters &parameters);

            void withdraw_notification(Php::Parameters &parameters);

            static Php::Value run(Php::Parameters &parameters);

            void add_main_option_entries(Php::Parameters &parameters);

            void add_main_option(Php::Parameters &parameters);

            void add_option_group(Php::Parameters &parameters);

            void set_option_context_parameter_string(Php::Parameters &parameters);

            void set_option_context_summary(Php::Parameters &parameters);

            void set_option_context_description(Php::Parameters &parameters);

            void set_default();

            Php::Value get_default();

            void mark_busy();

            void unmark_busy();

            Php::Value get_is_busy();

            void bind_busy_property(Php::Parameters &parameters);

            void unbind_busy_property(Php::Parameters &parameters);
    };

#endif
