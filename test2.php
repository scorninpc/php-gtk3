<?php

function GtkWindowDestroy($widget=NULL, $event=NULL)
{
	Gtk::main_quit();
}

$win = new GtkWindow();
$win->set_default_size(300, 200);

$paned = new GtkPaned(GtkOrientation::HORIZONTAL);
$paned->pack1(GtkButton::new_with_label("asd"), TRUE, TRUE);
$paned->pack2(new GtkButton(), FALSE, FALSE);
$paned->set_position(120);

var_dump($paned->get_position());



$win->add($paned);

$win->connect("destroy", "GtkWindowDestroy");

$win->show_all();

Gtk::main();