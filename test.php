<?php

function GtkWindowDestroy($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	Gtk::main_quit();
}

function GtkWindowButton1Clicked($widget, $event)
{

}

function GtkWindowButton2Clicked($widget, $event)
{
	
}

// ----------------------
// Horizontal box 2
$hbox = new GtkHBox(TRUE, 5);

// Button 1
$btn1 = new GtkButton();
$btn1->set_label("Button 1");
$hbox->pack_start($btn1, TRUE, TRUE, 5);

// Button 2
$btn2 = GtkButton::new_with_mnemonic("Bu_tton 2");
$hbox->pack_start($btn2, TRUE, TRUE, 5);

// Button 3
$btn3 = GtkButton::new_with_label("Button 3");
$hbox->pack_start($btn3, TRUE, TRUE, 5);

// ----------------------
// Vertical box
$vbox = new GtkVBox(TRUE, 5);
$vbox->pack_start($hbox, TRUE, TRUE, 5);

// ----------------------
// Entry 1
$txt1 = new GtkEntry();
$vbox->pack_start($txt1, TRUE, FALSE, 5);

// ----------------------
// Window
$win = new GtkWindow(GtkWindow::TOPLEVEL);
$win->add($vbox);
$win->set_default_size(300, 200);
$win->set_title("PHP-GTK3 @ 7.3");

// Connects
$win->connect("destroy", "GtkWindowDestroy", "param 1", "param 2", "param 3", "param 4");
$btn1->connect("clicked", "GtkWindowButton1Clicked");
$btn2->connect("clicked", "GtkWindowButton2Clicked");

// Show all
$win->show_all();

// Loop
Gtk::main();