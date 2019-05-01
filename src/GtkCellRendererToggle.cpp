
#include "GtkCellRendererToggle.h"

/**
 * Constructor
 */
GtkCellRendererToggle_::GtkCellRendererToggle_() = default;

/**
 * Destructor
 */
GtkCellRendererToggle_::~GtkCellRendererToggle_() = default;

/**
 *  PHP Constructor
 */
void GtkCellRendererToggle_::__construct(Php::Parameters &parameters)
{
	instance = (gpointer *)gtk_cell_renderer_toggle_new();
}

/**
 *  PHP Constructor
 */
void GtkCellRendererToggle_::set_activatable(Php::Parameters &parameters)
{
	gtk_cell_renderer_toggle_set_activatable(GTK_CELL_RENDERER_TOGGLE(instance), parameters[0]);
}