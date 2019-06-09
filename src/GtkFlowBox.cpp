
#include "GtkFlowBox.h"

/**
 * Constructor
 */
GtkFlowBox_::GtkFlowBox_() = default;

/**
 * Destructor
 */
GtkFlowBox_::~GtkFlowBox_() = default;

void GtkFlowBox_::__construct()
{
	instance = (gpointer *)gtk_flow_box_new ();

}

void GtkFlowBox_::insert(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gint position = (gint)parameters[1];

	gtk_flow_box_insert (GTK_FLOW_BOX(instance), widget, position);

}

Php::Value GtkFlowBox_::get_child_at_index(Php::Parameters &parameters)
{
	gint idx = (gint)parameters[0];

	GtkFlowBoxChild *ret = gtk_flow_box_get_child_at_index (GTK_FLOW_BOX(instance), idx);

	GtkFlowBoxChild_ *return_parsed = new GtkFlowBoxChild_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkFlowBoxChild", return_parsed);
}

void GtkFlowBox_::set_hadjustment(Php::Parameters &parameters)
{
	GtkAdjustment *adjustment;
	if(parameters.size() > 0) {
		Php::Value object_adjustment = parameters[0];
		GtkAdjustment_ *phpgtk_adjustment = (GtkAdjustment_ *)object_adjustment.implementation();
		adjustment = GTK_ADJUSTMENT(phpgtk_adjustment->get_instance());
	}

	gtk_flow_box_set_hadjustment (GTK_FLOW_BOX(instance), adjustment);

}

void GtkFlowBox_::set_vadjustment(Php::Parameters &parameters)
{
	GtkAdjustment *adjustment;
	if(parameters.size() > 0) {
		Php::Value object_adjustment = parameters[0];
		GtkAdjustment_ *phpgtk_adjustment = (GtkAdjustment_ *)object_adjustment.implementation();
		adjustment = GTK_ADJUSTMENT(phpgtk_adjustment->get_instance());
	}

	gtk_flow_box_set_vadjustment (GTK_FLOW_BOX(instance), adjustment);

}

void GtkFlowBox_::set_homogeneous(Php::Parameters &parameters)
{
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_flow_box_set_homogeneous (GTK_FLOW_BOX(instance), homogeneous);

}

Php::Value GtkFlowBox_::get_homogeneous()
{
	gboolean ret = gtk_flow_box_get_homogeneous (GTK_FLOW_BOX(instance));

	return ret;
}

void GtkFlowBox_::set_row_spacing(Php::Parameters &parameters)
{
	guint spacing = (int)parameters[0];

	gtk_flow_box_set_row_spacing (GTK_FLOW_BOX(instance), spacing);

}

Php::Value GtkFlowBox_::get_row_spacing()
{
	int ret = gtk_flow_box_get_row_spacing (GTK_FLOW_BOX(instance));

	return ret;
}

void GtkFlowBox_::set_column_spacing(Php::Parameters &parameters)
{
	guint spacing = (int)parameters[0];

	gtk_flow_box_set_column_spacing (GTK_FLOW_BOX(instance), spacing);

}

Php::Value GtkFlowBox_::get_column_spacing()
{
	int ret = gtk_flow_box_get_column_spacing (GTK_FLOW_BOX(instance));

	return ret;
}

void GtkFlowBox_::set_min_children_per_line(Php::Parameters &parameters)
{
	guint n_children = (int)parameters[0];

	gtk_flow_box_set_min_children_per_line (GTK_FLOW_BOX(instance), n_children);

}

Php::Value GtkFlowBox_::get_min_children_per_line()
{
	int ret = gtk_flow_box_get_min_children_per_line (GTK_FLOW_BOX(instance));

	return ret;
}

void GtkFlowBox_::set_max_children_per_line(Php::Parameters &parameters)
{
	guint n_children = (int)parameters[0];

	gtk_flow_box_set_max_children_per_line (GTK_FLOW_BOX(instance), n_children);

}

Php::Value GtkFlowBox_::get_max_children_per_line()
{
	int ret = gtk_flow_box_get_max_children_per_line (GTK_FLOW_BOX(instance));

	return ret;
}

void GtkFlowBox_::set_activate_on_single_click(Php::Parameters &parameters)
{
	gboolean single = (gboolean)parameters[0];

	gtk_flow_box_set_activate_on_single_click (GTK_FLOW_BOX(instance), single);

}

Php::Value GtkFlowBox_::get_activate_on_single_click()
{
	gboolean ret = gtk_flow_box_get_activate_on_single_click (GTK_FLOW_BOX(instance));

	return ret;
}

void GtkFlowBox_::selected_foreach(Php::Parameters &parameters)
{
	// GtkFlowBoxForeachFunc *func;
	// if(parameters.size() > 0) {
	// 	Php::Value object_func = parameters[0];
	// 	GtkFlowBoxForeachFunc_ *phpgtk_func = (GtkFlowBoxForeachFunc_ *)object_func.implementation();
	// 	func = GTK_WIDGET(phpgtk_func->get_instance());
	// }

	// gpointer data = (gpointer)parameters[1];

	// gtk_flow_box_selected_foreach (GTK_FLOW_BOX(instance), func, data);

	throw Php::Exception("GtkFlowBox_::selected_foreach not implemented");

}

Php::Value GtkFlowBox_::get_selected_children()
{
	// GList ret = gtk_flow_box_get_selected_children (GTK_FLOW_BOX(instance));

	// return ret;

	throw Php::Exception("GtkFlowBox_::get_selected_children not implemented");
}

void GtkFlowBox_::select_child(Php::Parameters &parameters)
{
	GtkFlowBoxChild *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkFlowBoxChild_ *phpgtk_child = (GtkFlowBoxChild_ *)object_child.implementation();
		child = GTK_FLOW_BOX_CHILD(phpgtk_child->get_instance());
	}

	gtk_flow_box_select_child (GTK_FLOW_BOX(instance), child);

}

void GtkFlowBox_::unselect_child(Php::Parameters &parameters)
{
	GtkFlowBoxChild *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkFlowBoxChild_ *phpgtk_child = (GtkFlowBoxChild_ *)object_child.implementation();
		child = GTK_FLOW_BOX_CHILD(phpgtk_child->get_instance());
	}

	gtk_flow_box_unselect_child (GTK_FLOW_BOX(instance), child);

}

void GtkFlowBox_::select_all()
{
	gtk_flow_box_select_all (GTK_FLOW_BOX(instance));

}

void GtkFlowBox_::unselect_all()
{
	gtk_flow_box_unselect_all (GTK_FLOW_BOX(instance));

}

void GtkFlowBox_::set_selection_mode(Php::Parameters &parameters)
{
	int int_mode = (int)parameters[0];
	GtkSelectionMode mode = (GtkSelectionMode)int_mode;

	gtk_flow_box_set_selection_mode (GTK_FLOW_BOX(instance), mode);

}

Php::Value GtkFlowBox_::get_selection_mode()
{
	GtkSelectionMode ret = gtk_flow_box_get_selection_mode (GTK_FLOW_BOX(instance));

	return ret;
}

void GtkFlowBox_::set_filter_func(Php::Parameters &parameters)
{
	// GtkFlowBoxFilterFunc *filter_func;
	// if(parameters.size() > 0) {
	// 	Php::Value object_filter_func = parameters[0];
	// 	GtkFlowBoxFilterFunc_ *phpgtk_filter_func = (GtkFlowBoxFilterFunc_ *)object_filter_func.implementation();
	// 	filter_func = GTK_WIDGET(phpgtk_filter_func->get_instance());
	// }

	// gpointer user_data = (gpointer)parameters[1];


	// gtk_flow_box_set_filter_func (GTK_FLOW_BOX(instance), filter_func, user_data, destroy);

	throw Php::Exception("GtkFlowBox_::set_filter_func not implemented");

}

void GtkFlowBox_::invalidate_filter()
{
	gtk_flow_box_invalidate_filter (GTK_FLOW_BOX(instance));

}

void GtkFlowBox_::set_sort_func(Php::Parameters &parameters)
{
	// GtkFlowBoxSortFunc *sort_func;
	// if(parameters.size() > 0) {
	// 	Php::Value object_sort_func = parameters[0];
	// 	GtkFlowBoxSortFunc_ *phpgtk_sort_func = (GtkFlowBoxSortFunc_ *)object_sort_func.implementation();
	// 	sort_func = GTK_WIDGET(phpgtk_sort_func->get_instance());
	// }

	// gpointer user_data = (gpointer)parameters[1];


	// gtk_flow_box_set_sort_func (GTK_FLOW_BOX(instance), sort_func, user_data, destroy);

	throw Php::Exception("GtkFlowBox_::set_sort_func not implemented");

}

void GtkFlowBox_::invalidate_sort()
{
	gtk_flow_box_invalidate_sort (GTK_FLOW_BOX(instance));

}

void GtkFlowBox_::bind_model(Php::Parameters &parameters)
{

	// GtkFlowBoxCreateWidgetFunc *create_widget_func;
	// if(parameters.size() > 1) {
	// 	Php::Value object_create_widget_func = parameters[1];
	// 	GtkFlowBoxCreateWidgetFunc_ *phpgtk_create_widget_func = (GtkFlowBoxCreateWidgetFunc_ *)object_create_widget_func.implementation();
	// 	create_widget_func = GTK_WIDGET(phpgtk_create_widget_func->get_instance());
	// }

	// gpointer user_data = (gpointer)parameters[2];


	// gtk_flow_box_bind_model (GTK_FLOW_BOX(instance), model, create_widget_func, user_data, user_data_free_func);

	throw Php::Exception("GtkFlowBox_::bind_model not implemented");

}

