
# PHP-GTK3

PHP-GTK is a bind of GTK 3 to create desktop applications with PHP

## Acknowledgements

 - [Compile for window](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md)
 - [Compile for linux](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-linux.md)
 - [Compile for mac](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-mac.md)
 - [Appimage](https://github.com/scorninpc/php-gtk3/blob/master/docs/appimage.md)

## Contributing

Contributions are always welcome!

See [issues](https://github.com/scorninpc/php-gtk3/issues) for problems and improvements.

## How its works

PHP-GTK3 work with a middleway of [PHP-CPP](https://github.com/CopernicaMarketingSoftware/PHP-CPP). In addition to making work faster, syntax and how to program closely resemble PHP, so more people can contribute to the project. Another strong point, perhaps the most important are the updates of Zend.h. In the migration from PHP5 to PHP7 for example, every bind was lost. In that way, there is a nice community working on PHP-CPP to make this updated

## PHP-GTK 3 Cookbook

You can find a cookbook of codes compiled and organized in http://andor.com.br/php-gtk/cookbook

## Example

```php
<?php

// Initialize
Gtk::init();

// Callback for when window is closed
function GtkWindowDestroy($widget=NULL, $event=NULL)
{
	Gtk::main_quit();
}

// Create a window
$win = new GtkWindow();
$win->set_default_size(300, 200);

// Connect "close" event with callback
$win->connect("destroy", "GtkWindowDestroy");

// Show window
$win->show_all();

// Start
Gtk::main();
```

## Involved

- [@scorninpc](https://www.github.com/scorninpc) - Main dev
- [@subabrain](https://www.github.com/subabrain) - Thank you for your hard work to compile on Windows
- [@apss-pohl](https://github.com/apss-pohl) - A lot fixes and improvements

## Screenshots

![GTKTreeview](https://i.imgur.com/zrO87QV.jpg)

![GTKTreeview](https://i.imgur.com/NeEjyLj.jpg)

![GTK interactive debugger](https://i.imgur.com/P50OpKF.jpg)

![GTK interactive debugger](https://i.imgur.com/NZkie9R.jpg)

![Widgets](https://i.imgur.com/UpBIYQB.jpg)

![Tooltips](https://i.imgur.com/cGECrWu.jpg)

