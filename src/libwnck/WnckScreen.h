
#ifndef _PHPGTK_WNCKSCREEN_H_
#define _PHPGTK_WNCKSCREEN_H_

	#include <phpcpp.h>
	#include <libwnck/libwnck.h>

	#include "../G/GObject.h"
	#include "WnckWindow.h"

	/**
	 *  
	 */
	class WnckScreen_ : public GObject_
	{
		/**
		 * Publics
		 */
		public:
			/**
			 *  C++ constructor/destructor
			 */
			WnckScreen_();
			~WnckScreen_();

			static Php::Value get_default();
			Php::Value get_active_window();
			Php::Value get_width();
			Php::Value get_height();
	};

#endif