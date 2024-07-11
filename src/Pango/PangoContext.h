
#ifndef _PHPGTK_PANGOCONTEXT_H_
#define _PHPGTK_PANGOCONTEXT_H_

    #include <phpcpp.h>

    #include "../G/GObject.h"

    class PangoContext_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            PangoContext_();
            ~PangoContext_();

            void __construct();
    };

#endif
