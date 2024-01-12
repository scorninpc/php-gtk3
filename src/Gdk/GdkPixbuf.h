
#ifndef _PHPGTK_GDKPIXBUF_H_
#define _PHPGTK_GDKPIXBUF_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
    #include <gdk/gdk.h>

    #include "GdkPixbufFormat.h"
    #include "GdkWindow.h"

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
            GdkPixbuf *instance;

            /**
             *  C++ constructor and destructor
             */
            GdkPixbuf_();
            ~GdkPixbuf_();

            /**
             * Return original GdkPixbuf
             */
            GdkPixbuf *get_instance();

            /**
             * Set the original GdkPixbuf
             */
            void set_instance(GdkPixbuf *pased_pixbuf);

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
            static Php::Value new_from_gd(Php::Parameters &parameters);

            static Php::Value new_from_file_at_size(Php::Parameters &parameters);

            static Php::Value new_from_file_at_scale(Php::Parameters &parameters);

            static Php::Value get_file_info(Php::Parameters &parameters);

            Php::Value get_colorspace();

            Php::Value get_n_channels();

            Php::Value get_has_alpha();

            Php::Value get_pixels();

            Php::Value get_width();

            Php::Value get_height();

            Php::Value get_rowstride();

            Php::Value get_option(Php::Parameters &parameters);

            Php::Value save(Php::Parameters &parameters);
            
            Php::Value get_from_drawable(Php::Parameters &parameters);
            
            Php::Value scale_simple(Php::Parameters &parameters);

            Php::Value get_data(Php::Parameters& parameters);

            Php::Value get_byte_length();

            void set_data(Php::Parameters& parameters);

    };

#endif