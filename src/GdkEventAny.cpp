#include <phpcpp.h>
#include <iostream>

#include <gtk/gtk.h>

/**
 * @todo Add all properties
 *
 * https://developer.gnome.org/gdk3/stable/gdk3-Event-Structures.html
 */
class GdkEventAny_ : public Php::Base
{

public:

    /**
     *  c++ constructor
     */
    GdkEventAny_() = default;

    /**
     *  c++ destructor
     */
    virtual ~GdkEventAny_() = default;
};