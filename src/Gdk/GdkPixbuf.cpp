
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
GdkPixbuf *GdkPixbuf_::get_instance()
{
    return instance;
}

/**
 * Set the original GdkPixbuf
 */
void GdkPixbuf_::set_instance(GdkPixbuf *pased_pixbuf)
{
    instance = pased_pixbuf;
}

/**
 *  PHP Constructor
 */
void GdkPixbuf_::__construct(Php::Parameters &parameters)
{
	
}

Php::Value GdkPixbuf_::new_from_file(Php::Parameters &parameters)
{
	std::string filename = parameters[0];

	// Create pixbuff
	GdkPixbuf *l_pixbuf = gdk_pixbuf_new_from_file(filename.c_str(), NULL);
	
	// Create the PHP-GTK object and set GTK object
	GdkPixbuf_ *pixbuf_ = new GdkPixbuf_();
	pixbuf_->set_instance(l_pixbuf);

	// Return PHP-GTK object
	return Php::Object("GdkPixbuf", pixbuf_);
}

Php::Value GdkPixbuf_::new_from_gd(Php::Parameters &parameters)
{
	Php::Value a = parameters[0];
	if (!a.instanceOf("gd")) throw Php::Exception("Not a GD resource");
	Php::call("var_dump", "OK1");
	Php::call("imagepng", a.implementation());
	Php::call("var_dump", "OK2");
	return 1;

	std::string filename = parameters[0];

	// Create pixbuff
	GdkPixbuf *l_pixbuf = gdk_pixbuf_new_from_file(filename.c_str(), NULL);
	
	// Create the PHP-GTK object and set GTK object
	GdkPixbuf_ *pixbuf_ = new GdkPixbuf_();
	pixbuf_->set_instance(l_pixbuf);

	// Return PHP-GTK object
	return Php::Object("GdkPixbuf", pixbuf_);
}

Php::Value GdkPixbuf_::new_from_file_at_size(Php::Parameters &parameters)
{
	std::string filename = parameters[0];

	int width = parameters[1];
	int height = parameters[2];

	// Create pixbuff
	GdkPixbuf *l_pixbuf = gdk_pixbuf_new_from_file_at_size(filename.c_str(), width, height, NULL);
	
	// Create the PHP-GTK object and set GTK object
	GdkPixbuf_ *pixbuf_ = new GdkPixbuf_();
	pixbuf_->set_instance(l_pixbuf);

	// Return PHP-GTK object
	return Php::Object("GdkPixbuf", pixbuf_);
}

Php::Value GdkPixbuf_::new_from_file_at_scale(Php::Parameters &parameters)
{
	std::string filename = parameters[0];

	int width = parameters[1];
	int height = parameters[2];
	gboolean preserve_aspect_ratio = parameters[3];

	// Create pixbuff
	GdkPixbuf *l_pixbuf = gdk_pixbuf_new_from_file_at_scale(filename.c_str(), width, height, preserve_aspect_ratio, NULL);
	
	// Create the PHP-GTK object and set GTK object
	GdkPixbuf_ *pixbuf_ = new GdkPixbuf_();
	pixbuf_->set_instance(l_pixbuf);

	// Return PHP-GTK object
	return Php::Object("GdkPixbuf", pixbuf_);
}

Php::Value GdkPixbuf_::get_file_info(Php::Parameters &parameters)
{
	throw Php::Exception("Use PHP methods to get file info");

	// std::string filename = parameters[0];

	// int width = 0;
	// int height = 0;

 //    GdkPixbufFormat *format = gdk_pixbuf_get_file_info(filename.c_str(), &width, &height);

 //    // Create the PHP-GTK object and set GTK object
	// GdkPixbufFormat_ *pixbuf_format_ = new GdkPixbufFormat_();
	// pixbuf_format_->set_instance(format);

 //    // Cria o retorno
 //    Php::Value arr;
 //    arr["width"] = width;
 //    arr["height"] = height;
 //    arr["format"] = Php::Object("GdkPixbufFormat", pixbuf_format_);
 //    arr[0] = arr["width"];
 //    arr[1] = arr["height"];
 //    arr[3] = arr["format"];

 //    return arr;
}


Php::Value GdkPixbuf_::get_colorspace()
{
	return gdk_pixbuf_get_colorspace(instance);
}

Php::Value GdkPixbuf_::get_n_channels()
{
	return gdk_pixbuf_get_n_channels(instance);
}

Php::Value GdkPixbuf_::get_has_alpha()
{
	return (bool)gdk_pixbuf_get_has_alpha(instance);
}

Php::Value GdkPixbuf_::get_pixels()
{
	return gdk_pixbuf_get_pixels(instance);
}

Php::Value GdkPixbuf_::get_width()
{
	return gdk_pixbuf_get_width(instance);
}

Php::Value GdkPixbuf_::get_height()
{
	return gdk_pixbuf_get_height(instance);
}

Php::Value GdkPixbuf_::get_rowstride()
{
	return gdk_pixbuf_get_rowstride(instance);
}

Php::Value GdkPixbuf_::get_option(Php::Parameters &parameters)
{
	std::string option = parameters[0];

	return gdk_pixbuf_get_option(instance, option.c_str());
}

Php::Value GdkPixbuf_::save(Php::Parameters &parameters)
{
	std::string filename = parameters[0];
	std::string type = parameters[1];

	gboolean ret = gdk_pixbuf_save(instance, filename.c_str(), type.c_str(), NULL, NULL);

	return (bool)ret;
}

