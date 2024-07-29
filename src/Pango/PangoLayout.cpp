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

/**
 * https://docs.gtk.org/Pango/method.Layout.set_markup.html
 */
void PangoLayout_::set_markup(Php::Parameters &parameters)
{
	std::string s_markup = parameters[0];
	gchar* markup = (gchar*) s_markup.c_str();

	gint length = (gint) parameters[1];

	pango_layout_set_markup(
		PANGO_LAYOUT(
			instance
		),
		markup,
		length
	);
}

void PangoLayout_::set_width(Php::Parameters &parameters)
{
	gint width = (gint) parameters[0];

	pango_layout_set_width(PANGO_LAYOUT(instance), width);
}

/**
 * https://docs.gtk.org/Pango/method.Layout.get_line.html
 */
Php::Value PangoLayout_::get_line(Php::Parameters &parameters)
{
	gint line = (gint) parameters[0];

	PangoLayoutLine* ret = pango_layout_get_line(
		PANGO_LAYOUT(instance), line
	);

	if (ret)
	{
		/**
		 * Build PangoLayoutLine
		 * https://docs.gtk.org/Pango/struct.LayoutLine.html
		 */

		Php::Array ret_arr;

		PangoLayout_ *return_parsed = new PangoLayout_();

		return_parsed->set_instance(
			(gpointer *)PANGO_LAYOUT(ret->layout)
		);

		ret_arr["layout"] = Php::Object("PangoLayout", return_parsed);
		ret_arr["start_index"] = (int) ret->start_index;
		ret_arr["length"] = (int) ret->length;

		// @TODO
		// ret_arr["runs"] = Php::Object("GSList", ret->runs);

		/**
		 * TRUE if this is the first line of the paragraph (by documentation)
		 */
		if (ret->is_paragraph_start == true) {
			ret_arr["is_paragraph_start"] = Php::Type::True;
		} else {
			ret_arr["is_paragraph_start"] = (int) ret->is_paragraph_start;
		}

		/**
		 * https://docs.gtk.org/Pango/enum.Direction.html
		 */
		ret_arr["resolved_dir"] = (int) ret->resolved_dir;

		return ret_arr;
	}

	return Php::Type::Null;
}

Php::Value PangoLayout_::get_text()
{
	return pango_layout_get_text(PANGO_LAYOUT(instance));
}

Php::Value PangoLayout_::get_width()
{
	return pango_layout_get_width(PANGO_LAYOUT(instance));
}

Php::Value PangoLayout_::xy_to_index(Php::Parameters &parameters)
{
	gint x = (gint) parameters[0]; // * Pango::SCALE
	gint y = (gint) parameters[1]; // * Pango::SCALE

	gint index_;
	gint trailing;

	gboolean result = pango_layout_xy_to_index(
		PANGO_LAYOUT(instance), x, y, &index_, &trailing
	);

	if (result) {

		Php::Array params;

		params["index_"] = (int) index_;
		params["trailing"] = (int) trailing;

		return params;

	}

	return Php::Type::False;
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

/**
* https://docs.gtk.org/Pango/method.Layout.get_size.html
*/

Php::Value PangoLayout_::get_size()
{
	gint width;
	gint height;

	pango_layout_get_size(
		PANGO_LAYOUT(
			instance
		),
		&width,
		&height
	);

	Php::Array ret_arr;

		ret_arr["width"] = (int) width;
		ret_arr["height"] = (int) height;

	return ret_arr;
}

/**
* https://docs.gtk.org/Pango/method.Layout.get_pixel_size.html
*/

Php::Value PangoLayout_::get_pixel_size()
{
	gint width;
	gint height;
	
	pango_layout_get_pixel_size(
		PANGO_LAYOUT(
			instance
		),
		&width,
		&height
	);

	Php::Array ret_arr;

		ret_arr["width"] = (int) width;
		ret_arr["height"] = (int) height;

	return ret_arr;
}