#ifndef _PHPGTK_H_
#define _PHPGTK_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>


	bool phpgtk_check_parameter(Php::Value value, Php::Type expected_type, bool required);


#endif