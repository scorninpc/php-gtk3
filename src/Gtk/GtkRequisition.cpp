
#include "GtkRequisition.h"

/**
 *  C++ constructor and destructor
 */
GtkRequisition_::GtkRequisition_() = default;
GtkRequisition_::~GtkRequisition_() = default;

/**
 *  PHP Constructor
 */
void GtkRequisition_::__construct(Php::Parameters &parameters)
{
    width = parameters[0];
    height = parameters[1];
}