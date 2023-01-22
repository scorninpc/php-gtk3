

#ifndef _PHPGTK_GTKTREESORTABLE_H_
#define _PHPGTK_GTKTREESORTABLE_H_

	#include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"

	class GtkTreeSortable_ : public GObject_
    {
		public:
			GtkTreeSortable_();
			~GtkTreeSortable_();

			void sort_column_changed();
			Php::Value get_sort_column_id(Php::Parameters &parameters);
			void set_sort_column_id(Php::Parameters &parameters);
			Php::Value has_default_sort_func();


	};

#endif