
#include "GtkFileChooserDialog.h"

/**
 * Constructor
 */
GtkFileChooserDialog_::GtkFileChooserDialog_() = default;

/**
 * Destructor
 */
GtkFileChooserDialog_::~GtkFileChooserDialog_() = default;

void GtkFileChooserDialog_::__construct(Php::Parameters &parameters)
{
	std::string s_title = parameters[0];
	gchar *title = (gchar *)s_title.c_str();

	Php::Value object_parent = parameters[1];
	GtkWindow *parent = NULL;
	if (object_parent.instanceOf("GtkWindow")) {
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	}

	int int_action = (int)parameters[2];
	GtkFileChooserAction action = (GtkFileChooserAction)int_action;

	Php::Value arr = parameters[3];
    if(arr.size() < 2) {
         throw Php::Exception("parameters expect one button with response");
    }

    instance = (gpointer *)gtk_file_chooser_dialog_new (title, parent, action, arr[0], (int)arr[1], NULL);

	// Add buttons
    for(int index=2; index < (int)arr.size(); index+=2) {
        gtk_dialog_add_button(GTK_DIALOG(instance), arr[index], (int)arr[index+1]);
        
    }

}

void GtkFileChooserDialog_::set_action(Php::Parameters &parameters)
{
	int int_action = (int)parameters[0];
	GtkFileChooserAction action = (GtkFileChooserAction)int_action;

	gtk_file_chooser_set_action (GTK_FILE_CHOOSER(instance), action);

}

Php::Value GtkFileChooserDialog_::get_action()
{
	GtkFileChooserAction ret = gtk_file_chooser_get_action (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_local_only(Php::Parameters &parameters)
{
	gboolean local_only = (gboolean)parameters[0];

	gtk_file_chooser_set_local_only (GTK_FILE_CHOOSER(instance), local_only);

}

Php::Value GtkFileChooserDialog_::get_local_only()
{
	gboolean ret = gtk_file_chooser_get_local_only (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_select_multiple(Php::Parameters &parameters)
{
	gboolean select_multiple = (gboolean)parameters[0];

	gtk_file_chooser_set_select_multiple (GTK_FILE_CHOOSER(instance), select_multiple);

}

Php::Value GtkFileChooserDialog_::get_select_multiple()
{
	gboolean ret = gtk_file_chooser_get_select_multiple (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_show_hidden(Php::Parameters &parameters)
{
	gboolean show_hidden = (gboolean)parameters[0];

	gtk_file_chooser_set_show_hidden (GTK_FILE_CHOOSER(instance), show_hidden);
}

Php::Value GtkFileChooserDialog_::get_show_hidden()
{
	gboolean ret = gtk_file_chooser_get_show_hidden (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_do_overwrite_confirmation(Php::Parameters &parameters)
{
	gboolean select_multiple = (gboolean)parameters[0];

	gtk_file_chooser_set_do_overwrite_confirmation (GTK_FILE_CHOOSER(instance), select_multiple);

}

Php::Value GtkFileChooserDialog_::get_do_overwrite_confirmation()
{
	gboolean ret = gtk_file_chooser_get_do_overwrite_confirmation (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_create_folders(Php::Parameters &parameters)
{
	gboolean create_folders = (gboolean)parameters[0];

	gtk_file_chooser_set_create_folders (GTK_FILE_CHOOSER(instance), create_folders);

}

Php::Value GtkFileChooserDialog_::get_create_folders()
{
	gboolean ret = gtk_file_chooser_get_create_folders (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_current_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_file_chooser_set_current_name (GTK_FILE_CHOOSER(instance), name);

}

Php::Value GtkFileChooserDialog_::get_current_name()
{
	std::string ret = gtk_file_chooser_get_current_name (GTK_FILE_CHOOSER(instance));

	return ret;
}

Php::Value GtkFileChooserDialog_::set_filename(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gboolean ret = gtk_file_chooser_set_filename (GTK_FILE_CHOOSER(instance), name);

	return ret;
}

Php::Value GtkFileChooserDialog_::get_filename()
{
	std::string ret = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(instance));

	return ret;
}

Php::Value GtkFileChooserDialog_::select_filename(Php::Parameters &parameters)
{
	std::string s_filename = parameters[0];
	gchar *filename = (gchar *)s_filename.c_str();

	gboolean ret = gtk_file_chooser_select_filename (GTK_FILE_CHOOSER(instance), filename);

	return ret;
}

void GtkFileChooserDialog_::unselect_filename(Php::Parameters &parameters)
{
	std::string s_filename = parameters[0];
	gchar *filename = (gchar *)s_filename.c_str();

	gtk_file_chooser_unselect_filename (GTK_FILE_CHOOSER(instance), filename);

}

void GtkFileChooserDialog_::select_all()
{
	gtk_file_chooser_select_all (GTK_FILE_CHOOSER(instance));

}

void GtkFileChooserDialog_::unselect_all()
{
	gtk_file_chooser_unselect_all (GTK_FILE_CHOOSER(instance));

}

Php::Value GtkFileChooserDialog_::get_filenames()
{
	GSList *ret = gtk_file_chooser_get_filenames (GTK_FILE_CHOOSER(instance));

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		ret_arr[index] = (char *) item->data;
	}

	return ret_arr;
}

Php::Value GtkFileChooserDialog_::set_current_folder(Php::Parameters &parameters)
{
	std::string s_filename = parameters[0];
	gchar *filename = (gchar *)s_filename.c_str();

	gboolean ret = gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER(instance), filename);

	return ret;
}

Php::Value GtkFileChooserDialog_::get_current_folder()
{
	std::string ret = gtk_file_chooser_get_current_folder (GTK_FILE_CHOOSER(instance));

	return ret;
}

Php::Value GtkFileChooserDialog_::get_uri()
{
	std::string ret = gtk_file_chooser_get_preview_filename (GTK_FILE_CHOOSER(instance));

	return ret;
}

Php::Value GtkFileChooserDialog_::set_uri(Php::Parameters &parameters)
{
	std::string s_uri = parameters[0];
	gchar *uri = (gchar *)s_uri.c_str();

	gboolean ret = gtk_file_chooser_set_uri (GTK_FILE_CHOOSER(instance), uri);

	return ret;
}

Php::Value GtkFileChooserDialog_::select_uri(Php::Parameters &parameters)
{
	std::string s_uri = parameters[0];
	gchar *uri = (gchar *)s_uri.c_str();

	gboolean ret = gtk_file_chooser_select_uri (GTK_FILE_CHOOSER(instance), uri);

	return ret;
}

void GtkFileChooserDialog_::unselect_uri(Php::Parameters &parameters)
{
	std::string s_uri = parameters[0];
	gchar *uri = (gchar *)s_uri.c_str();

	gtk_file_chooser_unselect_uri (GTK_FILE_CHOOSER(instance), uri);

}

Php::Value GtkFileChooserDialog_::get_uris()
{
	GSList *ret = gtk_file_chooser_get_uris (GTK_FILE_CHOOSER(instance));

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		ret_arr[index] = (char *) item->data;
	}

	return ret_arr;
}

Php::Value GtkFileChooserDialog_::set_current_folder_uri(Php::Parameters &parameters)
{
	std::string s_uri = parameters[0];
	gchar *uri = (gchar *)s_uri.c_str();

	gboolean ret = gtk_file_chooser_set_current_folder_uri (GTK_FILE_CHOOSER(instance), uri);

	return ret;
}

Php::Value GtkFileChooserDialog_::get_current_folder_uri()
{
	std::string s_uri = gtk_file_chooser_get_current_folder_uri (GTK_FILE_CHOOSER(instance));

	return s_uri.c_str();
}


void GtkFileChooserDialog_::set_preview_widget(Php::Parameters &parameters)
{
	GtkWidget *preview_widget;
	if(parameters.size() > 0) {
		Php::Value object_preview_widget = parameters[0];
		GtkWidget_ *phpgtk_preview_widget = (GtkWidget_ *)object_preview_widget.implementation();
		preview_widget = GTK_WIDGET(phpgtk_preview_widget->get_instance());
	}

	gtk_file_chooser_set_preview_widget (GTK_FILE_CHOOSER(instance), preview_widget);

}

Php::Value GtkFileChooserDialog_::get_preview_widget()
{
	gpointer *ret = (gpointer *)gtk_file_chooser_get_preview_widget (GTK_FILE_CHOOSER(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
	return cobject_to_phpobject(ret);
}

void GtkFileChooserDialog_::set_preview_widget_active(Php::Parameters &parameters)
{
	gboolean active = (gboolean)parameters[0];

	gtk_file_chooser_set_preview_widget_active (GTK_FILE_CHOOSER(instance), active);

}

Php::Value GtkFileChooserDialog_::get_preview_widget_active()
{
	gboolean ret = gtk_file_chooser_get_preview_widget_active (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_use_preview_label(Php::Parameters &parameters)
{
	gboolean use_label = (gboolean)parameters[0];

	gtk_file_chooser_set_use_preview_label (GTK_FILE_CHOOSER(instance), use_label);

}

Php::Value GtkFileChooserDialog_::get_use_preview_label()
{
	gboolean ret = gtk_file_chooser_get_use_preview_label (GTK_FILE_CHOOSER(instance));

	return ret;
}

Php::Value GtkFileChooserDialog_::get_preview_uri()
{
	std::string ret = gtk_file_chooser_get_preview_uri (GTK_FILE_CHOOSER(instance));

	return ret;
}

void GtkFileChooserDialog_::set_extra_widget(Php::Parameters &parameters)
{
	GtkWidget *extra_widget;
	if(parameters.size() > 0) {
		Php::Value object_extra_widget = parameters[0];
		GtkWidget_ *phpgtk_extra_widget = (GtkWidget_ *)object_extra_widget.implementation();
		extra_widget = GTK_WIDGET(phpgtk_extra_widget->get_instance());
	}

	gtk_file_chooser_set_extra_widget (GTK_FILE_CHOOSER(instance), extra_widget);

}

Php::Value GtkFileChooserDialog_::get_extra_widget()
{
	gpointer *ret = (gpointer *) gtk_file_chooser_get_extra_widget (GTK_FILE_CHOOSER(instance));

	return cobject_to_phpobject(ret);
	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
}

void GtkFileChooserDialog_::add_filter(Php::Parameters &parameters)
{
	GtkFileFilter *filter;
	if(parameters.size() > 0) {
		Php::Value object_filter = parameters[0];
		GtkFileFilter_ *phpgtk_filter = (GtkFileFilter_ *)object_filter.implementation();
		filter = GTK_FILE_FILTER(phpgtk_filter->get_instance());
	}

	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER(instance), filter);

}

void GtkFileChooserDialog_::remove_filter(Php::Parameters &parameters)
{
	Php::Value object_filter = parameters[0];
	GtkFileFilter_ *phpgtk_filter = (GtkFileFilter_ *)object_filter.implementation();
	GtkFileFilter *filter = GTK_FILE_FILTER(phpgtk_filter->get_instance());

	gtk_file_chooser_remove_filter (GTK_FILE_CHOOSER(instance), filter);

}

Php::Value GtkFileChooserDialog_::list_filters()
{
	GSList *ret = gtk_file_chooser_list_filters (GTK_FILE_CHOOSER(instance));

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {
		GtkFileFilter_ *return_parsed = new GtkFileFilter_();

		return_parsed->set_instance((gpointer *)GTK_FILE_FILTER(item->data));


		ret_arr[index] = Php::Object("GtkFileFilter", return_parsed);
	}

	return ret_arr;
}

void GtkFileChooserDialog_::set_filter(Php::Parameters &parameters)
{
	GtkFileFilter *filter;
	if(parameters.size() > 0) {
		Php::Value object_filter = parameters[0];
		GtkFileFilter_ *phpgtk_filter = (GtkFileFilter_ *)object_filter.implementation();
		filter = GTK_FILE_FILTER(phpgtk_filter->get_instance());
	}

	gtk_file_chooser_set_filter (GTK_FILE_CHOOSER(instance), filter);

}

Php::Value GtkFileChooserDialog_::get_filter()
{
	GtkFileFilter *ret = gtk_file_chooser_get_filter (GTK_FILE_CHOOSER(instance));

	GtkFileFilter_ *return_parsed = new GtkFileFilter_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkFileFilter", return_parsed);
}

