
#ifndef _PHPGTK_GTKCELLRENDERERTOGGLE_H_
#define _PHPGTK_GTKCELLRENDERERTOGGLE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    #include "GtkCellRenderer.h"

    /**
     * GtkCellRendererToggle_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html
     */
    class GtkCellRendererToggle_ : public GtkCellRenderer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkCellRendererToggle_();
            ~GtkCellRendererToggle_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);

            /**
             * Activates or deactivates a cell renderer.
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html#gtk-cell-renderer-toggle-set-active
             */
            void set_activatable(Php::Parameters &parameters);

            /**
             * Returns whether the cell renderer is active
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html#gtk-cell-renderer-toggle-get-active
             */
            Php::Value get_activatable();

            /**
             * If radio is TRUE, the cell renderer renders a radio toggle
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html#gtk-cell-renderer-toggle-set-radio
             */
            void set_radio(Php::Parameters &parameters);

            /**
             * Returns whether we’re rendering radio toggles rather than checkboxes.
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html#gtk-cell-renderer-toggle-get-radio
             */
            Php::Value get_radio();

            /**
             * Activates or deactivates a cell renderer.
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html#gtk-cell-renderer-toggle-set-radio
             */
            void set_active(Php::Parameters &parameters);

            /**
             * Returns whether the cell renderer is active.
             *
             * https://developer.gnome.org/gtk3/stable/GtkCellRendererToggle.html#gtk-cell-renderer-toggle-get-radio
             */
            Php::Value get_active();

    };

#endif