
#include "GtkScrolledWindow.h"

/**
 * Constructor
 */
GtkScrolledWindow_::GtkScrolledWindow_() = default;

/**
 * Destructor
 */
GtkScrolledWindow_::~GtkScrolledWindow_() = default;

/**
 *  PHP Constructor
 */
void GtkScrolledWindow_::__construct(Php::Parameters &parameters)
{
	instance = (gpointer *)gtk_scrolled_window_new(NULL, NULL);
}