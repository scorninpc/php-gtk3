
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

Php::Value GdkWindow_::get_window_type()
{
	return gdk_window_get_window_type(GDK_WINDOW(instance));
}

/**
 * https://developer.gnome.org/gdk3/stable/gdk3-Windows.html#gdk-window-get-children
 */
Php::Value GdkWindow_::get_children()
{
    GList *ret = gdk_window_get_children(GDK_WINDOW(instance));

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		
		GdkWindow_ *widget_ = new GdkWindow_();
		widget_->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("GdkWindow", widget_);
	}

	return ret_arr;
}

Php::Value GdkWindow_::get_width()
{
	return gdk_window_get_width(GDK_WINDOW(instance));
}

Php::Value GdkWindow_::get_height()
{
	return gdk_window_get_height(GDK_WINDOW(instance));
}

Php::Value GdkWindow_::get_position()
{
	    // Verify sizes
    int x = -1;
    int y = -1;

    gdk_window_get_position(GDK_WINDOW(instance), &x, &y);

    // Cria o retorno
    Php::Value arr;
    arr[0] = arr["x"] = x;
    arr[1] = arr["y"] = y;

    return arr;
}

void GdkWindow_::set_cursor(Php::Parameters &parameters)
{
	Php::Value object_cursor = parameters[0];
    GdkCursor_ *phpgtk_cursor = (GdkCursor_ *)object_cursor.implementation();
    GdkCursor *cursor = (GdkCursor *)phpgtk_cursor->get_instance();

	gdk_window_set_cursor(GDK_WINDOW(instance), cursor);
}