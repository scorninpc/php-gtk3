<?php

\Gtk::init();

$screen = WnckScreen::get_default();

$screen->connect("active-window-changed", function($screen, $window=NULL) {
	echo "==active-window-changed========================\n";
	var_dump($screen);
	var_dump($window);
	// echo "active: " . $window1->get_name() . "\n";

});

$screen->connect("window-opened", function($screen, $window=NULL) {
	echo "==window-opened========================\n";
	var_dump($screen);
	var_dump($window);

	$active_window = $screen->get_active_window();
	if($active_window) {
		echo "open: " . $active_window->get_name() . "\n";
		echo "open1: " . $window->get_name() . "\n";
	}

});



\Gtk::main();