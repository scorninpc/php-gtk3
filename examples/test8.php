<?php

Gtk::init();

// Status icon menu
$menu = new GtkMenu();
	$item = GtkMenuItem::new_with_label("Menu Item 1");
	$item->connect("activate", function() {
		echo "menu 1 clicked\n";
	});
	$menu->append($item);

	$item = GtkMenuItem::new_with_label("Menu Item 2");
	$item->connect("activate", function() {
		echo "menu 2 clicked\n";
	});
	$menu->append($item);

	$menu->show_all();

// Status icon
$status = GtkStatusIcon::new_from_file(dirname(realpath(__FILE__)) . "/logo.png");
$status->connect("button_press_event", function($widget, $event=NULL) use ($menu) {
	$menu->popup_at_pointer($event);
	$menu->show_all();
});


// Window
$window = new GtkWindow();
$window->connect("destroy", function() {
	Gtk::main_quit();
});
$window->show_all();

Gtk::main();
