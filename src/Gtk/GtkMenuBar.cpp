
#include "GtkMenuBar.h"

/**
 * Constructor
 */
GtkMenuBar_::GtkMenuBar_() = default;

/**
 * Destructor
 */
GtkMenuBar_::~GtkMenuBar_() = default;

void GtkMenuBar_::__construct()
{
	instance = (gpointer *)gtk_menu_bar_new ();

}

void GtkMenuBar_::new_from_model(Php::Parameters &parameters)
{

	// gtk_menu_bar_new_from_model (model);
	throw Php::Exception("GtkMenuBar_::new_from_model not implemented");

}

void GtkMenuBar_::set_pack_direction(Php::Parameters &parameters)
{
	int int_pack_dir = (int)parameters[0];
	GtkPackDirection pack_dir = (GtkPackDirection)int_pack_dir;

	gtk_menu_bar_set_pack_direction (GTK_MENU_BAR(instance), pack_dir);

}

Php::Value GtkMenuBar_::get_pack_direction()
{
	GtkPackDirection ret = gtk_menu_bar_get_pack_direction (GTK_MENU_BAR(instance));

	return ret;
}

void GtkMenuBar_::set_child_pack_direction(Php::Parameters &parameters)
{
	int int_child_pack_dir = (int)parameters[0];
	GtkPackDirection child_pack_dir = (GtkPackDirection)int_child_pack_dir;

	gtk_menu_bar_set_child_pack_direction (GTK_MENU_BAR(instance), child_pack_dir);

}

void GtkMenuBar_::child_pack_direction()
{
	gtk_menu_bar_get_child_pack_direction (GTK_MENU_BAR(instance));

}

