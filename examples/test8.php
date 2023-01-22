<?php

Gtk::init();

/**
 * highlight treeview lines
 */
function highlight($column, $renderer, $model, $iter, $cor1, $cor2) {
	$path = $model->get_path($iter);
	$row = $path[0];

	if($row % 2 == 1) {
		$color = $cor1;
	}
	else {
		$color = $cor2;
	}

	$renderer->set_property("cell-background", $color);
}

// Status icon menu
$menu = new GtkMenu();
	$item = GtkMenuItem::new_with_label("Menu Item 1");
	$item->connect("activate", function() {
		echo "menu 1 clicked\n";
	});
	$menu->append($item);

	$item = GtkMenuItem::new_with_label("Menu Item 2");
	$item->connect("activate", function() {
		echo "menu 2 clicked\n";
	});
	$menu->append($item);

	$menu->show_all();

// Status icon
$status = GtkStatusIcon::new_from_file(dirname(realpath(__FILE__)) . "/logo.png");
$status->connect("button_press_event", function($widget, $event=NULL) use ($menu) {
	$menu->popup_at_pointer($event);
	$menu->show_all();
});

// Treeview
$treeview = new GtkTreeView();
	$renderer = new GtkCellRendererText();
	$column = new GtkTreeViewColumn("Column", $renderer, "text", 0);
	$treeview->append_column($column);
	
	$column->set_cell_data_func($renderer, "highlight", "#ff0000", "#00FF00");

	$model = new GtkListStore(GObject::TYPE_STRING);
	$treeview->set_model($model);

	$model->append(["line 1"]);
	$model->append(["line 2"]);
	$model->append(["line 3"]);
	$model->append(["line 4"]);
	$model->append(["line 5"]);
	$model->append(["line 6"]);

// Window
$window = new GtkWindow();
$window->connect("destroy", function() {
	Gtk::main_quit();
});
$window->add($treeview);
$window->set_default_size(300, 200);
$window->show_all();

Gtk::main();
