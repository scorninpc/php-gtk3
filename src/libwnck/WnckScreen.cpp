
#include "WnckScreen.h"

/**
 *  
 */
/**
 * Constructor
 */
WnckScreen_::WnckScreen_() = default;

/**
 * Destructor
 */
WnckScreen_::~WnckScreen_() = default;

/**
 * https://developer.gnome.org/gdk3/stable/gdk3-Testing.html#gdk-test-simulate-button
 */
Php::Value WnckScreen_::test(Php::Parameters &parameters)
{
	GMainLoop *loop;
  WnckScreen *ret;
  
	// loop = g_main_loop_new (NULL, FALSE);


  ret = wnck_screen_get_default ();

	// g_signal_connect (screen, "window-opened",
 //             G_CALLBACK (on_window_opened), NULL);
 //  g_signal_connect (screen, "active-window-changed",
 //             G_CALLBACK (on_active_window_changed), NULL);

	// Create the PHP-GTK object and set GTK object
  WnckScreen_ *widget_ = new WnckScreen_();
  widget_->set_instance((gpointer *)ret);
  return Php::Object("WnckScreen", widget_);
}