
#include "GtkColorChooserDialog.h"

/**
 * Constructor
 */
GtkColorChooserDialog_::GtkColorChooserDialog_() = default;

/**
 * Destructor
 */
GtkColorChooserDialog_::~GtkColorChooserDialog_() = default;

void GtkColorChooserDialog_::__construct(Php::Parameters &parameters)
{
	std::string s_title = parameters[0];
	gchar *title = (gchar *)s_title.c_str();

	GtkWindow *parent;
	if(parameters.size() > 1) {
		Php::Value object_parent = parameters[1];
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	} else {
		parent = NULL;
	}

	instance = (gpointer *)gtk_color_chooser_dialog_new (title, parent);

}

Php::Value GtkColorChooserDialog_::get_rgba()
{
	GdkRGBA rgba;

	gtk_color_chooser_get_rgba (GTK_COLOR_CHOOSER(instance), &rgba);

	GdkRGBA_ *return_parsed = new GdkRGBA_();
    return_parsed->set_instance(rgba);
    return Php::Object("GdkRGBA", return_parsed);
}

void GtkColorChooserDialog_::set_rgba(Php::Parameters &parameters)
{
	GdkRGBA color;
	if(parameters.size() > 0) {
		Php::Value object_color = parameters[0];
		GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
		color = phpgtk_color->get_instance();
	}

	gtk_color_chooser_set_rgba (GTK_COLOR_CHOOSER(instance), &color);

}

Php::Value GtkColorChooserDialog_::get_use_alpha()
{
	bool ret = gtk_color_chooser_get_use_alpha (GTK_COLOR_CHOOSER(instance));

	return ret;
}

void GtkColorChooserDialog_::set_use_alpha(Php::Parameters &parameters)
{
	gboolean use_alpha = (gboolean)parameters[0];

	gtk_color_chooser_set_use_alpha (GTK_COLOR_CHOOSER(instance), use_alpha);

}

void GtkColorChooserDialog_::add_palette(Php::Parameters &parameters)
{
	// int int_GtkOrientation = (int)parameters[0];
	// GtkOrientation GtkOrientation = (GtkOrientation)int_GtkOrientation;

	// gint color_per_line = (gint)parameters[1];

	// gint n_colors = (gint)parameters[2];

	// GdkRGBA *colors;
	// if(parameters.size() > 3) {
	// 	Php::Value object_colors = parameters[3];
	// 	GdkRGBA_ *phpgtk_colors = (GdkRGBA_ *)object_colors.implementation();
	// 	colors = GTK_WIDGET(phpgtk_colors->get_instance());
	// }

	// gtk_color_chooser_add_palette (GTK_COLOR_CHOOSER_DIALOG(instance), GtkOrientation, color_per_line, n_colors, colors);

	throw Php::Exception("GtkColorChooserDialog_::add_palette not implemented yet");
}

