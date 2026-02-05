
#include "GdkEventConfigure.h"


/**
 *  c++ constructor
 */
GdkEventConfigure_::GdkEventConfigure_()
{
    
}

/**
 *  PHP Constructor
 */
void GdkEventConfigure_::__construct(Php::Parameters& parameters)
{

}

void GdkEventConfigure_::populate(GdkEventConfigure event)
{
   // get self reference as Php::Value object
    Php::Value self(this);

    // initialize a public property
    self["type"] = (int)event.type;
    // self["window"] = (GdkWindow *)event.window;  // GdkWindow
    self["send_event"] = (int)event.send_event;
    self["x"] = (int)event.x;
    self["y"] = (int)event.y;
    self["width"] = (int)event.width;
    self["height"] = (int)event.height;

}
