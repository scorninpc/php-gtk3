
#include "WnckScreen.h"

/**
 *  
 */
/**
 * Constructor
 */
WnckScreen_::WnckScreen_() = default;
WnckScreen_::~WnckScreen_() = default;

/**
 * https://developer.gnome.org/gdk3/stable/gdk3-Testing.html#gdk-test-simulate-button
 */
Php::Value WnckScreen_::get_default()
{
	WnckScreen *ret = wnck_screen_get_default();

	// 
	WnckScreen_ *widget_ = new WnckScreen_();
	widget_->set_instance((gpointer *)ret);
	return Php::Object("WnckScreen", widget_);
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckScreen.html#wnck-screen-get-active-window
 */
Php::Value WnckScreen_::get_active_window()
{
	WnckWindow *ret = wnck_screen_get_active_window(WNCK_SCREEN(instance));

	// 
	if (ret) {
		WnckWindow_ *widget_ = new WnckWindow_();
		widget_->set_instance((gpointer *)ret);
		return Php::Object("WnckWindow", widget_);
	}
	else {
		return NULL;
	}
}

