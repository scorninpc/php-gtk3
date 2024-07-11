#include "PangoContext.h"

/**
 * Constructor
 */
PangoContext_::PangoContext_() = default;

/**
 * Destructor
 */
PangoContext_::~PangoContext_() = default;

void PangoContext_::__construct()
{
	instance = (gpointer *)pango_context_new ();
}
