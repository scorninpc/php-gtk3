#ifdef WITH_GLADEUI
#include "GladeProject.h"

// void GladeProject_::set_project(GladeProject *passed_project)
// {
// 	project = passed_project;
// }
// GladeProject *GladeProject_::get_project()
// {
// 	return project;
// }

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
	instance = (gpointer *)glade_project_new();
}

Php::Value GladeProject_::selection_get()
{
	GList *ret = glade_project_selection_get(GLADE_PROJECT(instance));

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		
		GladeWidget_ *widget_ = new GladeWidget_();
		widget_->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("GladeWidget", widget_);
	}

	return ret_arr;
}

#endif