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