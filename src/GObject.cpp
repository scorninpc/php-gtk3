
#include <glib.h>

#include "GObject.h"
#include "GtkWidget.h"

/**
 * Struct for callback gpointer
 */
struct GObject_::st_callback {
    Php::Value callback_name;
    Php::Array callback_params;
    Php::Object self_widget;
};

/**
 *  
 */
GObject_::GObject_() = default;
GObject_::~GObject_() = default;

/**
 * Return original instance
 */
gpointer *GObject_::get_instance()
{
    return instance;
}

/**
 * Set the original gpointer
 */
void GObject_::set_instance(gpointer *pased_instance)
{
    instance = pased_instance;
}
/**
 * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
 *
 * @todo Verify if callback are callable with Php::Callable::Callable
 * @todo Some events like the delete-event, dont pass gpointer param correctly
 */
Php::Value GObject_::connect(Php::Parameters &parameters)
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
    int ret = g_signal_connect(instance, callback_event, G_CALLBACK (&connect_callback), callback_object);

    // Return handler id
    return ret;
}

/**
 * Class to abstract php callback for connect method, to call PHP function
 */
void GObject_::connect_callback(GtkWidget * widget, GdkEvent user_event, gpointer user_data)
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
void GObject_::handler_disconnect(Php::Parameters &parameters)
{
    Php::Value callback_handle = parameters[0];

    g_signal_handler_disconnect(instance, (int)callback_handle);
}