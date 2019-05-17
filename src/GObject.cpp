
#include <glib.h>

#include "GObject.h"
#include "GtkWidget.h"

/**
 * Struct for callback gpointer
 */
struct GObject_::st_callback {
    int type = 29;
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
    callback_object->type = 99;

    // Create the CPP callback
    // int ret = g_signal_connect(instance, callback_event, G_CALLBACK (connect_callback), callback_object);

    GClosure  *closure;
    closure = g_cclosure_new_swap (G_CALLBACK (connect_callback), callback_object, NULL);
    g_signal_connect_closure (instance, callback_event, closure, TRUE);

    // Return handler id
    // return ret;
    return 1;
}

/**
 * Class to abstract php callback for connect method, to call PHP function
 */
bool GObject_::connect_callback(gpointer user_data, gpointer *user_param)
{
    // Return to st_callback
    struct st_callback *callback_object = (struct st_callback *) user_data;


    // Create internal params, GtkWidget + GdkEvent
    Php::Value internal_parameters;
    internal_parameters[0] = callback_object->self_widget;
   

    Php::call("var_dump", G_TYPE_IS_FUNDAMENTAL(G_TYPE_FROM_CLASS(user_param)));

     // Verify if user_param is a GFundamentalType
    if(G_TYPE_IS_FUNDAMENTAL(G_TYPE_FROM_CLASS(user_param))) {

        // Create event from callback
        GdkEvent_ *event_ = new GdkEvent_();
        Php::Value gdkevent = Php::Object("GdkEvent", event_);
        event_->populate((GdkEvent *) user_param);
        
        // Add as second parameter
        internal_parameters[1] = gdkevent;
    }

    // Merge internal parameters with custom parameters
    // Php::Value callback_params = callback_object->callback_params;
    // Php::Value custom_parameters = Php::call("array_slice", callback_params, 2, callback_params.size());
    // Php::Value php_callback_param = Php::call("array_merge", internal_parameters, custom_parameters);

    // Call php function with parameters
    Php::Value ret = Php::call("call_user_func_array", callback_object->callback_name, internal_parameters);

    return ret;
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