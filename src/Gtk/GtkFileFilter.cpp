
#include "GtkFileFilter.h"

/**
 * Constructor
 */
GtkFileFilter_::GtkFileFilter_() = default;

/**
 * Destructor
 */
GtkFileFilter_::~GtkFileFilter_() = default;

void GtkFileFilter_::__construct()
{
	instance = (gpointer *)gtk_file_filter_new ();

}

void GtkFileFilter_::set_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_file_filter_set_name (GTK_FILE_FILTER(instance), name);

}

Php::Value GtkFileFilter_::get_name()
{
	char * ret = (char *) gtk_file_filter_get_name (GTK_FILE_FILTER(instance));

	return ret;
}

void GtkFileFilter_::add_mime_type(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_file_filter_add_mime_type (GTK_FILE_FILTER(instance), name);

}

void GtkFileFilter_::add_pattern(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_file_filter_add_pattern (GTK_FILE_FILTER(instance), name);

}

void GtkFileFilter_::add_pixbuf_formats()
{
	gtk_file_filter_add_pixbuf_formats (GTK_FILE_FILTER(instance));

}

Php::Value GtkFileFilter_::get_needed()
{
	GtkFileFilterFlags ret = gtk_file_filter_get_needed (GTK_FILE_FILTER(instance));

	return ret;
}

Php::Value GtkFileFilter_::filter(Php::Parameters &parameters)
{
	// GtkFileFilterInfo *filter_info;
	// if(parameters.size() > 0) {
	// 	Php::Value object_filter_info = parameters[0];
	// 	GtkFileFilterInfo_ *phpgtk_filter_info = (GtkFileFilterInfo_ *)object_filter_info.implementation();
	// 	filter_info = GTK_WIDGET(phpgtk_filter_info->get_instance());
	// }

	// gboolean ret = gtk_file_filter_filter (GTK_FILE_FILTER(instance), filter_info);

	// return ret;
	return 1;
}

