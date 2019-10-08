
#include "GtkTreeIter.h"

/**
 * Constructor
 */
GtkTreeIter_::GtkTreeIter_() = default;

/**
 * Destructor
 */
GtkTreeIter_::~GtkTreeIter_() = default;

/**
 * Return original GtkTreeIter
 */
GtkTreeIter GtkTreeIter_::get_instance()
{
    return instance;
}

/**
 * Set the original GtkTreeIter
 */
void GtkTreeIter_::set_instance(GtkTreeIter passed_instance)
{
    instance = passed_instance;
}