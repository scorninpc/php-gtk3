
#include "GtkPageSetup.h"

/**
 * Constructor
 */
GtkPageSetup_::GtkPageSetup_() = default;

/**
 * Destructor
 */
GtkPageSetup_::~GtkPageSetup_() = default;

void GtkPageSetup_::__construct()
{
	instance = (gpointer *)gtk_page_setup_new ();

}

Php::Value GtkPageSetup_::new_from_file(Php::Parameters &parameters)
{

	std::string s_file_name = parameters[0];
	gchar *file_name = (gchar *)s_file_name.c_str();

	GError *error;
	GtkPageSetup *ret = gtk_page_setup_new_from_file (file_name, &error);

	GtkPageSetup_ *return_parsed = new GtkPageSetup_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkPageSetup", return_parsed);
}

Php::Value GtkPageSetup_::new_from_key_file(Php::Parameters &parameters)
{
	// std::string s_group_name = parameters[0];
	// gchar *group_name = (gchar *)s_group_name.c_str();


	// GtkPageSetup *ret = gtk_page_setup_new_from_key_file (group_name, error);

	// GtkPageSetup_ *return_parsed = new GtkPageSetup_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkPageSetup", return_parsed);

	throw Php::Exception("GtkPageSetup_::new_from_key_file not implemented");
	return 1;
}

Php::Value GtkPageSetup_::copy()
{
	GtkPageSetup *ret = gtk_page_setup_copy (GTK_PAGE_SETUP(instance));

	GtkPageSetup_ *return_parsed = new GtkPageSetup_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkPageSetup", return_parsed);
}

Php::Value GtkPageSetup_::get_orientation()
{
	GtkPageOrientation ret = gtk_page_setup_get_orientation (GTK_PAGE_SETUP(instance));

	return ret;
}

void GtkPageSetup_::set_orientation(Php::Parameters &parameters)
{
	int int_orientation = (int)parameters[0];
	GtkPageOrientation orientation = (GtkPageOrientation)int_orientation;

	gtk_page_setup_set_orientation (GTK_PAGE_SETUP(instance), orientation);

}

Php::Value GtkPageSetup_::get_paper_size()
{
	GtkPaperSize *ret = gtk_page_setup_get_paper_size (GTK_PAGE_SETUP(instance));

	GtkPaperSize_ *return_parsed = new GtkPaperSize_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkPaperSize", return_parsed);
}

void GtkPageSetup_::set_paper_size(Php::Parameters &parameters)
{
	GtkPaperSize *paper_size;
	if(parameters.size() > 0) {
		Php::Value object_paper_size = parameters[0];
		GtkPaperSize_ *phpgtk_paper_size = (GtkPaperSize_ *)object_paper_size.implementation();
		paper_size = (phpgtk_paper_size->get_instance());
	}

	gtk_page_setup_set_paper_size (GTK_PAGE_SETUP(instance), paper_size);

}

Php::Value GtkPageSetup_::get_top_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_top_margin (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

void GtkPageSetup_::set_top_margin(Php::Parameters &parameters)
{
	gdouble margin = (gdouble)parameters[0];

	int int_unit = (int)parameters[1];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_page_setup_set_top_margin (GTK_PAGE_SETUP(instance), margin, unit);

}

Php::Value GtkPageSetup_::get_bottom_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_bottom_margin (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

void GtkPageSetup_::set_bottom_margin(Php::Parameters &parameters)
{
	gdouble margin = (gdouble)parameters[0];

	int int_unit = (int)parameters[1];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_page_setup_set_bottom_margin (GTK_PAGE_SETUP(instance), margin, unit);

}

Php::Value GtkPageSetup_::get_left_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_left_margin (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

void GtkPageSetup_::set_left_margin(Php::Parameters &parameters)
{
	gdouble margin = (gdouble)parameters[0];

	int int_unit = (int)parameters[1];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_page_setup_set_left_margin (GTK_PAGE_SETUP(instance), margin, unit);

}

Php::Value GtkPageSetup_::get_right_margin(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_right_margin (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

void GtkPageSetup_::set_right_margin(Php::Parameters &parameters)
{
	gdouble margin = (gdouble)parameters[0];

	int int_unit = (int)parameters[1];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_page_setup_set_right_margin (GTK_PAGE_SETUP(instance), margin, unit);

}

void GtkPageSetup_::set_paper_size_and_default_margins(Php::Parameters &parameters)
{
	GtkPaperSize *paper_size;
	if(parameters.size() > 0) {
		Php::Value object_paper_size = parameters[0];
		GtkPaperSize_ *phpgtk_paper_size = (GtkPaperSize_ *)object_paper_size.implementation();
		paper_size = (phpgtk_paper_size->get_instance());
	}

	gtk_page_setup_set_paper_size_and_default_margins (GTK_PAGE_SETUP(instance), paper_size);

}

Php::Value GtkPageSetup_::get_paper_width(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_paper_width (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

Php::Value GtkPageSetup_::get_paper_height(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_paper_height (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

Php::Value GtkPageSetup_::get_page_width(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_page_width (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

Php::Value GtkPageSetup_::get_page_height(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_page_setup_get_page_height (GTK_PAGE_SETUP(instance), unit);

	return ret;
}

Php::Value GtkPageSetup_::load_file(Php::Parameters &parameters)
{
	std::string s_file_name = parameters[0];
	gchar *file_name = (gchar *)s_file_name.c_str();

	GError *error;
	bool ret = gtk_page_setup_load_file (GTK_PAGE_SETUP(instance), file_name, &error);

	return ret;
}

Php::Value GtkPageSetup_::load_key_file(Php::Parameters &parameters)
{

	// std::string s_group_name = parameters[1];
	// gchar *group_name = (gchar *)s_group_name.c_str();


	// gboolean ret = gtk_page_setup_load_key_file (GTK_PAGE_SETUP(instance), key_file, group_name, error);

	// return ret;

	throw Php::Exception("GtkPageSetup_::load_key_file not implemented");
	return 1;
}

Php::Value GtkPageSetup_::to_file(Php::Parameters &parameters)
{
	std::string s_file_name = parameters[0];
	gchar *file_name = (gchar *)s_file_name.c_str();

	GError *error;
	bool ret = gtk_page_setup_to_file (GTK_PAGE_SETUP(instance), file_name, &error);

	return ret;
}

void GtkPageSetup_::to_key_file(Php::Parameters &parameters)
{

	// std::string s_group_name = parameters[1];
	// gchar *group_name = (gchar *)s_group_name.c_str();

	// gtk_page_setup_to_key_file (GTK_PAGE_SETUP(instance), key_file, group_name);

	throw Php::Exception("GtkPageSetup_::to_key_file not implemented");

}

