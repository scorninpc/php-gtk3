
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
GtkTreeIter *GtkTreeIter_::get_iter()
{
    return iter;
}

/**
 * Set the original GtkTreeIter
 */
void GtkTreeIter_::set_iter(GtkTreeIter *passed_iter)
{
    iter = passed_iter;
}