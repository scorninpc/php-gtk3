
#include "GtkProgressBar.h"

/**
 * Constructor
 */
GtkProgressBar_::GtkProgressBar_() = default;

/**
 * Destructor
 */
GtkProgressBar_::~GtkProgressBar_() = default;

void GtkProgressBar_::__construct()
{
	instance = (gpointer *)gtk_progress_bar_new ();

}

void GtkProgressBar_::pulse()
{
	gtk_progress_bar_pulse (GTK_PROGRESS_BAR(instance));

}

void GtkProgressBar_::set_fraction(Php::Parameters &parameters)
{
	gdouble fraction = (gdouble)parameters[0];

	gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR(instance), fraction);

}

Php::Value GtkProgressBar_::get_fraction()
{
	gdouble ret = gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR(instance));

	return ret;
}

void GtkProgressBar_::set_inverted(Php::Parameters &parameters)
{
	gboolean inverted = (gboolean)parameters[0];

	gtk_progress_bar_set_inverted (GTK_PROGRESS_BAR(instance), inverted);

}

Php::Value GtkProgressBar_::get_inverted()
{
	gboolean ret = gtk_progress_bar_get_inverted (GTK_PROGRESS_BAR(instance));

	return ret;
}

void GtkProgressBar_::set_show_text(Php::Parameters &parameters)
{
	gboolean show_text = (gboolean)parameters[0];

	gtk_progress_bar_set_show_text (GTK_PROGRESS_BAR(instance), show_text);

}

Php::Value GtkProgressBar_::get_show_text()
{
	gboolean ret = gtk_progress_bar_get_show_text (GTK_PROGRESS_BAR(instance));

	return ret;
}

void GtkProgressBar_::set_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gtk_progress_bar_set_text (GTK_PROGRESS_BAR(instance), text);

}

Php::Value GtkProgressBar_::get_text()
{
	std::string ret = gtk_progress_bar_get_text (GTK_PROGRESS_BAR(instance));

	return ret;
}

void GtkProgressBar_::set_ellipsize(Php::Parameters &parameters)
{

	// gtk_progress_bar_set_ellipsize (GTK_PROGRESS_BAR(instance), mode);
	throw Php::Exception("GtkProgressBar_::set_ellipsize not implemented");
}

Php::Value GtkProgressBar_::get_ellipsize()
{
	// PangoEllipsizeMode ret = gtk_progress_bar_get_ellipsize (GTK_PROGRESS_BAR(instance));

	// return ret;

	throw Php::Exception("GtkProgressBar_::get_ellipsize not implemented");

	return 1;
}

void GtkProgressBar_::set_pulse_step(Php::Parameters &parameters)
{
	gdouble fraction = (gdouble)parameters[0];

	gtk_progress_bar_set_pulse_step (GTK_PROGRESS_BAR(instance), fraction);

}

Php::Value GtkProgressBar_::get_pulse_step()
{
	gdouble ret = gtk_progress_bar_get_pulse_step (GTK_PROGRESS_BAR(instance));

	return ret;
}

