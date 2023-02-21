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

// treeviiew
$treeview = new GtkTreeView();
$treeview->get_selection()->set_mode(GtkSelectionMode::MULTIPLE); // enable multiple selections
$scroll = new GtkScrolledWindow();
$scroll->add($treeview);
$vbox->pack_start($scroll, TRUE, TRUE);

// columns
$column1 = new GtkTreeViewColumn("Name", new GtkCellRendererText(), "text", 0);
$column1->set_sort_column_id(0);
$treeview->append_column($column1);

$column2 = new GtkTreeViewColumn("Phone", new GtkCellRendererText(), "text", 1);
$column2->set_sort_column_id(1);
$treeview->append_column($column2);

$column3 = new GtkTreeViewColumn("Genre", new GtkCellRendererText(), "text", 2);
$column3->set_sort_column_id(2);
$treeview->append_column($column3);

$column4 = new GtkTreeViewColumn("Login", new GtkCellRendererText(), "text", 3);
$column4->set_sort_column_id(3);
$treeview->append_column($column4);

$column5 = new GtkTreeViewColumn("LONG", new GtkCellRendererText(), "text", 4);
$column5->set_sort_column_id(4);
$treeview->append_column($column5);


// model
$model = new GtkListStore(GObject::TYPE_STRING, GObject::TYPE_STRING, GObject::TYPE_STRING, GObject::TYPE_STRING, GObject::TYPE_LONG, GObject::TYPE_LONG);
$treeview->set_model($model);
$model->set_sort_func(3, 'sortDate');
//$model->set_sort_column_id(3, GtkSortType::ASCENDING);    // THIS WILL BREAK
$model->append(["Bruno", "+55 43 9 9282-2039", "M2", "02.02.2023 11:11:11", 0, 0]);
$model->append(["Natália", "+55 17 8273-0293", "F2", "01.02.2023 11:11:11", 1234567890, 1234567890]);
$model->append(["Maria", "+49 4190-8140", "F3", "02.01.2023 11:11:11", 609990000000007, 609990000000007]);
$model->append(["Sven", "+49 0291-2450", "M3", "12.02.2023 11:11:11", 2147483647, 2147483647]);
$model->append(["Oliver", "+49 0291-2451", "M4", "12.02.2023 11:11:11", 2147483648, 2147483648]);

// 1 is the second column
//$model->set_sort_func(3, 'sortDate');
$model->set_sort_column_id(3, GtkSortType::ASCENDING);


// button to get selected
$button = GtkButton::new_with_label("get selected");
$vbox->pack_start($button, TRUE, TRUE);
$button->connect("clicked", function ($widget) use ($treeview, $model) {
	list($model2, $selection) = $treeview->get_selection()->get_selected_rows($model);
	foreach ($selection as $select) {
		$iter = $model->get_iter($select);

		var_dump($model->get_value($iter, 4));
		var_dump($model->get_value($iter, 5));
	}
});

function sortDate($model, $iter1, $iter2)
{
	$item1 = $model->get_value($iter1, 3);
	$item2 = $model->get_value($iter2, 3);
	$val1  = strtotime(substr($item1, 0, 19));
	$val2  = strtotime(substr($item2, 0, 19));
	if ($val1 < $val2) {
		return -1;
	} elseif ($val1 == $val2) {
		return 0;
	} else {
		return 1;
	}
}

$win->show_all();
Gtk::main();
