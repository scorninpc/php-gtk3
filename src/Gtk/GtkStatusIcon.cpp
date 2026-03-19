

#include "GtkStatusIcon.h"

// Custom log handler to suppress GTK 3 bug with gtk_widget_get_scale_factor
// When loading icons from files, GTK internally calls gtk_widget_get_scale_factor
// on the GtkStatusIcon, which is not a GtkWidget, causing a critical warning
// This is a known GTK 3 issue and the warning is harmless
static void suppress_scale_factor_warning(const gchar *log_domain,
                                         GLogLevelFlags log_level,
                                         const gchar *message,
                                         gpointer user_data)
{
	(void)log_domain;
	(void)log_level;
	(void)user_data;
	
	// Suppress the specific gtk_widget_get_scale_factor warning for GtkStatusIcon
	// Expected message format: "gtk_widget_get_scale_factor: assertion 'GTK_IS_WIDGET (widget)' failed"
	// String matching is necessary as GTK doesn't provide error codes for log messages
	if (g_strstr_len(message, -1, "gtk_widget_get_scale_factor") &&
	    g_strstr_len(message, -1, "GTK_IS_WIDGET")) {
		// Silently ignore this specific warning
		return;
	}
	
	// For all other messages, use default handler
	g_log_default_handler(log_domain, log_level, message, user_data);
}

GtkStatusIcon_::GtkStatusIcon_() = default;
GtkStatusIcon_::~GtkStatusIcon_() = default;

void GtkStatusIcon_::set_from_pixbuf(Php::Parameters &parameters)
{
	GdkPixbuf *pixbuf;
	Php::Value object_pixbuf = parameters[0];
	GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
	pixbuf = GDK_PIXBUF(phpgtk_pixbuf->get_instance());

	gtk_status_icon_set_from_pixbuf(GTK_STATUS_ICON(instance), pixbuf);
}

void GtkStatusIcon_::set_from_file(Php::Parameters &parameters)
{
	std::string c_filename = parameters[0];

	gchar *filename = (gchar *)c_filename.c_str();

	gtk_status_icon_set_from_file(GTK_STATUS_ICON(instance), filename);
}

void GtkStatusIcon_::set_from_stock(Php::Parameters &parameters)
{
	std::string c_stock_id = parameters[0];

	gchar *stock_id = (gchar *)c_stock_id.c_str();

	gtk_status_icon_set_from_stock(GTK_STATUS_ICON(instance), stock_id);
}

void GtkStatusIcon_::set_from_icon_name(Php::Parameters &parameters)
{
	std::string c_icon_name = parameters[0];

	gchar *icon_name = (gchar *)c_icon_name.c_str();

	gtk_status_icon_set_from_icon_name(GTK_STATUS_ICON(instance), icon_name);
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
	GdkPixbuf* ret = gtk_status_icon_get_pixbuf(GTK_STATUS_ICON(instance));

	GdkPixbuf_ *phpgtk_ret = new GdkPixbuf_();
	phpgtk_ret->set_instance(ret);
	return Php::Object("GdkPixbuf", phpgtk_ret);
}

Php::Value GtkStatusIcon_::get_stock()
{
	const gchar* ret = gtk_status_icon_get_stock(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_icon_name()
{
	const gchar* ret = gtk_status_icon_get_icon_name(GTK_STATUS_ICON(instance));

	return ret;
}

/*
Php::Value GtkStatusIcon_::get_gicon()
{
	// GIcon* ret = gtk_status_icon_get_gicon(GTK_STATUS_ICON(instance));

	// GIcon*_ *phpgtk_ret = new GIcon*_();
	// phpgtk_ret->set_instance((gpointer *)ret);
	// return Php::Object("GIcon*", phpgtk_ret);
}
*/

Php::Value GtkStatusIcon_::get_size()
{
	gint ret = gtk_status_icon_get_size(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_screen()
{
	GdkScreen* ret = gtk_status_icon_get_screen(GTK_STATUS_ICON(instance));

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
	const gchar* ret = gtk_status_icon_get_title(GTK_STATUS_ICON(instance));

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
	gchar* ret = gtk_status_icon_get_tooltip_text(GTK_STATUS_ICON(instance));

	return ret;
}

Php::Value GtkStatusIcon_::get_tooltip_markup()
{
	gchar* ret = gtk_status_icon_get_tooltip_markup(GTK_STATUS_ICON(instance));

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
	instance = (gpointer *)gtk_status_icon_new();
}

Php::Value GtkStatusIcon_::new_from_pixbuf(Php::Parameters &parameters)
{
	GdkPixbuf *pixbuf;
	Php::Value object_pixbuf = parameters[0];
	GdkPixbuf_ *phpgtk_pixbuf = (GdkPixbuf_ *)object_pixbuf.implementation();
	pixbuf = GDK_PIXBUF(phpgtk_pixbuf->get_instance());

	GtkStatusIcon* ret = gtk_status_icon_new_from_pixbuf(pixbuf);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::new_from_file(Php::Parameters &parameters)
{
	std::string c_filename = parameters[0];

	gchar *filename = (gchar *)c_filename.c_str();

	// Install custom log handler to suppress GTK 3 bug with gtk_widget_get_scale_factor
	// GtkStatusIcon internally calls gtk_widget_get_scale_factor during icon loading,
	// but GtkStatusIcon is not a GtkWidget, causing a harmless critical warning
	guint handler_id = g_log_set_handler("Gtk", 
	                                     G_LOG_LEVEL_CRITICAL,
	                                     suppress_scale_factor_warning,
	                                     NULL);

	GtkStatusIcon* ret = gtk_status_icon_new_from_file(filename);
	
	// Remove the custom log handler
	g_log_remove_handler("Gtk", handler_id);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::new_from_stock(Php::Parameters &parameters)
{
	std::string c_stock_id = parameters[0];

	gchar *stock_id = (gchar *)c_stock_id.c_str();

	GtkStatusIcon* ret = gtk_status_icon_new_from_stock(stock_id);

	GtkStatusIcon_ *phpgtk_ret = new GtkStatusIcon_();
	phpgtk_ret->set_instance((gpointer *)ret);
	return Php::Object("GtkStatusIcon", phpgtk_ret);
}

Php::Value GtkStatusIcon_::new_from_icon_name(Php::Parameters &parameters)
{
	std::string c_icon_name = parameters[0];

	gchar *icon_name = (gchar *)c_icon_name.c_str();

	GtkStatusIcon* ret = gtk_status_icon_new_from_icon_name(icon_name);

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

	gint* x;
	gint* y;
	gboolean *push_in;

	gtk_status_icon_position_menu(menu, x, y, push_in, GTK_STATUS_ICON(instance));

	int64_t ux = (int64_t)&x;
	int64_t uy = (int64_t)&y;

    Php::Value arr;
    arr["x"] = ux;
    arr["y"] = uy;

    return arr;
}




