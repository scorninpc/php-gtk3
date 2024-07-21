
#include "GtkHeaderBar.h"

/**
 * Constructor
 */
GtkHeaderBar_::GtkHeaderBar_() = default;

/**
 * Destructor
 */
GtkHeaderBar_::~GtkHeaderBar_() = default;

void GtkHeaderBar_::__construct()
{
	instance = (gpointer *)gtk_header_bar_new ();

}

void GtkHeaderBar_::set_title(Php::Parameters &parameters)
{
	std::string s_title = parameters[0];
	gchar *title = (gchar *)s_title.c_str();

	gtk_header_bar_set_title (GTK_HEADER_BAR(instance), title);

}

Php::Value GtkHeaderBar_::get_title()
{
	std::string ret = gtk_header_bar_get_title (GTK_HEADER_BAR(instance));

	return ret;
}

void GtkHeaderBar_::set_subtitle(Php::Parameters &parameters)
{
	std::string s_subtitle = parameters[0];
	gchar *subtitle = (gchar *)s_subtitle.c_str();

	gtk_header_bar_set_subtitle (GTK_HEADER_BAR(instance), subtitle);

}

Php::Value GtkHeaderBar_::get_subtitle()
{
	std::string ret = gtk_header_bar_get_subtitle (GTK_HEADER_BAR(instance));

	return ret;
}

void GtkHeaderBar_::set_has_subtitle(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_header_bar_set_has_subtitle (GTK_HEADER_BAR(instance), setting);

}

Php::Value GtkHeaderBar_::get_has_subtitle()
{
	bool ret = gtk_header_bar_get_has_subtitle (GTK_HEADER_BAR(instance));

	return ret;
}

void GtkHeaderBar_::set_custom_title(Php::Parameters &parameters)
{
	GtkWidget *title_widget;
	if(parameters.size() > 0) {
		Php::Value object_title_widget = parameters[0];
		GtkWidget_ *phpgtk_title_widget = (GtkWidget_ *)object_title_widget.implementation();
		title_widget = GTK_WIDGET(phpgtk_title_widget->get_instance());
	}

	gtk_header_bar_set_custom_title (GTK_HEADER_BAR(instance), title_widget);

}

Php::Value GtkHeaderBar_::get_custom_title()
{
	gpointer *ret = (gpointer *)gtk_header_bar_get_custom_title (GTK_HEADER_BAR(instance));

	return cobject_to_phpobject(ret);
	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

void GtkHeaderBar_::pack_start(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_header_bar_pack_start (GTK_HEADER_BAR(instance), child);

}

void GtkHeaderBar_::pack_end(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_header_bar_pack_end (GTK_HEADER_BAR(instance), child);

}

void GtkHeaderBar_::set_show_close_button(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_header_bar_set_show_close_button (GTK_HEADER_BAR(instance), setting);

}

Php::Value GtkHeaderBar_::get_show_close_button()
{
	bool ret = gtk_header_bar_get_show_close_button (GTK_HEADER_BAR(instance));

	return ret;
}

void GtkHeaderBar_::set_decoration_layout(Php::Parameters &parameters)
{
	std::string s_layout = parameters[0];
	gchar *layout = (gchar *)s_layout.c_str();

	gtk_header_bar_set_decoration_layout (GTK_HEADER_BAR(instance), layout);

}

Php::Value GtkHeaderBar_::get_decoration_layout()
{
	std::string ret = gtk_header_bar_get_decoration_layout (GTK_HEADER_BAR(instance));

	return ret;
}

