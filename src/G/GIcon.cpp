

#include "GIcon.h"
#include "../Gdk/GdkPixbuf.h"
#include "../Gtk/GtkLogSuppression.h"

/**
 * Constructor
 */
GIcon_::GIcon_() : instance(nullptr) {}

/**
 * Destructor
 */
GIcon_::~GIcon_()
{
	// GIcon is reference counted, so we need to unref it
	if (instance != nullptr) {
		g_object_unref(instance);
		instance = nullptr;
	}
}

/**
 * Return original GIcon
 */
GIcon *GIcon_::get_instance()
{
	return instance;
}

/**
 * Set the original GIcon
 */
void GIcon_::set_instance(GIcon *passed_gicon, bool add_reference)
{
	// If we already have an instance, unref it first
	if (instance != nullptr) {
		g_object_unref(instance);
	}
	
	instance = passed_gicon;
	
	// Add a reference if requested (default behavior for safety)
	// Pass add_reference=false when transferring ownership from a newly created object
	if (instance != nullptr && add_reference) {
		g_object_ref(instance);
	}
}

/**
 * PHP Constructor
 */
void GIcon_::__construct()
{
	// Empty constructor - instances are typically created via static methods
	instance = nullptr;
}

/**
 * Create a GIcon from a GdkPixbuf
 * 
 * This creates a GBytesIcon from the pixbuf data, which can be used
 * with gtk_status_icon_set_from_gicon without triggering the scale factor issue
 */
Php::Value GIcon_::new_from_pixbuf(Php::Parameters &parameters)
{
	// Validate parameters
	if (parameters.size() < 1) {
		throw Php::Exception("GIcon::new_from_pixbuf() requires 1 parameter: GdkPixbuf object");
	}
	
	// Get the GdkPixbuf from parameters
	Php::Value object_pixbuf = parameters[0];
	GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
	GdkPixbuf *pixbuf = phpgtk_pixbuf->get_instance();
	
	// Save the pixbuf to a byte array and create a GBytesIcon
	// This is necessary because GIcon is an interface and we need a concrete implementation
	gchar *buffer;
	gsize buffer_size;
	GError *error = nullptr;
	
	// GTK may call gtk_widget_get_scale_factor during subsequent icon operations,
	// even though this is just converting a pixbuf to PNG format.
	// Suppress the warning that occurs when the GIcon is later used with GtkStatusIcon.
	{
		GtkLogSuppressor suppressor;
		gdk_pixbuf_save_to_buffer(pixbuf, &buffer, &buffer_size, "png", &error, NULL);
	} // suppressor automatically cleaned up here
	
	if (error != nullptr) {
		std::string error_msg = error->message;
		g_error_free(error);
		throw Php::Exception("Failed to convert pixbuf to icon: " + error_msg);
	}
	
	// Create GBytes from the buffer
	GBytes *bytes = g_bytes_new_take(buffer, buffer_size);
	
	// Create a GBytesIcon from the bytes
	GIcon *gicon = g_bytes_icon_new(bytes);
	g_bytes_unref(bytes);
	
	// Create the PHP-GTK object and transfer ownership
	// Pass false to set_instance since we're transferring the reference from g_bytes_icon_new
	GIcon_ *gicon_ = new GIcon_();
	gicon_->set_instance(gicon, false);
	
	// Return PHP-GTK object
	return Php::Object("GIcon", gicon_);
}

/**
 * Create a GIcon from a stock ID
 * 
 * This creates a GThemedIcon from the stock ID, which can be used
 * with gtk_status_icon_set_from_gicon without triggering the scale factor issue
 */
Php::Value GIcon_::new_from_stock(Php::Parameters &parameters)
{
	// Validate parameters
	if (parameters.size() < 1) {
		throw Php::Exception("GIcon::new_from_stock() requires 1 parameter: stock_id");
	}
	
	std::string c_stock_id = parameters[0];
	const gchar *stock_id = c_stock_id.c_str();
	
	// GTK may call gtk_widget_get_scale_factor when this themed icon is later used,
	// even though g_themed_icon_new itself doesn't involve scale factor queries.
	// Suppress the warning that occurs when the GIcon is used with GtkStatusIcon.
	GtkLogSuppressor suppressor;
	GIcon *gicon = g_themed_icon_new(stock_id);
	
	// Create the PHP-GTK object and transfer ownership
	// Pass false to set_instance since we're transferring the reference from g_themed_icon_new
	GIcon_ *gicon_ = new GIcon_();
	gicon_->set_instance(gicon, false);
	
	// Return PHP-GTK object
	return Php::Object("GIcon", gicon_);
}
