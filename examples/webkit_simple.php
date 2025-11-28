<?php

/**
 * Simple WebKitWebView Example
 * 
 * This example shows the minimal code needed to display a web page
 * in a GTK window using WebKitWebView.
 * 
 * Note: This requires PHP-GTK3 to be compiled with WITH_WEBKIT=1
 */

// Initialize GTK
Gtk::init();

// Callback for when window is closed
function onWindowDestroy()
{
    Gtk::main_quit();
}

// Create main window
$window = new GtkWindow();
$window->set_title("Simple WebKit Example");
$window->set_default_size(800, 600);
$window->connect("destroy", "onWindowDestroy");

// Create WebKitWebView widget
$webView = new WebKitWebView();

// Create a scrolled window to make the WebView scrollable
// The WebView will automatically resize to fit its parent
$scrolled = new GtkScrolledWindow();
$scrolled->add($webView);
$window->add($scrolled);

// Load a URL
$webView->load_uri("https://www.example.com");

// Show all widgets
$window->show_all();

// Start GTK main loop
Gtk::main();
