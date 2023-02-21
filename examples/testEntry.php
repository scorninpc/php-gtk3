<?php


function disableScroll($widget, $event)
{

	$widget->emit_stop_by_name("scroll-event");

	return false;
}

Gtk::init();

defined("APPLICATION_PATH") || define("APPLICATION_PATH", dirname(__FILE__));

// Input Datum bis
$string = 'TESTSTRING';
$buffer = new GtkEntryBuffer($string, strlen($string));
$entry = GtkEntry::new_with_buffer($buffer);
//$entry->get_buffer()->set_text("aaaaaaaaaaaaaaaaaaaaaaaaaa\nbbbbbbbbbbbbbbbbbbbbbbb\ncccccccccccccccccccccc\ndddddddddddddddddddd");
$entry->set_text('32132133');

// Window
$window = new GtkWindow();
$window->connect("destroy", function () {
	Gtk::main_quit();
});
$window->add($entry);
$window->set_default_size(300, 200);
$window->show_all();

Gtk::main();
