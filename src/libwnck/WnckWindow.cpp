
#include "WnckWindow.h"

/**
 *  
 */
/**
 * Constructor
 */
WnckWindow_::WnckWindow_() = default;
WnckWindow_::~WnckWindow_() = default;

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-get-name
 */
Php::Value WnckWindow_::get_name()
{
	std::string ret = wnck_window_get_name(WNCK_WINDOW(instance));

	return ret;
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-get-icon
 */
Php::Value WnckWindow_::get_icon()
{
	GdkPixbuf *ret = wnck_window_get_icon(WNCK_WINDOW(instance));

	GdkPixbuf_ *widget_ = new GdkPixbuf_();
	widget_->set_instance(ret);
	return Php::Object("GdkPixbuf", widget_);
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-get-window-type
 */
Php::Value WnckWindow_::get_window_type()
{
	int ret = wnck_window_get_window_type(WNCK_WINDOW(instance));

	return ret;
}