<?php



// Create a css provider
$css_provider = new GtkCssProvider();
$ret = $css_provider->load_from_data("label {color: red; font-size: 35px; padding: 30px; }");
if(!$ret) {
	die("Css Error\n");
}

// GtkLabel
$gtk_label = new GtkLabel(" - My Label - ");

// Add the css to context
$style_context = $gtk_label->get_style_context();
$style_context->add_provider($css_provider, 600);

// GtkSourceView
$gtk_sourceview = new GtkSourceView();
$gtk_sourceview_scroll = new GtkScrolledWindow();
$gtk_sourceview_scroll->add($gtk_sourceview);

// Box
$hbox = new GtkBox(GtkOrientation::VERTICAL);
$hbox->pack_start($gtk_label, FALSE, FALSE);
$hbox->pack_start($gtk_sourceview_scroll, TRUE, TRUE);

// GtkWindow
$gtk_window = new GtkWindow();
$gtk_window->connect("destroy", ["Gtk", "main_quit"]);
$gtk_window->add($hbox);
$gtk_window->set_size_request(500, 400);
$gtk_window->show_all();

// Loop
Gtk::main();