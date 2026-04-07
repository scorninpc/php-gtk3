
#include "Gdk.h"
#include "../../php-gtk.h"
#include "GdkEvent.h"

/**
 *
 */
Gdk_::Gdk_() = default;
Gdk_::~Gdk_() = default;

/**
 * https://developer.gnome.org/gdk3/stable/gdk3-Testing.html#gdk-test-simulate-button
 */
Php::Value Gdk_::test_simulate_button(Php::Parameters &parameters) {
  bool check;

  // ---
  phpgtk_check_parameter(parameters, 1, Php::Type::Object, TRUE, "GdkWindow");
  GdkWindow *window;
  if (parameters.size() > 0) {
    Php::Value object_window = parameters[0];
    GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
    window = GDK_WINDOW(phpgtk_window->get_instance());
  }

  // ---
  check = phpgtk_check_parameter(parameters, 2, Php::Type::Numeric, FALSE, NULL);
  gint x = 0;
  if (check) {
    x = (int)parameters[1];
  }

  // ---
  check = phpgtk_check_parameter(parameters, 3, Php::Type::Numeric, FALSE, NULL);
  gint y = 0;
  if (check) {
    y = (int)parameters[2];
  }

  // ---
  check = phpgtk_check_parameter(parameters, 4, Php::Type::Numeric, FALSE, NULL);
  gint button = 0;
  if (check) {
    button = (int)parameters[3];
  }

  // ---
  check = phpgtk_check_parameter(parameters, 5, Php::Type::Numeric, FALSE, NULL);
  GdkModifierType modifiers = GDK_BUTTON1_MASK;
  if (check) {
    int phpgtk_modifiers = (int)parameters[4];
    modifiers = (GdkModifierType)phpgtk_modifiers;
  }

  // ---
  check = phpgtk_check_parameter(parameters, 6, Php::Type::Numeric, FALSE, NULL);
  GdkEventType button_pressrelease = GDK_BUTTON_PRESS;
  if (check) {
    int phpgtk_button_pressrelease = (int)parameters[4];
    button_pressrelease = (GdkEventType)phpgtk_button_pressrelease;
  }

  // Move the cursor
  GdkDevice *device = gdk_device_manager_get_client_pointer(
      gdk_display_get_device_manager(gdk_display_get_default()));
  GdkScreen *screen = gdk_screen_get_default();
  gdk_device_warp(device, screen, x, y);

  //
  gdk_test_simulate_button(window, x, y, button, modifiers, button_pressrelease);

  return 1;
}

/**
 * Sets the given pixbuf as the source pattern for cr.
 *
 * https://developer.gnome.org/gdk3/stable/gdk3-Cairo-Interaction.html#gdk-cairo-set-source-pixbuf
 */
void Gdk_::cairo_set_source_pixbuf(Php::Parameters &parameters) {
  // Parameter 1: cairo_t* - passed as GdkEvent object from draw signal
  // Note: Cairo context is a G_TYPE_BOXED that gets wrapped as GdkEvent by GObject callback,
  // even though it's actually a cairo_t*. We extract the raw pointer from GdkEvent::instance.
  if (parameters.size() < 1) {
    throw Php::Exception("cairo_set_source_pixbuf: Missing cairo_context parameter");
  }
  if (parameters[0].type() != Php::Type::Object) {
    throw Php::Exception("cairo_set_source_pixbuf: cairo_context must be a GdkEvent object");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception("cairo_set_source_pixbuf: cairo_context must be a GdkEvent object");
  }
  Php::Value object_event = parameters[0];
  GdkEvent_ *phpgtk_event = (GdkEvent_ *)object_event.implementation();

  // The instance pointer is actually cairo_t*, not GdkEvent*
  // We need to get it before any GdkEvent-specific operations are performed
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("cairo_set_source_pixbuf: Invalid cairo context (null pointer)");
  }

  // Parameter 2: GdkPixbuf object
  if (parameters.size() < 2) {
    throw Php::Exception("cairo_set_source_pixbuf: Missing pixbuf parameter");
  }
  if (parameters[1].type() != Php::Type::Object) {
    throw Php::Exception("cairo_set_source_pixbuf: pixbuf must be a GdkPixbuf object");
  }
  if (!parameters[1].instanceOf("GdkPixbuf")) {
    throw Php::Exception("cairo_set_source_pixbuf: pixbuf must be a GdkPixbuf object");
  }
  Php::Value object_pixbuf = parameters[1];
  GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
  GdkPixbuf *pixbuf = phpgtk_pixbuf->get_instance();

  if (pixbuf == nullptr) {
    throw Php::Exception("cairo_set_source_pixbuf: Invalid pixbuf (null pointer)");
  }

  // Parameter 3: pixbuf_x (double)
  // Accept both int and float since the underlying API uses gdouble
  if (parameters.size() < 3) {
    throw Php::Exception("cairo_set_source_pixbuf: Missing pixbuf_x parameter");
  }
  Php::Value pixbuf_x_val = parameters[2];
  Php::Type pixbuf_x_type = pixbuf_x_val.type();
  if (pixbuf_x_type != Php::Type::Numeric && pixbuf_x_type != Php::Type::Float) {
    throw Php::Exception("cairo_set_source_pixbuf: pixbuf_x must be int or float");
  }
  gdouble pixbuf_x = (gdouble)parameters[2].floatValue();

  // Parameter 4: pixbuf_y (double)
  // Accept both int and float since the underlying API uses gdouble
  if (parameters.size() < 4) {
    throw Php::Exception("cairo_set_source_pixbuf: Missing pixbuf_y parameter");
  }
  Php::Value pixbuf_y_val = parameters[3];
  Php::Type pixbuf_y_type = pixbuf_y_val.type();
  if (pixbuf_y_type != Php::Type::Numeric && pixbuf_y_type != Php::Type::Float) {
    throw Php::Exception("cairo_set_source_pixbuf: pixbuf_y must be int or float");
  }
  gdouble pixbuf_y = (gdouble)parameters[3].floatValue();

  // Call the GDK function
  gdk_cairo_set_source_pixbuf(cr, pixbuf, pixbuf_x, pixbuf_y);
}

/**
 * Paints the current source everywhere within the current clip region.
 *
 * https://www.cairographics.org/manual/cairo-cairo-t.html#cairo-paint
 */
void Gdk_::cairo_paint(Php::Parameters &parameters) {
  // Parameter 1: cairo_t* - passed as GdkEvent object from draw signal
  // Note: Cairo context is a G_TYPE_BOXED that gets wrapped as GdkEvent by GObject callback,
  // even though it's actually a cairo_t*. We extract the raw pointer from GdkEvent::instance.
  if (parameters.size() < 1) {
    throw Php::Exception("cairo_paint: Missing cairo_context parameter");
  }
  if (parameters[0].type() != Php::Type::Object) {
    throw Php::Exception("cairo_paint: cairo_context must be a GdkEvent object");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception("cairo_paint: cairo_context must be a GdkEvent object");
  }
  Php::Value object_event = parameters[0];
  GdkEvent_ *phpgtk_event = (GdkEvent_ *)object_event.implementation();

  // The instance pointer is actually cairo_t*, not GdkEvent*
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("cairo_paint: Invalid cairo context (null pointer)");
  }

  // Call the Cairo function (use :: to call global C function, not the class method)
  ::cairo_paint(cr);
}