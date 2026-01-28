#ifdef WITH_GLADEUI
#include "GladePalette.h"

/**
 * Constructor
 */
GladePalette_::GladePalette_() = default;

/**
 * Destructor
 */
GladePalette_::~GladePalette_() = default;

void GladePalette_::__construct()
{
	instance = (gpointer *)glade_palette_new ();

}

Php::Value GladePalette_::get_item_appearance()
{
	throw Php::Exception("GladePalette_::get_item_appearance not implemented");

	// GladeItemAppearance ret = glade_palette_get_item_appearance (GLADE_PALETTE(instance));

	// return ret;
	return 1;
}

void GladePalette_::set_item_appearance(Php::Parameters &parameters)
{
	throw Php::Exception("GladePalette_::set_item_appearance not implemented");
	
	// int int_item_appearence = (int)parameters[0];
	// GladeItemAppearance item_appearence = (GladeItemAppearance)int_item_appearence;

	// glade_palette_set_item_appearance (GLADE_PALETTE(instance), item_appearence);

}

Php::Value GladePalette_::get_use_small_item_icons()
{
	bool ret = glade_palette_get_use_small_item_icons (GLADE_PALETTE(instance));

	return ret;
}

void GladePalette_::set_use_small_item_icons(Php::Parameters &parameters)
{
	gboolean use_small_item_icons = (gboolean)parameters[0];

	glade_palette_set_use_small_item_icons (GLADE_PALETTE(instance), use_small_item_icons);

}

Php::Value GladePalette_::get_show_selector_button()
{
	bool ret = glade_palette_get_show_selector_button (GLADE_PALETTE(instance));

	return ret;
}

void GladePalette_::set_show_selector_button(Php::Parameters &parameters)
{
	gboolean show_selector_button = (gboolean)parameters[0];

	glade_palette_set_show_selector_button (GLADE_PALETTE(instance), show_selector_button);

}

#endif