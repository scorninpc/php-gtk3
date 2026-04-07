
#ifndef _PHPGTK_GTKACCESLGROUP_H_
#define _PHPGTK_GTKACCESLGROUP_H_

#include <phpcpp.h>
#include <gtk/gtk.h>

#include "../G/GObject.h"

/**
 * GtkAccelGroup_
 *
 * https://docs.gtk.org/gtk3/class.AccelGroup.html
 */
class GtkAccelGroup_ : public GObject_ {
  /**
   * Publics
   */
 public:
  /**
   *  C++ constructor and destructor
   */
  GtkAccelGroup_();
  ~GtkAccelGroup_();

  /**
   * PHP Construct
   */
  void __construct();
};

#endif