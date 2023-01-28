

#ifndef _PHPGTK_GTKAPPLICATIONWINDOW_H_
#define _PHPGTK_GTKAPPLICATIONWINDOW_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>
    
	#include "GtkWindow.h"
	#include "../../php-gtk.h"

	

	class GtkApplicationWindow_ : public GtkWindow_
    {
		public:
			GtkApplicationWindow_();
			~GtkApplicationWindow_();

			void set_show_menubar(Php::Parameters &parameters);
			Php::Value get_show_menubar();


	};

#endif