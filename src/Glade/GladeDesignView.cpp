#ifdef WITH_GLADEUI
#include "GladeDesignView.h"

/**
 * Constructor
 */
GladeDesignView_::GladeDesignView_() = default;

/**
 * Destructor
 */
GladeDesignView_::~GladeDesignView_() = default;

void GladeDesignView_::__construct(Php::Parameters &parameters)
{
	
	Php::Value object_project = parameters[0];
	GladeProject_ *phpgtk_project = (GladeProject_ *)object_project.implementation();
	GladeProject *project = (GladeProject *)phpgtk_project->get_instance();

	instance = (gpointer *)glade_design_view_new (project);

}

Php::Value GladeDesignView_::get_project()
{
	GladeProject *ret = glade_design_view_get_project (GLADE_DESIGN_VIEW(instance));

	GladeProject_ *project = new GladeProject_();
	project->set_instance((gpointer *)ret);
	return Php::Object("GladeProject", project);
}

Php::Value GladeDesignView_::get_from_project(Php::Parameters &parameters)
{
	Php::Value object_project = parameters[0];
	GladeProject_ *phpgtk_project = (GladeProject_ *)object_project.implementation();
	GladeProject *project = (GladeProject *)phpgtk_project->get_instance();

	GladeDesignView *ret = glade_design_view_get_from_project (project);

	GladeDesignView_ *project_ret = new GladeDesignView_();
	project_ret->set_instance((gpointer *)ret);
	return Php::Object("GladeProject", project_ret);
}

#endif