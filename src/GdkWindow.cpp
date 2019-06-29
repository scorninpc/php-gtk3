
#include "GdkWindow.h"

/**
 * Constructor
 */
GdkWindow_::GdkWindow_() = default;

/**
 * Destructor
 */
GdkWindow_::~GdkWindow_() = default;

void GdkWindow_::beep()
{
	gdk_window_beep (GDK_WINDOW(instance));

}

void GdkWindow_::maximize()
{
	gdk_window_maximize (GDK_WINDOW(instance));

}

Php::Value GdkWindow_::get_default_root_window()
{
	GdkWindow *ret = gdk_get_default_root_window();

    // Create the PHP-GTK object and set GTK object
    GdkWindow_ *widget_ = new GdkWindow_();
    widget_->set_instance((gpointer *)ret);
    return Php::Object("GdkWindow", widget_);
}

