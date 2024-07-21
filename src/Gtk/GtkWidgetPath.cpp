
#include "GtkWidgetPath.h"

/**
 * Return original instance
 */
GtkWidgetPath *GtkWidgetPath_::get_instance()
{
    return instance;
}

/**
 * Set the original gpointer
 */
void GtkWidgetPath_::set_instance(GtkWidgetPath *pased_instance)
{
    instance = pased_instance;
}

/**
 * Constructor
 */
GtkWidgetPath_::GtkWidgetPath_() = default;

/**
 * Destructor
 */
GtkWidgetPath_::~GtkWidgetPath_() = default;


void GtkWidgetPath_::__construct()
{
	instance = gtk_widget_path_new();
}

Php::Value GtkWidgetPath_::append_type(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GType type = (GType)int_type;

	gint ret = gtk_widget_path_append_type (instance, type);

	return ret;
}

Php::Value GtkWidgetPath_::append_with_siblings(Php::Parameters &parameters)
{
	GtkWidgetPath *siblings;
	if(parameters.size() > 0) {
		Php::Value object_siblings = parameters[0];
		GtkWidgetPath_ *phpgtk_siblings = (GtkWidgetPath_ *)object_siblings.implementation();
		siblings = (phpgtk_siblings->get_instance());
	}

	guint sibling_index = (int)parameters[1];

	gint ret = gtk_widget_path_append_with_siblings (instance, siblings, sibling_index);

	return ret;
}

Php::Value GtkWidgetPath_::append_for_widget(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gint ret = gtk_widget_path_append_for_widget (instance, widget);

	return ret;
}

Php::Value GtkWidgetPath_::copy()
{
	GtkWidgetPath *ret = gtk_widget_path_copy (instance);

	GtkWidgetPath_ *return_parsed = new GtkWidgetPath_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkWidgetPath", return_parsed);
}

Php::Value GtkWidgetPath_::ref()
{
	GtkWidgetPath *ret = gtk_widget_path_ref (instance);

	GtkWidgetPath_ *return_parsed = new GtkWidgetPath_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkWidgetPath", return_parsed);
}

void GtkWidgetPath_::unref()
{
	gtk_widget_path_unref (instance);

}

void GtkWidgetPath_::free()
{
	gtk_widget_path_free (instance);

}

Php::Value GtkWidgetPath_::get_object_type()
{
	GType ret = gtk_widget_path_get_object_type (instance);

	return (int)ret;
}

Php::Value GtkWidgetPath_::has_parent(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GType type = (GType)int_type;

	bool ret = gtk_widget_path_has_parent (instance, type);

	return ret;
}

Php::Value GtkWidgetPath_::is_type(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GType type = (GType)int_type;

	bool ret = gtk_widget_path_is_type (instance, type);

	return ret;
}

void GtkWidgetPath_::iter_add_class(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	gtk_widget_path_iter_add_class (instance, pos, name);

}

void GtkWidgetPath_::iter_add_region(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// std::string s_name = parameters[1];
	// gchar *name = (gchar *)s_name.c_str();

	// int int_flags = (int)parameters[2];
	// GtkRegionFlags flags = (GtkRegionFlags)int_flags;

	// gtk_widget_path_iter_add_region (instance, pos, name, flags);

	throw Php::Exception("GtkWidgetPath_::iter_add_region not implemented");

}

void GtkWidgetPath_::iter_clear_classes(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	gtk_widget_path_iter_clear_classes (instance, pos);

}

void GtkWidgetPath_::iter_clear_regions(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// gtk_widget_path_iter_clear_regions (instance, pos);

	throw Php::Exception("GtkWidgetPath_::iter_clear_regions not implemented");

}

Php::Value GtkWidgetPath_::iter_get_name(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	std::string ret = gtk_widget_path_iter_get_name (instance, pos);

	return ret;
}

Php::Value GtkWidgetPath_::iter_get_object_name(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	const char *ret = gtk_widget_path_iter_get_object_name (instance, pos);

	return ret;
}

Php::Value GtkWidgetPath_::iter_get_object_type(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	GType ret = gtk_widget_path_iter_get_object_type (instance, pos);

	return (int)ret;
}

Php::Value GtkWidgetPath_::iter_get_siblings(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// GtkWidgetPath *ret = gtk_widget_path_iter_get_siblings (instance, pos);

	// GtkWidgetPath_ *return_parsed = new GtkWidgetPath_();
	// return_parsed->set_instance(ret);
	// return Php::Object("GtkWidgetPath", return_parsed);
	throw Php::Exception("GtkWidgetPath_::iter_get_siblings not implemented");
	return 0;
}

Php::Value GtkWidgetPath_::iter_get_sibling_index(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	int ret = gtk_widget_path_iter_get_sibling_index (instance, pos);

	return ret;
}

Php::Value GtkWidgetPath_::iter_get_state(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	GtkStateFlags ret = gtk_widget_path_iter_get_state (instance, pos);

	return ret;
}

Php::Value GtkWidgetPath_::iter_has_class(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	bool ret = gtk_widget_path_iter_has_class (instance, pos, name);

	return ret;
}

Php::Value GtkWidgetPath_::iter_has_name(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	bool ret = gtk_widget_path_iter_has_name (instance, pos, name);

	return ret;
}

Php::Value GtkWidgetPath_::iter_has_qclass(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// bool ret = gtk_widget_path_iter_has_qclass (instance, pos, qname);

	// return ret;

	throw Php::Exception("GtkWidgetPath_::iter_has_qclass not implemented");
	return 0;
}

Php::Value GtkWidgetPath_::iter_has_qname(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];


	// bool ret = gtk_widget_path_iter_has_qname (instance, pos, qname);

	// return ret;

	throw Php::Exception("GtkWidgetPath_::iter_has_qname not implemented");
	return 0;
}

Php::Value GtkWidgetPath_::iter_has_qregion(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];


	// int int_flags = (int)parameters[2];
	// GtkRegionFlags flags = (GtkRegionFlags)int_flags;

	// bool ret = gtk_widget_path_iter_has_qregion (instance, pos, qname, flags);

	// return ret;

	throw Php::Exception("GtkWidgetPath_::iter_has_qregion not implemented");
	return 0;
}

Php::Value GtkWidgetPath_::iter_has_region(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// std::string s_name = parameters[1];
	// gchar *name = (gchar *)s_name.c_str();

	// int int_flags = (int)parameters[2];
	// GtkRegionFlags flags = (GtkRegionFlags)int_flags;

	// bool ret = gtk_widget_path_iter_has_region (instance, pos, name, flags);

	// return ret;

	throw Php::Exception("GtkWidgetPath_::iter_has_region not implemented");
	return 0;
}

Php::Value GtkWidgetPath_::iter_list_classes(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// GSList ret = gtk_widget_path_iter_list_classes (instance, pos);

	// return ret;
	throw Php::Exception("GtkWidgetPath_::iter_list_classes not implemented");
	return 0;
}

Php::Value GtkWidgetPath_::iter_list_regions(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// GSList ret = gtk_widget_path_iter_list_regions (instance, pos);

	// return ret;

	throw Php::Exception("GtkWidgetPath_::iter_list_regions not implemented");
	return 0;
}

void GtkWidgetPath_::iter_remove_class(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	gtk_widget_path_iter_remove_class (instance, pos, name);

}

void GtkWidgetPath_::iter_remove_region(Php::Parameters &parameters)
{
	// gint pos = (gint)parameters[0];

	// std::string s_name = parameters[1];
	// gchar *name = (gchar *)s_name.c_str();

	// gtk_widget_path_iter_remove_region (instance, pos, name);

	throw Php::Exception("GtkWidgetPath_::iter_remove_region not implemented");

}

void GtkWidgetPath_::iter_set_name(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	gtk_widget_path_iter_set_name (instance, pos, name);

}

void GtkWidgetPath_::iter_set_object_name(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	std::string s_name = parameters[1];
	gchar *name = (gchar *)s_name.c_str();

	gtk_widget_path_iter_set_object_name (instance, pos, name);

}

void GtkWidgetPath_::iter_set_object_type(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	int int_type = (int)parameters[1];
	GType type = (GType)int_type;

	gtk_widget_path_iter_set_object_type (instance, pos, type);

}

void GtkWidgetPath_::iter_set_state(Php::Parameters &parameters)
{
	gint pos = (gint)parameters[0];

	int int_state = (int)parameters[1];
	GtkStateFlags state = (GtkStateFlags)int_state;

	gtk_widget_path_iter_set_state (instance, pos, state);

}

Php::Value GtkWidgetPath_::length()
{
	gint ret = gtk_widget_path_length (instance);

	return ret;
}

void GtkWidgetPath_::prepend_type(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GType type = (GType)int_type;

	gtk_widget_path_prepend_type (instance, type);

}

Php::Value GtkWidgetPath_::to_string()
{
	char *ret = gtk_widget_path_to_string (instance);

	return ret;
}

