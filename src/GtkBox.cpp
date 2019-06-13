
#include "GtkBox.h"

/**
 * Constructor
 */
GtkBox_::GtkBox_() = default;

/**
 * Destructor
 */
GtkBox_::~GtkBox_() = default;

void GtkBox_::__construct(Php::Parameters &parameters)
{
	//phpgtk_check_parameter(parameters[0], Php::Type::Numeric, TRUE);

	int int_child = (int)parameters[0];
	GtkOrientation child = (GtkOrientation)int_child;

	gint spacing = (gint)parameters[1];

	instance = (gpointer *)gtk_box_new (child, spacing);

}

void GtkBox_::pack_start(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean expand = (gboolean)parameters[1];

	gboolean fill = (gboolean)parameters[2];

	guint padding = (int)parameters[3];

	gtk_box_pack_start (GTK_BOX(instance), child, expand, fill, padding);

}

void GtkBox_::pack_end(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean expand = (gboolean)parameters[1];

	gboolean fill = (gboolean)parameters[2];

	guint padding = (int)parameters[3];

	gtk_box_pack_end (GTK_BOX(instance), child, expand, fill, padding);

}

Php::Value GtkBox_::get_homogeneous()
{
	gboolean ret = gtk_box_get_homogeneous (GTK_BOX(instance));

	return ret;
}

void GtkBox_::set_homogeneous(Php::Parameters &parameters)
{
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_box_set_homogeneous (GTK_BOX(instance), homogeneous);

}

Php::Value GtkBox_::get_spacing()
{
	gboolean ret = gtk_box_get_spacing (GTK_BOX(instance));

	return ret;
}

void GtkBox_::set_spacing(Php::Parameters &parameters)
{
	gboolean spacing = (gboolean)parameters[0];

	gtk_box_set_spacing (GTK_BOX(instance), spacing);

}

void GtkBox_::reorder_child(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean position = (gboolean)parameters[1];

	gtk_box_reorder_child (GTK_BOX(instance), child, position);

}

Php::Value GtkBox_::query_child_packing(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean expand;

	gboolean fill;

	guint padding;

	GtkPackType pack_type;

	gtk_box_query_child_packing (GTK_BOX(instance), child, &expand, &fill, &padding, &pack_type);


	// Cria o retorno
    Php::Value arr;
    
    arr["expand"] = (bool)expand;
    arr[0] = arr["expand"];

    arr["fill"] = (bool)fill;
    arr[1] = arr["fill"];

    arr["padding"] = (int)padding;
    arr[2] = arr["padding"];

    arr["pack_type"] = pack_type;
    arr[3] = (int)arr["pack_type"];
    

	return arr;
}

void GtkBox_::set_child_packing(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean expand = (gboolean)parameters[1];

	gboolean fill = (gboolean)parameters[2];

	guint padding = (int)parameters[3];

	int int_pack_type = (int)parameters[4];
	GtkPackType pack_type = (GtkPackType)int_pack_type;

	gtk_box_set_child_packing (GTK_BOX(instance), child, expand, fill, padding, pack_type);

}

Php::Value GtkBox_::get_baseline_position()
{
	GtkBaselinePosition ret = gtk_box_get_baseline_position (GTK_BOX(instance));

	return ret;
}

void GtkBox_::set_baseline_position(Php::Parameters &parameters)
{
	int int_position = (int)parameters[0];
	GtkBaselinePosition position = (GtkBaselinePosition)int_position;

	gtk_box_set_baseline_position (GTK_BOX(instance), position);

}

Php::Value GtkBox_::get_center_widget()
{
	GtkWidget *ret = gtk_box_get_center_widget (GTK_BOX(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkBox_::set_center_widget(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gtk_box_set_center_widget (GTK_BOX(instance), widget);

}

