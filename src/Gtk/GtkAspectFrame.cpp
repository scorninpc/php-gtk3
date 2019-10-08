
#include "GtkAspectFrame.h"

/**
 * Constructor
 */
GtkAspectFrame_::GtkAspectFrame_() = default;

/**
 * Destructor
 */
GtkAspectFrame_::~GtkAspectFrame_() = default;

void GtkAspectFrame_::__construct(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	double d_xalign = parameters[1];
	gfloat xalign = (float)d_xalign;

	double d_yalign = parameters[2];
	gfloat yalign = (float)d_yalign;

	double d_ratio = parameters[3];
	gfloat ratio = (float)d_ratio;

	gboolean obey_child = (gboolean)parameters[4];

	instance = (gpointer *)gtk_aspect_frame_new (label, xalign, yalign, ratio, obey_child);

}

void GtkAspectFrame_::set(Php::Parameters &parameters)
{
	double d_xalign = parameters[0];
	gfloat xalign = (float)d_xalign;

	double d_yalign = parameters[1];
	gfloat yalign = (float)d_yalign;

	double d_ratio = parameters[2];
	gfloat ratio = (float)d_ratio;

	gboolean obey_child = (gboolean)parameters[3];

	gtk_aspect_frame_set (GTK_ASPECT_FRAME(instance), xalign, yalign, ratio, obey_child);

}

