<?php

$win = new GtkWindow();
$win->set_default_size(300, 200);
$win->connect("destroy", ["Gtk", "main_quit"]);

$button = new GtkButton();
$button->set_label("Start");
$win->add($button);

$button->connect("clicked", function($widget) {
	global $win;

	if($widget->get_label() == "Start") {
		$widget->set_label("Stop");
	}
	else {
		$widget->set_label("Start");
		$handler = Gtk::timeout_add(500, function() {
			global $win;

			$gdkwindow = $win->get_parent_window();

			Gdk::test_simulate_button($gdkwindow, 0, 0, 1);

			// Tell to continue calling
			return TRUE;
		});
	}
});

$win->show_all();

Gtk::main();