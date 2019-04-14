#include <phpcpp.h>
#include <iostream>

#include <gtk/gtk.h>

/**
 * @todo Add all properties
 */
class GdkEvent_ : public Php::Base
{

public:

    int type;

    /**
     *  c++ constructor
     */
    GdkEvent_() = default;

    /**
     *  c++ destructor
     */
    virtual ~GdkEvent_() = default;

    /**
     *  php "constructor"
     *  @param  params
     */
    void __construct()
    {
       // get self reference as Php::Value object
        // Php::Value self(this);

        // initialize a public property
        // self["type"] = 0;
    }

};