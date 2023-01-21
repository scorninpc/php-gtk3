
#include "GtkStyleContext.h"

/**
 * Constructor
 */
GtkStyleContext_::GtkStyleContext_() = default;

/**
 * Destructor
 */
GtkStyleContext_::~GtkStyleContext_() = default;

void GtkStyleContext_::__construct()
{
	instance = (gpointer *)gtk_style_context_new ();

}

void GtkStyleContext_::add_provider(Php::Parameters &parameters)
{
	GtkCssProvider *provider;
	if(parameters.size() > 0) {
		Php::Value object_provider = parameters[0];
		GtkCssProvider_ *phpgtk_provider = (GtkCssProvider_ *)object_provider.implementation();
		provider = GTK_CSS_PROVIDER(phpgtk_provider->get_instance());
	}

	guint priority = (int)parameters[1];

	gtk_style_context_add_provider (GTK_STYLE_CONTEXT(instance), GTK_STYLE_PROVIDER(provider), priority);

}

void GtkStyleContext_::add_provider_for_screen(Php::Parameters &parameters)
{
	GtkCssProvider *provider;
	if(parameters.size() > 0) {
		Php::Value object_provider = parameters[0];
		GtkCssProvider_ *phpgtk_provider = (GtkCssProvider_ *)object_provider.implementation();
		provider = GTK_CSS_PROVIDER(phpgtk_provider->get_instance());
	}

	guint priority = (int)parameters[1];

	GdkScreen *screen = gdk_screen_get_default();

	gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

}

void GtkStyleContext_::get(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;


	// gtk_style_context_get (GTK_STYLE_CONTEXT(instance), state, );
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

Php::Value GtkStyleContext_::get_direction()
{
	// GtkTextDirection *ret = gtk_style_context_get_direction (GTK_STYLE_CONTEXT(instance));

	// GtkTextDirection_ *return_parsed = new GtkTextDirection_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkTextDirection", return_parsed);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::get_junction_sides()
{
	// GtkJunctionSides *ret = gtk_style_context_get_junction_sides (GTK_STYLE_CONTEXT(instance));

	// GtkJunctionSides_ *return_parsed = new GtkJunctionSides_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkJunctionSides", return_parsed);


	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::get_parent()
{
	// GtkStyleContext *ret = gtk_style_context_get_parent (GTK_STYLE_CONTEXT(instance));

	// GtkStyleContext_ *return_parsed = new GtkStyleContext_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkStyleContext", return_parsed);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::get_path()
{
	// GtkWidgetPath *ret = gtk_style_context_get_path (GTK_STYLE_CONTEXT(instance));

	// GtkWidgetPath_ *return_parsed = new GtkWidgetPath_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidgetPath", return_parsed);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::get_property(Php::Parameters &parameters)
{
	// std::string s_property = parameters[0];
	// gchar *property = (gchar *)s_property.c_str();

	// int int_state = (int)parameters[1];
	// GtkStateFlags state = (GtkStateFlags)int_state;


	// gtk_style_context_get_property (GTK_STYLE_CONTEXT(instance), property, state, value);


	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
}

Php::Value GtkStyleContext_::get_screen()
{
	GdkScreen *ret = gtk_style_context_get_screen (GTK_STYLE_CONTEXT(instance));

	GdkScreen_ *returnValue = new GdkScreen_();
    returnValue->set_instance(ret);

    return Php::Object("GdkScreen", returnValue);
}

Php::Value GtkStyleContext_::get_frame_clock()
{
	// GdkFrameClock ret = gtk_style_context_get_frame_clock (GTK_STYLE_CONTEXT(instance));

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::get_state()
{
	// GtkStateFlags ret = gtk_style_context_get_state (GTK_STYLE_CONTEXT(instance));

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::get_style(Php::Parameters &parameters)
{

	// gtk_style_context_get_style (GTK_STYLE_CONTEXT(instance), );

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_style_property(Php::Parameters &parameters)
{
	// std::string s_property_name = parameters[0];
	// gchar *property_name = (gchar *)s_property_name.c_str();


	// gtk_style_context_get_style_property (GTK_STYLE_CONTEXT(instance), property_name, value);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_style_valist(Php::Parameters &parameters)
{

	// gtk_style_context_get_style_valist (GTK_STYLE_CONTEXT(instance), args);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_valist(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;


	// gtk_style_context_get_valist (GTK_STYLE_CONTEXT(instance), state, args);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

Php::Value GtkStyleContext_::get_section(Php::Parameters &parameters)
{
	// std::string s_property = parameters[0];
	// gchar *property = (gchar *)s_property.c_str();

	// GtkCssSection *ret = gtk_style_context_get_section (GTK_STYLE_CONTEXT(instance), property);

	// GtkCssSection_ *return_parsed = new GtkCssSection_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkCssSection", return_parsed);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::get_color(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;

	// GdkRGBA *color;
	// if(parameters.size() > 1) {
	// 	Php::Value object_color = parameters[1];
	// 	GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
	// 	color = GTK_WIDGET(phpgtk_color->get_instance());
	// }

	// gtk_style_context_get_color (GTK_STYLE_CONTEXT(instance), state, color);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_background_color(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;

	// GdkRGBA *color;
	// if(parameters.size() > 1) {
	// 	Php::Value object_color = parameters[1];
	// 	GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
	// 	color = GTK_WIDGET(phpgtk_color->get_instance());
	// }

	// gtk_style_context_get_background_color (GTK_STYLE_CONTEXT(instance), state, color);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_border_color(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;

	// GdkRGBA *color;
	// if(parameters.size() > 1) {
	// 	Php::Value object_color = parameters[1];
	// 	GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
	// 	color = GTK_WIDGET(phpgtk_color->get_instance());
	// }

	// gtk_style_context_get_border_color (GTK_STYLE_CONTEXT(instance), state, color);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_border(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;

	// GtkBorder *border;
	// if(parameters.size() > 1) {
	// 	Php::Value object_border = parameters[1];
	// 	GtkBorder_ *phpgtk_border = (GtkBorder_ *)object_border.implementation();
	// 	border = GTK_WIDGET(phpgtk_border->get_instance());
	// }

	// gtk_style_context_get_border (GTK_STYLE_CONTEXT(instance), state, border);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_padding(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;

	// GtkBorder *padding;
	// if(parameters.size() > 1) {
	// 	Php::Value object_padding = parameters[1];
	// 	GtkBorder_ *phpgtk_padding = (GtkBorder_ *)object_padding.implementation();
	// 	padding = GTK_WIDGET(phpgtk_padding->get_instance());
	// }

	// gtk_style_context_get_padding (GTK_STYLE_CONTEXT(instance), state, padding);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::get_margin(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;

	// GtkBorder *margin;
	// if(parameters.size() > 1) {
	// 	Php::Value object_margin = parameters[1];
	// 	GtkBorder_ *phpgtk_margin = (GtkBorder_ *)object_margin.implementation();
	// 	margin = GTK_WIDGET(phpgtk_margin->get_instance());
	// }

	// gtk_style_context_get_margin (GTK_STYLE_CONTEXT(instance), state, margin);
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

Php::Value GtkStyleContext_::get_font(Php::Parameters &parameters)
{
	// int int_state = (int)parameters[0];
	// GtkStateFlags state = (GtkStateFlags)int_state;

	// PangoFontDescription ret = gtk_style_context_get_font (GTK_STYLE_CONTEXT(instance), state);

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::invalidate()
{
	// gtk_style_context_invalidate (GTK_STYLE_CONTEXT(instance));

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

Php::Value GtkStyleContext_::state_is_running(Php::Parameters &parameters)
{
	// GtkStateType *state;
	// if(parameters.size() > 0) {
	// 	Php::Value object_state = parameters[0];
	// 	GtkStateType_ *phpgtk_state = (GtkStateType_ *)object_state.implementation();
	// 	state = GTK_WIDGET(phpgtk_state->get_instance());
	// }

	// gdouble progress = (gdouble)parameters[1];

	// gboolean ret = gtk_style_context_state_is_running (GTK_STYLE_CONTEXT(instance), state, progress);

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::lookup_color(Php::Parameters &parameters)
{
	// std::string s_color_name = parameters[0];
	// gchar *color_name = (gchar *)s_color_name.c_str();

	// GdkRGBA *color;
	// if(parameters.size() > 1) {
	// 	Php::Value object_color = parameters[1];
	// 	GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
	// 	color = GTK_WIDGET(phpgtk_color->get_instance());
	// }

	// gboolean ret = gtk_style_context_lookup_color (GTK_STYLE_CONTEXT(instance), color_name, color);

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::lookup_icon_set(Php::Parameters &parameters)
{
	// std::string s_stock_id = parameters[0];
	// gchar *stock_id = (gchar *)s_stock_id.c_str();

	// GtkIconSet *ret = gtk_style_context_lookup_icon_set (GTK_STYLE_CONTEXT(instance), stock_id);

	// GtkIconSet_ *return_parsed = new GtkIconSet_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkIconSet", return_parsed);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::notify_state_change(Php::Parameters &parameters)
{
	// GdkWindow *window;
	// if(parameters.size() > 0) {
	// 	Php::Value object_window = parameters[0];
	// 	GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
	// 	window = GTK_WIDGET(phpgtk_window->get_instance());
	// }

	// gpointer region_id = (gpointer)parameters[1];

	// GtkStateType *state;
	// if(parameters.size() > 2) {
	// 	Php::Value object_state = parameters[2];
	// 	GtkStateType_ *phpgtk_state = (GtkStateType_ *)object_state.implementation();
	// 	state = GTK_WIDGET(phpgtk_state->get_instance());
	// }

	// gboolean state_value = (gboolean)parameters[3];

	// gtk_style_context_notify_state_change (GTK_STYLE_CONTEXT(instance), window, region_id, state, state_value);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::pop_animatable_region()
{
	// gtk_style_context_pop_animatable_region (GTK_STYLE_CONTEXT(instance));

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::push_animatable_region(Php::Parameters &parameters)
{
	// gpointer region_id = (gpointer)parameters[0];

	// gtk_style_context_push_animatable_region (GTK_STYLE_CONTEXT(instance), region_id);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::cancel_animations(Php::Parameters &parameters)
{
	// gpointer region_id = (gpointer)parameters[0];

	// gtk_style_context_cancel_animations (GTK_STYLE_CONTEXT(instance), region_id);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::scroll_animations(Php::Parameters &parameters)
{
	// GdkWindow *window;
	// if(parameters.size() > 0) {
	// 	Php::Value object_window = parameters[0];
	// 	GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
	// 	window = GTK_WIDGET(phpgtk_window->get_instance());
	// }

	// gint dx = (gint)parameters[1];

	// gint dy = (gint)parameters[2];

	// gtk_style_context_scroll_animations (GTK_STYLE_CONTEXT(instance), window, dx, dy);


	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
}

void GtkStyleContext_::remove_provider(Php::Parameters &parameters)
{
	// GtkStyleProvider *provider;
	// if(parameters.size() > 0) {
	// 	Php::Value object_provider = parameters[0];
	// 	GtkStyleProvider_ *phpgtk_provider = (GtkStyleProvider_ *)object_provider.implementation();
	// 	provider = GTK_WIDGET(phpgtk_provider->get_instance());
	// }

	// gtk_style_context_remove_provider (GTK_STYLE_CONTEXT(instance), provider);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::remove_provider_for_screen(Php::Parameters &parameters)
{
	// GtkStyleProvider *provider;
	// if(parameters.size() > 0) {
	// 	Php::Value object_provider = parameters[0];
	// 	GtkStyleProvider_ *phpgtk_provider = (GtkStyleProvider_ *)object_provider.implementation();
	// 	provider = GTK_WIDGET(phpgtk_provider->get_instance());
	// }

	// gtk_style_context_remove_provider_for_screen (GTK_STYLE_CONTEXT(instance), provider);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::reset_widgets()
{
	// gtk_style_context_reset_widgets (GTK_STYLE_CONTEXT(instance));

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::set_background(Php::Parameters &parameters)
{
	// GdkWindow *window;
	// if(parameters.size() > 0) {
	// 	Php::Value object_window = parameters[0];
	// 	GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
	// 	window = GTK_WIDGET(phpgtk_window->get_instance());
	// }

	// gtk_style_context_set_background (GTK_STYLE_CONTEXT(instance), window);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
}

void GtkStyleContext_::restore()
{
	// gtk_style_context_restore (GTK_STYLE_CONTEXT(instance));
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::save()
{
	// gtk_style_context_save (GTK_STYLE_CONTEXT(instance));
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::set_direction(Php::Parameters &parameters)
{
	// GtkTextDirection *direction;
	// if(parameters.size() > 0) {
	// 	Php::Value object_direction = parameters[0];
	// 	GtkTextDirection_ *phpgtk_direction = (GtkTextDirection_ *)object_direction.implementation();
	// 	direction = GTK_WIDGET(phpgtk_direction->get_instance());
	// }

	// gtk_style_context_set_direction (GTK_STYLE_CONTEXT(instance), direction);
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::set_junction_sides(Php::Parameters &parameters)
{
	// GtkJunctionSides *sides;
	// if(parameters.size() > 0) {
	// 	Php::Value object_sides = parameters[0];
	// 	GtkJunctionSides_ *phpgtk_sides = (GtkJunctionSides_ *)object_sides.implementation();
	// 	sides = GTK_WIDGET(phpgtk_sides->get_instance());
	// }

	// gtk_style_context_set_junction_sides (GTK_STYLE_CONTEXT(instance), sides);
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::set_parent(Php::Parameters &parameters)
{
	// GtkStyleContext *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkStyleContext_ *phpgtk_parent = (GtkStyleContext_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// gtk_style_context_set_parent (GTK_STYLE_CONTEXT(instance), parent);
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::set_path(Php::Parameters &parameters)
{
	// GtkWidgetPath *path;
	// if(parameters.size() > 0) {
	// 	Php::Value object_path = parameters[0];
	// 	GtkWidgetPath_ *phpgtk_path = (GtkWidgetPath_ *)object_path.implementation();
	// 	path = GTK_WIDGET(phpgtk_path->get_instance());
	// }

	// gtk_style_context_set_path (GTK_STYLE_CONTEXT(instance), path);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::add_class(Php::Parameters &parameters)
{
	std::string s_class_name = parameters[0];
	gchar *class_name = (gchar *)s_class_name.c_str();

	gtk_style_context_add_class (GTK_STYLE_CONTEXT(instance), class_name);
}

void GtkStyleContext_::remove_class(Php::Parameters &parameters)
{
	std::string s_class_name = parameters[0];
	gchar *class_name = (gchar *)s_class_name.c_str();

	gtk_style_context_remove_class (GTK_STYLE_CONTEXT(instance), class_name);
}

Php::Value GtkStyleContext_::has_class(Php::Parameters &parameters)
{
	// std::string s_class_name = parameters[0];
	// gchar *class_name = (gchar *)s_class_name.c_str();

	// gboolean ret = gtk_style_context_has_class (GTK_STYLE_CONTEXT(instance), class_name);

	// return ret;
	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::list_classes()
{
	// GList ret = gtk_style_context_list_classes (GTK_STYLE_CONTEXT(instance));

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::add_region(Php::Parameters &parameters)
{
	// std::string s_region_name = parameters[0];
	// gchar *region_name = (gchar *)s_region_name.c_str();

	// GtkRegionFlags *flags;
	// if(parameters.size() > 1) {
	// 	Php::Value object_flags = parameters[1];
	// 	GtkRegionFlags_ *phpgtk_flags = (GtkRegionFlags_ *)object_flags.implementation();
	// 	flags = GTK_WIDGET(phpgtk_flags->get_instance());
	// }

	// gtk_style_context_add_region (GTK_STYLE_CONTEXT(instance), region_name, flags);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::remove_region(Php::Parameters &parameters)
{
	// std::string s_region_name = parameters[0];
	// gchar *region_name = (gchar *)s_region_name.c_str();

	// gtk_style_context_remove_region (GTK_STYLE_CONTEXT(instance), region_name);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

Php::Value GtkStyleContext_::has_region(Php::Parameters &parameters)
{
	// std::string s_region_name = parameters[0];
	// gchar *region_name = (gchar *)s_region_name.c_str();

	// GtkRegionFlags *flags_return;
	// if(parameters.size() > 1) {
	// 	Php::Value object_flags_return = parameters[1];
	// 	GtkRegionFlags_ *phpgtk_flags_return = (GtkRegionFlags_ *)object_flags_return.implementation();
	// 	flags_return = GTK_WIDGET(phpgtk_flags_return->get_instance());
	// }

	// gboolean ret = gtk_style_context_has_region (GTK_STYLE_CONTEXT(instance), region_name, flags_return);

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::list_regions()
{
	// GList ret = gtk_style_context_list_regions (GTK_STYLE_CONTEXT(instance));

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::set_screen(Php::Parameters &parameters)
{
	// GdkScreen *screen;
	// if(parameters.size() > 0) {
	// 	Php::Value object_screen = parameters[0];
	// 	GdkScreen_ *phpgtk_screen = (GdkScreen_ *)object_screen.implementation();
	// 	screen = GTK_WIDGET(phpgtk_screen->get_instance());
	// }

	// gtk_style_context_set_screen (GTK_STYLE_CONTEXT(instance), screen);


	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
}

void GtkStyleContext_::set_frame_clock(Php::Parameters &parameters)
{
	// GdkFrameClock *frame_clock;
	// if(parameters.size() > 0) {
	// 	Php::Value object_frame_clock = parameters[0];
	// 	GdkFrameClock_ *phpgtk_frame_clock = (GdkFrameClock_ *)object_frame_clock.implementation();
	// 	frame_clock = GTK_WIDGET(phpgtk_frame_clock->get_instance());
	// }

	// gtk_style_context_set_frame_clock (GTK_STYLE_CONTEXT(instance), frame_clock);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::set_state(Php::Parameters &parameters)
{
	// int int_flags = (int)parameters[0];
	// GtkStateFlags flags = (GtkStateFlags)int_flags;

	// gtk_style_context_set_state (GTK_STYLE_CONTEXT(instance), flags);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::set_scale(Php::Parameters &parameters)
{
	// gint scale = (gint)parameters[0];

	// gtk_style_context_set_scale (GTK_STYLE_CONTEXT(instance), scale);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

Php::Value GtkStyleContext_::get_scale()
{
	// gint ret = gtk_style_context_get_scale (GTK_STYLE_CONTEXT(instance));

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::to_string(Php::Parameters &parameters)
{
	// GtkStyleContextPrintFlags *flags;
	// if(parameters.size() > 0) {
	// 	Php::Value object_flags = parameters[0];
	// 	GtkStyleContextPrintFlags_ *phpgtk_flags = (GtkStyleContextPrintFlags_ *)object_flags.implementation();
	// 	flags = GTK_WIDGET(phpgtk_flags->get_instance());
	// }

	// char ret = gtk_style_context_to_string (GTK_STYLE_CONTEXT(instance), flags);

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::gtk_border_new()
{
	// GtkBorder *ret = gtk_border_new (GTK_STYLE_CONTEXT(instance));

	// GtkBorder_ *return_parsed = new GtkBorder_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkBorder", return_parsed);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

Php::Value GtkStyleContext_::gtk_border_copy()
{
	// GtkBorder *ret = gtk_border_copy (GTK_STYLE_CONTEXT(instance));

	// GtkBorder_ *return_parsed = new GtkBorder_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkBorder", return_parsed);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::gtk_border_free()
{
	// gtk_border_free (GTK_STYLE_CONTEXT(instance));

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_arrow(Php::Parameters &parameters)
{

	// gdouble angle = (gdouble)parameters[1];

	// gdouble x = (gdouble)parameters[2];

	// gdouble y = (gdouble)parameters[3];

	// gdouble size = (gdouble)parameters[4];

	// gtk_render_arrow (GTK_STYLE_CONTEXT(instance), cr, angle, x, y, size);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_background(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_background (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_background_get_clip(Php::Parameters &parameters)
{
	// gdouble x = (gdouble)parameters[0];

	// gdouble y = (gdouble)parameters[1];

	// gdouble width = (gdouble)parameters[2];

	// gdouble height = (gdouble)parameters[3];

	// GdkRectangle *out_clip;
	// if(parameters.size() > 4) {
	// 	Php::Value object_out_clip = parameters[4];
	// 	GdkRectangle_ *phpgtk_out_clip = (GdkRectangle_ *)object_out_clip.implementation();
	// 	out_clip = GTK_WIDGET(phpgtk_out_clip->get_instance());
	// }

	// gtk_render_background_get_clip (GTK_STYLE_CONTEXT(instance), x, y, width, height, out_clip);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_check(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_check (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_expander(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_expander (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_extension(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// GtkPositionType *gap_side;
	// if(parameters.size() > 5) {
	// 	Php::Value object_gap_side = parameters[5];
	// 	GtkPositionType_ *phpgtk_gap_side = (GtkPositionType_ *)object_gap_side.implementation();
	// 	gap_side = GTK_WIDGET(phpgtk_gap_side->get_instance());
	// }

	// gtk_render_extension (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height, gap_side);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_focus(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_focus (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
}

void GtkStyleContext_::gtk_render_frame(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_frame (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_frame_gap(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// GtkPositionType *gap_side;
	// if(parameters.size() > 5) {
	// 	Php::Value object_gap_side = parameters[5];
	// 	GtkPositionType_ *phpgtk_gap_side = (GtkPositionType_ *)object_gap_side.implementation();
	// 	gap_side = GTK_WIDGET(phpgtk_gap_side->get_instance());
	// }

	// gdouble xy0_gap = (gdouble)parameters[6];

	// gdouble xy1_gap = (gdouble)parameters[7];

	// gtk_render_frame_gap (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height, gap_side, xy0_gap, xy1_gap);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_handle(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_handle (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_layout(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];


	// gtk_render_layout (GTK_STYLE_CONTEXT(instance), cr, x, y, layout);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_line(Php::Parameters &parameters)
{

	// gdouble x0 = (gdouble)parameters[1];

	// gdouble y0 = (gdouble)parameters[2];

	// gdouble x1 = (gdouble)parameters[3];

	// gdouble y1 = (gdouble)parameters[4];

	// gtk_render_line (GTK_STYLE_CONTEXT(instance), cr, x0, y0, x1, y1);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_option(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_option (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_slider(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// GtkOrientation *orientation;
	// if(parameters.size() > 5) {
	// 	Php::Value object_orientation = parameters[5];
	// 	GtkOrientation_ *phpgtk_orientation = (GtkOrientation_ *)object_orientation.implementation();
	// 	orientation = GTK_WIDGET(phpgtk_orientation->get_instance());
	// }

	// gtk_render_slider (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height, orientation);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_activity(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];

	// gdouble width = (gdouble)parameters[3];

	// gdouble height = (gdouble)parameters[4];

	// gtk_render_activity (GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

Php::Value GtkStyleContext_::gtk_render_icon_pixbuf(Php::Parameters &parameters)
{
	// GtkIconSource *source;
	// if(parameters.size() > 0) {
	// 	Php::Value object_source = parameters[0];
	// 	GtkIconSource_ *phpgtk_source = (GtkIconSource_ *)object_source.implementation();
	// 	source = GTK_WIDGET(phpgtk_source->get_instance());
	// }

	// GtkIconSize *size;
	// if(parameters.size() > 1) {
	// 	Php::Value object_size = parameters[1];
	// 	GtkIconSize_ *phpgtk_size = (GtkIconSize_ *)object_size.implementation();
	// 	size = GTK_WIDGET(phpgtk_size->get_instance());
	// }

	// GdkPixbuf ret = gtk_render_icon_pixbuf (GTK_STYLE_CONTEXT(instance), source, size);

	// return ret;

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");
	return 1;
}

void GtkStyleContext_::gtk_render_icon_surface(Php::Parameters &parameters)
{


	// gdouble x = (gdouble)parameters[2];

	// gdouble y = (gdouble)parameters[3];

	// gtk_render_icon_surface (GTK_STYLE_CONTEXT(instance), cr, surface, x, y);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_icon(Php::Parameters &parameters)
{

	// GdkPixbuf *pixbuf;
	// if(parameters.size() > 1) {
	// 	Php::Value object_pixbuf = parameters[1];
	// 	GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
	// 	pixbuf = GTK_WIDGET(phpgtk_pixbuf->get_instance());
	// }

	// gdouble x = (gdouble)parameters[2];

	// gdouble y = (gdouble)parameters[3];

	// gtk_render_icon (GTK_STYLE_CONTEXT(instance), cr, pixbuf, x, y);

	throw Php::Exception("GtkStyleContext_::gtk_render_icon not implemented");

}

void GtkStyleContext_::gtk_render_insertion_cursor(Php::Parameters &parameters)
{

	// gdouble x = (gdouble)parameters[1];

	// gdouble y = (gdouble)parameters[2];




	// gtk_render_insertion_cursor (GTK_STYLE_CONTEXT(instance), cr, x, y, layout, index, direction);

	throw Php::Exception("GtkStyleContext_::gtk_render_insertion_cursor not implemented");

}

