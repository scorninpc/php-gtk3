
#ifndef _PHPGTK_GTKBUTTON_H_
#define _PHPGTK_GTKBUTTON_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkBin.h"

    /**
     * 
     */
    class GtkButton_ : public GtkBin_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkButton_();
            virtual ~GtkButton_();

            /**
             * Set button label
             *      https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-set-label
             */
            void set_label(Php::Parameters &parameters);

            /**
             * new_with_label
             *      https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-new-with-label
             */
            static Php::Value new_with_label(Php::Parameters &parameters);
    };

#endif