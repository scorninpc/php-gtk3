
#include "GdkEvent.h"


//
GdkEvent *GdkEvent_::get_instance()
{
    return instance;
}

//
void GdkEvent_::set_instance(GdkEvent *event)
{
    instance = event;
}


void GdkEvent_::populate(GdkEvent *event)
{
    instance = event;

   // get self reference as Php::Value object
    Php::Value self(this);

    /**

    https://developer.gnome.org/gdk3/stable/gdk3-Events.html#gdk-event-get-event-type
    https://developer.gnome.org/gtk-tutorial/stable/a2767.html

    union _GdkEvent
    {
      GdkEventType              type;
      GdkEventAny               any;
      GdkEventExpose            expose;
      GdkEventNoExpose          no_expose;
      GdkEventVisibility        visibility;
      GdkEventMotion            motion;
      GdkEventButton            button;
      GdkEventKey               key;
      GdkEventCrossing          crossing;
      GdkEventFocus             focus_change;
      GdkEventConfigure         configure;
      GdkEventProperty          property;
      GdkEventSelection         selection;
      GdkEventProximity         proximity;
      GdkEventClient            client;
      GdkEventDND               dnd;
    };

    */

}
