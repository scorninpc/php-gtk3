
#ifndef _PHPGTK_GTK_H_
#define _PHPGTK_GTK_H_

	#include <phpcpp.h>
	#include <iostream>
	#include <gtk/gtk.h>

	/**
	 *  
	 */
	class Gtk_ : public Php::Base
	{
		/**
		 * Privates
		 */
		private:
			/**
			 * 
			 */
			GtkWidget *widget;

		/**
		 * Publics
		 */
		public:
			/**
			 *  C++ constructor/destructor
			 */
			Gtk_();

			/**
			 * Gtk loop
			 *		https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-main
			 */
			static void main();

			/**
			 * Gtk main quit
			 *		https://developer.gnome.org/gtk3/stable/gtk3-General.html#gtk-main-quit
			 */
			static void main_quit();
	};

#endif