
#include "GtkInfoBar.h"

/**
 * Constructor
 */
GtkInfoBar_::GtkInfoBar_() = default;

/**
 * Destructor
 */
GtkInfoBar_::~GtkInfoBar_() = default;

void GtkInfoBar_::__construct()
{
	instance = (gpointer *)gtk_info_bar_new ();

}

Php::Value GtkInfoBar_::new_with_buttons(Php::Parameters &parameters)
{

	Php::Value arr = parameters[0];
    if(arr.size() < 2) {
         throw Php::Exception("parameters expect one button with response");
    }

	GtkWidget *instance_a = gtk_info_bar_new_with_buttons (arr[0], (int)arr[1], NULL);

	// Add buttons
    for(int index=2; index < (int)arr.size(); index+=2) {
        gtk_info_bar_add_button(GTK_INFO_BAR(instance_a), arr[index], (int)arr[index+1]);
        
    }

	GtkInfoBar_ *return_parsed = new GtkInfoBar_();
	return_parsed->set_instance((gpointer *)instance_a);
	return Php::Object("GtkInfoBar", return_parsed);
}

void GtkInfoBar_::add_action_widget(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint response_id = (gint)parameters[1];

	gtk_info_bar_add_action_widget (GTK_INFO_BAR(instance), child, response_id);

}

Php::Value GtkInfoBar_::add_button(Php::Parameters &parameters)
{
	std::string s_button_text = parameters[0];
	gchar *button_text = (gchar *)s_button_text.c_str();

	gint response_id = (gint)parameters[1];

	GtkWidget *ret = gtk_info_bar_add_button (GTK_INFO_BAR(instance), button_text, response_id);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

void GtkInfoBar_::add_buttons(Php::Parameters &parameters)
{
	Php::Value arr = parameters[0];
    if(arr.size() < 2) {
         throw Php::Exception("parameters expect one button with response");
    }

    // Add buttons
    for(int index=0; index < (int)arr.size(); index+=2) {
        gtk_info_bar_add_buttons(GTK_INFO_BAR(instance), arr[index], (int)arr[index+1]);
    }

}

void GtkInfoBar_::set_response_sensitive(Php::Parameters &parameters)
{
	gint response_id = (gint)parameters[0];

	gboolean setting = (gboolean)parameters[1];

	gtk_info_bar_set_response_sensitive (GTK_INFO_BAR(instance), response_id, setting);

}

void GtkInfoBar_::set_default_response(Php::Parameters &parameters)
{
	gint response_id = (gint)parameters[0];

	gtk_info_bar_set_default_response (GTK_INFO_BAR(instance), response_id);

}

void GtkInfoBar_::response(Php::Parameters &parameters)
{
	gint response_id = (gint)parameters[0];

	gtk_info_bar_response (GTK_INFO_BAR(instance), response_id);

}

void GtkInfoBar_::set_message_type(Php::Parameters &parameters)
{
	int int_message_type = (int)parameters[0];
	GtkMessageType message_type = (GtkMessageType)int_message_type;

	gtk_info_bar_set_message_type (GTK_INFO_BAR(instance), message_type);

}

Php::Value GtkInfoBar_::get_message_type()
{
	GtkMessageType ret = gtk_info_bar_get_message_type (GTK_INFO_BAR(instance));

	return ret;
}

Php::Value GtkInfoBar_::get_action_area()
{
	GtkWidget *ret = gtk_info_bar_get_action_area (GTK_INFO_BAR(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkInfoBar_::get_content_area()
{
	GtkWidget *ret = gtk_info_bar_get_content_area (GTK_INFO_BAR(instance));

	GtkContainer_ *return_parsed = new GtkContainer_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkContainer", return_parsed);
}

Php::Value GtkInfoBar_::get_show_close_button()
{
	gboolean ret = gtk_info_bar_get_show_close_button (GTK_INFO_BAR(instance));

	return ret;
}

void GtkInfoBar_::set_show_close_button(Php::Parameters &parameters)
{
	gboolean setting = (gboolean)parameters[0];

	gtk_info_bar_set_show_close_button (GTK_INFO_BAR(instance), setting);

}

