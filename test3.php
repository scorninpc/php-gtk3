<?php

function GtkWindowDestroy($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	Gtk::main_quit();
}

function GtkWindowFocus($widget=NULL, $event=NULL, $param1=NULL, $param2=NULL, $param3=NULL, $param4=NULL)
{
	// var_dump("OK");
}

function GtkWindowReleased($widget=NULL, $event=NULL)
{
	// var_dump("OK");
}
function GtkWindowButton1Clicked($widget=NULL, $event=NULL)
{
	global $text;

	$buffer = $text->get_buffer();

	// $buffer->delete_selection(TRUE, TRUE);

	$iter = $buffer->get_iter_at_line_offset(1, 2);
	var_dump($iter->get_char());
	$iter->forward_line();
	var_dump($iter->get_char());

	// Tests
	// $buffer = $text->get_buffer();
	// $buffer->insert_at_cursor(date("Y-m-d"));

	// global $win;

	// // Move
	// $win->move(10, 10);

	// var_dump($widget);
	// var_dump($event);
}

function GtkWindowButton2Clicked($widget=NULL, $event=NULL)
{
	global $text;

	$buffer = $text->get_buffer();

	list($start, $end) = $buffer->get_selection_bounds();
	
	$buffer->delete($start, $end);

}

function GtkWindowButton3Clicked($widget=NULL, $event=NULL)
{

}

function GtkCellRendererToggled($renderer=NULL, $row=NULL)
{
	// echo "ok\n";
}

// ----------------------
// Horizontal box 2
$hbox = new GtkHBox(TRUE, 5);

// Button 1
// $btn1 = new GtkButton();
// $btn1->set_label("Button 1");
$btn1 = GtkButton::new_from_icon_name("help-faq", GtkIconSize::BUTTON);
$hbox->pack_start($btn1, TRUE, TRUE, 5);

// Button 2
$btn2 = GtkButton::new_with_mnemonic("Bu_tton 2");
$hbox->pack_start($btn2, TRUE, TRUE, 5);

// Button 3
$btn3 = GtkButton::new_with_label("Button 3");
$hbox->pack_start($btn3, TRUE, TRUE, 5);

// ----------------------
// Vertical box
$vbox = new GtkVBox(FALSE, 5);
$vbox->pack_start($hbox, FALSE, FALSE, 5);

// ----------------------
// Entry 1
$txt1 = new GtkEntry();
$vbox->pack_start($txt1, FALSE, FALSE, 5);

// ----------------------
// Window
$win = new GtkWindow(Gtk::WINDOW_TOPLEVEL);
$win->add($vbox);
$win->set_default_size(300, 200);
$win->set_title("PHP-GTK3 @ 7.3");
$win->set_position(GTK::WIN_POS_CENTER);
$win->set_type_hint(Gdk::WINDOW_TYPE_HINT_NORMAL);

// Icon from file
$win->set_icon_from_file("./logo.png");

// TextView
$text = GtkTextView::new_with_buffer(new GtkTextBuffer());
$text->set_wrap_mode(GtkWrapMode::CHAR);
$text->get_buffer()->set_text("aaaaaaaaaaaaaaaaaaaaaaaaaa\nbbbbbbbbbbbbbbbbbbbbbbb\ncccccccccccccccccccccc\ndddddddddddddddddddd");

$scroll = new GtkScrolledWindow();
$scroll->add($text);
$scroll->set_policy(GtkPolicyType::AUTOMATIC, GtkPolicyType::AUTOMATIC);

$vbox->pack_start($scroll, TRUE, TRUE, 5);



// Connects
$win->connect("destroy", "GtkWindowDestroy", "param 1", "param 2", "param 3", "param 4");
$btn1->connect("clicked", "GtkWindowButton1Clicked");
$btn2->connect("clicked", "GtkWindowReleased");
$btn2->connect("clicked", "GtkWindowButton2Clicked");
$btn3->connect("clicked", "GtkWindowButton3Clicked");

// Show all
$win->show_all();

// Loop
Gtk::main();