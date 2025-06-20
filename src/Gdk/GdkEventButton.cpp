
#include "GdkEventButton.h"


/**
 *  c++ constructor
 */
GdkEventButton_::GdkEventButton_()
{
    
}

/**
 *  PHP Constructor
 */
void GdkEventButton_::__construct(Php::Parameters& parameters)
{

}

void GdkEventButton_::populate(GdkEventButton event)
{
   // get self reference as Php::Value object
    Php::Value self(this);

    double *axes = (double *)event.axes;

    Php::Value arr_axes;
	arr_axes[0] = (double)axes[0];
	arr_axes[0] = (double)axes[1   ];


    // initialize a public property
    self["type"] = (int)event.type;
    // self["window"] = (int)event.window;  // GdkWindow
    self["send_event"] = (int)event.send_event;
    self["time"] = (int)event.time;
    self["x"] = (int)event.x;
    self["y"] = (int)event.y;
    self["axes"] = arr_axes;
    self["state"] = (int)event.state;
    self["button"] = (int)event.button;
    // self["device"] = (int)event.device;  // GdkDevice
    self["x_root"] = (double)event.x_root;
    self["y_root"] = (double)event.y_root;

}