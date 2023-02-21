<?php


function disableScroll($widget, $event)
{

	$widget->emit_stop_by_name("scroll-event");

	return false;
}

Gtk::init();

defined("APPLICATION_PATH") || define("APPLICATION_PATH", dirname(__FILE__));

$field = new GtkComboBox();
$store = new GtkListStore(GObject::TYPE_STRING, GObject::TYPE_STRING);
$renderer    = new GtkCellRendererText();

foreach (['Test1', 'Test2', 'Test3', 'Test4', 'Test5', 'Test6', 'Test7', 'Test8',] as $key => $entry) {
	$store->append(array($key, $entry));
}
$field->set_model($store);

$field->pack_start($renderer, false, false, 0);
$field->add_attribute($renderer, 'text', 1);
$field->set_size_request(-1, 30);
$field->connect('scroll-event', function () {
	var_dump(2222);
	return true;
});

// Target GTK2 CODE
// $field->connect('scroll_event', function ($widget, $event) {
// 	$widget->emit_stop_by_name("scroll-event");
// 	return false;
// });

// Window
$window = new GtkWindow();
$window->connect("destroy", function () {
	Gtk::main_quit();
});
$window->add($field);
$window->set_default_size(300, 200);
$window->show_all();

Gtk::main();
