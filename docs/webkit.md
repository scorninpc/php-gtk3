# WebKit Support

## Overview

PHP-GTK3 includes optional WebView widget support for displaying web content within GTK windows. The widget automatically adapts to its parent container size.

**Cross-Platform Support:**

- **Linux/macOS**: Uses WebKit2GTK (WebKit rendering engine)
- **Windows**: Uses Microsoft Edge WebView2 (Chromium/Edge rendering engine)

Two widget classes are available:

- **WebKitWebView** - The standard cross-platform WebView widget
- **GtkWebView** - A convenient alias with GTK-style naming (same functionality)

Both classes provide identical functionality across all platforms. Use whichever naming convention you prefer.

## Compilation

WebKit support is optional and controlled by the `WITH_WEBKIT=1` make flag.

### Install Dependencies

```bash
# Ubuntu/Debian
sudo apt-get install libwebkit2gtk-4.1-dev

# Fedora
sudo dnf install webkit2gtk4.1-devel
```

### Build with WebKit Support

```bash
make WITH_WEBKIT=1 -j 4
sudo make install
```

## Basic Usage

```php
<?php
Gtk::init();

$window = new GtkWindow();
$window->set_default_size(800, 600);

// You can use either WebKitWebView or GtkWebView (they're identical)
$webView = new GtkWebView();  // GTK-style naming
// or
// $webView = new WebKitWebView();  // WebKit-style naming

$scrolled = new GtkScrolledWindow();
$scrolled->add($webView);
$window->add($scrolled);

$webView->load_uri("https://www.example.com");

$window->show_all();
Gtk::main();
```

## Available Methods

### Loading Content

- `load_uri($uri)` - Load a URL
- `load_html($content, $base_uri)` - Load HTML content directly
- `reload()` - Reload the current page
- `stop_loading()` - Stop loading the current page

### Navigation

- `can_go_back()` - Check if can navigate back
- `go_back()` - Navigate to previous page
- `can_go_forward()` - Check if can navigate forward
- `go_forward()` - Navigate to next page

### JavaScript Integration

- `run_javascript($script)` - Execute JavaScript in the web view (PHP → JavaScript)
- `register_script_message_handler($name, $callback)` - Register custom message handler (JavaScript → PHP)
  - JavaScript sends messages using: `window.webkit.messageHandlers.name.postMessage(data)`
  - Callback receives message data as first parameter

### Settings & Info

- `enable_developer_extras()` - Enable Web Inspector for debugging
- `get_settings()` - Get WebKit settings object
- `get_uri()` - Get the current URI
- `get_title()` - Get the current page title
- `is_loading()` - Check if page is loading
- `set_user_data_folder($path)` - Set custom user data folder (Windows only)
  - **Windows**: Sets the directory where WebView2 stores cache, cookies, and local storage
  - **Must be called before widget is realized** (before window is shown)
  - **Linux/macOS**: No-op (WebKit2GTK uses WebKitWebsiteDataManager)
  - Default location on Windows: `./tmp` (relative to current directory)

## Examples

See the `examples/` directory for working examples:

- **webkit_simple.php** - Minimal WebKitWebView example
- **webkit_browser.php** - Full browser with navigation controls
- **webkit_communication.php** - Bidirectional JavaScript ↔ PHP communication
- **webkit_custom_data_folder.php** - Custom user data folder (Windows) with bidirectional communication

### Custom User Data Folder (Windows)

```php
<?php
Gtk::init();

$window = new GtkWindow();
$webView = new WebKitWebView();

// Set custom folder for WebView2 cache, cookies, etc.
// Must be called BEFORE the widget is shown
$webView->set_user_data_folder("C:/MyApp/WebViewData");

$scrolled = new GtkScrolledWindow();
$scrolled->add($webView);
$window->add($scrolled);

$webView->load_uri("https://www.example.com");

$window->show_all();
Gtk::main();
```

## JavaScript ↔ PHP Communication

### Setup (PHP Side)

```php
$webView = new WebKitWebView();

// Register a message handler named "phpApp"
$webView->register_script_message_handler("phpApp", function($messageData) {
    echo "Received from JavaScript: $messageData\n";
});
```

### Send Messages (JavaScript Side)

```javascript
// Send message to PHP
window.webkit.messageHandlers.phpApp.postMessage("Hello from JavaScript!");

// Send structured data
window.webkit.messageHandlers.phpApp.postMessage(
  JSON.stringify({
    type: "event",
    data: "value",
  })
);
```

### Execute JavaScript from PHP

```php
// Update page content from PHP
$webView->run_javascript("document.body.style.backgroundColor = 'lightblue';");

// Call JavaScript functions
$webView->run_javascript("myFunction('parameter');");
```

## Debugging

Enable Web Inspector for debugging JavaScript:

```php
$webView->enable_developer_extras();
```

Then right-click in the web page and select "Inspect Element" to access:

- Console (JavaScript errors and console.log output)
- Elements (DOM inspection)
- Network (HTTP requests)
- Debugger (JavaScript debugging)

## Troubleshooting

### Segfault on Close

**Important**: If you experience a segfault when closing WebKit applications, ensure the PHP `gd` extension is loaded **after** the `php-gtk3` extension in your `php.ini` file:

```ini
extension=php-gtk3
extension=gd
```

Loading extensions in the wrong order can cause segmentation faults during cleanup.

### Messages Not Received

**Important**: WebKit2GTK requires proper initialization for script message handlers:

1. The UserContentManager must be created **before** the WebView
2. Handlers must be registered on that manager
3. The WebView must be created **with** that manager

This is handled automatically in PHP-GTK3's implementation.

### Verify Handler Registration

In the Web Inspector Console:

```javascript
// Should show an object, not undefined
window.webkit.messageHandlers.phpApp;

// Test manually
window.webkit.messageHandlers.phpApp.postMessage("test");
```

### Signal Details

The `script-message-received::name` signal uses this signature:

```c
void callback(WebKitUserContentManager *manager,
              JSCValue *value,
              gpointer user_data)
```

The implementation properly extracts message values using JavaScriptCore's `jsc_value_to_string()` function.

## Architecture

- **Inheritance**: WebKitWebView extends GtkWidget
- **Platform-Specific Implementation**:
  - Linux/macOS: WebKit2GTK with UserContentManager
  - Windows: Microsoft Edge WebView2 with COM interfaces
- **Memory Management**: Properly unreferences resources in destructor
- **Security**: Input validation and null checks on all methods

## Platform-Specific Documentation

- **Windows WebView2**: See [webview2-windows.md](webview2-windows.md) for Windows-specific compilation and features
- **Unix WebKit2GTK**: This document covers Linux/macOS WebKit2GTK implementation

## Files

### Widget Classes

- **WebKitWebView** - Cross-platform WebView widget class
- **GtkWebView** - GTK-style alias (identical functionality)

### Source Code

- `src/WebKit/WebKitWebView.h` - Platform-aware header
- `src/WebKit/WebKitWebView.cpp` - Platform dispatcher
- `src/WebKit/WebKitWebView_Unix.cpp` - WebKit2GTK implementation
- `src/WebKit/WebKitWebView_Windows.cpp` - WebView2 implementation
- `src/Gtk/GtkWebView.h` - Alias header
- `src/Gtk/GtkWebView.cpp` - Alias implementation

### Build Integration

- `Makefile` - Optional compilation with `WITH_WEBKIT=1`
- `main.h` - Conditional include
- `main.cpp` - Conditional class registration
