
#ifndef _PHPGTK_GDK_H_
#define _PHPGTK_GDK_H_

	#include <phpcpp.h>
	#include <iostream>
	#include <gtk/gtk.h>

	#include "GdkWindow.h"

	/**
	 *  
	 */
	class Gdk_ : public Php::Base
	{
		/**
		 * Publics
		 */
		public:
			/**
			 *  C++ constructor/destructor
			 */
			Gdk_();
			virtual ~Gdk_();

			static Php::Value test_simulate_button(Php::Parameters &parameters);
	};

#endif