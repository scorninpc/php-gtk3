
#include "GtkGrid.h"

/**
 * Constructor
 */
GtkGrid_::GtkGrid_() = default;

/**
 * Destructor
 */
GtkGrid_::~GtkGrid_() = default;

void GtkGrid_::__construct()
{
	instance = (gpointer *)gtk_grid_new ();

}

void GtkGrid_::attach(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint left = (gint)parameters[1];

	gint top = (gint)parameters[2];

	gint width = (gint)parameters[3];

	gint height = (gint)parameters[4];

	gtk_grid_attach (GTK_GRID(instance), child, left, top, width, height);

}

void GtkGrid_::attach_next_to(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	GtkWidget *sibling;
	if(parameters.size() > 1) {
		Php::Value object_sibling = parameters[1];
		GtkWidget_ *phpgtk_sibling = (GtkWidget_ *)object_sibling.implementation();
		sibling = GTK_WIDGET(phpgtk_sibling->get_instance());
	}

	int int_side = (int)parameters[2];
	GtkPositionType side = (GtkPositionType)int_side;

	gint width = (gint)parameters[3];

	gint height = (gint)parameters[4];

	gtk_grid_attach_next_to (GTK_GRID(instance), child, sibling, side, width, height);

}

Php::Value GtkGrid_::get_child_at(Php::Parameters &parameters)
{
	gint left = (gint)parameters[0];

	gint top = (gint)parameters[1];

	gpointer *ret = (gpointer *)gtk_grid_get_child_at (GTK_GRID(instance), left, top);

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

void GtkGrid_::insert_row(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	gtk_grid_insert_row (GTK_GRID(instance), position);

}

void GtkGrid_::insert_column(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	gtk_grid_insert_column (GTK_GRID(instance), position);

}

void GtkGrid_::remove_row(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	gtk_grid_remove_row (GTK_GRID(instance), position);

}

void GtkGrid_::remove_column(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	gtk_grid_remove_column (GTK_GRID(instance), position);

}

void GtkGrid_::insert_next_to(Php::Parameters &parameters)
{
	GtkWidget *sibling;
	if(parameters.size() > 0) {
		Php::Value object_sibling = parameters[0];
		GtkWidget_ *phpgtk_sibling = (GtkWidget_ *)object_sibling.implementation();
		sibling = GTK_WIDGET(phpgtk_sibling->get_instance());
	}

	int int_side = (int)parameters[1];
	GtkPositionType side = (GtkPositionType)int_side;

	gtk_grid_insert_next_to (GTK_GRID(instance), sibling, side);

}

void GtkGrid_::set_row_homogeneous(Php::Parameters &parameters)
{
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_grid_set_row_homogeneous (GTK_GRID(instance), homogeneous);

}

Php::Value GtkGrid_::get_row_homogeneous()
{
	bool ret = gtk_grid_get_row_homogeneous (GTK_GRID(instance));

	return ret;
}

void GtkGrid_::set_row_spacing(Php::Parameters &parameters)
{
	guint spacing = (int)parameters[0];

	gtk_grid_set_row_spacing (GTK_GRID(instance), spacing);

}

Php::Value GtkGrid_::get_row_spacing()
{
	int ret = gtk_grid_get_row_spacing (GTK_GRID(instance));

	return ret;
}

void GtkGrid_::set_column_homogeneous(Php::Parameters &parameters)
{
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_grid_set_column_homogeneous (GTK_GRID(instance), homogeneous);

}

Php::Value GtkGrid_::get_column_homogeneous()
{
	bool ret = gtk_grid_get_column_homogeneous (GTK_GRID(instance));

	return ret;
}

void GtkGrid_::set_column_spacing(Php::Parameters &parameters)
{
	guint spacing = (int)parameters[0];

	gtk_grid_set_column_spacing (GTK_GRID(instance), spacing);

}

Php::Value GtkGrid_::get_column_spacing()
{
	int ret = gtk_grid_get_column_spacing (GTK_GRID(instance));

	return ret;
}

void GtkGrid_::set_baseline_row(Php::Parameters &parameters)
{
	gint row = (gint)parameters[0];

	gtk_grid_set_baseline_row (GTK_GRID(instance), row);

}

Php::Value GtkGrid_::get_baseline_row()
{
	gint ret = gtk_grid_get_baseline_row (GTK_GRID(instance));

	return ret;
}

void GtkGrid_::set_row_baseline_position(Php::Parameters &parameters)
{
	gint row = (gint)parameters[0];

	int int_pos = (int)parameters[1];
	GtkBaselinePosition pos = (GtkBaselinePosition)int_pos;

	gtk_grid_set_row_baseline_position (GTK_GRID(instance), row, pos);

}

Php::Value GtkGrid_::get_row_baseline_position(Php::Parameters &parameters)
{
	gint row = (gint)parameters[0];

	GtkBaselinePosition ret = gtk_grid_get_row_baseline_position (GTK_GRID(instance), row);

	return ret;
}

