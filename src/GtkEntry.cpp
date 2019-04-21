
#include "GtkEntry.h"

/**
 *  C++ constructor and destructor
 */
GtkEntry_::GtkEntry_() = default;
GtkEntry_::~GtkEntry_() = default;

/**
 *  PHP Constructor
 */
void GtkEntry_::__construct()
{
	// Create the GtkEntry
	widget = gtk_entry_new();
}