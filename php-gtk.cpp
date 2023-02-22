
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
	Php::call("echo", buffer);
	//Php::call("var_dump", phpgtk_type_to_string(type_passed).c_str());
	//Php::call("var_dump", phpgtk_type_to_string(type_expected).c_str());

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
	if(cobject == NULL) {
		return NULL;
	}

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)cobject);
	return Php::Object(g_type_name(G_TYPE_FROM_INSTANCE((gpointer *)cobject)), return_parsed);
}




/**
 * generict callback
 * 
 * Assume that all functions pass self widget as first param
 */
void generic_callback(gpointer *self, ...)
{
	/**
	 *  This will loop all vargs after *self, max to 5 times, casting to generic_st_callback 
	 *  	if the generic_st_callback.callback_name is a php land user function, this will be callable, so 
	 *  	we know that this param is the userdata
	 */
	struct generic_st_callback *callback_object;

	va_list ap;
    va_start(ap, self);
	bool test = false;
	for (int i=0; i<5; i++) {
		callback_object = (struct generic_st_callback *) va_arg(ap, generic_st_callback*);
		if(callback_object->callback_name.isCallable()) {
			va_end(ap);
			test = true;
			break;
		}
	}
	va_end(ap);

	if(!test) {
		std::string error("");
        throw Php::Exception(error + "cannot find callable method");
	}

	// create internal params
    Php::Value internal_parameters;

	// add self widget
	internal_parameters[0] = cobject_to_phpobject((gpointer *)self);

	// Loop into param_types of GSignalQuery from g_signal_query
	va_start(ap, self);
	for (int i=1; i<callback_object->n_params; i++) {
		switch (G_TYPE_FUNDAMENTAL(callback_object->param_types[i])) {
            case G_TYPE_CHAR:
                // Php::call("var_dump", "char");
                break;
                
            case G_TYPE_UCHAR:
                // Php::call("var_dump", "uchar");
                break;

            case G_TYPE_STRING:
            // Php::call("var_dump", "string");
                internal_parameters[i] = va_arg(ap, char *);
                break;

            case G_TYPE_BOOLEAN:
            // Php::call("var_dump", "boolean");
                internal_parameters[i] = va_arg(ap, gboolean);
                break;

            case G_TYPE_INT:
                // Php::call("var_dump", "int");
                internal_parameters[i] = va_arg(ap, gint);
                break;

            case G_TYPE_UINT:
                // Php::call("var_dump", "int");
                internal_parameters[i] = (int)va_arg(ap, guint);
                break;
                
            case G_TYPE_OBJECT:
            {
                // Php::call("var_dump", "object");
                gpointer *e = va_arg(ap, gpointer *);
                internal_parameters[i] = cobject_to_phpobject(e);
                
                break;
            }
            case G_TYPE_POINTER:
                // Php::call("var_dump", "pointer");
                break;
            case G_TYPE_INTERFACE: 
                // Php::call("var_dump", "interface");
                break;
            case G_TYPE_PARAM:
                // Php::call("var_dump", "param");
                break;
            case G_TYPE_BOXED:
            {
				// ----------------
				// GtkTreePath *e =  va_arg(ap, GtkTreePath *);
				// Php::call("var_dump", gtk_tree_path_to_string(e));
				// internal_parameters[i] = cobject_to_phpobject((gpointer *)e);

				// ----------------
				// gpointer *e = va_arg(ap, gpointer *);
				
				// Php::call("var_dump", g_type_name(G_TYPE_FROM_CLASS((gpointer *)e)));



				// ----------------
				// GdkEvent *e =  va_arg(ap, GdkEvent *);

                // // Create event from callback
                // GdkEvent_ *event_ = new GdkEvent_();
                // Php::Value gdkevent = Php::Object("GdkEvent", event_);
                // event_->populate(e);

                // internal_parameters[i] = gdkevent;

                break;
            }

            default:
                std::string error ("[generic_callback] Internal error: unsupported type ");
                throw Php::Exception(error + g_type_name(callback_object->param_types[i]));
        }
	}

	// call php function with parameters
    Php::Value ret = Php::call("call_user_func_array", callback_object->callback_name, internal_parameters);
}