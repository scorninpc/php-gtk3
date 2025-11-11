
#include "GdkEventMotion.h"


/**
 *  c++ constructor
 */
GdkEventMotion_::GdkEventMotion_()
{
    
}

/**
 *  PHP Constructor
 */
void GdkEventMotion_::__construct(Php::Parameters& parameters)
{

}

void GdkEventMotion_::populate(GdkEventMotion event)
{
   // get self reference as Php::Value object
    Php::Value self(this);

    double *axes = (double *)event.axes;

    Php::Value arr_axes;
    if (axes != NULL) {
        arr_axes[0] = (double)axes[0];
        arr_axes[1] = (double)axes[1];
    }

    // initialize properties from GdkEventMotion
    self["type"] = (int)event.type;
    // self["window"] = (int)event.window;  // GdkWindow
    self["send_event"] = (int)event.send_event;
    self["time"] = (int)event.time;
    self["x"] = (double)event.x;
    self["y"] = (double)event.y;
    self["axes"] = arr_axes;
    self["state"] = (int)event.state;
    self["is_hint"] = (int)event.is_hint;
    // self["device"] = (int)event.device;  // GdkDevice
    self["x_root"] = (double)event.x_root;
    self["y_root"] = (double)event.y_root;
}
