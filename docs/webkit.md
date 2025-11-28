# WebKit Support

## Overview

PHP-GTK3 includes optional WebKitWebView widget support for displaying web content within GTK windows. The widget automatically adapts to its parent container size.

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

$webView = new WebKitWebView();
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

## Examples

See the `examples/` directory for working examples:

- **webkit_simple.php** - Minimal example
- **webkit_browser.php** - Full browser with navigation
- **webkit_js_to_php.php** - Bidirectional JavaScript ↔ PHP communication

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
window.webkit.messageHandlers.phpApp.postMessage('Hello from JavaScript!');

// Send structured data
window.webkit.messageHandlers.phpApp.postMessage(JSON.stringify({
    type: 'event',
    data: 'value'
}));
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
window.webkit.messageHandlers.phpApp

// Test manually
window.webkit.messageHandlers.phpApp.postMessage('test')
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
- **Initialization**: Creates UserContentManager before WebView
- **Memory Management**: Properly unreferences resources in destructor
- **Security**: Input validation and null checks on all methods

## Files

### Source Code
- `src/WebKit/WebKitWebView.h`
- `src/WebKit/WebKitWebView.cpp`

### Build Integration
- `Makefile` - Optional compilation with `WITH_WEBKIT=1`
- `main.h` - Conditional include
- `main.cpp` - Conditional class registration
