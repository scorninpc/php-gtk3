
#include "php-gtk.h"

bool phpgtk_check_parameter(Php::Parameters &parameters, int param, Php::Type expected_type, bool required, const char *object_type)
{
	
	int param_count = parameters.size();

	if(required) {
		
		// ----
		if(param_count < param) {
			throw Php::Exception("parametro obrigatório");
		}

		// Test boolean individually cause True and False are different types
		if((expected_type == Php::Type::Bool) && 
				((parameters[param-1].type() == Php::Type::True) || (parameters[param-1].type() == Php::Type::False)))  {
			return true;
		}

		// Text Object type
		if((expected_type == Php::Type::Object) && (!Php::is_a(parameters[param-1], object_type))) {
			throw Php::Exception(phpgtk_wrong_type_message(param, parameters[param-1].type(), expected_type));
		}

		// ----
		if(parameters[param-1].type() != expected_type) {
			throw Php::Exception("asd");
		}

	}
	else {
		
		// ----
		if(param_count < param) {
			return false;
		}

		// Test boolean individually cause True and False are different types
		if((expected_type == Php::Type::Bool) && 
				((parameters[param-1].type() == Php::Type::True) || (parameters[param-1].type() == Php::Type::False)))  {
			return true;
		}

		// ----
		if(parameters[param-1].type() != expected_type) {
			Php::warning << phpgtk_wrong_type_message(param, Php::Type::Numeric, Php::Type::Bool) << std::flush;
			return false;
		}

		// Text Object type
		if((expected_type == Php::Type::Object) && (!Php::is_a(parameters[param-1], object_type))) {
			Php::warning << "parametro nao obrigatório do tipo invalido" << std::flush;
			return false;
		}
	}

	return true;
}


/**
 *
 */
char *phpgtk_wrong_type_message(int param, Php::Type type_passed, Php::Type type_expected)
{
	char *buffer;
	int len;
	
	// Get len of string
	len = snprintf(NULL, 0, "Expected parameter %d to be an %s, %s given", param, phpgtk_type_to_string(type_expected).c_str(), phpgtk_type_to_string(type_passed).c_str());
	buffer = (char *)malloc((len + 1) * sizeof(char));
	
	// Save into buffer
	snprintf(buffer, len+1, "Expected parameter %d to be an %s, %s given", param, phpgtk_type_to_string(type_expected).c_str(), phpgtk_type_to_string(type_passed).c_str());

	Php::call("var_dump", phpgtk_type_to_string(type_passed).c_str());
	Php::call("var_dump", phpgtk_type_to_string(type_expected).c_str());

	// throw
	return buffer;
}

/**
 *
 */
std::string phpgtk_type_to_string(Php::Type type)
{
	std::string str_type;

	switch(type) {
		case Php::Type::Undefined: str_type.assign("undefined"); break;
		case Php::Type::Null: str_type.assign("null"); break;
		case Php::Type::False: str_type.assign("false"); break;
		case Php::Type::True: str_type.assign("true"); break;
		case Php::Type::Numeric: str_type.assign("numeric"); break;
		case Php::Type::Float: str_type.assign("float"); break;
		case Php::Type::String: str_type.assign("string"); break;
		case Php::Type::Array: str_type.assign("array"); break;
		case Php::Type::Object: str_type.assign("object"); break;
		case Php::Type::Resource: str_type.assign("resource"); break;
		case Php::Type::Reference: str_type.assign("reference"); break;
		case Php::Type::Constant: str_type.assign("constant"); break;
		case Php::Type::ConstantAST: str_type.assign("constantAST"); break;
		case Php::Type::Bool: str_type.assign("bool"); break;
		case Php::Type::Callable: str_type.assign("callable"); break;
	}

	return str_type;
}

Php::Value cobject_to_phpobject(gpointer *cobject)
{
	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)cobject);
	return Php::Object(g_type_name(G_TYPE_FROM_INSTANCE((gpointer *)cobject)), return_parsed);
}