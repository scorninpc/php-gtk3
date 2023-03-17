
#ifndef _PHPGTK_GdkTHREADS_H_
#define _PHPGTK_GdkTHREADS_H_

#include <phpcpp.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

/**
 *
 */
class GdkThreads_ : public Php::Base
{
    /**
     * Publics
     */
public:

    /**
     *  C++ constructor and destructor
     */
    GdkThreads_() = default;

    void add_idle(Php::Parameters &parameters);
};

#endif