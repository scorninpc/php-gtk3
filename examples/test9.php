<?php

Gtk::init();

// Grid
$grid = new GtkGrid();

// Stack
$stack = new GtkStack();
$grid->attach($stack, 0, 0, 1, 1);
$stack->set_vexpand(TRUE);
$stack->set_hexpand(TRUE);

// Button
$buttonbox = new GtkButtonBox(GtkOrientation::HORIZONTAL);
$buttonbox->set_layout(GtkButtonBoxStyle::CENTER);
$grid->attach($buttonbox, 0, 1, 1, 1);

for($i=1; $i<=4; $i++) {
	$label = new GtkLabel("Stack content on page " . $i);

	$image = GtkImage::new_from_file(dirname(realpath(__FILE__)) . "/logo.png");
	$name = "label" . $i;
	$stack->add_named($image, $name);

	$button = GtkButton::new_with_label("Page " . $i);
	$button->connect("clicked", function($button) use ($i, $stack) {
		$name = "label" . $i;
        $stack->set_visible_child_name($name);

		$widget = $stack->get_child_by_name($name);
		var_dump($widget->get_pixbuf());

	});
	$buttonbox->add($button);
}

// Window
$window = new GtkWindow();
$window->connect("destroy", function() {
	Gtk::main_quit();
});
$window->add($grid);
$window->set_default_size(300, 200);
$window->show_all();

Gtk::main();
