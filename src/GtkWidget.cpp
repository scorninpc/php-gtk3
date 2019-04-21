
#include "GtkWidget.h"
#include "GtkBox.h"

/**
 * Struct for callback gpointer
 */
struct GtkWidget_::st_callback {
    Php::Value callback_name;
    Php::Array callback_params;
    Php::Object self_widget;
};

/**
 *  C++ constructor and destructor
 */
GtkWidget_::GtkWidget_() = default;
GtkWidget_::~GtkWidget_() = default;

/**
 * Return original GtkWidget
 */
GtkWidget *GtkWidget_::get_widget()
{
    return widget;
}

/**
 * Set the original GtkWidget
 */
void GtkWidget_::set_widget(GtkWidget *pased_widget)
{
    widget = pased_widget;
}

/**
 * https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-show-all
 */
void GtkWidget_::show_all()
{
    gtk_widget_show_all(widget);
}

/**
 * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
 *
 * @todo Verify if callback are callable with Php::Callable::Callable
 * @todo Some events like the delete-event, dont pass gpointer param correctly
 */
Php::Value GtkWidget_::connect(Php::Parameters &parameters)
{
    Php::Array callback_params = parameters;
    Php::Value callback_event = callback_params[0];
    Php::Value callback_name = callback_params[1];

    // Create gpoint param
    struct st_callback *callback_object = (struct st_callback *)malloc(sizeof(struct st_callback));
    memset(callback_object, 0, sizeof(struct st_callback));
    
    callback_object->callback_name = callback_name;
    callback_object->callback_params = callback_params;
    callback_object->self_widget = Php::Object("GtkWidget", this);

    // Create the CPP callback
    int ret = g_signal_connect(widget, callback_event, G_CALLBACK (&connect_callback), callback_object);

    // Return handler id
    return ret;
}

/**
 * Class to abstract php callback for connect method, to call PHP function
 */
void GtkWidget_::connect_callback(GtkWidget * widget, GdkEvent user_event, gpointer user_data)
{
    // Return to st_callback
    struct st_callback *callback_object = (struct st_callback *) user_data;

    // Create event from callback
    GdkEvent_ *event_ = new GdkEvent_();
    Php::Value gdkevent = Php::Object("GdkEvent", event_);
    event_->populate(&user_event);

    // Create internal params, GtkWidget + GdkEvent
    Php::Value internal_parameters;
    internal_parameters[0] = callback_object->self_widget;
    internal_parameters[1] = gdkevent;

    // Merge internal parameters with custom parameters
    Php::Value callback_params = callback_object->callback_params;
    Php::Value custom_parameters = Php::call("array_slice", callback_params, 2, callback_params.size());
    Php::Value php_callback_param = Php::call("array_merge", internal_parameters, custom_parameters);

    // Call php function with parameters
    Php::call("call_user_func_array", callback_object->callback_name, php_callback_param);
}

/**
 * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-handler-disconnect
 *
 * Disconnect signal by handle
 */
void GtkWidget_::handler_disconnect(Php::Parameters &parameters)
{
    Php::Value callback_handle = parameters[0];

    g_signal_handler_disconnect(widget, (int)callback_handle);
}

/**
 * Destroys a widget
 */
void GtkWidget_::destroy()
{
   gtk_widget_destroy(widget);
}

/**
 * Returns whether the widget is currently being destroyed
 */
Php::Value GtkWidget_::in_destruction()
{
   return gtk_widget_in_destruction(widget);
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
    GtkWidget *pointer_to = passedWidget->get_widget();

    gtk_widget_destroyed(widget, &pointer_to);
}

/**
 * Should be called by implementations of the remove method on GtkContainer, to dissociate a child from the container
 *
 * @todo not tested
 */
void GtkWidget_::unparent()
{
     gtk_widget_destroy(widget);
}

/**
 * Flags a widget to be displayed
 */
void GtkWidget_::show()
{
     gtk_widget_show(widget);
}

/**
 * Shows a widget
 */
void GtkWidget_::show_now()
{
     gtk_widget_show_now(widget);
}

/**
 * Reverses the effects of gtk_widget_show(), causing the widget to be hidden
 */
void GtkWidget_::hide()
{
     gtk_widget_hide(widget);
}

/**
 * Causes a widget to be mapped if it isn’t already
 *
 * @todo not tested
 */
void GtkWidget_::map()
{
    gtk_widget_map(widget);
}

/**
 * Causes a widget to be unmapped if it’s currently mapped.
 *
 * @todo not tested
 */
void GtkWidget_::unmap()
{
    gtk_widget_unmap(widget);
}


/**
 * if you show a widget and all its parent containers, then the widget will be realized and mapped automatically.
 *
 * @todo not tested
 */
void GtkWidget_::realize()
{
    gtk_widget_realize(widget);
}

/**
 * Causes a widget to be unrealized
 *
 * @todo not tested
 */
void GtkWidget_::unrealize()
{
    gtk_widget_unrealize(widget);
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
    gtk_widget_queue_draw(widget);
}

/**
 * Flags a widget to have its size renegotiated.
 *
 * @todo not tested
 */
void GtkWidget_::queue_resize()
{
    gtk_widget_queue_resize(widget);
}

/**
 * This function works like queue_resize(), except that the widget is not invalidated.
 *
 * @todo not tested
 */
void GtkWidget_::queue_resize_no_redraw()
{
    gtk_widget_queue_resize_no_redraw(widget);
}

/**
 * Flags the widget for a rerun of the GtkWidgetClass::size_allocate function
 *
 * @todo not tested
 */
void GtkWidget_::queue_allocate()
{
    gtk_widget_queue_allocate(widget);
}

/**
 * Retrieves the internal scale factor that maps from window coordinates to the actual device pixels.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::get_scale_factor()
{
    return gtk_widget_get_scale_factor(widget);
}

/**
 * For widgets that can be activated this function activates them.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::activate()
{
    return gtk_widget_activate(widget);
}

/**
 * Determines if the widget is the focus widget within its toplevel.
 */
Php::Value GtkWidget_::is_focus()
{
   return gtk_widget_is_focus(widget);
}

/**
 * Causes widget to have the keyboard focus for the GtkWindow it's inside
 */
void GtkWidget_::grab_focus()
{
    gtk_widget_grab_focus(widget);
}

/**
 * Determines if the widget has the global input focus.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::has_focus()
{
    return gtk_widget_has_focus(widget);
}

/**
 * Causes widget to become the default widget.
 *
 * @todo not tested
 */
void GtkWidget_::grab_default()
{
    gtk_widget_set_can_default(widget, true);
    gtk_widget_grab_default(widget);
}

/**
 * Widgets can be named, which allows you to refer to them from a CSS file.
 *
 * @todo not tested
 */
void GtkWidget_::set_name(Php::Parameters &parameters)
{
    gtk_widget_set_name(widget, parameters[0]);
}

/**
 * Retrieves the name of a widget.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::get_name()
{
    return (widget);
}

/**
 * Sets the sensitivity of a widget.
 */
void GtkWidget_::set_sensitive(Php::Parameters &parameters)
{
    gtk_widget_set_sensitive(widget, parameters[0]);
}

/**
 * Gets the sensitivity of a widget.
 */
Php::Value GtkWidget_::get_sensitive()
{
    return gtk_widget_get_sensitive(widget);
}

/**
 * If widget are sensitivity, include if parent is sensitive
 */
Php::Value GtkWidget_::is_sensitive()
{
    return (bool)gtk_widget_is_sensitive(widget);
}

/**
 * Sets the sensitivity of a widget.
 *
 * @todo not tested
 */
Php::Value GtkWidget_::mnemonic_activate(Php::Parameters &parameters)
{
    return gtk_widget_mnemonic_activate(widget, parameters[0]);
}

/**
 * Returns the parent container of widget.
 *
 * @todo C++ are strong typed, so, try to create a method to convert Gtk types and return PHP Gtk types, no use if in all method
 */
Php::Value GtkWidget_::get_parent()
{
    GtkWidget *parent_widget = gtk_widget_get_parent(widget);
    std::string widget_type = gtk_widget_get_name(parent_widget);

    if(widget_type == "GtkBox")
    {
        // Create the object
        GtkBox_ *return_widget = new GtkBox_();
        return_widget->set_widget(parent_widget);

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
    gtk_widget_set_tooltip_text(widget, tooltip.c_str());
}

/**
 * Gets text as the contents of the tooltip
 */
Php::Value GtkWidget_::get_tooltip_text()
{
    // Get the tooltip text
    return gtk_widget_get_tooltip_text(widget);
}

/**
 * Returns the current value of the has-tooltip property
 */
Php::Value GtkWidget_::get_has_tooltip()
{
    // Get if has tooltip
    return gtk_widget_get_has_tooltip(widget);
}

/**
 * Returns the width that has currently been allocated to widget
 */
Php::Value GtkWidget_::get_allocated_width()
{
    return gtk_widget_get_allocated_width(widget);
}

/**
 * Returns the height that has currently been allocated to widget
 */
Php::Value GtkWidget_::get_allocated_height()
{
    return gtk_widget_get_allocated_height(widget);
}

/**
 * Sets whether the widget should grab focus when it is clicked with the mouse.
 */
void GtkWidget_::set_focus_on_click(Php::Parameters &parameters)
{
   gtk_widget_set_focus_on_click(widget, parameters[0]);
}

/**
 * Sets the visibility state of widget
 */
void GtkWidget_::set_visible(Php::Parameters &parameters)
{
    gtk_widget_set_visible(widget, parameters[0]);
}

/**
 * Gets the visibility state of widget
 */
Php::Value GtkWidget_::get_visible()
{
    return gtk_widget_get_visible(widget);
}

/**
 * Sets the opacity of widget
 */
void GtkWidget_::set_opacity(Php::Parameters &parameters)
{
    gtk_widget_set_opacity(widget, parameters[0]);
}

/**
 * Gets the opacity of widget
 */
Php::Value GtkWidget_::get_opacity()
{
    return gtk_widget_get_opacity(widget);
}

/**
 * Sets the vertical align of widget
 */
void GtkWidget_::set_valign(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GtkAlign passedAlign = (GtkAlign)a;

    gtk_widget_set_valign(widget, passedAlign);
}

/**
 * Gets the vertical align of widget
 */
Php::Value GtkWidget_::get_valign()
{
    return gtk_widget_get_valign(widget);
}

/**
 * Sets the horizontal align of widget
 */
void GtkWidget_::set_halign(Php::Parameters &parameters)
{
    // Cast GtkAlign param
    int a = parameters[0];
    GtkAlign passedAlign = (GtkAlign)a;

    gtk_widget_set_halign(widget, passedAlign);
}

/**
 * Gets the horizontal align of widget
 */
Php::Value GtkWidget_::get_halign()
{
    return gtk_widget_get_halign(widget);
}

/**
 * Sets the start margin of widget
 */
void GtkWidget_::set_margin_start(Php::Parameters &parameters)
{
    gtk_widget_set_margin_start(widget, parameters[0]);
}

/**
 * Gets the start margin of widget
 */
Php::Value GtkWidget_::get_margin_start()
{
    return gtk_widget_get_margin_start(widget);
}

/**
 * Sets the end margin of widget
 */
void GtkWidget_::set_margin_end(Php::Parameters &parameters)
{
    gtk_widget_set_margin_end(widget, parameters[0]);
}

/**
 * Gets the end margin of widget
 */
Php::Value GtkWidget_::get_margin_end()
{
    return gtk_widget_get_margin_end(widget);
}

/**
 * Sets the top margin of widget
 */
void GtkWidget_::set_margin_top(Php::Parameters &parameters)
{
    gtk_widget_set_margin_top(widget, parameters[0]);
}

/**
 * Gets the top margin of widget
 */
Php::Value GtkWidget_::get_margin_top()
{
    return gtk_widget_get_margin_top(widget);
}

/**
 * Sets the bottom margin of widget
 */
void GtkWidget_::set_margin_bottom(Php::Parameters &parameters)
{
    gtk_widget_set_margin_bottom(widget, parameters[0]);
}

/**
 * Gets the bottom margin of widget
 */
Php::Value GtkWidget_::get_margin_bottom()
{
    return gtk_widget_get_margin_bottom(widget);
}