<?php

function GtkWindowDestroy($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	Gtk::main_quit();
}

function GtkWindowFocus($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	// var_dump("OK");
}

function GtkWindowReleased($widget=NULL, $event=NULL)
{
	// var_dump("OK");
}
function GtkWindowButton1Clicked($widget=NULL, $event=NULL)
{
	
	// global $win;

	// // Move
	// $win->move(10, 10);

	// var_dump($widget);
	// var_dump($event);
}

function GtkWindowButton2Clicked($widget=NULL, $event=NULL)
{
	global $model, $tree;

	$model->append([FALSE, 3, "param 2"]);

	//$tree->set_model($model);
}

function GtkWindowButton3Clicked($widget=NULL, $event=NULL)
{

}

function GtkCellRendererToggled($renderer=NULL, $row=NULL)
{
	// echo "ok\n";
}

// ----------------------
// Horizontal box 2
$hbox = new GtkHBox(TRUE, 5);

// Button 1
// $btn1 = new GtkButton();
// $btn1->set_label("Button 1");
$btn1 = GtkButton::new_from_icon_name("help-faq", GtkIconSize::BUTTON);
$hbox->pack_start($btn1, TRUE, TRUE, 5);

// Button 2
$btn2 = GtkButton::new_with_mnemonic("Bu_tton 2");
$hbox->pack_start($btn2, TRUE, TRUE, 5);

// Button 3
$btn3 = GtkButton::new_with_label("Button 3");
$hbox->pack_start($btn3, TRUE, TRUE, 5);

// ----------------------
// Vertical box
$vbox = new GtkVBox(FALSE, 5);
$vbox->pack_start($hbox, FALSE, FALSE, 5);

// ----------------------
// Entry 1
$txt1 = new GtkEntry();
$vbox->pack_start($txt1, FALSE, FALSE, 5);

// ----------------------
// Window
$win = new GtkWindow(Gtk::WINDOW_TOPLEVEL);
$win->add($vbox);
$win->set_default_size(300, 200);
$win->set_title("PHP-GTK3 @ 7.3");
$win->set_position(GTK::WIN_POS_CENTER);
$win->set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL);

// Icon from file
$win->set_icon_from_file("./logo.png");

// Icon from pixbuf
// $pixbuf = GdkPixbuf::new_from_file("./logo.png");
// $win->set_icon($pixbuf);

// From theme name
// $win->set_icon_name("application-exit");

// 
//$win->set_interactive_debugging(TRUE);

// Treeview
$tree = new GtkTreeView();
$vbox->pack_start($tree, TRUE, TRUE, 5);

	// Column 1
	$renderer1 = new GtkCellRendererToggle();
	$column1 = new GtkTreeViewColumn("", $renderer1, "active", 0);
	$renderer1->set_activatable(TRUE);
	$tree->append_column($column1);
	$column1->set_fixed_width(20);

	// $renderer1->connect('toggled', "GtkCellRendererToggled");

	// Column 2
	$renderer2 = new GtkCellRendererText();
	$column2 = new GtkTreeViewColumn("Column 2", $renderer2, "text", 1);
	$tree->append_column($column2);
	$renderer2->set_alignment(0.5, 0.5);
	$column2->set_alignment(0.5, 0.5);
	$column2->set_resizable(TRUE);

	$column2->set_sort_column_id(1);

	// Column 3
	$renderer3 = new GtkCellRendererText();
	$column3 = new GtkTreeViewColumn("Column 3", $renderer3, "text", 2);
	$tree->append_column($column3, TRUE);


$model = new GtkListStore(GObject::TYPE_BOOLEAN, GObject::TYPE_INT, GObject::TYPE_STRING);
$model->append([TRUE, 1, "line 1"]);
$model->append([FALSE, 2, "line 2"]);


$tree->set_model($model);


// Connects
$win->connect("destroy", "GtkWindowDestroy", "param 1", "param 2", "param 3", "param 4");
$btn1->connect("clicked", "GtkWindowButton1Clicked");
// $btn2->connect("button-release-event", "GtkWindowReleased");
$btn2->connect("clicked", "GtkWindowReleased");
$btn2->connect("clicked", "GtkWindowButton2Clicked");
$btn3->connect("clicked", "GtkWindowButton3Clicked");

// Show all
$win->show_all();

// Loop
Gtk::main();