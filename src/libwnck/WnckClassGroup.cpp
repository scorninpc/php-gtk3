
#include "WnckClassGroup.h"

/**
 *  
 */
/**
 * Constructor
 */
WnckClassGroup_::WnckClassGroup_() = default;
WnckClassGroup_::~WnckClassGroup_() = default;

/**
 * https://developer.gnome.org/libwnck/stable/WnckClassGroup.html#wnck-class-group-get-id
 */
Php::Value WnckClassGroup_::get_id()
{
	std::string ret = wnck_class_group_get_id(WNCK_CLASS_GROUP(instance));

	return ret;
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckClassGroup.html#wnck-class-group-get-name
 */
Php::Value WnckClassGroup_::get_name()
{
	std::string ret =  wnck_class_group_get_name(WNCK_CLASS_GROUP(instance));

	return ret;
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckClassGroup.html#wnck-class-group-get-icon
 */
Php::Value WnckClassGroup_::get_icon()
{
	GdkPixbuf *ret = wnck_class_group_get_icon(WNCK_CLASS_GROUP(instance));

	GdkPixbuf_ *widget_ = new GdkPixbuf_();
	widget_->set_instance(ret);
	return Php::Object("GdkPixbuf", widget_);
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckClassGroup.html#wnck-class-group-get-mini-icon
 */
Php::Value WnckClassGroup_::get_mini_icon()
{
	GdkPixbuf *ret = wnck_class_group_get_mini_icon(WNCK_CLASS_GROUP(instance));

	GdkPixbuf_ *widget_ = new GdkPixbuf_();
	widget_->set_instance(ret);
	return Php::Object("GdkPixbuf", widget_);
}

/**
 * https://developer.gnome.org/libwnck/stable/WnckClassGroup.html#wnck-class-group-get-windows
 */
Php::Value WnckClassGroup_::get_windows()
{
	GList *ret = wnck_class_group_get_windows(WNCK_CLASS_GROUP(instance));

	Php::Value ret_arr;

	for(int index=0; GList *item=g_list_nth(ret, index); index++) {
		
		WnckWindow_ *widget_ = new WnckWindow_();
		widget_->set_instance((gpointer *)item->data);
		ret_arr[index] = Php::Object("WnckWindow", widget_);
	}

	return ret_arr;
}