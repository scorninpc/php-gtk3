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

function GtkWindowButtonClicked($widget, $event)
{
	$widget->destroy();
}

function button3_clicked($widget, $event)
{
	$widget->hide();
}

function button4_clicked($widget, $event)
{
	global $btn3;
	$btn3->show();
}

// ----------------------
// Horizontal box 1
$hbox1 = new GtkHBox(TRUE, 5);

// Button 1
$btn1 = GtkButton::new_with_label("TEST 1");
$hbox1->pack_start($btn1, TRUE, TRUE, 5);

// Button 2
$btn2 = GtkButton::new_with_label("TEST 2");
$hbox1->pack_end($btn2, TRUE, TRUE, 5);

// ----------------------
// Horizontal box 2
$hbox2 = new GtkHBox(TRUE, 5);

// Button 3
$btn3 = GtkButton::new_with_label("TEST 3");
$hbox2->pack_start($btn3, TRUE, TRUE, 5);

// Button 4
$btn4 = GtkButton::new_with_label("TEST 4");
$hbox2->pack_end($btn4, TRUE, TRUE, 5);

// ----------------------
// Vertical box
$vbox = new GtkVBox(TRUE, 5);
$vbox->pack_start($hbox1, TRUE, TRUE, 5);
$vbox->pack_start($hbox2, TRUE, TRUE, 5);

// ----------------------
// Window
//$win = new GtkWindow(GtkWindow::POPUP);
$win = new GtkWindow(GtkWindow::TOPLEVEL);
$win->add($vbox);
$win->set_default_size(300, 200);
$win->set_title("PHP-GTK3 @ 7.3");

// Connects
$ida = $btn1->connect("pressed", "GtkWindowButtonPressed", "Pressed");
$idb = $btn1->connect("released", "GtkWindowButtonReleased", "Released");
$idc = $win->connect("destroy", "funTest", "param 1", "param 2", "param 3", "param 4");
$idd = $btn2->connect("clicked", "GtkWindowButtonClicked");
$idd = $btn3->connect("clicked", "button3_clicked");
$idd = $btn4->connect("clicked", "button4_clicked");

$win->show_all();

Gtk::main();