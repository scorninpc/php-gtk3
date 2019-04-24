
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
             *  PHP Constructor
             */
            void __construct();

            /**
             * Sets the text of the label of the button to str 
             *
             * https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-set-label
             */
            void set_label(Php::Parameters &parameters);

            /**
             * Gets the text of the label of the button to str 
             *
             * https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-get-label
             */
            Php::Value get_label();

            /**
             * Creates a GtkButton widget with a GtkLabel child containing the given text.
             *
             * https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-new-with-label
             */
            static Php::Value new_with_label(Php::Parameters &parameters);

            /**
             * Creates a new GtkButton containing a label. If characters in label are preceded by an underscore, they are underlined.
             *
             * https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-new-with-mnemonic
             */
            static Php::Value new_with_mnemonic(Php::Parameters &parameters);

            /**
             * Emits a "clicked" signal to the given GtkButton.
             */
            void clicked();

            /**
             * If true, an underline in the text of the button label indicates the next character should be used for the mnemonic accelerator key.
             *
             * https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-set-use-underline
             */
            void set_use_underline(Php::Parameters &parameters);

            /**
             * Returns whether an embedded underline in the button label indicates a mnemonic
             *
             * https://developer.gnome.org/gtk3/stable/GtkButton.html#gtk-button-get-use-underline
             */
            Php::Value get_use_underline();
    };

#endif