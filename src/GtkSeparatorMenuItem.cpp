
#include "GtkSeparatorMenuItem.h"

/**
 * Constructor
 */
GtkSeparatorMenuItem_::GtkSeparatorMenuItem_() = default;

/**
 * Destructor
 */
GtkSeparatorMenuItem_::~GtkSeparatorMenuItem_() = default;

void GtkSeparatorMenuItem_::__construct()
{
	instance = (gpointer *)gtk_separator_menu_item_new ();

}

