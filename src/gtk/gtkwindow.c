/**
 * Implementation of GtkWindow
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html
 */

#include <php.h>

#include <gtk/gtk.h>

#include "gtkwindow.h"
 
zend_class_entry *gtk_ce_gtkwindow;

GtkWidget* obj_window;

static zend_function_entry gtkwindow_methods[] = {
  PHP_ME(GtkWindow, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(GtkWindow, set_title, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(GtkWindow, set_resizable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(GtkWindow, set_default_size, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(GtkWindow, set_size_request, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(GtkWindow, show_all, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(GtkWindow, set_position, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(GtkWindow, connect, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  {NULL, NULL, NULL}
};
 
void gtk_init_gtkwindow(TSRMLS_D) {
  zend_class_entry ce;
 
  INIT_CLASS_ENTRY(ce, "GtkWindow", gtkwindow_methods);
  gtk_ce_gtkwindow = zend_register_internal_class(&ce TSRMLS_CC);
}
 
/**
 * Constructor
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#GtkWindow-struct
 */
PHP_METHOD(GtkWindow, __construct) {
	obj_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(obj_window), GTK_WIN_POS_CENTER_ALWAYS);
}

/**
 * set_title
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-title
 */
PHP_METHOD(GtkWindow, set_title) {
	char *title;
	int title_len;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &title, &title_len);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_title(GTK_WINDOW(obj_window), title);
}

/**
 * set_resizable
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWindow.html#gtk-window-set-resizable
 */
PHP_METHOD(GtkWindow, set_resizable) {
	int *resizable;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &resizable);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_resizable(GTK_WINDOW(obj_window), (gboolean)resizable);
}

/**
 * show_all
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWidget.html#gtk-widget-show-all
 */
PHP_METHOD(GtkWindow, show_all) {
	gtk_widget_show_all(obj_window);
}

/**
 * set_default_size
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-default-size
 */
PHP_METHOD(GtkWindow, set_default_size) {
	int *width;
	int *height;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &width, &height);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_default_size(GTK_WINDOW(obj_window), (int)width, (int)height);
}

/**
 * set_size_request
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWidget.html#gtk-widget-set-size-request
 */
PHP_METHOD(GtkWindow, set_size_request) {
	int *width;
	int *height;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &width, &height);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_widget_set_size_request(GTK_WINDOW(obj_window), (int)width, (int)height);
}

/**
 * set_position
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWindow.html#gtk-window-set-position
 */
PHP_METHOD(GtkWindow, set_position) {
	int *position;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &position);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_position(GTK_WINDOW(obj_window), (int)position);
}

/**
 * connect
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-title
 */
PHP_METHOD(GtkWindow, connect) {
	
	char *signal;
	char *signal_string;
	char *function_check;
	
	int signal_len;
	zval *function_callback;
	
	// Busca os parametros
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sz", &signal, &signal_len, &function_callback) == FAILURE) {
		return;
	} 
	
	// Verifica se o callback existe
	if(!zend_is_callable(function_callback, 0, &function_check)) {
		zend_throw_exception_ex(zend_exception_get_default(TSRMLS_C), -1 TSRMLS_CC, "Callback function not found");
	}
	
	gtk_signal_connect(GTK_OBJECT(obj_window), signal, GTK_SIGNAL_FUNC(quit_window), (gpointer)function_callback);
}

void quit_window(GtkWidget *widget, gpointer data) {
	zval retval;
	zval *function_callback = (zval *)data;
	
	char *cstr;
	if (Z_TYPE_P(function_callback) != IS_STRING) {
		convert_to_string(function_callback);
	}
	printf("OK");
	cstr = Z_STRVAL_P(function_callback);
	printf("OK");
	printf("\n->%s<--\n", cstr);
	

	//~ printf("1\n");
	//~ INIT_ZVAL(retval);
	//~ printf("2\n");
	//~ 
	//~ // Chama o callback
	//~ if(call_user_function_ex(EG(function_table), NULL, function_callback, &retval, 0, NULL TSRMLS_CC, NULL, NULL) != SUCCESS) {
		//~ printf("ERR\n");
		//~ zend_error(E_ERROR, "Function call failed");
	//~ }
	//~ 
	//~ printf("3\n");
}

