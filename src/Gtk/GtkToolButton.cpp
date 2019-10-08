
#include "GtkToolButton.h"

/**
 * Constructor
 */
GtkToolButton_::GtkToolButton_() = default;

/**
 * Destructor
 */
GtkToolButton_::~GtkToolButton_() = default;

void GtkToolButton_::__construct(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	instance = (gpointer *)gtk_tool_button_new (NULL, NULL);
	gtk_tool_button_set_label(GTK_TOOL_BUTTON(instance), label);

}

void GtkToolButton_::set_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gtk_tool_button_set_label (GTK_TOOL_BUTTON(instance), label);

}

Php::Value GtkToolButton_::get_label()
{
	std::string ret = gtk_tool_button_get_label (GTK_TOOL_BUTTON(instance));

	return ret;
}

void GtkToolButton_::set_use_underline(Php::Parameters &parameters)
{
	gboolean use_underline = (gboolean)parameters[0];

	gtk_tool_button_set_use_underline (GTK_TOOL_BUTTON(instance), use_underline);

}

Php::Value GtkToolButton_::get_use_underline()
{
	gboolean ret = gtk_tool_button_get_use_underline (GTK_TOOL_BUTTON(instance));

	return ret;
}

void GtkToolButton_::set_icon_name(Php::Parameters &parameters)
{
	std::string s_icon_name = parameters[0];
	gchar *icon_name = (gchar *)s_icon_name.c_str();

	gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(instance), icon_name);

}

Php::Value GtkToolButton_::get_icon_name()
{
	std::string ret = gtk_tool_button_get_icon_name (GTK_TOOL_BUTTON(instance));

	return ret;
}

void GtkToolButton_::set_icon_widget(Php::Parameters &parameters)
{
	GtkWidget *icon_widget;
	if(parameters.size() > 0) {
		Php::Value object_icon_widget = parameters[0];
		GtkWidget_ *phpgtk_icon_widget = (GtkWidget_ *)object_icon_widget.implementation();
		icon_widget = GTK_WIDGET(phpgtk_icon_widget->get_instance());
	}

	gtk_tool_button_set_icon_widget (GTK_TOOL_BUTTON(instance), icon_widget);

}

Php::Value GtkToolButton_::get_icon_widget()
{
	GtkWidget *ret = gtk_tool_button_get_icon_widget (GTK_TOOL_BUTTON(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkToolButton_::set_label_widget(Php::Parameters &parameters)
{
	GtkWidget *label_widget;
	if(parameters.size() > 0) {
		Php::Value object_label_widget = parameters[0];
		GtkWidget_ *phpgtk_label_widget = (GtkWidget_ *)object_label_widget.implementation();
		label_widget = GTK_WIDGET(phpgtk_label_widget->get_instance());
	}

	gtk_tool_button_set_label_widget (GTK_TOOL_BUTTON(instance), label_widget);

}

Php::Value GtkToolButton_::get_label_widget()
{
	GtkWidget *ret = gtk_tool_button_get_label_widget (GTK_TOOL_BUTTON(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

