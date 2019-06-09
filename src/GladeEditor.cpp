
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

	// glade_editor_load_widget (GLADE_EDITOR(instance), widget);
	throw Php::Exception("GladeEditor_::load_widget not implemented");
}

Php::Value GladeEditor_::query_dialog(Php::Parameters &parameters)
{
	throw Php::Exception("GladeEditor_::query_dialog not implemented");
	// gboolean ret = glade_editor_query_dialog (GLADE_EDITOR(instance), widget);

	// return ret;
	return false;
}

