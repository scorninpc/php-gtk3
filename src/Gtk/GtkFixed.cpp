
#include "GtkFixed.h"

/**
 * Constructor
 */
GtkFixed_::GtkFixed_() = default;

/**
 * Destructor
 */
GtkFixed_::~GtkFixed_() = default;

void GtkFixed_::__construct()
{
	instance = (gpointer *)gtk_fixed_new ();

}

void GtkFixed_::put(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gint x = (gint)parameters[1];

	gint y = (gint)parameters[2];

	gtk_fixed_put (GTK_FIXED(instance), widget, x, y);

}

void GtkFixed_::move(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gint x = (gint)parameters[1];

	gint y = (gint)parameters[2];

	gtk_fixed_move (GTK_FIXED(instance), widget, x, y);

}

