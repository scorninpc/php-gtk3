
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

void GdkPixbuf_::set_data(Php::Parameters& parameters)
{
	std::string s_key = parameters[0];
	gchar* key = (gchar*)s_key.c_str();

	std::string s_value = parameters[1];
	// Duplicate the string and store it
	gchar* value = g_strdup(s_value.c_str());

	// Store the duplicated string in the GObject, with g_free as the destroy notifier
	g_object_set_data_full(G_OBJECT(instance), key, value, (GDestroyNotify)g_free);
}

Php::Value GdkPixbuf_::get_data(Php::Parameters& parameters)
{
	std::string s_key = parameters[0];
	gchar* key = (gchar*)s_key.c_str();

	gpointer value = g_object_get_data(G_OBJECT(instance), key);

	if (value != NULL) {
		// Assuming the data is a string
		return Php::Value((char*)value);
	}
	else {
		return nullptr; // or return Php::Value(); to return NULL in PHP
	}
}

Php::Value GdkPixbuf_::get_byte_length()
{
	// Ensure the instance is not NULL
	if (instance == NULL) {
		throw Php::Exception("GdkPixbuf instance is NULL");
	}

	// Get the byte length of the pixbuf
	gsize length = gdk_pixbuf_get_byte_length(instance);

	// Return the length as an unsigned integer
	return Php::Value((int64_t)length);
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


Php::Value GdkPixbuf_::get_from_drawable(Php::Parameters &parameters)
{
	throw Php::Exception("GdkPixbuf_::get_from_drawable not implemented");
	// GdkPixbuf *screenshot;

	// [0] // Pixbuf para copiar
	// [1] // source
	// [2] // colormap
	// [3] // source_x
	// [4] // source_y
	// [5] // dest_x
	// [6] // dest_y
	// [7] // width
	// [8] // height

	// GdkWindow *drawable;
	// Php::Value object_drawable = parameters[0];
	// GdkWindow_ *phpgtk_drawable = (GdkWindow_ *)object_drawable.implementation();
	// drawable = GDK_WINDOW(phpgtk_drawable->get_instance());

	// int source_x = parameters[3];
	// int source_y = parameters[4];

	// int dest_x = parameters[5];
	// int dest_y = parameters[6];

	// int width = parameters[7];
	// int height = parameters[8];


	// screenshot = gdk_pixbuf_get_from_drawable (NULL, drawable, NULL, source_x, source_y, dest_x, dest_y, width, height);

	// // Create the PHP-GTK object and set GTK object
	// GdkWindow_ *widget_ = new GdkWindow_();
	// widget_->set_instance((gpointer *)ret);
	// return Php::Object("GdkWindow", widget_);
	return 1;
}

/**
 * https://developer.gnome.org/gdk-pixbuf/stable/gdk-pixbuf-Scaling.html#gdk-pixbuf-scale-simple
 */
Php::Value GdkPixbuf_::scale_simple(Php::Parameters &parameters)
{
	int width = parameters[0];
	int height = parameters[1];
	
	int int_type = (int)parameters[2];
	GdkInterpType type = (GdkInterpType)int_type;

	// Scale
	GdkPixbuf *l_pixbuf = gdk_pixbuf_scale_simple(GDK_PIXBUF(instance), width, height, type);
	
	// Create the PHP-GTK object and set GTK object
	GdkPixbuf_ *pixbuf_ = new GdkPixbuf_();
	pixbuf_->set_instance(l_pixbuf);

	// Return PHP-GTK object
	return Php::Object("GdkPixbuf", pixbuf_);
}