
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