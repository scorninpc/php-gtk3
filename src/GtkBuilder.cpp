
#include "GtkBuilder.h"

/**
 * Constructor
 */
GtkBuilder_::GtkBuilder_() = default;

/**
 * Destructor
 */
GtkBuilder_::~GtkBuilder_() = default;

void GtkBuilder_::__construct()
{
	instance = (gpointer *)gtk_builder_new ();

}

Php::Value GtkBuilder_::new_from_file(Php::Parameters &parameters)
{
	std::string s_filename = parameters[0];
	gchar *filename = (gchar *)s_filename.c_str();

	GtkBuilder *builder = gtk_builder_new_from_file (filename);

	GtkBuilder_ *phpgtk_builder = new GtkBuilder_();
	phpgtk_builder->set_instance((gpointer *)builder);
	return Php::Object("GtkBuilder", phpgtk_builder);

}

Php::Value GtkBuilder_::new_from_resource(Php::Parameters &parameters)
{
	std::string s_resource_path = parameters[0];
	gchar *resource_path = (gchar *)s_resource_path.c_str();

	GtkBuilder *builder = gtk_builder_new_from_resource (resource_path);

	GtkBuilder_ *phpgtk_builder = new GtkBuilder_();
	phpgtk_builder->set_instance((gpointer *)builder);
	return Php::Object("GtkBuilder", phpgtk_builder);
}

Php::Value GtkBuilder_::new_from_string(Php::Parameters &parameters)
{
	std::string s_string = parameters[0];
	gchar *string = (gchar *)s_string.c_str();

	GtkBuilder *builder = gtk_builder_new_from_string (string, s_string.length());

	GtkBuilder_ *phpgtk_builder = new GtkBuilder_();
	phpgtk_builder->set_instance((gpointer *)builder);
	return Php::Object("GtkBuilder", phpgtk_builder);
}

void GtkBuilder_::add_callback_symbol(Php::Parameters &parameters)
{
	// std::string s_callback_name = parameters[0];
	// gchar *callback_name = (gchar *)s_callback_name.c_str();

	// std::string s_add_callback_symbol = parameters[1];
	// gchar *add_callback_symbol = (gchar *)s_add_callback_symbol.c_str();

	// gtk_builder_add_callback_symbol ((instance), callback_name, add_callback_symbol);

	throw Php::Exception("GtkBuilder_::add_callback_symbol not implemented");
}

void GtkBuilder_::add_callback_symbols(Php::Parameters &parameters)
{
	// std::string s_callback_name = parameters[0];
	// gchar *callback_name = (gchar *)s_callback_name.c_str();

	// std::string s_add_callback_symbol = parameters[1];
	// gchar *add_callback_symbol = (gchar *)s_add_callback_symbol.c_str();

	// gtk_builder_add_callback_symbols ((instance), callback_name, add_callback_symbol);

	throw Php::Exception("GtkBuilder_::add_callback_symbols not implemented");
}

void GtkBuilder_::lookup_callback_symbol(Php::Parameters &parameters)
{
	// std::string s_callback_name = parameters[0];
	// gchar *callback_name = (gchar *)s_callback_name.c_str();

	// gtk_builder_lookup_callback_symbol ((instance), callback_name);

	throw Php::Exception("GtkBuilder_::lookup_callback_symbol not implemented");
}

Php::Value GtkBuilder_::add_from_file(Php::Parameters &parameters)
{
	std::string s_filename = parameters[0];
	gchar *filename = (gchar *)s_filename.c_str();

	GError *err = NULL;

	int ret = gtk_builder_add_from_file (GTK_BUILDER(instance), filename, &err);

	return ret;
}

Php::Value GtkBuilder_::add_from_resource(Php::Parameters &parameters)
{
	std::string s_resource_path = parameters[0];
	gchar *resource_path = (gchar *)s_resource_path.c_str();

	GError *err = NULL;

	int ret = gtk_builder_add_from_resource (GTK_BUILDER(instance), resource_path, &err);

	return ret;
}

Php::Value GtkBuilder_::add_from_string(Php::Parameters &parameters)
{
	std::string s_buffer = parameters[0];
	gchar *buffer = (gchar *)s_buffer.c_str();

	GError *err = NULL;

	int ret = gtk_builder_add_from_string (GTK_BUILDER(instance), buffer, s_buffer.length(), &err);

	return ret;
}

Php::Value GtkBuilder_::add_objects_from_file(Php::Parameters &parameters)
{
	// std::string s_buffer = parameters[0];
	// gchar *buffer = (gchar *)s_buffer.c_str();

	// GError *err = NULL;

	// int ret = gtk_builder_add_objects_from_file ((instance), buffer, &err);

	// return ret;

	throw Php::Exception("GtkBuilder_::add_objects_from_file not implemented");
}

Php::Value GtkBuilder_::add_objects_from_string(Php::Parameters &parameters)
{
	// std::string s_buffer = parameters[0];
	// gchar *buffer = (gchar *)s_buffer.c_str();

	// GError *err = NULL;

	// int ret = gtk_builder_add_objects_from_string ((instance), buffer, &err);

	// return ret;

	throw Php::Exception("GtkBuilder_::add_objects_from_string not implemented");
}

Php::Value GtkBuilder_::add_objects_from_resource(Php::Parameters &parameters)
{
	// std::string s_buffer = parameters[0];
	// gchar *buffer = (gchar *)s_buffer.c_str();

	// GError *err = NULL;

	// int ret = gtk_builder_add_objects_from_resource ((instance), buffer, &err);

	// return ret;

	throw Php::Exception("GtkBuilder_::add_objects_from_resource not implemented");
}

Php::Value GtkBuilder_::extend_with_template(Php::Parameters &parameters)
{
	// GtkWidget *widget;
	// if(parameters.size() > 0) {
	// 	Php::Value object_widget = parameters[0];
	// 	GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
	// 	widget = GTK_WIDGET(phpgtk_widget->get_instance());
	// }

	// GError *err = NULL;


	// std::string s_buffer = parameters[2];
	// gchar *buffer = (gchar *)s_buffer.c_str();

	// int ret = gtk_builder_extend_with_template ((instance), widget, template_type, buffer, &err);

	// return ret;

	throw Php::Exception("GtkBuilder_::extend_with_template not implemented");
}

Php::Value GtkBuilder_::get_object(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	GObject *object = gtk_builder_get_object (GTK_BUILDER(instance), name);

	// Get name of gType
	std::string gtype_name = g_type_name(G_TYPE_FROM_INSTANCE(object));

	// Return PHPGTK Object
	GObject_ *phpgtk_widget = new GObject_();
	phpgtk_widget->set_instance((gpointer *)object);
	return Php::Object(gtype_name.c_str(), phpgtk_widget);
}

Php::Value GtkBuilder_::get_objects()
{
	// GObject ret = gtk_builder_get_objects (GTK_BUILDER(instance));

	// return ret;

	throw Php::Exception("GtkBuilder_::get_objects not implemented");
}

void GtkBuilder_::expose_object(Php::Parameters &parameters)
{
	// std::string s_name = parameters[0];
	// gchar *name = (gchar *)s_name.c_str();


	// gtk_builder_expose_object (GTK_BUILDER(instance), name, object);

	throw Php::Exception("GtkBuilder_::expose_object not implemented");

}

void GtkBuilder_::connect_signals(Php::Parameters &parameters)
{
	// gpointer user_data = (gpointer)parameters[0];

	// gtk_builder_connect_signals (GTK_BUILDER(instance), user_data);

	throw Php::Exception("GtkBuilder_::connect_signals not implemented");

}

void GtkBuilder_::connect_signals_full(Php::Parameters &parameters)
{
	// std::string s_func = parameters[0];
	// gchar *func = (gchar *)s_func.c_str();

	// gpointer user_data = (gpointer)parameters[1];

	// gtk_builder_connect_signals_full (GTK_BUILDER(instance), func, user_data);

	throw Php::Exception("GtkBuilder_::connect_signals_full not implemented");

}

void GtkBuilder_::set_translation_domain(Php::Parameters &parameters)
{
	// std::string s_domain = parameters[0];
	// gchar *domain = (gchar *)s_domain.c_str();

	// gtk_builder_set_translation_domain (GTK_BUILDER(instance), domain);

	throw Php::Exception("GtkBuilder_::set_translation_domain not implemented");
}

Php::Value GtkBuilder_::get_translation_domain()
{
	// std::string ret = gtk_builder_get_translation_domain (GTK_BUILDER(instance));

	// return ret;

	throw Php::Exception("GtkBuilder_::get_translation_domain not implemented");
}

Php::Value GtkBuilder_::get_application()
{
	// GtkApplication *ret = gtk_builder_get_application ((instance));

	// GtkApplication_ *return_parsed = new GtkApplication_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkApplication", return_parsed);

	throw Php::Exception("GtkBuilder_::get_application not implemented");
}

void GtkBuilder_::set_application(Php::Parameters &parameters)
{
	// GtkApplication *application;
	// if(parameters.size() > 0) {
	// 	Php::Value object_application = parameters[0];
	// 	GtkApplication_ *phpgtk_application = (GtkApplication_ *)object_application.implementation();
	// 	application = GTK_WIDGET(phpgtk_application->get_instance());
	// }

	// gtk_builder_set_application ((instance), application);

	throw Php::Exception("GtkBuilder_::set_application not implemented");

}

Php::Value GtkBuilder_::get_type_from_name(Php::Parameters &parameters)
{
	std::string s_type_name = parameters[0];
	gchar *type_name = (gchar *)s_type_name.c_str();

	GType ret = gtk_builder_get_type_from_name (GTK_BUILDER(instance), type_name);

	return (int)ret;
}

Php::Value GtkBuilder_::value_from_string(Php::Parameters &parameters)
{
	// std::string s_type_name = parameters[0];
	// gchar *type_name = (gchar *)s_type_name.c_str();

	// gboolean ret = gtk_builder_value_from_string (GTK_BUILDER(instance), type_name);

	// return ret;

	throw Php::Exception("GtkBuilder_::value_from_string not implemented");
}

Php::Value GtkBuilder_::value_from_string_type(Php::Parameters &parameters)
{
	// std::string s_type_name = parameters[0];
	// gchar *type_name = (gchar *)s_type_name.c_str();

	// gboolean ret = gtk_builder_value_from_string_type (GTK_BUILDER(instance), type_name);

	// return ret;

	throw Php::Exception("GtkBuilder_::value_from_string_type not implemented");
}

