#include "PangoLayout.h"

/**
 * Constructor
 */
PangoLayout_::PangoLayout_() = default;

/**
 * Destructor
 */
PangoLayout_::~PangoLayout_() = default;

void PangoLayout_::__construct(Php::Parameters &parameters)
{
	Php::Value object_pango_context = parameters[0];
	PangoContext_ *pango_context = (PangoContext_*) object_pango_context.implementation();

	instance = (gpointer*) pango_layout_new (PANGO_CONTEXT(pango_context->get_instance()));
}

void PangoLayout_::set_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar* text = (gchar*) s_text.c_str();

	gint length = (gint) parameters[1];

	pango_layout_set_text(PANGO_LAYOUT(instance), text, length);
}

void PangoLayout_::set_width(Php::Parameters &parameters)
{
	gint width = (gint) parameters[0];

	pango_layout_set_width(PANGO_LAYOUT(instance), width);
}

Php::Value PangoLayout_::get_line(Php::Parameters &parameters)
{
	throw Php::Exception("PangoLayout::get_line not implemented");

	/* @TODO 
	gint line = (gint) parameters[0];

	return pango_layout_get_line(PANGO_LAYOUT(instance), line);
	*/
}

Php::Value PangoLayout_::get_text()
{
	return pango_layout_get_text(PANGO_LAYOUT(instance));
}

Php::Value PangoLayout_::get_width()
{
	return pango_layout_get_width(PANGO_LAYOUT(instance));
}

/**
* https://docs.gtk.org/Pango/method.Layout.get_extents.html
*/

Php::Value PangoLayout_::get_extents()
{
	/**
	* https://docs.gtk.org/Pango/struct.Rectangle.html
	*/
	PangoRectangle ink_rect;
	PangoRectangle logical_rect;

	pango_layout_get_extents(
		PANGO_LAYOUT(
			instance
		),
		&ink_rect,
		&logical_rect
	);

	Php::Array ink_rect_arr;

		ink_rect_arr["x"] = (int) ink_rect.x;
		ink_rect_arr["y"] = (int) ink_rect.y;
		ink_rect_arr["width"] = (int) ink_rect.width;
		ink_rect_arr["height"] = (int) ink_rect.height;

	Php::Array logical_rect_arr;

		logical_rect_arr["x"] = (int) logical_rect.x;
		logical_rect_arr["y"] = (int) logical_rect.y;
		logical_rect_arr["width"] = (int) logical_rect.width;
		logical_rect_arr["height"] = (int) logical_rect.height;

	Php::Array ret_arr;

		ret_arr["ink_rect"] = ink_rect_arr;
		ret_arr["logical_rect"] = logical_rect_arr;

	return ret_arr;
}