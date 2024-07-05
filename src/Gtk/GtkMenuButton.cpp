
#include "GtkMenuButton.h"

/**
 * Constructor
 */
GtkMenuButton_::GtkMenuButton_() = default;

/**
 * Destructor
 */
GtkMenuButton_::~GtkMenuButton_() = default;

void GtkMenuButton_::__construct()
{
	instance = (gpointer *)gtk_menu_button_new();
}

void GtkMenuButton_::set_popup(Php::Parameters& parameters)
{
	GtkWidget *menu;

	Php::Value object_menu = parameters[0];
	GtkWidget_ *phpgtk_menu = (GtkWidget_ *)object_menu.implementation();
	menu = GTK_WIDGET(phpgtk_menu->get_instance());

	gtk_menu_button_set_popup (GTK_MENU_BUTTON(instance), menu);
}