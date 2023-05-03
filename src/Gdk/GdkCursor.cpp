
#include "GdkCursor.h"

GdkCursor_::GdkCursor_() = default;
GdkCursor_::~GdkCursor_() = default;

/**
 *  PHP Constructor
 */
void GdkCursor_::__construct(Php::Parameters &parameters)
{
    int int_cursor_type = (int)parameters[0];
	GdkCursorType cursor_type = (GdkCursorType)int_cursor_type;

    instance = (gpointer *)gdk_cursor_new (cursor_type);
}

Php::Value GdkCursor_::new_for_display(Php::Parameters &parameters)
{
	Php::Value object_display = parameters[0];
    GdkDisplay_ *phpgtk_display = (GdkDisplay_ *)object_display.implementation();
    GdkDisplay *display = phpgtk_display->get_instance();

    int int_cursor_type = (int)parameters[1];
	GdkCursorType cursor_type = (GdkCursorType)int_cursor_type;

    gpointer *ret = (gpointer *)gdk_cursor_new_for_display(display, cursor_type);

    return cobject_to_phpobject(ret);
}

Php::Value GdkCursor_::new_from_name(Php::Parameters &parameters)
{
	Php::Value object_display = parameters[0];
    GdkDisplay_ *phpgtk_display = (GdkDisplay_ *)object_display.implementation();
    GdkDisplay *display = phpgtk_display->get_instance();

    std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

    gpointer *ret = (gpointer *)gdk_cursor_new_from_name(display, name);

    return cobject_to_phpobject(ret);
}

Php::Value GdkCursor_::new_from_pixbuf(Php::Parameters &parameters)
{
	Php::Value object_display = parameters[0];
    GdkDisplay_ *phpgtk_display = (GdkDisplay_ *)object_display.implementation();
    GdkDisplay *display = phpgtk_display->get_instance();

    Php::Value object_pixbuf = parameters[1];
    GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
    GdkPixbuf *pixbuf = phpgtk_pixbuf->get_instance();

    gint x = (int)parameters[2];

	gint y = (int)parameters[3];

    gpointer *ret = (gpointer *)gdk_cursor_new_from_pixbuf(display, pixbuf, x, y);

    return cobject_to_phpobject(ret);
}

Php::Value GdkCursor_::get_cursor_type()
{
    GdkCursorType ret = gdk_cursor_get_cursor_type(GDK_CURSOR(instance));

    return ret;
}

Php::Value GdkCursor_::get_display()
{
    gpointer *ret = (gpointer *)gdk_cursor_get_display(GDK_CURSOR(instance));

    return cobject_to_phpobject(ret);
}

Php::Value GdkCursor_::get_image()
{
    gpointer *ret = (gpointer *)gdk_cursor_get_image(GDK_CURSOR(instance));

    return cobject_to_phpobject(ret);
}