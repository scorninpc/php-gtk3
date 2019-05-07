
#include "GtkTextView.h"

/**
 * Constructor
 */
GtkTextView_::GtkTextView_() = default;

/**
 * Destructor
 */
GtkTextView_::~GtkTextView_() = default;

void GtkTextView_::__construct()
{
	instance = (gpointer *)gtk_text_view_new ();

}

