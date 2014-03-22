#ifndef GTK_BUTTON_H
#define GTK_BUTTON_H
 
void gtk_init_gtkbutton(TSRMLS_D);
static void php_file_close(zend_rsrc_list_entry *rsrc TSRMLS_DC);
void gtkbutton_initialize_resources(int module_number);

PHP_METHOD(GtkButton, __construct);

#endif /* GTK_BUTTON_H */
