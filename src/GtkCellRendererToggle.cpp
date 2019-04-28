
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
	renderer = gtk_cell_renderer_toggle_new();
}