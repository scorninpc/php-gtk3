
#include "GtkNotebook.h"

/**
 * Constructor
 */
GtkNotebook_::GtkNotebook_() = default;

/**
 * Destructor
 */
GtkNotebook_::~GtkNotebook_() = default;

void GtkNotebook_::__construct()
{
	instance = (gpointer *)gtk_notebook_new ();

}

Php::Value GtkNotebook_::append_page(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	GtkWidget *tab_label;
	if(parameters.size() > 1) {
		Php::Value object_tab_label = parameters[1];
		GtkWidget_ *phpgtk_tab_label = (GtkWidget_ *)object_tab_label.implementation();
		tab_label = GTK_WIDGET(phpgtk_tab_label->get_instance());
	}

	gint ret = gtk_notebook_append_page (GTK_NOTEBOOK(instance), child, tab_label);

	return ret;
}

Php::Value GtkNotebook_::prepend_page(Php::Parameters& parameters)
{
	GtkWidget* child;
	if (parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_* phpgtk_child = (GtkWidget_*)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	GtkWidget* tab_label;
	if (parameters.size() > 1) {
		Php::Value object_tab_label = parameters[1];
		GtkWidget_* phpgtk_tab_label = (GtkWidget_*)object_tab_label.implementation();
		tab_label = GTK_WIDGET(phpgtk_tab_label->get_instance());
	}

	gint ret = gtk_notebook_prepend_page(GTK_NOTEBOOK(instance), child, tab_label);

	return ret;
}

Php::Value GtkNotebook_::insert_page(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	GtkWidget *tab_label;
	if(parameters.size() > 1) {
		Php::Value object_tab_label = parameters[1];
		GtkWidget_ *phpgtk_tab_label = (GtkWidget_ *)object_tab_label.implementation();
		tab_label = GTK_WIDGET(phpgtk_tab_label->get_instance());
	}

	gint position = (gint)parameters[2];

	gint ret = gtk_notebook_insert_page (GTK_NOTEBOOK(instance), child, tab_label, position);

	return ret;
}

void GtkNotebook_::remove_page(Php::Parameters &parameters)
{
	gint position = (gint)parameters[0];

	gtk_notebook_remove_page (GTK_NOTEBOOK(instance), position);

}

void GtkNotebook_::detach_tab(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gtk_notebook_detach_tab (GTK_NOTEBOOK(instance), child);

}

Php::Value GtkNotebook_::page_num(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint ret = gtk_notebook_page_num (GTK_NOTEBOOK(instance), child);

	return ret;
}

void GtkNotebook_::next_page()
{
	gtk_notebook_next_page (GTK_NOTEBOOK(instance));

}

void GtkNotebook_::prev_page()
{
	gtk_notebook_prev_page (GTK_NOTEBOOK(instance));

}

void GtkNotebook_::reorder_child(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gint position = (gint)parameters[1];

	gtk_notebook_reorder_child (GTK_NOTEBOOK(instance), child, position);

}

void GtkNotebook_::set_tab_pos(Php::Parameters &parameters)
{
	int int_pos = (int)parameters[0];
	GtkPositionType pos = (GtkPositionType)int_pos;

	gtk_notebook_set_tab_pos (GTK_NOTEBOOK(instance), pos);

}

void GtkNotebook_::set_show_tabs(Php::Parameters &parameters)
{
	gboolean show_tabs = (gboolean)parameters[0];

	gtk_notebook_set_show_tabs (GTK_NOTEBOOK(instance), show_tabs);

}

void GtkNotebook_::set_show_border(Php::Parameters &parameters)
{
	gboolean show_border = (gboolean)parameters[0];

	gtk_notebook_set_show_border (GTK_NOTEBOOK(instance), show_border);

}

void GtkNotebook_::set_scrollable(Php::Parameters &parameters)
{
	gboolean scrollable = (gboolean)parameters[0];

	gtk_notebook_set_scrollable (GTK_NOTEBOOK(instance), scrollable);

}

void GtkNotebook_::popup_enable()
{
	gtk_notebook_popup_enable (GTK_NOTEBOOK(instance));

}

void GtkNotebook_::popup_disable()
{
	gtk_notebook_popup_disable (GTK_NOTEBOOK(instance));

}

Php::Value GtkNotebook_::get_current_page()
{
	gint ret = gtk_notebook_get_current_page (GTK_NOTEBOOK(instance));

	return ret;
}

Php::Value GtkNotebook_::get_menu_label(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gpointer *ret = (gpointer *)gtk_notebook_get_menu_label (GTK_NOTEBOOK(instance), child);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	return cobject_to_phpobject(ret);
}

Php::Value GtkNotebook_::get_nth_page(Php::Parameters &parameters)
{
	gint page_num = (gint)parameters[0];

	gpointer *ret = (gpointer *)gtk_notebook_get_nth_page (GTK_NOTEBOOK(instance), page_num);

	return cobject_to_phpobject(ret);
	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

Php::Value GtkNotebook_::get_n_pages()
{
	gint ret = gtk_notebook_get_n_pages (GTK_NOTEBOOK(instance));

	return ret;
}

Php::Value GtkNotebook_::get_tab_label(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gpointer *ret = (gpointer *)gtk_notebook_get_tab_label (GTK_NOTEBOOK(instance), child);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
	return cobject_to_phpobject(ret);
}

void GtkNotebook_::set_menu_label(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	GtkWidget *menu_label;
	if(parameters.size() > 1) {
		Php::Value object_menu_label = parameters[1];
		GtkWidget_ *phpgtk_menu_label = (GtkWidget_ *)object_menu_label.implementation();
		menu_label = GTK_WIDGET(phpgtk_menu_label->get_instance());
	}

	gtk_notebook_set_menu_label (GTK_NOTEBOOK(instance), child, menu_label);

}

void GtkNotebook_::set_menu_label_text(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	std::string s_menu_text = parameters[1];
	gchar *menu_text = (gchar *)s_menu_text.c_str();

	gtk_notebook_set_menu_label_text (GTK_NOTEBOOK(instance), child, menu_text);

}

void GtkNotebook_::set_tab_label(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	GtkWidget *tab_label;
	if(parameters.size() > 1) {
		Php::Value object_tab_label = parameters[1];
		GtkWidget_ *phpgtk_tab_label = (GtkWidget_ *)object_tab_label.implementation();
		tab_label = GTK_WIDGET(phpgtk_tab_label->get_instance());
	}

	gtk_notebook_set_tab_label (GTK_NOTEBOOK(instance), child, tab_label);

}

void GtkNotebook_::set_tab_label_text(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	std::string s_tab_text = parameters[1];
	gchar *tab_text = (gchar *)s_tab_text.c_str();

	gtk_notebook_set_tab_label_text (GTK_NOTEBOOK(instance), child, tab_text);

}

void GtkNotebook_::set_tab_reorderable(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean reorderable = (gboolean)parameters[1];

	gtk_notebook_set_tab_reorderable (GTK_NOTEBOOK(instance), child, reorderable);

}

void GtkNotebook_::set_tab_detachable(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean detachable = (gboolean)parameters[1];

	gtk_notebook_set_tab_detachable (GTK_NOTEBOOK(instance), child, detachable);

}

Php::Value GtkNotebook_::get_menu_label_text(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	std::string ret = gtk_notebook_get_menu_label_text (GTK_NOTEBOOK(instance), child);

	return ret;
}

Php::Value GtkNotebook_::get_scrollable()
{
	gboolean ret = gtk_notebook_get_scrollable (GTK_NOTEBOOK(instance));

	return ret;
}

Php::Value GtkNotebook_::get_show_border()
{
	gboolean ret = gtk_notebook_get_show_border (GTK_NOTEBOOK(instance));

	return ret;
}

Php::Value GtkNotebook_::get_show_tabs()
{
	gboolean ret = gtk_notebook_get_show_tabs (GTK_NOTEBOOK(instance));

	return ret;
}

Php::Value GtkNotebook_::get_tab_label_text(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	std::string ret = gtk_notebook_get_tab_label_text (GTK_NOTEBOOK(instance), child);

	return ret;
}

Php::Value GtkNotebook_::get_tab_pos()
{
	GtkPositionType ret = gtk_notebook_get_tab_pos (GTK_NOTEBOOK(instance));

	return ret;
}

Php::Value GtkNotebook_::get_tab_reorderable(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean ret = gtk_notebook_get_tab_reorderable (GTK_NOTEBOOK(instance), child);

	return ret;
}

Php::Value GtkNotebook_::get_tab_detachable(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	gboolean ret = gtk_notebook_get_tab_detachable (GTK_NOTEBOOK(instance), child);

	return ret;
}

void GtkNotebook_::set_current_page(Php::Parameters &parameters)
{
	gint page_num = (gint)parameters[0];

	gtk_notebook_set_current_page (GTK_NOTEBOOK(instance), page_num);

}

void GtkNotebook_::set_group_name(Php::Parameters &parameters)
{
	std::string s_group_name = parameters[0];
	gchar *group_name = (gchar *)s_group_name.c_str();

	gtk_notebook_set_group_name (GTK_NOTEBOOK(instance), group_name);

}

Php::Value GtkNotebook_::get_group_name()
{
	std::string ret = gtk_notebook_get_group_name (GTK_NOTEBOOK(instance));

	return ret;
}

void GtkNotebook_::set_action_widget(Php::Parameters &parameters)
{
	GtkWidget *child;
	if(parameters.size() > 0) {
		Php::Value object_child = parameters[0];
		GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
		child = GTK_WIDGET(phpgtk_child->get_instance());
	}

	int int_pack_type = (int)parameters[1];
	GtkPackType pack_type = (GtkPackType)int_pack_type;

	gtk_notebook_set_action_widget (GTK_NOTEBOOK(instance), child, pack_type);

}

Php::Value GtkNotebook_::get_action_widget(Php::Parameters &parameters)
{
	int int_pack_type = (int)parameters[0];
	GtkPackType pack_type = (GtkPackType)int_pack_type;

	gpointer *ret = (gpointer *)gtk_notebook_get_action_widget (GTK_NOTEBOOK(instance), pack_type);

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	return cobject_to_phpobject(ret);
}

