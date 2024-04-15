
#include "GtkAdjustment.h"

/**
 * Constructor
 */
GtkAdjustment_::GtkAdjustment_() = default;

/**
 * Destructor
 */
GtkAdjustment_::~GtkAdjustment_() = default;

/**
 *  PHP Constructor
 */
void GtkAdjustment_::__construct(Php::Parameters &parameters)
{
	// Verify if has value parameter
    double value = false;
    if(parameters.size() >= 3) {
        value = parameters[2];
    }

    // Verify if has lower parameter
    double lower = false;
    if(parameters.size() >= 3) {
        lower = parameters[2];
    }

    // Verify if has upper parameter
    double upper = false;
    if(parameters.size() >= 3) {
        upper = parameters[2];
    }

    // Verify if has step_increment parameter
    double step_increment = false;
    if(parameters.size() >= 3) {
        step_increment = parameters[2];
    }

    // Verify if has page_increment parameter
    double page_increment = false;
    if(parameters.size() >= 3) {
        page_increment = parameters[2];
    }

    // Verify if has page_size parameter
    double page_size = false;
    if(parameters.size() >= 3) {
        page_size = parameters[2];
    }

	instance = (gpointer *)gtk_adjustment_new(value, lower, upper, step_increment, page_increment, page_size);
}


Php::Value GtkAdjustment_::get_value()
{
    return gtk_adjustment_get_value(GTK_ADJUSTMENT(instance));
}

void GtkAdjustment_::set_value(Php::Parameters& parameters)
{
    double value = 0;
    value = (double)parameters[0];
    gtk_adjustment_set_value(GTK_ADJUSTMENT(instance), value);
}