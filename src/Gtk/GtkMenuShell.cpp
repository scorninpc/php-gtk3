
#include "GtkMenuShell.h"

/**
 * Constructor
 */
GtkMenuShell_::GtkMenuShell_() = default;

/**
 * Destructor
 */
GtkMenuShell_::~GtkMenuShell_() = default;

void GtkMenuShell_::append(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_menu_shell_append (GTK_MENU_SHELL(instance), child);

}

void GtkMenuShell_::prepend(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_menu_shell_prepend (GTK_MENU_SHELL(instance), child);

}

void GtkMenuShell_::insert(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint position = (gint)parameters[1];

	gtk_menu_shell_insert (GTK_MENU_SHELL(instance), child, position);

}

void GtkMenuShell_::deactivate()
{
	gtk_menu_shell_deactivate (GTK_MENU_SHELL(instance));

}

void GtkMenuShell_::select_item(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_menu_shell_select_item (GTK_MENU_SHELL(instance), child);

}

void GtkMenuShell_::select_first(Php::Parameters &parameters)
{
	gboolean search_sensitive = (gboolean)parameters[0];

	gtk_menu_shell_select_first (GTK_MENU_SHELL(instance), search_sensitive);

}

void GtkMenuShell_::deselect()
{
	gtk_menu_shell_deselect (GTK_MENU_SHELL(instance));

}

void GtkMenuShell_::activate_item(Php::Parameters &parameters)
{
	GtkWidget *menu_item;
	if(parameters.size() > 0) {
		Php::Value object_menu_item = parameters[0];
		GtkWidget_ *phpgtk_menu_item = (GtkWidget_ *)object_menu_item.implementation();
		menu_item = GTK_WIDGET(phpgtk_menu_item->get_instance());
	}

	gboolean force_deactivate = (gboolean)parameters[1];

	gtk_menu_shell_activate_item (GTK_MENU_SHELL(instance), menu_item, force_deactivate);

}

void GtkMenuShell_::cancel()
{
	gtk_menu_shell_cancel (GTK_MENU_SHELL(instance));

}

void GtkMenuShell_::set_take_focus(Php::Parameters &parameters)
{
	gboolean take_focus = (gboolean)parameters[0];

	gtk_menu_shell_set_take_focus (GTK_MENU_SHELL(instance), take_focus);

}

Php::Value GtkMenuShell_::get_take_focus()
{
	gboolean ret = gtk_menu_shell_get_take_focus (GTK_MENU_SHELL(instance));

	return ret;
}

Php::Value GtkMenuShell_::get_selected_item()
{
	gpointer *ret = (gpointer *)gtk_menu_shell_get_selected_item (GTK_MENU_SHELL(instance));

	return cobject_to_phpobject(ret);
	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkMenuShell_::get_parent_shell()
{
	gpointer *ret = (gpointer *)gtk_menu_shell_get_parent_shell (GTK_MENU_SHELL(instance));

	return cobject_to_phpobject(ret);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

void GtkMenuShell_::bind_model(Php::Parameters &parameters)
{

	// std::string s_action_namespace = parameters[1];
	// gchar *action_namespace = (gchar *)s_action_namespace.c_str();

	// gboolean with_separators = (gboolean)parameters[2];

	// gtk_menu_shell_bind_model (GTK_MENU_SHELL(instance), model, action_namespace, with_separators);

	throw Php::Exception("GtkMenuShell_::bind_model not implemented");

}

