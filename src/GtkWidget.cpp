
#include "GtkWidget.h"
#include "GtkBox.h"



/**
 *  C++ constructor and destructor
 */
GtkWidget_::GtkWidget_() = default;
GtkWidget_::~GtkWidget_() = default;

/**
 * Return original GtkWidget
 */
gpointer *GtkWidget_::get_widget()
{
    return instance;
}

/**
 * Set the original GtkWidget
 */
void GtkWidget_::set_widget(gpointer *pased_widget)
{
    instance = pased_widget;
}

/**
 * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show-all
 */
void GtkWidget_::show_all()
{
    gtk_widget_show_all(GTK_WIDGET(instance));
}

/**
 * Destroys a widget
 */
void GtkWidget_::destroy()
{
   gtk_widget_destroy(GTK_WIDGET(instance));
}

/**
 * Returns whether the widget is currently being destroyed
 */
Php::Value GtkWidget_::in_destruction()
{
   return gtk_widget_in_destruction(GTK_WIDGET(instance));
}

/**
 * This function sets *widget_pointer to NULL if widget_pointer != NULL
 *
 * @todo not tested
 */
void GtkWidget_::destroyed(Php::Parameters &parameters)
{
    Php::Value object = parameters[0];

    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");

    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();
    GtkWidget *pointer_to = GTK_WIDGET(passedWidget->get_instance());

    gtk_widget_destroyed(GTK_WIDGET(instance), &pointer_to);
}

/**
 * Should be called by implementations of the remove method on GtkContainer, to dissociate a child from the container
 *
 * @todo not tested
 */
void GtkWidget_::unparent()
{
     gtk_widget_destroy(GTK_WIDGET(instance));
}

/**
 * Flags a widget to be displayed
 */
void GtkWidget_::show()
{
     gtk_widget_show(GTK_WIDGET(instance));
}

/**
 * Shows a widget
 */
void GtkWidget_::show_now()
{
     gtk_widget_show_now(GTK_WIDGET(instance));
}

/**
 * Reverses the effects of gtk_widget_show(), causing the widget to be hidden
 */
void GtkWidget_::hide()
{
     gtk_widget_hide(GTK_WIDGET(instance));
}

/**
 * Causes a widget to be mapped if it isn’t already
 *
 * @todo not tested
 */
void GtkWidget_::map()
{
    gtk_widget_map(GTK_WIDGET(instance));
}

/**
 * Causes a widget to be unmapped if it’s currently mapped.
 *
 * @todo not tested
 */
void GtkWidget_::unmap()
{
    gtk_widget_unmap(GTK_WIDGET(instance));
}


/**
 * if you show a widget and all its parent containers, then the widget will be realized and mapped automatically.
 *
 * @todo not tested
 */
void GtkWidget_::realize()
{
    gtk_widget_realize(GTK_WIDGET(instance));
}

/**
 * Causes a widget to be unrealized
 *
 * @todo not tested
 */
void GtkWidget_::unrealize()
{
    gtk_widget_unrealize(GTK_WIDGET(instance));
}

/**
 * You should pass a cairo context as cr argument that is in an original state
 *
 * @todo not implemented, needs cairo
 */
void GtkWidget_::draw()
{
    throw Php::Exception("GtkWidget->draw() not implemented yet");
}

/**
 * Equivalent to calling gtk_widget_queue_draw_area() for the entire area of a widget.
 *
 * @todo not tested
 */
void GtkWidget_::queue_draw()
{
    gtk_widget_queue_draw(GTK_WIDGET(instance));
}

/**
 * Flags a widget to have its size renegotiated.
 *
 * @todo not tested
 */
void GtkWidget_::queue_resize()
{
    gtk_widget_queue_resize(GTK_WIDGET(instance));
}

/**
 * This function works like queue_resize(), except that the widget is not invalidated.
 *
 * @todo not tested
 */
void GtkWidget_::queue_resize_no_redraw()
{
    gtk_widget_queue_resize_no_redraw(GTK_WIDGET(instance));
}

/**
 * Flags the widget for a rerun of the GtkWidgetClass::size_allocate function
 *
 * @todo not tested
 */
void GtkWidget_::queue_allocate()
{
    gtk_widget_queue_allocate(GTK_WIDGET(instance));
}

/**
 * Retrieves the internal scale factor that maps from window coordinates to the actual device pixels.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::get_scale_factor()
{
    return gtk_widget_get_scale_factor(GTK_WIDGET(instance));
}

/**
 * For widgets that can be activated this function activates them.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::activate()
{
    return gtk_widget_activate(GTK_WIDGET(instance));
}

/**
 * Determines if the widget is the focus widget within its toplevel.
 */
Php::Value GtkWidget_::is_focus()
{
   return gtk_widget_is_focus(GTK_WIDGET(instance));
}

/**
 * Causes widget to have the keyboard focus for the GtkWindow it's inside
 */
void GtkWidget_::grab_focus()
{
    gtk_widget_grab_focus(GTK_WIDGET(instance));
}

/**
 * Determines if the widget has the global input focus.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::has_focus()
{
    return gtk_widget_has_focus(GTK_WIDGET(instance));
}

/**
 * Causes widget to become the default widget.
 *
 * @todo not tested
 */
void GtkWidget_::grab_default()
{
    gtk_widget_set_can_default(GTK_WIDGET(instance), true);
    gtk_widget_grab_default(GTK_WIDGET(instance));
}

/**
 * Widgets can be named, which allows you to refer to them from a CSS file.
 *
 * @todo not tested
 */
void GtkWidget_::set_name(Php::Parameters &parameters)
{
    gtk_widget_set_name(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Retrieves the name of a widget.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::get_name()
{
    return gtk_widget_get_name(GTK_WIDGET(instance));
}

/**
 * Sets the sensitivity of a widget.
 */
void GtkWidget_::set_sensitive(Php::Parameters &parameters)
{
    gtk_widget_set_sensitive(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Gets the sensitivity of a widget.
 */
Php::Value GtkWidget_::get_sensitive()
{
    return gtk_widget_get_sensitive(GTK_WIDGET(instance));
}

/**
 * If widget are sensitivity, include if parent is sensitive
 */
Php::Value GtkWidget_::is_sensitive()
{
    return (bool)gtk_widget_is_sensitive(GTK_WIDGET(instance));
}

/**
 * Sets the sensitivity of a widget.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::mnemonic_activate(Php::Parameters &parameters)
{
    return gtk_widget_mnemonic_activate(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Returns the parent container of widget.
 *
 * @todo C++ are strong typed, so, try to create a method to convert Gtk types and return PHP Gtk types, no use if in all method
 */
Php::Value GtkWidget_::get_parent()
{
    GtkWidget *parent_widget = gtk_widget_get_parent(GTK_WIDGET(instance));
    std::string widget_type = gtk_widget_get_name(parent_widget);

    if(widget_type == "GtkBox")
    {
        // Create the object
        GtkBox_ *return_widget = new GtkBox_();
        return_widget->set_instance((gpointer *)parent_widget);

        // Return the object
        return Php::Object("GtkBox", return_widget);
    }
    
    throw Php::Exception("Parent type of " + widget_type + " not implemented yet");
}

/**
 * Sets text as the contents of the tooltip
 */
void GtkWidget_::set_tooltip_text(Php::Parameters &parameters)
{
    std::string tooltip = parameters[0];

    // Set the tooltip text
    gtk_widget_set_tooltip_text(GTK_WIDGET(instance), tooltip.c_str());
}

/**
 * Gets text as the contents of the tooltip
 */
Php::Value GtkWidget_::get_tooltip_text()
{
    // Get the tooltip text
    return gtk_widget_get_tooltip_text(GTK_WIDGET(instance));
}

/**
 * Returns the current value of the has-tooltip property
 */
Php::Value GtkWidget_::get_has_tooltip()
{
    // Get if has tooltip
    return gtk_widget_get_has_tooltip(GTK_WIDGET(instance));
}

/**
 * Returns the width that has currently been allocated to widget
 */
Php::Value GtkWidget_::get_allocated_width()
{
    return gtk_widget_get_allocated_width(GTK_WIDGET(instance));
}

/**
 * Returns the height that has currently been allocated to widget
 */
Php::Value GtkWidget_::get_allocated_height()
{
    return gtk_widget_get_allocated_height(GTK_WIDGET(instance));
}

/**
 * Sets whether the widget should grab focus when it is clicked with the mouse.
 */
void GtkWidget_::set_focus_on_click(Php::Parameters &parameters)
{
   gtk_widget_set_focus_on_click(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Sets the visibility state of widget
 */
void GtkWidget_::set_visible(Php::Parameters &parameters)
{
    gtk_widget_set_visible(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Gets the visibility state of widget
 */
Php::Value GtkWidget_::get_visible()
{
    return gtk_widget_get_visible(GTK_WIDGET(instance));
}

/**
 * Sets the opacity of widget
 */
void GtkWidget_::set_opacity(Php::Parameters &parameters)
{
    gtk_widget_set_opacity(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Gets the opacity of widget
 */
Php::Value GtkWidget_::get_opacity()
{
    return gtk_widget_get_opacity(GTK_WIDGET(instance));
}

/**
 * Sets the vertical align of widget
 */
void GtkWidget_::set_valign(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GtkAlign passedAlign = (GtkAlign)a;

    gtk_widget_set_valign(GTK_WIDGET(instance), passedAlign);
}

/**
 * Gets the vertical align of widget
 */
Php::Value GtkWidget_::get_valign()
{
    return gtk_widget_get_valign(GTK_WIDGET(instance));
}

/**
 * Sets the horizontal align of widget
 */
void GtkWidget_::set_halign(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GtkAlign passedAlign = (GtkAlign)a;

    gtk_widget_set_halign(GTK_WIDGET(instance), passedAlign);
}

/**
 * Gets the horizontal align of widget
 */
Php::Value GtkWidget_::get_halign()
{
    return gtk_widget_get_halign(GTK_WIDGET(instance));
}

/**
 * Sets the start margin of widget
 */
void GtkWidget_::set_margin_start(Php::Parameters &parameters)
{
    gtk_widget_set_margin_start(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Gets the start margin of widget
 */
Php::Value GtkWidget_::get_margin_start()
{
    return gtk_widget_get_margin_start(GTK_WIDGET(instance));
}

/**
 * Sets the end margin of widget
 */
void GtkWidget_::set_margin_end(Php::Parameters &parameters)
{
    gtk_widget_set_margin_end(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Gets the end margin of widget
 */
Php::Value GtkWidget_::get_margin_end()
{
    return gtk_widget_get_margin_end(GTK_WIDGET(instance));
}

/**
 * Sets the top margin of widget
 */
void GtkWidget_::set_margin_top(Php::Parameters &parameters)
{
    gtk_widget_set_margin_top(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Gets the top margin of widget
 */
Php::Value GtkWidget_::get_margin_top()
{
    return gtk_widget_get_margin_top(GTK_WIDGET(instance));
}

/**
 * Sets the bottom margin of widget
 */
void GtkWidget_::set_margin_bottom(Php::Parameters &parameters)
{
    gtk_widget_set_margin_bottom(GTK_WIDGET(instance), parameters[0]);
}

/**
 * Gets the bottom margin of widget
 */
Php::Value GtkWidget_::get_margin_bottom()
{
    return gtk_widget_get_margin_bottom(GTK_WIDGET(instance));
}


/**
 * Sets the default size of a window
 */
void GtkWidget_::set_size_request(Php::Parameters &parameters)
{
    // Verify sizes
    int width = parameters[0];
    int height = parameters[1];

    // Set default size
    gtk_widget_set_size_request(GTK_WIDGET(instance), width, height);
}

Php::Value GtkWidget_::get_size_request(Php::Parameters &parameters)
{
    // Verify sizes
    int width = -1;
    int height = -1;

    // Set default size
    gtk_widget_get_size_request(GTK_WIDGET(instance), &width, &height);

    // Cria o retorno
    Php::Value arr;
    arr["width"] = width;
    arr["height"] = height;
    arr[0] = width;
    arr[1] = height;

    return arr;
}