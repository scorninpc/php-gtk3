
#include "GdkMonitor.h"

/**
 * Constructor
 */
GdkMonitor_::GdkMonitor_() = default;

/**
 * Destructor
 */
GdkMonitor_::~GdkMonitor_() = default;

/**
 * Return original GtkWidget
 */
GdkMonitor *GdkMonitor_::get_instance()
{
    return instance;
}

/**
 * Set the original GdkMonitor
 */
void GdkMonitor_::set_instance(GdkMonitor *monitor)
{
    instance = monitor;
}

/**
 * https://developer.gnome.org/gdk3/stable/GdkMonitor.html#gdk-monitor-get-width-mm
 */
Php::Value GdkMonitor_::get_width_mm()
{
    return gdk_monitor_get_width_mm(GDK_MONITOR(instance));
}

/**
 * https://developer.gnome.org/gdk3/stable/GdkMonitor.html#gdk-monitor-get-height-mm
 */
Php::Value GdkMonitor_::get_height_mm()
{
    return gdk_monitor_get_height_mm(GDK_MONITOR(instance));
}

/**
 * https://developer.gnome.org/gdk3/stable/GdkMonitor.html#gdk-monitor-get-workarea
 */
Php::Value GdkMonitor_::get_workarea()
{
    // Allocate a GdkRectangle on the stack
    GdkRectangle workarea;
    
    // Fill in the workarea details
    gdk_monitor_get_workarea(GDK_MONITOR(instance), &workarea);

    // Create the return array
    Php::Value arr;
    arr["x"] = workarea.x;
    arr["y"] = workarea.y;
    arr["width"] = workarea.width;
    arr["height"] = workarea.height;

    return arr;
}

Php::Value GdkMonitor_::get_geometry()
{
	GdkRectangle rect;
	gdk_monitor_get_geometry((GdkMonitor *)instance, &rect);

	Php::Value arr;
	arr["x"] = rect.x;
	arr["y"] = rect.y;
	arr["width"] = rect.width;
	arr["height"] = rect.height;

	return arr;
}