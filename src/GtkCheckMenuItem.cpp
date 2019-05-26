
#include "GtkCheckMenuItem.h"

/**
 * Constructor
 */
GtkCheckMenuItem_::GtkCheckMenuItem_() = default;

/**
 * Destructor
 */
GtkCheckMenuItem_::~GtkCheckMenuItem_() = default;

void GtkCheckMenuItem_::__construct()
{
	instance = (gpointer *)gtk_check_menu_item_new ();

}

Php::Value GtkCheckMenuItem_::new_with_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_check_menu_item_new_with_label (label);

	GtkCheckMenuItem_ *return_parsed = new GtkCheckMenuItem_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkCheckMenuItem", return_parsed);
}

Php::Value GtkCheckMenuItem_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_check_menu_item_new_with_mnemonic (label);

	GtkCheckMenuItem_ *return_parsed = new GtkCheckMenuItem_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkCheckMenuItem", return_parsed);
}

Php::Value GtkCheckMenuItem_::get_active()
{
	gboolean ret = gtk_check_menu_item_get_active (GTK_CHECK_MENU_ITEM(instance));

	return ret;
}

void GtkCheckMenuItem_::set_active(Php::Parameters &parameters)
{
	gboolean is_active = (gboolean)parameters[0];

	gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM(instance), is_active);

}

void GtkCheckMenuItem_::toggled()
{
	gtk_check_menu_item_toggled (GTK_CHECK_MENU_ITEM(instance));

}

Php::Value GtkCheckMenuItem_::get_inconsistent()
{
	gboolean ret = gtk_check_menu_item_get_inconsistent (GTK_CHECK_MENU_ITEM(instance));

	return ret;
}

void GtkCheckMenuItem_::set_inconsistent(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_check_menu_item_set_inconsistent (GTK_CHECK_MENU_ITEM(instance), setting);

}

Php::Value GtkCheckMenuItem_::get_draw_as_radio()
{
	gboolean ret = gtk_check_menu_item_get_draw_as_radio (GTK_CHECK_MENU_ITEM(instance));

	return ret;
}

void GtkCheckMenuItem_::set_draw_as_radio(Php::Parameters &parameters)
{
	gboolean draw_as_radio = (gboolean)parameters[0];

	gtk_check_menu_item_set_draw_as_radio (GTK_CHECK_MENU_ITEM(instance), draw_as_radio);

}

