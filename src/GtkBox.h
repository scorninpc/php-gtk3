
#ifndef _PHPGTK_GTKBOX_H_
#define _PHPGTK_GTKBOX_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkContainer.h"

    /**
     * 
     */
    class GtkBox_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkBox_();
            virtual ~GtkBox_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Adds child to box , packed with reference to the start of box . The child is packed after any other child packed with reference to the start of box.
             *      https://developer.gnome.org/gtk3/stable/GtkBox.html#gtk-box-pack-start
             */
            void pack_start(Php::Parameters &parameters);

            /**
             * Adds child to box , packed with reference to the end of box . The child is packed after (away from end of) any other child packed with reference to the end of box.
             *      https://developer.gnome.org/gtk3/stable/GtkBox.html#gtk-box-pack-end
             */
            void pack_end(Php::Parameters &parameters);

            /**
             * Sets the “homogeneous” property of box , controlling whether or not all children of box are given equal space in the box.
             *      https://developer.gnome.org/gtk3/stable/GtkBox.html#gtk-box-set-homogeneous
             */
            void set_homogeneous(Php::Parameters &parameters);

            /**
             * Sets the “spacing” property of box , which is the number of pixels to place between children of box.
             *      https://developer.gnome.org/gtk3/stable/GtkBox.html#gtk-box-set-spacing
             */
            void set_spacing(Php::Parameters &parameters);
    };

#endif