
#include "GtkCalendar.h"

/**
 * Constructor
 */
GtkCalendar_::GtkCalendar_() = default;

/**
 * Destructor
 */
GtkCalendar_::~GtkCalendar_() = default;

void GtkCalendar_::__construct()
{
	instance = (gpointer *)gtk_calendar_new ();

}

void GtkCalendar_::select_month(Php::Parameters &parameters)
{
	guint month = (int)parameters[0];

	guint year = (int)parameters[1];

	gtk_calendar_select_month (GTK_CALENDAR(instance), month, year);

}

void GtkCalendar_::select_day(Php::Parameters &parameters)
{
	guint day = (int)parameters[0];

	gtk_calendar_select_day (GTK_CALENDAR(instance), day);

}

void GtkCalendar_::mark_day(Php::Parameters &parameters)
{
	guint day = (int)parameters[0];

	gtk_calendar_mark_day (GTK_CALENDAR(instance), day);

}

void GtkCalendar_::unmark_day(Php::Parameters &parameters)
{
	guint day = (int)parameters[0];

	gtk_calendar_unmark_day (GTK_CALENDAR(instance), day);

}

Php::Value GtkCalendar_::get_day_is_marked(Php::Parameters &parameters)
{
	guint day = (int)parameters[0];

	gboolean ret = gtk_calendar_get_day_is_marked (GTK_CALENDAR(instance), day);

	return ret;
}

void GtkCalendar_::clear_marks()
{
	gtk_calendar_clear_marks (GTK_CALENDAR(instance));

}

Php::Value GtkCalendar_::get_display_options()
{
	GtkCalendarDisplayOptions ret = gtk_calendar_get_display_options (GTK_CALENDAR(instance));

	return ret;
}

void GtkCalendar_::set_display_options(Php::Parameters &parameters)
{
	int int_flags = (int)parameters[0];
	GtkCalendarDisplayOptions flags = (GtkCalendarDisplayOptions)int_flags;

	gtk_calendar_set_display_options (GTK_CALENDAR(instance), flags);

}

Php::Value GtkCalendar_::get_date(Php::Parameters &parameters)
{
	guint year;
	guint month;
	guint day;

	gtk_calendar_get_date (GTK_CALENDAR(instance), &year, &month, &day);

	// Cria o retorno
	Php::Value arr;
	arr[0] = arr["year"] = (int)year;
	arr[1] = arr["month"] = (int)month;
	arr[2] = arr["day"] = (int)day;

	return arr;
}

void GtkCalendar_::set_detail_func(Php::Parameters &parameters)
{
	// GtkCalendarDetailFunc *func;
	// if(parameters.size() > 0) {
	// 	Php::Value object_func = parameters[0];
	// 	GtkCalendarDetailFunc_ *phpgtk_func = (GtkCalendarDetailFunc_ *)object_func.implementation();
	// 	func = GTK_WIDGET(phpgtk_func->get_instance());
	// }

	// gpointer data = (gpointer)parameters[1];


	// gtk_calendar_set_detail_func (GTK_CALENDAR(instance), func, data, destroy);

	throw Php::Exception("GtkCalendar_::set_detail_func not implemented");

}

Php::Value GtkCalendar_::get_detail_width_chars()
{
	gint ret = gtk_calendar_get_detail_width_chars (GTK_CALENDAR(instance));

	return ret;
}

void GtkCalendar_::set_detail_width_chars(Php::Parameters &parameters)
{
	gint chars = (gint)parameters[0];

	gtk_calendar_set_detail_width_chars (GTK_CALENDAR(instance), chars);

}

Php::Value GtkCalendar_::get_detail_height_rows()
{
	gint ret = gtk_calendar_get_detail_height_rows (GTK_CALENDAR(instance));

	return ret;
}

void GtkCalendar_::set_detail_height_rows(Php::Parameters &parameters)
{
	gint rows = (gint)parameters[0];

	gtk_calendar_set_detail_height_rows (GTK_CALENDAR(instance), rows);

}

