
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
 *  PHP Constructor
 */
void GtkCellRenderer_::__construct(Php::Parameters &parameters)
{
}

/**
 * Sets the renderer’s alignment within its available space.
 */
void GtkCellRenderer_::set_alignment(Php::Parameters &parameters)
{
	double xalign = parameters[0];
	double yalign = parameters[1];
    gtk_cell_renderer_set_alignment(GTK_CELL_RENDERER(instance), xalign, yalign);
}

/**
 * Fills in xalign and yalign with the appropriate values of cell .
 */
Php::Value GtkCellRenderer_::get_alignment()
{
	float xalign = 0;
	float yalign = 0;

    gtk_cell_renderer_get_alignment(GTK_CELL_RENDERER(instance), &xalign, &yalign);

    // Cria o retorno
    Php::Value arr;
    arr["xalign"] = xalign;
    arr["yalign"] = yalign;

    return arr;
}