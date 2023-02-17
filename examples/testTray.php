<?php
function check_menu()
{
    $menu = new GtkMenu();

    $menu->append(new GtkSeparatorMenuItem());
    $quit = GtkMenuItem::new_with_label('Quit');
    $quit->connect('activate', function () {
        var_dump('Quit');
    });

    $menu->append($quit);

    $menu->show_all();
    return $menu;
}


Gtk::init();

defined("APPLICATION_PATH") || define("APPLICATION_PATH", dirname(__FILE__));

$tray = GtkStatusIcon::new_from_file(dirname(realpath(__FILE__)) . "/logo.png");
$tray->set_tooltip_text($tooltip);
$tray->connect("button_press_event", function ($widget, $event = null) {
    if ($event->button->button == 3) {
        // Right click
        $menu = check_menu();
        $menu->popup_at_pointer($event);
        $menu->show_all();
    }
});

$tray->set_visible(true);

$entry = new GtkEntry();
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
