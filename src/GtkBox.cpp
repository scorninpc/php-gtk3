
#include "GtkBox.h"

/**
 * Constructor
 */
GtkBox_::GtkBox_() = default;

/**
 * Destructor
 */
GtkBox_::~GtkBox_() = default;

/**
 *  PHP Constructor
 */
void GtkBox_::__construct(Php::Parameters &parameters)
{
    // Cast GtkOrientation param
    int a = parameters[0];
    GtkOrientation passedWidget = (GtkOrientation)a;

    // Verify if has padding parameter
    int padding = 0;
    if(parameters.size() >= 2) {
        padding = parameters[1];
    }

    // Create the box
    instance = (gpointer *)gtk_box_new(passedWidget, padding);
}

/**
 *  Pack widget to a box on next start
 */
void GtkBox_::pack_start(Php::Parameters &parameters)
{
    // Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    // Verify if has expand parameter
    gboolean expand = false;
    if(parameters.size() >= 2) {
        expand = parameters[1];
    }

    // Verify if has fill parameter
    gboolean fill = false;
    if(parameters.size() >= 3) {
        fill = parameters[2];
    }

    // Verify if has padding parameter
    int padding = 0;
    if(parameters.size() >= 3) {
        padding = parameters[4];
    }

    // Pack the widget
    gtk_box_pack_start(GTK_BOX(instance), GTK_WIDGET(passedWidget->get_instance()), expand, fill, padding);
}

/**
 *  Pack widget to a box on next end
 */
void GtkBox_::pack_end(Php::Parameters &parameters)
{
    // Get the widget to packed
    Php::Value object = parameters[0];
    if (!object.instanceOf("GtkWidget")) throw Php::Exception("parameter expect GtkWidget instance");
    GtkWidget_ *passedWidget = (GtkWidget_ *)object.implementation();

    // Verify if has expand parameter
    gboolean expand = false;
    if(parameters.size() >= 2) {
        expand = parameters[1];
    }

    // Verify if has fill parameter
    gboolean fill = false;
    if(parameters.size() >= 3) {
        fill = parameters[2];
    }

    // Verify if has padding parameter
    int padding = 0;
    if(parameters.size() >= 3) {
        padding = parameters[4];
    }

    // Pack the widget
    gtk_box_pack_end(GTK_BOX(instance), GTK_WIDGET(passedWidget->get_instance()), expand, fill, padding);
}

/**
 * Sets the homogeneous property of box , controlling whether or not all children of box are given equal space in the box.
 */
void GtkBox_::set_homogeneous(Php::Parameters &parameters)
{
    // Verify if has expand parameter
    gboolean homogeneous = false;
    if(parameters.size() >= 1) {
        homogeneous = parameters[0];
    }

    gtk_box_set_homogeneous(GTK_BOX(instance), homogeneous);
}

/**
 * Sets the spacing property of box , which is the number of pixels to place between children of box.
 */
void GtkBox_::set_spacing(Php::Parameters &parameters)
{
    // Verify if has expand parameter
    gboolean spacing = false;
    if(parameters.size() >= 1) {
        spacing = parameters[0];
    }

    gtk_box_set_spacing(GTK_BOX(instance), spacing);
}