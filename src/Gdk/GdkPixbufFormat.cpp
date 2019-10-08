
#include "GdkPixbufFormat.h"

/**
 * Constructor
 */
GdkPixbufFormat_::GdkPixbufFormat_() = default;

/**
 * Destructor
 */
GdkPixbufFormat_::~GdkPixbufFormat_() = default;

/**
 * Return original GtkWidget
 */
GdkPixbufFormat *GdkPixbufFormat_::get_instance()
{
    return instance;
}

/**
 * Set the original GdkPixbufFormat
 */
void GdkPixbufFormat_::set_instance(GdkPixbufFormat *pixbuf_format)
{
    instance = pixbuf_format;

    // get self reference as Php::Value object
    Php::Value self(this);

    // initialize a public property
    self["mime_types"] = gdk_pixbuf_format_get_name(pixbuf_format);
    // self["any"] = Php::Object("GdkEventAny", &event->any);
}