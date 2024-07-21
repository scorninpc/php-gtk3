
#include "GtkFontButton.h"

/**
 * Constructor
 */
GtkFontButton_::GtkFontButton_() = default;

/**
 * Destructor
 */
GtkFontButton_::~GtkFontButton_() = default;

void GtkFontButton_::__construct()
{
	instance = (gpointer *)gtk_font_button_new ();

}

Php::Value GtkFontButton_::new_with_font(Php::Parameters &parameters)
{
	std::string s_fontname = parameters[0];
	gchar *fontname = (gchar *)s_fontname.c_str();

	GtkWidget *ret = gtk_font_button_new_with_font (fontname);

	GtkFontButton_ *return_parsed = new GtkFontButton_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkFontButton", return_parsed);
}

Php::Value GtkFontButton_::set_font_name(Php::Parameters &parameters)
{
	// std::string s_fontname = parameters[0];
	// gchar *fontname = (gchar *)s_fontname.c_str();

	// bool ret = gtk_font_chooser_set_font (GTK_FONT_BUTTON(instance), fontname);

	// return ret;

	Php::deprecated << "GtkFontButton_::set_font_name is deprecated on Gtk 3.22" << std::endl;
	return 1;
}

void GtkFontButton_::set_font(Php::Parameters &parameters)
{
	std::string s_fontname = parameters[0];
	gchar *fontname = (gchar *)s_fontname.c_str();

	gtk_font_chooser_set_font (GTK_FONT_CHOOSER(instance), fontname);
}

Php::Value GtkFontButton_::get_font_name()
{
	// std::string ret = gtk_font_button_get_font_name (GTK_FONT_CHOOSER(instance));

	// return ret;
	Php::deprecated << "GtkFontButton_::get_font_name is deprecated on Gtk 3.22" << std::endl;
	return 1;
}

Php::Value GtkFontButton_::get_font()
{
	std::string ret = gtk_font_chooser_get_font (GTK_FONT_CHOOSER(instance));

	return ret;
}

void GtkFontButton_::set_show_style(Php::Parameters &parameters)
{
	gboolean show_style = (gboolean)parameters[0];

	gtk_font_button_set_show_style (GTK_FONT_BUTTON(instance), show_style);

}

Php::Value GtkFontButton_::get_show_style()
{
	bool ret = gtk_font_button_get_show_style (GTK_FONT_BUTTON(instance));

	return ret;
}

void GtkFontButton_::set_show_size(Php::Parameters &parameters)
{
	gboolean show_size = (gboolean)parameters[0];

	gtk_font_button_set_show_size (GTK_FONT_BUTTON(instance), show_size);

}

Php::Value GtkFontButton_::get_show_size()
{
	bool ret = gtk_font_button_get_show_size (GTK_FONT_BUTTON(instance));

	return ret;
}

void GtkFontButton_::set_use_font(Php::Parameters &parameters)
{
	gboolean use_font = (gboolean)parameters[0];

	gtk_font_button_set_use_font (GTK_FONT_BUTTON(instance), use_font);

}

Php::Value GtkFontButton_::get_use_font()
{
	bool ret = gtk_font_button_get_use_font (GTK_FONT_BUTTON(instance));

	return ret;
}

void GtkFontButton_::set_use_size(Php::Parameters &parameters)
{
	gboolean use_size = (gboolean)parameters[0];

	gtk_font_button_set_use_size (GTK_FONT_BUTTON(instance), use_size);

}

Php::Value GtkFontButton_::get_use_size()
{
	bool ret = gtk_font_button_get_use_size (GTK_FONT_BUTTON(instance));

	return ret;
}

void GtkFontButton_::set_title(Php::Parameters &parameters)
{
	std::string s_title = parameters[0];
	gchar *title = (gchar *)s_title.c_str();

	gtk_font_button_set_title (GTK_FONT_BUTTON(instance), title);

}

Php::Value GtkFontButton_::get_title()
{
	std::string ret = gtk_font_button_get_title (GTK_FONT_BUTTON(instance));

	return ret;
}

