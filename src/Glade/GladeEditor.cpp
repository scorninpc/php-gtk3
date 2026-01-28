#ifdef WITH_GLADEUI
#include "GladeEditor.h"

/**
 * Constructor
 */
GladeEditor_::GladeEditor_() = default;

/**
 * Destructor
 */
GladeEditor_::~GladeEditor_() = default;

void GladeEditor_::__construct()
{
	instance = (gpointer *)glade_editor_new ();

}

void GladeEditor_::load_widget(Php::Parameters &parameters)
{
	Php::Value object_widget = parameters[0];
	GladeWidget_ *phpgtk_widget = (GladeWidget_ *)object_widget.implementation();
	GladeWidget *widget = (GladeWidget *)phpgtk_widget->get_instance();

	// Php::call("var_dump", glade_widget_get_name(widget));


	glade_editor_load_widget (GLADE_EDITOR(instance), glade_widget_get_from_gobject(widget));
}

Php::Value GladeEditor_::query_dialog(Php::Parameters &parameters)
{
	throw Php::Exception("GladeEditor_::query_dialog not implemented");
	// gboolean ret = glade_editor_query_dialog (GLADE_EDITOR(instance), widget);

	// return ret;
	return false;
}

#endif