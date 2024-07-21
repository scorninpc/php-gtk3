
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
    
    gboolean ret = g_source_remove(tag);
    
    return ret;
}


Php::Value Gtk_::events_pending()
{
	return gtk_events_pending();
}

Php::Value Gtk_::main_iteration()
{
	return gtk_main_iteration();
}

void Gtk_::init()
{
    gtk_init(0, NULL);
}
