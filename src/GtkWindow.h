
#ifndef _PHPGTK_GTKWINDOW_H_
#define _PHPGTK_GTKWINDOW_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>

    #include "GtkBin.h"

    /**
     *  
     */
    class GtkWindow_ : public GtkBin_
    {
        
        /**
         * Publics
         */
        public:
            /**
             * C++ constructor/destructor
             * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-new
             */
            GtkWindow_();
            virtual ~GtkWindow_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Sets the title of the GtkWindow
             *      https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-title
             */
            void set_title(Php::Parameters &parameters);

            /**
             * Sets the default size of a window
             *      https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-default-size
             */
            void set_default_size(Php::Parameters &parameters);
    };

#endif