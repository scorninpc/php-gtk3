
#include "GtkFileChooser.h"

/**
 * Constructor
 */
GtkFileChooser_::GtkFileChooser_() = default;

/**
 * Destructor
 */
GtkFileChooser_::~GtkFileChooser_() = default;

Php::Value GtkFileChooser_::get_filename()
{
	std::string ret = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(instance));

	return ret;
}

