
#include "php-gtk.h"

bool phpgtk_check_parameter(Php::Value value, Php::Type expected_type, bool required)
{
	Php::call("var_dump", "OK1");
	if(required) {
		Php::call("var_dump", "OK2");
		if(value.type() == Php::Type::Null) {
			Php::call("var_dump", "OK3");
			throw Php::Exception("tipo errado");
		}
		Php::call("var_dump", "OK4");
	}

}