
#ifndef _PHPGTK_GTKWINDOW_H_
#define _PHPGTK_GTKWINDOW_H_

	#include <phpcpp.h>
	#include <iostream>
	#include <gtk/gtk.h>

	#include "GtkWidget.h"

	/**
	 *  
	 */
	class GtkWindow_ : public GtkWidget_
	{
		
		/**
		 * Publics
		 */
		public:
			/**
			 * C++ constructor/destructor
			 * https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-new
			 */
			GtkWindow_();
	};

#endif