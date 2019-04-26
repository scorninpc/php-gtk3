
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
            GdkPixbuf *pixbuf;

            /**
             *  C++ constructor and destructor
             */
            GdkPixbuf_();
            ~GdkPixbuf_();

            /**
             * Return original GdkPixbuf
             */
            GdkPixbuf *get_pixbuf();

            /**
             * Set the original GdkPixbuf
             */
            void set_pixbuf(GdkPixbuf *pased_pixbuf);

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Creates a new pixbuf by loading an image from a file.
             *
             * https://developer.gnome.org/gdk-pixbuf/stable/gdk-pixbuf-File-Loading.html#gdk-pixbuf-new-from-file
             */
            static Php::Value new_from_file(Php::Parameters &parameters);
    };

#endif