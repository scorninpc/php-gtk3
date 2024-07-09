---
name: Bug report
about: Create a report to help us improve
title: ''
labels: ''
assignees: ''

---

**Describe the bug**
A clear and concise description of what the bug is.

**Small working code**
```php
<?php

	Gtk::init();

	// create a window
	$window = new GtkWindow();
	$window->set_size_request(500, 500);

	/**
	 * add your widget or logic here, that couse the problem
	 */
	
	
	// connect to signal that close program
	$window->connect("destroy", function() {
		Gtk::main_quit();
	});

	// show all and start
	$window->show_all();
	Gtk::main();
```

**Expected behavior**
A clear and concise description of what you expected to happen.

**Screenshots**
If applicable, add screenshots to help explain your problem.

**Version**
 - Linux, Windows or Mac?: 
 - Using pre-build binary? Which version?:
 - Did you compiled? What your PHP full version?:

**Additional context**
Add any other context about the problem here.
