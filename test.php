<?php

function GtkWindowDestroy($widget=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	echo "\n------ GtkWindowDestroy\n";
	// Gtk::main_quit();
	var_dump($widget);
	var_dump($param1);
	var_dump($param2);
	var_dump($param3);
	var_dump($param4);
}

function GtkWindowDelete($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	// global $win;
	// $dialog = GtkMessageDialog::new_with_markup($win, GtkDialogFlags::MODAL, GtkMessageType::INFO, GtkButtonsType::YES_NO, "Want close PHP-GTK3 test program?");
	// $a = $dialog->run();
	// $dialog->destroy();

	// if($a == GtkResponseType::YES) {
		Gtk::main_quit();
	// }

	// return TRUE;
}

function GtkWindowFocus($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{

}

function GtkButton2Released($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	echo "\n------ GtkButton2Released\n";
	var_dump($widget);
	var_dump($event);
	// var_dump($param1);
	// var_dump($param2);
	// var_dump($param4);
}

function GtkTreeViewButtonPressed($widget=NULL, $event=NULL)
{
	// var_dump($widget);
	// var_dump($event);
}

function GtkWindowButton1Clicked($widget=NULL, $param1=NULL)
{
	echo "\n------ GtkWindowButton1Clicked\n";
	var_dump($param1);
	
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
	// var_dump($widget);
	// var_dump($event);
}

function GtkCellRendererToggled($renderer=NULL, $path=NULL)
{
	// echo "\n------ GtkCellRendererToggled\n";
	global $model, $tree;

	$iter = $model->get_iter($path);
	if($iter) {
		$value = $model->get_value($iter, 0);
		var_dump($value);
		$model->set_value($iter, 0, !$value);
	}
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
$btn3 = GtkToggleButton::new_with_label("Button 3");
$hbox->pack_start($btn3, TRUE, TRUE, 5);

// Button 4
$btn4 = GtkCheckButton::new_with_label("Button 4");
$hbox->pack_start($btn4, TRUE, TRUE, 5);

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

	// Column 0
	$renderer0 = new GtkCellRendererPixbuf();
	$column0 = new GtkTreeViewColumn("", $renderer0, "pixbuf", 0);
	$tree->append_column($column0, TRUE);


	// Column 1
	$renderer1 = new GtkCellRendererToggle();
	$column1 = new GtkTreeViewColumn("", $renderer1, "active", 1);
	$renderer1->set_activatable(TRUE);
	$tree->append_column($column1);
	$column1->set_fixed_width(30);

	$renderer1->connect('toggled', "GtkCellRendererToggled");

	// Column 2
	$renderer2 = new GtkCellRendererText();
	$column2 = new GtkTreeViewColumn("Column 2", $renderer2, "text", 2);
	$tree->append_column($column2);
	$renderer2->set_alignment(0.5, 0.5);
	$column2->set_alignment(0.5, 0.5);
	$column2->set_resizable(TRUE);

	$column2->set_sort_column_id(1);

	// Column 3
	$renderer3 = new GtkCellRendererText();
	$column3 = new GtkTreeViewColumn("Column 3", $renderer3, "text", 3);
	$tree->append_column($column3, TRUE);


	// Column 4
	$renderer4 = new GtkCellRendererText();
	$column4 = new GtkTreeViewColumn("Column 4", $renderer4, "text", 4);
	$tree->append_column($column4, TRUE);


$model = new GtkListStore(Gdk::TYPE_PIXBUF, GObject::TYPE_BOOLEAN, GObject::TYPE_INT, GObject::TYPE_DOUBLE, GObject::TYPE_STRING);
$pixbuf = GdkPixbuf::new_from_file("./logo.png");
$model->append([$pixbuf, TRUE, 1, 2.3, "line 1"]);
$model->append([$pixbuf, FALSE, 2, 92.2, "line 2"]);


$tree->set_model($model);


// Connects
// $win->connect("destroy", "GtkWindowDestroy", "param 1", "param 2", "param 3", "param 4");
$win->connect("delete-event", "GtkWindowDelete", "param 1", "param 2", "param 3", "param 4");
$btn1->connect("clicked", "GtkWindowButton1Clicked", "Extra Param 1");
$btn2->connect("button-release-event", "GtkButton2Released");
// $btn2->connect("clicked", "GtkWindowReleased");
// $btn2->connect("clicked", "GtkWindowButton2Clicked");
// $btn3->connect("clicked", "GtkWindowButton3Clicked");
// $tree->connect("button-release-event", "GtkTreeViewButtonPressed");

// Show all
$win->show_all();

// Loop
Gtk::main();