
#ifndef _PHPGTK_GDKPIXBUF_H_
#define _PHPGTK_GDKPIXBUF_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GdkPixbuf
     * 
     * https://developer.gnome.org/gdk-pixbuf/stable/gdk-pixbuf-The-GdkPixbuf-Structure.html
     */
    class GdkPixbuf_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GdkPixbuf_();
            ~GdkPixbuf_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif