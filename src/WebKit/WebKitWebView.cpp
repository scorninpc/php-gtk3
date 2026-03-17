// Platform-specific WebView implementations
// This file includes the appropriate implementation based on the platform
// Note: Including .cpp files is intentional here to provide platform-specific
// implementations of the same class methods without requiring separate compilation units.

#ifdef _WIN32
    // Windows: Use Microsoft Edge WebView2
    #include "WebKitWebView_Windows.cpp"
#else
    // Unix/Linux/macOS: Use WebKit2GTK
    #include "WebKitWebView_Unix.cpp"
#endif
