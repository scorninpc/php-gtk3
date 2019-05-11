
#include "GtkTextTagTable.h"

/**
 * Constructor
 */
GtkTextTagTable_::GtkTextTagTable_() = default;

/**
 * Destructor
 */
GtkTextTagTable_::~GtkTextTagTable_() = default;

void GtkTextTagTable_::__construct()
{
	instance = (gpointer *)gtk_text_tag_table_new ();

}

Php::Value GtkTextTagTable_::add(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = (phpgtk_tag->get_tag());
	}

	gboolean ret = gtk_text_tag_table_add (GTK_TEXT_TAG_TABLE(instance), tag);

	return ret;
}

void GtkTextTagTable_::remove(Php::Parameters &parameters)
{
	GtkTextTag *tag;
	if(parameters.size() > 0) {
		Php::Value object_tag = parameters[0];
		GtkTextTag_ *phpgtk_tag = (GtkTextTag_ *)object_tag.implementation();
		tag = (phpgtk_tag->get_tag());
	}

	gtk_text_tag_table_remove (GTK_TEXT_TAG_TABLE(instance), tag);

}

Php::Value GtkTextTagTable_::lookup(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	GtkTextTag *ret = gtk_text_tag_table_lookup (GTK_TEXT_TAG_TABLE(instance), name);

	GtkTextTag_ *return_parsed = new GtkTextTag_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkTextTag", return_parsed);
}

Php::Value GtkTextTagTable_::foreach(Php::Parameters &parameters)
{
	// GtkTextTagTableForeach *func;
	// if(parameters.size() > 0) {
	// 	Php::Value object_func = parameters[0];
	// 	GtkTextTagTableForeach_ *phpgtk_func = (GtkTextTagTableForeach_ *)object_func.implementation();
	// 	func = (phpgtk_func->get_instance());
	// }

	// gpointer data = (gpointer)parameters[1];

	// void ret = gtk_text_tag_table_foreach (GTK_TEXT_TAG_TABLE(instance), func, data);

	// return ret;

	
	throw Php::Exception("GtkTextTagTable_::foreach not implemented");
	return 1;
}

Php::Value GtkTextTagTable_::get_size()
{
	gint ret = gtk_text_tag_table_get_size (GTK_TEXT_TAG_TABLE(instance));

	return ret;
}

