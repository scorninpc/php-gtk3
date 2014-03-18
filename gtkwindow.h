#ifndef GTK_WINDOW__H
#define GTK_WINDOW__H

void gtk_init_gtkwindow(TSRMLS_D);
 
PHP_METHOD(GtkWindow, __construct);
PHP_METHOD(GtkWindow, set_title);
PHP_METHOD(GtkWindow, set_resizable);
PHP_METHOD(GtkWindow, set_default_size);
PHP_METHOD(GtkWindow, set_size_request);
PHP_METHOD(GtkWindow, show_all);
PHP_METHOD(GtkWindow, set_position);
PHP_METHOD(GtkWindow, connect);

#endif /* GTK_WINDOW__H */

void quit_window();
