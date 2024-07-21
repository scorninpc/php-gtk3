
#include "GtkPaperSize.h"

/**
 * Return original instance
 */
GtkPaperSize *GtkPaperSize_::get_instance()
{
    return instance;
}

/**
 * Set the original gpointer
 */
void GtkPaperSize_::set_instance(GtkPaperSize *pased_instance)
{
    instance = pased_instance;
}

/**
 * Constructor
 */
GtkPaperSize_::GtkPaperSize_() = default;

/**
 * Destructor
 */
GtkPaperSize_::~GtkPaperSize_() = default;

void GtkPaperSize_::__construct(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	instance = gtk_paper_size_new (name);

}

Php::Value GtkPaperSize_::new_from_ppd(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	std::string s_ppd_display_name = parameters[1];
	gchar *ppd_display_name = (gchar *)s_ppd_display_name.c_str();

	gdouble width = (gdouble)parameters[2];

	gdouble height = (gdouble)parameters[3];

	GtkPaperSize *ret = gtk_paper_size_new_from_ppd (name, ppd_display_name, width, height);

	GtkPaperSize_ *return_parsed = new GtkPaperSize_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkPaperSize", return_parsed);
}

Php::Value GtkPaperSize_::new_from_ipp(Php::Parameters &parameters)
{

	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gdouble width = (gdouble)parameters[1];

	gdouble height = (gdouble)parameters[2];

	GtkPaperSize *ret = gtk_paper_size_new_from_ipp (name, width, height);

	GtkPaperSize_ *return_parsed = new GtkPaperSize_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkPaperSize", return_parsed);
}

Php::Value GtkPaperSize_::new_custom(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	std::string s_display_name = parameters[1];
	gchar *display_name = (gchar *)s_display_name.c_str();

	gdouble width = (gdouble)parameters[2];

	gdouble height = (gdouble)parameters[3];

	int int_unit = (int)parameters[4];
	GtkUnit unit = (GtkUnit)int_unit;

	GtkPaperSize *ret = gtk_paper_size_new_custom (name, display_name, width, height, unit);

	GtkPaperSize_ *return_parsed = new GtkPaperSize_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkPaperSize", return_parsed);
}

Php::Value GtkPaperSize_::copy()
{
	GtkPaperSize *ret = gtk_paper_size_copy (instance);

	GtkPaperSize_ *return_parsed = new GtkPaperSize_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkPaperSize", return_parsed);
}

void GtkPaperSize_::free()
{
	gtk_paper_size_free (instance);

}

Php::Value GtkPaperSize_::is_equal(Php::Parameters &parameters)
{
	GtkPaperSize *size2;
	if(parameters.size() > 0) {
		Php::Value object_size2 = parameters[0];
		GtkPaperSize_ *phpgtk_size2 = (GtkPaperSize_ *)object_size2.implementation();
		size2 = (phpgtk_size2->get_instance());
	}

	bool ret = gtk_paper_size_is_equal (instance, size2);

	return ret;
}

Php::Value GtkPaperSize_::get_paper_sizes()
{
	// GList ret = gtk_paper_size_get_paper_sizes (instance);

	// return ret;

	throw Php::Exception("GtkPaperSize_::get_paper_sizes not implemented");
	return 1;
}

Php::Value GtkPaperSize_::get_name()
{
	std::string ret = gtk_paper_size_get_name (instance);

	return ret;
}

Php::Value GtkPaperSize_::get_display_name()
{
	std::string ret = gtk_paper_size_get_display_name (instance);

	return ret;
}

Php::Value GtkPaperSize_::get_ppd_name()
{
	std::string ret = gtk_paper_size_get_ppd_name (instance);

	return ret;
}

Php::Value GtkPaperSize_::get_width(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_paper_size_get_width (instance, unit);

	return ret;
}

Php::Value GtkPaperSize_::get_height(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_paper_size_get_height (instance, unit);

	return ret;
}

Php::Value GtkPaperSize_::is_ipp()
{
	bool ret = gtk_paper_size_is_ipp (instance);

	return ret;
}

Php::Value GtkPaperSize_::is_custom()
{
	bool ret = gtk_paper_size_is_custom (instance);

	return ret;
}

void GtkPaperSize_::set_size(Php::Parameters &parameters)
{
	gdouble width = (gdouble)parameters[0];

	gdouble height = (gdouble)parameters[1];

	int int_unit = (int)parameters[2];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_paper_size_set_size (instance, width, height, unit);

}

Php::Value GtkPaperSize_::get_default_top_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_paper_size_get_default_top_margin (instance, unit);

	return ret;
}

Php::Value GtkPaperSize_::get_default_bottom_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_paper_size_get_default_bottom_margin (instance, unit);

	return ret;
}

Php::Value GtkPaperSize_::get_default_left_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_paper_size_get_default_left_margin (instance, unit);

	return ret;
}

Php::Value GtkPaperSize_::get_default_right_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_paper_size_get_default_right_margin (instance, unit);

	return ret;
}

Php::Value GtkPaperSize_::get_default()
{
	std::string ret = gtk_paper_size_get_default ();

	return ret;
}

Php::Value GtkPaperSize_::new_from_key_file(Php::Parameters &parameters)
{
	// std::string s_group_name = parameters[0];
	// gchar *group_name = (gchar *)s_group_name.c_str();


	// GtkPaperSize *ret = gtk_paper_size_new_from_key_file (instance, group_name, error);

	// GtkPaperSize_ *return_parsed = new GtkPaperSize_();
	// return_parsed->set_instance(ret);
	// return Php::Object("GtkPaperSize", return_parsed);

	throw Php::Exception("GtkPaperSize_::new_from_key_file not implemented");
	return 1;
}

void GtkPaperSize_::to_key_file(Php::Parameters &parameters)
{

	// std::string s_group_name = parameters[1];
	// gchar *group_name = (gchar *)s_group_name.c_str();

	// gtk_paper_size_to_key_file (instance, key_file, group_name);
	throw Php::Exception("GtkPaperSize_::to_key_file not implemented");
}

