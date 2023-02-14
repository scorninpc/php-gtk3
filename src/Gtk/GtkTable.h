#ifndef _PHPGTK_GTKTABLE_H_
#define _PHPGTK_GTKTABLE_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>
    
	#include "../../php-gtk.h"

	#include "GtkContainer.h"


	class GtkTable_ : public GtkContainer_
    {
		public:
			GtkTable_();
			~GtkTable_();
			
			void resize(Php::Parameters &parameters);
			void attach(Php::Parameters &parameters);
			void attach_defaults(Php::Parameters &parameters);
			void set_row_spacing(Php::Parameters &parameters);
			Php::Value get_row_spacing(Php::Parameters &parameters);
			void set_col_spacing(Php::Parameters &parameters);
			Php::Value get_col_spacing(Php::Parameters &parameters);
			void set_row_spacings(Php::Parameters &parameters);
			Php::Value get_default_row_spacing();
			void set_col_spacings(Php::Parameters &parameters);
			Php::Value get_default_col_spacing();
			void set_homogeneous(Php::Parameters &parameters);
			Php::Value get_homogeneous();
			Php::Value get_size(Php::Parameters &parameters);
			void __construct(Php::Parameters &parameters);

	};

#endif