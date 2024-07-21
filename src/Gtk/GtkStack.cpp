
#include "GtkStack.h"

/**
 * Constructor
 */
GtkStack_::GtkStack_() = default;

/**
 * Destructor
 */
GtkStack_::~GtkStack_() = default;

void GtkStack_::__construct()
{
	instance = (gpointer *)gtk_stack_new ();

}

void GtkStack_::add_named(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	gtk_stack_add_named (GTK_STACK(instance), child, name);

}

void GtkStack_::add_titled(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	std::string s_title = parameters[2];
	gchar *title = (gchar *)s_title.c_str();

	gtk_stack_add_titled (GTK_STACK(instance), child, name, title);

}


Php::Value GtkStack_::get_child_by_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gpointer *ret = (gpointer *)gtk_stack_get_child_by_name (GTK_STACK(instance), name);

	return cobject_to_phpobject(ret);
}

void GtkStack_::set_visible_child(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_stack_set_visible_child (GTK_STACK(instance), child);

}

Php::Value GtkStack_::get_visible_child()
{
	gpointer *ret = (gpointer *)gtk_stack_get_visible_child (GTK_STACK(instance));

	return cobject_to_phpobject(ret);
}

void GtkStack_::set_visible_child_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_stack_set_visible_child_name (GTK_STACK(instance), name);

}

Php::Value GtkStack_::get_visible_child_name()
{
	std::string ret = gtk_stack_get_visible_child_name (GTK_STACK(instance));

	return ret;
}

void GtkStack_::set_visible_child_full(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	int int_transition = (int)parameters[1];
	GtkStackTransitionType transition = (GtkStackTransitionType)int_transition;

	gtk_stack_set_visible_child_full (GTK_STACK(instance), name, transition);

}

void GtkStack_::set_homogeneous(Php::Parameters &parameters)
{
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_stack_set_homogeneous (GTK_STACK(instance), homogeneous);

}

Php::Value GtkStack_::get_homogeneous()
{
	bool ret = gtk_stack_get_homogeneous (GTK_STACK(instance));

	return ret;
}

void GtkStack_::set_hhomogeneous(Php::Parameters &parameters)
{
	gboolean hhomogeneous = (gboolean)parameters[0];

	gtk_stack_set_hhomogeneous (GTK_STACK(instance), hhomogeneous);

}

Php::Value GtkStack_::get_hhomogeneous()
{
	bool ret = gtk_stack_get_hhomogeneous (GTK_STACK(instance));

	return ret;
}

void GtkStack_::set_vhomogeneous(Php::Parameters &parameters)
{
	gboolean vhomogeneous = (gboolean)parameters[0];

	gtk_stack_set_vhomogeneous (GTK_STACK(instance), vhomogeneous);

}

Php::Value GtkStack_::get_vhomogeneous()
{
	bool ret = gtk_stack_get_vhomogeneous (GTK_STACK(instance));

	return ret;
}

void GtkStack_::set_transition_duration(Php::Parameters &parameters)
{
	guint duration = (int)parameters[0];

	gtk_stack_set_transition_duration (GTK_STACK(instance), duration);

}

Php::Value GtkStack_::get_transition_duration()
{
	int ret = gtk_stack_get_transition_duration (GTK_STACK(instance));

	return ret;
}

void GtkStack_::set_transition_type(Php::Parameters &parameters)
{
	int int_transition = (int)parameters[0];
	GtkStackTransitionType transition = (GtkStackTransitionType)int_transition;

	gtk_stack_set_transition_type (GTK_STACK(instance), transition);

}

Php::Value GtkStack_::get_transition_type()
{
	GtkStackTransitionType ret = gtk_stack_get_transition_type (GTK_STACK(instance));

	return ret;
}

Php::Value GtkStack_::get_transition_running()
{
	bool ret = gtk_stack_get_transition_running (GTK_STACK(instance));

	return ret;
}

Php::Value GtkStack_::get_interpolate_size()
{
	bool ret = gtk_stack_get_interpolate_size (GTK_STACK(instance));

	return ret;
}

void GtkStack_::set_interpolate_size(Php::Parameters &parameters)
{
	gboolean interpolate_size = (gboolean)parameters[0];

	gtk_stack_set_interpolate_size (GTK_STACK(instance), interpolate_size);

}

