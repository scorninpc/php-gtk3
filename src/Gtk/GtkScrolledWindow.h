
#ifndef _PHPGTK_GTKSCROLLEDWINDOW_H_
#define _PHPGTK_GTKSCROLLEDWINDOW_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkContainer.h"

    /**
     * GtkScrolledWindow_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkScrolledWindow.html
     */
    class GtkScrolledWindow_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkScrolledWindow_();
            ~GtkScrolledWindow_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Sets the scrollbar policy for the horizontal and vertical scrollbars.
             *
             * https://developer.gnome.org/gtk3/stable/GtkScrolledWindow.html#gtk-scrolled-window-set-policy
             */
            void set_policy(Php::Parameters &parameters);
            
            void set_shadow_type(Php::Parameters &parameters);

            void set_propagate_natural_height(Php::Parameters& parameters);

            void set_max_content_height(Php::Parameters& parameters);

            void set_min_content_height(Php::Parameters& parameters);
    };

#endif