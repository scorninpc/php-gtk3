<?php

// ---
$box = new GtkBox(GtkOrientation::VERTICAL);

// ---
$button1 = GtkButton::new_with_label("Botão 1");
$button1->connect("clicked", function($widget) { var_dump("BUTTON 1"); });
$box->pack_start($button1, TRUE, TRUE);

// ---
try {
	$button2 = clone $button1;
	$button2->connect("clicked", function($widget) { var_dump("BUTTON 2"); });
	$button2->set_label("Botão 2");
	$box->pack_start($button2, TRUE, TRUE);
}
catch(Exception $e) {
	echo $e->getMessage() . "\n";
}

// ---
$win = new GtkWindow();
$win->add($box);

// ---
$win->show_all();
$win->connect("destroy", ["Gtk", "main_quit"]);
Gtk::main();