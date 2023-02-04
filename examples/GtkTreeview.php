<?php

Gtk::init();

function GtkWindowDestroy($widget=NULL, $event=NULL)
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
	$treeview->append_column($column1);

	$column2 = new GtkTreeViewColumn("Phone", new GtkCellRendererText(), "text", 1);
	$treeview->append_column($column2);

	$column3 = new GtkTreeViewColumn("Genre", new GtkCellRendererText(), "text", 2);
	$treeview->append_column($column3);

// model
$model = new GtkListStore(GObject::TYPE_STRING, GObject::TYPE_STRING, GObject::TYPE_STRING);
$treeview->set_model($model);

	$model->append(["Bruno", "+55 43 9 9282-2039", "M"]);
	$model->append(["Natália", "+55 17 8273-0293", "F"]);
	$model->append(["Sven", "+49 4190-8140", "F"]);

// button to get selected
$button = GtkButton::new_with_label("get selected");
$vbox->pack_start($button, TRUE, TRUE);
$button->connect("clicked", function($widget) use ($treeview, $model) {
	$selection = $treeview->get_selection()->get_selected_rows($model);
	foreach($selection as $select) {
		$iter = $model->get_iter($select);
		
		var_dump($model->get_value($iter, 0));
	}
});

$win->show_all();
Gtk::main();