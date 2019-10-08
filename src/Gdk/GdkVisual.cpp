
#include "GdkVisual.h"

/**
 * Constructor
 */
GdkVisual_::GdkVisual_() = default;

/**
 * Destructor
 */
GdkVisual_::~GdkVisual_() = default;

Php::Value GdkVisual_::get_blue_pixel_details(Php::Parameters &parameters)
{
	guint32 mask;
	gint shift;
	gint precision;

	gdk_visual_get_blue_pixel_details (GDK_VISUAL(instance), &mask, &shift, &precision);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["mask"] = (int)mask;
	arr[1] = arr["shift"] = (int)shift;
	arr[2] = arr["precision"] = (int)precision;

	return arr;
}

Php::Value GdkVisual_::get_green_pixel_details(Php::Parameters &parameters)
{
	guint32 mask;
	gint shift;
	gint precision;

	gdk_visual_get_green_pixel_details (GDK_VISUAL(instance), &mask, &shift, &precision);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["mask"] = (int)mask;
	arr[1] = arr["shift"] = (int)shift;
	arr[2] = arr["precision"] = (int)precision;

	return arr;
}

Php::Value GdkVisual_::get_red_pixel_details(Php::Parameters &parameters)
{
	guint32 mask;
	gint shift;
	gint precision;

	gdk_visual_get_red_pixel_details (GDK_VISUAL(instance), &mask, &shift, &precision);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["mask"] = (int)mask;
	arr[1] = arr["shift"] = (int)shift;
	arr[2] = arr["precision"] = (int)precision;

	return arr;
}

Php::Value GdkVisual_::get_depth()
{
	gint ret = gdk_visual_get_depth (GDK_VISUAL(instance));

	return ret;
}

Php::Value GdkVisual_::get_visual_type()
{
	GdkVisualType ret = gdk_visual_get_visual_type (GDK_VISUAL(instance));

	return ret;
}

Php::Value GdkVisual_::get_screen()
{
	// GdkScreen ret = gdk_visual_get_screen (GDK_VISUAL(instance));

	// return ret;

	return 1;
}

