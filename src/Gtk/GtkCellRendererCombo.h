#ifndef _PHPGTK_GTKCELLRENDERERCOMBO_H_
#define _PHPGTK_GTKCELLRENDERERCOMBO_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>
    
	#include "GtkCellRendererText.h"


	class GtkCellRendererCombo_ : public GtkCellRendererText_
    {
		public:
			GtkCellRendererCombo_();
			~GtkCellRendererCombo_();
			
			void __construct();

	};

#endif