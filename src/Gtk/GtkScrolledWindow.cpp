
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

void GtkScrolledWindow_::set_overlay_scrolling(Php::Parameters &parameters)
{
    gboolean overlay_scrolling = (gboolean)parameters[0];

    gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(instance), overlay_scrolling);
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

void GtkScrolledWindow_::set_propagate_natural_height(Php::Parameters &parameters)
{
    gboolean natural_height = (gboolean)parameters[0];

    gtk_scrolled_window_set_propagate_natural_height(GTK_SCROLLED_WINDOW(instance), natural_height);
}

void GtkScrolledWindow_::set_propagate_natural_width(Php::Parameters &parameters)
{
    gboolean natural_height = (gboolean)parameters[0];

    gtk_scrolled_window_set_propagate_natural_width(GTK_SCROLLED_WINDOW(instance), natural_height);
}

void GtkScrolledWindow_::set_max_content_height(Php::Parameters &parameters)
{
    int height = (int)parameters[0];

    gtk_scrolled_window_set_max_content_height(GTK_SCROLLED_WINDOW(instance), height);
}

void GtkScrolledWindow_::set_min_content_height(Php::Parameters &parameters)
{
    int height = (int)parameters[0];

    gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(instance), height);
}

Php::Value GtkScrolledWindow_::get_vadjustment()
{
    gpointer* ret = (gpointer*)gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(instance));

    return cobject_to_phpobject(ret);
}

Php::Value GtkScrolledWindow_::get_hadjustment()
{
    gpointer* ret = (gpointer*)gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(instance));

    return cobject_to_phpobject(ret);
}

void GtkScrolledWindow_::set_max_content_width(Php::Parameters &parameters)
{
    int width = (int)parameters[0];

    gtk_scrolled_window_set_max_content_width(GTK_SCROLLED_WINDOW(instance), width);
}

void GtkScrolledWindow_::set_min_content_width(Php::Parameters &parameters)
{
    int width = (int)parameters[0];

    gtk_scrolled_window_set_min_content_width(GTK_SCROLLED_WINDOW(instance), width);
}