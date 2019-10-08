
#include "GtkCellRendererPixbuf.h"

/**
 * Constructor
 */
GtkCellRendererPixbuf_::GtkCellRendererPixbuf_() = default;

/**
 * Destructor
 */
GtkCellRendererPixbuf_::~GtkCellRendererPixbuf_() = default;

void GtkCellRendererPixbuf_::__construct()
{
	instance = (gpointer *)gtk_cell_renderer_pixbuf_new ();

}

