
#include "GtkToolItem.h"

/**
 * Constructor
 */
GtkToolItem_::GtkToolItem_() = default;

/**
 * Destructor
 */
GtkToolItem_::~GtkToolItem_() = default;

void GtkToolItem_::__construct()
{
	instance = (gpointer *)gtk_tool_item_new ();

}

void GtkToolItem_::set_homogeneous(Php::Parameters &parameters)
{
	gboolean homogeneous = (gboolean)parameters[0];

	gtk_tool_item_set_homogeneous (GTK_TOOL_ITEM(instance), homogeneous);

}

Php::Value GtkToolItem_::get_homogeneous()
{
	gboolean ret = gtk_tool_item_get_homogeneous (GTK_TOOL_ITEM(instance));

	return ret;
}

void GtkToolItem_::set_expand(Php::Parameters &parameters)
{
	gboolean expand = (gboolean)parameters[0];

	gtk_tool_item_set_expand (GTK_TOOL_ITEM(instance), expand);

}

Php::Value GtkToolItem_::get_expand()
{
	gboolean ret = gtk_tool_item_get_expand (GTK_TOOL_ITEM(instance));

	return ret;
}

void GtkToolItem_::set_tooltip_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gtk_tool_item_set_tooltip_text (GTK_TOOL_ITEM(instance), text);

}

void GtkToolItem_::set_tooltip_markup(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gtk_tool_item_set_tooltip_markup (GTK_TOOL_ITEM(instance), text);

}

void GtkToolItem_::set_use_drag_window(Php::Parameters &parameters)
{
	gboolean use_drag_window = (gboolean)parameters[0];

	gtk_tool_item_set_use_drag_window (GTK_TOOL_ITEM(instance), use_drag_window);

}

Php::Value GtkToolItem_::get_use_drag_window()
{
	gboolean ret = gtk_tool_item_get_use_drag_window (GTK_TOOL_ITEM(instance));

	return ret;
}

void GtkToolItem_::set_visible_horizontal(Php::Parameters &parameters)
{
	gboolean visible_horizontal = (gboolean)parameters[0];

	gtk_tool_item_set_visible_horizontal (GTK_TOOL_ITEM(instance), visible_horizontal);

}

Php::Value GtkToolItem_::get_visible_horizontal()
{
	gboolean ret = gtk_tool_item_get_visible_horizontal (GTK_TOOL_ITEM(instance));

	return ret;
}

void GtkToolItem_::set_visible_vertical(Php::Parameters &parameters)
{
	gboolean visible_vertical = (gboolean)parameters[0];

	gtk_tool_item_set_visible_vertical (GTK_TOOL_ITEM(instance), visible_vertical);

}

Php::Value GtkToolItem_::get_visible_vertical()
{
	gboolean ret = gtk_tool_item_get_visible_vertical (GTK_TOOL_ITEM(instance));

	return ret;
}

void GtkToolItem_::set_is_important(Php::Parameters &parameters)
{
	gboolean is_important = (gboolean)parameters[0];

	gtk_tool_item_set_is_important (GTK_TOOL_ITEM(instance), is_important);

}

Php::Value GtkToolItem_::get_is_important()
{
	gboolean ret = gtk_tool_item_get_is_important (GTK_TOOL_ITEM(instance));

	return ret;
}

Php::Value GtkToolItem_::get_icon_size()
{
	GtkIconSize ret = gtk_tool_item_get_icon_size (GTK_TOOL_ITEM(instance));

	return ret;
}

Php::Value GtkToolItem_::get_orientation()
{
	GtkOrientation ret = gtk_tool_item_get_orientation (GTK_TOOL_ITEM(instance));

	return ret;
}

Php::Value GtkToolItem_::get_toolbar_style()
{
	GtkToolbarStyle ret = gtk_tool_item_get_toolbar_style (GTK_TOOL_ITEM(instance));

	return ret;
}

Php::Value GtkToolItem_::get_relief_style()
{
	GtkReliefStyle ret = gtk_tool_item_get_relief_style (GTK_TOOL_ITEM(instance));

	return ret;
}

Php::Value GtkToolItem_::get_text_alignment()
{
	gfloat ret = gtk_tool_item_get_text_alignment (GTK_TOOL_ITEM(instance));

	return ret;
}

Php::Value GtkToolItem_::get_text_orientation()
{
	GtkOrientation ret = gtk_tool_item_get_text_orientation (GTK_TOOL_ITEM(instance));

	return ret;
}

Php::Value GtkToolItem_::retrieve_proxy_menu_item()
{
	gpointer *ret = (gpointer *)gtk_tool_item_retrieve_proxy_menu_item (GTK_TOOL_ITEM(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	return cobject_to_phpobject(ret);
}

void GtkToolItem_::set_proxy_menu_item(Php::Parameters &parameters)
{
	std::string s_menu_item_id = parameters[0];
	gchar *menu_item_id = (gchar *)s_menu_item_id.c_str();

	GtkWidget *menu_item;
	if(parameters.size() > 1) {
		Php::Value object_menu_item = parameters[1];
		GtkWidget_ *phpgtk_menu_item = (GtkWidget_ *)object_menu_item.implementation();
		menu_item = GTK_WIDGET(phpgtk_menu_item->get_instance());
	}

	gtk_tool_item_set_proxy_menu_item (GTK_TOOL_ITEM(instance), menu_item_id, menu_item);

}

Php::Value GtkToolItem_::get_proxy_menu_item(Php::Parameters &parameters)
{
	std::string s_menu_item_id = parameters[0];
	gchar *menu_item_id = (gchar *)s_menu_item_id.c_str();

	gpointer *ret = (gpointer *)gtk_tool_item_get_proxy_menu_item (GTK_TOOL_ITEM(instance), menu_item_id);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	return cobject_to_phpobject(ret);
}

void GtkToolItem_::rebuild_menu()
{
	gtk_tool_item_rebuild_menu (GTK_TOOL_ITEM(instance));

}

void GtkToolItem_::toolbar_reconfigured()
{
	gtk_tool_item_toolbar_reconfigured (GTK_TOOL_ITEM(instance));

}

void GtkToolItem_::get_text_size_group()
{
	gtk_tool_item_get_text_size_group (GTK_TOOL_ITEM(instance));

}

