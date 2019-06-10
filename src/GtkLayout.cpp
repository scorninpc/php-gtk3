
#include "GtkLayout.h"

/**
 * Constructor
 */
GtkLayout_::GtkLayout_() = default;

/**
 * Destructor
 */
GtkLayout_::~GtkLayout_() = default;

void GtkLayout_::__construct(Php::Parameters &parameters)
{
	GtkAdjustment *hadjustment;
	if(parameters.size() > 0) {
		Php::Value object_hadjustment = parameters[0];
		GtkAdjustment_ *phpgtk_hadjustment = (GtkAdjustment_ *)object_hadjustment.implementation();
		hadjustment = GTK_ADJUSTMENT(phpgtk_hadjustment->get_instance());
	}

	GtkAdjustment *vadjustment;
	if(parameters.size() > 1) {
		Php::Value object_vadjustment = parameters[1];
		GtkAdjustment_ *phpgtk_vadjustment = (GtkAdjustment_ *)object_vadjustment.implementation();
		vadjustment = GTK_ADJUSTMENT(phpgtk_vadjustment->get_instance());
	}

	instance = (gpointer *)gtk_layout_new (hadjustment, vadjustment);

}

void GtkLayout_::put(Php::Parameters &parameters)
{
	GtkWidget *child_widget;
	if(parameters.size() > 0) {
		Php::Value object_child_widget = parameters[0];
		GtkWidget_ *phpgtk_child_widget = (GtkWidget_ *)object_child_widget.implementation();
		child_widget = GTK_WIDGET(phpgtk_child_widget->get_instance());
	}

	gint x = (gint)parameters[1];

	gint y = (gint)parameters[2];

	gtk_layout_put (GTK_LAYOUT(instance), child_widget, x, y);

}

void GtkLayout_::move(Php::Parameters &parameters)
{
	GtkWidget *child_widget;
	if(parameters.size() > 0) {
		Php::Value object_child_widget = parameters[0];
		GtkWidget_ *phpgtk_child_widget = (GtkWidget_ *)object_child_widget.implementation();
		child_widget = GTK_WIDGET(phpgtk_child_widget->get_instance());
	}

	gint x = (gint)parameters[1];

	gint y = (gint)parameters[2];

	gtk_layout_move (GTK_LAYOUT(instance), child_widget, x, y);

}

void GtkLayout_::set_size(Php::Parameters &parameters)
{
	guint width = (int)parameters[0];

	guint height = (int)parameters[1];

	gtk_layout_set_size (GTK_LAYOUT(instance), width, height);

}

Php::Value GtkLayout_::get_size(Php::Parameters &parameters)
{
	guint width;

	guint height;

	gtk_layout_get_size (GTK_LAYOUT(instance), &width, &height);

	// Cria o retorno
    Php::Value arr;
    arr[0] = arr["width"] = (int)width;
    arr[1] = arr["height"] = (int)height;

    return arr;
}

Php::Value GtkLayout_::get_hadjustment()
{
	Php::deprecated << "get_hadjustment is deprecated on Gtk 3.0" << std::endl;
	return 0;
}

Php::Value GtkLayout_::get_vadjustment()
{
	Php::deprecated << "get_vadjustment is deprecated on Gtk 3.0" << std::endl;
	return 0;
}

void GtkLayout_::set_hadjustment(Php::Parameters &parameters)
{
	Php::deprecated << "set_hadjustment is deprecated on Gtk 3.0" << std::endl;
}

void GtkLayout_::set_vadjustment(Php::Parameters &parameters)
{
	Php::deprecated << "set_vadjustment is deprecated on Gtk 3.0" << std::endl;
}

Php::Value GtkLayout_::get_bin_window()
{
	// GdkWindow ret = gtk_layout_get_bin_window (GTK_LAYOUT(instance));

	// return ret;

	throw Php::Exception("GtkLayout_::get_bin_window not implemented yet");
	return 0;
}

