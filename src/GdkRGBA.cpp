
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