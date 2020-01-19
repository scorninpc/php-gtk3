
#include "GtkRadioButton.h"
#include "../../main.h"

/**
 * Constructor
 */
GtkRadioButton_::GtkRadioButton_() = default;

/**
 * Destructor
 */
GtkRadioButton_::~GtkRadioButton_() = default;

void GtkRadioButton_::__construct(Php::Parameters &parameters)
{
	instance = (gpointer *)gtk_radio_button_new (NULL);
}

Php::Value GtkRadioButton_::new_from_widget(Php::Parameters &parameters)
{
	// ----
	phpgtk_check_parameter(parameters, 1, Php::Type::Object, TRUE, "GtkWidget");
	
	GtkRadioButton *radio_group_member;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		radio_group_member = GTK_RADIO_BUTTON(phpgtk_child->get_instance());
	}

	GtkWidget *ret = gtk_radio_button_new_from_widget (radio_group_member);


	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkRadioButton", return_parsed);
}

Php::Value GtkRadioButton_::new_with_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_radio_button_new_with_label (NULL, label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkRadioButton", return_parsed);
}

Php::Value GtkRadioButton_::new_with_label_from_widget(Php::Parameters &parameters)
{
	// ----
	phpgtk_check_parameter(parameters, 1, Php::Type::Object, TRUE, "GtkWidget");
	
	GtkRadioButton *radio_group_member;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		radio_group_member = GTK_RADIO_BUTTON(phpgtk_child->get_instance());
	}

	// --
	std::string s_label = parameters[1];
	gchar *label = (gchar *)s_label.c_str();

	// --
	GtkWidget *ret = gtk_radio_button_new_with_label_from_widget (radio_group_member, label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkRadioButton", return_parsed);
}

Php::Value GtkRadioButton_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_radio_button_new_with_mnemonic (NULL, label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkRadioButton", return_parsed);
}

Php::Value GtkRadioButton_::new_with_mnemonic_from_widget(Php::Parameters &parameters)
{
	// ----
	phpgtk_check_parameter(parameters, 1, Php::Type::Object, TRUE, "GtkWidget");
	
	GtkRadioButton *radio_group_member;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		radio_group_member = GTK_RADIO_BUTTON(phpgtk_child->get_instance());
	}

	// -- 
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	// -- 
	GtkWidget *ret = gtk_radio_button_new_with_mnemonic_from_widget (radio_group_member, label);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkRadioButton", return_parsed);
}

void GtkRadioButton_::set_group(Php::Parameters &parameters)
{

	gtk_radio_button_set_group (GTK_RADIO_BUTTON(instance), NULL );

}

Php::Value GtkRadioButton_::get_group()
{
	GSList *ret = gtk_radio_button_get_group (GTK_RADIO_BUTTON(instance));

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		 
		GtkRadioButton_ *return_parsed = new GtkRadioButton_();
		return_parsed->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("GtkRadioButton", return_parsed);
	}

	return ret_arr;
}

void GtkRadioButton_::join_group(Php::Parameters &parameters)
{
	GtkRadioButton *group_source;
	if(parameters.size() > 0) {
		Php::Value object_group_source = parameters[0];
		GtkRadioButton_ *phpgtk_group_source = (GtkRadioButton_ *)object_group_source.implementation();
		group_source = GTK_RADIO_BUTTON(phpgtk_group_source->get_instance());
	}

	gtk_radio_button_join_group (GTK_RADIO_BUTTON(instance), group_source);

}

