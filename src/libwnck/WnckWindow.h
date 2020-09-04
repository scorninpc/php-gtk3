
#ifndef _PHPGTK_WNCKWINDOW_H_
#define _PHPGTK_WNCKWINDOW_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>
    #include <gdk/gdk.h>
	#include <libwnck/libwnck.h>

	#include "../G/GObject.h"
	#include "../Gdk/GdkPixbuf.h"
	#include "WnckClassGroup.h"

	/**
	 *  
	 */
	class WnckWindow_ : public GObject_
	{
		/**
		 * Publics
		 */
		public:
			/**
			 *  C++ constructor/destructor
			 */
			WnckWindow_();
			~WnckWindow_();

			static Php::Value get_window(Php::Parameters &parameters);
			Php::Value get_name();
			Php::Value get_icon();
			Php::Value get_window_type();
			Php::Value get_xid();
			Php::Value get_pid();
			Php::Value get_class_group();
			Php::Value is_active();
			void minimize();
			void activate(Php::Parameters &parameters);
	};

#endif