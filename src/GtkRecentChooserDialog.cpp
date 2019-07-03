
#include "GtkRecentChooserDialog.h"

/**
 * Constructor
 */
GtkRecentChooserDialog_::GtkRecentChooserDialog_() = default;

/**
 * Destructor
 */
GtkRecentChooserDialog_::~GtkRecentChooserDialog_() = default;

void GtkRecentChooserDialog_::__construct(Php::Parameters &parameters)
{
	std::string s_title = parameters[0];
	gchar *title = (gchar *)s_title.c_str();

	Php::Value object_parent = parameters[1];
	GtkWindow *parent = NULL;
	if (object_parent.instanceOf("GtkWindow")) {
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	}

	// std::string s_first_button_text = parameters[2];
	// gchar *first_button_text = (gchar *)s_first_button_text.c_str();


	Php::Value arr = parameters[2];
    if(arr.size() < 2) {
         throw Php::Exception("parameters expect one button with response");
    }

	instance = (gpointer *)gtk_recent_chooser_dialog_new (title, parent, arr[0], (int)arr[1], NULL);

	// Add buttons
    for(int index=2; index < (int)arr.size(); index+=2) {
        gtk_dialog_add_button(GTK_DIALOG(instance), arr[index], (int)arr[index+1]);
        
    }

}

Php::Value GtkRecentChooserDialog_::new_for_manager(Php::Parameters &parameters)
{
	// GtkWindow *parent;
	// if(parameters.size() > 0) {
	// 	Php::Value object_parent = parameters[0];
	// 	GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
	// 	parent = GTK_WIDGET(phpgtk_parent->get_instance());
	// }

	// GtkRecentManager *manager;
	// if(parameters.size() > 1) {
	// 	Php::Value object_manager = parameters[1];
	// 	GtkRecentManager_ *phpgtk_manager = (GtkRecentManager_ *)object_manager.implementation();
	// 	manager = GTK_WIDGET(phpgtk_manager->get_instance());
	// }

	// std::string s_first_button_text = parameters[2];
	// gchar *first_button_text = (gchar *)s_first_button_text.c_str();


	// GtkWidget *ret = gtk_recent_chooser_dialog_new_for_manager (GTK_RECENT_CHOOSER(instance), parent, manager, first_button_text, );

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);

	throw Php::Exception("GtkRecentChooserDialog_::new_for_manager not implemented");
}

void GtkRecentChooserDialog_::set_show_private(Php::Parameters &parameters)
{
	gboolean show_private = (gboolean)parameters[0];

	gtk_recent_chooser_set_show_private (GTK_RECENT_CHOOSER(instance), show_private);

}

Php::Value GtkRecentChooserDialog_::get_show_private()
{
	gboolean ret = gtk_recent_chooser_get_show_private (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_show_not_found(Php::Parameters &parameters)
{
	gboolean show_not_found = (gboolean)parameters[0];

	gtk_recent_chooser_set_show_not_found (GTK_RECENT_CHOOSER(instance), show_not_found);

}

Php::Value GtkRecentChooserDialog_::get_show_not_found()
{
	gboolean ret = gtk_recent_chooser_get_show_not_found (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_show_icons(Php::Parameters &parameters)
{
	gboolean show_icons = (gboolean)parameters[0];

	gtk_recent_chooser_set_show_icons (GTK_RECENT_CHOOSER(instance), show_icons);

}

Php::Value GtkRecentChooserDialog_::get_show_icons()
{
	gboolean ret = gtk_recent_chooser_get_show_icons (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_select_multiple(Php::Parameters &parameters)
{
	gboolean select_multiple = (gboolean)parameters[0];

	gtk_recent_chooser_set_select_multiple (GTK_RECENT_CHOOSER(instance), select_multiple);

}

Php::Value GtkRecentChooserDialog_::get_select_multiple()
{
	gboolean ret = gtk_recent_chooser_get_select_multiple (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_local_only(Php::Parameters &parameters)
{
	gboolean local_only = (gboolean)parameters[0];

	gtk_recent_chooser_set_local_only (GTK_RECENT_CHOOSER(instance), local_only);

}

Php::Value GtkRecentChooserDialog_::get_local_only()
{
	gboolean ret = gtk_recent_chooser_get_local_only (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_limit(Php::Parameters &parameters)
{
	gint limit = (gint)parameters[0];

	gtk_recent_chooser_set_limit (GTK_RECENT_CHOOSER(instance), limit);

}

Php::Value GtkRecentChooserDialog_::get_limit()
{
	gint ret = gtk_recent_chooser_get_limit (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_show_tips(Php::Parameters &parameters)
{
	gboolean show_tips = (gboolean)parameters[0];

	gtk_recent_chooser_set_show_tips (GTK_RECENT_CHOOSER(instance), show_tips);

}

Php::Value GtkRecentChooserDialog_::get_show_tips()
{
	gboolean ret = gtk_recent_chooser_get_show_tips (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_sort_type(Php::Parameters &parameters)
{
	int int_sort_type = (int)parameters[0];
	GtkRecentSortType sort_type = (GtkRecentSortType)int_sort_type;

	gtk_recent_chooser_set_sort_type (GTK_RECENT_CHOOSER(instance), sort_type);

}

Php::Value GtkRecentChooserDialog_::get_sort_type()
{
	GtkRecentSortType ret = gtk_recent_chooser_get_sort_type (GTK_RECENT_CHOOSER(instance));

	return ret;
}

void GtkRecentChooserDialog_::set_sort_func(Php::Parameters &parameters)
{
	// GtkRecentSortFunc *sort_func;
	// if(parameters.size() > 0) {
	// 	Php::Value object_sort_func = parameters[0];
	// 	GtkRecentSortFunc_ *phpgtk_sort_func = (GtkRecentSortFunc_ *)object_sort_func.implementation();
	// 	sort_func = GTK_WIDGET(phpgtk_sort_func->get_instance());
	// }

	// gpointer sort_data = (gpointer)parameters[1];


	// gtk_recent_chooser_set_sort_func (GTK_RECENT_CHOOSER(instance), sort_func, sort_data, data_destroy);

	throw Php::Exception("GtkRecentChooserDialog_::set_sort_func not implemented");

}

Php::Value GtkRecentChooserDialog_::set_current_uri(Php::Parameters &parameters)
{
	std::string s_uri = parameters[0];
	gchar *uri = (gchar *)s_uri.c_str();

	GError *error = NULL;

	gboolean ret = gtk_recent_chooser_set_current_uri (GTK_RECENT_CHOOSER(instance), uri, &error);

	return ret;
}

Php::Value GtkRecentChooserDialog_::get_current_uri()
{
	gchar *ret = gtk_recent_chooser_get_current_uri (GTK_RECENT_CHOOSER(instance));

	std::string ret_str = ret;

	return ret_str;
}

Php::Value GtkRecentChooserDialog_::get_current_item()
{
	// GtkRecentInfo *ret = gtk_recent_chooser_get_current_item (GTK_RECENT_CHOOSER(instance));

	// GtkRecentInfo_ *return_parsed = new GtkRecentInfo_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkRecentInfo", return_parsed);

	throw Php::Exception("GtkRecentChooserDialog_::get_current_item not implemented");
	return 1;
}

Php::Value GtkRecentChooserDialog_::select_uri(Php::Parameters &parameters)
{
	std::string s_uri = parameters[0];
	gchar *uri = (gchar *)s_uri.c_str();

	GError *error = NULL;

	gboolean ret = gtk_recent_chooser_select_uri (GTK_RECENT_CHOOSER(instance), uri, &error);

	return ret;
}

void GtkRecentChooserDialog_::unselect_uri(Php::Parameters &parameters)
{
	std::string s_uri = parameters[0];
	gchar *uri = (gchar *)s_uri.c_str();

	gtk_recent_chooser_unselect_uri (GTK_RECENT_CHOOSER(instance), uri);

}

void GtkRecentChooserDialog_::select_all()
{
	gtk_recent_chooser_select_all (GTK_RECENT_CHOOSER(instance));

}

void GtkRecentChooserDialog_::unselect_all()
{
	gtk_recent_chooser_unselect_all (GTK_RECENT_CHOOSER(instance));

}

Php::Value GtkRecentChooserDialog_::get_items()
{
	GList *ret = gtk_recent_chooser_get_items (GTK_RECENT_CHOOSER(instance));

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		ret_arr[index] = (char *) item->data;
	}

	return ret_arr;
}

Php::Value GtkRecentChooserDialog_::get_uris(Php::Parameters &parameters)
{
	gsize length;

	gchar **ret = gtk_recent_chooser_get_uris (GTK_RECENT_CHOOSER(instance), &length);

	Php::Value ret_arr;
	for(int index=0; index<(int)g_strv_length(ret); index++) {
		ret_arr[index] = (char *) ret[index];
	}

	return ret_arr;
}

void GtkRecentChooserDialog_::add_filter(Php::Parameters &parameters)
{
	// GtkRecentFilter *filter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_filter = parameters[0];
	// 	GtkRecentFilter_ *phpgtk_filter = (GtkRecentFilter_ *)object_filter.implementation();
	// 	filter = GTK_WIDGET(phpgtk_filter->get_instance());
	// }

	// gtk_recent_chooser_add_filter (GTK_RECENT_CHOOSER(instance), filter);

	throw Php::Exception("GtkRecentChooserDialog_::add_filter not implemented");

}

void GtkRecentChooserDialog_::remove_filter(Php::Parameters &parameters)
{
	// GtkRecentFilter *filter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_filter = parameters[0];
	// 	GtkRecentFilter_ *phpgtk_filter = (GtkRecentFilter_ *)object_filter.implementation();
	// 	filter = GTK_WIDGET(phpgtk_filter->get_instance());
	// }

	// gtk_recent_chooser_remove_filter (GTK_RECENT_CHOOSER(instance), filter);

	throw Php::Exception("GtkRecentChooserDialog_::remove_filter not implemented");

}

Php::Value GtkRecentChooserDialog_::list_filters()
{
	GSList *ret = gtk_recent_chooser_list_filters (GTK_RECENT_CHOOSER(instance));

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		ret_arr[index] = (char *) item->data;
	}

	return ret_arr;
}

void GtkRecentChooserDialog_::set_filter(Php::Parameters &parameters)
{
	// GtkRecentFilter *filter;
	// if(parameters.size() > 0) {
	// 	Php::Value object_filter = parameters[0];
	// 	GtkRecentFilter_ *phpgtk_filter = (GtkRecentFilter_ *)object_filter.implementation();
	// 	filter = GTK_WIDGET(phpgtk_filter->get_instance());
	// }

	// gtk_recent_chooser_set_filter (GTK_RECENT_CHOOSER(instance), filter);

	throw Php::Exception("GtkRecentChooserDialog_::set_filter not implemented");
}

Php::Value GtkRecentChooserDialog_::get_filter()
{
	// GtkRecentFilter *ret = gtk_recent_chooser_get_filter (GTK_RECENT_CHOOSER(instance));

	// GtkRecentFilter_ *return_parsed = new GtkRecentFilter_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkRecentFilter", return_parsed);

	throw Php::Exception("GtkRecentChooserDialog_::get_filter not implemented");
	return 1;
}

