
#include "GtkScrolledWindow.h"

/**
 * Constructor
 */
GtkScrolledWindow_::GtkScrolledWindow_() = default;

/**
 * Destructor
 */
GtkScrolledWindow_::~GtkScrolledWindow_() = default;

/**
 *  PHP Constructor
 */
void GtkScrolledWindow_::__construct(Php::Parameters &parameters)
{
	instance = (gpointer *)gtk_scrolled_window_new(NULL, NULL);
}

/**
 * Sets the scrollbar policy for the horizontal and vertical scrollbars.
 */
void GtkScrolledWindow_::set_policy(Php::Parameters &parameters)
{
    // Cast hscrollbar_policy param
    int a = parameters[0];
    GtkPolicyType hscrollbar_policy = (GtkPolicyType)a;

    // Cast vscrollbar_policy param
    int b = parameters[1];
    GtkPolicyType vscrollbar_policy = (GtkPolicyType)b;

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(instance), hscrollbar_policy, vscrollbar_policy);
}

void GtkScrolledWindow_::set_shadow_type(Php::Parameters &parameters)
{
	int int_type = (int)parameters[0];
	GtkShadowType type = (GtkShadowType)int_type;

    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(instance), type);

}