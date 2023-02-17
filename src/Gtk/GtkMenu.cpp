
#include "GtkMenu.h"

/**
 * Constructor
 */
GtkMenu_::GtkMenu_() = default;

/**
 * Destructor
 */
GtkMenu_::~GtkMenu_() = default;

void GtkMenu_::__construct()
{
	instance = (gpointer *)gtk_menu_new ();

}

void GtkMenu_::new_from_model(Php::Parameters &parameters)
{

	// gtk_menu_new_from_model (model);

	throw Php::Exception("GtkMenu_::new_from_model not implemented");

}

void GtkMenu_::set_screen(Php::Parameters &parameters)
{
	// GdkScreen *screen;
	// if(parameters.size() > 0) {
	// 	Php::Value object_screen = parameters[0];
	// 	GdkScreen_ *phpgtk_screen = (GdkScreen_ *)object_screen.implementation();
	// 	screen = GTK_WIDGET(phpgtk_screen->get_instance());
	// }

	// gtk_menu_set_screen (GTK_MENU(instance), screen);

	throw Php::Exception("GtkMenu_::set_screen not implemented");

}

void GtkMenu_::reorder_child(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint position = (gint)parameters[1];

	gtk_menu_reorder_child (GTK_MENU(instance), child, position);
}

void GtkMenu_::attach(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	guint left_attach = (int)parameters[1];

	guint right_attach = (int)parameters[2];

	guint top_attach = (int)parameters[3];

	guint bottom_attach = (int)parameters[4];

	gtk_menu_attach (GTK_MENU(instance), child, left_attach, right_attach, top_attach, bottom_attach);

}

void GtkMenu_::popup_at_rect(Php::Parameters &parameters)
{
	// GdkWindow *rect_window;
	// if(parameters.size() > 0) {
	// 	Php::Value object_rect_window = parameters[0];
	// 	GdkWindow_ *phpgtk_rect_window = (GdkWindow_ *)object_rect_window.implementation();
	// 	rect_window = GTK_WIDGET(phpgtk_rect_window->get_instance());
	// }

	// GdkRectangle *rect;
	// if(parameters.size() > 1) {
	// 	Php::Value object_rect = parameters[1];
	// 	GdkRectangle_ *phpgtk_rect = (GdkRectangle_ *)object_rect.implementation();
	// 	rect = GTK_WIDGET(phpgtk_rect->get_instance());
	// }

	// GdkGravity *rect_anchor;
	// if(parameters.size() > 2) {
	// 	Php::Value object_rect_anchor = parameters[2];
	// 	GdkGravity_ *phpgtk_rect_anchor = (GdkGravity_ *)object_rect_anchor.implementation();
	// 	rect_anchor = GTK_WIDGET(phpgtk_rect_anchor->get_instance());
	// }

	// GdkGravity *menu_anchor;
	// if(parameters.size() > 3) {
	// 	Php::Value object_menu_anchor = parameters[3];
	// 	GdkGravity_ *phpgtk_menu_anchor = (GdkGravity_ *)object_menu_anchor.implementation();
	// 	menu_anchor = GTK_WIDGET(phpgtk_menu_anchor->get_instance());
	// }

	// GdkEvent *trigger_event;
	// if(parameters.size() > 4) {
	// 	Php::Value object_trigger_event = parameters[4];
	// 	GdkEvent_ *phpgtk_trigger_event = (GdkEvent_ *)object_trigger_event.implementation();
	// 	trigger_event = GTK_WIDGET(phpgtk_trigger_event->get_instance());
	// }

	// gtk_menu_popup_at_rect (GTK_MENU(instance), rect_window, rect, rect_anchor, menu_anchor, trigger_event);


	throw Php::Exception("GtkMenu_::popup_at_rect not implemented");

}

void GtkMenu_::popup_at_widget(Php::Parameters &parameters)
{
	// GtkWidget *widget;
	// if(parameters.size() > 0) {
	// 	Php::Value object_widget = parameters[0];
	// 	GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
	// 	widget = GTK_WIDGET(phpgtk_widget->get_instance());
	// }

	// GdkGravity *widget_anchor;
	// if(parameters.size() > 1) {
	// 	Php::Value object_widget_anchor = parameters[1];
	// 	GdkGravity_ *phpgtk_widget_anchor = (GdkGravity_ *)object_widget_anchor.implementation();
	// 	widget_anchor = GTK_WIDGET(phpgtk_widget_anchor->get_instance());
	// }

	// GdkGravity *menu_anchor;
	// if(parameters.size() > 2) {
	// 	Php::Value object_menu_anchor = parameters[2];
	// 	GdkGravity_ *phpgtk_menu_anchor = (GdkGravity_ *)object_menu_anchor.implementation();
	// 	menu_anchor = GTK_WIDGET(phpgtk_menu_anchor->get_instance());
	// }

	// GdkEvent *trigger_event;
	// if(parameters.size() > 3) {
	// 	Php::Value object_trigger_event = parameters[3];
	// 	GdkEvent_ *phpgtk_trigger_event = (GdkEvent_ *)object_trigger_event.implementation();
	// 	trigger_event = GTK_WIDGET(phpgtk_trigger_event->get_instance());
	// }

	// gtk_menu_popup_at_widget (GTK_MENU(instance), widget, widget_anchor, menu_anchor, trigger_event);

	throw Php::Exception("GtkMenu_::at_widget not implemented");

}

void GtkMenu_::popup_at_pointer (Php::Parameters &parameters)
{
	GdkEvent *trigger_event;
	Php::Value object_trigger_event = parameters[0];
	GdkEvent_ *phpgtk_trigger_event = (GdkEvent_ *)object_trigger_event.implementation();
	trigger_event = phpgtk_trigger_event->get_instance();

	gtk_menu_popup_at_pointer(GTK_MENU(instance), trigger_event);
}

void GtkMenu_::set_accel_group(Php::Parameters &parameters)
{
	// GtkAccelGroup *accel_group;
	// if(parameters.size() > 0) {
	// 	Php::Value object_accel_group = parameters[0];
	// 	GtkAccelGroup_ *phpgtk_accel_group = (GtkAccelGroup_ *)object_accel_group.implementation();
	// 	accel_group = GTK_WIDGET(phpgtk_accel_group->get_instance());
	// }

	// gtk_menu_set_accel_group (GTK_MENU(instance), accel_group);

	throw Php::Exception("GtkMenu_::set_accel_group not implemented");

}

Php::Value GtkMenu_::get_accel_group()
{
	// GtkAccelGroup *ret = gtk_menu_get_accel_group (GTK_MENU(instance));

	// GtkAccelGroup_ *return_parsed = new GtkAccelGroup_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkAccelGroup", return_parsed);

	throw Php::Exception("GtkMenu_::get_accel_group not implemented");
}

void GtkMenu_::set_accel_path(Php::Parameters &parameters)
{
	std::string s_accel_path = parameters[0];
	gchar *accel_path = (gchar *)s_accel_path.c_str();

	gtk_menu_set_accel_path (GTK_MENU(instance), accel_path);

}

Php::Value GtkMenu_::get_accel_path()
{
	std::string ret = gtk_menu_get_accel_path (GTK_MENU(instance));

	return ret;
}

void GtkMenu_::set_monitor(Php::Parameters &parameters)
{
	gint monitor_num = (gint)parameters[0];

	gtk_menu_set_monitor (GTK_MENU(instance), monitor_num);

}

Php::Value GtkMenu_::get_monitor()
{
	gint ret = gtk_menu_get_monitor (GTK_MENU(instance));

	return ret;
}

void GtkMenu_::place_on_monitor(Php::Parameters &parameters)
{
	// GdkMonitor *monitor;
	// if(parameters.size() > 0) {
	// 	Php::Value object_monitor = parameters[0];
	// 	GdkMonitor_ *phpgtk_monitor = (GdkMonitor_ *)object_monitor.implementation();
	// 	monitor = GTK_WIDGET(phpgtk_monitor->get_instance());
	// }

	// gtk_menu_place_on_monitor (GTK_MENU(instance), monitor);

	throw Php::Exception("GtkMenu_::place_on_monitor not implemented");

}

void GtkMenu_::set_reserve_toggle_size(Php::Parameters &parameters)
{
	gboolean reserve_toggle_size = (gboolean)parameters[0];

	gtk_menu_set_reserve_toggle_size (GTK_MENU(instance), reserve_toggle_size);

}

Php::Value GtkMenu_::get_reserve_toggle_size()
{
	gboolean ret = gtk_menu_get_reserve_toggle_size (GTK_MENU(instance));

	return ret;
}

void GtkMenu_::popdown()
{
	gtk_menu_popdown (GTK_MENU(instance));

}

void GtkMenu_::reposition()
{
	gtk_menu_reposition (GTK_MENU(instance));

}

Php::Value GtkMenu_::get_active()
{
	gpointer *ret = (gpointer *)gtk_menu_get_active (GTK_MENU(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	return cobject_to_phpobject(ret);
}

void GtkMenu_::set_active(Php::Parameters &parameters)
{
	guint index = (int)parameters[0];

	gtk_menu_set_active (GTK_MENU(instance), index);

}

void GtkMenu_::attach_to_widget(Php::Parameters &parameters)
{
	// GtkWidget *attach_widget;
	// if(parameters.size() > 0) {
	// 	Php::Value object_attach_widget = parameters[0];
	// 	GtkWidget_ *phpgtk_attach_widget = (GtkWidget_ *)object_attach_widget.implementation();
	// 	attach_widget = GTK_WIDGET(phpgtk_attach_widget->get_instance());
	// }

	// GtkMenuDetachFunc *detacher;
	// if(parameters.size() > 1) {
	// 	Php::Value object_detacher = parameters[1];
	// 	GtkMenuDetachFunc_ *phpgtk_detacher = (GtkMenuDetachFunc_ *)object_detacher.implementation();
	// 	detacher = GTK_WIDGET(phpgtk_detacher->get_instance());
	// }

	// gtk_menu_attach_to_widget (GTK_MENU(instance), attach_widget, detacher);

	throw Php::Exception("GtkMenu_::attach_to_widget not implemented");

}

void GtkMenu_::detach()
{
	gtk_menu_detach (GTK_MENU(instance));

}

Php::Value GtkMenu_::get_attach_widget()
{
	gpointer *ret = (gpointer *)gtk_menu_get_attach_widget (GTK_MENU(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
	return cobject_to_phpobject(ret);
}

Php::Value GtkMenu_::get_for_attach_widget()
{
	// GList ret = gtk_menu_get_for_attach_widget (GTK_MENU(instance));

	// return ret;

	throw Php::Exception("GtkMenu_::get_for_attach_widget not implemented");
}

