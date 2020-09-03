<?php

\Gtk::init();

$a = WnckScreen::test("asd");

$a->connect("active-window-changed", function($screen, $window1=NULL) {

	echo $window1;
	// echo "active: " . $window1->get_name() . "\n";

});

$a->connect("window-opened", function($screen, $window=NULL) {

	echo "open: " . $window->get_name() . "\n";

});



\Gtk::main();