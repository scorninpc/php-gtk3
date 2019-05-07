
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

	GtkWindow *parent;
	if(parameters.size() > 1) {
		Php::Value object_parent = parameters[1];
		GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
		parent = GTK_WINDOW(phpgtk_parent->get_instance());
	}

	int int_action = (int)parameters[2];
	GtkFileChooserAction action = (GtkFileChooserAction)int_action;


	instance = (gpointer *)gtk_file_chooser_dialog_new (title, parent, action, "OK", GTK_RESPONSE_OK, "Cancel", GTK_RESPONSE_CANCEL, NULL);
}

