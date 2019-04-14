#include <phpcpp.h>

/**
 * @todo Add all properties
 */
class GdkEvent_ : public Php::Base
{
public:
    void GdkEvent_()
    {
        // get self reference as Php::Value object
        Php::Value self(this);

        // initialize a public property
        self["type"] = "s";
    }
};