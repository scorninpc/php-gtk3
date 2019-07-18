
#include "GtkColorButton.h"

/**
 * Constructor
 */
GtkColorButton_::GtkColorButton_() = default;

/**
 * Destructor
 */
GtkColorButton_::~GtkColorButton_() = default;

void GtkColorButton_::__construct()
{
	instance = (gpointer *)gtk_color_button_new ();

}

Php::Value GtkColorButton_::new_with_color()
{
	// GtkWidget *ret = gtk_color_button_new_with_color (GTK_COLOR_BUTTON(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	Php::deprecated << "GtkColorButton_::new_with_color is deprecated on Gtk 3.4" << std::endl;
	return 1;
}

Php::Value GtkColorButton_::new_with_rgba(Php::Parameters &parameters)
{
	GdkRGBA rgba;
	if(parameters.size() > 0) {
		Php::Value object_rgba = parameters[0];
		GdkRGBA_ *phpgtk_rgba = (GdkRGBA_ *)object_rgba.implementation();
		rgba = phpgtk_rgba->get_instance();
	}

	GtkWidget *ret = gtk_color_button_new_with_rgba (&rgba);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkColorButton_::set_color(Php::Parameters &parameters)
{
	// GdkColor *color;
	// if(parameters.size() > 0) {
	// 	Php::Value object_color = parameters[0];
	// 	GdkColor_ *phpgtk_color = (GdkColor_ *)object_color.implementation();
	// 	color = GTK_WIDGET(phpgtk_color->get_instance());
	// }

	// gtk_color_button_set_color (GTK_COLOR_BUTTON(instance), color);

	Php::deprecated << "GtkColorButton_::set_color is deprecated on Gtk 3.0" << std::endl;

}

void GtkColorButton_::get_color(Php::Parameters &parameters)
{
	// GdkColor *color;
	// if(parameters.size() > 0) {
	// 	Php::Value object_color = parameters[0];
	// 	GdkColor_ *phpgtk_color = (GdkColor_ *)object_color.implementation();
	// 	color = GTK_WIDGET(phpgtk_color->get_instance());
	// }

	// gtk_color_button_get_color (GTK_COLOR_BUTTON(instance), color);

	Php::deprecated << "GtkColorButton_::get_color is deprecated on Gtk 3.4" << std::endl;

}

void GtkColorButton_::set_alpha(Php::Parameters &parameters)
{
	// guint16 alpha = (guint16)parameters[0];

	// gtk_color_button_set_alpha (GTK_COLOR_BUTTON(instance), alpha);

	Php::deprecated << "GtkColorButton_::set_alpha is deprecated on Gtk 3.4" << std::endl;

}

void GtkColorButton_::get_alpha(Php::Parameters &parameters)
{
	// guint16 alpha = (guint16)parameters[0];

	// gtk_color_button_set_alpha (GTK_COLOR_BUTTON(instance), alpha);

	Php::deprecated << "GtkColorButton_::get_alpha is deprecated on Gtk 3.4" << std::endl;

}

void GtkColorButton_::set_rgba(Php::Parameters &parameters)
{
	// GdkRGBA *rgba;
	// if(parameters.size() > 0) {
	// 	Php::Value object_rgba = parameters[0];
	// 	GdkRGBA_ *phpgtk_rgba = (GdkRGBA_ *)object_rgba.implementation();
	// 	rgba = GTK_WIDGET(phpgtk_rgba->get_instance());
	// }

	// gtk_color_button_set_rgba (GTK_COLOR_BUTTON(instance), rgba);

	Php::deprecated << "GtkColorButton_::set_rgba is deprecated on Gtk 3.4" << std::endl;

}

Php::Value GtkColorButton_::get_rgba(Php::Parameters &parameters)
{
	GdkRGBA rgba;

	gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER(instance), &rgba);

	// Create the PHP-GTK object and set GTK object
	GdkRGBA_ *rgba_ = new GdkRGBA_();
	rgba_->set_instance(rgba);
	return Php::Object("GdkRGBA", rgba_);

}

void GtkColorButton_::set_use_alpha(Php::Parameters &parameters)
{
	// gboolean use_alpha = (gboolean)parameters[0];

	// gtk_color_button_set_use_alpha (GTK_COLOR_BUTTON(instance), use_alpha);

	Php::deprecated << "GtkColorButton_::set_use_alpha is deprecated on Gtk 3.4" << std::endl;

}

Php::Value GtkColorButton_::get_use_alpha()
{
	// gboolean ret = gtk_color_button_get_use_alpha (GTK_COLOR_BUTTON(instance));

	// return ret;

	Php::deprecated << "GtkColorButton_::get_use_alpha is deprecated on Gtk 3.4" << std::endl;
	return 1;
}

void GtkColorButton_::set_title(Php::Parameters &parameters)
{
	std::string s_title = parameters[0];
	gchar *title = (gchar *)s_title.c_str();

	gtk_color_button_set_title (GTK_COLOR_BUTTON(instance), title);

}

Php::Value GtkColorButton_::get_title()
{
	std::string ret = gtk_color_button_get_title (GTK_COLOR_BUTTON(instance));

	return ret;
}

