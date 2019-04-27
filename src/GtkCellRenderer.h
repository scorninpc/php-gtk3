
#ifndef _PHPGTK_GTKCELLRENDERER_H_
#define _PHPGTK_GTKCELLRENDERER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkCellRenderer_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkCellRenderer.html
     */
    class GtkCellRenderer_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GtkCellRenderer *renderer;

            /**
             * Return original GtkCellRenderer
             */
            GtkCellRenderer *get_renderer();

            /**
             * Set the original GtkCellRenderer
             */
            void set_renderer(GtkCellRenderer *renderer);

            /**
             *  C++ constructor and destructor
             */
            GtkCellRenderer_();
            ~GtkCellRenderer_();

            /**
             * PHP Construct
             */
            void __construct(Php::Parameters &parameters);
    };

#endif