
#include "GtkDrawingArea.h"

GtkDrawingArea_::GtkDrawingArea_() = default;
GtkDrawingArea_::~GtkDrawingArea_() = default;

void GtkDrawingArea_::__construct()
{
	instance = (gpointer *)gtk_drawing_area_new ();
}
