
#ifndef _PHPGTK_GTKWIDGET_H_
#define _PHPGTK_GTKWIDGET_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
	#include "../Gdk/GdkEvent.h"
	#include "../Gdk/GdkWindow.h"
	#include "../Gdk/GdkVisual.h"
	#include "../Pango/PangoContext.h"
	#include "GtkWidgetPath.h"
	#include "GtkStyleContext.h"

	#include "../../php-gtk.h"

    /**
     * GtkWidget_
     *
     * https://developer.gnome.org/gtk3/stable/GtkWidget.html
     */
    class GtkWidget_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkWidget_();
            ~GtkWidget_();

            Php::Value __construct(Php::Parameters &parameters);

            void destroy();

            Php::Value in_destruction();

            void destroyed(Php::Parameters &parameters);

            void unparent();

            void show();

            void show_now();

            void hide();

            void show_all();

            void map();

            void unmap();

            void realize();

            void unrealize();

            void draw(Php::Parameters &parameters);

            void queue_draw();

            void queue_resize();

            void queue_resize_no_redraw();

            void queue_allocate();

            Php::Value get_frame_clock();

            Php::Value get_scale_factor();

            Php::Value add_tick_callback(Php::Parameters &parameters);

            void remove_tick_callback(Php::Parameters &parameters);

            void size_request(Php::Parameters &parameters);

            void get_child_requisition(Php::Parameters &parameters);

            void size_allocate(Php::Parameters &parameters);

            void size_allocate_with_baseline(Php::Parameters &parameters);

            void add_accelerator(Php::Parameters &parameters);

            Php::Value remove_accelerator(Php::Parameters &parameters);

            void set_accel_path(Php::Parameters &parameters);

            Php::Value list_accel_closures();

            Php::Value can_activate_accel(Php::Parameters &parameters);

            Php::Value event(Php::Parameters &parameters);

            Php::Value activate();

            void reparent(Php::Parameters &parameters);

            Php::Value intersect(Php::Parameters &parameters);

            Php::Value is_focus();

            void grab_focus();

            void grab_default();

            void set_name(Php::Parameters &parameters);

            Php::Value get_name();

            void set_state(Php::Parameters &parameters);

            void set_sensitive(Php::Parameters &parameters);

            void set_parent(Php::Parameters &parameters);

            void set_parent_window(Php::Parameters &parameters);

            Php::Value get_parent_window();

            void set_events(Php::Parameters &parameters);

            Php::Value get_events();

            void add_events(Php::Parameters &parameters);

            void set_device_events(Php::Parameters &parameters);

            Php::Value get_device_events(Php::Parameters &parameters);

            void add_device_events(Php::Parameters &parameters);

            void set_device_enabled(Php::Parameters &parameters);

            Php::Value get_device_enabled(Php::Parameters &parameters);

            Php::Value get_toplevel();

            Php::Value get_ancestor(Php::Parameters &parameters);

            Php::Value get_visual();

            void set_visual(Php::Parameters &parameters);

            void get_pointer(Php::Parameters &parameters);

            Php::Value is_ancestor(Php::Parameters &parameters);

            Php::Value translate_coordinates(Php::Parameters &parameters);

            Php::Value hide_on_delete();

            void set_style(Php::Parameters &parameters);

            void ensure_style();

            Php::Value get_style();

            void reset_rc_styles();

            Php::Value get_default_style();

            void set_direction(Php::Parameters &parameters);

            Php::Value get_direction();

            void set_default_direction(Php::Parameters &parameters);

            Php::Value get_default_direction();

            void shape_combine_region(Php::Parameters &parameters);

            void input_shape_combine_region(Php::Parameters &parameters);

            void path(Php::Parameters &parameters);

            void class_path(Php::Parameters &parameters);

            Php::Value get_composite_name();

            void override_background_color(Php::Parameters &parameters);

            void override_color(Php::Parameters &parameters);

            void override_font(Php::Parameters &parameters);

            void override_symbolic_color(Php::Parameters &parameters);

            void override_cursor(Php::Parameters &parameters);

            void modify_style(Php::Parameters &parameters);

            Php::Value get_modifier_style();

            void modify_fg(Php::Parameters &parameters);

            void modify_bg(Php::Parameters &parameters);

            void modify_text(Php::Parameters &parameters);

            void modify_base(Php::Parameters &parameters);

            void modify_font(Php::Parameters &parameters);

            void modify_cursor(Php::Parameters &parameters);

            Php::Value create_pango_context();

            Php::Value get_pango_context();

            void set_font_options(Php::Parameters &parameters);

            void set_font_map(Php::Parameters &parameters);

            Php::Value get_font_map();

            Php::Value create_pango_layout(Php::Parameters &parameters);

            Php::Value render_icon(Php::Parameters &parameters);

            Php::Value render_icon_pixbuf(Php::Parameters &parameters);

            void pop_composite_child();

            void push_composite_child();

            void queue_draw_area(Php::Parameters &parameters);

            void queue_draw_region(Php::Parameters &parameters);

            void set_app_paintable(Php::Parameters &parameters);

            void set_double_buffered(Php::Parameters &parameters);

            void set_redraw_on_allocate(Php::Parameters &parameters);

            void set_composite_name(Php::Parameters &parameters);

            Php::Value mnemonic_activate(Php::Parameters &parameters);

            void class_install_style_property(Php::Parameters &parameters);

            void class_install_style_property_parser(Php::Parameters &parameters);

            Php::Value class_find_style_property(Php::Parameters &parameters);

            Php::Value class_list_style_properties(Php::Parameters &parameters);

            Php::Value send_expose(Php::Parameters &parameters);

            Php::Value send_focus_change(Php::Parameters &parameters);

            void style_get(Php::Parameters &parameters);

            void style_get_property(Php::Parameters &parameters);

            void style_get_valist(Php::Parameters &parameters);

            void style_attach();

            void class_set_accessible_type(Php::Parameters &parameters);

            void class_set_accessible_role(Php::Parameters &parameters);

            Php::Value get_accessible();

            Php::Value child_focus(Php::Parameters &parameters);

            void child_notify(Php::Parameters &parameters);

            void freeze_child_notify();

            Php::Value get_child_visible();

            Php::Value get_parent();

            Php::Value get_settings();

            Php::Value get_clipboard(Php::Parameters &parameters);

            Php::Value get_display();

            Php::Value get_root_window();

            Php::Value get_screen();

            Php::Value has_screen();

            Php::Value get_size_request(Php::Parameters &parameters);

            void set_child_visible(Php::Parameters &parameters);

            void set_size_request(Php::Parameters &parameters);

            void thaw_child_notify();

            void set_no_show_all(Php::Parameters &parameters);

            Php::Value get_no_show_all();

            Php::Value list_mnemonic_labels();

            void add_mnemonic_label(Php::Parameters &parameters);

            void remove_mnemonic_label(Php::Parameters &parameters);

            Php::Value is_composited();

            void error_bell();

            Php::Value keynav_failed(Php::Parameters &parameters);

            Php::Value get_tooltip_markup();

            void set_tooltip_markup(Php::Parameters &parameters);

            Php::Value get_tooltip_text();

            void set_tooltip_text(Php::Parameters &parameters);

            Php::Value get_tooltip_window();

            void set_tooltip_window(Php::Parameters &parameters);

            Php::Value get_has_tooltip();

            void set_has_tooltip(Php::Parameters &parameters);

            void trigger_tooltip_query();

            Php::Value get_window();

            void register_window(Php::Parameters &parameters);

            void unregister_window(Php::Parameters &parameters);

            Php::Value gtk_cairo_should_draw_window(Php::Parameters &parameters);

            void gtk_cairo_transform_to_window(Php::Parameters &parameters);

            Php::Value get_allocated_width();

            Php::Value get_allocated_height();

            void get_allocation(Php::Parameters &parameters);

            void set_allocation(Php::Parameters &parameters);

            Php::Value get_allocated_baseline();

            void get_allocated_size(Php::Parameters &parameters);

            void get_clip(Php::Parameters &parameters);

            void set_clip(Php::Parameters &parameters);

            Php::Value get_app_paintable();

            Php::Value get_can_default();

            void set_can_default(Php::Parameters &parameters);

            Php::Value get_can_focus();

            void set_can_focus(Php::Parameters &parameters);

            Php::Value get_focus_on_click();

            void set_focus_on_click(Php::Parameters &parameters);

            Php::Value get_double_buffered();

            Php::Value get_has_window();

            void set_has_window(Php::Parameters &parameters);

            Php::Value get_sensitive();

            Php::Value is_sensitive();

            Php::Value get_state();

            Php::Value get_visible();

            Php::Value is_visible();

            void set_visible(Php::Parameters &parameters);

            void set_state_flags(Php::Parameters &parameters);

            void unset_state_flags(Php::Parameters &parameters);

            Php::Value get_state_flags();

            Php::Value has_default();

            Php::Value has_focus();

            Php::Value has_visible_focus();

            Php::Value has_grab();

            Php::Value has_rc_style();

            Php::Value is_drawable();

            Php::Value is_toplevel();

            void set_window(Php::Parameters &parameters);

            void set_receives_default(Php::Parameters &parameters);

            Php::Value get_receives_default();

            void set_support_multidevice(Php::Parameters &parameters);

            Php::Value get_support_multidevice();

            void set_realized(Php::Parameters &parameters);

            Php::Value get_realized();

            void set_mapped(Php::Parameters &parameters);

            Php::Value get_mapped();

            void get_requisition(Php::Parameters &parameters);

            Php::Value device_is_shadowed(Php::Parameters &parameters);

            Php::Value get_modifier_mask(Php::Parameters &parameters);

            void insert_action_group(Php::Parameters &parameters);

            Php::Value get_opacity();

            void set_opacity(Php::Parameters &parameters);

            Php::Value list_action_prefixes();

            Php::Value get_action_group(Php::Parameters &parameters);

            Php::Value get_path();

            Php::Value get_style_context();

            void reset_style();

            Php::Value class_get_css_name();

            void class_set_css_name(Php::Parameters &parameters);

            Php::Value gtk_requisition_new();

            Php::Value gtk_requisition_copy(Php::Parameters &parameters);

            void gtk_requisition_free();

            Php::Value get_preferred_height(Php::Parameters &parameters);

            Php::Value get_preferred_width(Php::Parameters &parameters);

            Php::Value get_preferred_height_for_width(Php::Parameters &parameters);

            Php::Value get_preferred_width_for_height(Php::Parameters &parameters);

            Php::Value get_preferred_height_and_baseline_for_width(Php::Parameters &parameters);

            Php::Value get_request_mode();

            Php::Value get_preferred_size(Php::Parameters &parameters);

            Php::Value gtk_distribute_natural_allocation(Php::Parameters &parameters);

            Php::Value get_halign();

            void set_halign(Php::Parameters &parameters);

            Php::Value get_valign();

            Php::Value get_valign_with_baseline();

            void set_valign(Php::Parameters &parameters);

            Php::Value get_margin_left();

            void set_margin_left(Php::Parameters &parameters);

            Php::Value get_margin_right();

            void set_margin_right(Php::Parameters &parameters);

            Php::Value get_margin_start();

            void set_margin_start(Php::Parameters &parameters);

            Php::Value get_margin_end();

            void set_margin_end(Php::Parameters &parameters);

            Php::Value get_margin_top();

            void set_margin_top(Php::Parameters &parameters);

            Php::Value get_margin_bottom();

            void set_margin_bottom(Php::Parameters &parameters);

            Php::Value get_hexpand();

            void set_hexpand(Php::Parameters &parameters);

            Php::Value get_hexpand_set();

            void set_hexpand_set(Php::Parameters &parameters);

            Php::Value get_vexpand();

            void set_vexpand(Php::Parameters &parameters);

            Php::Value get_vexpand_set();

            void set_vexpand_set(Php::Parameters &parameters);

            void queue_compute_expand();

            Php::Value compute_expand(Php::Parameters &parameters);

            void init_template();

            void class_set_template(Php::Parameters &parameters);

            void class_set_template_from_resource(Php::Parameters &parameters);

            Php::Value get_template_child(Php::Parameters &parameters);

            void class_bind_template_child_full(Php::Parameters &parameters);

            void class_bind_template_callback_full(Php::Parameters &parameters);

            void class_set_connect_func(Php::Parameters &parameters);

            Php::Value scroll_event(Php::Parameters& parameters);
    };

#endif
