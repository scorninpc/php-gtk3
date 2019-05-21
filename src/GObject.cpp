
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
    Php::Parameters parameters;


    guint signal_id;
    const gchar *signal_name;
    GType itype;
    GSignalFlags signal_flags;
    GType return_type;
    guint n_params;
    const GType *param_types;
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
    
    // Add my internal parameters
    callback_object->callback_name = callback_name;
    callback_object->callback_params = callback_params;
    callback_object->self_widget = Php::Object("GtkWidget", this);
    callback_object->parameters = parameters;
    
    
    // Retriave and store signal query parameters , to be used on callback
    GSignalQuery signal_info;
    g_signal_query(g_signal_lookup (callback_event, G_OBJECT_TYPE (instance)), &signal_info);
    
    callback_object->signal_id = signal_info.signal_id;
    callback_object->signal_name = signal_info.signal_name;
    callback_object->itype = signal_info.itype;
    callback_object->signal_flags = signal_info.signal_flags;
    callback_object->return_type = signal_info.return_type;
    callback_object->n_params = signal_info.n_params;
    callback_object->param_types = signal_info.param_types;


    // Create the CPP callback
    // int ret = g_signal_connect(instance, callback_event, G_CALLBACK (connect_callback), callback_object);

    GClosure  *closure;
    closure = g_cclosure_new_swap (G_CALLBACK (connect_callback), callback_object, NULL);
    int ret = g_signal_connect_closure (instance, callback_event, closure, TRUE);

    // Return handler id
    // return ret;
    return ret;
}

/**
 * Class to abstract php callback for connect method, to call PHP function
 */
bool GObject_::connect_callback(gpointer user_data, ...)
{
    
    // Return to st_callback
    struct st_callback *callback_object = (struct st_callback *) user_data;

    // Create internal params, GtkWidget + GdkEvent
    Php::Value internal_parameters;
    internal_parameters[0] = callback_object->self_widget;

    // Get param counter from g_signal_query, to loop casting types and store into internal_parameters
    int param_count = callback_object->n_params;
    va_list ap;
    va_start(ap, user_data);

    // Loop into param_types of GSignalQuery from g_signal_query
    for (int i=0; i<param_count; i++) {

        switch (G_TYPE_FUNDAMENTAL(callback_object->param_types[i])) {
            case G_TYPE_CHAR:
                // Php::call("var_dump", "char");
                break;
            case G_TYPE_UCHAR:
                // Php::call("var_dump", "uchar");
                break;
            case G_TYPE_STRING:
                // Php::call("var_dump", "string");

                internal_parameters[i+1] = va_arg(ap, char *);

                break;
            case G_TYPE_OBJECT:
                // Php::call("var_dump", "gobject");
                break;
            case G_TYPE_POINTER:
                // Php::call("var_dump", "gpointer");
                break;
            case G_TYPE_INTERFACE: 
                // Php::call("var_dump", "interface");
                break;
            case G_TYPE_PARAM:
                // Php::call("var_dump", "param");
                break;
            case G_TYPE_BOXED:
            {
                // Php::call("var_dump", "boxed");


                GdkEvent *e = va_arg(ap, GdkEvent *);

                // Create event from callback
                GdkEvent_ *event_ = new GdkEvent_();
                Php::Value gdkevent = Php::Object("GdkEvent", event_);
                event_->populate(e);

                internal_parameters[i+1] = gdkevent;

                break;
            }

            default:
                std::string error ("[GObject_::connect_callback] Internal error: unsupported type ");
                throw Php::Exception(error + g_type_name(callback_object->param_types[i]));
        }
        
    }

    va_end(ap);

    // Add user extra param
    int parameters_count = callback_object->parameters.size();
    for(int i=2; i<parameters_count; i++) {
        internal_parameters[internal_parameters.size()+i-1] = callback_object->parameters[i];
    }


    // Call php function with parameters
    Php::Value ret = Php::call("call_user_func_array", callback_object->callback_name, internal_parameters);


    return ret;

    // Return to st_callback
    // struct st_callback *callback_object = (struct st_callback *) user_data;


    // // Create internal params, GtkWidget + GdkEvent
    // Php::Value internal_parameters;
    // internal_parameters[0] = callback_object->self_widget;
   

    // Php::call("var_dump", G_TYPE_IS_FUNDAMENTAL(G_TYPE_FROM_CLASS(user_param)));

    //  // Verify if user_param is a GFundamentalType
    // if(G_TYPE_IS_FUNDAMENTAL(G_TYPE_FROM_CLASS(user_param))) {

    //     // Create event from callback
    //     GdkEvent_ *event_ = new GdkEvent_();
    //     Php::Value gdkevent = Php::Object("GdkEvent", event_);
    //     event_->populate((GdkEvent *) user_param);
        
    //     // Add as second parameter
    //     internal_parameters[1] = gdkevent;
    // }

    // // Merge internal parameters with custom parameters
    // // Php::Value callback_params = callback_object->callback_params;
    // // Php::Value custom_parameters = Php::call("array_slice", callback_params, 2, callback_params.size());
    // // Php::Value php_callback_param = Php::call("array_merge", internal_parameters, custom_parameters);

    // // Call php function with parameters
    // Php::Value ret = Php::call("call_user_func_array", callback_object->callback_name, internal_parameters);

    // return ret;
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