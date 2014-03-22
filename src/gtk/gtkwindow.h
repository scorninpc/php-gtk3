#ifndef GTK_WINDOW_H
#define GTK_WINDOW_H

PHP_METHOD(GtkWindow, __construct);
PHP_METHOD(GtkWindow, set_title);
PHP_METHOD(GtkWindow, set_resizable);
PHP_METHOD(GtkWindow, set_default_size);
PHP_METHOD(GtkWindow, set_size_request);
PHP_METHOD(GtkWindow, show_all);
PHP_METHOD(GtkWindow, set_position);
PHP_METHOD(GtkWindow, connect);
PHP_METHOD(GtkWindow, add);

#endif /* GTK_WINDOW_H */

void quit_window();
void gtk_init_gtkwindow(TSRMLS_D);
void gtkwindow_free_storage(void *object TSRMLS_DC);
zend_object_value gtkwindow_create_handler(zend_class_entry *type TSRMLS_DC);
