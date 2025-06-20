
#include "GdkEventKey.h"


/**
 *  c++ constructor
 */
GdkEventKey_::GdkEventKey_()
{
    
}

/**
 *  PHP Constructor
 */
void GdkEventKey_::__construct(Php::Parameters& parameters)
{

}

void GdkEventKey_::populate(GdkEventKey event)
{
    // Php::call("var_dump", "OK");

    // get self reference as Php::Value object
    Php::Value self(this);
    // initialize a public property
    self["type"] = (int)event.type;
    // self["window"] = (int)event.window;  // GdkWindow
    self["send_event"] = (int)event.send_event;
    self["time"] = (int)event.time;
    self["state"] = (int)event.state;
    self["keyval"] = (int)event.keyval;
    self["length"] = (int)event.length;

    if(event.string != NULL) {
        const gchar *event_string = event.string;
        self["string"] = (char *)&event_string;
    }

    self["hardware_keycode"] = (int)event.hardware_keycode;
    self["keycode"] = (int)event.hardware_keycode;
    self["group"] = (int)event.group;
    self["is_modifier"] = (int)event.is_modifier;
    


}