<?php

Gtk::init();

function GtkWindowDestroy($widget = NULL, $event = NULL)
{
	Gtk::main_quit();
}

$win = new GtkWindow();
$win->set_default_size(300, 200);
$win->connect("destroy", "GtkWindowDestroy");


$vbox = new GtkBox(GtkOrientation::VERTICAL);
$win->add($vbox);

$calendar = new GtkCalendar("04.02.2023");
$vbox->pack_start($calendar, TRUE, TRUE);

$button = GtkButton::new_with_label("dump date");
$vbox->pack_start($button, TRUE, TRUE);
$button->connect("clicked", function ($widget) use ($calendar) {
	var_dump($calendar->get_date());
});

$button = GtkButton::new_with_label("destroy calendar");
$vbox->pack_start($button, TRUE, TRUE);
$button->connect("clicked", function ($widget) use ($calendar) {
	$calendar->destroy();
});


$win->show_all();
Gtk::main();
