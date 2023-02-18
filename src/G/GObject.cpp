
#include <glib.h>

#include "GObject.h"
#include "../Gtk/GtkWidget.h"

#include "../../main.h"

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


void GObject_::__clone()
{
    std::string gtype_name = g_type_name(G_TYPE_FROM_INSTANCE(instance));

    char *buffer;
    int len;

    // Get len of string
    len = snprintf(NULL, 0, "Trying to clone an uncloneable object of class %s", gtype_name.c_str());
    buffer = (char *)malloc((len + 1) * sizeof(char));
    
    // Save into buffer
    snprintf(buffer, len+1, "Trying to clone an uncloneable object of class %s", gtype_name.c_str());

    throw Php::Exception("asdasdasd");
}

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
 * https://developer.gnome.org/gobject/stable/gobject-Signals.html#g-signal-connect-after
 */
Php::Value GObject_::connect_after(Php::Parameters &parameters)
{
    return GObject_::connect_internal(parameters, TRUE);
}

/**
 * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
 *
 * @todo Verify if callback are callable with Php::Callable::Callable
 * @todo Some events like the delete-event, dont pass gpointer param correctly
 */
Php::Value GObject_::connect(Php::Parameters &parameters)
{
    return GObject_::connect_internal(parameters, FALSE);
}

/**
 * https://developer.gnome.org/gobject/unstable/gobject-Signals.html#g-signal-connect
 *
 * @todo Verify if callback are callable with Php::Callable::Callable
 * @todo Some events like the delete-event, dont pass gpointer param correctly
 */
Php::Value GObject_::connect_internal(Php::Parameters &parameters, bool after)
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

    if(G_IS_OBJECT(instance)) {
        g_signal_query(g_signal_lookup (callback_event, G_OBJECT_TYPE (instance)), &signal_info);
    }

    if(G_IS_OBJECT_CLASS(instance)) {
        g_signal_query(g_signal_lookup (callback_event, G_OBJECT_CLASS_TYPE (instance)), &signal_info);
    }

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
    int ret = g_signal_connect_closure (instance, callback_event, closure, after);

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

        // Php::call("var_dump", g_type_name(callback_object->param_types[i]));

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

            case G_TYPE_BOOLEAN:
            // Php::call("var_dump", "boolean");
                internal_parameters[i+1] = va_arg(ap, gboolean);
                break;

            case G_TYPE_INT:
                // Php::call("var_dump", "int");
                internal_parameters[i+1] = va_arg(ap, gint);
                break;

            case G_TYPE_UINT:
                // Php::call("var_dump", "int");
                internal_parameters[i+1] = (int)va_arg(ap, guint);
                break;
                
            case G_TYPE_OBJECT:
            {
                // Php::call("var_dump", "object");
                gpointer *e = va_arg(ap, gpointer *);

                // Create event from callback
                GObject_ *event_ = new GObject_();
                event_->set_instance(e);
                Php::Value gobject_ = Php::Object(g_type_name(callback_object->param_types[i]), event_);
                internal_parameters[i+1] = gobject_;
                
                break;
            }
            case G_TYPE_POINTER:
                // Php::call("var_dump", "pointer");
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


Php::Value  GObject_::is_connected(Php::Parameters& parameters)
{
    Php::Value callback_handle = parameters[0];

    gboolean ret = g_signal_handler_is_connected(instance, (int)callback_handle);

    return ret;
}


Php::Value GObject_::get_property(Php::Parameters &parameters)
{
    std::string s_property_name = parameters[0];
    gchar *property_name = (gchar *)s_property_name.c_str();

    GValue gvalue = {0};
    g_value_init(&gvalue, G_TYPE_OBJECT);

    g_object_get_property (G_OBJECT(instance), property_name, &gvalue);

    return phpgtk_get_phpvalue(&gvalue);

}

void GObject_::set_property(Php::Parameters &parameters)
{
    std::string s_property_name = parameters[0];
    gchar *property_name = (gchar *)s_property_name.c_str();

    // get interface of instance
    gpointer iface = g_type_default_interface_peek (G_OBJECT_TYPE(instance));
    
    // get the property spec
    GParamSpec* prop = g_object_class_find_property(G_OBJECT_GET_CLASS(instance), "editable");

    // parse the param by the gtype
    GValue value = phpgtk_get_gvalue(parameters[1], G_TYPE_FUNDAMENTAL(prop->value_type));
    
    // set property
    g_object_set_property(G_OBJECT(instance), property_name, &value);
}

void GObject_::signal_handler_block(Php::Parameters &parameters)
{
    double p_handler_id = parameters[0];
    gulong handler_id = (gulong) p_handler_id;

    g_signal_handler_block(G_OBJECT(instance), handler_id);
}

void GObject_::signal_handler_unblock(Php::Parameters &parameters)
{
    double p_handler_id = parameters[0];
    gulong handler_id = (gulong) p_handler_id;

    g_signal_handler_unblock(G_OBJECT(instance), handler_id);
}