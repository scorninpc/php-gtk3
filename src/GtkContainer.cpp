
#include "GtkContainer.h"

/**
 * Constructor
 */
GtkContainer_::GtkContainer_() = default;

/**
 * Destructor
 */
GtkContainer_::~GtkContainer_() = default;

void GtkContainer_::add(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gtk_container_add (GTK_CONTAINER(instance), widget);

}

void GtkContainer_::remove(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gtk_container_remove (GTK_CONTAINER(instance), widget);

}

void GtkContainer_::add_with_properties(Php::Parameters &parameters)
{
	// GtkWidget *widget;
	// if(parameters.size() > 0) {
	// 	Php::Value object_widget = parameters[0];
	// 	GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
	// 	widget = GTK_WIDGET(phpgtk_widget->get_instance());
	// }

	// std::string s_first_prop_name = parameters[1];
	// gchar *first_prop_name = (gchar *)s_first_prop_name.c_str();


	// gtk_container_add_with_properties (GTK_CONTAINER(instance), widget, first_prop_name, );

	throw Php::Exception("GtkContainer_::add_with_properties not implemented");
}

Php::Value GtkContainer_::get_resize_mode()
{
	// GtkResizeMode ret = gtk_container_get_resize_mode (GTK_CONTAINER(instance));

	Php::deprecated << "get_resize_mode is deprecated on Gtk 3.12" << std::endl;

	// return ret;
	return 0;
}

void GtkContainer_::set_resize_mode(Php::Parameters &parameters)
{
	// int int_resize_mode = (int)parameters[0];
	// GtkResizeMode resize_mode = (GtkResizeMode)int_resize_mode;

	// gtk_container_set_resize_mode (GTK_CONTAINER(instance), resize_mode);

	Php::deprecated << "set_resize_mode is deprecated on Gtk 3.12" << std::endl;

}

void GtkContainer_::check_resize()
{
	gtk_container_check_resize (GTK_CONTAINER(instance));

}

void GtkContainer_::foreach(Php::Parameters &parameters)
{
	// GtkCallback *callback;
	// if(parameters.size() > 0) {
	// 	Php::Value object_callback = parameters[0];
	// 	GtkCallback_ *phpgtk_callback = (GtkCallback_ *)object_callback.implementation();
	// 	callback = GTK_WIDGET(phpgtk_callback->get_instance());
	// }

	// gpointer callback_data = (gpointer)parameters[1];

	// gtk_container_foreach (GTK_CONTAINER(instance), callback, callback_data);

	throw Php::Exception("GtkContainer_::foreach not implemented");
}

Php::Value GtkContainer_::get_children()
{
	// GList ret = gtk_container_get_children (GTK_CONTAINER(instance));

	// return ret;

	throw Php::Exception("GtkContainer_::get_children not implemented");
}

Php::Value GtkContainer_::get_path_for_child(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	GtkWidgetPath *ret = gtk_container_get_path_for_child (GTK_CONTAINER(instance), child);

	GtkWidgetPath_ *return_parsed = new GtkWidgetPath_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkWidgetPath", return_parsed);
}

void GtkContainer_::set_reallocate_redraws(Php::Parameters &parameters)
{
	// gboolean needs_redraws = (gboolean)parameters[0];

	// gtk_container_set_reallocate_redraws (GTK_CONTAINER(instance), needs_redraws);

	Php::deprecated << "set_resize_mode is deprecated on Gtk 3.14" << std::endl;

}

Php::Value GtkContainer_::get_focus_child()
{
	GtkWidget *ret = gtk_container_get_focus_child (GTK_CONTAINER(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkContainer_::set_focus_child(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_container_set_focus_child (GTK_CONTAINER(instance), child);

}

Php::Value GtkContainer_::get_focus_vadjustment()
{
	GtkAdjustment *ret = gtk_container_get_focus_vadjustment (GTK_CONTAINER(instance));

	GtkAdjustment_ *return_parsed = new GtkAdjustment_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkAdjustment", return_parsed);
}

void GtkContainer_::set_focus_vadjustment(Php::Parameters &parameters)
{
	GtkAdjustment *adjustment;
	if(parameters.size() > 0) {
		Php::Value object_adjustment = parameters[0];
		GtkAdjustment_ *phpgtk_adjustment = (GtkAdjustment_ *)object_adjustment.implementation();
		adjustment = GTK_ADJUSTMENT(phpgtk_adjustment->get_instance());
	}

	gtk_container_set_focus_vadjustment (GTK_CONTAINER(instance), adjustment);

}

Php::Value GtkContainer_::get_focus_hadjustment()
{
	GtkAdjustment *ret = gtk_container_get_focus_hadjustment (GTK_CONTAINER(instance));

	GtkAdjustment_ *return_parsed = new GtkAdjustment_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkAdjustment", return_parsed);
}

void GtkContainer_::set_focus_hadjustment(Php::Parameters &parameters)
{
	GtkAdjustment *adjustment;
	if(parameters.size() > 0) {
		Php::Value object_adjustment = parameters[0];
		GtkAdjustment_ *phpgtk_adjustment = (GtkAdjustment_ *)object_adjustment.implementation();
		adjustment = GTK_ADJUSTMENT(phpgtk_adjustment->get_instance());
	}

	gtk_container_set_focus_hadjustment (GTK_CONTAINER(instance), adjustment);

}

void GtkContainer_::resize_children()
{
	// gtk_container_resize_children (GTK_CONTAINER(instance));

	Php::deprecated << "set_resize_mode is deprecated on Gtk 3.10" << std::endl;
}

Php::Value GtkContainer_::child_type()
{
	GType ret = gtk_container_child_type (GTK_CONTAINER(instance));

	return (int)ret;
}

void GtkContainer_::child_get(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }

	// std::string s_first_prop_name = parameters[1];
	// gchar *first_prop_name = (gchar *)s_first_prop_name.c_str();


	// gtk_container_child_get (GTK_CONTAINER(instance), child, first_prop_name, );

	throw Php::Exception("GtkContainer_::child_get not implemented");

}

void GtkContainer_::child_set(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }

	// std::string s_first_prop_name = parameters[1];
	// gchar *first_prop_name = (gchar *)s_first_prop_name.c_str();


	// gtk_container_child_set (GTK_CONTAINER(instance), child, first_prop_name, );

	throw Php::Exception("GtkContainer_::child_set not implemented");

}

void GtkContainer_::child_get_property(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }

	// std::string s_property_name = parameters[1];
	// gchar *property_name = (gchar *)s_property_name.c_str();


	// gtk_container_child_get_property (GTK_CONTAINER(instance), child, property_name, value);

	throw Php::Exception("GtkContainer_::child_get_property not implemented");

}

void GtkContainer_::child_set_property(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }

	// std::string s_property_name = parameters[1];
	// gchar *property_name = (gchar *)s_property_name.c_str();


	// gtk_container_child_set_property (GTK_CONTAINER(instance), child, property_name, value);

	throw Php::Exception("GtkContainer_::child_set_property not implemented");

}

void GtkContainer_::child_get_valist(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }

	// std::string s_first_property_name = parameters[1];
	// gchar *first_property_name = (gchar *)s_first_property_name.c_str();


	// gtk_container_child_get_valist (GTK_CONTAINER(instance), child, first_property_name, var_args);

	throw Php::Exception("GtkContainer_::child_get_valist not implemented");

}

void GtkContainer_::child_set_valist(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }

	// std::string s_first_property_name = parameters[1];
	// gchar *first_property_name = (gchar *)s_first_property_name.c_str();


	// gtk_container_child_set_valist (GTK_CONTAINER(instance), child, first_property_name, var_args);

	throw Php::Exception("GtkContainer_::child_set_valist not implemented");

}

void GtkContainer_::child_notify(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	std::string s_child_property = parameters[1];
	gchar *child_property = (gchar *)s_child_property.c_str();

	gtk_container_child_notify (GTK_CONTAINER(instance), child, child_property);

}

void GtkContainer_::child_notify_by_pspec(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }


	// gtk_container_child_notify_by_pspec (GTK_CONTAINER(instance), child, pspec);

	throw Php::Exception("GtkContainer_::child_notify_by_pspec not implemented");

}

void GtkContainer_::forall(Php::Parameters &parameters)
{
	// GtkCallback *callback;
	// if(parameters.size() > 0) {
	// 	Php::Value object_callback = parameters[0];
	// 	GtkCallback_ *phpgtk_callback = (GtkCallback_ *)object_callback.implementation();
	// 	callback = GTK_WIDGET(phpgtk_callback->get_instance());
	// }

	// gpointer callback_data = (gpointer)parameters[1];

	// gtk_container_forall (GTK_CONTAINER(instance), callback, callback_data);

	throw Php::Exception("GtkContainer_::forall not implemented");
}

Php::Value GtkContainer_::get_border_width()
{
	int ret = gtk_container_get_border_width (GTK_CONTAINER(instance));

	return ret;
}

void GtkContainer_::set_border_width(Php::Parameters &parameters)
{
	guint border_width = (int)parameters[0];

	gtk_container_set_border_width (GTK_CONTAINER(instance), border_width);

}

void GtkContainer_::propagate_draw(Php::Parameters &parameters)
{
	// GtkWidget *child;
	// if(parameters.size() > 0) {
	// 	Php::Value object_child = parameters[0];
	// 	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	// 	child = GTK_WIDGET(phpgtk_child->get_instance());
	// }


	// gtk_container_propagate_draw (GTK_CONTAINER(instance), child, cr);

	throw Php::Exception("GtkContainer_::propagate_draw not implemented");

}

Php::Value GtkContainer_::get_focus_chain(Php::Parameters &parameters)
{
	Php::deprecated << "get_focus_chain is deprecated on Gtk 3.24" << std::endl;

	throw Php::Exception("GtkContainer_::get_focus_chain not implemented");
}

void GtkContainer_::set_focus_chain(Php::Parameters &parameters)
{
	Php::deprecated << "set_focus_chain is deprecated on Gtk 3.24" << std::endl;
	
	throw Php::Exception("GtkContainer_::set_focus_chain not implemented");

}

void GtkContainer_::unset_focus_chain()
{
	gtk_container_unset_focus_chain (GTK_CONTAINER(instance));

}

Php::Value GtkContainer_::class_find_child_property(Php::Parameters &parameters)
{
	// std::string s_property_name = parameters[0];
	// gchar *property_name = (gchar *)s_property_name.c_str();

	// GParamSpec ret = gtk_container_class_find_child_property (GTK_CONTAINER(instance), property_name);

	// return ret;

	throw Php::Exception("GtkContainer_::class_find_child_property not implemented");
	return 0;
}

void GtkContainer_::class_install_child_property(Php::Parameters &parameters)
{
	// guint property_id = (int)parameters[0];


	// gtk_container_class_install_child_property (GTK_CONTAINER(instance), property_id, pspec);

	throw Php::Exception("GtkContainer_::class_install_child_property not implemented");
}

void GtkContainer_::class_install_child_properties(Php::Parameters &parameters)
{
	// guint n_pspecs = (int)parameters[0];


	// gtk_container_class_install_child_properties (GTK_CONTAINER(instance), n_pspecs, pspecs);

	throw Php::Exception("GtkContainer_::class_install_child_properties not implemented");

}

Php::Value GtkContainer_::class_list_child_properties(Php::Parameters &parameters)
{
	// guint n_properties = (int)parameters[0];

	// GParamSpec ret = *gtk_container_class_list_child_properties (GTK_CONTAINER(instance), n_properties);

	// return ret;

	throw Php::Exception("GtkContainer_::class_list_child_properties not implemented");
	return 0;
}

void GtkContainer_::class_handle_border_width()
{
	// gtk_container_class_handle_border_width (GTK_CONTAINER(instance));

	throw Php::Exception("GtkContainer_::class_handle_border_width not implemented");

}

