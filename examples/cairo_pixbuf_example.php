<?php

/**
 * Example: Using Gdk::cairo_set_source_pixbuf
 *
 * This example demonstrates how to use the Gdk::cairo_set_source_pixbuf function
 * to draw a pixbuf (image) on a drawing area using Cairo.
 *
 * The function sets a pixbuf as the source for a Cairo context, allowing you to
 * paint images onto widgets that support Cairo drawing.
 *
 * Function signature:
 * Gdk::cairo_set_source_pixbuf(GdkEvent $cairo_context, GdkPixbuf $pixbuf, int|float $x, int|float $y)
 *
 * Parameters:
 *   $cairo_context - The Cairo context (passed as GdkEvent from draw signal due to G_TYPE_BOXED handling)
 *   $pixbuf        - The GdkPixbuf to use as source
 *   $x             - X coordinate to place the pixbuf
 *   $y             - Y coordinate to place the pixbuf
 */
Gtk::init();

// Create main window
$window = new GtkWindow();
$window->set_title('Cairo Pixbuf Example');
$window->set_default_size(400, 300);
$window->connect('destroy', function () {
    Gtk::main_quit();
});

// Create drawing area
$drawing_area = new GtkDrawingArea();
$window->add($drawing_area);

// Create a simple test icon file
$icon_file = '/tmp/test_icon.png';
if (!file_exists($icon_file)) {
    // Create a simple 48x48 PNG icon with true color support
    $image = imagecreatetruecolor(48, 48);
    $bg = imagecolorallocate($image, 255, 0, 0); // Red background
    $fg = imagecolorallocate($image, 255, 255, 255); // White foreground
    imagefilledrectangle($image, 0, 0, 48, 48, $bg);
    imagefilledellipse($image, 24, 24, 30, 30, $fg);
    imagepng($image, $icon_file);
    imagedestroy($image);
};

$pixbuf = GdkPixbuf::new_from_file($icon_file);

// Connect to draw signal
$drawing_area->connect('draw', function ($widget, $cairo_context) use ($pixbuf) {
    // The cairo context is passed as a GdkEvent object from the draw signal
    // (This is due to how G_TYPE_BOXED types are handled in the callback system)

    // Set the pixbuf as the source for the cairo context at position (50, 50)
    Gdk::cairo_set_source_pixbuf($cairo_context, $pixbuf, 50, 50);

    // Paint the pixbuf onto the drawing area
    Gdk::cairo_paint($cairo_context);

    return false;
});

// Show all widgets
$window->show_all();

// Start GTK main loop
Gtk::main();
