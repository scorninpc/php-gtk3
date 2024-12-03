
#include "Gtk.h"

// https://developer.gnome.org/gtk3/stable/gtkbase.html

/**
 * Struct for callback gpointer
 */
struct Gtk_::st_timeout_add {
    Php::Value callback_name;
    Php::Array callback_params;
};

/**
 *  
 */
Gtk_::Gtk_() = default;


/**
 *
 */
void Gtk_::main()
{
	gtk_main();
}

/**
 *
 */
void Gtk_::main_quit()
{
	gtk_main_quit();
}


Php::Value Gtk_::timeout_add(Php::Parameters &parameters)
{
    guint interval = (int)parameters[0];
    
    // Exclude the first two parameters: They are interval and function name
    Php::Array callback_params;
    for (size_t i = 2; i < parameters.size(); i++) {
        callback_params[i - 2] = parameters[i];
    }

    // Create gpointer user data
    struct st_timeout_add *callback_object = (struct st_timeout_add *)malloc(sizeof(struct st_timeout_add));
    memset(callback_object, 0, sizeof(struct st_timeout_add));

    // Add my internal parameters
    callback_object->callback_name = parameters[1];
    callback_object->callback_params = callback_params;

    // Call
    gint ret = g_timeout_add(interval, timeout_add_callback, callback_object);
    return ret;
}

gint Gtk_::timeout_add_callback(gpointer data)
{
    // Return to st_timeout_add
    struct st_timeout_add *callback_object = (struct st_timeout_add *) data;

    // Use the prepared callback_params directly
    Php::Array internal_parameters = callback_object->callback_params;

    // Call php function with parameters
    Php::Value ret = Php::call("call_user_func_array", callback_object->callback_name, internal_parameters);

    // verify return type
    if(ret.type() != Php::Type::False) {
        ret = Php::Type::True;
    }

    return ret;
}

Php::Value Gtk_::source_remove(Php::Parameters &parameters)
{
    guint tag = (int)parameters[0];
    
    bool ret = g_source_remove(tag);
    
    return ret;
}

/**
 * https://docs.gtk.org/gtk3/func.show_uri_on_window.html
 */
Php::Value Gtk_::show_uri_on_window(Php::Parameters &parameters)
{
    // Init parent object
    Php::Value object_parent = parameters[0];
    GtkWindow *parent = NULL;

    if (object_parent.instanceOf("GtkWindow")) {
        GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
        parent = GTK_WINDOW(phpgtk_parent->get_instance());
    }

    // Init URI
    std::string s_uri = parameters[1];
    char* uri = (char*)s_uri.c_str();

    // @TODO
    guint32 timestamp;
    GError** error;
    
    gboolean ret = gtk_show_uri_on_window(parent, uri, timestamp, error);

    return ret;
}

Php::Value Gtk_::events_pending()
{
	return gtk_events_pending();
}

Php::Value Gtk_::main_do_event(Php::Parameters& parameters)
{
    if (parameters.size() == 0) {
        throw Php::Exception("Gtk::main_do_event requires a GdkEvent as a parameter.");
    }

    // Ensure the parameter is an object
    if (!parameters[0].isObject()) {
        throw Php::Exception("Expected a GdkEvent object as the first parameter.");
    }

    Php::Value object_event = parameters[0];

    // Validate and cast to GdkEvent_
    GdkEvent_* phpgtk_event = dynamic_cast<GdkEvent_*>(object_event.implementation());
    if (!phpgtk_event) {
        throw Php::Exception("Invalid GdkEvent object.");
    }

    // Retrieve the native GdkEvent instance
    GdkEvent* event = phpgtk_event->get_instance();
    if (!event) {
        throw Php::Exception("GdkEvent instance is null.");
    }

    // Call gtk_main_do_event
    gtk_main_do_event(event);

    return nullptr;
}

Php::Value Gtk_::main_iteration()
{
	return gtk_main_iteration();
}

/**
 * https://docs.gtk.org/gtk3/func.get_major_version.html
 */
Php::Value Gtk_::get_major_version()
{
    guint ret = gtk_get_major_version();

    return (int) ret;
}

/**
 * https://docs.gtk.org/gtk3/func.get_micro_version.html
 */
Php::Value Gtk_::get_micro_version()
{
    guint ret = gtk_get_micro_version();

    return (int) ret;
}

/**
 * https://docs.gtk.org/gtk3/func.get_minor_version.html
 */
Php::Value Gtk_::get_minor_version()
{
    guint ret = gtk_get_minor_version();

    return (int) ret;
}

void Gtk_::init()
{
    gtk_init(0, NULL);
}
