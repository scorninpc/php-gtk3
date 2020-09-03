
#ifndef _PHPGTK_WNCKSCREEN_H_
#define _PHPGTK_WNCKSCREEN_H_

	#include <phpcpp.h>
	#include <libwnck/libwnck.h>

	#include "../G/GObject.h"

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

			static Php::Value test(Php::Parameters &parameters);
	};

#endif