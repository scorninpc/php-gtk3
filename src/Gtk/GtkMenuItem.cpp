
#include "GtkMenuItem.h"

/**
 * Constructor
 */
GtkMenuItem_::GtkMenuItem_() = default;

/**
 * Destructor
 */
GtkMenuItem_::~GtkMenuItem_() = default;

void GtkMenuItem_::__construct()
{
	instance = (gpointer *)gtk_menu_item_new ();

}

Php::Value GtkMenuItem_::new_with_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gpointer *ret = (gpointer *)gtk_menu_item_new_with_label (label);

	return cobject_to_phpobject(ret);

	// Create the PHP-GTK object and set GTK object
	// GtkMenuItem_ *menuitem_ = new GtkMenuItem_();
	// menuitem_->set_instance((gpointer *)menuitem);

	// // Return PHP-GTK object
	// return Php::Object("GtkMenuItem", menuitem_);
}

Php::Value GtkMenuItem_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gpointer *ret = (gpointer *)gtk_menu_item_new_with_mnemonic (label);

	return cobject_to_phpobject(ret);
	// // Create the PHP-GTK object and set GTK object
	// GtkMenuItem_ *menuitem_ = new GtkMenuItem_();
	// menuitem_->set_instance((gpointer *)menuitem);

	// // Return PHP-GTK object
	// return Php::Object("GtkMenuItem", menuitem_);
}

Php::Value GtkMenuItem_::get_label()
{
	std::string ret = gtk_menu_item_get_label (GTK_MENU_ITEM(instance));

	return ret;
}

void GtkMenuItem_::set_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gtk_menu_item_set_label (GTK_MENU_ITEM(instance), label);

}

Php::Value GtkMenuItem_::get_use_underline()
{
	bool ret = gtk_menu_item_get_use_underline (GTK_MENU_ITEM(instance));

	return ret;
}

void GtkMenuItem_::set_use_underline(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_menu_item_set_use_underline (GTK_MENU_ITEM(instance), setting);

}

void GtkMenuItem_::set_submenu(Php::Parameters &parameters)
{
	GtkWidget *submenu;
	if(parameters.size() > 0) {
		Php::Value object_submenu = parameters[0];
		GtkWidget_ *phpgtk_submenu = (GtkWidget_ *)object_submenu.implementation();
		submenu = GTK_WIDGET(phpgtk_submenu->get_instance());
	}

	gtk_menu_item_set_submenu (GTK_MENU_ITEM(instance), submenu);

}

Php::Value GtkMenuItem_::get_submenu()
{
	gpointer *ret = (gpointer *)gtk_menu_item_get_submenu (GTK_MENU_ITEM(instance));

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

void GtkMenuItem_::set_accel_path(Php::Parameters &parameters)
{
	std::string s_accel_path = parameters[0];
	gchar *accel_path = (gchar *)s_accel_path.c_str();

	gtk_menu_item_set_accel_path (GTK_MENU_ITEM(instance), accel_path);

}

Php::Value GtkMenuItem_::get_accel_path()
{
	std::string ret = gtk_menu_item_get_accel_path (GTK_MENU_ITEM(instance));

	return ret;
}

void GtkMenuItem_::select()
{
	gtk_menu_item_select (GTK_MENU_ITEM(instance));

}

void GtkMenuItem_::deselect()
{
	gtk_menu_item_deselect (GTK_MENU_ITEM(instance));

}

void GtkMenuItem_::activate()
{
	gtk_menu_item_activate (GTK_MENU_ITEM(instance));

}

Php::Value GtkMenuItem_::toggle_size_request(Php::Parameters &parameters)
{
	gint requisition;

	gtk_menu_item_toggle_size_request (GTK_MENU_ITEM(instance), &requisition);

	return requisition;

}

void GtkMenuItem_::size_allocate(Php::Parameters &parameters)
{
	gint requisition = (gint)parameters[0];

	gtk_menu_item_toggle_size_allocate (GTK_MENU_ITEM(instance), requisition);

}

Php::Value GtkMenuItem_::get_reserve_indicator()
{
	bool ret = gtk_menu_item_get_reserve_indicator (GTK_MENU_ITEM(instance));

	return ret;
}

void GtkMenuItem_::set_reserve_indicator(Php::Parameters &parameters)
{
	gboolean reserve = (gboolean)parameters[0];

	gtk_menu_item_set_reserve_indicator (GTK_MENU_ITEM(instance), reserve);

}

void GtkMenuItem_::set_right_justified(Php::Parameters& parameters)
{
	gboolean right_justified = (gboolean)parameters[0];

	gtk_menu_item_set_right_justified(GTK_MENU_ITEM(instance), right_justified);
}


