/**
 * Main file of gtk extension
 */
 
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_gtk.h"
#include "gtk/gtk.h"

#include "src/gtk/gtkwindow.h"

/* extension control */
PHP_MINIT_FUNCTION(gtk)
{
	REGISTER_LONG_CONSTANT("GTK_WIN_POS_NONE", GTK_WIN_POS_NONE, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("GTK_WIN_POS_CENTER", GTK_WIN_POS_CENTER, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("GTK_WIN_POS_MOUSE", GTK_WIN_POS_MOUSE, CONST_CS | CONST_PERSISTENT);
	
	gtk_init_gtk(TSRMLS_C);
	gtk_init_gtkwindow(TSRMLS_C);
	
	return SUCCESS;
}

zend_module_entry gtk_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"gtk",
	NULL,
	PHP_MINIT(gtk),
	NULL,
	NULL,
	NULL,
	NULL,
#if ZEND_MODULE_API_NO >= 20010901
	PHP_GTK_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_GTK
ZEND_GET_MODULE(gtk)
#endif

/* gtk class */
zend_class_entry *gtk_ce_gtk;

static zend_function_entry gtk_methods[] = {
  PHP_ME(Gtk, main, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_ME(Gtk, main_quit, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  
  {NULL, NULL, NULL}
};

/**
 * Inicializa a classe GTK
 */
void gtk_init_gtk(TSRMLS_D) {
	zend_class_entry ce;

	// Registra a classe
	INIT_CLASS_ENTRY(ce, "Gtk", gtk_methods);
	gtk_ce_gtk = zend_register_internal_class(&ce TSRMLS_CC);

	// Inicializa o GTK
	gtk_init(0, NULL);
	
	// Constantes
	zend_declare_class_constant_long(gtk_ce_gtk, ZEND_STRS("WIN_POS_NONE")-1, GTK_WIN_POS_NONE TSRMLS_CC);
	zend_declare_class_constant_long(gtk_ce_gtk, ZEND_STRS("WIN_POS_CENTER")-1, GTK_WIN_POS_CENTER TSRMLS_CC);
	zend_declare_class_constant_long(gtk_ce_gtk, ZEND_STRS("WIN_POS_MOUSE")-1, GTK_WIN_POS_MOUSE TSRMLS_CC);
	zend_declare_class_constant_long(gtk_ce_gtk, ZEND_STRS("WIN_POS_CENTER_ALWAYS")-1, GTK_WIN_POS_CENTER_ALWAYS TSRMLS_CC);
	zend_declare_class_constant_long(gtk_ce_gtk, ZEND_STRS("WIN_POS_CENTER_ON_PARENT")-1, GTK_WIN_POS_CENTER_ON_PARENT TSRMLS_CC);
}

PHP_METHOD(Gtk, main) {
	gtk_main();
}

PHP_METHOD(Gtk, main_quit) {
	printf("OK\n");
	gtk_main_quit();
}
