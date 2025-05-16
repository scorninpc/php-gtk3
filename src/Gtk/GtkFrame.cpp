
#include "GtkFrame.h"

/**
 * Constructor
 */
GtkFrame_::GtkFrame_() = default;

/**
 * Destructor
 */
GtkFrame_::~GtkFrame_() = default;

void GtkFrame_::__construct(Php::Parameters &parameters)
{
	std::string s_str = "";
	if(parameters.size() > 0) {
		s_str.assign((const char *)parameters[0]);
	}

	instance = (gpointer *)gtk_frame_new (s_str.c_str());

}

void GtkFrame_::set_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gtk_frame_set_label (GTK_FRAME(instance), label);

}

void GtkFrame_::set_label_widget(Php::Parameters &parameters)
{
	GtkWidget *label_widget;
	if(parameters.size() > 0) {
		Php::Value object_label_widget = parameters[0];
		GtkWidget_ *phpgtk_label_widget = (GtkWidget_ *)object_label_widget.implementation();
		label_widget = GTK_WIDGET(phpgtk_label_widget->get_instance());
	}

	gtk_frame_set_label_widget (GTK_FRAME(instance), label_widget);

}

void GtkFrame_::set_label_align(Php::Parameters &parameters)
{
	double d_xalign = parameters[0];
	gfloat xalign = (float)d_xalign;

	double d_yalign = parameters[1];
	gfloat yalign = (float)d_yalign;

	gtk_frame_set_label_align (GTK_FRAME(instance), xalign, yalign);

}

void GtkFrame_::set_shadow_type(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GtkShadowType type = (GtkShadowType)int_type;

	gtk_frame_set_shadow_type (GTK_FRAME(instance), type);

}

Php::Value GtkFrame_::get_label()
{
	std::string ret = gtk_frame_get_label (GTK_FRAME(instance));

	return ret;
}

Php::Value GtkFrame_::get_label_align(Php::Parameters &parameters)
{
	gfloat d_xalign;
	gfloat d_yalign;

	gtk_frame_get_label_align (GTK_FRAME(instance), &d_xalign, &d_yalign);

	
	// Cria o retorno
    Php::Value arr;
    arr[0] = arr["xalign"] = (int)d_xalign;
    arr[1] = arr["yalign"] = (int)d_yalign;

    return arr;
}

Php::Value GtkFrame_::get_label_widget()
{
	gpointer *ret = (gpointer *)gtk_frame_get_label_widget (GTK_FRAME(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
	return cobject_to_phpobject(ret);
}

Php::Value GtkFrame_::get_shadow_type()
{
	GtkShadowType ret = gtk_frame_get_shadow_type (GTK_FRAME(instance));

	return ret;
}

