
#include "GtkSpinner.h"

/**
 * Constructor
 */
GtkSpinner_::GtkSpinner_() = default;

/**
 * Destructor
 */
GtkSpinner_::~GtkSpinner_() = default;

void GtkSpinner_::__construct()
{
	instance = (gpointer *)gtk_spinner_new ();

}

void GtkSpinner_::start()
{
	gtk_spinner_start (GTK_SPINNER(instance));

}

void GtkSpinner_::stop()
{
	gtk_spinner_stop (GTK_SPINNER(instance));

}

