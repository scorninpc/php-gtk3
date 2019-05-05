
#include "GtkLabel.h"

/**
 * Constructor
 */
GtkLabel_::GtkLabel_() = default;

/**
 * Destructor
 */
GtkLabel_::~GtkLabel_() = default;

void GtkLabel_::__construct(Php::Parameters &parameters)
{
	std::string s_str = parameters[0];
	gchar *str = (gchar *)s_str.c_str();

	instance = (gpointer *)gtk_label_new (str);

}

