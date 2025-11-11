
#include "GdkEvent.h"


// 
GdkEvent *GdkEvent_::get_instance()
{
    return instance;
}

/**
 *  PHP Constructor
 */
void GdkEvent_::__construct(Php::Parameters& parameters)
{

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

    // GdkEventType
    self["type"] = event->type;
    
    // Only populate the relevant event structure based on event type
    // to avoid accessing invalid union members
    
    // GtkEventButton - for button press/release events
    if (event->type == GDK_BUTTON_PRESS || event->type == GDK_BUTTON_RELEASE ||
        event->type == GDK_2BUTTON_PRESS || event->type == GDK_3BUTTON_PRESS ||
        event->type == GDK_PAD_BUTTON_PRESS || event->type == GDK_PAD_BUTTON_RELEASE) {
        GdkEventButton_ *eventbutton_ = new GdkEventButton_();
        Php::Value gdkeventbutton = Php::Object("GdkEventButton", eventbutton_);
        eventbutton_->populate(event->button);
        self["button"] = eventbutton_;
    }

    // GtkEventKey - for key press/release events
    if (event->type == GDK_KEY_PRESS || event->type == GDK_KEY_RELEASE) {
        GdkEventKey_ *eventkey_ = new GdkEventKey_();
        Php::Value gdkeventkey = Php::Object("GdkEventKey", eventkey_);
        eventkey_->populate(event->key);
        self["key"] = eventkey_;
    }

    // GtkEventFocus - for focus change events
    if (event->type == GDK_FOCUS_CHANGE) {
        GdkEventFocus_ *eventfocus_ = new GdkEventFocus_();
        Php::Value gdkeventfocus = Php::Object("GdkEventFocus", eventfocus_);
        eventfocus_->populate(event->focus_change);
        self["focus_change"] = eventfocus_;
    }

    // GdkEventScroll - for scroll events
    if (event->type == GDK_SCROLL) {
        GdkEventScroll_ *eventscroll_ = new GdkEventScroll_();
        Php::Value gdkeventscroll = Php::Object("GdkEventScroll", eventscroll_);
        eventscroll_->populate(event->scroll);
        self["scroll"] = eventscroll_;
    }

    // GdkEventMotion - for motion notify events
    if (event->type == GDK_MOTION_NOTIFY) {
        GdkEventMotion_ *eventmotion_ = new GdkEventMotion_();
        Php::Value gdkeventmotion = Php::Object("GdkEventMotion", eventmotion_);
        eventmotion_->populate(event->motion);
        self["motion"] = eventmotion_;
    }

    // GdkEventCrossing - for enter/leave notify events
    if (event->type == GDK_ENTER_NOTIFY || event->type == GDK_LEAVE_NOTIFY) {
        GdkEventCrossing_ *eventcrossing_ = new GdkEventCrossing_();
        Php::Value gdkeventcrossing = Php::Object("GdkEventCrossing", eventcrossing_);
        eventcrossing_->populate(event->crossing);
        self["crossing"] = eventcrossing_;
    }


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
