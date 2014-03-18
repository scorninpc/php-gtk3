<?php

class test {
	static function quit() {
		echo "\ntest::quit()\n";
		Gtk::main_quit();
	}
}

function aquit() {
	echo "\naqui function\n";
	Gtk::main_quit();
}

// GtkWindow
$window = new GtkWindow();
$window->set_title("Gtk main test");
$window->set_size_request(500, 500);
$window->set_default_size(500, 500);
$window->set_resizable(FALSE);
$window->set_position(Gtk::WIN_POS_CENTER);

//$window->connect("destroy", array($a, 'quit'));
try {
	$window->connect("destroy", 'aquit');
}
catch(Exception $e) {
	echo "Erro: " . $e->getMessage();
}

$window->show_all();
Gtk::main();
