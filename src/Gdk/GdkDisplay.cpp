
#include "GdkDisplay.h"

/**
 * Constructor
 */
GdkDisplay_::GdkDisplay_() = default;

/**
 * Destructor
 */
GdkDisplay_::~GdkDisplay_() = default;

/**
 * Return original GtkWidget
 */
GdkDisplay *GdkDisplay_::get_instance()
{
    return instance;
}

/**
 * Set the original GdkDisplay
 */
void GdkDisplay_::set_instance(GdkDisplay *screen)
{
    instance = screen;
}

/**
 * https://developer.gnome.org/gdk3/stable/GdkDisplay.html#gdk-display-get-default
 */
Php::Value GdkDisplay_::get_default()
{
    GdkDisplay *returndedValue = gdk_display_get_default();

    GdkDisplay_ *returnValue = new GdkDisplay_();
    returnValue->set_instance(returndedValue);

    return Php::Object("GdkDisplay", returnValue);
}

/**
 * https://developer.gnome.org/gdk3/stable/GdkDisplay.html#gdk-display-get-primary-monitor
 */
Php::Value GdkDisplay_::get_primary_monitor()
{
    GdkMonitor *returndedValue = gdk_display_get_primary_monitor(GDK_DISPLAY(instance));

    GdkMonitor_ *returnValue = new GdkMonitor_();
    returnValue->set_instance(returndedValue);

    return Php::Object("GdkMonitor", returnValue);
}