<?php


/**
 * Helper for strings
 */
class Strings
{
	static public function removeBreaks($string)
	{
		return str_replace("\r", "", str_replace("\n", "", $string));
	}

	/**
	 * sprintf by name
	 * 
	 * %(name)s - string no marcador name
	 * %(age)02d - integer 02 no marcador age
	 */
	static public function vsprintf_named($format, $args) 
	{
		$names = preg_match_all('/%\((.*?)\)/', $format, $matches, PREG_SET_ORDER);

		$values = array();
		foreach($matches as $match) {
			$values[] = $args[$match[1]];
		}

		$format = preg_replace('/%\((.*?)\)/', '%', $format);
		return vsprintf($format, $values);
	}

	static public function explodeCamelCase($string)
	{
		$re = '/(?<=[a-z])(?=[A-Z]) | (?<=[A-Z])(?=[A-Z][a-z])/x';
		$a = preg_split($re, $string);

		return $a;
	}
}

/**
 * Controls
 */
$existing_classes = [
	"GtkApplicationWindow" => "GtkWindow",
	"GtkApplication" => "GApplication",
	"GtkWindow" => "GtkWidget",
];

$def_functions = [];
$def_classes = [];


/**
 * Run application
 */

// Read def file
$defs = file_get_contents("defs.txt");

// Parse functions from defs
preg_match_all('/^([a-zA-Z\*]*)\ (.*)\ \((.*)\,{0,}\)/im', $defs, $parsed_defs);

// Loop adjusting definitions
foreach($parsed_defs[0] as $index => $def) {
	

	// Store defs
	$function_return = $parsed_defs[1][$index];
	$function_name = $parsed_defs[2][$index];
	$params = $parsed_defs[3][$index];
	
	// Parse params
	$params = explode(",", $params);
	$function_params = [];
	foreach($params as $param) {
		$function_params[] = rtrim(ltrim($param));
	}

	// Get class name
	$tmp = explode("_", $function_name);
	$tmp = array_map("ucfirst", $tmp);

	echo "-> " . $function_name . "\n";
	while(count($tmp)) {
		$class_name = implode("", $tmp);
		echo $class_name . "\n";
		if(!isset($existing_classes[$class_name])) {
			array_pop($tmp);
		}
		else {
			break;
		}
	}
	echo "Found [" . $class_name . "]\n";

	echo "----\n";

	// Store all parsed
	if(!isset($def_classes[$class_name])) {
		$def_classes[$class_name] = [];
	}

	$def_classes[$class_name][] = [
		'name' => $function_name,
		'return' => $function_return,
		'params' => $function_params,
		'class' => $class_name
	];

}

// Create the header file
foreach($def_classes as $class_name => $def_class) {

	/**
	 * Create header file
	 */
	$extra_includes = [];
	$methods = [];

	$tmp = \Strings::explodeCamelCase($class_name);
	$namespace = $tmp[0];


	$template_file = "
#ifndef _PHPGTK_%(u_class_name)s_H_
#define _PHPGTK_%(u_class_name)s_H_

	#include <phpcpp.h>
	#include <gtk/gtk.h>

	%(extra_includes)s

	class %(class_name)s_ : public %(extends)s_
	{
		/**
		 * Publics
		 */
		public:

			/**
			 *  C++ constructor and destructor
			 */
			%(class_name)s_();
			~%(class_name)s_();

			%(methods)s

	}

#endif
";

	// Loop into functions
	foreach($def_class as $function_name => $function) {

		$class_functions_holder = \Strings::explodeCamelCase($class_name);
		$class_functions_holder = array_map("strtolower", $class_functions_holder);
		$class_functions_holder = implode("_", $class_functions_holder) . "_";

		$method_name = str_replace($class_functions_holder, "", $function['name']);
		if($method_name == "new") {
			$method_name = "__construct";
			$method_return  = "void";
		}
		else {

			// Parse return type
			if($function['return'] == "void") {
				$method_return = "void";
			}
			else {
				$method_return = "Php::Value";
			}

			// Parse params
			$count = 0;
			foreach($function['params'] as $index => $param) {
				$tmp = explode(" ", $param);
				$param_type = str_replace("*", "", $tmp[0]);
				$param_name = $tmp[1];

				// Verify if the first param are the class
				if($index == 0) {
					if($param_type == $class_name) {
						continue;
					}
				}

				// Include the extends class
				if(isset($existing_classes[$param_type])) {
					$tmp = \Strings::explodeCamelCase($existing_classes[$param_type]);
					if($tmp[0] == $namespace) {
						$extra_includes[$existing_classes[$param_type]] = "#include \"" . $existing_classes[$param_type] . ".h\"";
					}
					else {
						$extra_includes[$existing_classes[$param_type]] = "#include \"../" . $tmp[0] . "/" . $existing_classes[$param_type] . ".h\"";
					}
				}

				$count++;
			}
			if($count > 0) {
				$method_param = "Php::Parameters &parameters";
			}
			else {
				$method_param = "";
			}

			
		}

		$methods[] = $method_return . " " . $method_name . "(" . $method_param . ");";

	}

	// Include the extends class
	$tmp = \Strings::explodeCamelCase($existing_classes[$class_name]);
	if($tmp[0] == $namespace) {
		$extra_includes[$existing_classes[$param_type]] = "#include \"" . $existing_classes[$class_name] . ".h\"";
	}
	else {
		$extra_includes[$existing_classes[$param_type]] = "#include \"../" . $tmp[0] . "/" . $existing_classes[$class_name] . ".h\"";
	}
	
	// Do the replacements
	$header_file_content = \Strings::vsprintf_named($template_file, [
		'class_name' => $class_name,
		'u_class_name' => strtoupper($class_name),
		'extends' => $existing_classes[$class_name],
		'extra_includes' => implode("\n\t", $extra_includes),
		'methods' => implode("\n\t\t\t", $methods),
	]);

	// 
	var_dump($header_file_content);


	/**
	 * Create cpp file
	 */
}