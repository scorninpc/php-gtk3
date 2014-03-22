/**
 * Implementation of GtkEntry
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkEntry.html
 */

#include <php.h>

#include <gtk/gtk.h>

#include "gtkentry.h"
 
zend_class_entry *gtk_ce_gtkentry;

GtkWidget* obj_entry;

static zend_function_entry gtkentry_methods[] = {
  PHP_ME(GtkEntry, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  {NULL, NULL, NULL}
};
 
void gtk_init_gtkentry(TSRMLS_D) {
  zend_class_entry ce;
 
  INIT_CLASS_ENTRY(ce, "GtkEntry", gtkentry_methods);
  gtk_ce_gtkentry = zend_register_internal_class(&ce TSRMLS_CC);
}
 
/**
 * Constructor
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkEntry.html#GtkEntry-struct
 */
PHP_METHOD(GtkEntry, __construct) {
	obj_entry = gtk_entry_new();
}
