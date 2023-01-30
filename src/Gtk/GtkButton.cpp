
#include "GtkButton.h"

/**
 * Constructor
 */
GtkButton_::GtkButton_() = default;

/**
 * Destructor
 */
GtkButton_::~GtkButton_() = default;

void GtkButton_::__construct()
{
	instance = (gpointer *)gtk_button_new ();

}

Php::Value GtkButton_::new_with_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_button_new_with_label (label);

	GtkButton_ *return_parsed = new GtkButton_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkButton", return_parsed);
}

Php::Value GtkButton_::new_with_mnemonic(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	GtkWidget *ret = gtk_button_new_with_mnemonic (label);

	GtkButton_ *return_parsed = new GtkButton_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkButton", return_parsed);
}

Php::Value GtkButton_::new_from_icon_name(Php::Parameters &parameters)
{
	std::string s_icon_name = parameters[0];
	gchar *icon_name = (gchar *)s_icon_name.c_str();

	int int_size = (int)parameters[1];
	GtkIconSize size = (GtkIconSize)int_size;

	GtkWidget *ret = gtk_button_new_from_icon_name (icon_name, size);

	GtkWidget_ *return_parsed = new GtkWidget_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkButton", return_parsed);
}

Php::Value GtkButton_::new_from_stock()
{
	// GtkWidget *ret = gtk_button_new_from_stock ();

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
	Php::deprecated << "new_from_stock is deprecated on Gtk 3.10" << std::endl;
	return 0;
}

void GtkButton_::pressed()
{
	// gtk_button_pressed (GTK_BUTTON(instance));
	Php::deprecated << "pressed is deprecated on Gtk 2.20" << std::endl;

}

void GtkButton_::released()
{
	// gtk_button_released (GTK_BUTTON(instance));
	Php::deprecated << "released is deprecated on Gtk 2.20" << std::endl;

}

void GtkButton_::clicked()
{
	gtk_button_clicked (GTK_BUTTON(instance));

}

void GtkButton_::enter()
{
	// gtk_button_enter (GTK_BUTTON(instance));
	Php::deprecated << "enter is deprecated on Gtk 2.20" << std::endl;

}

void GtkButton_::leave()
{
	// gtk_button_leave (GTK_BUTTON(instance));
	Php::deprecated << "leave is deprecated on Gtk 2.20" << std::endl;

}

void GtkButton_::set_relief(Php::Parameters &parameters)
{
	int int_relief = (int)parameters[0];
	GtkReliefStyle relief = (GtkReliefStyle)int_relief;

	gtk_button_set_relief (GTK_BUTTON(instance), relief);

}

Php::Value GtkButton_::get_relief()
{
	GtkReliefStyle ret = gtk_button_get_relief (GTK_BUTTON(instance));

	return ret;
}

Php::Value GtkButton_::get_label()
{
	std::string ret = gtk_button_get_label (GTK_BUTTON(instance));

	return ret;
}

void GtkButton_::set_label(Php::Parameters &parameters)
{
	std::string s_label = parameters[0];
	gchar *label = (gchar *)s_label.c_str();

	gtk_button_set_label (GTK_BUTTON(instance), label);

}

Php::Value GtkButton_::get_use_stock()
{
	// gboolean ret = gtk_button_get_use_stock (GTK_BUTTON(instance));

	// return ret;
	Php::deprecated << "get_use_stock is deprecated on Gtk 3.10" << std::endl;
	return 0;
}

void GtkButton_::set_use_stock(Php::Parameters &parameters)
{
	// gboolean use_stock = (gboolean)parameters[0];

	// gtk_button_set_use_stock (GTK_BUTTON(instance), use_stock);

	Php::deprecated << "set_use_stock is deprecated on Gtk 3.10" << std::endl;

}

Php::Value GtkButton_::get_use_underline()
{
	gboolean ret = gtk_button_get_use_underline (GTK_BUTTON(instance));

	return ret;
}

void GtkButton_::set_use_underline(Php::Parameters &parameters)
{
	gboolean use_underline = (gboolean)parameters[0];

	gtk_button_set_use_underline (GTK_BUTTON(instance), use_underline);

}

void GtkButton_::set_focus_on_click(Php::Parameters &parameters)
{
	 gboolean focus_on_click = (gboolean)parameters[0];

	 gtk_button_set_focus_on_click (GTK_BUTTON(instance), focus_on_click);

	//Php::deprecated << "set_focus_on_click is deprecated on Gtk 3.20" << std::endl;

}

Php::Value GtkButton_::get_focus_on_click()
{
	// gboolean ret = gtk_button_get_focus_on_click (GTK_BUTTON(instance));

	// return ret;

	Php::deprecated << "get_focus_on_click is deprecated on Gtk 3.20" << std::endl;
	return 0;
}

void GtkButton_::set_alignment(Php::Parameters &parameters)
{
	// double d_xalign = parameters[0];
	// gfloat xalign = (float)d_xalign;

	// double d_yalign = parameters[1];
	// gfloat yalign = (float)d_yalign;

	// gtk_button_set_alignment (GTK_BUTTON(instance), xalign, yalign);

	Php::deprecated << "set_alignment is deprecated on Gtk 3.14" << std::endl;

}

void GtkButton_::get_alignment(Php::Parameters &parameters)
{

	Php::deprecated << "get_alignment is deprecated on Gtk 3.14" << std::endl;
}

void GtkButton_::set_image(Php::Parameters &parameters)
{
	GtkWidget *image;
	if(parameters.size() > 0) {
		Php::Value object_image = parameters[0];
		GtkWidget_ *phpgtk_image = (GtkWidget_ *)object_image.implementation();
		image = GTK_WIDGET(phpgtk_image->get_instance());
	}

	gtk_button_set_image (GTK_BUTTON(instance), image);

}

Php::Value GtkButton_::get_image()
{
	gpointer *ret = (gpointer *)gtk_button_get_image (GTK_BUTTON(instance));

	// GtkWidget_ *return_parsed = new GtkWidget_();
	// return_parsed->set_instance((gpointer *)ret);
	// return Php::Object("GtkWidget", return_parsed);
	return cobject_to_phpobject(ret);
}

void GtkButton_::set_image_position(Php::Parameters &parameters)
{
	int int_position = (int)parameters[0];
	GtkPositionType position = (GtkPositionType)int_position;

	gtk_button_set_image_position (GTK_BUTTON(instance), position);

}

Php::Value GtkButton_::get_image_position()
{
	GtkPositionType ret = gtk_button_get_image_position (GTK_BUTTON(instance));

	return ret;
}

void GtkButton_::set_always_show_image(Php::Parameters &parameters)
{
	gboolean always_show = (gboolean)parameters[0];

	gtk_button_set_always_show_image (GTK_BUTTON(instance), always_show);

}

Php::Value GtkButton_::get_always_show_image()
{
	gboolean ret = gtk_button_get_always_show_image (GTK_BUTTON(instance));

	return ret;
}

Php::Value GtkButton_::get_event_window()
{
	// GdkWindow ret = gtk_button_get_event_window (GTK_BUTTON(instance));

	// return ret;

	throw Php::Exception("GtkButton_::get_event_window not implemented");
	return 0;
}

