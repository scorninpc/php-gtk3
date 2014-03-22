/**
 * Implementation of GtkButton
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkButton.html
 */

#include <php.h>

#include <gtk/gtk.h>

#include "gtkbutton.h"
 
zend_class_entry *gtk_ce_gtkbutton;

GtkWidget* obj_button;

static zend_function_entry gtkbutton_methods[] = {
  PHP_ME(GtkButton, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  {NULL, NULL, NULL}
};
 
void gtk_init_gtkbutton(TSRMLS_D) {
  zend_class_entry ce;
 
  INIT_CLASS_ENTRY(ce, "GtkButton", gtkbutton_methods);
  gtk_ce_gtkbutton = zend_register_internal_class(&ce TSRMLS_CC);
}
 
/**
 * Constructor
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkButton.html#GtkButton-struct
 */
PHP_METHOD(GtkButton, __construct) {
	obj_button = gtk_button_new();
}
