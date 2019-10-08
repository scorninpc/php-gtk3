
#include "GtkListBoxRow.h"


/**
 * Return original instance
 */
GtkListBoxRow *GtkListBoxRow_::get_row()
{
    return row;
}

/**
 * Set the original GtkListBoxRow
 */
void GtkListBoxRow_::set_row(GtkListBoxRow *pased_row)
{
    row = pased_row;
}

/**
 * Constructor
 */
GtkListBoxRow_::GtkListBoxRow_() = default;

/**
 * Destructor
 */
GtkListBoxRow_::~GtkListBoxRow_() = default;

// 
void GtkListBoxRow_::__construct()
{
	instance = (gpointer *)gtk_list_box_row_new();

}