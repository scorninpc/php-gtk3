
#include "GtkMenuButton.h"

/**
 * Constructor
 */
GtkMenuButton_::GtkMenuButton_() = default;

/**
 * Destructor
 */
GtkMenuButton_::~GtkMenuButton_() = default;

void GtkMenuButton_::__construct()
{
	instance = (gpointer *)gtk_menu_button_new();
}