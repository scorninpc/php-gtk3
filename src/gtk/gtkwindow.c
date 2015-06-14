/**
 * Implementation of GtkWindow
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html
 */

#include <php.h>

#include <gtk/gtk.h>

#include "gtkwindow.h"

zend_object_handlers gtkwindow_object_handlers;
zend_class_entry *gtkwindow_ce;

struct gtk_widget_object {
	zend_object std;
	GtkWidget *widget;
};

// PHP GtkWindow methods
static zend_function_entry gtkwindow_methods[] = {
	PHP_ME(GtkWindow, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, set_title, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, set_resizable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, set_default_size, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, set_size_request, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, show_all, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, set_position, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, connect, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(GtkWindow, add, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	{NULL, NULL, NULL}
};

// Initialize class
void gtk_init_gtkwindow(TSRMLS_D) {
	zend_class_entry ce;

	// Registry class
	INIT_CLASS_ENTRY(ce, "GtkWindow", gtkwindow_methods);
	gtkwindow_ce = zend_register_internal_class(&ce TSRMLS_CC);

	// Handle to clone objects
	gtkwindow_ce->create_object = gtkwindow_create_handler;
	memcpy(&gtkwindow_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	gtkwindow_object_handlers.clone_obj = NULL;
}

// Destroy a object
void gtkwindow_free_storage(void *object TSRMLS_DC)
{
    struct gtk_widget_object *obj = (struct gtk_widget_object *)object;
    efree(obj->widget); 

    zend_hash_destroy(obj->std.properties);
    FREE_HASHTABLE(obj->std.properties);

    efree(obj);
}

// Create a handler of object
zend_object_value gtkwindow_create_handler(zend_class_entry *type TSRMLS_DC)
{
    zval *tmp;
    zend_object_value retval;

    struct gtk_widget_object *obj = (struct gtk_widget_object *)emalloc(sizeof(struct gtk_widget_object));
    memset(obj, 0, sizeof(struct gtk_widget_object));
    obj->std.ce = type;

    ALLOC_HASHTABLE(obj->std.properties);
    zend_hash_init(obj->std.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
    
    #if PHP_VERSION_ID < 50399
		zend_hash_copy(obj->std.properties, &type->default_properties, (copy_ctor_func_t)zval_add_ref, (void *)&tmp, sizeof(zval *));
	#else
		object_properties_init((zend_object*) &(obj->std), type);
	#endif
    
    retval.handle = zend_objects_store_put(obj, NULL, gtkwindow_free_storage, NULL TSRMLS_CC);
    retval.handlers = &gtkwindow_object_handlers;

    return retval;
}
 
/**
 * Constructor
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#GtkWindow-struct
 */
PHP_METHOD(GtkWindow, __construct) {
	GtkWidget *widget = NULL;
    zval *object = getThis();
    struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(object TSRMLS_CC);
    
	obj->widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
}

/**
 * set_title
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-title
 */
PHP_METHOD(GtkWindow, set_title) {
    struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
	char *title;
	int title_len;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &title, &title_len);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_title(GTK_WINDOW(widget), title);
}

/**
 * set_resizable
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWindow.html#gtk-window-set-resizable
 */
PHP_METHOD(GtkWindow, set_resizable) {
	struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
	int *resizable;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &resizable);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_resizable(GTK_WINDOW(widget), (gboolean)resizable);
}

/**
 * show_all
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWidget.html#gtk-widget-show-all
 */
PHP_METHOD(GtkWindow, show_all) {
	struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
	gtk_widget_show_all(widget);
}

/**
 * set_default_size
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-default-size
 */
PHP_METHOD(GtkWindow, set_default_size) {
	struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
	int *width;
	int *height;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &width, &height);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_default_size(GTK_WINDOW(widget), (int)width, (int)height);
}

/**
 * set_size_request
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWidget.html#gtk-widget-set-size-request
 */
PHP_METHOD(GtkWindow, set_size_request) {
	struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
	int *width;
	int *height;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &width, &height);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_widget_set_size_request(GTK_WINDOW(widget), (int)width, (int)height);
}

/**
 * set_position
 * 
 * @see https://developer.gnome.org/gtk3/3.4/GtkWindow.html#gtk-window-set-position
 */
PHP_METHOD(GtkWindow, set_position) {
	struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
	int *position;
	
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &position);
	
	if(result != SUCCESS) {
		return;
	}
	
	gtk_window_set_position(GTK_WINDOW(widget), (int)position);
}

/**
 * connect
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkWindow.html#gtk-window-set-title
 */
PHP_METHOD(GtkWindow, connect) {
	struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
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
	
	//call_user_function_ex(CG(function_table), NULL, function_callback, &retval, 0, NULL, 1, NULL TSRMLS_CC);

	//~ g_signal_connect(G_OBJECT(widget), "destroy", G_CALLBACK(aconnect), NULL);
	g_signal_connect (G_OBJECT (widget), "destroy", G_CALLBACK (aconnect),  (gpointer)function_callback);
	
	
	/*
	struct gtk_widget_object *obj = (struct gtk_widget_object *)zend_object_store_get_object(getThis() TSRMLS_CC);
    GtkWidget *widget = obj->widget;
    
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
	
	g_signal_connect(G_OBJECT(widget), signal, G_CALLBACK(quit_window), (gpointer)function_callback);
	*/
}


static void aconnect(GtkWidget *widget, gpointer data) {
	
	zval *retval;
	zval *function_name = (zval *)data;
	zval *arglist[3];
	
	call_user_function(EG(function_table), NULL, function_name, &retval, 0, arglist TSRMLS_CC);
	//~ call_user_function(CG(function_table), NULL, function_name, &retval, 0, arglist TSRMLS_CC);
	
	/*
	char *cstr;
	if (Z_TYPE_P(function_callback) != IS_STRING) {
		convert_to_string(function_callback);
	}
	printf("OK");
	cstr = Z_STRVAL_P(function_callback);
	printf("OK");
	printf("\n->%s<--\n", cstr);
	*/

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

/**
 * add
 * 
 * @see https://developer.gnome.org/gtk3/stable/GtkContainer.html#gtk-container-add
 */
PHP_METHOD(GtkWindow, add)
{
	zval *resource;
	int res_type = -1; 
	int result;
	
	result = zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &resource);
	if (result == FAILURE) {
		return;
	}
	
	convert_to_object_ex(&resource);
	GtkWidget *widget = (GtkWidget *)resource;
	
	//gtk_container_add(GTK_CONTAINER(obj_window), widget);
}
