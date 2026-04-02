
#include "GtkBin.h"

GtkBin_::GtkBin_() = default;
GtkBin_::~GtkBin_() = default;

Php::Value GtkBin_::get_child() {
  if (!instance || !GTK_IS_BIN(instance)) {
    return nullptr;
  }

  gpointer *ret = (gpointer *)gtk_bin_get_child(GTK_BIN(instance));

  if (!ret) {
    return nullptr;
  }

  return cobject_to_phpobject(ret);
}