#ifdef WITH_LIBWNCK
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
 * https://developer.gnome.org/gdk3/stable/gdk3-Testing.html#gdk-test-simulate-button
 */
Php::Value WnckWindow_::get_window(Php::Parameters &parameters)
{
	int xwindow = parameters[0];

	WnckWindow *ret = wnck_window_get(xwindow);

	// 
	WnckWindow_ *widget_ = new WnckWindow_();
	widget_->set_instance((gpointer *)ret);
	return Php::Object("WnckWindow", widget_);
}

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

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-get-xid
 */
Php::Value WnckWindow_::get_xid()
{
	int ret = wnck_window_get_xid(WNCK_WINDOW(instance));

	return ret;
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-get-xid
 */
Php::Value WnckWindow_::get_pid()
{
	int ret = wnck_window_get_pid(WNCK_WINDOW(instance));

	return ret;
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-get-class-group
 */
Php::Value WnckWindow_::get_class_group()
{
	WnckClassGroup *ret = wnck_window_get_class_group(WNCK_WINDOW(instance));

	WnckClassGroup_ *widget_ = new WnckClassGroup_();
	widget_->set_instance((gpointer *) ret);
	return Php::Object("WnckClassGroup", widget_);
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-is-active
 */
Php::Value WnckWindow_::is_active()
{
	gboolean ret = wnck_window_is_active(WNCK_WINDOW(instance));

	return ret;
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-minimize
 */
void WnckWindow_::minimize()
{
	wnck_window_minimize(WNCK_WINDOW(instance));
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-activate
 */
void WnckWindow_::activate(Php::Parameters &parameters)
{
	int time = parameters[0];

	wnck_window_activate(WNCK_WINDOW(instance), time);
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckWindow.html#wnck-window-close
 */
void WnckWindow_::close(Php::Parameters &parameters)
{
	int time = parameters[0];

	wnck_window_close(WNCK_WINDOW(instance), time);
}
#endif