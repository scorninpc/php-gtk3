
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