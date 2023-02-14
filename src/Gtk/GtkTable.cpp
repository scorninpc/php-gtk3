#include "GtkTable.h"

GtkTable_::GtkTable_() = default;
GtkTable_::~GtkTable_() = default;


void GtkTable_::resize(Php::Parameters &parameters)
{
	
	int rows = (int)parameters[0];

	int columns = (int)parameters[1];

	gtk_table_resize(GTK_TABLE(instance), rows, columns);
}

void GtkTable_::attach(Php::Parameters &parameters)
{
	
	GtkWidget *child;
	Php::Value object_child = parameters[0];
	GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
	child = GTK_WIDGET(phpgtk_child->get_instance());

	int left_attach = (int)parameters[1];

	int right_attach = (int)parameters[2];

	int top_attach = (int)parameters[3];

	int bottom_attach = (int)parameters[4];

	int int_xoptions = parameters[5];
	GtkAttachOptions xoptions = (GtkAttachOptions) int_xoptions;

	int int_yoptions = parameters[6];
	GtkAttachOptions yoptions = (GtkAttachOptions) int_yoptions;

	int xpadding = (int)parameters[7];

	int ypadding = (int)parameters[8];

	gtk_table_attach(GTK_TABLE(instance), child, left_attach, right_attach, top_attach, bottom_attach, xoptions, yoptions, xpadding, ypadding);
}

void GtkTable_::attach_defaults(Php::Parameters &parameters)
{
	
	GtkWidget *widget;
	Php::Value object_widget = parameters[0];
	GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
	widget = GTK_WIDGET(phpgtk_widget->get_instance());

	int left_attach = (int)parameters[1];

	int right_attach = (int)parameters[2];

	int top_attach = (int)parameters[3];

	int bottom_attach = (int)parameters[4];

	gtk_table_attach_defaults(GTK_TABLE(instance), widget, left_attach, right_attach, top_attach, bottom_attach);
}

void GtkTable_::set_row_spacing(Php::Parameters &parameters)
{
	
	int row = (int)parameters[0];

	int spacing = (int)parameters[1];

	gtk_table_set_row_spacing(GTK_TABLE(instance), row, spacing);
}

Php::Value GtkTable_::get_row_spacing(Php::Parameters &parameters)
{
	
	int row = (int)parameters[0];

	guint ret = gtk_table_get_row_spacing(GTK_TABLE(instance), row);

	return (int)ret;
}

void GtkTable_::set_col_spacing(Php::Parameters &parameters)
{
	
	int column = (int)parameters[0];

	int spacing = (int)parameters[1];

	gtk_table_set_col_spacing(GTK_TABLE(instance), column, spacing);
}

Php::Value GtkTable_::get_col_spacing(Php::Parameters &parameters)
{
	
	int column = (int)parameters[0];

	guint ret = gtk_table_get_col_spacing(GTK_TABLE(instance), column);

	return (int)ret;
}

void GtkTable_::set_row_spacings(Php::Parameters &parameters)
{
	
	int spacing = (int)parameters[0];

	gtk_table_set_row_spacings(GTK_TABLE(instance), spacing);
}

Php::Value GtkTable_::get_default_row_spacing()
{
	
	guint ret = gtk_table_get_default_row_spacing(GTK_TABLE(instance));

	return (int)ret;
}

void GtkTable_::set_col_spacings(Php::Parameters &parameters)
{
	
	int spacing = (int)parameters[0];

	gtk_table_set_col_spacings(GTK_TABLE(instance), spacing);
}

Php::Value GtkTable_::get_default_col_spacing()
{
	
	guint ret = gtk_table_get_default_col_spacing(GTK_TABLE(instance));

	return (int)ret;
}

void GtkTable_::set_homogeneous(Php::Parameters &parameters)
{
	
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_table_set_homogeneous(GTK_TABLE(instance), homogeneous);
}

Php::Value GtkTable_::get_homogeneous()
{
	
	gboolean ret = gtk_table_get_homogeneous(GTK_TABLE(instance));

	return ret;
}

Php::Value GtkTable_::get_size(Php::Parameters &parameters)
{
	
	guint* rows;

	guint* columns;

	gtk_table_get_size(GTK_TABLE(instance), rows, columns);

	Php::Value arr;
	arr["rows"] = rows;
	arr["columns"] = columns;

	return arr;
}

void GtkTable_::__construct(Php::Parameters &parameters)
{
	
	int rows = (int)parameters[0];

	int columns = (int)parameters[1];

	gboolean homogeneous = (gboolean)parameters[2];

	instance = (gpointer *)gtk_table_new(rows, columns, homogeneous);
}
