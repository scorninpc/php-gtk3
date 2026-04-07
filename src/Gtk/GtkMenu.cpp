
#include "GtkMenu.h"
#include "GtkStatusIcon.h"

/**
 * Struct for popup callback
 */
struct GtkMenu_::st_popup_callback {
  Php::Value callback_function;
  Php::Value user_data;
  Php::Value menu_object;  // Store the original menu PHP object
  bool use_gtk_status_icon_position;
};

/**
 * Constructor
 */
GtkMenu_::GtkMenu_() = default;

/**
 * Destructor
 */
GtkMenu_::~GtkMenu_() = default;

/**
 * Destroy notify function to clean up callback data
 */
void GtkMenu_::popup_callback_destroy(gpointer data) {
  struct st_popup_callback *callback_object = static_cast<struct st_popup_callback *>(data);
  delete callback_object;
}

/**
 * Callback function for gtk_menu_popup positioning
 */
void GtkMenu_::popup_position_callback(GtkMenu *menu, gint *x, gint *y, gboolean *push_in,
                                       gpointer user_data) {
  struct st_popup_callback *callback_object = static_cast<struct st_popup_callback *>(user_data);

  // Special case: if using gtk_status_icon_position_menu, call it directly
  if (callback_object->use_gtk_status_icon_position) {
    // user_data should be a GtkStatusIcon object
    if (!callback_object->user_data.isNull() && callback_object->user_data.isObject()) {
      Php::Value status_icon_obj = callback_object->user_data;
      GtkStatusIcon_ *status_icon_wrapper =
          dynamic_cast<GtkStatusIcon_ *>(status_icon_obj.implementation());
      if (status_icon_wrapper) {
        GtkStatusIcon *status_icon = GTK_STATUS_ICON(status_icon_wrapper->get_instance());
        gtk_status_icon_position_menu(menu, x, y, push_in, status_icon);
        return;
      }
    }
    // Fall through to default positioning if status icon is invalid
    Php::warning
        << "GtkMenu::popup: status icon position_menu requires a valid GtkStatusIcon object"
        << std::flush;
    *x = 0;
    *y = 0;
    *push_in = TRUE;
    return;
  }

  // Initialize output parameters to safe defaults
  if (x) {
    *x = 0;
  }
  if (y) {
    *y = 0;
  }
  if (push_in) {
    *push_in = TRUE;
  }

  try {
    // Create parameters array for the PHP callback
    Php::Array params;

    // Add the original menu object (stored during popup() call)
    params[0] = callback_object->menu_object;

    // Add user data if provided
    if (!callback_object->user_data.isNull()) {
      params[1] = callback_object->user_data;
    }

    // Call the PHP callback function
    Php::Value result =
        Php::call("call_user_func_array", callback_object->callback_function, params);

    // The callback should return an array with 'x', 'y', and optionally 'push_in'
    if (result.isArray()) {
      Php::Array result_array = result;
      if (result_array.contains("x")) {
        *x = (gint)result_array["x"];
      }
      if (result_array.contains("y")) {
        *y = (gint)result_array["y"];
      }
      if (result_array.contains("push_in")) {
        *push_in = (gboolean)result_array["push_in"];
      }
    } else {
      // Callback did not return an array - log a warning
      Php::warning << "GtkMenu::popup positioning callback did not return an array; using default "
                      "position (0, 0)"
                   << std::flush;
    }
  } catch (const Php::Exception &e) {
    // Log the exception to help diagnose callback failures, but do not let it cross
    // the C callback boundary (GtkMenuPositionFunc).
    Php::warning << "GtkMenu::popup positioning callback failed: " << e.what() << std::flush;
    // Safe defaults were already set at the start of the function.
    // Do not rethrow: throwing across a C ABI callback boundary is undefined.
  }
}

void GtkMenu_::__construct() {
  instance = (gpointer *)gtk_menu_new();
}

void GtkMenu_::new_from_model(Php::Parameters &parameters) {
  // gtk_menu_new_from_model (model);

  throw Php::Exception("GtkMenu_::new_from_model not implemented");
}

void GtkMenu_::set_screen(Php::Parameters &parameters) {
  // GdkScreen *screen;
  // if(parameters.size() > 0) {
  // 	Php::Value object_screen = parameters[0];
  // 	GdkScreen_ *phpgtk_screen = (GdkScreen_ *)object_screen.implementation();
  // 	screen = GTK_WIDGET(phpgtk_screen->get_instance());
  // }

  // gtk_menu_set_screen (GTK_MENU(instance), screen);

  throw Php::Exception("GtkMenu_::set_screen not implemented");
}

void GtkMenu_::reorder_child(Php::Parameters &parameters) {
  GtkWidget *child;
  if (parameters.size() > 0) {
    Php::Value object_child = parameters[0];
    GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
    child = GTK_WIDGET(phpgtk_child->get_instance());
  }

  gint position = (gint)parameters[1];

  gtk_menu_reorder_child(GTK_MENU(instance), child, position);
}

void GtkMenu_::attach(Php::Parameters &parameters) {
  GtkWidget *child;
  if (parameters.size() > 0) {
    Php::Value object_child = parameters[0];
    GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
    child = GTK_WIDGET(phpgtk_child->get_instance());
  }

  guint left_attach = (int)parameters[1];

  guint right_attach = (int)parameters[2];

  guint top_attach = (int)parameters[3];

  guint bottom_attach = (int)parameters[4];

  gtk_menu_attach(GTK_MENU(instance), child, left_attach, right_attach, top_attach, bottom_attach);
}

void GtkMenu_::popup_at_rect(Php::Parameters &parameters) {
  // GdkWindow *rect_window;
  // if(parameters.size() > 0) {
  // 	Php::Value object_rect_window = parameters[0];
  // 	GdkWindow_ *phpgtk_rect_window = (GdkWindow_ *)object_rect_window.implementation();
  // 	rect_window = GTK_WIDGET(phpgtk_rect_window->get_instance());
  // }

  // GdkRectangle *rect;
  // if(parameters.size() > 1) {
  // 	Php::Value object_rect = parameters[1];
  // 	GdkRectangle_ *phpgtk_rect = (GdkRectangle_ *)object_rect.implementation();
  // 	rect = GTK_WIDGET(phpgtk_rect->get_instance());
  // }

  // GdkGravity *rect_anchor;
  // if(parameters.size() > 2) {
  // 	Php::Value object_rect_anchor = parameters[2];
  // 	GdkGravity_ *phpgtk_rect_anchor = (GdkGravity_ *)object_rect_anchor.implementation();
  // 	rect_anchor = GTK_WIDGET(phpgtk_rect_anchor->get_instance());
  // }

  // GdkGravity *menu_anchor;
  // if(parameters.size() > 3) {
  // 	Php::Value object_menu_anchor = parameters[3];
  // 	GdkGravity_ *phpgtk_menu_anchor = (GdkGravity_ *)object_menu_anchor.implementation();
  // 	menu_anchor = GTK_WIDGET(phpgtk_menu_anchor->get_instance());
  // }

  // GdkEvent *trigger_event;
  // if(parameters.size() > 4) {
  // 	Php::Value object_trigger_event = parameters[4];
  // 	GdkEvent_ *phpgtk_trigger_event = (GdkEvent_ *)object_trigger_event.implementation();
  // 	trigger_event = GTK_WIDGET(phpgtk_trigger_event->get_instance());
  // }

  // gtk_menu_popup_at_rect (GTK_MENU(instance), rect_window, rect, rect_anchor, menu_anchor,
  // trigger_event);

  throw Php::Exception("GtkMenu_::popup_at_rect not implemented");
}

void GtkMenu_::popup_at_widget(Php::Parameters &parameters) {
  // GtkWidget *widget;
  // if(parameters.size() > 0) {
  // 	Php::Value object_widget = parameters[0];
  // 	GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
  // 	widget = GTK_WIDGET(phpgtk_widget->get_instance());
  // }

  // GdkGravity *widget_anchor;
  // if(parameters.size() > 1) {
  // 	Php::Value object_widget_anchor = parameters[1];
  // 	GdkGravity_ *phpgtk_widget_anchor = (GdkGravity_ *)object_widget_anchor.implementation();
  // 	widget_anchor = GTK_WIDGET(phpgtk_widget_anchor->get_instance());
  // }

  // GdkGravity *menu_anchor;
  // if(parameters.size() > 2) {
  // 	Php::Value object_menu_anchor = parameters[2];
  // 	GdkGravity_ *phpgtk_menu_anchor = (GdkGravity_ *)object_menu_anchor.implementation();
  // 	menu_anchor = GTK_WIDGET(phpgtk_menu_anchor->get_instance());
  // }

  // GdkEvent *trigger_event;
  // if(parameters.size() > 3) {
  // 	Php::Value object_trigger_event = parameters[3];
  // 	GdkEvent_ *phpgtk_trigger_event = (GdkEvent_ *)object_trigger_event.implementation();
  // 	trigger_event = GTK_WIDGET(phpgtk_trigger_event->get_instance());
  // }

  // gtk_menu_popup_at_widget (GTK_MENU(instance), widget, widget_anchor, menu_anchor,
  // trigger_event);

  throw Php::Exception("GtkMenu_::at_widget not implemented");
}

void GtkMenu_::popup_at_pointer(Php::Parameters &parameters) {
  GdkEvent *trigger_event;
  Php::Value object_trigger_event = parameters[0];
  GdkEvent_ *phpgtk_trigger_event = (GdkEvent_ *)object_trigger_event.implementation();
  trigger_event = phpgtk_trigger_event->get_instance();

  gtk_menu_popup_at_pointer(GTK_MENU(instance), trigger_event);
}

void GtkMenu_::popup(Php::Parameters &parameters) {
  GtkWidget *parent_menu_shell = nullptr;
  GtkWidget *parent_menu_item = nullptr;
  GtkMenuPositionFunc func = nullptr;
  gpointer data = nullptr;
  struct st_popup_callback *callback_object = nullptr;
  guint button = 0;
  guint32 activate_time = 0;

  // Optional parent_menu_shell (parameter 0)
  if (parameters.size() > 0 && !parameters[0].isNull()) {
    if (!parameters[0].isObject()) {
      throw Php::Exception(
          "GtkMenu::popup parameter 0 (parent_menu_shell) expects a GtkWidget or null");
    }

    Php::Value object_parent_menu_shell = parameters[0];
    GtkWidget_ *phpgtk_parent_menu_shell =
        dynamic_cast<GtkWidget_ *>(object_parent_menu_shell.implementation());
    if (!phpgtk_parent_menu_shell) {
      throw Php::Exception(
          "GtkMenu::popup parameter 0 (parent_menu_shell) must be a GtkWidget instance");
    }

    parent_menu_shell = GTK_WIDGET(phpgtk_parent_menu_shell->get_instance());
  }

  // Optional parent_menu_item (parameter 1)
  if (parameters.size() > 1 && !parameters[1].isNull()) {
    if (!parameters[1].isObject()) {
      throw Php::Exception(
          "GtkMenu::popup parameter 1 (parent_menu_item) expects a GtkWidget or null");
    }

    Php::Value object_parent_menu_item = parameters[1];
    GtkWidget_ *phpgtk_parent_menu_item =
        dynamic_cast<GtkWidget_ *>(object_parent_menu_item.implementation());
    if (!phpgtk_parent_menu_item) {
      throw Php::Exception(
          "GtkMenu::popup parameter 1 (parent_menu_item) must be a GtkWidget instance");
    }
    parent_menu_item = GTK_WIDGET(phpgtk_parent_menu_item->get_instance());
  }

  // Optional func (parameter 2) - positioning callback
  // Must be a PHP callable (function, closure, or callable array) or null
  if (parameters.size() > 2 && !parameters[2].isNull()) {
    // Accept only valid callables (arrays are allowed only when they are callable, e.g. [$object,
    // 'methodName'])
    if (!parameters[2].isCallable()) {
      throw Php::Exception(
          "GtkMenu::popup parameter 2 (func) must be a valid callable or null. "
          "Use [$statusIconObject, 'position_menu'] for instance methods, not ['ClassName', "
          "'methodName']");
    }

    // Create callback structure
    callback_object = new struct st_popup_callback();
    callback_object->callback_function = parameters[2];
    callback_object->use_gtk_status_icon_position = false;
    // Store the original menu PHP object to preserve object identity and avoid
    // unnecessary wrapper creation on each callback invocation
    callback_object->menu_object = Php::Object(this);

    // Check if this is a special case for gtk_status_icon_position_menu
    // This is when callback is an array like [$statusIcon, 'position_menu']
    if (parameters[2].isArray()) {
      Php::Array callback_array = parameters[2];
      if (callback_array.size() == 2) {
        Php::Value element0 = callback_array[0];
        Php::Value element1 = callback_array[1];

        if (element1.isString()) {
          std::string method_name = element1.stringValue();
          if (method_name == "position_menu" && element0.isObject()) {
            // Check if it's a GtkStatusIcon object
            GtkStatusIcon_ *status_icon_test =
                dynamic_cast<GtkStatusIcon_ *>(element0.implementation());
            if (status_icon_test) {
              // Use the direct GTK function instead of PHP callback
              callback_object->use_gtk_status_icon_position = true;
              callback_object->user_data = element0;  // The status icon object
            }
          }
        }
      }
    }

    // Check if user_data is provided (parameter 3) - only if not using special gtk function
    if (!callback_object->use_gtk_status_icon_position && parameters.size() > 3 &&
        !parameters[3].isNull()) {
      callback_object->user_data = parameters[3];
    }

    // Set the C callback function and user data
    func = popup_position_callback;
    data = static_cast<gpointer>(callback_object);
  }

  // Button number (parameter 4)
  if (parameters.size() > 4) {
    button = (int)parameters[4];
  }

  // Activate time (parameter 5)
  if (parameters.size() > 5) {
    activate_time = (int)parameters[5];
  }

  // Call gtk_menu_popup
  // Note: gtk_menu_popup is deprecated since GTK 3.22, but still available in GTK 3.24
  // The callback data is managed by GObject and will be freed when no longer needed
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  gtk_menu_popup(GTK_MENU(instance), parent_menu_shell, parent_menu_item, func, data, button,
                 activate_time);
  G_GNUC_END_IGNORE_DEPRECATIONS

  // Attach or clear callback data on the menu with automatic cleanup.
  // Calling g_object_set_data_full() again on the same key ensures any
  // previously-attached data is destroyed. When callback_object is NULL,
  // the key is removed and the old data (if any) is freed.
  g_object_set_data_full(G_OBJECT(instance), "php-gtk-popup-callback", callback_object,
                         callback_object ? popup_callback_destroy : NULL);
}

void GtkMenu_::set_accel_group(Php::Parameters &parameters) {
  // GtkAccelGroup *accel_group;
  // if(parameters.size() > 0) {
  // 	Php::Value object_accel_group = parameters[0];
  // 	GtkAccelGroup_ *phpgtk_accel_group = (GtkAccelGroup_ *)object_accel_group.implementation();
  // 	accel_group = GTK_WIDGET(phpgtk_accel_group->get_instance());
  // }

  // gtk_menu_set_accel_group (GTK_MENU(instance), accel_group);

  throw Php::Exception("GtkMenu_::set_accel_group not implemented");
}

Php::Value GtkMenu_::get_accel_group() {
  // GtkAccelGroup *ret = gtk_menu_get_accel_group (GTK_MENU(instance));

  // GtkAccelGroup_ *return_parsed = new GtkAccelGroup_();
  // return_parsed->set_instance((gpointer *)ret);
  // return Php::Object("GtkAccelGroup", return_parsed);

  throw Php::Exception("GtkMenu_::get_accel_group not implemented");
}

void GtkMenu_::set_accel_path(Php::Parameters &parameters) {
  std::string s_accel_path = parameters[0];
  gchar *accel_path = (gchar *)s_accel_path.c_str();

  gtk_menu_set_accel_path(GTK_MENU(instance), accel_path);
}

Php::Value GtkMenu_::get_accel_path() {
  std::string ret = gtk_menu_get_accel_path(GTK_MENU(instance));

  return ret;
}

void GtkMenu_::set_monitor(Php::Parameters &parameters) {
  gint monitor_num = (gint)parameters[0];

  gtk_menu_set_monitor(GTK_MENU(instance), monitor_num);
}

Php::Value GtkMenu_::get_monitor() {
  gint ret = gtk_menu_get_monitor(GTK_MENU(instance));

  return ret;
}

void GtkMenu_::place_on_monitor(Php::Parameters &parameters) {
  // GdkMonitor *monitor;
  // if(parameters.size() > 0) {
  // 	Php::Value object_monitor = parameters[0];
  // 	GdkMonitor_ *phpgtk_monitor = (GdkMonitor_ *)object_monitor.implementation();
  // 	monitor = GTK_WIDGET(phpgtk_monitor->get_instance());
  // }

  // gtk_menu_place_on_monitor (GTK_MENU(instance), monitor);

  throw Php::Exception("GtkMenu_::place_on_monitor not implemented");
}

void GtkMenu_::set_reserve_toggle_size(Php::Parameters &parameters) {
  gboolean reserve_toggle_size = (gboolean)parameters[0];

  gtk_menu_set_reserve_toggle_size(GTK_MENU(instance), reserve_toggle_size);
}

Php::Value GtkMenu_::get_reserve_toggle_size() {
  bool ret = gtk_menu_get_reserve_toggle_size(GTK_MENU(instance));

  return ret;
}

void GtkMenu_::popdown() {
  gtk_menu_popdown(GTK_MENU(instance));
}

void GtkMenu_::reposition() {
  gtk_menu_reposition(GTK_MENU(instance));
}

Php::Value GtkMenu_::get_active() {
  gpointer *ret = (gpointer *)gtk_menu_get_active(GTK_MENU(instance));

  // GtkWidget_ *return_parsed = new GtkWidget_();
  // return_parsed->set_instance((gpointer *)ret);
  // return Php::Object("GtkWidget", return_parsed);

  return cobject_to_phpobject(ret);
}

void GtkMenu_::set_active(Php::Parameters &parameters) {
  guint index = (int)parameters[0];

  gtk_menu_set_active(GTK_MENU(instance), index);
}

void GtkMenu_::attach_to_widget(Php::Parameters &parameters) {
  // GtkWidget *attach_widget;
  // if(parameters.size() > 0) {
  // 	Php::Value object_attach_widget = parameters[0];
  // 	GtkWidget_ *phpgtk_attach_widget = (GtkWidget_ *)object_attach_widget.implementation();
  // 	attach_widget = GTK_WIDGET(phpgtk_attach_widget->get_instance());
  // }

  // GtkMenuDetachFunc *detacher;
  // if(parameters.size() > 1) {
  // 	Php::Value object_detacher = parameters[1];
  // 	GtkMenuDetachFunc_ *phpgtk_detacher = (GtkMenuDetachFunc_
  // *)object_detacher.implementation(); 	detacher = GTK_WIDGET(phpgtk_detacher->get_instance());
  // }

  // gtk_menu_attach_to_widget (GTK_MENU(instance), attach_widget, detacher);

  throw Php::Exception("GtkMenu_::attach_to_widget not implemented");
}

void GtkMenu_::detach() {
  gtk_menu_detach(GTK_MENU(instance));
}

Php::Value GtkMenu_::get_attach_widget() {
  gpointer *ret = (gpointer *)gtk_menu_get_attach_widget(GTK_MENU(instance));

  // GtkWidget_ *return_parsed = new GtkWidget_();
  // return_parsed->set_instance((gpointer *)ret);
  // return Php::Object("GtkWidget", return_parsed);
  return cobject_to_phpobject(ret);
}

Php::Value GtkMenu_::get_for_attach_widget() {
  // GList ret = gtk_menu_get_for_attach_widget (GTK_MENU(instance));

  // return ret;

  throw Php::Exception("GtkMenu_::get_for_attach_widget not implemented");
}
