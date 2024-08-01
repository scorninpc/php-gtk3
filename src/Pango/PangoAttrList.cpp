#include "PangoAttrList.h"

/**
 * Constructor
 */
PangoAttrList_::PangoAttrList_() = default;

/**
 * Destructor
 */
PangoAttrList_::~PangoAttrList_() = default;

void PangoAttrList_::__construct()
{
	instance = (gpointer *)pango_attr_list_new ();
}

Php::Value PangoAttrList_::get_attributes()
{
	throw Php::Exception("PangoAttrList::get_attributes() not implemented");

	/*
	GSList *ret = pango_attr_list_get_attributes(PANGO_ATTR_LIST(instance));

	Php::Value ret_arr;

	for(int index=0; GSList *item=g_slist_nth(ret, index); index++) {

		PangoAttribute_ *return_parsed = new PangoAttribute_();

		return_parsed->set_instance(
			(gpointer *)PANGO_ATTRIBUTE(item->data) // @TODO
		);

		ret_arr[index] = Php::Object("PangoAttribute", return_parsed);
	}
	
	return ret_arr;
	*/
}