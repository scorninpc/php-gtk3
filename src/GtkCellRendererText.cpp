
#include "GtkCellRendererText.h"

/**
 * Constructor
 */
GtkCellRendererText_::GtkCellRendererText_() = default;

/**
 * Destructor
 */
GtkCellRendererText_::~GtkCellRendererText_() = default;

/**
 *  PHP Constructor
 */
void GtkCellRendererText_::__construct(Php::Parameters &parameters)
{
	instance = (gpointer *)gtk_cell_renderer_text_new();
}

/**
 * If radio is TRUE, the cell renderer renders a radio toggle
 */
void GtkCellRendererText_::set_fixed_height_from_font(Php::Parameters &parameters)
{
    gtk_cell_renderer_text_set_fixed_height_from_font(GTK_CELL_RENDERER_TEXT(instance), parameters[0]);
}