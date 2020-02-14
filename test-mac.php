<?php

$application = new GtkApplication("br.com.pitteli.example", GApplication::FLAGS_NONE);
$application->connect("activate", function($application) {


	// Mac
	$osx = new GtkosxApplication();

	$pixbuf = GdkPixbuf::new_from_file("./logo.png");
	$osx->set_dock_icon_pixbuf($pixbuf);
	$menuTest = GtkMenuItem::new_with_label("New File");
	$osx->insert_app_menu_item($menuTest, 1);

	$menu = $menuTest->get_parent()->get_parent();
	var_dump($menu);

	$mnuAbout = GtkMenuItem::new_with_label("About"); 
	$menu->append($mnuAbout);


	// Window
	$window = $application->window_new();
	$window->set_title("PHP-GTK Window");
	$window->show_all();

});

$status = GApplication::run($application);
