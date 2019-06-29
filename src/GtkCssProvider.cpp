
#include "GtkCssProvider.h"

/**
 * Constructor
 */
GtkCssProvider_::GtkCssProvider_() = default;

/**
 * Destructor
 */
GtkCssProvider_::~GtkCssProvider_() = default;

Php::Value GtkCssProvider_::get_named(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	std::string s_variant = parameters[1];
	gchar *variant = (gchar *)s_variant.c_str();

	GtkCssProvider *ret = gtk_css_provider_get_named (name, variant);

	GtkCssProvider_ *return_parsed = new GtkCssProvider_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkCssProvider", return_parsed);
}

Php::Value GtkCssProvider_::load_from_data(Php::Parameters &parameters)
{
	std::string s_data = parameters[0];
	gchar *data = (gchar *)s_data.c_str();

	gssize length = s_data.length();

	GError *error = NULL;

	gboolean ret = gtk_css_provider_load_from_data (GTK_CSS_PROVIDER(instance), data, length, &error);

	return ret;
}

Php::Value GtkCssProvider_::load_from_file(Php::Parameters &parameters)
{
	std::string s_file = parameters[0];
	gchar *filepath = (gchar *)s_file.c_str();

	GFile *file = g_file_new_for_path(filepath);

	GError *error = NULL;

	gboolean ret = gtk_css_provider_load_from_file (GTK_CSS_PROVIDER(instance), file, &error);

	return ret;
}

Php::Value GtkCssProvider_::load_from_path(Php::Parameters &parameters)
{
	std::string s_path = parameters[0];
	gchar *path = (gchar *)s_path.c_str();

	GError *error = NULL;

	gboolean ret = gtk_css_provider_load_from_path (GTK_CSS_PROVIDER(instance), path, &error);

	return ret;
}

void GtkCssProvider_::load_from_resource(Php::Parameters &parameters)
{
	std::string s_resource_path = parameters[0];
	gchar *resource_path = (gchar *)s_resource_path.c_str();

	gtk_css_provider_load_from_resource (GTK_CSS_PROVIDER(instance), resource_path);

}

void GtkCssProvider_::__construct()
{
	instance = (gpointer *)gtk_css_provider_new ();
}

Php::Value GtkCssProvider_::to_string()
{
	std::string ret = gtk_css_provider_to_string (GTK_CSS_PROVIDER(instance));

	return ret;
}

Php::Value GtkCssProvider_::gtk_css_section_get_end_line()
{
	// GtkCssSection *section;

	// int ret = gtk_css_section_get_end_line (section);

	// return ret;
	throw Php::Exception("GtkCssProvider_::gtk_css_section_get_end_line not implemented");
	return 1;
}

Php::Value GtkCssProvider_::gtk_css_section_get_end_position()
{
	// int ret = gtk_css_section_get_end_position (GTK_CSS_PROVIDER(instance));

	// return ret;
	throw Php::Exception("GtkCssProvider_::gtk_css_section_get_end_position not implemented");
	return 1;
}

Php::Value GtkCssProvider_::gtk_css_section_get_file()
{
	// std::string ret = gtk_css_section_get_file (GTK_CSS_PROVIDER(instance));

	// return ret;
	throw Php::Exception("GtkCssProvider_::gtk_css_section_get_file not implemented");
	return 1;
}

Php::Value GtkCssProvider_::gtk_css_section_get_parent()
{
	// GtkCssSection *ret = gtk_css_section_get_parent (GTK_CSS_PROVIDER(instance));

	// GtkCssSection_ *return_parsed = new GtkCssSection_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkCssSection", return_parsed);

	throw Php::Exception("GtkCssProvider_::gtk_css_section_get_parent not implemented");
	return 1;
}

Php::Value GtkCssProvider_::gtk_css_section_get_section_type()
{
	// GtkCssSectionType ret = gtk_css_section_get_section_type (GTK_CSS_PROVIDER(instance));

	// return ret;
	throw Php::Exception("GtkCssProvider_::gtk_css_section_get_section_type not implemented");
	return 1;
}

Php::Value GtkCssProvider_::gtk_css_section_get_start_line()
{
	// int ret = gtk_css_section_get_start_line (GTK_CSS_PROVIDER(instance));

	// return ret;

	throw Php::Exception("GtkCssProvider_::gtk_css_section_get_start_line not implemented");
	return 1;
}

Php::Value GtkCssProvider_::gtk_css_section_get_start_position()
{
	// int ret = gtk_css_section_get_start_position (GTK_CSS_PROVIDER(instance));

	// return ret;

	throw Php::Exception("GtkCssProvider_::gtk_css_section_get_start_position not implemented");
	return 1;
}

Php::Value GtkCssProvider_::gtk_css_section_ref()
{
	// GtkCssSection *ret = gtk_css_section_ref (GTK_CSS_PROVIDER(instance));

	// GtkCssSection_ *return_parsed = new GtkCssSection_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkCssSection", return_parsed);

	throw Php::Exception("GtkCssProvider_::gtk_css_section_ref not implemented");
	return 1;
}

void GtkCssProvider_::gtk_css_section_unref()
{
	// gtk_css_section_unref (GTK_CSS_PROVIDER(instance));

	throw Php::Exception("GtkCssProvider_::gtk_css_section_unref not implemented");

}

