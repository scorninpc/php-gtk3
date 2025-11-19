
#include "GdkEventCrossing.h"


/**
 *  c++ constructor
 */
GdkEventCrossing_::GdkEventCrossing_()
{
    
}

/**
 *  PHP Constructor
 */
void GdkEventCrossing_::__construct(Php::Parameters& parameters)
{

}

void GdkEventCrossing_::populate(GdkEventCrossing event)
{
   // get self reference as Php::Value object
    Php::Value self(this);

    // initialize properties from GdkEventCrossing
    self["type"] = (int)event.type;
    // self["window"] = (int)event.window;  // GdkWindow
    self["send_event"] = (int)event.send_event;
    // self["subwindow"] = (int)event.subwindow;  // GdkWindow
    self["time"] = (int)event.time;
    self["x"] = (double)event.x;
    self["y"] = (double)event.y;
    self["x_root"] = (double)event.x_root;
    self["y_root"] = (double)event.y_root;
    self["mode"] = (int)event.mode;
    self["detail"] = (int)event.detail;
    self["focus"] = (bool)event.focus;
    self["state"] = (int)event.state;
}
