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

		// Create notebook
		$this->ntb = new GtkNotebook();
		$this->ntb->set_tab_pos(GtkPositionType::RIGHT);
		$paned->add2($this->ntb);

		
		$this->ntb->append_page($this->b = GtkButton::new_with_label("BRUNO"));
		$this->ntb->append_page(GtkButton::new_with_label("OK 1"));
		$this->ntb->insert_page(GtkButton::new_with_label("___"), GtkButton::new_with_label("X"), 0);
		// $this->ntb->append_page(GtkButton::new_with_label("OK 2"));


		$this->b->connect("clicked", [$this, "b_clicked"]);

		// Create window
		$win = new GtkWindow();
		$win->set_default_size(800, 600);
		$win->add($paned);

		// Connects
		$win->connect("destroy", [$this, "GtkWindowDestroy"]);

		// Show all
		$win->show_all();
	}

	public function b_clicked ($widget)
	{
		$child = $this->ntb->get_nth_page(1);
		
		var_dump($this->ntb->get_tab_label_text($child));

		// $num = $this->ntb->get_current_page();
		// $this->ntb->remove_page($num);
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