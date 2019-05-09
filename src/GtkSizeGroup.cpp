
#include "GtkSizeGroup.h"

/**
 * Constructor
 */
GtkSizeGroup_::GtkSizeGroup_() = default;

/**
 * Destructor
 */
GtkSizeGroup_::~GtkSizeGroup_() = default;

void GtkSizeGroup_::__construct(Php::Parameters &parameters)
{
	int int_mode = (int)parameters[0];
	GtkSizeGroupMode mode = (GtkSizeGroupMode)int_mode;

	instance = (gpointer *)gtk_size_group_new (mode);

}

void GtkSizeGroup_::set_mode(Php::Parameters &parameters)
{
	int int_mode = (int)parameters[0];
	GtkSizeGroupMode mode = (GtkSizeGroupMode)int_mode;

	gtk_size_group_set_mode (GTK_SIZE_GROUP(instance), mode);

}

Php::Value GtkSizeGroup_::get_mode()
{
	GtkSizeGroupMode ret = gtk_size_group_get_mode (GTK_SIZE_GROUP(instance));

	return ret;
}

void GtkSizeGroup_::add_widget(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gtk_size_group_add_widget (GTK_SIZE_GROUP(instance), widget);

}

void GtkSizeGroup_::remove_widget(Php::Parameters &parameters)
{
	GtkWidget *widget;
	if(parameters.size() > 0) {
		Php::Value object_widget = parameters[0];
		GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
		widget = GTK_WIDGET(phpgtk_widget->get_instance());
	}

	gtk_size_group_remove_widget (GTK_SIZE_GROUP(instance), widget);

}

Php::Value GtkSizeGroup_::get_widgets()
{
	// GSList ret = gtk_size_group_get_widgets (GTK_SIZE_GROUP(instance));

	// return ret;

	return 1;
}

