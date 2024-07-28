
#ifndef _PHPGTK_PANGOATTRLIST_H_
#define _PHPGTK_PANGOATTRLIST_H_

    #include <phpcpp.h>

    #include "../G/GObject.h"

    class PangoAttrList_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            PangoAttrList_();
            ~PangoAttrList_();

            void __construct();

            Php::Value get_attributes();
    };

#endif
