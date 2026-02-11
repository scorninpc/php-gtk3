<?php

/**
 * WebKitWebView Bidirectional Communication Example
 * 
 * This example demonstrates bidirectional communication between PHP/GTK
 * and JavaScript in a WebKitWebView:
 * 
 * - PHP → JavaScript: Using run_javascript() to execute JavaScript code
 * - JavaScript → PHP: Using script message handlers via window.webkit.messageHandlers
 * 
 * This allows:
 * - PHP to update the DOM, call JS functions, send data to the web page
 * - JavaScript to send messages and data back to the PHP/GTK application
 * 
 * Note: This requires PHP-GTK3 to be compiled with WITH_WEBKIT=1
 */

// Initialize GTK
Gtk::init();

echo "[PHP] Starting Bidirectional WebKit Communication Example\n";
echo "[PHP] =====================================================\n";

// Callback for when window is closed
function onWindowDestroy()
{
    Gtk::main_quit();
}

// Create main window
$window = new GtkWindow();
$window->set_title("WebKit Bidirectional Communication");
$window->set_default_size(900, 700);
$window->connect("destroy", "onWindowDestroy");

// Create a vertical box for layout
$vbox = new GtkBox(Gtk::ORIENTATION_VERTICAL, 5);
$window->add($vbox);

// Create PHP → JS control panel
$phpToJsLabel = new GtkLabel("PHP → JavaScript Controls:");
$phpToJsLabel->set_xalign(0);
$vbox->pack_start($phpToJsLabel, false, false, 5);

$controlBox = new GtkBox(Gtk::ORIENTATION_HORIZONTAL, 5);
$vbox->pack_start($controlBox, false, false, 5);

// Create JS → PHP message log area
$jsToPhpLabel = new GtkLabel("Messages from JavaScript:");
$jsToPhpLabel->set_xalign(0);
$vbox->pack_start($jsToPhpLabel, false, false, 5);

// Create scrolled window for message log
$scrolledLog = new GtkScrolledWindow();
$scrolledLog->set_size_request(-1, 120);
$vbox->pack_start($scrolledLog, false, true, 0);

// Create text view for logging messages from JavaScript
$logView = new GtkTextView();
$logView->set_editable(false);
$buffer = $logView->get_buffer();
$scrolledLog->add($logView);

// Create WebKitWebView widget
echo "[PHP] Creating WebKitWebView widget...\n";
$webView = new WebKitWebView();
$webView->set_user_data_folder('./tmp');
echo "[PHP] WebKitWebView created successfully\n";

// Enable developer extras for debugging
echo "[PHP] Enabling Web Inspector (Developer Tools)...\n";
if (method_exists($webView, 'enable_developer_extras')) {
    $webView->enable_developer_extras();
    echo "[PHP] Web Inspector enabled. Right-click in the web page and select 'Inspect Element'.\n";
} else {
    echo "[PHP] WARNING: enable_developer_extras() method not available.\n";
}

// Register a script message handler named "phpApp" with a callback
// JavaScript can send messages using: window.webkit.messageHandlers.phpApp.postMessage(data)
echo "[PHP] Registering script message handler 'phpApp'...\n";
$webView->register_script_message_handler("phpApp", function ($messageData = null) use ($buffer) {
    // Callback is invoked when JavaScript sends a message
    $timestamp = date('H:i:s');

    if ($messageData !== null) {
        $message = "[$timestamp] JS→PHP: $messageData\n";
        echo "[PHP] Received message from JavaScript: $messageData\n";
    } else {
        $message = "[$timestamp] JS→PHP: (no data)\n";
        echo "[PHP] Received message from JavaScript (no data)\n";
    }

    $endIter = $buffer->get_end_iter();
    $buffer->insert($endIter, $message, -1);

    // Get a fresh end iterator after the insert to create the mark
    $newEndIter = $buffer->get_end_iter();
    $mark = $buffer->create_mark(null, $newEndIter, false);
});
echo "[PHP] Script message handler registered successfully\n";

// Create a scrolled window to contain the web view
$scrolled = new GtkScrolledWindow();
$scrolled->add($webView);
$vbox->pack_start($scrolled, true, true, 0);

// Button 1: Update Text
$btn1 = GtkButton::new_with_label("Update Page Title");
$btn1->connect("clicked", function () use ($webView) {
    echo "[PHP] Sending command to update page title...\n";
    $timestamp = date('H:i:s');
    $js = "document.getElementById('title').textContent = 'Updated at ' + " . json_encode($timestamp) . ";";
    $webView->run_javascript($js);
});
$controlBox->pack_start($btn1, true, true, 5);

// Button 2: Change Background Color
$btn2 = GtkButton::new_with_label("Random Background");
$btn2->connect("clicked", function () use ($webView) {
    echo "[PHP] Sending command to change background color...\n";
    $colors = ['#FFE0E0', '#E0FFE0', '#E0E0FF', '#FFE0FF', '#FFFFE0', '#E0FFFF'];
    $color = $colors[array_rand($colors)];
    $js = "document.body.style.backgroundColor = " . json_encode($color) . ";";
    $webView->run_javascript($js);
});
$controlBox->pack_start($btn2, true, true, 5);

// Button 3: Send Message to JS
$btn3 = GtkButton::new_with_label("Send Message to JS");
$btn3->connect("clicked", function () use ($webView) {
    echo "[PHP] Sending message to JavaScript...\n";
    $timestamp = date('H:i:s');
    $message = "Message from PHP at $timestamp";
    $js = "addPhpMessage(" . json_encode($message) . ");";
    $webView->run_javascript($js);
});
$controlBox->pack_start($btn3, true, true, 5);

// Button 4: Update Counter
$counter = 0;
$btn4 = GtkButton::new_with_label("PHP Counter (0)");
$btn4->connect("clicked", function () use ($webView, &$counter, $btn4) {
    $counter++;
    echo "[PHP] Incrementing counter to $counter...\n";
    $js = "updatePhpCounter($counter);";
    $webView->run_javascript($js);
    $btn4->set_label("PHP Counter ($counter)");
});
$controlBox->pack_start($btn4, true, true, 5);

// Static HTML content demonstrating bidirectional communication
$html = <<<'HTML'
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Bidirectional Communication</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f5f5f5;
            transition: background-color 0.3s ease;
        }
        h1 {
            color: #333;
        }
        .info-box {
            background: white;
            padding: 20px;
            border-radius: 8px;
            margin: 15px 0;
            box-shadow: 0 2px 4px rgba(0,0,0,0.1);
        }
        .section-title {
            font-size: 18px;
            font-weight: bold;
            color: #2196F3;
            margin-bottom: 10px;
        }
        button {
            background-color: #2196F3;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            margin: 5px;
            font-size: 13px;
        }
        button:hover {
            background-color: #1976D2;
        }
        button:active {
            background-color: #0D47A1;
        }
        .success {
            background-color: #4CAF50 !important;
        }
        .warning {
            background-color: #FF9800 !important;
        }
        #title {
            color: #2196F3;
            font-size: 24px;
            margin: 10px 0;
        }
        #phpCounter, #jsCounter {
            font-size: 36px;
            color: #F44336;
            font-weight: bold;
        }
        #phpMessages, #jsMessages {
            background: #263238;
            color: #aed581;
            padding: 10px;
            border-radius: 4px;
            font-family: 'Courier New', monospace;
            min-height: 60px;
            max-height: 120px;
            overflow-y: auto;
            font-size: 12px;
        }
        .message-item {
            padding: 3px 0;
            border-bottom: 1px solid #37474F;
        }
        .message-item:last-child {
            border-bottom: none;
        }
        .code {
            background: #263238;
            color: #aed581;
            padding: 10px;
            border-radius: 4px;
            font-family: 'Courier New', monospace;
            margin: 8px 0;
            overflow-x: auto;
            font-size: 11px;
        }
        .grid {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 15px;
        }
        @media (max-width: 800px) {
            .grid {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>
<body>
    <h1>Bidirectional WebKit Communication</h1>
    
    <div class="info-box">
        <h2 id="title">Communication Active</h2>
    </div>
    
    <div class="grid">
        <div class="info-box">
            <div class="section-title">PHP → JavaScript</div>
            <p>PHP Counter: <span id="phpCounter">0</span></p>
            <div id="phpMessages">
                <div class="message-item">Waiting for messages from PHP...</div>
            </div>
        </div>
        
        <div class="info-box">
            <div class="section-title">JavaScript → PHP</div>
            <p>JS Counter: <span id="jsCounter">0</span></p>
            <div>
                <button onclick="sendSimpleMessage()">Send Simple Message</button>
                <button class="success" onclick="sendTextMessage()">Send Text Data</button>
                <button class="warning" onclick="sendCounterValue()">Send Counter Value</button>
                <button onclick="incrementJsCounter()">Increment JS Counter</button>
            </div>
        </div>
    </div>
    
    <div class="info-box">
        <h3>How It Works</h3>
        <div class="grid">
            <div>
                <strong>PHP → JavaScript:</strong>
                <div class="code">
$webView->run_javascript("yourCode();");
                </div>
            </div>
            <div>
                <strong>JavaScript → PHP:</strong>
                <div class="code">
window.webkit.messageHandlers
  .phpApp.postMessage(data);
                </div>
            </div>
        </div>
    </div>
    
    <script>
        let jsCounter = 0;
        let messageCount = 0;
        
        // PHP → JS: Function to add a message from PHP
        function addPhpMessage(message) {
            const messagesDiv = document.getElementById('phpMessages');
            const messageItem = document.createElement('div');
            messageItem.className = 'message-item';
            messageItem.textContent = message;
            messagesDiv.appendChild(messageItem);
            messagesDiv.scrollTop = messagesDiv.scrollHeight;
            console.log('[JS] Received from PHP:', message);
        }
        
        // PHP → JS: Function to update the counter from PHP
        function updatePhpCounter(value) {
            const counterElement = document.getElementById('phpCounter');
            counterElement.textContent = value;
            counterElement.style.transform = 'scale(1.2)';
            setTimeout(() => {
                counterElement.style.transition = 'transform 0.3s ease';
                counterElement.style.transform = 'scale(1)';
            }, 100);
            console.log('[JS] PHP counter updated to:', value);
        }
        
        // JS → PHP: Send simple message to PHP
        function sendSimpleMessage() {
            try {
                window.webkit.messageHandlers.phpApp.postMessage('Hello from JavaScript!');
                messageCount++;
                console.log('[JS] Sent simple message to PHP (#' + messageCount + ')');
            } catch (e) {
                console.error('[JS] Error sending message:', e);
            }
        }
        
        // JS → PHP: Send text message to PHP
        function sendTextMessage() {
            try {
                const timestamp = new Date().toLocaleTimeString();
                window.webkit.messageHandlers.phpApp.postMessage('Message at ' + timestamp);
                messageCount++;
                console.log('[JS] Sent text message to PHP (#' + messageCount + ')');
            } catch (e) {
                console.error('[JS] Error sending message:', e);
            }
        }
        
        // JS → PHP: Send counter value to PHP
        function sendCounterValue() {
            try {
                window.webkit.messageHandlers.phpApp.postMessage('JS Counter value: ' + jsCounter);
                messageCount++;
                console.log('[JS] Sent counter value to PHP (#' + messageCount + ')');
            } catch (e) {
                console.error('[JS] Error sending message:', e);
            }
        }
        
        // Increment JavaScript counter
        function incrementJsCounter() {
            jsCounter++;
            document.getElementById('jsCounter').textContent = jsCounter;
            // Also send update to PHP
            try {
                window.webkit.messageHandlers.phpApp.postMessage('JS counter incremented to ' + jsCounter);
            } catch (e) {
                console.error('[JS] Error sending message:', e);
            }
        }
        
        // Auto-send a welcome message when loaded
        window.addEventListener('load', function() {
            setTimeout(function() {
                try {
                    window.webkit.messageHandlers.phpApp.postMessage('Page loaded successfully!');
                    console.log('[JS] Initial message sent to PHP');
                } catch (e) {
                    console.error('[JS] WebKit message handler not available');
                }
            }, 500);
        });
    </script>
</body>
</html>
HTML;

// Load the HTML content
echo "[PHP] Loading HTML content into WebView...\n";
$webView->load_html($html, "about:blank");
echo "[PHP] HTML content loaded\n";

// Show all widgets
echo "[PHP] Showing all widgets...\n";
$window->show_all();
echo "[PHP] Widgets shown\n";

// Log initial message
$endIter = $buffer->get_end_iter();
$buffer->insert($endIter, "Waiting for messages from JavaScript...\n", -1);

// Send an initial message after a short delay to demonstrate PHP → JS communication
Gtk::timeout_add(1000, function () use ($webView) {
    echo "[PHP] Sending initial welcome message...\n";
    $js = "addPhpMessage(" . json_encode('Welcome! PHP can send messages to JavaScript.') . ");";
    $webView->run_javascript($js);
    return false; // Don't repeat
});

// Start GTK main loop
echo "[PHP] Starting GTK main loop...\n";
echo "[PHP] Application running. Use GTK buttons for PHP→JS, webpage buttons for JS→PHP.\n";
Gtk::main();
