
#ifndef _PHPGTK_GDKPIXBUFFORMAT_H_
#define _PHPGTK_GDKPIXBUFFORMAT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>


    /**
     * GdkPixbufFormat_
     * 
     * https://developer.gnome.org/gtk3/stable/GdkPixbufFormat.html
     */
    class GdkPixbufFormat_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GdkPixbufFormat *instance;

            /**
             *  C++ constructor and destructor
             */
            GdkPixbufFormat_();
            ~GdkPixbufFormat_();

            /**
             * Return original GtkWidget
             */
            GdkPixbufFormat *get_instance();

            /**
             * Set the original GdkPixbufFormat
             */
            void set_instance(GdkPixbufFormat *pixbuf_format);


    };

#endif
