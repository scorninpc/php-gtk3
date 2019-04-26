
#include "GdkPixbuf.h"

/**
 * Constructor
 */
GdkPixbuf_::GdkPixbuf_() = default;

/**
 * Destructor
 */
GdkPixbuf_::~GdkPixbuf_() = default;

/**
 * Return original GtkWidget
 */
GdkPixbuf *GdkPixbuf_::get_pixbuf()
{
    return pixbuf;
}

/**
 * Set the original GdkPixbuf
 */
void GdkPixbuf_::set_pixbuf(GdkPixbuf *pased_pixbuf)
{
    pixbuf = pased_pixbuf;
}

/**
 *  PHP Constructor
 */
void GdkPixbuf_::__construct(Php::Parameters &parameters)
{
	
}

/**
 * Creates a new pixbuf by loading an image from a file.
 */
Php::Value GdkPixbuf_::new_from_file(Php::Parameters &parameters)
{
	std::string filename = parameters[0];

	// Create pixbuff
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(filename.c_str(), NULL);
	
	// Create the PHP-GTK object and set GTK object
	GdkPixbuf_ *pixbuf_ = new GdkPixbuf_();
	pixbuf_->set_pixbuf(pixbuf);

	// Return PHP-GTK object
	return Php::Object("GdkPixbuf", pixbuf_);
}