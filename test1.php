<?php

function GtkWindowDestroy($widget=NULL, $event=NULL)
{
	Gtk::main_quit();
}

$win = new GtkWindow();
$win->set_default_size(300, 200);

$win->connect("destroy", "GtkWindowDestroy");

$win->show_all();

Gtk::main();