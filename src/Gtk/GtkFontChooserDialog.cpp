
#include "GtkFontChooserDialog.h"

/**
 * Constructor
 */
GtkFontChooserDialog_::GtkFontChooserDialog_() = default;

/**
 * Destructor
 */
GtkFontChooserDialog_::~GtkFontChooserDialog_() = default;

void GtkFontChooserDialog_::__construct(Php::Parameters &parameters)
{
	std::string s_title = parameters[0];
	gchar *title = (gchar *)s_title.c_str();

	Php::Value object_parent = parameters[1];
    GtkWindow *parent = NULL;
    if (object_parent.instanceOf("GtkWindow")) {
        GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
        parent = GTK_WINDOW(phpgtk_parent->get_instance());
    }

	instance = (gpointer *)gtk_font_chooser_dialog_new (title, parent);

}

Php::Value GtkFontChooserDialog_::get_font_size()
{
	gint ret = gtk_font_chooser_get_font_size (GTK_FONT_CHOOSER(instance));

	return ret;
}

Php::Value GtkFontChooserDialog_::get_font()
{
	std::string ret = gtk_font_chooser_get_font (GTK_FONT_CHOOSER(instance));

	return ret;
}

Php::Value GtkFontChooserDialog_::get_preview_text()
{
	std::string ret = gtk_font_chooser_get_preview_text (GTK_FONT_CHOOSER(instance));

	return ret;
}

void GtkFontChooserDialog_::set_preview_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gtk_font_chooser_set_preview_text (GTK_FONT_CHOOSER(instance), text);

}

Php::Value GtkFontChooserDialog_::get_show_preview_entry()
{
	gboolean ret = gtk_font_chooser_get_show_preview_entry (GTK_FONT_CHOOSER(instance));

	return ret;
}

void GtkFontChooserDialog_::set_show_preview_entry(Php::Parameters &parameters)
{
	gboolean show_preview_entry = (gboolean)parameters[0];

	gtk_font_chooser_set_show_preview_entry (GTK_FONT_CHOOSER(instance), show_preview_entry);

}

