
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
 *  Activates or deactivates a cell renderer.
 */
void GtkCellRendererToggle_::set_activatable(Php::Parameters &parameters)
{
	gtk_cell_renderer_toggle_set_activatable(GTK_CELL_RENDERER_TOGGLE(instance), parameters[0]);
}

/**
 * Returns whether the cell renderer is active
 */
Php::Value GtkCellRendererToggle_::get_activatable()
{
    // 
    return gtk_cell_renderer_toggle_get_activatable(GTK_CELL_RENDERER_TOGGLE(instance));
}

/**
 * If radio is TRUE, the cell renderer renders a radio toggle
 */
void GtkCellRendererToggle_::set_radio(Php::Parameters &parameters)
{
    gtk_cell_renderer_toggle_set_radio(GTK_CELL_RENDERER_TOGGLE(instance), parameters[0]);
}

/**
 * Returns whether we’re rendering radio toggles rather than checkboxes.
 */
Php::Value GtkCellRendererToggle_::get_radio()
{
    // 
    return gtk_cell_renderer_toggle_get_radio(GTK_CELL_RENDERER_TOGGLE(instance));
}

/**
 * Activates or deactivates a cell renderer.
 */
void GtkCellRendererToggle_::set_active(Php::Parameters &parameters)
{
    gtk_cell_renderer_toggle_set_active(GTK_CELL_RENDERER_TOGGLE(instance), parameters[0]);
}

/**
 * Returns whether the cell renderer is active.
 */
Php::Value GtkCellRendererToggle_::get_active()
{
    // 
    return gtk_cell_renderer_toggle_get_active(GTK_CELL_RENDERER_TOGGLE(instance));
}