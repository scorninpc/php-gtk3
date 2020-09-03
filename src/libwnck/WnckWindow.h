
#ifndef _PHPGTK_WNCKWINDOW_H_
#define _PHPGTK_WNCKWINDOW_H_

	#include <phpcpp.h>
	#include <libwnck/libwnck.h>

	#include "../G/GObject.h"
	#include "../Gdk/GdkPixbuf.h"

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

			Php::Value get_name();
			Php::Value get_icon();
			Php::Value get_window_type();
	};

#endif