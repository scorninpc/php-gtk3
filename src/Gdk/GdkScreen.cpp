
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

/**
 * https://developer.gnome.org/gdk3/stable/GdkScreen.html#gdk-screen-get-rgba-visual
 */
Php::Value GdkScreen_::get_rgba_visual()
{
    GdkVisual *returndedValue = gdk_screen_get_rgba_visual(instance);

    GdkVisual_ *returnValue = new GdkVisual_();
    returnValue->set_instance((gpointer *)returndedValue);

    return Php::Object("GdkVisual", returnValue);
}

/**
 * https://developer.gnome.org/gdk3/stable/GdkScreen.html#gdk-screen-get-window-stack
 */
Php::Value GdkScreen_::get_window_stack()
{
    GList *ret = gdk_screen_get_window_stack(instance);

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		
		GdkWindow_ *widget_ = new GdkWindow_();
		widget_->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("GdkWindow", widget_);
	}

	return ret_arr;
}

Php::Value GdkScreen_::get_default()
{
    GdkScreen *ret = gdk_screen_get_default();

    GdkScreen_ *returnValue = new GdkScreen_();
    returnValue->set_instance(ret);

    return Php::Object("GdkScreen", returnValue);
}