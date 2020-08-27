
#include "GdkScreen.h"

/**
 * Constructor
 */
GdkScreen_::GdkScreen_() = default;

/**
 * Destructor
 */
GdkScreen_::~GdkScreen_() = default;

/**
 * Return original GtkWidget
 */
GdkScreen *GdkScreen_::get_instance()
{
    return instance;
}

/**
 * Set the original GdkScreen
 */
void GdkScreen_::set_instance(GdkScreen *screen)
{
    instance = screen;
}