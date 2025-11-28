<?php

/**
 * WebKitWebView Example
 * 
 * This example demonstrates how to use the WebKitWebView widget
 * to display web content in a GTK window.
 * 
 * Note: This requires PHP-GTK3 to be compiled with WITH_WEBKIT=1
 */

// Initialize GTK
Gtk::init();

// Callback for when window is closed
function onWindowDestroy($widget = NULL, $event = NULL)
{
    Gtk::main_quit();
}

// Create main window
$window = new GtkWindow();
$window->set_title("WebKit Browser Example");
$window->set_default_size(800, 600);
$window->connect("destroy", "onWindowDestroy");

// Create a vertical box for layout
$vbox = new GtkBox(Gtk::ORIENTATION_VERTICAL, 5);
$window->add($vbox);

// Create URL entry and navigation controls
$hbox = new GtkBox(Gtk::ORIENTATION_HORIZONTAL, 5);
$vbox->pack_start($hbox, false, false, 5);

// Back button
$backButton = new GtkButton("◀ Back");
$hbox->pack_start($backButton, false, false, 0);

// Forward button
$forwardButton = new GtkButton("Forward ▶");
$hbox->pack_start($forwardButton, false, false, 0);

// Reload button
$reloadButton = new GtkButton("⟳ Reload");
$hbox->pack_start($reloadButton, false, false, 0);

// URL entry
$urlEntry = new GtkEntry();
$urlEntry->set_text("https://www.example.com");
$hbox->pack_start($urlEntry, true, true, 0);

// Go button
$goButton = new GtkButton("Go");
$hbox->pack_start($goButton, false, false, 0);

// Create WebKitWebView widget
$webView = new WebKitWebView();

// Create a scrolled window to contain the web view
$scrolled = new GtkScrolledWindow();
$scrolled->add($webView);
$vbox->pack_start($scrolled, true, true, 0);

// Status bar
$statusbar = new GtkStatusbar();
$vbox->pack_start($statusbar, false, false, 0);
$contextId = $statusbar->get_context_id("status");

// Load initial URL
$webView->load_uri($urlEntry->get_text());

// Connect Go button
$goButton->connect("clicked", function() use ($webView, $urlEntry) {
    $url = $urlEntry->get_text();
    
    // Add http:// if no protocol specified
    if (!preg_match('/^https?:\/\//i', $url)) {
        $url = 'http://' . $url;
        $urlEntry->set_text($url);
    }
    
    $webView->load_uri($url);
});

// Connect URL entry (press Enter to load)
$urlEntry->connect("activate", function() use ($webView, $urlEntry) {
    $url = $urlEntry->get_text();
    
    // Add http:// if no protocol specified
    if (!preg_match('/^https?:\/\//i', $url)) {
        $url = 'http://' . $url;
        $urlEntry->set_text($url);
    }
    
    $webView->load_uri($url);
});

// Connect Back button
$backButton->connect("clicked", function() use ($webView, $backButton) {
    if ($webView->can_go_back()) {
        $webView->go_back();
    }
});

// Connect Forward button
$forwardButton->connect("clicked", function() use ($webView, $forwardButton) {
    if ($webView->can_go_forward()) {
        $webView->go_forward();
    }
});

// Connect Reload button
$reloadButton->connect("clicked", function() use ($webView) {
    $webView->reload();
});

// Update URL entry when navigation occurs
// Note: You may need to connect to appropriate signals for this
// This is a simplified example

// Show all widgets
$window->show_all();

// Start GTK main loop
Gtk::main();
