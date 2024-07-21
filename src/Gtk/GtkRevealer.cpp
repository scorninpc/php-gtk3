
#include "GtkRevealer.h"

/**
 * Constructor
 */
GtkRevealer_::GtkRevealer_() = default;

/**
 * Destructor
 */
GtkRevealer_::~GtkRevealer_() = default;

void GtkRevealer_::__construct()
{
	instance = (gpointer *)gtk_revealer_new ();

}

Php::Value GtkRevealer_::get_reveal_child()
{
	bool ret = gtk_revealer_get_reveal_child (GTK_REVEALER(instance));

	return ret;
}

void GtkRevealer_::set_reveal_child(Php::Parameters &parameters)
{
	gboolean reveal_child = (gboolean)parameters[0];

	gtk_revealer_set_reveal_child (GTK_REVEALER(instance), reveal_child);

}

Php::Value GtkRevealer_::get_child_revealed()
{
	bool ret = gtk_revealer_get_child_revealed (GTK_REVEALER(instance));

	return ret;
}

Php::Value GtkRevealer_::get_transition_duration()
{
	int ret = gtk_revealer_get_transition_duration (GTK_REVEALER(instance));

	return ret;
}

void GtkRevealer_::set_transition_duration(Php::Parameters &parameters)
{
	guint duration = (int)parameters[0];

	gtk_revealer_set_transition_duration (GTK_REVEALER(instance), duration);

}

Php::Value GtkRevealer_::get_transition_type()
{
	GtkRevealerTransitionType ret = gtk_revealer_get_transition_type (GTK_REVEALER(instance));

	return ret;
}

void GtkRevealer_::set_transition_type(Php::Parameters &parameters)
{
	int int_transition = (int)parameters[0];
	GtkRevealerTransitionType transition = (GtkRevealerTransitionType)int_transition;

	gtk_revealer_set_transition_type (GTK_REVEALER(instance), transition);

}

