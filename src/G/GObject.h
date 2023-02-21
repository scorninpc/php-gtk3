
#ifndef _PHPGTK_GOBJECT_H_
#define _PHPGTK_GOBJECT_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>


    

    /**
     *  
     */
    class GObject_ : public Php::Base
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
            gpointer *instance;

            /**
             * Set/Get original gpoint
             */
            gpointer *get_instance();
            void set_instance(gpointer *pased_instance);

            /**
             *  C++ constructor/destructor
             */
            GObject_();
            virtual ~GObject_();

            /**
             * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
             */
            Php::Value connect_internal(Php::Parameters &parameters, bool after);
            Php::Value connect(Php::Parameters &parameters);
            Php::Value connect_after(Php::Parameters &parameters);

            /**
             * Class to abstract php callback for connect method, to call PHP function
             */
            static bool connect_callback(gpointer user_data, ...);

            /**
             * Disconnect signal by handle
             *
             * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-handler-disconnect
             */
            void handler_disconnect(Php::Parameters &parameters);

            Php::Value is_connected(Php::Parameters& parameters);

            Php::Value get_property(Php::Parameters &parameters);
            Php::Value set_property(Php::Parameters &parameters);
            void signal_handler_block(Php::Parameters &parameters);
            void signal_handler_unblock(Php::Parameters &parameters);


            void __clone();
    };

#endif