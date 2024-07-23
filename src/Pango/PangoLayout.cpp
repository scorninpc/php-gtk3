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