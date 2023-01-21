
#ifndef _PHPGTK_GTKEVENTBOX_H_
#define _PHPGTK_GTKEVENTBOX_H_

	#include <phpcpp.h>
	#include <gtk/gtk.h>

	#include "GtkBin.h"

	class GtkEventBox_ : public GtkBin_
	{
		public:
			GtkEventBox_();
			~GtkEventBox_();

			void __construct();

			Php::Value get_visible_window();

			void set_visible_window(Php::Parameters &parameters);

			Php::Value get_above_child();

			void set_above_child(Php::Parameters &parameters);
	};

#endif