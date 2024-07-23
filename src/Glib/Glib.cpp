
#include "Glib.h"

Glib_::Glib_() = default;
Glib_::~Glib_() = default;

Php::Value Glib_::markup_escape_text(Php::Parameters &parameters)
{
    std::string s_text = parameters[0];
    const gchar *text = (const gchar *)s_text.c_str();

    gssize length = (gssize) parameters[1];

    return g_markup_escape_text(text, length);
}