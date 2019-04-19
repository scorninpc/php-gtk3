
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

    // Php::out << "-- GtkWidget::connect 1" << std::endl;
    // Php::call("var_dump", callback_object->callback_name);
    // Php::call("var_dump", callback_object->callback_params);
    // Php::call("var_dump", callback_object->self_widget);

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

    // Php::out << "-- GtkWidget::connect_callback 1" << std::endl;
    // Php::call("var_dump", callback_object->callback_name);
    // Php::call("var_dump", callback_object->callback_params);
    // Php::call("var_dump", callback_object->self_widget);

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



void GtkWidget_::test1()
{
    Php::out << "-- GtkWidget_::test 1" << std::endl;
}