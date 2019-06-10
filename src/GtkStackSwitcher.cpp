
#include "GtkStackSwitcher.h"

/**
 * Constructor
 */
GtkStackSwitcher_::GtkStackSwitcher_() = default;

/**
 * Destructor
 */
GtkStackSwitcher_::~GtkStackSwitcher_() = default;

void GtkStackSwitcher_::__construct()
{
	instance = (gpointer *)gtk_stack_switcher_new ();

}

void GtkStackSwitcher_::set_stack(Php::Parameters &parameters)
{
	GtkStack *stack;
	if(parameters.size() > 0) {
		Php::Value object_stack = parameters[0];
		GtkStack_ *phpgtk_stack = (GtkStack_ *)object_stack.implementation();
		stack = GTK_STACK(phpgtk_stack->get_instance());
	}

	gtk_stack_switcher_set_stack (GTK_STACK_SWITCHER(instance), stack);

}

Php::Value GtkStackSwitcher_::get_stack()
{
	GtkStack *ret = gtk_stack_switcher_get_stack (GTK_STACK_SWITCHER(instance));

	GtkStack_ *return_parsed = new GtkStack_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkStack", return_parsed);
}

