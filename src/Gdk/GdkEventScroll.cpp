
#include "GdkEventScroll.h"


/**
 *  c++ constructor
 */
GdkEventScroll_::GdkEventScroll_()
{
    
}

/**
 *  PHP Constructor
 */
void GdkEventScroll_::__construct(Php::Parameters& parameters)
{

}

void GdkEventScroll_::populate(GdkEventScroll event)
{
   // get self reference as Php::Value object
    Php::Value self(this);

    // initialize properties from GdkEventScroll
    self["type"] = (int)event.type;
    // self["window"] = (int)event.window;  // GdkWindow
    self["send_event"] = (int)event.send_event;
    self["time"] = (int)event.time;
    self["x"] = (double)event.x;
    self["y"] = (double)event.y;
    self["state"] = (int)event.state;
    self["direction"] = (int)event.direction;
    // self["device"] = (int)event.device;  // GdkDevice
    self["x_root"] = (double)event.x_root;
    self["y_root"] = (double)event.y_root;
    self["delta_x"] = (double)event.delta_x;
    self["delta_y"] = (double)event.delta_y;
}
