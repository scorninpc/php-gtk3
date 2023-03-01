#include "GtkCellRendererCombo.h"

GtkCellRendererCombo_::GtkCellRendererCombo_() = default;
GtkCellRendererCombo_::~GtkCellRendererCombo_() = default;


void GtkCellRendererCombo_::__construct()
{
	
	instance = (gpointer *)gtk_cell_renderer_combo_new();
}
