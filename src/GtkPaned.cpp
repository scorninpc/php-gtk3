
#include "GtkPaned.h"

/**
 * Constructor
 */
GtkPaned_::GtkPaned_() = default;

/**
 * Destructor
 */
GtkPaned_::~GtkPaned_() = default;

/**
 *  PHP Constructor
 */
void GtkPaned_::__construct(Php::Parameters &parameters)
{
	// Cast GtkOrientation param
    int a = parameters[0];
    GtkOrientation passedWidget = (GtkOrientation)a;

	instance = (gpointer *) gtk_paned_new(passedWidget);
}

/**
 *  Adds a child to the top or left pane with default parameters.
 */
void GtkPaned_::add1(Php::Parameters &parameters)
{
    // Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    // Pack the widget
    gtk_paned_add1(GTK_PANED(instance), GTK_WIDGET(passedWidget->get_instance()));
}

/**
 *  Adds a child to the bottom or right pane with default parameters.
 */
void GtkPaned_::add2(Php::Parameters &parameters)
{
    // Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    // Pack the widget
    gtk_paned_add2(GTK_PANED(instance), GTK_WIDGET(passedWidget->get_instance()));
}

/**
 * Adds a child to the top or left pane.
 */
void GtkPaned_::pack1(Php::Parameters &parameters)
{
    // Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    // Verify if has resize parameter
    gboolean resize = false;
    if(parameters.size() >= 2) {
        resize = parameters[1];
    }

    // Verify if has shrink parameter
    gboolean shrink = false;
    if(parameters.size() >= 3) {
        shrink = parameters[2];
    }

    // Pack the widget
    gtk_paned_pack1(GTK_PANED(instance), GTK_WIDGET(passedWidget->get_instance()), resize, shrink);
}

/**
 * Adds a child to the bottom or right pane.
 */
void GtkPaned_::pack2(Php::Parameters &parameters)
{
    // Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    // Verify if has resize parameter
    gboolean resize = false;
    if(parameters.size() >= 2) {
        resize = parameters[1];
    }

    // Verify if has shrink parameter
    gboolean shrink = false;
    if(parameters.size() >= 3) {
        shrink = parameters[2];
    }

    // Pack the widget
    gtk_paned_pack2(GTK_PANED(instance), GTK_WIDGET(passedWidget->get_instance()), resize, shrink);
}

/**
 * Obtains the first child of the paned widget.
 *
 * @todo need to test
 */
Php::Value GtkPaned_::get_child1()
{
    // Create the gtk button
    GtkWidget *widget = gtk_paned_get_child1(GTK_PANED(instance));
    
    // Create the PHP-GTK object and set GTK object
    GtkWidget_ *widget_ = new GtkWidget_();
    widget_->set_instance((gpointer *)widget);

    // Return PHP-GTK object
    return Php::Object("GtkWidget", widget_);
}

/**
 * Obtains the second child of the paned widget.
 *
 * @todo need to test
 */
Php::Value GtkPaned_::get_child2()
{
    // Create the gtk button
    GtkWidget *widget = gtk_paned_get_child2(GTK_PANED(instance));
    
    // Create the PHP-GTK object and set GTK object
    GtkWidget_ *widget_ = new GtkWidget_();
    widget_->set_instance((gpointer *)widget);

    // Return PHP-GTK object
    return Php::Object("GtkWidget", widget_);
}

/**
 * Sets the position of the divider between the two panes.
 */
void GtkPaned_::set_position(Php::Parameters &parameters)
{
    gtk_paned_set_position(GTK_PANED(instance), parameters[0]);
}

/**
 * Obtains the position of the divider between the two panes
 */
Php::Value GtkPaned_::get_position()
{
    return gtk_paned_get_position(GTK_PANED(instance));
}