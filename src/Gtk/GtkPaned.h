
#ifndef _PHPGTK_GTKPANED_H_
#define _PHPGTK_GTKPANED_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkContainer.h"
    
	#include "../../php-gtk.h"

    /**
     * GtkPaned_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkPaned.html
     */
    class GtkPaned_ : public GtkContainer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkPaned_();
            ~GtkPaned_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             *  Adds a child to the top or left pane with default parameters.
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-add1
             */
            void add1(Php::Parameters &parameters);

            /**
             *  Adds a child to the bottom or right pane with default parameters.
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-add2
             */
            void add2(Php::Parameters &parameters);

            /**
             * Adds a child to the top or left pane.
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-pack1
             */
            void pack1(Php::Parameters &parameters);

            /**
             * Adds a child to the bottom or right pane.
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-pack2
             */
            void pack2(Php::Parameters &parameters);

            /**
             * Obtains the first child of the paned widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-get-child1
             */
            Php::Value get_child1();

            /**
             * Obtains the second child of the paned widget.
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-get-child2
             */
            Php::Value get_child2();

            /**
             * Sets the position of the divider between the two panes.
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-set-position
             */
            void set_position(Php::Parameters &parameters);

            /**
             * Obtains the position of the divider between the two panes
             *
             * https://developer.gnome.org/gtk3/stable/GtkPaned.html#gtk-paned-get-position
             */
            Php::Value get_position();
    };

#endif