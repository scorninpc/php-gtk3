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
}

/**
 * Controls
 */
$def_classes = [
	"gtk_application" => "GtkApplication",
];

$def_functions = [];


/**
 * Run application
 */

// Read def file
$defs = file_get_contents("defs.txt");

// Parse functions from defs
preg_match_all('/^([a-zA-Z]*)\ (.*)\ \((.*)\,{0,}\)/im', $defs, $parsed_defs);

// Loop adjusting definitions
foreach($parsed_defs[0] as $index => $def) {
	
	$function_return = $parsed_defs[1][$index];
	$function_name = $parsed_defs[2][$index];
	$function_params = $parsed_defs[3][$index];
	
	$def_functions[$function_name] = [
		'name' => $function_name,
		'return' => $function_return,
		'params' => $function_params,
	];

}


// 
var_dump($def_functions);
