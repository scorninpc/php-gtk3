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

// GtkWindow
$gtk_window = new GtkWindow();
$gtk_window->connect("destroy", ["Gtk", "main_quit"]);
$gtk_window->add($gtk_label);
$gtk_window->show_all();

// Loop
Gtk::main();