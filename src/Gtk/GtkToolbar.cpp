
#include "GtkToolbar.h"

/**
 * Constructor
 */
GtkToolbar_::GtkToolbar_() = default;

/**
 * Destructor
 */
GtkToolbar_::~GtkToolbar_() = default;

void GtkToolbar_::__construct()
{
	instance = (gpointer *)gtk_toolbar_new ();

}

void GtkToolbar_::insert(Php::Parameters &parameters)
{
	GtkToolItem *item;
	if(parameters.size() > 0) {
		Php::Value object_item = parameters[0];
		GtkToolItem_ *phpgtk_item = (GtkToolItem_ *)object_item.implementation();
		item = GTK_TOOL_ITEM(phpgtk_item->get_instance());
	}

	gint pos = (gint)parameters[1];

	gtk_toolbar_insert (GTK_TOOLBAR(instance), item, pos);

}

Php::Value GtkToolbar_::get_item_index(Php::Parameters &parameters)
{
	GtkToolItem *item;
	if(parameters.size() > 0) {
		Php::Value object_item = parameters[0];
		GtkToolItem_ *phpgtk_item = (GtkToolItem_ *)object_item.implementation();
		item = GTK_TOOL_ITEM(phpgtk_item->get_instance());
	}

	gint ret = gtk_toolbar_get_item_index (GTK_TOOLBAR(instance), item);

	return ret;
}

Php::Value GtkToolbar_::get_n_items()
{
	gint ret = gtk_toolbar_get_n_items (GTK_TOOLBAR(instance));

	return ret;
}

Php::Value GtkToolbar_::get_nth_item(Php::Parameters &parameters)
{
	gint n = (gint)parameters[0];

	GtkToolItem *ret = gtk_toolbar_get_nth_item (GTK_TOOLBAR(instance), n);

	GtkToolItem_ *return_parsed = new GtkToolItem_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkToolItem", return_parsed);
}

Php::Value GtkToolbar_::get_drop_index(Php::Parameters &parameters)
{
	gint x = (gint)parameters[0];

	gint y = (gint)parameters[1];

	gint ret = gtk_toolbar_get_drop_index (GTK_TOOLBAR(instance), x, y);

	return ret;
}

void GtkToolbar_::set_drop_highlight_item(Php::Parameters &parameters)
{
	GtkToolItem *item;
	if(parameters.size() > 0) {
		Php::Value object_item = parameters[0];
		GtkToolItem_ *phpgtk_item = (GtkToolItem_ *)object_item.implementation();
		item = GTK_TOOL_ITEM(phpgtk_item->get_instance());
	}

	gint index = (gint)parameters[1];

	gtk_toolbar_set_drop_highlight_item (GTK_TOOLBAR(instance), item, index);

}

void GtkToolbar_::set_show_arrow(Php::Parameters &parameters)
{
	gboolean show_arrow = (gboolean)parameters[0];

	gtk_toolbar_set_show_arrow (GTK_TOOLBAR(instance), show_arrow);

}

void GtkToolbar_::unset_icon_size()
{
	gtk_toolbar_unset_icon_size (GTK_TOOLBAR(instance));

}

Php::Value GtkToolbar_::get_show_arrow()
{
	gboolean ret = gtk_toolbar_get_show_arrow (GTK_TOOLBAR(instance));

	return ret;
}

Php::Value GtkToolbar_::get_style()
{
	GtkToolbarStyle ret = gtk_toolbar_get_style (GTK_TOOLBAR(instance));

	return ret;
}

Php::Value GtkToolbar_::get_icon_size()
{
	GtkIconSize ret = gtk_toolbar_get_icon_size (GTK_TOOLBAR(instance));

	return ret;
}

Php::Value GtkToolbar_::get_relief_style()
{
	GtkReliefStyle ret = gtk_toolbar_get_relief_style (GTK_TOOLBAR(instance));

	return ret;
}

void GtkToolbar_::set_style(Php::Parameters &parameters)
{
	int int_style = (int)parameters[0];
	GtkToolbarStyle style = (GtkToolbarStyle)int_style;

	gtk_toolbar_set_style (GTK_TOOLBAR(instance), style);

}

void GtkToolbar_::set_icon_size(Php::Parameters &parameters)
{
	int int_style = (int)parameters[0];
	GtkIconSize style = (GtkIconSize)int_style;

	gtk_toolbar_set_icon_size (GTK_TOOLBAR(instance), style);

}

void GtkToolbar_::unset_style()
{
	gtk_toolbar_unset_style (GTK_TOOLBAR(instance));

}

