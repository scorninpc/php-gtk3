
#include "GtkVBox.h"

/**
 * Constructor
 */
GtkVBox_::GtkVBox_() = default;

/**
 * Destructor
 */
GtkVBox_::~GtkVBox_() = default;

/**
 *  PHP Constructor
 */
void GtkVBox_::__construct(Php::Parameters &parameters)
{
	// Construct the parent
	Php::call("parent::__construct", GTK_ORIENTATION_VERTICAL, 0);

	// Verify if has homogeneous parameter
	if(parameters.size() >= 1) {
		Php::call("parent::set_homogeneous", parameters[0]);
	}

	// Verify if has spacing parameter
	if(parameters.size() >= 2) {
		Php::call("parent::set_spacing", parameters[1]);
	}
}