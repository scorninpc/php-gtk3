
#include "GtkImage.h"

/**
 * Constructor
 */
GtkImage_::GtkImage_() = default;

/**
 * Destructor
 */
GtkImage_::~GtkImage_() = default;

void GtkImage_::__construct()
{
	instance = (gpointer *)gtk_image_new ();

}

Php::Value GtkImage_::new_from_file(Php::Parameters &parameters)
{
	std::string s_filename = parameters[0];
	gchar *filename = (gchar *)s_filename.c_str();

	gpointer *ret = (gpointer *)gtk_image_new_from_file (filename);

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkImage_::new_from_icon_set(Php::Parameters &parameters)
{
	// int int_size = (int)parameters[0];
	// GtkIconSize size = (GtkIconSize)int_size;

	// GtkWidget *ret = gtk_image_new_from_icon_set (GTK_IMAGE(instance), size);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	Php::deprecated << "new_from_icon_set is deprecated on Gtk 3.10" << std::endl;
	return 0;
}

void GtkImage_::get_icon_set(Php::Parameters &parameters)
{
	// GtkIconSet *icon_set;
	// if(parameters.size() > 0) {
	// 	Php::Value object_icon_set = parameters[0];
	// 	GtkIconSet_ *phpgtk_icon_set = (GtkIconSet_ *)object_icon_set.implementation();
	// 	icon_set = GTK_WIDGET(phpgtk_icon_set->get_instance());
	// }

	// int int_size = (int)parameters[1];
	// GtkIconSize size = (GtkIconSize)int_size;

	// gtk_image_get_icon_set (GTK_IMAGE(instance), icon_set, size);

	throw Php::Exception("GtkImage_::get_icon_set not implemented");

}

Php::Value GtkImage_::get_pixbuf()
{
	gpointer *ret = (gpointer *)gtk_image_get_pixbuf (GTK_IMAGE(instance));

	return cobject_to_phpobject(ret);

	// GdkPixbuf_ *return_parsed = new GdkPixbuf_();
	// return_parsed->set_instance(ret);
	// return Php::Object("GdkPixbuf", return_parsed);
}

void GtkImage_::get_stock(Php::Parameters &parameters)
{
	// std::string s_stock_id = parameters[0];
	// gchar *stock_id = (gchar *)s_stock_id.c_str();

	// int int_size = (int)parameters[1];
	// GtkIconSize size = (GtkIconSize)int_size;

	// gtk_image_get_stock (GTK_IMAGE(instance), stock_id, size);

	Php::deprecated << "get_stock is deprecated on Gtk 3.10" << std::endl;

}

Php::Value GtkImage_::get_animation()
{
	// GdkPixbufAnimation ret = gtk_image_get_animation (GTK_IMAGE(instance));

	// return ret;

	throw Php::Exception("GtkImage_::get_animation not implemented");

	return 0;
}

Php::Value GtkImage_::get_icon_name(Php::Parameters &parameters)
{
	// const gchar *icon_name;

	// int int_size = (int)parameters[1];
	// GtkIconSize size = (GtkIconSize)int_size;

	// gtk_image_get_icon_name (GTK_IMAGE(instance), icon_name, size);

	throw Php::Exception("GtkImage_::get_icon_name not implemented");
	return 0;
}

void GtkImage_::get_gicon(Php::Parameters &parameters)
{

	// int int_size = (int)parameters[1];
	// GtkIconSize size = (GtkIconSize)int_size;

	// gtk_image_get_gicon (GTK_IMAGE(instance), gicon, size);

	throw Php::Exception("GtkImage_::get_gicon not implemented");
}

Php::Value GtkImage_::get_storage_type()
{
	GtkImageType ret = gtk_image_get_storage_type (GTK_IMAGE(instance));

	return ret;
}

Php::Value GtkImage_::new_from_pixbuf(Php::Parameters &parameters)
{

	GdkPixbuf *pixbuf;
	if(parameters.size() > 0) {
		Php::Value object_pixbuf = parameters[0];
		GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
		pixbuf = phpgtk_pixbuf->get_instance();
	}

	gpointer *ret = (gpointer *)gtk_image_new_from_pixbuf (pixbuf);

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkImage", return_parsed);
}

Php::Value GtkImage_::new_from_stock(Php::Parameters &parameters)
{
	// int int_size = (int)parameters[0];
	// GtkIconSize size = (GtkIconSize)int_size;

	// GtkWidget *ret = gtk_image_new_from_stock (GTK_IMAGE(instance), size);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	Php::deprecated << "new_from_stock is deprecated on Gtk 3.10" << std::endl;
	return 0;
}

Php::Value GtkImage_::new_from_animation()
{
	// GtkWidget *ret = gtk_image_new_from_animation (GTK_IMAGE(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	throw Php::Exception("GtkImage_::new_from_animation not implemented");

	return 0;
}

Php::Value GtkImage_::new_from_icon_name(Php::Parameters &parameters)
{
	std::string s_icon_name = parameters[0];
	gchar *icon_name = (gchar *)s_icon_name.c_str();

	int int_size = (int)parameters[1];
	GtkIconSize size = (GtkIconSize)int_size;

	gpointer *ret = (gpointer *)gtk_image_new_from_icon_name (icon_name, size);

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkImage", return_parsed);
}

Php::Value GtkImage_::new_from_gicon(Php::Parameters &parameters)
{
	throw Php::Exception("GtkImage_::new_from_gicon not implemented");

	return 0;
	// int int_size = (int)parameters[0];
	// GtkIconSize size = (GtkIconSize)int_size;

	// GtkWidget *ret = gtk_image_new_from_gicon (GTK_IMAGE(instance), size);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkImage_::new_from_resource(Php::Parameters &parameters)
{
	std::string s_resource_path = parameters[0];
	gchar *resource_path = (gchar *)s_resource_path.c_str();

	gpointer *ret = (gpointer *)gtk_image_new_from_resource (resource_path);

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkImage", return_parsed);
}

Php::Value GtkImage_::new_from_surface()
{
	// GtkWidget *ret = gtk_image_new_from_surface (GTK_IMAGE(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	throw Php::Exception("GtkImage_::new_from_surface not implemented");

	return 0;
}

void GtkImage_::set_from_file(Php::Parameters &parameters)
{
	std::string s_filename = parameters[0];
	gchar *filename = (gchar *)s_filename.c_str();

	gtk_image_set_from_file (GTK_IMAGE(instance), filename);

}

void GtkImage_::set_from_icon_set(Php::Parameters &parameters)
{
	// GtkIconSet *icon_set;
	// if(parameters.size() > 0) {
	// 	Php::Value object_icon_set = parameters[0];
	// 	GtkIconSet_ *phpgtk_icon_set = (GtkIconSet_ *)object_icon_set.implementation();
	// 	icon_set = GTK_WIDGET(phpgtk_icon_set->get_instance());
	// }

	// int int_size = (int)parameters[1];
	// GtkIconSize size = (GtkIconSize)int_size;

	// gtk_image_set_from_icon_set (GTK_IMAGE(instance), icon_set, size);

	Php::deprecated << "set_from_icon_set is deprecated on Gtk 3.10" << std::endl;

}

void GtkImage_::set_from_pixbuf(Php::Parameters &parameters)
{
	GdkPixbuf *pixbuf;
	if(parameters.size() > 0) {
		Php::Value object_pixbuf = parameters[0];
		GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
		pixbuf = phpgtk_pixbuf->get_instance();
	}

	gtk_image_set_from_pixbuf (GTK_IMAGE(instance), pixbuf);

}

void GtkImage_::set_from_stock(Php::Parameters &parameters)
{
	// std::string s_stock_id = parameters[0];
	// gchar *stock_id = (gchar *)s_stock_id.c_str();

	// int int_size = (int)parameters[1];
	// GtkIconSize size = (GtkIconSize)int_size;

	// gtk_image_set_from_stock (GTK_IMAGE(instance), stock_id, size);
	Php::deprecated << "set_from_stock is deprecated on Gtk 3.10" << std::endl;

}

void GtkImage_::set_from_animation(Php::Parameters &parameters)
{
	// GdkPixbufAnimation *animation;
	// if(parameters.size() > 0) {
	// 	Php::Value object_animation = parameters[0];
	// 	GdkPixbufAnimation_ *phpgtk_animation = (GdkPixbufAnimation_ *)object_animation.implementation();
	// 	animation = GTK_WIDGET(phpgtk_animation->get_instance());
	// }

	// gtk_image_set_from_animation (GTK_IMAGE(instance), animation);


	throw Php::Exception("GtkImage_::set_from_animation not implemented");

}

void GtkImage_::set_from_icon_name(Php::Parameters &parameters)
{
	std::string s_icon_name = parameters[0];
	gchar *icon_name = (gchar *)s_icon_name.c_str();

	int int_size = (int)parameters[1];
	GtkIconSize size = (GtkIconSize)int_size;

	gtk_image_set_from_icon_name (GTK_IMAGE(instance), icon_name, size);

}

void GtkImage_::set_from_gicon(Php::Parameters &parameters)
{

	// int int_size = (int)parameters[1];
	// GtkIconSize size = (GtkIconSize)int_size;

	// gtk_image_set_from_gicon (GTK_IMAGE(instance), icon, size);

	throw Php::Exception("GtkImage_::set_from_gicon not implemented");

}

void GtkImage_::set_from_resource(Php::Parameters &parameters)
{
	std::string s_resource_path = parameters[0];
	gchar *resource_path = (gchar *)s_resource_path.c_str();

	gtk_image_set_from_resource (GTK_IMAGE(instance), resource_path);

}

void GtkImage_::set_from_surface(Php::Parameters &parameters)
{

	// gtk_image_set_from_surface (GTK_IMAGE(instance), surface);

	throw Php::Exception("GtkImage_::set_from_surface not implemented");

}

void GtkImage_::clear()
{
	gtk_image_clear (GTK_IMAGE(instance));

}

void GtkImage_::set_pixel_size(Php::Parameters &parameters)
{
	gint pixel_size = (gint)parameters[0];

	gtk_image_set_pixel_size (GTK_IMAGE(instance), pixel_size);

}

Php::Value GtkImage_::get_pixel_size()
{
	gint ret = gtk_image_get_pixel_size (GTK_IMAGE(instance));

	return ret;
}

