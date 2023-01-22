

#include "GtkSeparator.h"

GtkSeparator_::GtkSeparator_() = default;
GtkSeparator_::~GtkSeparator_() = default;

void GtkSeparator_::__construct(Php::Parameters &parameters)
{
	int porientation = parameters[0];
	GtkOrientation orientation = (GtkOrientation) porientation;

	instance = (gpointer *)gtk_separator_new(orientation);
}



