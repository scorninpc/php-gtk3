<?php

$builder = GtkBuilder::new_from_file("./test4.ui");

// Label
$label = $builder->get_object("label");
$label->set_label("OK");

// Entry
$entry = $builder->get_object("entry");

// Button
$button = $builder->get_object("button");
$button->connect("clicked", function($widget, $entry) { // Connect to click of button, passing entry as user data
	// Print entry value to console
	var_dump($entry->get_text());
}, $entry);

// Window
$window = $builder->get_object("window");
$window->connect("destroy", ["Gtk", "main_quit"]); // connect to destroy
$window->show_all();

// Loop
Gtk::main();