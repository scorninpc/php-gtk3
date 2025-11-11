# Compiling WebView Support on Windows

## Overview

On Windows, PHP-GTK3 uses Microsoft Edge WebView2 instead of WebKit2GTK for web content rendering. WebView2 provides better Windows integration and uses the Chromium engine that comes with Microsoft Edge.

## Prerequisites

### 1. WebView2 SDK

Download and install the WebView2 SDK:

- Download from: https://developer.microsoft.com/en-us/microsoft-edge/webview2/
- Or use NuGet: `Microsoft.Web.WebView2`
- Extract the SDK to a known location (e.g., `C:\WebView2SDK`)

### 2. WebView2 Runtime

The WebView2 runtime is included in Windows 10/11 with Microsoft Edge installed. For distribution:

- End users need Microsoft Edge installed (comes with Windows 10/11)
- Or download the evergreen standalone installer from Microsoft

## Compilation Steps

### 1. Set Environment Variables

```cmd
set WEBVIEW2_SDK=C:\WebView2SDK
set WEBVIEW2_INCLUDE=%WEBVIEW2_SDK%\build\native\include
set WEBVIEW2_LIB=%WEBVIEW2_SDK%\build\native\x64
```

### 2. Update Visual Studio Project

Add to your project configuration:

**Include Directories:**

```
$(WEBVIEW2_INCLUDE)
```

**Library Directories:**

```
$(WEBVIEW2_LIB)
```

**Additional Dependencies:**

```
WebView2LoaderStatic.lib
```

### 3. Build with WebView Support

```cmd
nmake WITH_WEBKIT=1
```

Or in Visual Studio, define `WITH_WEBKIT` preprocessor directive.

## Code Structure

The WebView implementation uses conditional compilation:

```cpp
#ifdef _WIN32
    // Windows: Uses WebView2
    #include "WebKitWebView_Windows.cpp"
#else
    // Unix: Uses WebKit2GTK
    #include "WebKitWebView_Unix.cpp"
#endif
```

## WebView2 Features

All standard WebView methods are supported on Windows:

- `load_uri()` - Navigate to URL
- `load_html()` - Load HTML content
- `reload()` - Reload page
- `go_back()` / `go_forward()` - Navigation
- `run_javascript()` - Execute JavaScript
- `register_script_message_handler()` - JS → PHP messaging
- `enable_developer_extras()` - Enable DevTools

## Message Handling (JavaScript ↔ PHP)

On Windows, script message handlers use WebView2's web messaging:

**PHP Side:**

```php
$webView->register_script_message_handler("myHandler", function($data) {
    echo "Received from JS: $data\n";
});
```

**JavaScript Side:**

```javascript
// Send a message to the host using WebView2 API
window.chrome.webview.postMessage("myHandler:Hello from JavaScript!");

// Or, for custom message formats:
window.chrome.webview.postMessage("myHandler:Hello!");
```

## Troubleshooting

### "WebView2 not found"

Ensure:

1. WebView2 SDK is installed
2. Environment variables are set correctly
3. `WITH_WEBKIT=1` is defined during compilation

### "Failed to create environment"

Check:

1. Microsoft Edge is installed
2. WebView2 runtime is available
3. User has permissions to create WebView2 data folder

### DevTools not working

Call `enable_developer_extras()` before loading content:

```php
$webView->enable_developer_extras();
$webView->load_uri("https://example.com");
```

Then right-click in the web view and select "Inspect".

## Distribution

When distributing your application:

1. **Include WebView2Loader.dll** from the SDK
2. **Or** require Microsoft Edge (Windows 10/11 have it by default)
3. **Or** bundle the WebView2 evergreen runtime installer

The WebView2 runtime is small (~130MB) and automatically updates through Microsoft Edge.

## Differences from WebKit2GTK

While the PHP API is identical, there are minor platform differences:

| Feature           | WebKit2GTK (Unix)             | WebView2 (Windows)                |
| ----------------- | ----------------------------- | --------------------------------- |
| JavaScript Engine | JavaScriptCore                | V8 (Chromium)                     |
| DevTools          | WebKit Inspector              | Chromium DevTools                 |
| Rendering         | WebKit                        | Blink (Chromium)                  |
| Message Format    | window.webkit.messageHandlers | window.chrome.webview.postMessage |

The `register_script_message_handler()` method automatically handles these differences, providing a consistent API.
