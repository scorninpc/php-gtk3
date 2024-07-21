
#include "GtkFlowBoxChild.h"

/**
 * Constructor
 */
GtkFlowBoxChild_::GtkFlowBoxChild_() = default;

/**
 * Destructor
 */
GtkFlowBoxChild_::~GtkFlowBoxChild_() = default;

void GtkFlowBoxChild_::__construct()
{
	instance = (gpointer *)gtk_flow_box_child_new ();
}

Php::Value GtkFlowBoxChild_::get_index()
{
	gint ret = gtk_flow_box_child_get_index (GTK_FLOW_BOX_CHILD(instance));

	return ret;
}

Php::Value GtkFlowBoxChild_::is_selected()
{
	bool ret = gtk_flow_box_child_is_selected (GTK_FLOW_BOX_CHILD(instance));

	return ret;
}

void GtkFlowBoxChild_::changed()
{
	gtk_flow_box_child_changed (GTK_FLOW_BOX_CHILD(instance));

}

