<?php

function funTest($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	echo "\n-- GtkWindow::destroy::params ------\n\n";
	var_dump($widget);
	var_dump($event);
	var_dump($param1);
	var_dump($param2);
	var_dump($param3);
	var_dump($param4);

	echo "\n-- Gtk::destroy::main_quit ------\n\n";
	Gtk::main_quit();
}


function GtkWindowButtonPressed($widget, $event)
{
	echo "\n-- GtkWindow::button-press-event::params ------\n\n";
	var_dump($widget);
	var_dump($event);
}


echo "\n-- GtkWindow ------\n\n";
$win = new GtkWindow();
var_dump($win);

echo "\n-- GtkWindow::connect ------\n\n";
// $id = $win->connect("button-press-event", "GtkWindowButtonPressed", "parametro 1");
$id = $win->connect("destroy", "funTest", "parametro 1", "parametro 2", "parametro 3", "parametro 4");
var_dump($id);

//echo "\n-- GtkWindow::handle_disconnect ------\n\n";
//$id = $win->handler_disconnect($id);

echo "\n-- GtkWindow::show_all ------\n\n";
$win->show_all();

echo "\n-- Gtk::main ------\n\n";
Gtk::main();

// echo "\n-- GtkApplication ------\n\n";

// $app = new GtkApplication();
// var_dump($app);

// echo "\n-- GtkApplication->new ------\n\n";

// $a = $app->new();
// var_dump($a);

// echo "\n-- myTest -----------\n\n";

// myTest($a);

echo "\n-- END! ------\n\n";