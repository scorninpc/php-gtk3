<?php


function funTest($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	Gtk::main_quit();
}


function GtkWindowButtonPressed($widget, $event, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	$widget->set_label($param1);
}

function GtkWindowButtonReleased($widget, $event, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	$widget->set_label($param1);
}

$win = new GtkWindow();

$btn = GtkButton::new_with_label("TEST");
$win->add($btn);

$ida = $btn->connect("pressed", "GtkWindowButtonPressed", "Pressed");
$idb = $btn->connect("released", "GtkWindowButtonReleased", "Released");
$idc = $win->connect("destroy", "funTest", "parametro 1", "parametro 2", "parametro 3", "parametro 4");

$win->show_all();

Gtk::main();