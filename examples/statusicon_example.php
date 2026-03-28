<?php

/**
 * GtkStatusIcon Example with GIcon Support
 * 
 * This example demonstrates how to use GtkStatusIcon with GIcon
 * to avoid the gtk_widget_get_scale_factor assertion issue.
 * 
 * The problem: GtkStatusIcon is NOT a GtkWidget, but GTK internally 
 * calls gtk_widget_get_scale_factor on it when loading icons from 
 * pixbufs, causing assertion failures in some environments.
 * 
 * The solution: Use GIcon as an intermediate format. GIcon-based 
 * methods (set_from_gicon, new_from_gicon) do NOT trigger the 
 * scale factor assertion.
 */

// Initialize GTK
Gtk::init();
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

// Example 1: Create a status icon from a pixbuf using GIcon
echo "Example 1: Creating status icon from pixbuf via GIcon\n";
echo "-------------------------------------------------------\n";


// Convert the pixbuf to a GIcon
// This is the key step that avoids the scale factor issue
$gicon = GIcon::new_from_pixbuf($pixbuf);

// Method 1: Create new status icon from GIcon (static method)
$status_icon1 = GtkStatusIcon::new_from_gicon($gicon);
$status_icon1->set_title("Status Icon from GIcon");
$status_icon1->set_visible(true);

echo "✓ Created status icon using GtkStatusIcon::new_from_gicon()\n";
echo "  Title: " . $status_icon1->get_title() . "\n";
echo "  Visible: " . ($status_icon1->get_visible() ? "yes" : "no") . "\n";
echo "  Embedded: " . ($status_icon1->is_embedded() ? "yes" : "no") . "\n\n";

// Example 2: Set icon on existing status icon using GIcon
echo "Example 2: Setting icon on existing status icon\n";
echo "------------------------------------------------\n";


// Convert to GIcon
$gicon2 = GIcon::new_from_pixbuf($pixbuf);

// Create an empty status icon and then set the icon
$status_icon2 = new GtkStatusIcon();
$status_icon2->set_from_gicon($gicon2);  // Use set_from_gicon instead of set_from_pixbuf
$status_icon2->set_title("Another Status Icon");
$status_icon2->set_tooltip_text("This icon was set using set_from_gicon()");
$status_icon2->set_visible(true);

echo "✓ Set icon using set_from_gicon()\n";
echo "  Title: " . $status_icon2->get_title() . "\n";
echo "  Tooltip: " . $status_icon2->get_tooltip_text() . "\n\n";

// Example 3: Load icon from file and convert to GIcon
echo "Example 3: Loading icon from file via GIcon\n";
echo "--------------------------------------------\n";

$gicon3 = GIcon::new_from_pixbuf($pixbuf);
$status_icon3 = GtkStatusIcon::new_from_gicon($gicon3);
$status_icon3->set_title("Icon from File (via GIcon)");
$status_icon3->set_visible(true);

echo "✓ Created icon from pixbuf converted to GIcon\n";
echo "  Icon is visible in system tray\n\n";

// Example 4: Retrieve the GIcon from a status icon
echo "Example 4: Getting GIcon from status icon\n";
echo "------------------------------------------\n";

$retrieved_gicon = $status_icon1->get_gicon();
if ($retrieved_gicon !== null) {
    echo "✓ Successfully retrieved GIcon from status icon\n";
    echo "  GIcon object: " . get_class($retrieved_gicon) . "\n\n";
} else {
    echo "✗ No GIcon set on this status icon\n\n";
}

// Example 5: Comparison with traditional methods
echo "Example 5: Why use GIcon?\n";
echo "-------------------------\n";
echo "Traditional methods (set_from_pixbuf, new_from_pixbuf) may trigger:\n";
echo "  'gtk_widget_get_scale_factor: assertion GTK_IS_WIDGET (widget) failed'\n\n";
echo "GIcon-based methods (set_from_gicon, new_from_gicon) do NOT trigger this\n";
echo "assertion because they don't attempt to query widget properties.\n\n";
echo "Use GIcon when:\n";
echo "  • You experience assertion failures with set_from_pixbuf()\n";
echo "  • Your application crashes when loading icons\n";
echo "  • You want more control over icon representation\n\n";

echo "Best Practice:\n";
echo "  1. Load your image as GdkPixbuf\n";
echo "  2. Convert to GIcon using GIcon::new_from_pixbuf()\n";
echo "  3. Use GtkStatusIcon::new_from_gicon() or set_from_gicon()\n\n";

echo "All examples completed successfully!\n";
echo "Check your system tray for the status icons.\n";

// Example 6: Using stock icons with GIcon
echo "\nExample 6: Creating status icon from stock ID via GIcon\n";
echo "---------------------------------------------------------\n";

// Create a GIcon from a stock ID
// This avoids any pixbuf loading and scale factor issues
$gicon_stock = GIcon::new_from_stock("gtk-dialog-info");

// Create status icon from the stock GIcon
$status_icon_stock = GtkStatusIcon::new_from_gicon($gicon_stock);
$status_icon_stock->set_title("Stock Icon via GIcon");
$status_icon_stock->set_tooltip_text("Info icon from stock");
$status_icon_stock->set_visible(true);

echo "✓ Created status icon from stock ID using GIcon\n";
echo "  Stock ID: gtk-dialog-info\n";
echo "  This method NEVER triggers scale factor assertions\n\n";

echo "Stock icons you can try:\n";
echo "  - gtk-dialog-info\n";
echo "  - gtk-dialog-warning\n";
echo "  - gtk-dialog-error\n";
echo "  - gtk-dialog-question\n";
echo "  - gtk-apply\n";
echo "  - gtk-cancel\n\n";

// Keep the application running so icons stay visible
echo "\nPress Ctrl+C to exit.\n";

// Simple GTK main loop
Gtk::main();
