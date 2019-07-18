
#ifndef _PHPGTK_GDKRGBA_H_
#define _PHPGTK_GDKRGBA_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * 
     */
    class GdkRGBA_ : public Php::Base
    {
        /**
         * Publics
         */
        public:
            /**
             *  C++ constructor and destructor
             */
            GdkRGBA_();
            ~GdkRGBA_();

            Php::Value __get(const Php::Value &name);

            GdkRGBA instance;
            GdkRGBA get_instance();
            void set_instance(GdkRGBA event);


            static Php::Value parse(Php::Parameters &parameters);
            Php::Value to_string(Php::Parameters &parameters);
    };

#endif