
#include "GtkMessageDialog.h"

/**
 * Constructor
 */
GtkMessageDialog_::GtkMessageDialog_() = default;

/**
 * Destructor
 */
GtkMessageDialog_::~GtkMessageDialog_() = default;

void GtkMessageDialog_::__construct(Php::Parameters &parameters)
{
	GtkWindow *parent;
	if(parameters.size() > 0) {
		Php::Value object_parent = parameters[0];
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	}

	int int_flags = (int)parameters[1];
	GtkDialogFlags flags = (GtkDialogFlags)int_flags;

	int int_type = (int)parameters[2];
	GtkMessageType type = (GtkMessageType)int_type;

	int int_buttons = (int)parameters[3];
	GtkButtonsType buttons = (GtkButtonsType)int_buttons;

	std::string s_message_format = parameters[4];
	gchar *message_format = (gchar *)s_message_format.c_str();


	std::string s_text = "";
	if(parameters.size() > 1) {
		std::string a_text = parameters[1];
		s_text = a_text;
	}
	
	instance = (gpointer *)gtk_message_dialog_new (parent, flags, type, buttons, message_format, s_text.c_str());

}

Php::Value GtkMessageDialog_::new_with_markup(Php::Parameters &parameters)
{
	GtkMessageDialog_ *messagedialog = new GtkMessageDialog_();

	GtkWindow *parent;
	if(parameters.size() > 0) {
		Php::Value object_parent = parameters[0];
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	}

	int int_flags = (int)parameters[1];
	GtkDialogFlags flags = (GtkDialogFlags)int_flags;

	int int_type = (int)parameters[2];
	GtkMessageType type = (GtkMessageType)int_type;

	int int_buttons = (int)parameters[3];
	GtkButtonsType buttons = (GtkButtonsType)int_buttons;

	std::string s_message_format = parameters[4];
	gchar *message_format = (gchar *)s_message_format.c_str();

	std::string s_text = "";
	if(parameters.size() > 1) {
		std::string a_text = parameters[1];
		s_text = a_text;
	}

	gpointer *l_instance = (gpointer *)gtk_message_dialog_new_with_markup (parent, flags, type, buttons, message_format, s_text.c_str());

	messagedialog->set_instance(l_instance);
	return Php::Object("GtkMessageDialog", messagedialog);

}

void GtkMessageDialog_::set_markup(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	gtk_message_dialog_set_markup (GTK_MESSAGE_DIALOG(instance), str);

}

void GtkMessageDialog_::format_secondary_text(Php::Parameters &parameters)
{
	std::string s_message_format = parameters[0];

	std::string s_text = "";
	if(parameters.size() > 1) {
		std::string a_text = parameters[1];
		s_text = a_text;
	}

	gtk_message_dialog_format_secondary_text (GTK_MESSAGE_DIALOG(instance), s_message_format.c_str(), s_text.c_str());

}

void GtkMessageDialog_::format_secondary_markup(Php::Parameters &parameters)
{
	std::string s_message_format = parameters[0];

	std::string s_text = "";
	if(parameters.size() > 1) {
		std::string a_text = parameters[1];
		s_text = a_text;
	}

	gtk_message_dialog_format_secondary_markup (GTK_MESSAGE_DIALOG(instance), s_message_format.c_str(), s_text.c_str());

}

Php::Value GtkMessageDialog_::get_message_area()
{
	GtkWidget *ret = gtk_message_dialog_get_message_area (GTK_MESSAGE_DIALOG(instance));

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkWidget", return_parsed);
}

