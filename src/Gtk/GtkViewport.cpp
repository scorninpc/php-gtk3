

#include "GtkViewport.h"

GtkViewport_::GtkViewport_() = default;
GtkViewport_::~GtkViewport_() = default;

Php::Value GtkViewport_::get_hadjustment()
{
	gpointer *ret = (gpointer *)gtk_viewport_get_hadjustment(GTK_VIEWPORT(instance));


	return cobject_to_phpobject(ret);
}

Php::Value GtkViewport_::get_vadjustment()
{
	gpointer *ret = (gpointer *)gtk_viewport_get_vadjustment(GTK_VIEWPORT(instance));


	return cobject_to_phpobject(ret);
}

void GtkViewport_::set_hadjustment(Php::Parameters &parameters)
{
	GtkAdjustment *adjustment;
	Php::Value object_adjustment = parameters[0];
	GtkAdjustment_ *phpgtk_adjustment = (GtkAdjustment_ *)object_adjustment.implementation();
	adjustment = GTK_ADJUSTMENT(phpgtk_adjustment->get_instance());

	gtk_viewport_set_hadjustment(GTK_VIEWPORT(instance), adjustment);
}

void GtkViewport_::set_vadjustment(Php::Parameters &parameters)
{
	GtkAdjustment *adjustment;
	Php::Value object_adjustment = parameters[0];
	GtkAdjustment_ *phpgtk_adjustment = (GtkAdjustment_ *)object_adjustment.implementation();
	adjustment = GTK_ADJUSTMENT(phpgtk_adjustment->get_instance());

	gtk_viewport_set_vadjustment(GTK_VIEWPORT(instance), adjustment);
}

void GtkViewport_::set_shadow_type(Php::Parameters &parameters)
{
	int int_type = parameters[0];
	GtkShadowType type = (GtkShadowType) int_type;

	gtk_viewport_set_shadow_type(GTK_VIEWPORT(instance), type);
}

Php::Value GtkViewport_::get_shadow_type()
{
	int ret = (int)gtk_viewport_get_shadow_type(GTK_VIEWPORT(instance));


	return ret;
}

Php::Value GtkViewport_::get_bin_window()
{
	gpointer *ret =(gpointer *)gtk_viewport_get_bin_window(GTK_VIEWPORT(instance));


	return cobject_to_phpobject(ret);
}

Php::Value GtkViewport_::get_view_window()
{
	gpointer *ret = (gpointer *)gtk_viewport_get_view_window(GTK_VIEWPORT(instance));


	return cobject_to_phpobject(ret);
}

void GtkViewport_::__construct(Php::Parameters &parameters)
{
	// GtkAdjustment *hadjustment;
	// Php::Value object_hadjustment = parameters[0];
	// GtkAdjustment_ *phpgtk_hadjustment = (GtkAdjustment_ *)object_hadjustment.implementation();
	// hadjustment = GTK_ADJUSTMENT(phpgtk_hadjustment->get_instance());

	// GtkAdjustment *vadjustment;
	// Php::Value object_vadjustment = parameters[1];
	// GtkAdjustment_ *phpgtk_vadjustment = (GtkAdjustment_ *)object_vadjustment.implementation();
	// vadjustment = GTK_ADJUSTMENT(phpgtk_vadjustment->get_instance());

	instance = (gpointer *)gtk_viewport_new(NULL, NULL);
}



