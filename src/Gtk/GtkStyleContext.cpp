
#include "GtkStyleContext.h"
#include "../Gdk/GdkEvent.h"
#include "../Gdk/GdkPixbuf.h"
#include "../Gdk/GdkWindow.h"
#include "../Gdk/GdkRGBA.h"
#include "GtkWidgetPath.h"

/**
 * Constructor
 */
GtkStyleContext_::GtkStyleContext_() = default;

/**
 * Destructor
 */
GtkStyleContext_::~GtkStyleContext_() = default;

void GtkStyleContext_::__construct() {
  instance = (gpointer *)gtk_style_context_new();
}

void GtkStyleContext_::add_provider(Php::Parameters &parameters) {
  GtkCssProvider *provider;
  if (parameters.size() > 0) {
    Php::Value object_provider = parameters[0];
    GtkCssProvider_ *phpgtk_provider = (GtkCssProvider_ *)object_provider.implementation();
    provider = GTK_CSS_PROVIDER(phpgtk_provider->get_instance());
  }

  guint priority = (int)parameters[1];

  gtk_style_context_add_provider(GTK_STYLE_CONTEXT(instance), GTK_STYLE_PROVIDER(provider),
                                 priority);
}

void GtkStyleContext_::add_provider_for_screen(Php::Parameters &parameters) {
  GtkCssProvider *provider;
  if (parameters.size() > 0) {
    Php::Value object_provider = parameters[0];
    GtkCssProvider_ *phpgtk_provider = (GtkCssProvider_ *)object_provider.implementation();
    provider = GTK_CSS_PROVIDER(phpgtk_provider->get_instance());
  }

  guint priority = (int)parameters[1];

  GdkScreen *screen = gdk_screen_get_default();

  gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);
}

void GtkStyleContext_::get(Php::Parameters &parameters) {
  throw Php::Exception("GtkStyleContext_::get not implemented - variadic function not supported");
}

Php::Value GtkStyleContext_::get_direction() {
  GtkTextDirection ret = gtk_style_context_get_direction(GTK_STYLE_CONTEXT(instance));

  return ret;
}

Php::Value GtkStyleContext_::get_junction_sides() {
  GtkJunctionSides ret = gtk_style_context_get_junction_sides(GTK_STYLE_CONTEXT(instance));

  return ret;
}

Php::Value GtkStyleContext_::get_parent() {
  GtkStyleContext *ret = gtk_style_context_get_parent(GTK_STYLE_CONTEXT(instance));

  if (ret == nullptr) {
    return nullptr;
  }

  GtkStyleContext_ *return_parsed = new GtkStyleContext_();
  return_parsed->set_instance((gpointer *)ret);
  return Php::Object("GtkStyleContext", return_parsed);
}

Php::Value GtkStyleContext_::get_path() {
  const GtkWidgetPath *ret = gtk_style_context_get_path(GTK_STYLE_CONTEXT(instance));

  if (ret == nullptr) {
    return nullptr;
  }

  // gtk_style_context_get_path() returns a borrowed const reference owned by
  // the style context. Create a copy so the PHP wrapper owns and may safely
  // mutate and free the path without affecting GTK's internal state.
  GtkWidgetPath *path_copy = gtk_widget_path_copy(ret);
  if (path_copy == nullptr) {
    return nullptr;
  }

  GtkWidgetPath_ *return_parsed = new GtkWidgetPath_();
  return_parsed->set_instance(path_copy);
  return Php::Object("GtkWidgetPath", return_parsed);
}

void GtkStyleContext_::get_property(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_property not implemented - GValue handling not yet available");
}

Php::Value GtkStyleContext_::get_screen() {
  GdkScreen *ret = gtk_style_context_get_screen(GTK_STYLE_CONTEXT(instance));

  GdkScreen_ *returnValue = new GdkScreen_();
  returnValue->set_instance(ret);

  return Php::Object("GdkScreen", returnValue);
}

Php::Value GtkStyleContext_::get_frame_clock() {
  throw Php::Exception(
      "GtkStyleContext_::get_frame_clock not implemented - GdkFrameClock class not yet available");
}

Php::Value GtkStyleContext_::get_state() {
  GtkStateFlags ret = gtk_style_context_get_state(GTK_STYLE_CONTEXT(instance));

  return ret;
}

void GtkStyleContext_::get_style(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_style not implemented - variadic function not supported");
}

void GtkStyleContext_::get_style_property(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_style_property not implemented - GValue handling not yet available");
}

void GtkStyleContext_::get_style_valist(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_style_valist not implemented - va_list not supported");
}

void GtkStyleContext_::get_valist(Php::Parameters &parameters) {
  throw Php::Exception("GtkStyleContext_::get_valist not implemented - va_list not supported");
}

Php::Value GtkStyleContext_::get_section(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_section not implemented - GtkCssSection class not yet available");
}

Php::Value GtkStyleContext_::get_color(Php::Parameters &parameters) {
  // Validate state parameter
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::get_color: At least one parameter (state) is required");
  }
  if (!parameters[0].isNumeric()) {
    throw Php::Exception("GtkStyleContext_::get_color: First parameter (state) must be numeric");
  }

  int int_state = (int)parameters[0];
  GtkStateFlags state = (GtkStateFlags)int_state;

  GdkRGBA color;

  gtk_style_context_get_color(GTK_STYLE_CONTEXT(instance), state, &color);

  // If a second parameter is provided, validate and update it with the color value
  if (parameters.size() > 1) {
    Php::Value object_color = parameters[1];
    if (!object_color.isObject() || !object_color.instanceOf("GdkRGBA")) {
      throw Php::Exception(
          "GtkStyleContext_::get_color: Second parameter must be a GdkRGBA instance");
    }
    GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
    phpgtk_color->set_instance(color);
  }

  // Always return a GdkRGBA object
  GdkRGBA_ *return_parsed = new GdkRGBA_();
  return_parsed->set_instance(color);
  return Php::Object("GdkRGBA", return_parsed);
}

Php::Value GtkStyleContext_::get_background_color(Php::Parameters &parameters) {
  // Validate state parameter
  if (parameters.size() < 1) {
    throw Php::Exception(
        "GtkStyleContext_::get_background_color: At least one parameter (state) is required");
  }
  if (!parameters[0].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::get_background_color: First parameter (state) must be numeric");
  }

  int int_state = (int)parameters[0];
  GtkStateFlags state = (GtkStateFlags)int_state;

  GdkRGBA color;

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_get_background_color(GTK_STYLE_CONTEXT(instance), state, &color);
  G_GNUC_END_IGNORE_DEPRECATIONS

  // If a second parameter is provided, validate and update it with the color value
  if (parameters.size() > 1) {
    Php::Value object_color = parameters[1];
    if (!object_color.isObject() || !object_color.instanceOf("GdkRGBA")) {
      throw Php::Exception(
          "GtkStyleContext_::get_background_color: Second parameter must be a GdkRGBA instance");
    }
    GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
    phpgtk_color->set_instance(color);
  }

  // Always return a GdkRGBA object
  GdkRGBA_ *return_parsed = new GdkRGBA_();
  return_parsed->set_instance(color);
  return Php::Object("GdkRGBA", return_parsed);
}

Php::Value GtkStyleContext_::get_border_color(Php::Parameters &parameters) {
  // Validate state parameter
  if (parameters.size() < 1) {
    throw Php::Exception(
        "GtkStyleContext_::get_border_color: At least one parameter (state) is required");
  }
  if (!parameters[0].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::get_border_color: First parameter (state) must be numeric");
  }

  int int_state = (int)parameters[0];
  GtkStateFlags state = (GtkStateFlags)int_state;

  GdkRGBA color;

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_get_border_color(GTK_STYLE_CONTEXT(instance), state, &color);
  G_GNUC_END_IGNORE_DEPRECATIONS

  // If a second parameter is provided, validate and update it with the color value
  if (parameters.size() > 1) {
    Php::Value object_color = parameters[1];
    if (!object_color.isObject() || !object_color.instanceOf("GdkRGBA")) {
      throw Php::Exception(
          "GtkStyleContext_::get_border_color: Second parameter must be a GdkRGBA instance");
    }
    GdkRGBA_ *phpgtk_color = (GdkRGBA_ *)object_color.implementation();
    phpgtk_color->set_instance(color);
  }

  // Always return a GdkRGBA object
  GdkRGBA_ *return_parsed = new GdkRGBA_();
  return_parsed->set_instance(color);
  return Php::Object("GdkRGBA", return_parsed);
}

void GtkStyleContext_::get_border(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_border not implemented - GtkBorder class not yet available");
}

void GtkStyleContext_::get_padding(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_padding not implemented - GtkBorder class not yet available");
}

void GtkStyleContext_::get_margin(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_margin not implemented - GtkBorder class not yet available");
}

Php::Value GtkStyleContext_::get_font(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::get_font not implemented - PangoFontDescription class not yet available");
}

void GtkStyleContext_::invalidate() {
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_invalidate(GTK_STYLE_CONTEXT(instance));
  G_GNUC_END_IGNORE_DEPRECATIONS
}

Php::Value GtkStyleContext_::state_is_running(Php::Parameters &parameters) {
  // Validate state parameter
  if (parameters.size() < 1) {
    throw Php::Exception(
        "GtkStyleContext_::state_is_running: At least one parameter (state) is required");
  }
  if (!parameters[0].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::state_is_running: First parameter (state) must be numeric");
  }

  int int_state = (int)parameters[0];
  GtkStateType state = (GtkStateType)int_state;

  gdouble progress = 0.0;
  if (parameters.size() > 1) {
    if (!parameters[1].isNumeric()) {
      throw Php::Exception(
          "GtkStyleContext_::state_is_running: Second parameter (progress) must be numeric");
    }
    progress = (gdouble)parameters[1];
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gboolean ret = gtk_style_context_state_is_running(GTK_STYLE_CONTEXT(instance), state, &progress);
  G_GNUC_END_IGNORE_DEPRECATIONS

  // Return array with [is_running, progress]
  Php::Array result;
  result[0] = (bool)ret;
  result[1] = progress;
  return result;
}

Php::Value GtkStyleContext_::lookup_color(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::lookup_color: Requires one parameter: color_name");
  }

  if (!parameters[0].isString()) {
    throw Php::Exception(
        "GtkStyleContext_::lookup_color: First parameter (color_name) must be a string");
  }

  std::string s_color_name = parameters[0];
  gchar *color_name = (gchar *)s_color_name.c_str();

  GdkRGBA color;

  gboolean ret = gtk_style_context_lookup_color(GTK_STYLE_CONTEXT(instance), color_name, &color);

  if (!ret) {
    return nullptr;
  }

  GdkRGBA_ *return_parsed = new GdkRGBA_();
  return_parsed->set_instance(color);
  return Php::Object("GdkRGBA", return_parsed);
}

Php::Value GtkStyleContext_::lookup_icon_set(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::lookup_icon_set: Requires one parameter: stock_id");
  }

  if (!parameters[0].isString()) {
    throw Php::Exception(
        "GtkStyleContext_::lookup_icon_set: First parameter (stock_id) must be a string");
  }

  std::string s_stock_id = parameters[0];
  gchar *stock_id = (gchar *)s_stock_id.c_str();

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  GtkIconSet *ret = gtk_style_context_lookup_icon_set(GTK_STYLE_CONTEXT(instance), stock_id);
  G_GNUC_END_IGNORE_DEPRECATIONS

  // GtkIconSet is a boxed type. Until a GtkIconSet_ wrapper is implemented,
  // we cannot safely expose it to PHP. If no icon set is found, return null
  // (matching the GTK behavior). If one is found, throw a clear exception
  // indicating that the wrapper is not yet available.
  if (ret == nullptr) {
    return nullptr;
  }

  throw Php::Exception("GtkStyleContext_::lookup_icon_set(): GtkIconSet wrapper not available yet");
}

void GtkStyleContext_::notify_state_change(Php::Parameters &parameters) {
  GdkWindow *window = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    Php::Value object_window = parameters[0];
    if (!object_window.isObject() || !object_window.instanceOf("GdkWindow")) {
      throw Php::Exception(
          "GtkStyleContext_::notify_state_change(): first argument must be a GdkWindow instance or "
          "null");
    }
    GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
    window = GDK_WINDOW(phpgtk_window->get_instance());
  }

  gpointer region_id = nullptr;
  if (parameters.size() > 1 && !parameters[1].isNull()) {
    if (!parameters[1].isNumeric()) {
      throw Php::Exception(
          "GtkStyleContext_::notify_state_change(): second argument (region_id) must be numeric or "
          "null");
    }
    region_id = (gpointer)(intptr_t)parameters[1].numericValue();
  }

  int int_state = 0;
  if (parameters.size() > 2) {
    if (!parameters[2].isNumeric()) {
      throw Php::Exception(
          "GtkStyleContext_::notify_state_change(): third argument (state) must be a numeric "
          "GtkStateType value");
    }
    int_state = (int)parameters[2].numericValue();
  }
  GtkStateType state = (GtkStateType)int_state;

  gboolean state_value = FALSE;
  if (parameters.size() > 3) {
    state_value = (gboolean)parameters[3].boolValue();
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_notify_state_change(GTK_STYLE_CONTEXT(instance), window, region_id, state,
                                        state_value);
  G_GNUC_END_IGNORE_DEPRECATIONS
}

void GtkStyleContext_::pop_animatable_region() {
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_pop_animatable_region(GTK_STYLE_CONTEXT(instance));
  G_GNUC_END_IGNORE_DEPRECATIONS
}

void GtkStyleContext_::push_animatable_region(Php::Parameters &parameters) {
  gpointer region_id = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    region_id = (gpointer)(intptr_t)parameters[0].numericValue();
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_push_animatable_region(GTK_STYLE_CONTEXT(instance), region_id);
  G_GNUC_END_IGNORE_DEPRECATIONS
}

void GtkStyleContext_::cancel_animations(Php::Parameters &parameters) {
  gpointer region_id = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    region_id = (gpointer)(intptr_t)parameters[0].numericValue();
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_cancel_animations(GTK_STYLE_CONTEXT(instance), region_id);
  G_GNUC_END_IGNORE_DEPRECATIONS
}

void GtkStyleContext_::scroll_animations(Php::Parameters &parameters) {
  GdkWindow *window = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    Php::Value object_window = parameters[0];
    if (!object_window.isObject() || !object_window.instanceOf("GdkWindow")) {
      throw Php::Exception(
          "GtkStyleContext_::scroll_animations first parameter must be a GdkWindow or null");
    }

    GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
    window = GDK_WINDOW(phpgtk_window->get_instance());
  }

  gint dx = 0;
  if (parameters.size() > 1 && !parameters[1].isNull()) {
    if (!parameters[1].isNumeric()) {
      throw Php::Exception(
          "GtkStyleContext_::scroll_animations second parameter (dx) must be numeric");
    }
    dx = (gint)parameters[1].numericValue();
  }

  gint dy = 0;
  if (parameters.size() > 2 && !parameters[2].isNull()) {
    if (!parameters[2].isNumeric()) {
      throw Php::Exception(
          "GtkStyleContext_::scroll_animations third parameter (dy) must be numeric");
    }
    dy = (gint)parameters[2].numericValue();
  }
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_scroll_animations(GTK_STYLE_CONTEXT(instance), window, dx, dy);
  G_GNUC_END_IGNORE_DEPRECATIONS
}

void GtkStyleContext_::remove_provider(Php::Parameters &parameters) {
  GtkStyleProvider *provider = nullptr;
  if (parameters.size() > 0) {
    Php::Value object_provider = parameters[0];
    GtkCssProvider_ *phpgtk_provider = (GtkCssProvider_ *)object_provider.implementation();
    provider = GTK_STYLE_PROVIDER(phpgtk_provider->get_instance());
  }

  if (provider == nullptr) {
    throw Php::Exception("GtkStyleContext::remove_provider requires a provider parameter");
  }

  gtk_style_context_remove_provider(GTK_STYLE_CONTEXT(instance), provider);
}

void GtkStyleContext_::remove_provider_for_screen(Php::Parameters &parameters) {
  GtkStyleProvider *provider = nullptr;
  if (parameters.size() > 0) {
    Php::Value object_provider = parameters[0];
    GtkCssProvider_ *phpgtk_provider = (GtkCssProvider_ *)object_provider.implementation();
    provider = GTK_STYLE_PROVIDER(phpgtk_provider->get_instance());
  }

  if (provider == nullptr) {
    throw Php::Exception(
        "GtkStyleContext::remove_provider_for_screen requires a provider parameter");
  }

  GdkScreen *screen = gdk_screen_get_default();
  if (screen == nullptr) {
    throw Php::Exception(
        "GtkStyleContext::remove_provider_for_screen: no default screen available");
  }

  gtk_style_context_remove_provider_for_screen(screen, provider);
}

void GtkStyleContext_::reset_widgets() {
  GdkScreen *screen = nullptr;

  // Prefer the screen associated with this style context, if any
  if (instance != nullptr) {
    screen = gtk_style_context_get_screen(GTK_STYLE_CONTEXT(instance));
  }

  // Fall back to the default screen if the context has no screen
  if (screen == nullptr) {
    screen = gdk_screen_get_default();
  }

  // Only reset widgets if we have a valid screen
  if (screen != nullptr) {
    G_GNUC_BEGIN_IGNORE_DEPRECATIONS
    gtk_style_context_reset_widgets(screen);
    G_GNUC_END_IGNORE_DEPRECATIONS
  }
}

void GtkStyleContext_::set_background(Php::Parameters &parameters) {
  GdkWindow *window = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    Php::Value object_window = parameters[0];

    // Ensure the provided argument is a GdkWindow instance
    if (!object_window.instanceOf("GdkWindow")) {
      throw Php::Exception(
          "GtkStyleContext::set_background expects parameter 0 to be a GdkWindow instance or null");
    }

    GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
    if (phpgtk_window == nullptr) {
      throw Php::Exception("GtkStyleContext::set_background received an invalid GdkWindow object");
    }
    window = GDK_WINDOW(phpgtk_window->get_instance());
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_set_background(GTK_STYLE_CONTEXT(instance), window);
  G_GNUC_END_IGNORE_DEPRECATIONS
}

void GtkStyleContext_::restore() {
  gtk_style_context_restore(GTK_STYLE_CONTEXT(instance));
}

void GtkStyleContext_::save() {
  gtk_style_context_save(GTK_STYLE_CONTEXT(instance));
}

void GtkStyleContext_::set_direction(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception(
        "GtkStyleContext_::set_direction expects 1 numeric parameter (GtkTextDirection)");
  }

  if (!parameters[0].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::set_direction expects a numeric GtkTextDirection value as the first "
        "parameter");
  }

  int int_direction = (int)parameters[0];
  GtkTextDirection direction = (GtkTextDirection)int_direction;

  gtk_style_context_set_direction(GTK_STYLE_CONTEXT(instance), direction);
}

void GtkStyleContext_::set_junction_sides(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception(
        "GtkStyleContext_::set_junction_sides: Requires one numeric parameter (GtkJunctionSides)");
  }

  if (!parameters[0].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::set_junction_sides: First parameter must be a numeric GtkJunctionSides "
        "value");
  }

  int int_sides = (int)parameters[0];
  GtkJunctionSides sides = (GtkJunctionSides)int_sides;

  gtk_style_context_set_junction_sides(GTK_STYLE_CONTEXT(instance), sides);
}

void GtkStyleContext_::set_parent(Php::Parameters &parameters) {
  GtkStyleContext *parent = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    Php::Value object_parent = parameters[0];
    if (!object_parent.isObject() || !object_parent.instanceOf("GtkStyleContext")) {
      throw Php::Exception("GtkStyleContext::set_parent expects GtkStyleContext or null");
    }
    GtkStyleContext_ *phpgtk_parent = (GtkStyleContext_ *)object_parent.implementation();
    if (phpgtk_parent != nullptr) {
      parent = GTK_STYLE_CONTEXT(phpgtk_parent->get_instance());
    }
  }

  gtk_style_context_set_parent(GTK_STYLE_CONTEXT(instance), parent);
}

void GtkStyleContext_::set_path(Php::Parameters &parameters) {
  GtkWidgetPath *path = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    Php::Value object_path = parameters[0];
    if (!object_path.isObject() || !object_path.instanceOf("GtkWidgetPath")) {
      throw Php::Exception("GtkStyleContext::set_path expects GtkWidgetPath or null");
    }
    GtkWidgetPath_ *phpgtk_path = (GtkWidgetPath_ *)object_path.implementation();
    if (phpgtk_path != nullptr) {
      path = phpgtk_path->get_instance();
    }
  }

  gtk_style_context_set_path(GTK_STYLE_CONTEXT(instance), path);
}

void GtkStyleContext_::add_class(Php::Parameters &parameters) {
  std::string s_class_name = parameters[0];
  gchar *class_name = (gchar *)s_class_name.c_str();

  gtk_style_context_add_class(GTK_STYLE_CONTEXT(instance), class_name);
}

void GtkStyleContext_::remove_class(Php::Parameters &parameters) {
  std::string s_class_name = parameters[0];
  gchar *class_name = (gchar *)s_class_name.c_str();

  gtk_style_context_remove_class(GTK_STYLE_CONTEXT(instance), class_name);
}

Php::Value GtkStyleContext_::has_class(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::has_class: Requires one parameter: class_name");
  }

  if (!parameters[0].isString()) {
    throw Php::Exception(
        "GtkStyleContext_::has_class: First parameter (class_name) must be a string");
  }

  std::string s_class_name = parameters[0];
  gchar *class_name = (gchar *)s_class_name.c_str();

  gboolean ret = gtk_style_context_has_class(GTK_STYLE_CONTEXT(instance), class_name);

  return ret;
}

Php::Value GtkStyleContext_::list_classes() {
  GList *ret = gtk_style_context_list_classes(GTK_STYLE_CONTEXT(instance));

  if (!ret) {
    return Php::Array();
  }

  Php::Array ret_arr;
  int i = 0;
  for (GList *item = ret; item != nullptr; item = item->next, ++i) {
    ret_arr[i] = (const char *)item->data;
  }
  g_list_free(ret);
  return ret_arr;
}

void GtkStyleContext_::add_region(Php::Parameters &parameters) {
  if (parameters.size() < 2) {
    throw Php::Exception(
        "GtkStyleContext_::add_region: Requires two parameters: region_name and flags");
  }

  if (!parameters[0].isString()) {
    throw Php::Exception(
        "GtkStyleContext_::add_region: First parameter (region_name) must be a string");
  }

  std::string s_region_name = parameters[0];
  gchar *region_name = (gchar *)s_region_name.c_str();

  if (!parameters[1].isNumeric()) {
    throw Php::Exception("GtkStyleContext_::add_region: Second parameter (flags) must be numeric");
  }
  int int_flags = (int)parameters[1];
  GtkRegionFlags flags = (GtkRegionFlags)int_flags;

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_add_region(GTK_STYLE_CONTEXT(instance), region_name, flags);
  G_GNUC_END_IGNORE_DEPRECATIONS
}

void GtkStyleContext_::remove_region(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::remove_region: Requires one parameter: region_name");
  }

  if (!parameters[0].isString()) {
    throw Php::Exception(
        "GtkStyleContext_::remove_region: First parameter (region_name) must be a string");
  }

  std::string s_region_name = parameters[0];
  gchar *region_name = (gchar *)s_region_name.c_str();

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_style_context_remove_region(GTK_STYLE_CONTEXT(instance), region_name);
  G_GNUC_END_IGNORE_DEPRECATIONS
}

Php::Value GtkStyleContext_::has_region(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::has_region: Requires one parameter: region_name");
  }

  if (!parameters[0].isString()) {
    throw Php::Exception(
        "GtkStyleContext_::has_region: First parameter (region_name) must be a string");
  }
  std::string s_region_name = parameters[0];
  gchar *region_name = (gchar *)s_region_name.c_str();

  GtkRegionFlags flags_return = (GtkRegionFlags)0;

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gboolean ret =
      gtk_style_context_has_region(GTK_STYLE_CONTEXT(instance), region_name, &flags_return);
  G_GNUC_END_IGNORE_DEPRECATIONS

  // Return array with [has_region, flags]
  Php::Array result;
  result[0] = (bool)ret;
  result[1] = (int)flags_return;
  return result;
}

Php::Value GtkStyleContext_::list_regions() {
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  GList *ret = gtk_style_context_list_regions(GTK_STYLE_CONTEXT(instance));
  G_GNUC_END_IGNORE_DEPRECATIONS

  if (!ret) {
    return Php::Array();
  }

  Php::Array ret_arr;
  int i = 0;
  for (GList *item = ret; item != nullptr; item = item->next, ++i) {
    ret_arr[i] = (const char *)item->data;
  }
  g_list_free_full(ret, g_free);
  return ret_arr;
}

void GtkStyleContext_::set_screen(Php::Parameters &parameters) {
  GdkScreen *screen = nullptr;
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    Php::Value object_screen = parameters[0];
    if (!object_screen.isObject() || !object_screen.instanceOf("GdkScreen")) {
      throw Php::Exception(
          "GtkStyleContext_::set_screen expects parameter 0 to be a GdkScreen instance or null");
    }
    GdkScreen_ *phpgtk_screen = (GdkScreen_ *)object_screen.implementation();
    screen = phpgtk_screen->get_instance();
  }

  gtk_style_context_set_screen(GTK_STYLE_CONTEXT(instance), screen);
}

void GtkStyleContext_::set_frame_clock(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::set_frame_clock not implemented - GdkFrameClock class not yet available");
}

void GtkStyleContext_::set_state(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::set_state expects 1 numeric parameter (GtkStateFlags)");
  }

  if (!parameters[0].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::set_state expects a numeric GtkStateFlags value as the first parameter");
  }

  auto int_flags = parameters[0].numericValue();
  GtkStateFlags flags = (GtkStateFlags)int_flags;

  gtk_style_context_set_state(GTK_STYLE_CONTEXT(instance), flags);
}

void GtkStyleContext_::set_scale(Php::Parameters &parameters) {
  if (parameters.size() < 1) {
    throw Php::Exception("GtkStyleContext_::set_scale expects 1 numeric parameter (scale)");
  }

  if (!parameters[0].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::set_scale expects a numeric scale value as the first parameter");
  }

  gint scale = (gint)parameters[0];

  if (scale <= 0) {
    throw Php::Exception("GtkStyleContext_::set_scale expects a positive scale value");
  }

  gtk_style_context_set_scale(GTK_STYLE_CONTEXT(instance), scale);
}

Php::Value GtkStyleContext_::get_scale() {
  gint ret = gtk_style_context_get_scale(GTK_STYLE_CONTEXT(instance));

  return ret;
}

Php::Value GtkStyleContext_::to_string(Php::Parameters &parameters) {
  // Default to no special print flags if none are provided
  GtkStyleContextPrintFlags flags = GTK_STYLE_CONTEXT_PRINT_NONE;

  if (parameters.size() > 0) {
    if (!parameters[0].isNumeric()) {
      throw Php::Exception("GtkStyleContext_::to_string: First parameter (flags) must be numeric");
    }
    int int_flags = (int)parameters[0];
    flags = (GtkStyleContextPrintFlags)int_flags;
  }

  char *ret = gtk_style_context_to_string(GTK_STYLE_CONTEXT(instance), flags);

  if (ret == nullptr) {
    return "";
  }

  std::string result(ret);
  g_free(ret);
  return result;
}

Php::Value GtkStyleContext_::gtk_border_new() {
  throw Php::Exception(
      "GtkStyleContext_::gtk_border_new not implemented - GtkBorder class not yet available");
}

Php::Value GtkStyleContext_::gtk_border_copy() {
  throw Php::Exception(
      "GtkStyleContext_::gtk_border_copy not implemented - GtkBorder class not yet available");
}

void GtkStyleContext_::gtk_border_free() {
  throw Php::Exception(
      "GtkStyleContext_::gtk_border_free not implemented - GtkBorder class not yet available");
}

void GtkStyleContext_::gtk_render_arrow(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_arrow: Requires five parameters: GdkEvent (cairo context), "
        "angle, x, y, size");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_arrow: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_arrow: Parameters 2-5 (angle, x, y, size) must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_arrow: Invalid cairo context");
  }

  gdouble angle = (gdouble)parameters[1];
  gdouble x = (gdouble)parameters[2];
  gdouble y = (gdouble)parameters[3];
  gdouble size = (gdouble)parameters[4];

  ::gtk_render_arrow(GTK_STYLE_CONTEXT(instance), cr, angle, x, y, size);
}

void GtkStyleContext_::gtk_render_background(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_background: Requires five parameters: GdkEvent (cairo "
        "context), x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_background: First parameter must be a GdkEvent (cairo "
        "context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_background: Parameters 2-5 (x, y, width, height) must be "
        "numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_background: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_background(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

void GtkStyleContext_::gtk_render_background_get_clip(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::gtk_render_background_get_clip not implemented - GdkRectangle handling "
      "not yet available");
}

void GtkStyleContext_::gtk_render_check(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_check: Requires five parameters: GdkEvent (cairo context), "
        "x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_check: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_check: Parameters 2-5 (x, y, width, height) must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_check: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_check(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

void GtkStyleContext_::gtk_render_expander(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_expander: Requires five parameters: GdkEvent (cairo "
        "context), x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_expander: First parameter must be a GdkEvent (cairo "
        "context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_expander: Parameters 2-5 (x, y, width, height) must be "
        "numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_expander: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_expander(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

void GtkStyleContext_::gtk_render_extension(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 6) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_extension: Requires six parameters: GdkEvent (cairo "
        "context), x, y, width, height, gap_side");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_extension: First parameter must be a GdkEvent (cairo "
        "context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric() || !parameters[5].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_extension: Parameters 2-6 (x, y, width, height, gap_side) "
        "must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_extension: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];
  int int_gap_side = (int)parameters[5];
  GtkPositionType gap_side = (GtkPositionType)int_gap_side;

  ::gtk_render_extension(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height, gap_side);
}

void GtkStyleContext_::gtk_render_focus(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_focus: Requires five parameters: GdkEvent (cairo context), "
        "x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_focus: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_focus: Parameters 2-5 (x, y, width, height) must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_focus: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_focus(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

void GtkStyleContext_::gtk_render_frame(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_frame: Requires five parameters: GdkEvent (cairo context), "
        "x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_frame: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_frame: Parameters 2-5 (x, y, width, height) must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_frame: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_frame(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

void GtkStyleContext_::gtk_render_frame_gap(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 8) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_frame_gap: Requires eight parameters: GdkEvent (cairo "
        "context), x, y, width, height, gap_side, xy0_gap, xy1_gap");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_frame_gap: First parameter must be a GdkEvent (cairo "
        "context)");
  }
  // Validate parameters 1-7 (user parameters 2-8) are numeric
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric() || !parameters[5].isNumeric() || !parameters[6].isNumeric() ||
      !parameters[7].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_frame_gap: Parameters 2-8 (x, y, width, height, gap_side, "
        "xy0_gap, xy1_gap) must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_frame_gap: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];
  int int_gap_side = (int)parameters[5];
  GtkPositionType gap_side = (GtkPositionType)int_gap_side;
  gdouble xy0_gap = (gdouble)parameters[6];
  gdouble xy1_gap = (gdouble)parameters[7];

  ::gtk_render_frame_gap(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height, gap_side, xy0_gap,
                         xy1_gap);
}

void GtkStyleContext_::gtk_render_handle(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_handle: Requires five parameters: GdkEvent (cairo context), "
        "x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_handle: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_handle: Parameters 2-5 (x, y, width, height) must be "
        "numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_handle: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_handle(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

void GtkStyleContext_::gtk_render_layout(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::gtk_render_layout not implemented - Cairo/Pango support not yet "
      "available");
}

void GtkStyleContext_::gtk_render_line(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_line: Requires five parameters: GdkEvent (cairo context), "
        "x0, y0, x1, y1");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_line: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_line: Parameters 2-5 (x0, y0, x1, y1) must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_line: Invalid cairo context");
  }

  gdouble x0 = (gdouble)parameters[1];
  gdouble y0 = (gdouble)parameters[2];
  gdouble x1 = (gdouble)parameters[3];
  gdouble y1 = (gdouble)parameters[4];

  ::gtk_render_line(GTK_STYLE_CONTEXT(instance), cr, x0, y0, x1, y1);
}

void GtkStyleContext_::gtk_render_option(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_option: Requires five parameters: GdkEvent (cairo context), "
        "x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_option: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_option: Parameters 2-5 (x, y, width, height) must be "
        "numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_option: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_option(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

void GtkStyleContext_::gtk_render_slider(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 6) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_slider: Requires six parameters: GdkEvent (cairo context), "
        "x, y, width, height, orientation");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_slider: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric() || !parameters[5].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_slider: Parameters 2-6 (x, y, width, height, orientation) "
        "must be numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_slider: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];
  int int_orientation = (int)parameters[5];
  GtkOrientation orientation = (GtkOrientation)int_orientation;

  ::gtk_render_slider(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height, orientation);
}

void GtkStyleContext_::gtk_render_activity(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 5) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_activity: Requires five parameters: GdkEvent (cairo "
        "context), x, y, width, height");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_activity: First parameter must be a GdkEvent (cairo "
        "context)");
  }
  if (!parameters[1].isNumeric() || !parameters[2].isNumeric() || !parameters[3].isNumeric() ||
      !parameters[4].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_activity: Parameters 2-5 (x, y, width, height) must be "
        "numeric");
  }

  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_activity: Invalid cairo context");
  }

  gdouble x = (gdouble)parameters[1];
  gdouble y = (gdouble)parameters[2];
  gdouble width = (gdouble)parameters[3];
  gdouble height = (gdouble)parameters[4];

  ::gtk_render_activity(GTK_STYLE_CONTEXT(instance), cr, x, y, width, height);
}

Php::Value GtkStyleContext_::gtk_render_icon_pixbuf(Php::Parameters &parameters) {
  // Note: This function is deprecated since GTK 3.10
  // GtkIconSource parameter - we'll accept nullptr for now since GtkIconSource is also deprecated
  // The full implementation would require a GtkIconSource wrapper

  // Keep parameter positions aligned with GTK:
  // gtk_render_icon_pixbuf(context, source, size)
  // - If one argument is provided, treat it as `size` (backwards compatible)
  // - If two or more arguments are provided, treat the second as `size` and
  //   ignore the first (conceptual `source`) until a GtkIconSource wrapper exists
  if (parameters.size() == 0) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_icon_pixbuf: At least a size parameter is required");
  }

  const GtkIconSource *source = nullptr;
  // For now, source is always nullptr as we don't have GtkIconSource wrapper

  // Determine which parameter holds the size
  std::size_t size_index = (parameters.size() >= 2) ? 1 : 0;

  // Validate that the size parameter is numeric before casting
  if (!parameters[size_index].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_icon_pixbuf: size parameter must be numeric");
  }

  int int_size = (int)parameters[size_index];

  // Basic validation: reject the explicit invalid sentinel, allow custom registered sizes
  if (int_size == GTK_ICON_SIZE_INVALID) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_icon_pixbuf: size parameter must not be "
        "GTK_ICON_SIZE_INVALID");
  }

  GtkIconSize size = (GtkIconSize)int_size;

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  GdkPixbuf *ret = ::gtk_render_icon_pixbuf(GTK_STYLE_CONTEXT(instance), source, size);
  G_GNUC_END_IGNORE_DEPRECATIONS

  if (ret == nullptr) {
    return nullptr;
  }

  GdkPixbuf_ *return_parsed = new GdkPixbuf_();
  return_parsed->set_instance(ret);
  return Php::Object("GdkPixbuf", return_parsed);
}

void GtkStyleContext_::gtk_render_icon_surface(Php::Parameters &parameters) {
  // Extract cairo context from GdkEvent wrapper (first parameter)
  if (parameters.size() < 1 || !parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_icon_surface: First parameter must be a GdkEvent (cairo "
        "context)");
  }
  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_icon_surface: Invalid cairo context");
  }

  // For surface parameter, we need cairo_surface_t* which isn't wrapped yet
  // This would need a cairo surface wrapper to implement properly
  throw Php::Exception(
      "GtkStyleContext_::gtk_render_icon_surface not implemented - cairo_surface_t wrapper not yet "
      "available");
}

void GtkStyleContext_::gtk_render_icon(Php::Parameters &parameters) {
  // Validate parameters
  if (parameters.size() < 4) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_icon: Requires four parameters: GdkEvent (cairo context), "
        "GdkPixbuf, x, y");
  }
  if (!parameters[0].instanceOf("GdkEvent")) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_icon: First parameter must be a GdkEvent (cairo context)");
  }
  if (!parameters[1].instanceOf("GdkPixbuf")) {
    throw Php::Exception("GtkStyleContext_::gtk_render_icon: Second parameter must be a GdkPixbuf");
  }
  if (!parameters[2].isNumeric() || !parameters[3].isNumeric()) {
    throw Php::Exception(
        "GtkStyleContext_::gtk_render_icon: Third and fourth parameters (x, y) must be numeric");
  }

  // Extract cairo context from GdkEvent wrapper (first parameter)
  GdkEvent_ *phpgtk_event = (GdkEvent_ *)parameters[0].implementation();
  cairo_t *cr = (cairo_t *)phpgtk_event->instance;

  if (cr == nullptr) {
    throw Php::Exception("GtkStyleContext_::gtk_render_icon: Invalid cairo context");
  }

  // Extract pixbuf parameter
  GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)parameters[1].implementation();
  GdkPixbuf *pixbuf = phpgtk_pixbuf->get_instance();

  gdouble x = (gdouble)parameters[2];
  gdouble y = (gdouble)parameters[3];

  ::gtk_render_icon(GTK_STYLE_CONTEXT(instance), cr, pixbuf, x, y);
}

void GtkStyleContext_::gtk_render_insertion_cursor(Php::Parameters &parameters) {
  throw Php::Exception(
      "GtkStyleContext_::gtk_render_insertion_cursor not implemented - Cairo/Pango support not yet "
      "available");
}
