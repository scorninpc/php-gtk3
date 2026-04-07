
#ifndef _PHPGTK_GDKEVENTTOUCH_H_
#define _PHPGTK_GDKEVENTTOUCH_H_

#include <phpcpp.h>
#include <gtk/gtk.h>

/**
 * GdkEventTouch - Touch event wrapper
 * Handles touch begin, update, end, and cancel events
 */
class GdkEventTouch_ : public Php::Base {
  /**
   * Publics
   */
 public:
  /**
   *  C++ constructor and destructor
   */
  GdkEventTouch_();

  /**
   * PHP Construct
   */
  void __construct(Php::Parameters &parameters);

  /**
   * Populate GdkEventTouch to PHPGTK::GdkEventTouch
   */
  void populate(GdkEventTouch event);
};

#endif
