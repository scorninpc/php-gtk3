
#include "Gdk.h"
#include "../../php-gtk.h"

/**
 *  
 */
Gdk_::Gdk_() = default;
Gdk_::~Gdk_() = default;

/**
 * https://developer.gnome.org/gdk3/stable/gdk3-Testing.html#gdk-test-simulate-button
 */
Php::Value Gdk_::test_simulate_button(Php::Parameters &parameters)
{
	bool check;

	// ---
	phpgtk_check_parameter(parameters, 1, Php::Type::Object, TRUE, "GdkWindow");
	GdkWindow *window;
	if(parameters.size() > 0) {
		Php::Value object_window = parameters[0];
		GdkWindow_ *phpgtk_window = (GdkWindow_ *)object_window.implementation();
		window = GDK_WINDOW(phpgtk_window->get_instance());
	}

	// ---
	check = phpgtk_check_parameter(parameters, 2, Php::Type::Numeric, FALSE, NULL);
	gint x = 0;
	if(check) {
		x = (int)parameters[1];
	}

	// ---
	check = phpgtk_check_parameter(parameters, 3, Php::Type::Numeric, FALSE, NULL);
	gint y = 0;
	if(check) {
		y = (int)parameters[2];
	}

	// ---
	check = phpgtk_check_parameter(parameters, 4, Php::Type::Numeric, FALSE, NULL);
	gint button = 0;
	if(check) {
		button = (int)parameters[3];
	}

	// ---
	check = phpgtk_check_parameter(parameters, 5, Php::Type::Numeric, FALSE, NULL);
	GdkModifierType modifiers = GDK_BUTTON1_MASK;
	if(check) {
		int phpgtk_modifiers = (int)parameters[4];
		modifiers = (GdkModifierType)phpgtk_modifiers;
	}

	// ---
	check = phpgtk_check_parameter(parameters, 6, Php::Type::Numeric, FALSE, NULL);
	GdkEventType button_pressrelease = GDK_BUTTON_PRESS;
	if(check) {
		int phpgtk_button_pressrelease = (int)parameters[4];
		button_pressrelease = (GdkEventType)phpgtk_button_pressrelease;
	}

	// Move the cursor
	GdkDevice *device = gdk_device_manager_get_client_pointer(gdk_display_get_device_manager(gdk_display_get_default()));
	GdkScreen *screen = gdk_screen_get_default();
	gdk_device_warp (device, screen, x, y);

	// 
	gdk_test_simulate_button(window, x, y, button, modifiers, button_pressrelease);

	return 1;
}