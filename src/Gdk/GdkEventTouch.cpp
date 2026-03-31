
#include "GdkEventTouch.h"

/**
 *  c++ constructor
 */
GdkEventTouch_::GdkEventTouch_() = default;

/**
 *  PHP Constructor
 */
void GdkEventTouch_::__construct(Php::Parameters &parameters) {}

void GdkEventTouch_::populate(GdkEventTouch event) {
  // get self reference as Php::Value object
  Php::Value self(this);

  double *axes = (double *)event.axes;

  Php::Value arr_axes;
  if (axes != nullptr) {
    arr_axes[0] = (double)axes[0];
    arr_axes[1] = (double)axes[1];
  }

  // initialize properties from GdkEventTouch
  self["type"] = (int)event.type;
  // self["window"] = (int)event.window;  // GdkWindow
  self["send_event"] = (int)event.send_event;
  self["time"] = static_cast<int64_t>(event.time);
  self["x"] = (double)event.x;
  self["y"] = (double)event.y;
  self["axes"] = arr_axes;
  self["state"] = (int)event.state;
  // self["sequence"] = event.sequence;  // GdkEventSequence - pointer to touch
  // sequence
  self["emulating_pointer"] = (bool)event.emulating_pointer;
  // self["device"] = (int)event.device;  // GdkDevice
  self["x_root"] = (double)event.x_root;
  self["y_root"] = (double)event.y_root;
}
