
#include "GtkActionBar.h"

/**
 * Constructor
 */
GtkActionBar_::GtkActionBar_() = default;

/**
 * Destructor
 */
GtkActionBar_::~GtkActionBar_() = default;

void GtkActionBar_::__construct()
{
	instance = (gpointer *)gtk_action_bar_new ();

}

void GtkActionBar_::pack_start(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_action_bar_pack_start (GTK_ACTION_BAR(instance), child);

}

void GtkActionBar_::pack_end(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_action_bar_pack_end (GTK_ACTION_BAR(instance), child);

}

Php::Value GtkActionBar_::get_center_widget()
{
	GtkWidget *ret = gtk_action_bar_get_center_widget (GTK_ACTION_BAR(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkActionBar_::set_center_widget(Php::Parameters &parameters)
{
	GtkWidget *center_widget;
	if(parameters.size() > 0) {
		Php::Value object_center_widget = parameters[0];
		GtkWidget_ *phpgtk_center_widget = (GtkWidget_ *)object_center_widget.implementation();
		center_widget = GTK_WIDGET(phpgtk_center_widget->get_instance());
	}

	gtk_action_bar_set_center_widget (GTK_ACTION_BAR(instance), center_widget);

}

