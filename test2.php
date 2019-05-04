<?php

/**
 * Application class
 */
class Application
{
	/**
	 * Construtor
	 */
	public function __construct()
	{
		// Paned
		$paned = new GtkPaned(GtkOrientation::HORIZONTAL); // GtkHPaned and GtkVPaned is deprecated
		
		$paned->pack2(new GtkButton(), FALSE, FALSE);
		$paned->set_position(120);

		// Treeview
		$tree = new GtkTreeView();
			$renderer = new GtkCellRendererText();
			$column = new GtkTreeViewColumn("", $renderer, "text", 0);
			$tree->append_column($column);
		
		$model = new GtkListStore(GObject::TYPE_STRING);
		$model->append(["line 1"]); $model->append(["line 2"]); $model->append(["line 3"]);
		$model->append(["line 1"]); $model->append(["line 2"]); $model->append(["line 3"]);
		$model->append(["line 1"]); $model->append(["line 2"]); $model->append(["line 3"]);
		$model->append(["line 1"]); $model->append(["line 2"]); $model->append(["line 3"]);
		$model->append(["line 1"]); $model->append(["line 2"]); $model->append(["line 3"]);
		$tree->set_model($model);

		$scroll = new GtkScrolledWindow();
		$scroll->add($tree); // add_with_viewport is deprecated
		$scroll->set_policy(GtkPolicyType::AUTOMATIC, GtkPolicyType::AUTOMATIC);
		$paned->add1($scroll);

		// Create window
		$win = new GtkWindow();
		$win->set_default_size(300, 200);
		$win->add($paned);

		// Connects
		$win->connect("destroy", [$this, "GtkWindowDestroy"]);

		// Show all
		$win->show_all();
	}

	/**
	 * GtkWindow on Destroy
	 */
	public function GtkWindowDestroy($widget=NULL, $event=NULL)
	{
		Gtk::main_quit();
	}
}

// Start application
$app = new Application();
Gtk::main();