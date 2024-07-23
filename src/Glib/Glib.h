
#ifndef _PHPGTK_GLIB_H_
#define _PHPGTK_GLIB_H_

    #include <glib.h>
    #include <phpcpp.h>

    class Glib_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            Glib_();
            ~Glib_();

            /**
            * https://docs.gtk.org/glib/func.markup_escape_text.html
            */
            static Php::Value markup_escape_text(Php::Parameters &parameters);
    };

#endif
