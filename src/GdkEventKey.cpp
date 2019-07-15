
#include "GdkEventKey.h"


/**
 *  c++ constructor
 */
GdkEventKey_::GdkEventKey_()
{
    
}


void GdkEventKey_::populate(GdkEventKey event)
{
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
    self["string"] = event.string;
    self["hardware_keycode"] = (int)event.hardware_keycode;
    self["keycode"] = (int)event.hardware_keycode;
    self["group"] = (int)event.group;
    self["is_modifier"] = (int)event.is_modifier;
    


}