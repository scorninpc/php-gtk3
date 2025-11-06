
#include "GdkEventFocus.h"


/**
 *  c++ constructor
 */
GdkEventFocus_::GdkEventFocus_()
{
    
}

/**
 *  PHP Constructor
 */
void GdkEventFocus_::__construct(Php::Parameters& parameters)
{

}

void GdkEventFocus_::populate(GdkEventFocus event)
{
   // get self reference as Php::Value object
    Php::Value self(this);

    // initialize a public property
    self["type"] = (int)event.type;
    // self["window"] = (int)event.window;  // GdkWindow
    self["send_event"] = (int)event.send_event;
    self["in"] = (int)event.in;

}
