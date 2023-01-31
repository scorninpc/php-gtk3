
#include "GtkWidget.h"
#include "GtkWindow.h"
#include "../Gdk/GdkRGBA.h"

/**
 * Constructor
 */
GtkWidget_::GtkWidget_() = default;

/**
 * Destructor
 */
GtkWidget_::~GtkWidget_() = default;

Php::Value GtkWidget_::__construct(Php::Parameters &parameters)
{
// // 	std::string s_first_property_name = parameters[0];
// 	gchar *first_property_name = (gchar *)s_first_property_name.c_str();

// 	GtkWidget *ret = instance = (gpointer *)gtk_widget_new (first_property_name);

// 	GtkWidget_ *return_parsed = new GtkWidget_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkWidget", return_parsed);
	 throw Php::Exception("GtkWidget_::__construct not implemented");
}

void GtkWidget_::destroy()
{
	gtk_widget_destroy (GTK_WIDGET(instance));

}

Php::Value GtkWidget_::in_destruction()
{
	gboolean ret = gtk_widget_in_destruction (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::destroyed(Php::Parameters &parameters)
{
// // 	GtkWidget *widget_pointer;
// 	if(parameters.size() > 0) {
// 		Php::Value object_widget_pointer = parameters[0];
// 		GtkWidget_ *phpgtk_widget_pointer = (GtkWidget_ *)object_widget_pointer.implementation();
// 		widget_pointer = GTK_WIDGET(phpgtk_widget_pointer->get_instance());
// 	}

// 	gtk_widget_destroyed (GTK_WIDGET(instance), widget_pointer);

	 throw Php::Exception("GtkWidget_::destroyed not implemented");
}

void GtkWidget_::unparent()
{
	gtk_widget_unparent (GTK_WIDGET(instance));

}

void GtkWidget_::show()
{
	gtk_widget_show (GTK_WIDGET(instance));

}

void GtkWidget_::show_now()
{
	gtk_widget_show_now (GTK_WIDGET(instance));

}

void GtkWidget_::hide()
{
	gtk_widget_hide (GTK_WIDGET(instance));

}

void GtkWidget_::show_all()
{
	gtk_widget_show_all (GTK_WIDGET(instance));

}

void GtkWidget_::map()
{
	gtk_widget_map (GTK_WIDGET(instance));

}

void GtkWidget_::unmap()
{
	gtk_widget_unmap (GTK_WIDGET(instance));

}

void GtkWidget_::realize()
{
	gtk_widget_realize (GTK_WIDGET(instance));

}

void GtkWidget_::unrealize()
{
	gtk_widget_unrealize (GTK_WIDGET(instance));

}

void GtkWidget_::draw(Php::Parameters &parameters)
{
// 
// 	gtk_widget_draw (GTK_WIDGET(instance), cr);

	 throw Php::Exception("GtkWidget_::draw not implemented");
}

void GtkWidget_::queue_draw()
{
	gtk_widget_queue_draw (GTK_WIDGET(instance));

}

void GtkWidget_::queue_resize()
{
	gtk_widget_queue_resize (GTK_WIDGET(instance));

}

void GtkWidget_::queue_resize_no_redraw()
{
	gtk_widget_queue_resize_no_redraw (GTK_WIDGET(instance));

}

void GtkWidget_::queue_allocate()
{
	gtk_widget_queue_allocate (GTK_WIDGET(instance));

}

Php::Value GtkWidget_::get_frame_clock()
{
// 	GdkFrameClock ret = gtk_widget_get_frame_clock (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_frame_clock not implemented");
}

Php::Value GtkWidget_::get_scale_factor()
{
	gint ret = gtk_widget_get_scale_factor (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::add_tick_callback(Php::Parameters &parameters)
{
// // 	GtkTickCallback *callback;
// 	if(parameters.size() > 0) {
// 		Php::Value object_callback = parameters[0];
// 		GtkTickCallback_ *phpgtk_callback = (GtkTickCallback_ *)object_callback.implementation();
// 		callback = GTK_WIDGET(phpgtk_callback->get_instance());
// 	}

// // 	gpointer user_data = (gpointer)parameters[1];

// 
// 	int ret = gtk_widget_add_tick_callback (GTK_WIDGET(instance), callback, user_data, notify);

// 	return ret;
	 throw Php::Exception("GtkWidget_::add_tick_callback not implemented");
}

void GtkWidget_::remove_tick_callback(Php::Parameters &parameters)
{
	guint id = (int)parameters[0];

	gtk_widget_remove_tick_callback (GTK_WIDGET(instance), id);

}

void GtkWidget_::size_request(Php::Parameters &parameters)
{
// // 	GtkRequisition *requisition;
// 	if(parameters.size() > 0) {
// 		Php::Value object_requisition = parameters[0];
// 		GtkRequisition_ *phpgtk_requisition = (GtkRequisition_ *)object_requisition.implementation();
// 		requisition = GTK_WIDGET(phpgtk_requisition->get_instance());
// 	}

// 	gtk_widget_size_request (GTK_WIDGET(instance), requisition);

	 Php::deprecated << "GtkWidget_::size_request  is deprecated on Gtk 3.0";
}

void GtkWidget_::get_child_requisition(Php::Parameters &parameters)
{
// // 	GtkRequisition *requisition;
// 	if(parameters.size() > 0) {
// 		Php::Value object_requisition = parameters[0];
// 		GtkRequisition_ *phpgtk_requisition = (GtkRequisition_ *)object_requisition.implementation();
// 		requisition = GTK_WIDGET(phpgtk_requisition->get_instance());
// 	}

// 	gtk_widget_get_child_requisition (GTK_WIDGET(instance), requisition);

	 Php::deprecated << "GtkWidget_::get_child_requisition  is deprecated on Gtk 3.0";
}

void GtkWidget_::size_allocate(Php::Parameters &parameters)
{
// // 	GtkAllocation *allocation;
// 	if(parameters.size() > 0) {
// 		Php::Value object_allocation = parameters[0];
// 		GtkAllocation_ *phpgtk_allocation = (GtkAllocation_ *)object_allocation.implementation();
// 		allocation = GTK_WIDGET(phpgtk_allocation->get_instance());
// 	}

// 	gtk_widget_size_allocate (GTK_WIDGET(instance), allocation);

	 throw Php::Exception("GtkWidget_::size_allocate not implemented");
}

void GtkWidget_::size_allocate_with_baseline(Php::Parameters &parameters)
{
// // 	GtkAllocation *allocation;
// 	if(parameters.size() > 0) {
// 		Php::Value object_allocation = parameters[0];
// 		GtkAllocation_ *phpgtk_allocation = (GtkAllocation_ *)object_allocation.implementation();
// 		allocation = GTK_WIDGET(phpgtk_allocation->get_instance());
// 	}

// // 	gint baseline = (gint)parameters[1];

// 	gtk_widget_size_allocate_with_baseline (GTK_WIDGET(instance), allocation, baseline);

	 throw Php::Exception("GtkWidget_::size_allocate_with_baseline not implemented");
}

void GtkWidget_::add_accelerator(Php::Parameters &parameters)
{
// // 	std::string s_accel_signal = parameters[0];
// 	gchar *accel_signal = (gchar *)s_accel_signal.c_str();

// // 	GtkAccelGroup *accel_group;
// 	if(parameters.size() > 1) {
// 		Php::Value object_accel_group = parameters[1];
// 		GtkAccelGroup_ *phpgtk_accel_group = (GtkAccelGroup_ *)object_accel_group.implementation();
// 		accel_group = GTK_WIDGET(phpgtk_accel_group->get_instance());
// 	}

// // 	guint accel_key = (int)parameters[2];

// // 	GdkModifierType *accel_mods;
// 	if(parameters.size() > 3) {
// 		Php::Value object_accel_mods = parameters[3];
// 		GdkModifierType_ *phpgtk_accel_mods = (GdkModifierType_ *)object_accel_mods.implementation();
// 		accel_mods = GTK_WIDGET(phpgtk_accel_mods->get_instance());
// 	}

// // 	GtkAccelFlags *accel_flags;
// 	if(parameters.size() > 4) {
// 		Php::Value object_accel_flags = parameters[4];
// 		GtkAccelFlags_ *phpgtk_accel_flags = (GtkAccelFlags_ *)object_accel_flags.implementation();
// 		accel_flags = GTK_WIDGET(phpgtk_accel_flags->get_instance());
// 	}

// 	gtk_widget_add_accelerator (GTK_WIDGET(instance), accel_signal, accel_group, accel_key, accel_mods, accel_flags);

	 throw Php::Exception("GtkWidget_::add_accelerator not implemented");
}

Php::Value GtkWidget_::remove_accelerator(Php::Parameters &parameters)
{
// // 	GtkAccelGroup *accel_group;
// 	if(parameters.size() > 0) {
// 		Php::Value object_accel_group = parameters[0];
// 		GtkAccelGroup_ *phpgtk_accel_group = (GtkAccelGroup_ *)object_accel_group.implementation();
// 		accel_group = GTK_WIDGET(phpgtk_accel_group->get_instance());
// 	}

// // 	guint accel_key = (int)parameters[1];

// // 	GdkModifierType *accel_mods;
// 	if(parameters.size() > 2) {
// 		Php::Value object_accel_mods = parameters[2];
// 		GdkModifierType_ *phpgtk_accel_mods = (GdkModifierType_ *)object_accel_mods.implementation();
// 		accel_mods = GTK_WIDGET(phpgtk_accel_mods->get_instance());
// 	}

// 	gboolean ret = gtk_widget_remove_accelerator (GTK_WIDGET(instance), accel_group, accel_key, accel_mods);

// 	return ret;
	 throw Php::Exception("GtkWidget_::remove_accelerator not implemented");
}

void GtkWidget_::set_accel_path(Php::Parameters &parameters)
{
// // 	std::string s_accel_path = parameters[0];
// 	gchar *accel_path = (gchar *)s_accel_path.c_str();

// // 	GtkAccelGroup *accel_group;
// 	if(parameters.size() > 1) {
// 		Php::Value object_accel_group = parameters[1];
// 		GtkAccelGroup_ *phpgtk_accel_group = (GtkAccelGroup_ *)object_accel_group.implementation();
// 		accel_group = GTK_WIDGET(phpgtk_accel_group->get_instance());
// 	}

// 	gtk_widget_set_accel_path (GTK_WIDGET(instance), accel_path, accel_group);

	 throw Php::Exception("GtkWidget_::set_accel_path not implemented");
}

Php::Value GtkWidget_::list_accel_closures()
{
// 	GList ret = gtk_widget_list_accel_closures (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::list_accel_closures not implemented");
}

Php::Value GtkWidget_::can_activate_accel(Php::Parameters &parameters)
{
	guint signal_id = (int)parameters[0];

	gboolean ret = gtk_widget_can_activate_accel (GTK_WIDGET(instance), signal_id);

	return ret;
}

Php::Value GtkWidget_::event(Php::Parameters &parameters)
{
// // 	GdkEvent *event;
// 	if(parameters.size() > 0) {
// 		Php::Value object_event = parameters[0];
// 		GdkEvent_ *phpgtk_event = (GdkEvent_ *)object_event.implementation();
// 		event = GDK_EVENT(phpgtk_event->get_instance());
// 	}

// 	gboolean ret = gtk_widget_event (GTK_WIDGET(instance), event);

// 	return ret;
	 throw Php::Exception("GtkWidget_::event not implemented");
}

Php::Value GtkWidget_::activate()
{
	gboolean ret = gtk_widget_activate (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::reparent(Php::Parameters &parameters)
{
// // 	GtkWidget *new_parent;
// 	if(parameters.size() > 0) {
// 		Php::Value object_new_parent = parameters[0];
// 		GtkWidget_ *phpgtk_new_parent = (GtkWidget_ *)object_new_parent.implementation();
// 		new_parent = GTK_WIDGET(phpgtk_new_parent->get_instance());
// 	}

// 	gtk_widget_reparent (GTK_WIDGET(instance), new_parent);

	 Php::deprecated << "GtkWidget_::reparent  is deprecated on Gtk 3.14";
}

Php::Value GtkWidget_::intersect(Php::Parameters &parameters)
{
// // 	GdkRectangle *area;
// 	if(parameters.size() > 0) {
// 		Php::Value object_area = parameters[0];
// 		GdkRectangle_ *phpgtk_area = (GdkRectangle_ *)object_area.implementation();
// 		area = GTK_WIDGET(phpgtk_area->get_instance());
// 	}

// // 	GdkRectangle *intersection;
// 	if(parameters.size() > 1) {
// 		Php::Value object_intersection = parameters[1];
// 		GdkRectangle_ *phpgtk_intersection = (GdkRectangle_ *)object_intersection.implementation();
// 		intersection = GTK_WIDGET(phpgtk_intersection->get_instance());
// 	}

// 	gboolean ret = gtk_widget_intersect (GTK_WIDGET(instance), area, intersection);

// 	return ret;
	 throw Php::Exception("GtkWidget_::intersect not implemented");
}

Php::Value GtkWidget_::is_focus()
{
	gboolean ret = gtk_widget_is_focus (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::grab_focus()
{
	gtk_widget_grab_focus (GTK_WIDGET(instance));

}

void GtkWidget_::grab_default()
{
	gtk_widget_grab_default (GTK_WIDGET(instance));

}

void GtkWidget_::set_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_widget_set_name (GTK_WIDGET(instance), name);

}

Php::Value GtkWidget_::get_name()
{
	std::string ret = gtk_widget_get_name (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_state(Php::Parameters &parameters)
{
// // 	GtkStateType *state;
// 	if(parameters.size() > 0) {
// 		Php::Value object_state = parameters[0];
// 		GtkStateType_ *phpgtk_state = (GtkStateType_ *)object_state.implementation();
// 		state = GTK_WIDGET(phpgtk_state->get_instance());
// 	}

// 	gtk_widget_set_state (GTK_WIDGET(instance), state);

	 Php::deprecated << "GtkWidget_::set_state  is deprecated on Gtk 3.0";
}

void GtkWidget_::set_sensitive(Php::Parameters &parameters)
{
	gboolean sensitive = (gboolean)parameters[0];

	gtk_widget_set_sensitive (GTK_WIDGET(instance), sensitive);

}

void GtkWidget_::set_parent(Php::Parameters &parameters)
{
	GtkWidget *parent;
	if(parameters.size() > 0) {
		Php::Value object_parent = parameters[0];
		GtkWidget_ *phpgtk_parent = (GtkWidget_ *)object_parent.implementation();
		parent = GTK_WIDGET(phpgtk_parent->get_instance());
	}

	gtk_widget_set_parent (GTK_WIDGET(instance), parent);

}

void GtkWidget_::set_parent_window(Php::Parameters &parameters)
{
	GdkWindow *parent_window;
	if(parameters.size() > 0) {
		Php::Value object_parent_window = parameters[0];
		GdkWindow_ *phpgtk_parent_window = (GdkWindow_ *)object_parent_window.implementation();
		parent_window = GDK_WINDOW(phpgtk_parent_window->get_instance());
	}

	gtk_widget_set_parent_window (GTK_WIDGET(instance), parent_window);

}

Php::Value GtkWidget_::get_parent_window()
{
	GdkWindow *ret = gtk_widget_get_parent_window (GTK_WIDGET(instance));

	GdkWindow_ *return_parsed = new GdkWindow_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GdkWindow", return_parsed);
}

void GtkWidget_::set_events(Php::Parameters &parameters)
{
	gint events = (gint)parameters[0];

	gtk_widget_set_events (GTK_WIDGET(instance), events);

}

Php::Value GtkWidget_::get_events()
{
	gint ret = gtk_widget_get_events (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::add_events(Php::Parameters &parameters)
{
	gint events = (gint)parameters[0];

	gtk_widget_add_events (GTK_WIDGET(instance), events);

}

void GtkWidget_::set_device_events(Php::Parameters &parameters)
{
// // 	GdkDevice *device;
// 	if(parameters.size() > 0) {
// 		Php::Value object_device = parameters[0];
// 		GdkDevice_ *phpgtk_device = (GdkDevice_ *)object_device.implementation();
// 		device = GTK_WIDGET(phpgtk_device->get_instance());
// 	}

// // 	int int_events = (int)parameters[1];
// 	GdkEventMask events = (GdkEventMask)int_events;

// 	gtk_widget_set_device_events (GTK_WIDGET(instance), device, events);

	 throw Php::Exception("GtkWidget_::set_device_events not implemented");
}

Php::Value GtkWidget_::get_device_events(Php::Parameters &parameters)
{
// // 	GdkDevice *device;
// 	if(parameters.size() > 0) {
// 		Php::Value object_device = parameters[0];
// 		GdkDevice_ *phpgtk_device = (GdkDevice_ *)object_device.implementation();
// 		device = GTK_WIDGET(phpgtk_device->get_instance());
// 	}

// 	GdkEventMask ret = gtk_widget_get_device_events (GTK_WIDGET(instance), device);

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_device_events not implemented");
}

void GtkWidget_::add_device_events(Php::Parameters &parameters)
{
// // 	GdkDevice *device;
// 	if(parameters.size() > 0) {
// 		Php::Value object_device = parameters[0];
// 		GdkDevice_ *phpgtk_device = (GdkDevice_ *)object_device.implementation();
// 		device = GTK_WIDGET(phpgtk_device->get_instance());
// 	}

// // 	int int_events = (int)parameters[1];
// 	GdkEventMask events = (GdkEventMask)int_events;

// 	gtk_widget_add_device_events (GTK_WIDGET(instance), device, events);

	 throw Php::Exception("GtkWidget_::add_device_events not implemented");
}

void GtkWidget_::set_device_enabled(Php::Parameters &parameters)
{
// // 	GdkDevice *device;
// 	if(parameters.size() > 0) {
// 		Php::Value object_device = parameters[0];
// 		GdkDevice_ *phpgtk_device = (GdkDevice_ *)object_device.implementation();
// 		device = GTK_WIDGET(phpgtk_device->get_instance());
// 	}

// // 	gboolean enabled = (gboolean)parameters[1];

// 	gtk_widget_set_device_enabled (GTK_WIDGET(instance), device, enabled);

	 throw Php::Exception("GtkWidget_::set_device_enabled not implemented");
}

Php::Value GtkWidget_::get_device_enabled(Php::Parameters &parameters)
{
// // 	GdkDevice *device;
// 	if(parameters.size() > 0) {
// 		Php::Value object_device = parameters[0];
// 		GdkDevice_ *phpgtk_device = (GdkDevice_ *)object_device.implementation();
// 		device = GTK_WIDGET(phpgtk_device->get_instance());
// 	}

// 	gboolean ret = gtk_widget_get_device_enabled (GTK_WIDGET(instance), device);

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_device_enabled not implemented");
}

Php::Value GtkWidget_::get_toplevel()
{
	gpointer *ret = (gpointer *)gtk_widget_get_toplevel (GTK_WIDGET(instance));

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkWidget_::get_ancestor(Php::Parameters &parameters)
{
	// GtkWidget *ret = gtk_widget_get_ancestor (GTK_WIDGET(instance), widget_type);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	throw Php::Exception("GtkWidget_::get_ancestor not implemented");
}

Php::Value GtkWidget_::get_visual()
{
	GdkVisual *ret = gtk_widget_get_visual (GTK_WIDGET(instance));

	GdkVisual_ *return_parsed = new GdkVisual_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GdkVisual", return_parsed);
}

void GtkWidget_::set_visual(Php::Parameters &parameters)
{
	GdkVisual *visual;
	if(parameters.size() > 0) {
		Php::Value object_visual = parameters[0];
		GdkVisual_ *phpgtk_visual = (GdkVisual_ *)object_visual.implementation();
		visual = GDK_VISUAL(phpgtk_visual->get_instance());
	}

	gtk_widget_set_visual (GTK_WIDGET(instance), visual);

}

void GtkWidget_::get_pointer(Php::Parameters &parameters)
{
// // 	gint x = (gint)parameters[0];

// // 	gint y = (gint)parameters[1];

// 	gtk_widget_get_pointer (GTK_WIDGET(instance), x, y);

	 Php::deprecated << "GtkWidget_::get_pointer  is deprecated on Gtk 3.4";
}

Php::Value GtkWidget_::is_ancestor(Php::Parameters &parameters)
{
	GtkWidget *ancestor;
	if(parameters.size() > 0) {
		Php::Value object_ancestor = parameters[0];
		GtkWidget_ *phpgtk_ancestor = (GtkWidget_ *)object_ancestor.implementation();
		ancestor = GTK_WIDGET(phpgtk_ancestor->get_instance());
	}

	gboolean ret = gtk_widget_is_ancestor (GTK_WIDGET(instance), ancestor);

	return ret;
}

Php::Value GtkWidget_::translate_coordinates(Php::Parameters &parameters)
{
	GtkWidget *dest_widget;
	if(parameters.size() > 0) {
		Php::Value object_dest_widget = parameters[0];
		GtkWidget_ *phpgtk_dest_widget = (GtkWidget_ *)object_dest_widget.implementation();
		dest_widget = GTK_WIDGET(phpgtk_dest_widget->get_instance());
	}

	gint src_x = (gint)parameters[1];

	gint src_y = (gint)parameters[2];

	gint dest_x;

	gint dest_y;

	gboolean ret = gtk_widget_translate_coordinates (GTK_WIDGET(instance), dest_widget, src_x, src_y, &dest_x, &dest_y);
	if(!ret) {
		return ret;
	}

	Php::Value arr;
	arr[0] = arr["x"] = (int)dest_x;
	arr[1] = arr["y"] = (int)dest_y;

	return arr;
}

Php::Value GtkWidget_::hide_on_delete()
{
	gboolean ret = gtk_widget_hide_on_delete (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_style(Php::Parameters &parameters)
{
// // 	GtkStyle *style;
// 	if(parameters.size() > 0) {
// 		Php::Value object_style = parameters[0];
// 		GtkStyle_ *phpgtk_style = (GtkStyle_ *)object_style.implementation();
// 		style = GTK_STYLE(phpgtk_style->get_instance());
// 	}

// 	gtk_widget_set_style (GTK_WIDGET(instance), style);

	 Php::deprecated << "GtkWidget_::set_style  is deprecated on Gtk 3.0";
}

void GtkWidget_::ensure_style()
{
// 	gtk_widget_ensure_style (GTK_WIDGET(instance));

	 Php::deprecated << "GtkWidget_::ensure_style  is deprecated on Gtk 3.0";
}

Php::Value GtkWidget_::get_style()
{
// 	GtkStyle *ret = gtk_widget_get_style (GTK_WIDGET(instance));

// 	GtkStyle_ *return_parsed = new GtkStyle_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkStyle", return_parsed);
	 Php::deprecated << "GtkWidget_::get_style  is deprecated on Gtk 3.0";
	 return 1;
}

void GtkWidget_::reset_rc_styles()
{
// 	gtk_widget_reset_rc_styles (GTK_WIDGET(instance));

	 Php::deprecated << "GtkWidget_::reset_rc_styles  is deprecated on Gtk 3.0";
}

Php::Value GtkWidget_::get_default_style()
{
// 	GtkStyle *ret = gtk_widget_get_default_style (GTK_WIDGET(instance));

// 	GtkStyle_ *return_parsed = new GtkStyle_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkStyle", return_parsed);
	 Php::deprecated << "GtkWidget_::get_default_style  is deprecated on Gtk 3.0";
	 return 1;
}

void GtkWidget_::set_direction(Php::Parameters &parameters)
{
	int int_dir = (int)parameters[0];
	GtkTextDirection dir = (GtkTextDirection)int_dir;

	gtk_widget_set_direction (GTK_WIDGET(instance), dir);

}

Php::Value GtkWidget_::get_direction()
{
	GtkTextDirection ret = gtk_widget_get_direction (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_default_direction(Php::Parameters &parameters)
{
	int int_dir = (int)parameters[0];
	GtkTextDirection dir = (GtkTextDirection)int_dir;

	gtk_widget_set_default_direction (dir);

}

Php::Value GtkWidget_::get_default_direction()
{
	GtkTextDirection ret = gtk_widget_get_default_direction ();

	return ret;
}

void GtkWidget_::shape_combine_region(Php::Parameters &parameters)
{
// 
// 	gtk_widget_shape_combine_region (GTK_WIDGET(instance), region);

	 throw Php::Exception("GtkWidget_::shape_combine_region not implemented");
}

void GtkWidget_::input_shape_combine_region(Php::Parameters &parameters)
{
// 
// 	gtk_widget_input_shape_combine_region (GTK_WIDGET(instance), region);

	 throw Php::Exception("GtkWidget_::input_shape_combine_region not implemented");
}

void GtkWidget_::path(Php::Parameters &parameters)
{
// // 	guint path_length = (int)parameters[0];

// // 	std::string s_path = parameters[1];
// 	gchar *path = (gchar *)s_path.c_str();

// // 	std::string s_path_reversed = parameters[2];
// 	gchar *path_reversed = (gchar *)s_path_reversed.c_str();

// 	gtk_widget_path (GTK_WIDGET(instance), path_length, path, path_reversed);

	 Php::deprecated << "GtkWidget_::path  is deprecated on Gtk 3.0";
}

void GtkWidget_::class_path(Php::Parameters &parameters)
{
// // 	guint path_length = (int)parameters[0];

// // 	std::string s_path = parameters[1];
// 	gchar *path = (gchar *)s_path.c_str();

// // 	std::string s_path_reversed = parameters[2];
// 	gchar *path_reversed = (gchar *)s_path_reversed.c_str();

// 	gtk_widget_class_path (GTK_WIDGET(instance), path_length, path, path_reversed);

	 Php::deprecated << "GtkWidget_::class_path  is deprecated on Gtk 3.0";
}

Php::Value GtkWidget_::get_composite_name()
{
// 	std::string ret = gtk_widget_get_composite_name (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::get_composite_name  is deprecated on Gtk 3.10";
	 return 1;
}

void GtkWidget_::override_background_color(Php::Parameters &parameters)
{
 	int int_state = (int)parameters[0];
 	GtkStateFlags state = (GtkStateFlags)int_state;
	// GtkWidget* color;
	GdkRGBA color;

 	if(parameters.size() > 1) {
 		Php::Value object_color = parameters[1];
 		GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
 		color = phpgtk_color->get_instance();
 	}

 	gtk_widget_override_background_color (GTK_WIDGET(instance), state, &color);

	Php::deprecated << "GtkWidget_::override_background_color  is deprecated on Gtk 3.16";
}

void GtkWidget_::override_color(Php::Parameters &parameters)
{
 	int int_state = (int)parameters[0];
	GtkStateFlags state = (GtkStateFlags)int_state;

 	GdkRGBA color;
	if(parameters.size() > 1) {
		Php::Value object_color = parameters[1];
 		GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
 		color = phpgtk_color->get_instance();
 	}

 	gtk_widget_override_color (GTK_WIDGET(instance), state, &color);

    Php::deprecated << "GtkWidget_::override_color  is deprecated on Gtk 3.16";
}

void GtkWidget_::override_font(Php::Parameters &parameters)
{
// 
// 	gtk_widget_override_font (GTK_WIDGET(instance), font_desc);

	 Php::deprecated << "GtkWidget_::override_font  is deprecated on Gtk 3.16";
}

void GtkWidget_::override_symbolic_color(Php::Parameters &parameters)
{
// // 	std::string s_name = parameters[0];
// 	gchar *name = (gchar *)s_name.c_str();

// // 	GdkRGBA *color;
// 	if(parameters.size() > 1) {
// 		Php::Value object_color = parameters[1];
// 		GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
// 		color = GTK_WIDGET(phpgtk_color->get_instance());
// 	}

// 	gtk_widget_override_symbolic_color (GTK_WIDGET(instance), name, color);

	 Php::deprecated << "GtkWidget_::override_symbolic_color  is deprecated on Gtk 3.16";
}

void GtkWidget_::override_cursor(Php::Parameters &parameters)
{
// // 	GdkRGBA *cursor;
// 	if(parameters.size() > 0) {
// 		Php::Value object_cursor = parameters[0];
// 		GdkRGBA_ *phpgtk_cursor = (GdkRGBA_ *)object_cursor.implementation();
// 		cursor = GTK_WIDGET(phpgtk_cursor->get_instance());
// 	}

// // 	GdkRGBA *secondary_cursor;
// 	if(parameters.size() > 1) {
// 		Php::Value object_secondary_cursor = parameters[1];
// 		GdkRGBA_ *phpgtk_secondary_cursor = (GdkRGBA_ *)object_secondary_cursor.implementation();
// 		secondary_cursor = GTK_WIDGET(phpgtk_secondary_cursor->get_instance());
// 	}

// 	gtk_widget_override_cursor (GTK_WIDGET(instance), cursor, secondary_cursor);

	 Php::deprecated << "GtkWidget_::override_cursor  is deprecated on Gtk 3.16";
}

void GtkWidget_::modify_style(Php::Parameters &parameters)
{
// // 	GtkRcStyle *style;
// 	if(parameters.size() > 0) {
// 		Php::Value object_style = parameters[0];
// 		GtkRcStyle_ *phpgtk_style = (GtkRcStyle_ *)object_style.implementation();
// 		style = GTK_WIDGET(phpgtk_style->get_instance());
// 	}

// 	gtk_widget_modify_style (GTK_WIDGET(instance), style);

	 Php::deprecated << "GtkWidget_::modify_style  is deprecated on Gtk 3.0";
}

Php::Value GtkWidget_::get_modifier_style()
{
// 	GtkRcStyle *ret = gtk_widget_get_modifier_style (GTK_WIDGET(instance));

// 	GtkRcStyle_ *return_parsed = new GtkRcStyle_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkRcStyle", return_parsed);
	 Php::deprecated << "GtkWidget_::get_modifier_style  is deprecated on Gtk 3.0";
	 return 1;
}

void GtkWidget_::modify_fg(Php::Parameters &parameters)
{
// // 	GtkStateType *state;
// 	if(parameters.size() > 0) {
// 		Php::Value object_state = parameters[0];
// 		GtkStateType_ *phpgtk_state = (GtkStateType_ *)object_state.implementation();
// 		state = GTK_WIDGET(phpgtk_state->get_instance());
// 	}

// // 	GdkColor *color;
// 	if(parameters.size() > 1) {
// 		Php::Value object_color = parameters[1];
// 		GdkColor_ *phpgtk_color = (GdkColor_ *)object_color.implementation();
// 		color = GTK_WIDGET(phpgtk_color->get_instance());
// 	}

// 	gtk_widget_modify_fg (GTK_WIDGET(instance), state, color);

	 Php::deprecated << "GtkWidget_::modify_fg  is deprecated on Gtk 3.0";
}

void GtkWidget_::modify_bg(Php::Parameters &parameters)
{
// // 	GtkStateType *state;
// 	if(parameters.size() > 0) {
// 		Php::Value object_state = parameters[0];
// 		GtkStateType_ *phpgtk_state = (GtkStateType_ *)object_state.implementation();
// 		state = GTK_WIDGET(phpgtk_state->get_instance());
// 	}

// // 	GdkColor *color;
// 	if(parameters.size() > 1) {
// 		Php::Value object_color = parameters[1];
// 		GdkColor_ *phpgtk_color = (GdkColor_ *)object_color.implementation();
// 		color = GTK_WIDGET(phpgtk_color->get_instance());
// 	}

// 	gtk_widget_modify_bg (GTK_WIDGET(instance), state, color);

	 Php::deprecated << "GtkWidget_::modify_bg  is deprecated on Gtk 3.0";
}

void GtkWidget_::modify_text(Php::Parameters &parameters)
{
// // 	GtkStateType *state;
// 	if(parameters.size() > 0) {
// 		Php::Value object_state = parameters[0];
// 		GtkStateType_ *phpgtk_state = (GtkStateType_ *)object_state.implementation();
// 		state = GTK_WIDGET(phpgtk_state->get_instance());
// 	}

// // 	GdkColor *color;
// 	if(parameters.size() > 1) {
// 		Php::Value object_color = parameters[1];
// 		GdkColor_ *phpgtk_color = (GdkColor_ *)object_color.implementation();
// 		color = GTK_WIDGET(phpgtk_color->get_instance());
// 	}

// 	gtk_widget_modify_text (GTK_WIDGET(instance), state, color);

	 Php::deprecated << "GtkWidget_::modify_text  is deprecated on Gtk 3.0";
}

void GtkWidget_::modify_base(Php::Parameters &parameters)
{
// // 	GtkStateType *state;
// 	if(parameters.size() > 0) {
// 		Php::Value object_state = parameters[0];
// 		GtkStateType_ *phpgtk_state = (GtkStateType_ *)object_state.implementation();
// 		state = GTK_WIDGET(phpgtk_state->get_instance());
// 	}

// // 	GdkColor *color;
// 	if(parameters.size() > 1) {
// 		Php::Value object_color = parameters[1];
// 		GdkColor_ *phpgtk_color = (GdkColor_ *)object_color.implementation();
// 		color = GTK_WIDGET(phpgtk_color->get_instance());
// 	}

// 	gtk_widget_modify_base (GTK_WIDGET(instance), state, color);

	 Php::deprecated << "GtkWidget_::modify_base  is deprecated on Gtk 3.0";
}

void GtkWidget_::modify_font(Php::Parameters &parameters)
{
// 
// 	gtk_widget_modify_font (GTK_WIDGET(instance), font_desc);

	 Php::deprecated << "GtkWidget_::modify_font  is deprecated on Gtk 3.0";
}

void GtkWidget_::modify_cursor(Php::Parameters &parameters)
{
// // 	GdkColor *primary;
// 	if(parameters.size() > 0) {
// 		Php::Value object_primary = parameters[0];
// 		GdkColor_ *phpgtk_primary = (GdkColor_ *)object_primary.implementation();
// 		primary = GTK_WIDGET(phpgtk_primary->get_instance());
// 	}

// // 	GdkColor *secondary;
// 	if(parameters.size() > 1) {
// 		Php::Value object_secondary = parameters[1];
// 		GdkColor_ *phpgtk_secondary = (GdkColor_ *)object_secondary.implementation();
// 		secondary = GTK_WIDGET(phpgtk_secondary->get_instance());
// 	}

// 	gtk_widget_modify_cursor (GTK_WIDGET(instance), primary, secondary);

	 Php::deprecated << "GtkWidget_::modify_cursor  is deprecated on Gtk 3.0";
}

Php::Value GtkWidget_::create_pango_context()
{
// 	PangoContext ret = gtk_widget_create_pango_context (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::create_pango_context not implemented");
}

Php::Value GtkWidget_::get_pango_context()
{
// 	PangoContext ret = gtk_widget_get_pango_context (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_pango_context not implemented");
}

void GtkWidget_::set_font_options(Php::Parameters &parameters)
{
// 
// 	gtk_widget_set_font_options (GTK_WIDGET(instance), options);

	 throw Php::Exception("GtkWidget_::set_font_options not implemented");
}

void GtkWidget_::set_font_map(Php::Parameters &parameters)
{
// 
// 	gtk_widget_set_font_map (GTK_WIDGET(instance), font_map);

	 throw Php::Exception("GtkWidget_::set_font_map not implemented");
}

Php::Value GtkWidget_::get_font_map()
{
// 	PangoFontMap ret = gtk_widget_get_font_map (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_font_map not implemented");
}

Php::Value GtkWidget_::create_pango_layout(Php::Parameters &parameters)
{
// // 	std::string s_text = parameters[0];
// 	gchar *text = (gchar *)s_text.c_str();

// 	PangoLayout ret = gtk_widget_create_pango_layout (GTK_WIDGET(instance), text);

// 	return ret;
	 throw Php::Exception("GtkWidget_::create_pango_layout not implemented");
}

Php::Value GtkWidget_::render_icon(Php::Parameters &parameters)
{
// // 	std::string s_stock_id = parameters[0];
// 	gchar *stock_id = (gchar *)s_stock_id.c_str();

// // 	GtkIconSize *size;
// 	if(parameters.size() > 1) {
// 		Php::Value object_size = parameters[1];
// 		GtkIconSize_ *phpgtk_size = (GtkIconSize_ *)object_size.implementation();
// 		size = GTK_WIDGET(phpgtk_size->get_instance());
// 	}

// // 	std::string s_detail = parameters[2];
// 	gchar *detail = (gchar *)s_detail.c_str();

// 	GdkPixbuf ret = gtk_widget_render_icon (GTK_WIDGET(instance), stock_id, size, detail);

// 	return ret;
	 Php::deprecated << "GtkWidget_::render_icon  is deprecated on Gtk 3.0";
	 return 1;
}

Php::Value GtkWidget_::render_icon_pixbuf(Php::Parameters &parameters)
{
// // 	std::string s_stock_id = parameters[0];
// 	gchar *stock_id = (gchar *)s_stock_id.c_str();

// // 	GtkIconSize *size;
// 	if(parameters.size() > 1) {
// 		Php::Value object_size = parameters[1];
// 		GtkIconSize_ *phpgtk_size = (GtkIconSize_ *)object_size.implementation();
// 		size = GTK_WIDGET(phpgtk_size->get_instance());
// 	}

// 	GdkPixbuf ret = gtk_widget_render_icon_pixbuf (GTK_WIDGET(instance), stock_id, size);

// 	return ret;
	 Php::deprecated << "GtkWidget_::render_icon_pixbuf  is deprecated on Gtk 3.10";
	 return 1;
}

void GtkWidget_::pop_composite_child()
{
// 	gtk_widget_pop_composite_child (GTK_WIDGET(instance));

	 Php::deprecated << "GtkWidget_::pop_composite_child  is deprecated on Gtk 3.10";
}

void GtkWidget_::push_composite_child()
{
// 	gtk_widget_push_composite_child (GTK_WIDGET(instance));

	 Php::deprecated << "GtkWidget_::push_composite_child  is deprecated on Gtk 3.10";
}

void GtkWidget_::queue_draw_area(Php::Parameters &parameters)
{
	gint x = (gint)parameters[0];

	gint y = (gint)parameters[1];

	gint width = (gint)parameters[2];

	gint height = (gint)parameters[3];

	gtk_widget_queue_draw_area (GTK_WIDGET(instance), x, y, width, height);

}

void GtkWidget_::queue_draw_region(Php::Parameters &parameters)
{
// 
// 	gtk_widget_queue_draw_region (GTK_WIDGET(instance), region);

	 throw Php::Exception("GtkWidget_::queue_draw_region not implemented");
}

void GtkWidget_::set_app_paintable(Php::Parameters &parameters)
{
	gboolean app_paintable = (gboolean)parameters[0];

	gtk_widget_set_app_paintable (GTK_WIDGET(instance), app_paintable);

}

void GtkWidget_::set_double_buffered(Php::Parameters &parameters)
{
// // 	gboolean double_buffered = (gboolean)parameters[0];

// 	gtk_widget_set_double_buffered (GTK_WIDGET(instance), double_buffered);

	 Php::deprecated << "GtkWidget_::set_double_buffered  is deprecated on Gtk 3.14";
}

void GtkWidget_::set_redraw_on_allocate(Php::Parameters &parameters)
{
	gboolean redraw_on_allocate = (gboolean)parameters[0];

	gtk_widget_set_redraw_on_allocate (GTK_WIDGET(instance), redraw_on_allocate);

}

void GtkWidget_::set_composite_name(Php::Parameters &parameters)
{
// // 	std::string s_name = parameters[0];
// 	gchar *name = (gchar *)s_name.c_str();

// 	gtk_widget_set_composite_name (GTK_WIDGET(instance), name);

	 Php::deprecated << "GtkWidget_::set_composite_name  is deprecated on Gtk 3.10";
}

Php::Value GtkWidget_::mnemonic_activate(Php::Parameters &parameters)
{
	gboolean group_cycling = (gboolean)parameters[0];

	gboolean ret = gtk_widget_mnemonic_activate (GTK_WIDGET(instance), group_cycling);

	return ret;
}

void GtkWidget_::class_install_style_property(Php::Parameters &parameters)
{
// 
// 	gtk_widget_class_install_style_property (GTK_WIDGET(instance), pspec);

	 throw Php::Exception("GtkWidget_::class_install_style_property not implemented");
}

void GtkWidget_::class_install_style_property_parser(Php::Parameters &parameters)
{
// 
// // 	GtkRcPropertyParser *parser;
// 	if(parameters.size() > 1) {
// 		Php::Value object_parser = parameters[1];
// 		GtkRcPropertyParser_ *phpgtk_parser = (GtkRcPropertyParser_ *)object_parser.implementation();
// 		parser = GTK_WIDGET(phpgtk_parser->get_instance());
// 	}

// 	gtk_widget_class_install_style_property_parser (GTK_WIDGET(instance), pspec, parser);

	 throw Php::Exception("GtkWidget_::class_install_style_property_parser not implemented");
}

Php::Value GtkWidget_::class_find_style_property(Php::Parameters &parameters)
{
// // 	std::string s_property_name = parameters[0];
// 	gchar *property_name = (gchar *)s_property_name.c_str();

// 	GParamSpec ret = gtk_widget_class_find_style_property (GTK_WIDGET(instance), property_name);

// 	return ret;
	 throw Php::Exception("GtkWidget_::class_find_style_property not implemented");
}

Php::Value GtkWidget_::class_list_style_properties(Php::Parameters &parameters)
{
// // 	guint n_properties = (int)parameters[0];

// 	GParamSpec ret = *gtk_widget_class_list_style_properties (GTK_WIDGET(instance), n_properties);

// 	return ret;
	 throw Php::Exception("GtkWidget_::class_list_style_properties not implemented");
}

Php::Value GtkWidget_::send_expose(Php::Parameters &parameters)
{
// // 	GdkEvent *event;
// 	if(parameters.size() > 0) {
// 		Php::Value object_event = parameters[0];
// 		GdkEvent_ *phpgtk_event = (GdkEvent_ *)object_event.implementation();
// 		event = GDK_EVENT(phpgtk_event->get_instance());
// 	}

// 	gint ret = gtk_widget_send_expose (GTK_WIDGET(instance), event);

// 	return ret;
	 throw Php::Exception("GtkWidget_::send_expose not implemented");
}

Php::Value GtkWidget_::send_focus_change(Php::Parameters &parameters)
{
// // 	GdkEvent *event;
// 	if(parameters.size() > 0) {
// 		Php::Value object_event = parameters[0];
// 		GdkEvent_ *phpgtk_event = (GdkEvent_ *)object_event.implementation();
// 		event = GDK_EVENT(phpgtk_event->get_instance());
// 	}

// 	gboolean ret = gtk_widget_send_focus_change (GTK_WIDGET(instance), event);

// 	return ret;
	 throw Php::Exception("GtkWidget_::send_focus_change not implemented");
}

void GtkWidget_::style_get(Php::Parameters &parameters)
{
// // 	std::string s_first_property_name = parameters[0];
// 	gchar *first_property_name = (gchar *)s_first_property_name.c_str();

// 	gtk_widget_style_get (GTK_WIDGET(instance), first_property_name);

	 throw Php::Exception("GtkWidget_::style_get not implemented");
}

void GtkWidget_::style_get_property(Php::Parameters &parameters)
{
	// std::string s_property_name = parameters[0];
	// gchar *property_name = (gchar *)s_property_name.c_str();




	// gtk_widget_style_get_property (GTK_WIDGET(instance), property_name, value);

	throw Php::Exception("GtkWidget_::style_get_property not implemented");

}

void GtkWidget_::style_get_valist(Php::Parameters &parameters)
{
// // 	std::string s_first_property_name = parameters[0];
// 	gchar *first_property_name = (gchar *)s_first_property_name.c_str();

// 
// 	gtk_widget_style_get_valist (GTK_WIDGET(instance), first_property_name, var_args);

	 throw Php::Exception("GtkWidget_::style_get_valist not implemented");
}

void GtkWidget_::style_attach()
{
// 	gtk_widget_style_attach (GTK_WIDGET(instance));

	 Php::deprecated << "GtkWidget_::style_attach  is deprecated on Gtk 3.0";
}

void GtkWidget_::class_set_accessible_type(Php::Parameters &parameters)
{
// 
// 	gtk_widget_class_set_accessible_type (GTK_WIDGET(instance), type);

	 throw Php::Exception("GtkWidget_::class_set_accessible_type not implemented");
}

void GtkWidget_::class_set_accessible_role(Php::Parameters &parameters)
{
// 
// 	gtk_widget_class_set_accessible_role (GTK_WIDGET(instance), role);

	 throw Php::Exception("GtkWidget_::class_set_accessible_role not implemented");
}

Php::Value GtkWidget_::get_accessible()
{
// 	AtkObject ret = gtk_widget_get_accessible (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_accessible not implemented");
}

Php::Value GtkWidget_::child_focus(Php::Parameters &parameters)
{
	int int_direction = (int)parameters[0];
	GtkDirectionType direction = (GtkDirectionType)int_direction;

	gboolean ret = gtk_widget_child_focus (GTK_WIDGET(instance), direction);

	return ret;
}

void GtkWidget_::child_notify(Php::Parameters &parameters)
{
	std::string s_child_property = parameters[0];
	gchar *child_property = (gchar *)s_child_property.c_str();

	gtk_widget_child_notify (GTK_WIDGET(instance), child_property);

}

void GtkWidget_::freeze_child_notify()
{
	gtk_widget_freeze_child_notify (GTK_WIDGET(instance));

}

Php::Value GtkWidget_::get_child_visible()
{
	gboolean ret = gtk_widget_get_child_visible (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::get_parent()
{
	gpointer *ret = (gpointer *)gtk_widget_get_parent (GTK_WIDGET(instance));



	// GType t = G_OBJECT_TYPE(ret);
	// g_print("<Widget>: %s\n", g_type_name(t));


	return cobject_to_phpobject(ret);
	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkWidget_::get_settings()
{
// 	GtkSettings *ret = gtk_widget_get_settings (GTK_WIDGET(instance));

// 	GtkSettings_ *return_parsed = new GtkSettings_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkSettings", return_parsed);
	 throw Php::Exception("GtkWidget_::get_settings not implemented");
}

Php::Value GtkWidget_::get_clipboard(Php::Parameters &parameters)
{
// // 	GdkAtom *selection;
// 	if(parameters.size() > 0) {
// 		Php::Value object_selection = parameters[0];
// 		GdkAtom_ *phpgtk_selection = (GdkAtom_ *)object_selection.implementation();
// 		selection = GTK_WIDGET(phpgtk_selection->get_instance());
// 	}

// 	GtkClipboard *ret = gtk_widget_get_clipboard (GTK_WIDGET(instance), selection);

// 	GtkClipboard_ *return_parsed = new GtkClipboard_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkClipboard", return_parsed);
	 throw Php::Exception("GtkWidget_::get_clipboard not implemented");
}

Php::Value GtkWidget_::get_display()
{
// 	GdkDisplay ret = gtk_widget_get_display (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_display not implemented");
}

Php::Value GtkWidget_::get_root_window()
{
// 	GdkWindow ret = gtk_widget_get_root_window (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::get_root_window  is deprecated on Gtk 3.12";
	 return 1;
}

Php::Value GtkWidget_::get_screen()
{
// 	GdkScreen ret = gtk_widget_get_screen (GTK_WIDGET(instance));

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_screen not implemented");
}

Php::Value GtkWidget_::has_screen()
{
	gboolean ret = gtk_widget_has_screen (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::get_size_request(Php::Parameters &parameters)
{
	gint width;

	gint height;

	gtk_widget_get_size_request (GTK_WIDGET(instance), &width, &height);

	Php::Value arr;
	arr[0] = arr["width"] = (int)width;
	arr[1] = arr["height"] = (int)height;

	return arr;

}

void GtkWidget_::set_child_visible(Php::Parameters &parameters)
{
	gboolean is_visible = (gboolean)parameters[0];

	gtk_widget_set_child_visible (GTK_WIDGET(instance), is_visible);

}

void GtkWidget_::set_size_request(Php::Parameters &parameters)
{
	gint width = (gint)parameters[0];

	gint height = (gint)parameters[1];

	gtk_widget_set_size_request (GTK_WIDGET(instance), width, height);

}

void GtkWidget_::thaw_child_notify()
{
	gtk_widget_thaw_child_notify (GTK_WIDGET(instance));

}

void GtkWidget_::set_no_show_all(Php::Parameters &parameters)
{
	gboolean no_show_all = (gboolean)parameters[0];

	gtk_widget_set_no_show_all (GTK_WIDGET(instance), no_show_all);

}

Php::Value GtkWidget_::get_no_show_all()
{
	gboolean ret = gtk_widget_get_no_show_all (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::list_mnemonic_labels()
{
	// GList ret = gtk_widget_list_mnemonic_labels (GTK_WIDGET(instance));

	// return ret;

	throw Php::Exception("GtkWidget_::list_mnemonic_labels not implemented");

	return 1;
}

void GtkWidget_::add_mnemonic_label(Php::Parameters &parameters)
{
	GtkWidget *label;
	if(parameters.size() > 0) {
		Php::Value object_label = parameters[0];
		GtkWidget_ *phpgtk_label = (GtkWidget_ *)object_label.implementation();
		label = GTK_WIDGET(phpgtk_label->get_instance());
	}

	gtk_widget_add_mnemonic_label (GTK_WIDGET(instance), label);

}

void GtkWidget_::remove_mnemonic_label(Php::Parameters &parameters)
{
	GtkWidget *label;
	if(parameters.size() > 0) {
		Php::Value object_label = parameters[0];
		GtkWidget_ *phpgtk_label = (GtkWidget_ *)object_label.implementation();
		label = GTK_WIDGET(phpgtk_label->get_instance());
	}

	gtk_widget_remove_mnemonic_label (GTK_WIDGET(instance), label);

}

Php::Value GtkWidget_::is_composited()
{
// 	gboolean ret = gtk_widget_is_composited (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::is_composited  is deprecated on Gtk 3.22";
	 return 1;
}

void GtkWidget_::error_bell()
{
	gtk_widget_error_bell (GTK_WIDGET(instance));

}

Php::Value GtkWidget_::keynav_failed(Php::Parameters &parameters)
{
	int int_direction = (int)parameters[0];
	GtkDirectionType direction = (GtkDirectionType)int_direction;

	gboolean ret = gtk_widget_keynav_failed (GTK_WIDGET(instance), direction);

	return ret;
}

Php::Value GtkWidget_::get_tooltip_markup()
{
	std::string ret = gtk_widget_get_tooltip_markup (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_tooltip_markup(Php::Parameters &parameters)
{
	std::string s_markup = parameters[0];
	gchar *markup = (gchar *)s_markup.c_str();

	gtk_widget_set_tooltip_markup (GTK_WIDGET(instance), markup);

}

Php::Value GtkWidget_::get_tooltip_text()
{
	std::string ret = gtk_widget_get_tooltip_text (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_tooltip_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gtk_widget_set_tooltip_text (GTK_WIDGET(instance), text);

}

Php::Value GtkWidget_::get_tooltip_window()
{
	GtkWindow *ret = gtk_widget_get_tooltip_window (GTK_WIDGET(instance));

	GtkWindow_ *return_parsed = new GtkWindow_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWindow", return_parsed);
}

void GtkWidget_::set_tooltip_window(Php::Parameters &parameters)
{
	GtkWindow *custom_window;
	if(parameters.size() > 0) {
		Php::Value object_custom_window = parameters[0];
		GtkWindow_ *phpgtk_custom_window = (GtkWindow_ *)object_custom_window.implementation();
		custom_window = GTK_WINDOW(phpgtk_custom_window->get_instance());
	}

	gtk_widget_set_tooltip_window (GTK_WIDGET(instance), custom_window);

}

Php::Value GtkWidget_::get_has_tooltip()
{
	gboolean ret = gtk_widget_get_has_tooltip (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_has_tooltip(Php::Parameters &parameters)
{
	gboolean has_tooltip = (gboolean)parameters[0];

	gtk_widget_set_has_tooltip (GTK_WIDGET(instance), has_tooltip);

}

void GtkWidget_::trigger_tooltip_query()
{
	gtk_widget_trigger_tooltip_query (GTK_WIDGET(instance));

}

Php::Value GtkWidget_::get_window()
{
	GdkWindow *ret = gtk_widget_get_window (GTK_WIDGET(instance));

	GdkWindow_ *return_parsed = new GdkWindow_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GdkWindow", return_parsed);
}

void GtkWidget_::register_window(Php::Parameters &parameters)
{
	GdkWindow *window;
	if(parameters.size() > 0) {
		Php::Value object_window = parameters[0];
		GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
		window = GDK_WINDOW(phpgtk_window->get_instance());
	}

	gtk_widget_register_window (GTK_WIDGET(instance), window);

}

void GtkWidget_::unregister_window(Php::Parameters &parameters)
{
	GdkWindow *window;
	if(parameters.size() > 0) {
		Php::Value object_window = parameters[0];
		GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
		window = GDK_WINDOW(phpgtk_window->get_instance());
	}

	gtk_widget_unregister_window (GTK_WIDGET(instance), window);

}

Php::Value GtkWidget_::gtk_cairo_should_draw_window(Php::Parameters &parameters)
{
// // 	GdkWindow *window;
// 	if(parameters.size() > 0) {
// 		Php::Value object_window = parameters[0];
// 		GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
// 		window = GTK_WIDGET(phpgtk_window->get_instance());
// 	}

// 	gboolean ret = gtk_cairo_should_draw_window (GTK_WIDGET(instance), window);

// 	return ret;
	 throw Php::Exception("GtkWidget_::gtk_cairo_should_draw_window not implemented");
}

void GtkWidget_::gtk_cairo_transform_to_window(Php::Parameters &parameters)
{
// // 	GtkWidget *widget;
// 	if(parameters.size() > 0) {
// 		Php::Value object_widget = parameters[0];
// 		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
// 		widget = GTK_WIDGET(phpgtk_widget->get_instance());
// 	}

// // 	GdkWindow *window;
// 	if(parameters.size() > 1) {
// 		Php::Value object_window = parameters[1];
// 		GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
// 		window = GTK_WIDGET(phpgtk_window->get_instance());
// 	}

// 	gtk_cairo_transform_to_window (GTK_WIDGET(instance), widget, window);

	 throw Php::Exception("GtkWidget_::gtk_cairo_transform_to_window not implemented");
}

Php::Value GtkWidget_::get_allocated_width()
{
	int ret = gtk_widget_get_allocated_width (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::get_allocated_height()
{
	int ret = gtk_widget_get_allocated_height (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::get_allocation(Php::Parameters &parameters)
{
// // 	GtkAllocation *allocation;
// 	if(parameters.size() > 0) {
// 		Php::Value object_allocation = parameters[0];
// 		GtkAllocation_ *phpgtk_allocation = (GtkAllocation_ *)object_allocation.implementation();
// 		allocation = GTK_WIDGET(phpgtk_allocation->get_instance());
// 	}

// 	gtk_widget_get_allocation (GTK_WIDGET(instance), allocation);

	 throw Php::Exception("GtkWidget_::get_allocation not implemented");
}

void GtkWidget_::set_allocation(Php::Parameters &parameters)
{
// // 	GtkAllocation *allocation;
// 	if(parameters.size() > 0) {
// 		Php::Value object_allocation = parameters[0];
// 		GtkAllocation_ *phpgtk_allocation = (GtkAllocation_ *)object_allocation.implementation();
// 		allocation = GTK_WIDGET(phpgtk_allocation->get_instance());
// 	}

// 	gtk_widget_set_allocation (GTK_WIDGET(instance), allocation);

	 throw Php::Exception("GtkWidget_::set_allocation not implemented");
}

Php::Value GtkWidget_::get_allocated_baseline()
{
	int ret = gtk_widget_get_allocated_baseline (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::get_allocated_size(Php::Parameters &parameters)
{
// // 	GtkAllocation *allocation;
// 	if(parameters.size() > 0) {
// 		Php::Value object_allocation = parameters[0];
// 		GtkAllocation_ *phpgtk_allocation = (GtkAllocation_ *)object_allocation.implementation();
// 		allocation = GTK_WIDGET(phpgtk_allocation->get_instance());
// 	}

// 
// 	gtk_widget_get_allocated_size (GTK_WIDGET(instance), allocation, baseline);

	 throw Php::Exception("GtkWidget_::get_allocated_size not implemented");
}

void GtkWidget_::get_clip(Php::Parameters &parameters)
{
// // 	GtkAllocation *clip;
// 	if(parameters.size() > 0) {
// 		Php::Value object_clip = parameters[0];
// 		GtkAllocation_ *phpgtk_clip = (GtkAllocation_ *)object_clip.implementation();
// 		clip = GTK_WIDGET(phpgtk_clip->get_instance());
// 	}

// 	gtk_widget_get_clip (GTK_WIDGET(instance), clip);

	 throw Php::Exception("GtkWidget_::get_clip not implemented");
}

void GtkWidget_::set_clip(Php::Parameters &parameters)
{
// // 	GtkAllocation *clip;
// 	if(parameters.size() > 0) {
// 		Php::Value object_clip = parameters[0];
// 		GtkAllocation_ *phpgtk_clip = (GtkAllocation_ *)object_clip.implementation();
// 		clip = GTK_WIDGET(phpgtk_clip->get_instance());
// 	}

// 	gtk_widget_set_clip (GTK_WIDGET(instance), clip);

	 throw Php::Exception("GtkWidget_::set_clip not implemented");
}

Php::Value GtkWidget_::get_app_paintable()
{
	gboolean ret = gtk_widget_get_app_paintable (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::get_can_default()
{
	gboolean ret = gtk_widget_get_can_default (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_can_default(Php::Parameters &parameters)
{
	gboolean can_default = (gboolean)parameters[0];

	gtk_widget_set_can_default (GTK_WIDGET(instance), can_default);

}

Php::Value GtkWidget_::get_can_focus()
{
	gboolean ret = gtk_widget_get_can_focus (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_can_focus(Php::Parameters &parameters)
{
	gboolean can_focus = (gboolean)parameters[0];

	gtk_widget_set_can_focus (GTK_WIDGET(instance), can_focus);

}

Php::Value GtkWidget_::get_focus_on_click()
{
	gboolean ret = gtk_widget_get_focus_on_click (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_focus_on_click(Php::Parameters &parameters)
{
	gboolean focus_on_click = (gboolean)parameters[0];

	gtk_widget_set_focus_on_click (GTK_WIDGET(instance), focus_on_click);

}

Php::Value GtkWidget_::get_double_buffered()
{
// 	gboolean ret = gtk_widget_get_double_buffered (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::get_double_buffered  is deprecated on Gtk 3.0";
	 return 1;
}

Php::Value GtkWidget_::get_has_window()
{
	gboolean ret = gtk_widget_get_has_window (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_has_window(Php::Parameters &parameters)
{
	gboolean has_window = (gboolean)parameters[0];

	gtk_widget_set_has_window (GTK_WIDGET(instance), has_window);

}

Php::Value GtkWidget_::get_sensitive()
{
	gboolean ret = gtk_widget_get_sensitive (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::is_sensitive()
{
	gboolean ret = gtk_widget_is_sensitive (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::get_state()
{
// 	GtkStateType ret = gtk_widget_get_state (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::get_state  is deprecated on Gtk 3.0";
	 return 1;
}

Php::Value GtkWidget_::get_visible()
{
	gboolean ret = gtk_widget_get_visible (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::is_visible()
{
	gboolean ret = gtk_widget_is_visible (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_visible(Php::Parameters &parameters)
{
	gboolean visible = (gboolean)parameters[0];

	gtk_widget_set_visible (GTK_WIDGET(instance), visible);

}

void GtkWidget_::set_state_flags(Php::Parameters &parameters)
{
	int int_flags = (int)parameters[0];
	GtkStateFlags flags = (GtkStateFlags)int_flags;

	gboolean clear = (gboolean)parameters[1];

	gtk_widget_set_state_flags (GTK_WIDGET(instance), flags, clear);

}

void GtkWidget_::unset_state_flags(Php::Parameters &parameters)
{
	int int_flags = (int)parameters[0];
	GtkStateFlags flags = (GtkStateFlags)int_flags;

	gtk_widget_unset_state_flags (GTK_WIDGET(instance), flags);

}

Php::Value GtkWidget_::get_state_flags()
{
	GtkStateFlags ret = gtk_widget_get_state_flags (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::has_default()
{
	gboolean ret = gtk_widget_has_default (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::has_focus()
{
	gboolean ret = gtk_widget_has_focus (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::has_visible_focus()
{
	gboolean ret = gtk_widget_has_visible_focus (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::has_grab()
{
	gboolean ret = gtk_widget_has_grab (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::has_rc_style()
{
// 	gboolean ret = gtk_widget_has_rc_style (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::has_rc_style  is deprecated on Gtk 3.0";
	 return 1;
}

Php::Value GtkWidget_::is_drawable()
{
	gboolean ret = gtk_widget_is_drawable (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::is_toplevel()
{
	gboolean ret = gtk_widget_is_toplevel (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_window(Php::Parameters &parameters)
{
	GdkWindow *window;
	if(parameters.size() > 0) {
		Php::Value object_window = parameters[0];
		GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
		window = GDK_WINDOW(phpgtk_window->get_instance());
	}

	gtk_widget_set_window (GTK_WIDGET(instance), window);

}

void GtkWidget_::set_receives_default(Php::Parameters &parameters)
{
	gboolean receives_default = (gboolean)parameters[0];

	gtk_widget_set_receives_default (GTK_WIDGET(instance), receives_default);

}

Php::Value GtkWidget_::get_receives_default()
{
	gboolean ret = gtk_widget_get_receives_default (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_support_multidevice(Php::Parameters &parameters)
{
	gboolean support_multidevice = (gboolean)parameters[0];

	gtk_widget_set_support_multidevice (GTK_WIDGET(instance), support_multidevice);

}

Php::Value GtkWidget_::get_support_multidevice()
{
	gboolean ret = gtk_widget_get_support_multidevice (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_realized(Php::Parameters &parameters)
{
	gboolean realized = (gboolean)parameters[0];

	gtk_widget_set_realized (GTK_WIDGET(instance), realized);

}

Php::Value GtkWidget_::get_realized()
{
	gboolean ret = gtk_widget_get_realized (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_mapped(Php::Parameters &parameters)
{
	gboolean mapped = (gboolean)parameters[0];

	gtk_widget_set_mapped (GTK_WIDGET(instance), mapped);

}

Php::Value GtkWidget_::get_mapped()
{
	gboolean ret = gtk_widget_get_mapped (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::get_requisition(Php::Parameters &parameters)
{
// // 	GtkRequisition *requisition;
// 	if(parameters.size() > 0) {
// 		Php::Value object_requisition = parameters[0];
// 		GtkRequisition_ *phpgtk_requisition = (GtkRequisition_ *)object_requisition.implementation();
// 		requisition = GTK_WIDGET(phpgtk_requisition->get_instance());
// 	}

// 	gtk_widget_get_requisition (GTK_WIDGET(instance), requisition);

	 Php::deprecated << "GtkWidget_::get_requisition  is deprecated on Gtk 3.0";
}

Php::Value GtkWidget_::device_is_shadowed(Php::Parameters &parameters)
{
// // 	GdkDevice *device;
// 	if(parameters.size() > 0) {
// 		Php::Value object_device = parameters[0];
// 		GdkDevice_ *phpgtk_device = (GdkDevice_ *)object_device.implementation();
// 		device = GTK_WIDGET(phpgtk_device->get_instance());
// 	}

// 	gboolean ret = gtk_widget_device_is_shadowed (GTK_WIDGET(instance), device);

// 	return ret;
	 throw Php::Exception("GtkWidget_::device_is_shadowed not implemented");
}

Php::Value GtkWidget_::get_modifier_mask(Php::Parameters &parameters)
{
// // 	GdkModifierIntent *intent;
// 	if(parameters.size() > 0) {
// 		Php::Value object_intent = parameters[0];
// 		GdkModifierIntent_ *phpgtk_intent = (GdkModifierIntent_ *)object_intent.implementation();
// 		intent = GTK_WIDGET(phpgtk_intent->get_instance());
// 	}

// 	GdkModifierType ret = gtk_widget_get_modifier_mask (GTK_WIDGET(instance), intent);

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_modifier_mask not implemented");
}

void GtkWidget_::insert_action_group(Php::Parameters &parameters)
{
// // 	std::string s_name = parameters[0];
// 	gchar *name = (gchar *)s_name.c_str();

// 
// 	gtk_widget_insert_action_group (GTK_WIDGET(instance), name, group);

	 throw Php::Exception("GtkWidget_::insert_action_group not implemented");
}

Php::Value GtkWidget_::get_opacity()
{
	double ret = gtk_widget_get_opacity (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_opacity(Php::Parameters &parameters)
{

	gtk_widget_set_opacity (GTK_WIDGET(instance), parameters[0]);

}

Php::Value GtkWidget_::list_action_prefixes()
{
	// std::string ret = *gtk_widget_list_action_prefixes (GTK_WIDGET(instance));

	// return ret;

	throw Php::Exception("GtkWidget_::list_action_prefixes not implemented");
	return 1;
}

Php::Value GtkWidget_::get_action_group(Php::Parameters &parameters)
{
// // 	std::string s_prefix = parameters[0];
// 	gchar *prefix = (gchar *)s_prefix.c_str();

// 	GActionGroup ret = gtk_widget_get_action_group (GTK_WIDGET(instance), prefix);

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_action_group not implemented");
}

Php::Value GtkWidget_::get_path()
{
	GtkWidgetPath *ret = gtk_widget_get_path (GTK_WIDGET(instance));

	GtkWidgetPath_ *return_parsed = new GtkWidgetPath_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkWidgetPath", return_parsed);
}

Php::Value GtkWidget_::get_style_context()
{
	GtkStyleContext *ret = gtk_widget_get_style_context (GTK_WIDGET(instance));

	GtkStyleContext_ *return_parsed = new GtkStyleContext_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkStyleContext", return_parsed);
}

void GtkWidget_::reset_style()
{
	gtk_widget_reset_style (GTK_WIDGET(instance));

}

Php::Value GtkWidget_::class_get_css_name()
{
	// char ret = gtk_widget_class_get_css_name (GTK_WIDGET(instance));

	// return ret;

	 throw Php::Exception("GtkWidget_::class_get_css_name not implemented");
}

void GtkWidget_::class_set_css_name(Php::Parameters &parameters)
{
	// std::string s_text = parameters[0];
	// gchar *text = (gchar *)s_text.c_str();

 // 	gtk_widget_class_set_css_name (GTK_WIDGET(instance), text);
}

Php::Value GtkWidget_::gtk_requisition_new()
{
// 	GtkRequisition *ret = gtk_requisition_new (GTK_WIDGET(instance));

// 	GtkRequisition_ *return_parsed = new GtkRequisition_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkRequisition", return_parsed);
	 throw Php::Exception("GtkWidget_::gtk_requisition_new not implemented");
}

Php::Value GtkWidget_::gtk_requisition_copy(Php::Parameters &parameters)
{
	throw Php::Exception("GtkWidget_::gtk_requisition_copy not implemented");
	return 1;
}

void GtkWidget_::gtk_requisition_free()
{
	// gtk_requisition_free (GTK_WIDGET(instance));

	throw Php::Exception("GtkWidget_::gtk_requisition_free not implemented");

}

Php::Value GtkWidget_::get_preferred_height(Php::Parameters &parameters)
{
	gint minimum_height;
	gint natural_height;

	gtk_widget_get_preferred_height (GTK_WIDGET(instance), &minimum_height, &natural_height);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["minimum_height"] = (int)minimum_height;
	arr[1] = arr["natural_height"] = (int)natural_height;

	return arr;
}

Php::Value GtkWidget_::get_preferred_width(Php::Parameters &parameters)
{
	gint minimum_width;
	gint natural_width;

	gtk_widget_get_preferred_width (GTK_WIDGET(instance), &minimum_width, &natural_width);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["minimum_width"] = (int)minimum_width;
	arr[1] = arr["natural_width"] = (int)natural_width;

	return arr;
}

Php::Value GtkWidget_::get_preferred_height_for_width(Php::Parameters &parameters)
{
	gint width = (gint)parameters[0];

	gint minimum_height;
	gint natural_height;

	gtk_widget_get_preferred_height_for_width (GTK_WIDGET(instance), width, &minimum_height, &natural_height);


	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["minimum_height"] = (int)minimum_height;
	arr[1] = arr["natural_height"] = (int)natural_height;

	return arr;

}

Php::Value GtkWidget_::get_preferred_width_for_height(Php::Parameters &parameters)
{
	gint height = (gint)parameters[0];

	gint minimum_width;
	gint natural_width;

	gtk_widget_get_preferred_width_for_height (GTK_WIDGET(instance), height, &minimum_width, &natural_width);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["minimum_width"] = (int)minimum_width;
	arr[1] = arr["natural_width"] = (int)natural_width;

	return arr;

}

Php::Value GtkWidget_::get_preferred_height_and_baseline_for_width(Php::Parameters &parameters)
{
	gint width = (gint)parameters[0];

	gint minimum_height;
	gint natural_height;
	gint minimum_baseline;
	gint natural_baseline;

	gtk_widget_get_preferred_height_and_baseline_for_width (GTK_WIDGET(instance), width, &minimum_height, &natural_height, &minimum_baseline, &natural_baseline);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["minimum_height"] = (int)minimum_height;
	arr[1] = arr["minimum_baseline"] = (int)minimum_baseline;
	arr[2] = arr["natural_height"] = (int)natural_height;
	arr[3] = arr["natural_baseline"] = (int)natural_baseline;

	return arr;
}

Php::Value GtkWidget_::get_request_mode()
{
	GtkSizeRequestMode ret = gtk_widget_get_request_mode (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::get_preferred_size(Php::Parameters &parameters)
{
	GtkRequisition minimum_size;
	GtkRequisition natural_size;

	gtk_widget_get_preferred_size (GTK_WIDGET(instance), &minimum_size, &natural_size);


	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["minimum_height"] = (int)minimum_size.height;
	arr[1] = arr["minimum_width"] = (int)minimum_size.width;
	arr[2] = arr["natural_height"] = (int)natural_size.height;
	arr[3] = arr["natural_width"] = (int)natural_size.width;

	return arr;
}

Php::Value GtkWidget_::gtk_distribute_natural_allocation(Php::Parameters &parameters)
{
	// guint n_requested_sizes = (int)parameters[0];

	// GtkRequestedSize *sizes;

	// gint ret = gtk_distribute_natural_allocation (GTK_WIDGET(instance), n_requested_sizes, sizes);

	// return ret;

	throw Php::Exception("GtkWidget_::gtk_distribute_natural_allocation not implemented");
	return 1;
}

Php::Value GtkWidget_::get_halign()
{
	GtkAlign ret = gtk_widget_get_halign (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_halign(Php::Parameters &parameters)
{
	int int_align = (int)parameters[0];
	GtkAlign align = (GtkAlign)int_align;

	gtk_widget_set_halign (GTK_WIDGET(instance), align);

}

Php::Value GtkWidget_::get_valign()
{
	GtkAlign ret = gtk_widget_get_valign (GTK_WIDGET(instance));

	return ret;
}

Php::Value GtkWidget_::get_valign_with_baseline()
{
	GtkAlign ret = gtk_widget_get_valign_with_baseline (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_valign(Php::Parameters &parameters)
{
	int int_align = (int)parameters[0];
	GtkAlign align = (GtkAlign)int_align;

	gtk_widget_set_valign (GTK_WIDGET(instance), align);

}

Php::Value GtkWidget_::get_margin_left()
{
// 	gint ret = gtk_widget_get_margin_left (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::get_margin_left  is deprecated on Gtk 3.12";
	 return 1;
}

void GtkWidget_::set_margin_left(Php::Parameters &parameters)
{
// // 	gint margin = (gint)parameters[0];

// 	gtk_widget_set_margin_left (GTK_WIDGET(instance), margin);

	 Php::deprecated << "GtkWidget_::set_margin_left  is deprecated on Gtk 3.12";
}

Php::Value GtkWidget_::get_margin_right()
{
// 	gint ret = gtk_widget_get_margin_right (GTK_WIDGET(instance));

// 	return ret;
	 Php::deprecated << "GtkWidget_::get_margin_right  is deprecated on Gtk 3.12";
	 return 1;
}

void GtkWidget_::set_margin_right(Php::Parameters &parameters)
{
// // 	gint margin = (gint)parameters[0];

// 	gtk_widget_set_margin_right (GTK_WIDGET(instance), margin);

	 Php::deprecated << "GtkWidget_::set_margin_right  is deprecated on Gtk 3.12";
}

Php::Value GtkWidget_::get_margin_start()
{
	gint ret = gtk_widget_get_margin_start (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_margin_start(Php::Parameters &parameters)
{
	gint margin = (gint)parameters[0];

	gtk_widget_set_margin_start (GTK_WIDGET(instance), margin);

}

Php::Value GtkWidget_::get_margin_end()
{
	gint ret = gtk_widget_get_margin_end (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_margin_end(Php::Parameters &parameters)
{
	gint margin = (gint)parameters[0];

	gtk_widget_set_margin_end (GTK_WIDGET(instance), margin);

}

Php::Value GtkWidget_::get_margin_top()
{
	gint ret = gtk_widget_get_margin_top (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_margin_top(Php::Parameters &parameters)
{
	gint margin = (gint)parameters[0];

	gtk_widget_set_margin_top (GTK_WIDGET(instance), margin);

}

Php::Value GtkWidget_::get_margin_bottom()
{
	gint ret = gtk_widget_get_margin_bottom (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_margin_bottom(Php::Parameters &parameters)
{
	gint margin = (gint)parameters[0];

	gtk_widget_set_margin_bottom (GTK_WIDGET(instance), margin);

}

Php::Value GtkWidget_::get_hexpand()
{
	gboolean ret = gtk_widget_get_hexpand (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_hexpand(Php::Parameters &parameters)
{
	gboolean expand = (gboolean)parameters[0];

	gtk_widget_set_hexpand (GTK_WIDGET(instance), expand);

}

Php::Value GtkWidget_::get_hexpand_set()
{
	gboolean ret = gtk_widget_get_hexpand_set (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_hexpand_set(Php::Parameters &parameters)
{
	gboolean set = (gboolean)parameters[0];

	gtk_widget_set_hexpand_set (GTK_WIDGET(instance), set);

}

Php::Value GtkWidget_::get_vexpand()
{
	gboolean ret = gtk_widget_get_vexpand (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_vexpand(Php::Parameters &parameters)
{
	gboolean expand = (gboolean)parameters[0];

	gtk_widget_set_vexpand (GTK_WIDGET(instance), expand);

}

Php::Value GtkWidget_::get_vexpand_set()
{
	gboolean ret = gtk_widget_get_vexpand_set (GTK_WIDGET(instance));

	return ret;
}

void GtkWidget_::set_vexpand_set(Php::Parameters &parameters)
{
	gboolean set = (gboolean)parameters[0];

	gtk_widget_set_vexpand_set (GTK_WIDGET(instance), set);

}

void GtkWidget_::queue_compute_expand()
{
	gtk_widget_queue_compute_expand (GTK_WIDGET(instance));

}

Php::Value GtkWidget_::compute_expand(Php::Parameters &parameters)
{
	int int_orientation = (int)parameters[0];
	GtkOrientation orientation = (GtkOrientation)int_orientation;

	gboolean ret = gtk_widget_compute_expand (GTK_WIDGET(instance), orientation);

	return ret;
}

void GtkWidget_::init_template()
{
	gtk_widget_init_template (GTK_WIDGET(instance));

}

void GtkWidget_::class_set_template(Php::Parameters &parameters)
{
// 
// 	gtk_widget_class_set_template (GTK_WIDGET(instance), template_bytes);

	 throw Php::Exception("GtkWidget_::class_set_template not implemented");
}

void GtkWidget_::class_set_template_from_resource(Php::Parameters &parameters)
{
	// std::string s_resource_name = parameters[0];
	// gchar *resource_name = (gchar *)s_resource_name.c_str();

	// gtk_widget_class_set_template_from_resource (GTK_WIDGET(instance), resource_name);

	throw Php::Exception("GtkWidget_::class_set_template_from_resource not implemented");

}

Php::Value GtkWidget_::get_template_child(Php::Parameters &parameters)
{
// 
// // 	std::string s_name = parameters[1];
// 	gchar *name = (gchar *)s_name.c_str();

// 	GObject ret = gtk_widget_get_template_child (GTK_WIDGET(instance), widget_type, name);

// 	return ret;
	 throw Php::Exception("GtkWidget_::get_template_child not implemented");
}

void GtkWidget_::class_bind_template_child_full(Php::Parameters &parameters)
{
// // 	std::string s_name = parameters[0];
// 	gchar *name = (gchar *)s_name.c_str();

// // 	gboolean internal_child = (gboolean)parameters[1];

// // 	gssize struct_offset = (gssize)parameters[2];

// 	gtk_widget_class_bind_template_child_full (GTK_WIDGET(instance), name, internal_child, struct_offset);

	 throw Php::Exception("GtkWidget_::class_bind_template_child_full not implemented");
}

void GtkWidget_::class_bind_template_callback_full(Php::Parameters &parameters)
{
// // 	std::string s_callback_name = parameters[0];
// 	gchar *callback_name = (gchar *)s_callback_name.c_str();

// 
// 	gtk_widget_class_bind_template_callback_full (GTK_WIDGET(instance), callback_name, callback_symbol);

	 throw Php::Exception("GtkWidget_::class_bind_template_callback_full not implemented");
}

void GtkWidget_::class_set_connect_func(Php::Parameters &parameters)
{
// // 	GtkBuilderConnectFunc *connect_func;
// 	if(parameters.size() > 0) {
// 		Php::Value object_connect_func = parameters[0];
// 		GtkBuilderConnectFunc_ *phpgtk_connect_func = (GtkBuilderConnectFunc_ *)object_connect_func.implementation();
// 		connect_func = GTK_WIDGET(phpgtk_connect_func->get_instance());
// 	}

// // 	gpointer connect_data = (gpointer)parameters[1];

// 
// 	gtk_widget_class_set_connect_func (GTK_WIDGET(instance), connect_func, connect_data, connect_data_destroy);

	 throw Php::Exception("GtkWidget_::class_set_connect_func not implemented");
}

