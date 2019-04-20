
#include "GtkWidget.h"

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
 * Obtains the frame clock for a widget
 *
 * @todo not implemented, needs GdkFrameClock
 */
void GtkWidget_::get_frame_clock()
{
    throw Php::Exception("GtkWidget->queue_allocate() not implemented yet");
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
 * Callback type for adding a function to update animations
 *
 * @todo not implemented, needs GdkFrameClock
 */
Php::Value GtkWidget_::GtkTickCallback()
{
    throw Php::Exception("GtkWidget->GtkTickCallback() not implemented yet");
}

/**
 * Queues an animation frame update and adds a callback to be called before each frame.
 *
 * @todo not implemented, needs GtkTickCallback
 */
Php::Value GtkWidget_::add_tick_callback()
{
    throw Php::Exception("GtkWidget->add_tick_callback() not implemented yet");
}

/**
 * Removes a tick callback previously registered with add_tick_callback()
 *
 * @todo not implemented, needs GtkTickCallback
 */
void GtkWidget_::remove_tick_callback()
{
    throw Php::Exception("GtkWidget->gtk_widget_remove_tick_callback() not implemented yet");
}

/**
 *  Obtains the preferred size of a widget. 
 */
void GtkWidget_::size_request()
{
    throw Php::Exception("size_request() is not implemented. Use set_size_request and get_size_request");
}