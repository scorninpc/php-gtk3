
#include "GtkButtonBox.h"

/**
 * Constructor
 */
GtkButtonBox_::GtkButtonBox_() = default;

/**
 * Destructor
 */
GtkButtonBox_::~GtkButtonBox_() = default;

void GtkButtonBox_::__construct(Php::Parameters &parameters)
{
	int int_orientation = (int)parameters[0];
	GtkOrientation orientation = (GtkOrientation)int_orientation;

	instance = (gpointer *)gtk_button_box_new (orientation);

}

Php::Value GtkButtonBox_::get_layout()
{
	GtkButtonBoxStyle ret = gtk_button_box_get_layout (GTK_BUTTON_BOX(instance));

	return ret;
}

Php::Value GtkButtonBox_::get_child_secondary(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	bool ret = gtk_button_box_get_child_secondary (GTK_BUTTON_BOX(instance), child);

	return ret;
}

Php::Value GtkButtonBox_::get_child_non_homogeneous(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	bool ret = gtk_button_box_get_child_non_homogeneous (GTK_BUTTON_BOX(instance), child);

	return ret;
}

void GtkButtonBox_::set_layout(Php::Parameters &parameters)
{
	int int_layout_style = (int)parameters[0];
	GtkButtonBoxStyle layout_style = (GtkButtonBoxStyle)int_layout_style;

	gtk_button_box_set_layout (GTK_BUTTON_BOX(instance), layout_style);

}

void GtkButtonBox_::set_child_secondary(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean is_secondary = (gboolean)parameters[1];

	gtk_button_box_set_child_secondary (GTK_BUTTON_BOX(instance), child, is_secondary);

}

void GtkButtonBox_::set_child_non_homogeneous(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean non_homogeneous = (gboolean)parameters[1];

	gtk_button_box_set_child_non_homogeneous (GTK_BUTTON_BOX(instance), child, non_homogeneous);

}

