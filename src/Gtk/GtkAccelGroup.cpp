
#include "GtkAccelGroup.h"

/**
 * Constructor
 */
GtkAccelGroup_::GtkAccelGroup_() = default;

/**
 * Destructor
 */
GtkAccelGroup_::~GtkAccelGroup_() = default;

/**
 *  PHP Constructor
 */
void GtkAccelGroup_::__construct()
{
	instance = (gpointer *)gtk_accel_group_new();
}