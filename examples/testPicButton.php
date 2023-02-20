<?php

function disableScroll($widget, $event)
{
	$widget->emit_stop_by_name("scroll-event");
	return false;
}

Gtk::init();

defined("APPLICATION_PATH") || define("APPLICATION_PATH", dirname(__FILE__));

// Image only
$button1 = new GtkButton();
$button1->set_always_show_image(true);
$button1Pixbuf = GdkPixbuf::new_from_file_at_size(dirname(realpath(__FILE__)) . './logo.png', 32, 32);
$button1Image    = GtkImage::new_from_pixbuf($button1Pixbuf);
$button1->set_image($button1Image);

// Image and text 
$button2 = GtkButton::new_with_label('Test');
$button2->set_always_show_image(true);
$button2Pixbuf = GdkPixbuf::new_from_file_at_size(dirname(realpath(__FILE__)) . './logo.png', 32, 32);
$button2Image    = GtkImage::new_from_pixbuf($button2Pixbuf);
$button2->set_image($button2Image);

// Image test
$logoPixbuf =  GdkPixbuf::new_from_file_at_size(dirname(realpath(__FILE__)) . './logo.png', 32, 32);
$logoImage  = GtkImage::new_from_pixbuf($logoPixbuf);
$logoImage->set_size_request(250, 60);

$vbox = new GtkBox(GtkOrientation::VERTICAL, 5);
$vbox->add($logoImage);
$vbox->add($button1);
$vbox->add($button2);
// Window
$window = new GtkWindow();
$window->connect("destroy", function () {
	Gtk::main_quit();
});
$window->add($vbox);
$window->set_default_size(300, 200);
$window->show_all();

Gtk::main();
