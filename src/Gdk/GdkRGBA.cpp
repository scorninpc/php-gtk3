
#include "GdkRGBA.h"


GdkRGBA_::GdkRGBA_() = default;
GdkRGBA_::~GdkRGBA_() = default;

// 
GdkRGBA GdkRGBA_::get_instance()
{
    return instance;
}

// 
void GdkRGBA_::set_instance(GdkRGBA event)
{
    instance = event;
}

Php::Value GdkRGBA_::__get(const Php::Value &name)
{
    if (name == "red") return instance.red;
    if (name == "green") return instance.green;
    if (name == "blue") return instance.blue;
    if (name == "alpha") return instance.alpha;

    // property not supported, fall back on default
    return Php::Base::__get(name);
}


Php::Value GdkRGBA_::parse(Php::Parameters &parameters)
{
    std::string s_spec = parameters[0];
    gchar *spec = (gchar *)s_spec.c_str();

    GdkRGBA rgba;

    gboolean ret = gdk_rgba_parse(&rgba, spec);
    if(!ret) {
        return ret;
    }

    GdkRGBA_ *return_parsed = new GdkRGBA_();
    return_parsed->set_instance(rgba);
    return Php::Object("GdkRGBA", return_parsed);
}

Php::Value GdkRGBA_::to_string(Php::Parameters &parameters)
{
    char *ret = gdk_rgba_to_string(&instance);
    
    return ret;
}