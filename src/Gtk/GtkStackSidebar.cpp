
#include "GtkStackSidebar.h"

/**
 * Constructor
 */
GtkStackSidebar_::GtkStackSidebar_() = default;

/**
 * Destructor
 */
GtkStackSidebar_::~GtkStackSidebar_() = default;

void GtkStackSidebar_::__construct()
{
	instance = (gpointer *)gtk_stack_sidebar_new ();

}

void GtkStackSidebar_::set_stack(Php::Parameters &parameters)
{
	GtkStack *stack;
	if(parameters.size() > 0) {
		Php::Value object_stack = parameters[0];
		GtkStack_ *phpgtk_stack = (GtkStack_ *)object_stack.implementation();
		stack = GTK_STACK(phpgtk_stack->get_instance());
	}

	gtk_stack_sidebar_set_stack (GTK_STACK_SIDEBAR(instance), stack);

}

Php::Value GtkStackSidebar_::get_stack()
{
	GtkStack *ret = gtk_stack_sidebar_get_stack (GTK_STACK_SIDEBAR(instance));

	GtkStack_ *return_parsed = new GtkStack_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkStack", return_parsed);
}

