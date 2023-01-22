

#ifndef _PHPGTK_GTKSEPARATOR_H_
#define _PHPGTK_GTKSEPARATOR_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkWidget.h"

	class GtkSeparator_ : public GtkWidget_
    {
		public:
			GtkSeparator_();
			~GtkSeparator_();

			void __construct(Php::Parameters &parameters);


	};

#endif