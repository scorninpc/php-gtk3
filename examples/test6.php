<?php

$application = new GtkApplication("br.com.pitteli.example", GApplication::FLAGS_NONE);
$application->connect("activate", function($application) {

	$window = $application->window_new();
	$window->set_title("PHP-GTK Window");
	$window->show_all();

});

$status = GApplication::run($application);

return $status;

// $win = new GtkWindow();
// $win->set_default_size(300, 200);
// $win->connect("destroy", ["Gtk", "main_quit"]);

// $button = new GtkButton();
// $button->set_label("Start");
// $win->add($button);

// $button->connect("clicked", function($widget) {
// 	global $win;

// 	if($widget->get_label() == "Start") {
// 		$widget->set_label("Stop");

// 		$handler = Gtk::timeout_add(1000, function() {
			
// 			$gdkwindow = GdkWindow::get_default_root_window();

// 			Gdk::test_simulate_button($gdkwindow, 451, 531, 1);

// 			echo "OK\n";

// 			// Tell to continue calling
// 			return TRUE;
// 		});
// 	}
// 	else {
// 		$widget->set_label("Start");
		
// 	}
// });

// $win->show_all();

// Gtk::main();