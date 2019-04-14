#include <phpcpp.h>
#include <iostream>

#include <gtk/gtk.h>

/**
 *  
 */
class Gtk_ : public Php::Base
{
	private:
		GtkWidget *widget;

	public:
		/**
		 *  C++ constructor
		 */
		Gtk_() = default;

		/**
		 * Gtk loop
		 *		https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-main
		 */
		static void main()
		{
			gtk_main();
		}

		/**
		 * Gtk main quit
		 *		https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-main-quit
		 */
		static void main_quit()
		{
			gtk_main_quit();
		}
};