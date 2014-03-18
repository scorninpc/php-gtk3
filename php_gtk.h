#ifndef PHP_GTK_H
#define PHP_GTK_H

void gtk_init_gtk(TSRMLS_D);

extern zend_module_entry gtk_module_entry;
#define phpext_gtk_ptr &gtk_module_entry
extern zend_class_entry *gtk_ce_gtk;
extern PHP_MINIT_FUNCTION(gtk);

#define PHP_GTK_VERSION "0.1.0"

#ifdef PHP_WIN32
#	define PHP_GTK_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_GTK_API __attribute__ ((visibility("default")))
#else
#	define PHP_GTK_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#ifdef ZTS
#define GTK_G(v) TSRMG(gtk_globals_id, zend_gtk_globals *, v)
#else
#define GTK_G(v) (gtk_globals.v)
#endif

#endif	/* PHP_GTK_H */


/* Gtk */
#ifndef GTK__H
#define GTK__H

void gtk_init_gtk(TSRMLS_D);
 
PHP_METHOD(Gtk, main);
PHP_METHOD(Gtk, main_quit);

#endif /* GTK__H */
