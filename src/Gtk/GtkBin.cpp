
#include "GtkBin.h"

GtkBin_::GtkBin_() = default;
GtkBin_::~GtkBin_() = default;

Php::Value GtkBin_::get_child()
{
	gpointer *ret = (gpointer *)gtk_bin_get_child(GTK_BIN(instance));

	return cobject_to_phpobject(ret);
}