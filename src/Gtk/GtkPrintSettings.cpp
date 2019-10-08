
#include "GtkPrintSettings.h"

/**
 * Constructor
 */
GtkPrintSettings_::GtkPrintSettings_() = default;

/**
 * Destructor
 */
GtkPrintSettings_::~GtkPrintSettings_() = default;

void GtkPrintSettings_::__construct()
{
	instance = (gpointer *)gtk_print_settings_new ();

}

Php::Value GtkPrintSettings_::new_from_file(Php::Parameters &parameters)
{
	std::string s_file_name = parameters[0];
	gchar *file_name = (gchar *)s_file_name.c_str();

	GError *error;
	GtkPrintSettings *ret = gtk_print_settings_new_from_file (file_name, &error);

	GtkPrintSettings_ *return_parsed = new GtkPrintSettings_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkPrintSettings", return_parsed);
}

Php::Value GtkPrintSettings_::new_from_key_file(Php::Parameters &parameters)
{
	// std::string s_group_name = parameters[0];
	// gchar *group_name = (gchar *)s_group_name.c_str();

	// std::string s_group_name = parameters[0];
	// gchar *group_name = (gchar *)s_group_name.c_str();

	// GError *error;
	// GtkPrintSettings *ret = gtk_print_settings_new_from_key_file (GTK_PRINT_SETTINGS(instance), group_name, &error);

	// GtkPrintSettings_ *return_parsed = new GtkPrintSettings_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkPrintSettings", return_parsed);

	throw Php::Exception("GtkPrintSettings_::new_from_key_file not implemented");
	return 1;
}


Php::Value GtkPrintSettings_::copy()
{
	GtkPrintSettings *ret = gtk_print_settings_copy (GTK_PRINT_SETTINGS(instance));

	GtkPrintSettings_ *return_parsed = new GtkPrintSettings_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkPrintSettings", return_parsed);
}

Php::Value GtkPrintSettings_::has_key(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gboolean ret = gtk_print_settings_has_key (GTK_PRINT_SETTINGS(instance), key);

	return ret;
}

Php::Value GtkPrintSettings_::get(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	std::string ret = gtk_print_settings_get (GTK_PRINT_SETTINGS(instance), key);

	return ret;
}

void GtkPrintSettings_::set(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	std::string s_value = parameters[1];
	gchar *value = (gchar *)s_value.c_str();

	gtk_print_settings_set (GTK_PRINT_SETTINGS(instance), key, value);

}

void GtkPrintSettings_::unset(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gtk_print_settings_unset (GTK_PRINT_SETTINGS(instance), key);

}

void GtkPrintSettings_::foreach(Php::Parameters &parameters)
{
	// GtkPrintSettingsFunc *func;
	// if(parameters.size() > 0) {
	// 	Php::Value object_func = parameters[0];
	// 	GtkPrintSettingsFunc_ *phpgtk_func = (GtkPrintSettingsFunc_ *)object_func.implementation();
	// 	func = GTK_WIDGET(phpgtk_func->get_instance());
	// }

	// gpointer user_data = (gpointer)parameters[1];

	// gtk_print_settings_foreach (GTK_PRINT_SETTINGS(instance), func, user_data);

	throw Php::Exception("GtkMenuShell_::bind_model not implemented");

}

Php::Value GtkPrintSettings_::get_bool(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gboolean ret = gtk_print_settings_get_bool (GTK_PRINT_SETTINGS(instance), key);

	return ret;
}

void GtkPrintSettings_::set_bool(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gboolean value = (gboolean)parameters[1];

	gtk_print_settings_set_bool (GTK_PRINT_SETTINGS(instance), key, value);

}

Php::Value GtkPrintSettings_::get_double(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gdouble ret = gtk_print_settings_get_double (GTK_PRINT_SETTINGS(instance), key);

	return ret;
}

Php::Value GtkPrintSettings_::get_double_with_default(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gdouble def = (gdouble)parameters[1];

	gdouble ret = gtk_print_settings_get_double_with_default (GTK_PRINT_SETTINGS(instance), key, def);

	return ret;
}

void GtkPrintSettings_::set_double(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gdouble value = (gdouble)parameters[1];

	gtk_print_settings_set_double (GTK_PRINT_SETTINGS(instance), key, value);

}

Php::Value GtkPrintSettings_::get_length(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	int int_unit = (int)parameters[1];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_print_settings_get_length (GTK_PRINT_SETTINGS(instance), key, unit);

	return ret;
}

void GtkPrintSettings_::set_length(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gdouble value = (gdouble)parameters[1];

	int int_unit = (int)parameters[2];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_print_settings_set_length (GTK_PRINT_SETTINGS(instance), key, value, unit);

}

Php::Value GtkPrintSettings_::get_int(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gint ret = gtk_print_settings_get_int (GTK_PRINT_SETTINGS(instance), key);

	return ret;
}

Php::Value GtkPrintSettings_::get_int_with_default(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gint def = (gint)parameters[1];

	gint ret = gtk_print_settings_get_int_with_default (GTK_PRINT_SETTINGS(instance), key, def);

	return ret;
}

void GtkPrintSettings_::set_int(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	gint value = (gint)parameters[1];

	gtk_print_settings_set_int (GTK_PRINT_SETTINGS(instance), key, value);

}

Php::Value GtkPrintSettings_::get_printer()
{
	std::string ret = gtk_print_settings_get_printer (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_printer(Php::Parameters &parameters)
{
	std::string s_printer = parameters[0];
	gchar *printer = (gchar *)s_printer.c_str();

	gtk_print_settings_set_printer (GTK_PRINT_SETTINGS(instance), printer);

}

Php::Value GtkPrintSettings_::get_orientation()
{
	GtkPageOrientation ret = gtk_print_settings_get_orientation (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_orientation(Php::Parameters &parameters)
{
	int int_orientation = (int)parameters[0];
	GtkPageOrientation orientation = (GtkPageOrientation)int_orientation;

	gtk_print_settings_set_orientation (GTK_PRINT_SETTINGS(instance), orientation);

}

Php::Value GtkPrintSettings_::get_paper_size()
{
	GtkPaperSize *ret = gtk_print_settings_get_paper_size (GTK_PRINT_SETTINGS(instance));

	GtkPaperSize_ *return_parsed = new GtkPaperSize_();
	return_parsed->set_instance(ret);
	return Php::Object("GtkPaperSize", return_parsed);
}

void GtkPrintSettings_::set_paper_size(Php::Parameters &parameters)
{
	GtkPaperSize *paper_size;
	if(parameters.size() > 0) {
		Php::Value object_paper_size = parameters[0];
		GtkPaperSize_ *phpgtk_paper_size = (GtkPaperSize_ *)object_paper_size.implementation();
		paper_size = (phpgtk_paper_size->get_instance());
	}

	gtk_print_settings_set_paper_size (GTK_PRINT_SETTINGS(instance), paper_size);

}

Php::Value GtkPrintSettings_::get_paper_width(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_print_settings_get_paper_width (GTK_PRINT_SETTINGS(instance), unit);

	return ret;
}

void GtkPrintSettings_::set_paper_width(Php::Parameters &parameters)
{
	gdouble width = (gdouble)parameters[0];

	int int_unit = (int)parameters[1];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_print_settings_set_paper_width (GTK_PRINT_SETTINGS(instance), width, unit);

}

Php::Value GtkPrintSettings_::get_paper_height(Php::Parameters &parameters)
{
	int int_unit = (int)parameters[0];
	GtkUnit unit = (GtkUnit)int_unit;

	gdouble ret = gtk_print_settings_get_paper_height (GTK_PRINT_SETTINGS(instance), unit);

	return ret;
}

void GtkPrintSettings_::set_paper_height(Php::Parameters &parameters)
{
	gdouble height = (gdouble)parameters[0];

	int int_unit = (int)parameters[1];
	GtkUnit unit = (GtkUnit)int_unit;

	gtk_print_settings_set_paper_height (GTK_PRINT_SETTINGS(instance), height, unit);

}

Php::Value GtkPrintSettings_::get_use_color()
{
	gboolean ret = gtk_print_settings_get_use_color (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_use_color(Php::Parameters &parameters)
{
	gboolean use_color = (gboolean)parameters[0];

	gtk_print_settings_set_use_color (GTK_PRINT_SETTINGS(instance), use_color);

}

Php::Value GtkPrintSettings_::get_collate()
{
	gboolean ret = gtk_print_settings_get_collate (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_collate(Php::Parameters &parameters)
{
	gboolean collate = (gboolean)parameters[0];

	gtk_print_settings_set_collate (GTK_PRINT_SETTINGS(instance), collate);

}

Php::Value GtkPrintSettings_::get_reverse()
{
	gboolean ret = gtk_print_settings_get_reverse (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_reverse(Php::Parameters &parameters)
{
	gboolean reverse = (gboolean)parameters[0];

	gtk_print_settings_set_reverse (GTK_PRINT_SETTINGS(instance), reverse);

}

Php::Value GtkPrintSettings_::get_duplex()
{
	GtkPrintDuplex ret = gtk_print_settings_get_duplex (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_duplex(Php::Parameters &parameters)
{
	int int_duplex = (int)parameters[0];
	GtkPrintDuplex duplex = (GtkPrintDuplex)int_duplex;

	gtk_print_settings_set_duplex (GTK_PRINT_SETTINGS(instance), duplex);

}

Php::Value GtkPrintSettings_::get_quality()
{
	GtkPrintQuality ret = gtk_print_settings_get_quality (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_quality(Php::Parameters &parameters)
{
	int int_quality = (int)parameters[0];
	GtkPrintQuality quality = (GtkPrintQuality)int_quality;

	gtk_print_settings_set_quality (GTK_PRINT_SETTINGS(instance), quality);

}

Php::Value GtkPrintSettings_::get_n_copies()
{
	gint ret = gtk_print_settings_get_n_copies (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_n_copies(Php::Parameters &parameters)
{
	gint num_copies = (gint)parameters[0];

	gtk_print_settings_set_n_copies (GTK_PRINT_SETTINGS(instance), num_copies);

}

Php::Value GtkPrintSettings_::get_number_up()
{
	gint ret = gtk_print_settings_get_number_up (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_number_up(Php::Parameters &parameters)
{
	gint number_up = (gint)parameters[0];

	gtk_print_settings_set_number_up (GTK_PRINT_SETTINGS(instance), number_up);

}

Php::Value GtkPrintSettings_::get_number_up_layout()
{
	GtkNumberUpLayout ret = gtk_print_settings_get_number_up_layout (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_number_up_layout(Php::Parameters &parameters)
{
	int int_number_up_layout = (int)parameters[0];
	GtkNumberUpLayout number_up_layout = (GtkNumberUpLayout)int_number_up_layout;

	gtk_print_settings_set_number_up_layout (GTK_PRINT_SETTINGS(instance), number_up_layout);

}

Php::Value GtkPrintSettings_::get_resolution()
{
	gint ret = gtk_print_settings_get_resolution (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_resolution(Php::Parameters &parameters)
{
	gint resolution = (gint)parameters[0];

	gtk_print_settings_set_resolution (GTK_PRINT_SETTINGS(instance), resolution);

}

void GtkPrintSettings_::set_resolution_xy(Php::Parameters &parameters)
{
	gint resolution_x = (gint)parameters[0];

	gint resolution_y = (gint)parameters[1];

	gtk_print_settings_set_resolution_xy (GTK_PRINT_SETTINGS(instance), resolution_x, resolution_y);

}

Php::Value GtkPrintSettings_::get_resolution_x()
{
	gint ret = gtk_print_settings_get_resolution_x (GTK_PRINT_SETTINGS(instance));

	return ret;
}

Php::Value GtkPrintSettings_::get_resolution_y()
{
	gint ret = gtk_print_settings_get_resolution_y (GTK_PRINT_SETTINGS(instance));

	return ret;
}

Php::Value GtkPrintSettings_::get_printer_lpi()
{
	gdouble ret = gtk_print_settings_get_printer_lpi (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_printer_lpi(Php::Parameters &parameters)
{
	gdouble lpi = (gdouble)parameters[0];

	gtk_print_settings_set_printer_lpi (GTK_PRINT_SETTINGS(instance), lpi);

}

Php::Value GtkPrintSettings_::get_scale()
{
	gdouble ret = gtk_print_settings_get_scale (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_scale(Php::Parameters &parameters)
{
	gdouble scale = (gdouble)parameters[0];

	gtk_print_settings_set_scale (GTK_PRINT_SETTINGS(instance), scale);

}

Php::Value GtkPrintSettings_::get_print_pages()
{
	GtkPrintPages ret = gtk_print_settings_get_print_pages (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_print_pages(Php::Parameters &parameters)
{
	int int_pages = (int)parameters[0];
	GtkPrintPages pages = (GtkPrintPages)int_pages;

	gtk_print_settings_set_print_pages (GTK_PRINT_SETTINGS(instance), pages);

}

Php::Value GtkPrintSettings_::get_page_ranges(Php::Parameters &parameters)
{
	// gint num_ranges = (gint)parameters[0];

	// GtkPageRange *ret = gtk_print_settings_get_page_ranges (GTK_PRINT_SETTINGS(instance), num_ranges);

	// // Cria o retorno
	// Php::Value arr;
	// arr[0] = arr["start"] = (int)ret->start;
	// arr[1] = arr["end"] = (int)ret->end;
	// return arr;
	throw Php::Exception("GtkPrintSettings_::get_page_ranges not implemented");
	return 1;
}

void GtkPrintSettings_::set_page_ranges(Php::Parameters &parameters)
{
	// int int_page_ranges = (int)parameters[0];
	// GtkPageRange page_ranges = (GtkPageRange)int_page_ranges;

	// gint num_ranges = (gint)parameters[1];

	// gtk_print_settings_set_page_ranges (GTK_PRINT_SETTINGS(instance), page_ranges, num_ranges);
	throw Php::Exception("GtkPrintSettings_::set_page_ranges not implemented");
}

Php::Value GtkPrintSettings_::get_page_set()
{
	GtkPageSet ret = gtk_print_settings_get_page_set (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_page_set(Php::Parameters &parameters)
{
	int int_page_set = (int)parameters[0];
	GtkPageSet page_set = (GtkPageSet)int_page_set;

	gtk_print_settings_set_page_set (GTK_PRINT_SETTINGS(instance), page_set);

}

Php::Value GtkPrintSettings_::get_default_source()
{
	std::string ret = gtk_print_settings_get_default_source (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_default_source(Php::Parameters &parameters)
{
	std::string s_default_source = parameters[0];
	gchar *default_source = (gchar *)s_default_source.c_str();

	gtk_print_settings_set_default_source (GTK_PRINT_SETTINGS(instance), default_source);

}

Php::Value GtkPrintSettings_::get_media_type()
{
	std::string ret = gtk_print_settings_get_media_type (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_media_type(Php::Parameters &parameters)
{
	std::string s_media_type = parameters[0];
	gchar *media_type = (gchar *)s_media_type.c_str();

	gtk_print_settings_set_media_type (GTK_PRINT_SETTINGS(instance), media_type);

}

Php::Value GtkPrintSettings_::get_dither()
{
	std::string ret = gtk_print_settings_get_dither (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_dither(Php::Parameters &parameters)
{
	std::string s_dither = parameters[0];
	gchar *dither = (gchar *)s_dither.c_str();

	gtk_print_settings_set_dither (GTK_PRINT_SETTINGS(instance), dither);

}

Php::Value GtkPrintSettings_::get_finishings()
{
	std::string ret = gtk_print_settings_get_finishings (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_finishings(Php::Parameters &parameters)
{
	std::string s_finishings = parameters[0];
	gchar *finishings = (gchar *)s_finishings.c_str();

	gtk_print_settings_set_finishings (GTK_PRINT_SETTINGS(instance), finishings);

}

Php::Value GtkPrintSettings_::get_output_bin()
{
	std::string ret = gtk_print_settings_get_output_bin (GTK_PRINT_SETTINGS(instance));

	return ret;
}

void GtkPrintSettings_::set_output_bin(Php::Parameters &parameters)
{
	std::string s_output_bin = parameters[0];
	gchar *output_bin = (gchar *)s_output_bin.c_str();

	gtk_print_settings_set_output_bin (GTK_PRINT_SETTINGS(instance), output_bin);

}

Php::Value GtkPrintSettings_::load_file(Php::Parameters &parameters)
{
	std::string s_file_name = parameters[0];
	gchar *file_name = (gchar *)s_file_name.c_str();

	GError *error;
	gboolean ret = gtk_print_settings_load_file (GTK_PRINT_SETTINGS(instance), file_name, &error);

	return ret;
}

Php::Value GtkPrintSettings_::load_key_file(Php::Parameters &parameters)
{

	// std::string s_group_name = parameters[1];
	// gchar *group_name = (gchar *)s_group_name.c_str();


	// gboolean ret = gtk_print_settings_load_key_file (GTK_PRINT_SETTINGS(instance), key_file, group_name, &error);

	// return ret;

	throw Php::Exception("GtkPrintSettings_::load_key_file not implemented");
	return 1;
}

Php::Value GtkPrintSettings_::to_file(Php::Parameters &parameters)
{
	std::string s_file_name = parameters[0];
	gchar *file_name = (gchar *)s_file_name.c_str();

	GError *error;
	gboolean ret = gtk_print_settings_to_file (GTK_PRINT_SETTINGS(instance), file_name, &error);

	return ret;
}

void GtkPrintSettings_::to_key_file(Php::Parameters &parameters)
{

	// std::string s_group_name = parameters[1];
	// gchar *group_name = (gchar *)s_group_name.c_str();

	// gtk_print_settings_to_key_file (GTK_PRINT_SETTINGS(instance), key_file, group_name);

	throw Php::Exception("GtkPrintSettings_::to_key_file not implemented");

}

