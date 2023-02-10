

#ifndef _PHPGTK_GTKALIGNMENT_H_
#define _PHPGTK_GTKALIGNMENT_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkBin.h"

	class GtkAlignment_ : public GtkBin_
    {
		public:
			GtkAlignment_();
			~GtkAlignment_();

			void set(Php::Parameters &parameters);
			void set_padding(Php::Parameters &parameters);
			Php::Value get_padding();
			void __construct(Php::Parameters &parameters);

			Php::Value get_child();

	};

#endif