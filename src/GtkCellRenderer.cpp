
#include "GtkCellRenderer.h"

/**
 * Constructor
 */
GtkCellRenderer_::GtkCellRenderer_() = default;

/**
 * Destructor
 */
GtkCellRenderer_::~GtkCellRenderer_() = default;

/**
 * Return original GtkCellRenderer
 */
GtkCellRenderer *GtkCellRenderer_::get_renderer()
{
    return renderer;
}

/**
 * Set the original GtkCellRenderer
 */
void GtkCellRenderer_::set_renderer(GtkCellRenderer *renderer)
{
    renderer = renderer;
}

/**
 *  PHP Constructor
 */
void GtkCellRenderer_::__construct(Php::Parameters &parameters)
{
	
}