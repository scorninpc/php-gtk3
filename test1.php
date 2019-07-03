<?php

function GtkWindowDestroy($widget=NULL, $event=NULL)
{
	Gtk::main_quit();
}

$win = new GtkWindow();
$win->set_default_size(300, 200);
$win->connect("destroy", "GtkWindowDestroy");
$win->show_all();


/*
// Create dialog with buttons
$dialog = new GtkRecentChooserDialog("Recent Files", $win, ["OK", GtkResponseType::OK, "Cancel", GtkResponseType::CANCEL]);
$dialog->set_select_multiple(TRUE);

// run
$result = $dialog->run();
if($result == GtkResponseType::OK) {
	// var_dump($dialog->get_current_uri());
}
$dialog->destroy();
*/

/*
// Create dialog with buttons
$dialogBox = GtkDialog::new_with_buttons("Pergunta", $win, GtkDialogFlags::MODAL, ["OK", GtkResponseType::OK, "Cancel", GtkResponseType::CANCEL]);
	// Create content area
	$hbox = new GtkBox(GtkOrientation::HORIZONTAL);
	$label = new GtkLabel("Hello!");
	$hbox->pack_start($label, FALSE, FALSE);

	// Add the content area
	$topArea = $dialogBox->get_content_area();
	$topArea->add($hbox);
	$dialogBox->show_all();

	// run
	$result = $dialogBox->run();
	if($result == GtkResponseType::OK) {
		var_dump("OK");
	}
	$dialogBox->destroy();
*/

/*
// Create a message dialog
$dialog = GtkMessageDialog::new_with_markup($win, GtkDialogFlags::MODAL, GtkMessageType::INFO, GtkButtonsType::OK, "Want close PHP-GTK3 test program?");
	// run
	$result = $dialog->run();
	if($result == GtkResponseType::OK) {
		var_dump("OK");
	}
	$dialog->destroy();
*/

/*
// File chooser
$dialog = new GtkFileChooserDialog("Open file", $win, GtkFileChooserAction::OPEN, ["Cancel", GtkResponseType::CANCEL, "Ok", GtkResponseType::OK]);

	// filters
	$filter = new GtkFileFilter();
	$filter->set_name("PHP Files");
	$filter->add_pattern("*.php");
	$dialog->add_filter($filter);

	// run with filter
	$dialog->set_select_multiple(TRUE);
	$result = $dialog->run();
	if($result == GtkResponseType::OK) {
		var_dump($dialog->get_filenames());
	}
	$dialog->destroy();

	// Remove filters
	$a = $dialog->list_filters();
	foreach($a as $b) {
		$dialog->remove_filter($b);
	}

	// run without filters
	$dialog->set_select_multiple(TRUE);
	$result = $dialog->run();
	if($result == GtkResponseType::OK) {
		var_dump($dialog->get_filenames());
	}
	$dialog->destroy();
*/

/*
$dialog = GtkDialog::new_with_buttons("TITLE", $win, GtkDialogFlags::MODAL, [
	"_Quit", GtkResponseType::CANCEL
]);
$dialog->run();
$dialog->destroy();
*/


/*
// About
$dialog = new GtkAboutDialog();

$dialog->set_authors("OK");

$dialog->run();
$dialog->destroy();
*/



Gtk::main();