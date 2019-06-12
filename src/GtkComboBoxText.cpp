
#include "GtkComboBoxText.h"

/**
 * Constructor
 */
GtkComboBoxText_::GtkComboBoxText_() = default;

/**
 * Destructor
 */
GtkComboBoxText_::~GtkComboBoxText_() = default;

void GtkComboBoxText_::__construct()
{
	instance = (gpointer *)gtk_combo_box_text_new ();

}

Php::Value GtkComboBoxText_::new_with_entry()
{
	GtkWidget *ret = gtk_combo_box_text_new_with_entry ();

	GtkComboBoxText_ *return_parsed = new GtkComboBoxText_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkComboBoxText", return_parsed);
}

void GtkComboBoxText_::append(Php::Parameters &parameters)
{
	std::string s_id = parameters[0];
	gchar *id = (gchar *)s_id.c_str();

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gtk_combo_box_text_append (GTK_COMBO_BOX_TEXT(instance), id, text);

}

void GtkComboBoxText_::prepend(Php::Parameters &parameters)
{
	std::string s_id = parameters[0];
	gchar *id = (gchar *)s_id.c_str();

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gtk_combo_box_text_prepend (GTK_COMBO_BOX_TEXT(instance), id, text);

}

void GtkComboBoxText_::insert(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	std::string s_id = parameters[1];
	gchar *id = (gchar *)s_id.c_str();

	std::string s_text = parameters[2];
	gchar *text = (gchar *)s_text.c_str();

	gtk_combo_box_text_insert (GTK_COMBO_BOX_TEXT(instance), position, id, text);

}

void GtkComboBoxText_::append_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(instance), text);

}

void GtkComboBoxText_::prepend_text(Php::Parameters &parameters)
{
	std::string s_text = parameters[0];
	gchar *text = (gchar *)s_text.c_str();

	gtk_combo_box_text_prepend_text (GTK_COMBO_BOX_TEXT(instance), text);

}

void GtkComboBoxText_::insert_text(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gtk_combo_box_text_insert_text (GTK_COMBO_BOX_TEXT(instance), position, text);

}

void GtkComboBoxText_::remove(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	gtk_combo_box_text_remove (GTK_COMBO_BOX_TEXT(instance), position);

}

void GtkComboBoxText_::remove_all()
{
	gtk_combo_box_text_remove_all (GTK_COMBO_BOX_TEXT(instance));

}

Php::Value GtkComboBoxText_::get_active_text()
{
	std::string ret = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(instance));

	return ret;
}

