
#include "GtkEntryCompletion.h"

/**
 * Constructor
 */
GtkEntryCompletion_::GtkEntryCompletion_() = default;

/**
 * Destructor
 */
GtkEntryCompletion_::~GtkEntryCompletion_() = default;

void GtkEntryCompletion_::__construct()
{
	instance = (gpointer *)gtk_entry_completion_new ();

}

Php::Value GtkEntryCompletion_::new_with_area()
{
// 	GtkEntryCompletion *ret = gtk_entry_completion_new_with_area ();

// 	GtkEntryCompletion_ *return_parsed = new GtkEntryCompletion_();
// 	return_parsed->set_instance((gpointer *)ret);
// 	return Php::Object("GtkEntryCompletion", return_parsed);
	 throw Php::Exception("GtkEntryCompletion_::new_with_area not implemented");
}

Php::Value GtkEntryCompletion_::get_entry()
{
	GtkWidget *ret = gtk_entry_completion_get_entry (GTK_ENTRY_COMPLETION(instance));

	GtkEntry_ *return_parsed = new GtkEntry_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkEntry", return_parsed);
}

void GtkEntryCompletion_::set_model(Php::Parameters &parameters)
{
	GtkTreeModel *model;
	if(parameters.size() > 0) {
		Php::Value object_model = parameters[0];
		GtkTreeModel_ *phpgtk_model = (GtkTreeModel_ *)object_model.implementation();
		model = phpgtk_model->get_model();
	}

	gtk_entry_completion_set_model (GTK_ENTRY_COMPLETION(instance), model);

}

Php::Value GtkEntryCompletion_::get_model()
{
	GtkTreeModel *ret = gtk_entry_completion_get_model (GTK_ENTRY_COMPLETION(instance));

	GtkTreeModel_ *return_parsed = new GtkTreeModel_();
	return_parsed->set_model(ret);
	return Php::Object("GtkTreeModel", return_parsed);
}

void GtkEntryCompletion_::set_match_func(Php::Parameters &parameters)
{
// // 	GtkEntryCompletionMatchFunc *func;
// 	if(parameters.size() > 0) {
// 		Php::Value object_func = parameters[0];
// 		GtkEntryCompletionMatchFunc_ *phpgtk_func = (GtkEntryCompletionMatchFunc_ *)object_func.implementation();
// 		func = GTK_WIDGET(phpgtk_func->get_instance());
// 	}

// // 	gpointer func_data = (gpointer)parameters[1];

// 
// 	gtk_entry_completion_set_match_func (GTK_ENTRY_COMPLETION(instance), func, func_data, func_notify);

	 throw Php::Exception("GtkEntryCompletion_::set_match_func not implemented");
}

void GtkEntryCompletion_::set_minimum_key_length(Php::Parameters &parameters)
{
	gint length = (gint)parameters[0];

	gtk_entry_completion_set_minimum_key_length (GTK_ENTRY_COMPLETION(instance), length);

}

Php::Value GtkEntryCompletion_::get_minimum_key_length()
{
	gint ret = gtk_entry_completion_get_minimum_key_length (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

Php::Value GtkEntryCompletion_::compute_prefix(Php::Parameters &parameters)
{
	std::string s_key = parameters[0];
	gchar *key = (gchar *)s_key.c_str();

	std::string ret = gtk_entry_completion_compute_prefix (GTK_ENTRY_COMPLETION(instance), key);

	return ret;
}

void GtkEntryCompletion_::complete()
{
	gtk_entry_completion_complete (GTK_ENTRY_COMPLETION(instance));

}

Php::Value GtkEntryCompletion_::get_completion_prefix()
{
	std::string ret = gtk_entry_completion_get_completion_prefix (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

void GtkEntryCompletion_::insert_prefix()
{
	gtk_entry_completion_insert_prefix (GTK_ENTRY_COMPLETION(instance));

}

void GtkEntryCompletion_::insert_action_text(Php::Parameters &parameters)
{
	gint index_ = (gint)parameters[0];

	std::string s_text = parameters[1];
	gchar *text = (gchar *)s_text.c_str();

	gtk_entry_completion_insert_action_text (GTK_ENTRY_COMPLETION(instance), index_, text);

}

void GtkEntryCompletion_::insert_action_markup(Php::Parameters &parameters)
{
	gint index_ = (gint)parameters[0];

	std::string s_markup = parameters[1];
	gchar *markup = (gchar *)s_markup.c_str();

	gtk_entry_completion_insert_action_markup (GTK_ENTRY_COMPLETION(instance), index_, markup);

}

void GtkEntryCompletion_::delete_action(Php::Parameters &parameters)
{
	gint index_ = (gint)parameters[0];

	gtk_entry_completion_delete_action (GTK_ENTRY_COMPLETION(instance), index_);

}

void GtkEntryCompletion_::set_text_column(Php::Parameters &parameters)
{
	gint column = (gint)parameters[0];

	gtk_entry_completion_set_text_column (GTK_ENTRY_COMPLETION(instance), column);

}

Php::Value GtkEntryCompletion_::get_text_column()
{
	gint ret = gtk_entry_completion_get_text_column (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

void GtkEntryCompletion_::set_inline_completion(Php::Parameters &parameters)
{
	gboolean inline_completion = (gboolean)parameters[0];

	gtk_entry_completion_set_inline_completion (GTK_ENTRY_COMPLETION(instance), inline_completion);

}

Php::Value GtkEntryCompletion_::get_inline_completion()
{
	gboolean ret = gtk_entry_completion_get_inline_completion (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

void GtkEntryCompletion_::set_inline_selection(Php::Parameters &parameters)
{
	gboolean inline_selection = (gboolean)parameters[0];

	gtk_entry_completion_set_inline_selection (GTK_ENTRY_COMPLETION(instance), inline_selection);

}

Php::Value GtkEntryCompletion_::get_inline_selection()
{
	gboolean ret = gtk_entry_completion_get_inline_selection (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

void GtkEntryCompletion_::set_popup_completion(Php::Parameters &parameters)
{
	gboolean popup_completion = (gboolean)parameters[0];

	gtk_entry_completion_set_popup_completion (GTK_ENTRY_COMPLETION(instance), popup_completion);

}

Php::Value GtkEntryCompletion_::get_popup_completion()
{
	gboolean ret = gtk_entry_completion_get_popup_completion (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

void GtkEntryCompletion_::set_popup_set_width(Php::Parameters &parameters)
{
	gboolean popup_set_width = (gboolean)parameters[0];

	gtk_entry_completion_set_popup_set_width (GTK_ENTRY_COMPLETION(instance), popup_set_width);

}

Php::Value GtkEntryCompletion_::get_popup_set_width()
{
	gboolean ret = gtk_entry_completion_get_popup_set_width (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

void GtkEntryCompletion_::set_popup_single_match(Php::Parameters &parameters)
{
	gboolean popup_single_match = (gboolean)parameters[0];

	gtk_entry_completion_set_popup_single_match (GTK_ENTRY_COMPLETION(instance), popup_single_match);

}

Php::Value GtkEntryCompletion_::get_popup_single_match()
{
	gboolean ret = gtk_entry_completion_get_popup_single_match (GTK_ENTRY_COMPLETION(instance));

	return ret;
}

