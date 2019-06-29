
#ifndef _PHPGTK_GTKSTYLECONTEXT_H_
#define _PHPGTK_GTKSTYLECONTEXT_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GObject.h"
    #include "GtkCssProvider.h"

    /**
     * GtkStyleContext_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkStyleContext.html
     */
    class GtkStyleContext_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkStyleContext_();
            ~GtkStyleContext_();

            void __construct();

            void add_provider(Php::Parameters &parameters);

            void add_provider_for_screen(Php::Parameters &parameters);

            void get(Php::Parameters &parameters);

            Php::Value get_direction();

            Php::Value get_junction_sides();

            Php::Value get_parent();

            Php::Value get_path();

            void get_property(Php::Parameters &parameters);

            Php::Value get_screen();

            Php::Value get_frame_clock();

            Php::Value get_state();

            void get_style(Php::Parameters &parameters);

            void get_style_property(Php::Parameters &parameters);

            void get_style_valist(Php::Parameters &parameters);

            void get_valist(Php::Parameters &parameters);

            Php::Value get_section(Php::Parameters &parameters);

            void get_color(Php::Parameters &parameters);

            void get_background_color(Php::Parameters &parameters);

            void get_border_color(Php::Parameters &parameters);

            void get_border(Php::Parameters &parameters);

            void get_padding(Php::Parameters &parameters);

            void get_margin(Php::Parameters &parameters);

            Php::Value get_font(Php::Parameters &parameters);

            void invalidate();

            Php::Value state_is_running(Php::Parameters &parameters);

            Php::Value lookup_color(Php::Parameters &parameters);

            Php::Value lookup_icon_set(Php::Parameters &parameters);

            void notify_state_change(Php::Parameters &parameters);

            void pop_animatable_region();

            void push_animatable_region(Php::Parameters &parameters);

            void cancel_animations(Php::Parameters &parameters);

            void scroll_animations(Php::Parameters &parameters);

            void remove_provider(Php::Parameters &parameters);

            void remove_provider_for_screen(Php::Parameters &parameters);

            void reset_widgets();

            void set_background(Php::Parameters &parameters);

            void restore();

            void save();

            void set_direction(Php::Parameters &parameters);

            void set_junction_sides(Php::Parameters &parameters);

            void set_parent(Php::Parameters &parameters);

            void set_path(Php::Parameters &parameters);

            void add_class(Php::Parameters &parameters);

            void remove_class(Php::Parameters &parameters);

            Php::Value has_class(Php::Parameters &parameters);

            Php::Value list_classes();

            void add_region(Php::Parameters &parameters);

            void remove_region(Php::Parameters &parameters);

            Php::Value has_region(Php::Parameters &parameters);

            Php::Value list_regions();

            void set_screen(Php::Parameters &parameters);

            void set_frame_clock(Php::Parameters &parameters);

            void set_state(Php::Parameters &parameters);

            void set_scale(Php::Parameters &parameters);

            Php::Value get_scale();

            Php::Value to_string(Php::Parameters &parameters);

            Php::Value gtk_border_new();

            Php::Value gtk_border_copy();

            void gtk_border_free();

            void gtk_render_arrow(Php::Parameters &parameters);

            void gtk_render_background(Php::Parameters &parameters);

            void gtk_render_background_get_clip(Php::Parameters &parameters);

            void gtk_render_check(Php::Parameters &parameters);

            void gtk_render_expander(Php::Parameters &parameters);

            void gtk_render_extension(Php::Parameters &parameters);

            void gtk_render_focus(Php::Parameters &parameters);

            void gtk_render_frame(Php::Parameters &parameters);

            void gtk_render_frame_gap(Php::Parameters &parameters);

            void gtk_render_handle(Php::Parameters &parameters);

            void gtk_render_layout(Php::Parameters &parameters);

            void gtk_render_line(Php::Parameters &parameters);

            void gtk_render_option(Php::Parameters &parameters);

            void gtk_render_slider(Php::Parameters &parameters);

            void gtk_render_activity(Php::Parameters &parameters);

            Php::Value gtk_render_icon_pixbuf(Php::Parameters &parameters);

            void gtk_render_icon_surface(Php::Parameters &parameters);

            void gtk_render_icon(Php::Parameters &parameters);

            void gtk_render_insertion_cursor(Php::Parameters &parameters);
    };

#endif
