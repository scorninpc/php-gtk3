#ifndef _PHPGTK_H_
#define _PHPGTK_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>


	bool phpgtk_check_parameter(Php::Parameters &parameters, int param, Php::Type expected_type, bool required, const char *object_type);
	char *phpgtk_wrong_type_message(int param, Php::Type type_passed, Php::Type type_expected);
	std::string phpgtk_type_to_string(Php::Type type);


#endif