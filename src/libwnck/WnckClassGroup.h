
#ifndef _PHPGTK_WNCKCLASSGROUP_H_
#define _PHPGTK_WNCKCLASSGROUP_H_

	#include <phpcpp.h>
	#include <libwnck/libwnck.h>

	#include "../G/GObject.h"
	#include "../Gdk/GdkPixbuf.h"
	#include "WnckWindow.h"

	/**
	 *  
	 */
	class WnckClassGroup_ : public GObject_
	{
		/**
		 * Publics
		 */
		public:
			/**
			 *  C++ constructor/destructor
			 */
			WnckClassGroup_();
			~WnckClassGroup_();

			Php::Value get_id();
			Php::Value get_name();
			Php::Value get_icon();
			Php::Value get_mini_icon();
			Php::Value get_windows();
	};

#endif