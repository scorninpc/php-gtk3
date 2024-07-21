
#include "GtkSeparatorToolItem.h"

/**
 * Constructor
 */
GtkSeparatorToolItem_::GtkSeparatorToolItem_() = default;

/**
 * Destructor
 */
GtkSeparatorToolItem_::~GtkSeparatorToolItem_() = default;

void GtkSeparatorToolItem_::__construct()
{
	instance = (gpointer *)gtk_separator_tool_item_new ();

}

void GtkSeparatorToolItem_::set_draw(Php::Parameters &parameters)
{
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_separator_tool_item_set_draw (GTK_SEPARATOR_TOOL_ITEM(instance), homogeneous);

}

Php::Value GtkSeparatorToolItem_::get_draw()
{
	bool ret = gtk_separator_tool_item_get_draw (GTK_SEPARATOR_TOOL_ITEM(instance));

	return ret;
}

