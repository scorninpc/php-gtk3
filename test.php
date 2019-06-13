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
	global $popupmenu;

	// var_dump($widget);
	if($event->button->button == 3) {
		$popupmenu->popup_at_pointer($event);
	}
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
		$value = $model->get_value($iter, 1);
		var_dump($value);
		$model->set_value($iter, 1, !$value);
	}
}

// ----------------------
// Vertical box
$vbox = new GtkBox();
die("OK");

// $vbox->pack_start(2.2, TRUE, TRUE);

// ----------------------
// Menu
$vbox->pack_start(2, TRUE, TRUE, 1); $hlbl->set_xalign(0);

$menubar = new GtkMenuBar();
$vbox->pack_start($menubar, FALSE, FALSE, 0);
	
	$mnuFile = GtkMenuItem::new_with_mnemonic("_File");
		
		$menu = new GtkMenu();
			$mnuFile1 = GtkMenuItem::new_with_label("New File"); $menu->append($mnuFile1);
			$mnuFile2 = GtkMenuItem::new_with_label("Open File"); $menu->append($mnuFile2);
			$mnuFile3 = new GtkSeparatorMenuItem(); $menu->append($mnuFile3);
			$mnuFile4 = GtkMenuItem::new_with_label("Quit"); $menu->append($mnuFile4); 
			$mnuFile4->connect("activate", function($widget) {
				Gtk::main_quit();
			});
			
			$mnuFile5 = GtkCheckMenuItem::new_with_label("hello?"); $menu->append($mnuFile5); 

			$mnuFile->set_submenu($menu);

		$mnuAbout = GtkMenuItem::new_with_label("About"); 
		

	$menubar->append($mnuFile);
	$menubar->append($mnuAbout);

// ----------------------
// Horizontal box 2
$hbox = new GtkBox(GtkOrientation::HORIZONTAL, 1);

// ----------------------
// Button 1
$vbox->pack_start($hlbl = new GtkLabel("- GtkButton"), TRUE, TRUE, 1); $hlbl->set_xalign(0);

// $btn1 = new GtkButton();
// $btn1->set_label("Button 1");
$btn1 = GtkButton::new_from_icon_name("help-faq", GtkIconSize::BUTTON);
$hbox->pack_start($btn1, TRUE, TRUE, 1);

// Button 2
$btn2 = GtkButton::new_with_mnemonic("Bu_tton 2");
$hbox->pack_start($btn2, TRUE, TRUE, 1);

// Button 3
$btn3 = GtkToggleButton::new_with_label("Button 3");
$hbox->pack_start($btn3, TRUE, TRUE, 1);

// Button 4
$btn4 = GtkCheckButton::new_with_label("Button 4");
$hbox->pack_start($btn4, TRUE, TRUE, 1);

$vbox->pack_start($hbox, FALSE, FALSE, 1);

// ----------------------
// Entry 1
$vbox->pack_start($hlbl = new GtkLabel("- GtkEntry"), TRUE, TRUE, 1); $hlbl->set_xalign(0);

$txt1 = new GtkEntry();
$vbox->pack_start($txt1, FALSE, FALSE, 1);

// ----------------------
// GtkComboBox 1
$vbox->pack_start($hlbl = new GtkLabel("- GtkComboBox"), TRUE, TRUE, 1); $hlbl->set_xalign(0);

$cml = new GtkListStore(GObject::TYPE_STRING);
$cml->append(["Test 1"]);
$cml->append(["Test 2"]);
$cml->append(["Test 3"]);

$cmb1 = GtkComboBox::new_with_model($cml);
$vbox->pack_start($cmb1, FALSE, FALSE, 1);

$cellRenderer = new GtkCellRendererText();
$cmb1->pack_start($cellRenderer);
$cmb1->add_attribute($cellRenderer, 'text', 0);
$cmb1->set_active(2);

// Icon from pixbuf
// $pixbuf = GdkPixbuf::new_from_file("./logo.png");
// $win->set_icon($pixbuf);

// From theme name
// $win->set_icon_name("application-exit");

// 
//$win->set_interactive_debugging(TRUE);

// ----------------------
// Treeview
$vbox->pack_start($hlbl = new GtkLabel("- GtkTreeView"), TRUE, TRUE, 1); $hlbl->set_xalign(0);

$tree = new GtkTreeView();
$vbox->pack_start($tree, TRUE, TRUE, 1);

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
	$renderer2->set_alignment(0.5, 0.1);
	$column2->set_alignment(0.5, 0.1);
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


$model = new GtkListStore(GObject::TYPE_OBJECT, GObject::TYPE_BOOLEAN, GObject::TYPE_INT, GObject::TYPE_DOUBLE, GObject::TYPE_STRING);
$pixbuf = GdkPixbuf::new_from_file_at_size("./logo.png", 15, -1);
$model->append([$pixbuf, TRUE, 1, 2.3, "line 1"]);
$model->append([$pixbuf, FALSE, 2, 92.2, "line 2"]);


$tree->set_model($model);


// ----------------------
// Menu for treeview
$popupmenu = new GtkMenu();
	$menuitem1 = GtkMenuItem::new_with_label("Menu Item 1"); 
	$popupmenu->append($menuitem1);
	$menuitem1->connect('activate', function($widget, $tree) {
		
		$model = $tree->get_model();
		$selection = $tree->get_selection();
		$iter = $selection->get_selected($model);
		
		$value = $model->get_value($iter, 1);
		var_dump($value);
		$value = $model->get_value($iter, 2);
		var_dump($value);
		$value = $model->get_value($iter, 3);
		var_dump($value);
		$value = $model->get_value($iter, 4);
		var_dump($value);

	}, $tree);
	$menuitem2 = GtkMenuItem::new_with_label("Menu Item 2"); 
	$popupmenu->append($menuitem2);
	$popupmenu->show_all();

// ----------------------
// ListBox
$vbox->pack_start($hlbl = new GtkLabel("- GtkListBox"), TRUE, TRUE, 1); $hlbl->set_xalign(0);


$ltb = new GtkListBox();

$scroll = new GtkScrolledWindow();
$scroll->add($ltb); // add_with_viewport is deprecated
$scroll->set_policy(GtkPolicyType::AUTOMATIC, GtkPolicyType::AUTOMATIC);
$vbox->pack_start($scroll, TRUE, TRUE, 1);

$row = new GtkListBoxRow();
	$lhbox = new GtkBox(GtkOrientation::HORIZONTAL);
	$lhbox->pack_start(new GtkLabel("Cell 1x1"), TRUE, TRUE);
	$lhbox->pack_start(new GtkLabel("Cell 1x2"), TRUE, TRUE);
	$lhbox->pack_start(GtkCheckButton::new_with_label(""), FALSE, FALSE);
$row->add($lhbox, TRUE, TRUE);
$ltb->insert($row);

$row = new GtkListBoxRow();
	$lhbox = new GtkBox(GtkOrientation::HORIZONTAL);
	$lhbox->pack_start(new GtkLabel("Cell 2x1"), TRUE, TRUE);
	$lhbox->pack_start(new GtkLabel("Cell 2x2"), TRUE, TRUE);
	$lhbox->pack_start(GtkCheckButton::new_with_label(""), FALSE, FALSE);
$row->add($lhbox, TRUE, TRUE);
$ltb->insert($row);

// ----------------------
// Grid
$vbox->pack_start($hlbl = new GtkLabel("- GtkGrid"), TRUE, TRUE, 1); $hlbl->set_xalign(0);
$grid = new GtkGrid();
$vbox->pack_start($grid, TRUE, TRUE);

$grid->attach(GtkButton::new_with_label("Grid 1x1"), 0, 0, 2, 1);
$grid->attach(GtkButton::new_with_label("Grid 1x3"), 2, 0, 1, 1);
$grid->attach(GtkButton::new_with_label("Grid 1x4"), 3, 0, 2, 1);

$grid->attach(GtkButton::new_with_label("Grid 2x1"), 0, 1, 1, 1);
$grid->attach(GtkButton::new_with_label("Grid 2x2"), 1, 1, 1, 1);
$grid->attach(GtkButton::new_with_label("Grid 2x3"), 2, 1, 1, 1);
$grid->attach(GtkButton::new_with_label("Grid 2x4"), 3, 1, 1, 1);
$grid->attach(GtkButton::new_with_label("Grid 2x5"), 4, 1, 1, 1);

$grid->attach(GtkButton::new_with_label("Grid 3x1"), 0, 2, 1, 1);
$grid->attach(GtkButton::new_with_label("Grid 3x3"), 1, 2, 1, 1);
$grid->attach(GtkButton::new_with_label("Grid 3x3"), 2, 2, 2, 1);
$grid->attach(GtkButton::new_with_label("Grid 3x5"), 4, 2, 1, 1);

// ----------------------
// Status
$vbox->pack_start($hlbl = new GtkLabel("- GtkStatusbar"), TRUE, TRUE, 1); $hlbl->set_xalign(0);

$stt1 = new GtkStatusbar();
$vbox->pack_start($stt1, FALSE, TRUE, 0);
$stt1->set_size_request(20, 20);

// add messages
$context_id = $stt1->get_context_id("global");
$stt1->push($context_id, "Status 1");
$stt1->push($context_id, "Status 2");
$stt1->push($context_id, "Status 3");

$stt1->pop($context_id);


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


// Connects
// $win->connect("destroy", "GtkWindowDestroy", "param 1", "param 2", "param 3", "param 4");
$win->connect("delete-event", "GtkWindowDelete", "param 1", "param 2", "param 3", "param 4");
$btn1->connect("clicked", "GtkWindowButton1Clicked", "Extra Param 1");
$btn2->connect("button-release-event", "GtkButton2Released");
// $btn2->connect("clicked", "GtkWindowReleased");
// $btn2->connect("clicked", "GtkWindowButton2Clicked");
// $btn3->connect("clicked", "GtkWindowButton3Clicked");
$tree->connect("button-release-event", "GtkTreeViewButtonPressed");

// Show all
$win->show_all();

// Loop
Gtk::main();