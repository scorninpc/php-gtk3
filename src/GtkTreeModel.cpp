
#include "GtkTreeModel.h"

/**
 * Constructor
 */
GtkTreeModel_::GtkTreeModel_() = default;

/**
 * Destructor
 */
GtkTreeModel_::~GtkTreeModel_() = default;

/**
 * Return original GtkTreeModel
 */
GtkTreeModel *GtkTreeModel_::get_model()
{
    return model;
}

/**
 * Set the original GtkTreeModel
 */
void GtkTreeModel_::set_model(GtkTreeModel *passed_model)
{
    model = passed_model;
}

/**
 *  PHP Constructor
 */
void GtkTreeModel_::__construct(Php::Parameters &parameters)
{
	
}