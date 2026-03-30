

#include "GtkStatusIcon.h"
#include "GtkLogSuppression.h"

GtkStatusIcon_::GtkStatusIcon_() = default;
GtkStatusIcon_::~GtkStatusIcon_() = default;

/**
 * Helper function to detect if running on Wayland backend
 * GtkStatusIcon only works on X11, not on Wayland
 */
static bool is_wayland_backend()
{
	GdkDisplay *display = gdk_display_get_default();
	if (!display) {
		return false;
	}
	
	// Check if the display is a Wayland display
	// GDK_IS_WAYLAND_DISPLAY is available when compiled with Wayland support
	#ifdef GDK_WINDOWING_WAYLAND
	const char *backend = G_OBJECT_TYPE_NAME(display);
	return (backend && g_str_has_prefix(backend, "GdkWayland"));
	#else
	return false;
	#endif
}

/**
 * Emit a warning about GtkStatusIcon limitations on Wayland
 */
static void warn_if_wayland()
{
	static bool warning_shown = false;
	
	if (!warning_shown && is_wayland_backend()) {
		warning_shown = true;
		Php::warning << "GtkStatusIcon is deprecated and does not work on Wayland. "
		            << "The system tray icon will not be visible. "
		            << "Possible workarounds: "
		            << "(1) Set GDK_BACKEND=x11 to force X11 compatibility mode, or "
		            << "(2) Use a desktop environment that supports XEmbed system tray protocol."
		            << std::flush;
	}
}

void GtkStatusIcon_::set_from_pixbuf(Php::Parameters &parameters)
{
	GdkPixbuf *pixbuf;
	Php::Value object_pixbuf = parameters[0];
	GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
	pixbuf = GDK_PIXBUF(phpgtk_pixbuf->get_instance());

	// GTK internally calls gtk_widget_get_scale_factor on GtkStatusIcon during icon loading,
	// which triggers an assertion since GtkStatusIcon is not a GtkWidget
	GtkLogSuppressor suppressor;
	gtk_status_icon_set_from_pixbuf(GTK_STATUS_ICON(instance), pixbuf);
}

void GtkStatusIcon_::set_from_file(Php::Parameters &parameters)
{
	std::string c_filename = parameters[0];
	gchar *filename = (gchar *)c_filename.c_str();

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	gtk_status_icon_set_from_file(GTK_STATUS_ICON(instance), filename);
}

void GtkStatusIcon_::set_from_stock(Php::Parameters &parameters)
{
	std::string c_stock_id = parameters[0];
	gchar *stock_id = (gchar *)c_stock_id.c_str();

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	gtk_status_icon_set_from_stock(GTK_STATUS_ICON(instance), stock_id);
}

void GtkStatusIcon_::set_from_icon_name(Php::Parameters &parameters)
{
	std::string c_icon_name = parameters[0];
	gchar *icon_name = (gchar *)c_icon_name.c_str();

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	gtk_status_icon_set_from_icon_name(GTK_STATUS_ICON(instance), icon_name);
}

void GtkStatusIcon_::set_from_gicon(Php::Parameters &parameters)
{
	GIcon *gicon;
	Php::Value object_gicon = parameters[0];
	GIcon_ *phpgtk_gicon = (GIcon_ *)object_gicon.implementation();
	gicon = phpgtk_gicon->get_instance();

	// Suppress GTK 3 scale factor warnings during icon loading via GIcon
	GtkLogSuppressor suppressor;
	gtk_status_icon_set_from_gicon(GTK_STATUS_ICON(instance), gicon);
}

/*
Php::Value GtkStatusIcon_::get_storage_type()
{
	// GtkImageType ret = gtk_status_icon_get_storage_type(GTK_STATUS_ICON(instance));

	// GtkImageType_ *phpgtk_ret = new GtkImageType_();
	// phpgtk_ret->set_instance((gpointer *)ret);
	// return Php::Object("GtkImageType", phpgtk_ret);
}
*/

Php::Value GtkStatusIcon_::get_pixbuf()
{
	GdkPixbuf *ret = gtk_status_icon_get_pixbuf(GTK_STATUS_ICON(instance));

	GdkPixbuf_ *phpgtk_ret = new GdkPixbuf_();
	phpgtk_ret->set_instance(ret);
	return Php::Object("GdkPixbuf", phpgtk_ret);
}

Php::Value GtkStatusIcon_::get_stock()
{
	const gchar *ret = gtk_status_icon_get_stock(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_icon_name()
{
	const gchar *ret = gtk_status_icon_get_icon_name(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_gicon()
{
	GIcon *ret = gtk_status_icon_get_gicon(GTK_STATUS_ICON(instance));

	if (ret == nullptr)
	{
		return Php::Value(nullptr);
	}

	// Note: gtk_status_icon_get_gicon() returns a borrowed reference owned by the status icon.
	// The GIcon_ wrapper takes its own reference via set_instance(), so it can safely outlive the status icon.
	// However, its contents may become stale if the status icon's GIcon is changed later.
	GIcon_ *phpgtk_ret = new GIcon_();
	phpgtk_ret->set_instance(ret);
	return Php::Object("GIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::get_size()
{
	gint ret = gtk_status_icon_get_size(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_screen()
{
	GdkScreen *ret = gtk_status_icon_get_screen(GTK_STATUS_ICON(instance));

	GdkScreen_ *phpgtk_ret = new GdkScreen_();
	phpgtk_ret->set_instance(ret);
	return Php::Object("GdkScreen", phpgtk_ret);
}

void GtkStatusIcon_::set_has_tooltip(Php::Parameters &parameters)
{
	gboolean has_tooltip = (gboolean)parameters[0];

	gtk_status_icon_set_has_tooltip(GTK_STATUS_ICON(instance), has_tooltip);
}

void GtkStatusIcon_::set_tooltip_text(Php::Parameters &parameters)
{
	std::string c_text = parameters[0];

	gchar *text = (gchar *)c_text.c_str();

	gtk_status_icon_set_tooltip_text(GTK_STATUS_ICON(instance), text);
}

void GtkStatusIcon_::set_tooltip_markup(Php::Parameters &parameters)
{
	std::string c_markup = parameters[0];

	gchar *markup = (gchar *)c_markup.c_str();

	gtk_status_icon_set_tooltip_markup(GTK_STATUS_ICON(instance), markup);
}

void GtkStatusIcon_::set_title(Php::Parameters &parameters)
{
	std::string c_title = parameters[0];

	gchar *title = (gchar *)c_title.c_str();

	gtk_status_icon_set_title(GTK_STATUS_ICON(instance), title);
}

Php::Value GtkStatusIcon_::get_title()
{
	const gchar *ret = gtk_status_icon_get_title(GTK_STATUS_ICON(instance));

	return ret;
}

void GtkStatusIcon_::set_name(Php::Parameters &parameters)
{
	std::string c_name = parameters[0];

	gchar *name = (gchar *)c_name.c_str();

	gtk_status_icon_set_name(GTK_STATUS_ICON(instance), name);
}

void GtkStatusIcon_::set_visible(Php::Parameters &parameters)
{
	gboolean visible = (gboolean)parameters[0];

	gtk_status_icon_set_visible(GTK_STATUS_ICON(instance), visible);
}

Php::Value GtkStatusIcon_::get_visible()
{
	bool ret = gtk_status_icon_get_visible(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::is_embedded()
{
	bool ret = gtk_status_icon_is_embedded(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_has_tooltip()
{
	bool ret = gtk_status_icon_get_has_tooltip(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_tooltip_text()
{
	gchar *ret = gtk_status_icon_get_tooltip_text(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_tooltip_markup()
{
	gchar *ret = gtk_status_icon_get_tooltip_markup(GTK_STATUS_ICON(instance));

	return ret;
}

/*
Php::Value GtkStatusIcon_::get_x11_window_id()
{
	// guint32 ret = gtk_status_icon_get_x11_window_id(GTK_STATUS_ICON(instance));

	// guint32_ *phpgtk_ret = new guint32_();
	// phpgtk_ret->set_instance((gpointer *)ret);
	// return Php::Object("guint32", phpgtk_ret);
}
*/

void GtkStatusIcon_::__construct()
{
	warn_if_wayland();
	instance = (gpointer *)gtk_status_icon_new();
}

Php::Value GtkStatusIcon_::new_from_pixbuf(Php::Parameters &parameters)
{
	warn_if_wayland();
	
	GdkPixbuf *pixbuf;
	Php::Value object_pixbuf = parameters[0];
	GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
	pixbuf = GDK_PIXBUF(phpgtk_pixbuf->get_instance());

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	GtkStatusIcon *ret = gtk_status_icon_new_from_pixbuf(pixbuf);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::new_from_file(Php::Parameters &parameters)
{
	warn_if_wayland();
	
	std::string c_filename = parameters[0];
	gchar *filename = (gchar *)c_filename.c_str();

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	GtkStatusIcon *ret = gtk_status_icon_new_from_file(filename);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::new_from_stock(Php::Parameters &parameters)
{
	warn_if_wayland();
	
	std::string c_stock_id = parameters[0];
	gchar *stock_id = (gchar *)c_stock_id.c_str();

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	GtkStatusIcon *ret = gtk_status_icon_new_from_stock(stock_id);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::new_from_icon_name(Php::Parameters &parameters)
{
	warn_if_wayland();
	
	std::string c_icon_name = parameters[0];
	gchar *icon_name = (gchar *)c_icon_name.c_str();

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	GtkStatusIcon *ret = gtk_status_icon_new_from_icon_name(icon_name);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::new_from_gicon(Php::Parameters &parameters)
{
	warn_if_wayland();
	
	GIcon *gicon;
	Php::Value object_gicon = parameters[0];
	GIcon_ *phpgtk_gicon = (GIcon_ *)object_gicon.implementation();
	gicon = phpgtk_gicon->get_instance();

	// Suppress GTK 3 scale factor warnings during icon loading
	GtkLogSuppressor suppressor;
	GtkStatusIcon *ret = gtk_status_icon_new_from_gicon(gicon);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::position_menu(Php::Parameters &parameters)
{
	GtkMenu *menu;
	Php::Value object_menu = parameters[0];
	GtkMenu_ *phpgtk_menu = (GtkMenu_ *)object_menu.implementation();
	menu = GTK_MENU(phpgtk_menu->get_instance());

	// Use stack variables and pass their addresses to gtk_status_icon_position_menu
	gint x = 0;
	gint y = 0;
	gboolean push_in = FALSE;

	gtk_status_icon_position_menu(menu, &x, &y, &push_in, GTK_STATUS_ICON(instance));

	// Return the computed coordinates as a PHP array
	Php::Value arr;
	arr["x"] = x;
	arr["y"] = y;
	arr["push_in"] = (bool)push_in;

	return arr;
}

void GtkStatusIcon_::set_blinking(Php::Parameters &parameters)
{
	(void)parameters;  // Mark as intentionally unused
	throw Php::Exception("GtkStatusIcon::set_blinking is not available in GTK 3. This function was removed in GTK 3.14. Consider using a timer to alternate icons for a blinking effect.");
}

Php::Value GtkStatusIcon_::get_blinking()
{
	throw Php::Exception("GtkStatusIcon::get_blinking is not available in GTK 3. This function was removed in GTK 3.14.");
}
