

#ifndef _PHPGTK_GTKVIEWPORT_H_
#define _PHPGTK_GTKVIEWPORT_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>
    
	#include "../../php-gtk.h"
	#include "GtkBin.h"
	

	class GtkViewport_ : public GtkBin_
    {
		public:
			GtkViewport_();
			~GtkViewport_();

			Php::Value get_hadjustment();
			Php::Value get_vadjustment();
			void set_hadjustment(Php::Parameters &parameters);
			void set_vadjustment(Php::Parameters &parameters);
			void set_shadow_type(Php::Parameters &parameters);
			Php::Value get_shadow_type();
			Php::Value get_bin_window();
			Php::Value get_view_window();
			void __construct(Php::Parameters &parameters);


	};

#endif