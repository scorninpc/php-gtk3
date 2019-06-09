#include "GladeProject.h"

void GladeProject_::set_project(GladeProject *passed_project)
{
	project = passed_project;
}
GladeProject *GladeProject_::get_project()
{
	return project;
}

/**
 * Constructor
 */
GladeProject_::GladeProject_() = default;

/**
 * Destructor
 */
GladeProject_::~GladeProject_() = default;

void GladeProject_::__construct()
{
	project = glade_project_new();
}

