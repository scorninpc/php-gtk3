#ifndef _PHPGTK_H_
#define _PHPGTK_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>
    
	#include "src/Gtk/GtkWidget.h"


	bool phpgtk_check_parameter(Php::Parameters &parameters, int param, Php::Type expected_type, bool required, const char *object_type);
	char *phpgtk_wrong_type_message(int param, Php::Type type_passed, Php::Type type_expected);
	std::string phpgtk_type_to_string(Php::Type type);
	Php::Value cobject_to_phpobject(gpointer *cobject);

	/**
	 * Struct for generic callback
	 */
	struct generic_st_callback {
		Php::Value callback_name;
		Php::Object self_widget;
		Php::Parameters parameters;

		GType return_type;
		int n_params;
		GType *param_types;
	};

	void generic_callback(gpointer *self, ...);


#endif