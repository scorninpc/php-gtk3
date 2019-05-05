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
		$this->ntb->set_tab_pos(GtkPositionType::TOP);
		$paned->add2($this->ntb);

		
		$this->create_new_tab("GtkLabel.cpp");
		$this->create_new_tab("GtkLabel.h");
		$this->create_new_tab("main.cpp");
		$this->create_new_tab("main.h");
		
		// $this->b->connect("clicked", [$this, "b_clicked"]);

		// Create window
		$win = new GtkWindow();
		$win->set_default_size(800, 600);
		$win->add($paned);

		// Connects
		$win->connect("destroy", [$this, "GtkWindowDestroy"]);

		// $win->set_interactive_debugging(TRUE);

		// Show all
		$win->show_all();
	}

	public function create_new_tab($label)
	{
		$hbox = new GtkHBox();
		$button_close = GtkButton::new_with_label("x");
		$label = new GtkLabel($label);
		$hbox->pack_start($label, TRUE, TRUE);
		$hbox->pack_start($button_close, FALSE, FALSE);

		$this->ntb->insert_page(new GtkLabel(""), $hbox);

		$button_close->connect("clicked", [$this, "close_tab"], $hbox);


		$hbox->show_all();
	}

	public function close_tab($widget=NULL, $event=NULL, $child=NULL)
	{
		// $this->ntb->remove_page($page_num);

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