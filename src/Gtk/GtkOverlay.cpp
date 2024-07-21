
#include "GtkOverlay.h"

/**
 * Constructor
 */
GtkOverlay_::GtkOverlay_() = default;

/**
 * Destructor
 */
GtkOverlay_::~GtkOverlay_() = default;

void GtkOverlay_::__construct()
{
	instance = (gpointer *)gtk_overlay_new ();

}

void GtkOverlay_::add_overlay(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gtk_overlay_add_overlay (GTK_OVERLAY(instance), widget);

}

void GtkOverlay_::reorder_overlay(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint position = (gint)parameters[1];

	gtk_overlay_reorder_overlay (GTK_OVERLAY(instance), child, position);

}

Php::Value GtkOverlay_::get_overlay_pass_through(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	bool ret = gtk_overlay_get_overlay_pass_through (GTK_OVERLAY(instance), widget);

	return ret;
}

void GtkOverlay_::set_overlay_pass_through(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gboolean pass_through = (gboolean)parameters[1];

	gtk_overlay_set_overlay_pass_through (GTK_OVERLAY(instance), widget, pass_through);

}

