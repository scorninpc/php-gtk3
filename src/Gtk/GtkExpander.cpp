
#include "GtkExpander.h"

/**
 * Constructor
 */
GtkExpander_::GtkExpander_() = default;

/**
 * Destructor
 */
GtkExpander_::~GtkExpander_() = default;

void GtkExpander_::__construct(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	instance = (gpointer *)gtk_expander_new (label);

}

Php::Value GtkExpander_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gpointer *ret = (gpointer *)gtk_expander_new_with_mnemonic (label);

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

void GtkExpander_::set_expanded(Php::Parameters &parameters)
{
	gboolean expanded = (gboolean)parameters[0];

	gtk_expander_set_expanded (GTK_EXPANDER(instance), expanded);

}

Php::Value GtkExpander_::get_expanded()
{
	bool ret = gtk_expander_get_expanded (GTK_EXPANDER(instance));

	return ret;
}

void GtkExpander_::set_spacing(Php::Parameters &parameters)
{
	gint spacing = (gint)parameters[0];

	gtk_expander_set_spacing (GTK_EXPANDER(instance), spacing);

}

Php::Value GtkExpander_::get_spacing()
{
	gint ret = gtk_expander_get_spacing (GTK_EXPANDER(instance));

	return ret;
}

void GtkExpander_::set_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gtk_expander_set_label (GTK_EXPANDER(instance), label);

}

Php::Value GtkExpander_::get_label()
{
	std::string ret = gtk_expander_get_label (GTK_EXPANDER(instance));

	return ret;
}

void GtkExpander_::set_use_underline(Php::Parameters &parameters)
{
	gboolean use_underline = (gboolean)parameters[0];

	gtk_expander_set_use_underline (GTK_EXPANDER(instance), use_underline);

}

Php::Value GtkExpander_::get_use_underline()
{
	bool ret = gtk_expander_get_use_underline (GTK_EXPANDER(instance));

	return ret;
}

void GtkExpander_::set_use_markup(Php::Parameters &parameters)
{
	gboolean use_markup = (gboolean)parameters[0];

	gtk_expander_set_use_markup (GTK_EXPANDER(instance), use_markup);

}

Php::Value GtkExpander_::get_use_markup()
{
	bool ret = gtk_expander_get_use_markup (GTK_EXPANDER(instance));

	return ret;
}

void GtkExpander_::set_label_widget(Php::Parameters &parameters)
{
	GtkWidget *label_widget;
	if(parameters.size() > 0) {
		Php::Value object_label_widget = parameters[0];
		GtkWidget_ *phpgtk_label_widget = (GtkWidget_ *)object_label_widget.implementation();
		label_widget = GTK_WIDGET(phpgtk_label_widget->get_instance());
	}

	gtk_expander_set_label_widget (GTK_EXPANDER(instance), label_widget);

}

Php::Value GtkExpander_::get_label_widget()
{
	gpointer *ret = (gpointer *)gtk_expander_get_label_widget (GTK_EXPANDER(instance));

	return cobject_to_phpobject(ret);
	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

void GtkExpander_::set_label_fill(Php::Parameters &parameters)
{
	gboolean label_fill = (gboolean)parameters[0];

	gtk_expander_set_label_fill (GTK_EXPANDER(instance), label_fill);

}

Php::Value GtkExpander_::get_label_fill()
{
	bool ret = gtk_expander_get_label_fill (GTK_EXPANDER(instance));

	return ret;
}

void GtkExpander_::set_resize_toplevel(Php::Parameters &parameters)
{
	gboolean resize_toplevel = (gboolean)parameters[0];

	gtk_expander_set_resize_toplevel (GTK_EXPANDER(instance), resize_toplevel);

}

Php::Value GtkExpander_::get_resize_toplevel()
{
	bool ret = gtk_expander_get_resize_toplevel (GTK_EXPANDER(instance));

	return ret;
}

