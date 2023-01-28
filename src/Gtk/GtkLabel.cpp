
#include "GtkLabel.h"

/**
 * Constructor
 */
GtkLabel_::GtkLabel_() = default;

/**
 * Destructor
 */
GtkLabel_::~GtkLabel_() = default;

void GtkLabel_::__construct(Php::Parameters &parameters)
{
	std::string s_str = "";
	;
	if(parameters.size() > 0) {
		s_str.assign((const char *)parameters[0]);
	}

	instance = (gpointer *)gtk_label_new (s_str.c_str());

}

void GtkLabel_::set_text(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	gtk_label_set_text (GTK_LABEL(instance), str);

}

void GtkLabel_::set_markup(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	gtk_label_set_markup (GTK_LABEL(instance), str);

}

void GtkLabel_::set_markup_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	gtk_label_set_markup_with_mnemonic (GTK_LABEL(instance), str);

}

void GtkLabel_::set_pattern(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	gtk_label_set_pattern (GTK_LABEL(instance), str);

}

void GtkLabel_::set_justify(Php::Parameters &parameters)
{
	int int_jtype = (int)parameters[0];
	GtkJustification jtype = (GtkJustification)int_jtype;

	gtk_label_set_justify (GTK_LABEL(instance), jtype);

}

void GtkLabel_::set_xalign(Php::Parameters &parameters)
{
	double d_xalign = parameters[0];
	gfloat xalign = (float)d_xalign;

	gtk_label_set_xalign (GTK_LABEL(instance), xalign);

}

void GtkLabel_::set_yalign(Php::Parameters &parameters)
{
	double d_yalign = parameters[0];
	gfloat yalign = (float)d_yalign;

	gtk_label_set_yalign (GTK_LABEL(instance), yalign);

}

void GtkLabel_::set_width_chars(Php::Parameters &parameters)
{
	gint n_chars = (gint)parameters[0];

	gtk_label_set_width_chars (GTK_LABEL(instance), n_chars);

}

void GtkLabel_::set_max_width_chars(Php::Parameters &parameters)
{
	gint n_chars = (gint)parameters[0];

	gtk_label_set_max_width_chars (GTK_LABEL(instance), n_chars);

}

void GtkLabel_::set_line_wrap(Php::Parameters &parameters)
{
	gboolean wrap = (gboolean)parameters[0];

	gtk_label_set_line_wrap (GTK_LABEL(instance), wrap);

}

void GtkLabel_::set_lines(Php::Parameters &parameters)
{
	gint lines = (gint)parameters[0];

	gtk_label_set_lines (GTK_LABEL(instance), lines);

}

Php::Value GtkLabel_::get_mnemonic_keyval()
{
	gint ret = gtk_label_get_mnemonic_keyval (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_selectable()
{
	gboolean ret = gtk_label_get_selectable (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_text()
{
	std::string ret = gtk_label_get_text (GTK_LABEL(instance));

	return ret;
}

void GtkLabel_::set_mnemonic_widget(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gtk_label_set_mnemonic_widget (GTK_LABEL(instance), widget);

}

void GtkLabel_::set_selectable(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_label_set_selectable (GTK_LABEL(instance), setting);

}

void GtkLabel_::set_text_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	gtk_label_set_text_with_mnemonic (GTK_LABEL(instance), str);

}

Php::Value GtkLabel_::get_justify()
{
	GtkJustification ret = gtk_label_get_justify (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_xalign()
{
	gfloat ret = gtk_label_get_xalign (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_yalign()
{
	gfloat ret = gtk_label_get_yalign (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_width_chars()
{
	gint ret = gtk_label_get_width_chars (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_max_width_chars()
{
	gint ret = gtk_label_get_max_width_chars (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_label()
{
	std::string ret = gtk_label_get_label (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_line_wrap()
{
	gboolean ret = gtk_label_get_line_wrap (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_lines()
{
	gint ret = gtk_label_get_lines (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_mnemonic_widget()
{
	gpointer *ret = (gpointer *)gtk_label_get_mnemonic_widget (GTK_LABEL(instance));

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkLabel_::get_use_markup()
{
	gboolean ret = gtk_label_get_use_markup (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_use_underline()
{
	gboolean ret = gtk_label_get_use_underline (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_single_line_mode()
{
	gboolean ret = gtk_label_get_single_line_mode (GTK_LABEL(instance));

	return ret;
}

Php::Value GtkLabel_::get_angle()
{
	gdouble ret = gtk_label_get_angle (GTK_LABEL(instance));

	return ret;
}

void GtkLabel_::set_label(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	gtk_label_set_label (GTK_LABEL(instance), str);

}

void GtkLabel_::set_use_markup(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_label_set_use_markup (GTK_LABEL(instance), setting);

}

void GtkLabel_::set_use_underline(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_label_set_use_underline (GTK_LABEL(instance), setting);

}

void GtkLabel_::set_single_line_mode(Php::Parameters &parameters)
{
	gboolean single_line_mode = (gboolean)parameters[0];

	gtk_label_set_single_line_mode (GTK_LABEL(instance), single_line_mode);

}

void GtkLabel_::set_angle(Php::Parameters &parameters)
{
	gdouble angle = (gdouble)parameters[0];

	gtk_label_set_angle (GTK_LABEL(instance), angle);

}

Php::Value GtkLabel_::get_current_uri()
{
	std::string ret = gtk_label_get_current_uri (GTK_LABEL(instance));

	return ret;
}

void GtkLabel_::set_track_visited_links(Php::Parameters &parameters)
{
	gboolean track_links = (gboolean)parameters[0];

	gtk_label_set_track_visited_links (GTK_LABEL(instance), track_links);

}

Php::Value GtkLabel_::get_track_visited_links()
{
	gboolean ret = gtk_label_get_track_visited_links (GTK_LABEL(instance));

	return ret;
}

void GtkLabel_::set_ellipsize(Php::Parameters &parameters)
{
	int int_etype = (int)parameters[0];
	PangoEllipsizeMode etype = (PangoEllipsizeMode)int_etype;

	gtk_label_set_ellipsize (GTK_LABEL(instance), etype);

}

Php::Value GtkLabel_::get_ellipsize()
{
	gint ret = gtk_label_get_ellipsize (GTK_LABEL(instance));

	return ret;
}

