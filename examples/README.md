# PHP-GTK3 Examples

This directory contains examples demonstrating the use of PHP-GTK3 widgets and features.

## WebKit Examples

### webkit_simple.php

A minimal example showing how to display a web page in a GTK window using WebKitWebView.

**Requirements:**

- PHP-GTK3 compiled with `WITH_WEBKIT=1`
- webkit2gtk-4.1 library installed

**Usage:**

```bash
php -dextension=php-gtk3.so webkit_simple.php
```

### webkit_browser.php

A more complete example with navigation controls (back, forward, reload) and URL entry.

**Requirements:**

- PHP-GTK3 compiled with `WITH_WEBKIT=1`
- webkit2gtk-4.1 library installed

**Usage:**

```bash
php -dextension=php-gtk3.so webkit_browser.php
```

### webkit_communication.php

Demonstrates bidirectional communication between PHP/GTK and JavaScript in a WebKitWebView.

**Features:**

- **PHP → JavaScript**: Using `run_javascript()` to execute JavaScript code
  - Update DOM elements, change styles, call JS functions from PHP
  - Pass data from PHP to JavaScript
- **JavaScript → PHP**: Using script message handlers via `window.webkit.messageHandlers`
  - JavaScript sends messages to PHP using `window.webkit.messageHandlers.phpApp.postMessage()`
  - PHP receives messages via callback registered with `register_script_message_handler()`
- Interactive demo with GTK buttons (PHP→JS) and webpage buttons (JS→PHP)
- Message logging to show communication in both directions

**Requirements:**

- PHP-GTK3 compiled with `WITH_WEBKIT=1`
- webkit2gtk-4.1 library installed

**Usage:**

```bash
php -dextension=php-gtk3.so webkit_communication.php
```

## Compiling PHP-GTK3 with WebKit Support

To use the WebKit examples, you need to compile PHP-GTK3 with WebKit support:

1. Install WebKit2GTK development libraries:

   ```bash
   sudo apt-get install libwebkit2gtk-4.1-dev
   ```

2. Compile PHP-GTK3 with WebKit support:

   ```bash
   make WITH_WEBKIT=1 -j 4
   ```

3. Install the extension:
   ```bash
   sudo make install
   ```

For more information, see the [compilation documentation](../docs/compile-linux.md).
