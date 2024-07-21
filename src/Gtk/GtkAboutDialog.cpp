
#include "GtkAboutDialog.h"

/**
 * Constructor
 */
GtkAboutDialog_::GtkAboutDialog_() = default;

/**
 * Destructor
 */
GtkAboutDialog_::~GtkAboutDialog_() = default;

void GtkAboutDialog_::__construct()
{
	instance = (gpointer *)gtk_about_dialog_new ();

}

Php::Value GtkAboutDialog_::get_program_name()
{
	std::string ret = gtk_about_dialog_get_program_name (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_program_name(Php::Parameters &parameters)
{
	std::string s_name = parameters[0];
	gchar *name = (gchar *)s_name.c_str();

	gtk_about_dialog_set_program_name (GTK_ABOUT_DIALOG(instance), name);

}

Php::Value GtkAboutDialog_::get_version()
{
	std::string ret = gtk_about_dialog_get_version (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_version(Php::Parameters &parameters)
{
	std::string s_version = parameters[0];
	gchar *version = (gchar *)s_version.c_str();

	gtk_about_dialog_set_version (GTK_ABOUT_DIALOG(instance), version);

}

Php::Value GtkAboutDialog_::get_copyright()
{
	std::string ret = gtk_about_dialog_get_copyright (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_copyright(Php::Parameters &parameters)
{
	std::string s_copyright = parameters[0];
	gchar *copyright = (gchar *)s_copyright.c_str();

	gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG(instance), copyright);

}

Php::Value GtkAboutDialog_::get_comments()
{
	std::string ret = gtk_about_dialog_get_comments (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_comments(Php::Parameters &parameters)
{
	std::string s_comments = parameters[0];
	gchar *comments = (gchar *)s_comments.c_str();

	gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG(instance), comments);

}

Php::Value GtkAboutDialog_::get_license()
{
	std::string ret = gtk_about_dialog_get_license (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_license(Php::Parameters &parameters)
{
	std::string s_license = parameters[0];
	gchar *license = (gchar *)s_license.c_str();

	gtk_about_dialog_set_license (GTK_ABOUT_DIALOG(instance), license);

}

Php::Value GtkAboutDialog_::get_wrap_license()
{
	bool ret = gtk_about_dialog_get_wrap_license (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_wrap_license(Php::Parameters &parameters)
{
	gboolean wrap_license = (gboolean)parameters[0];

	gtk_about_dialog_set_wrap_license (GTK_ABOUT_DIALOG(instance), wrap_license);

}

Php::Value GtkAboutDialog_::get_license_type()
{
	GtkLicense ret = gtk_about_dialog_get_license_type (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_license_type(Php::Parameters &parameters)
{
	int int_license_type = (int)parameters[0];
	GtkLicense license_type = (GtkLicense)int_license_type;

	gtk_about_dialog_set_license_type (GTK_ABOUT_DIALOG(instance), license_type);

}

Php::Value GtkAboutDialog_::get_website()
{
	std::string ret = gtk_about_dialog_get_website (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_website(Php::Parameters &parameters)
{
	std::string s_website = parameters[0];
	gchar *website = (gchar *)s_website.c_str();

	gtk_about_dialog_set_website (GTK_ABOUT_DIALOG(instance), website);

}

Php::Value GtkAboutDialog_::get_website_label()
{
	std::string ret = gtk_about_dialog_get_website_label (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_website_label(Php::Parameters &parameters)
{
	std::string s_website_label = parameters[0];
	gchar *website_label = (gchar *)s_website_label.c_str();

	gtk_about_dialog_set_website_label (GTK_ABOUT_DIALOG(instance), website_label);

}

Php::Value GtkAboutDialog_::get_authors()
{
	const gchar * const * c_ret = gtk_about_dialog_get_authors (GTK_ABOUT_DIALOG(instance));

	return c_ret;
}

void GtkAboutDialog_::set_authors(Php::Parameters &parameters)
{
	std::string s_authors = parameters[0];

	static const gchar* authors[] = { (gchar *)s_authors.c_str(), nullptr };

	gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG(instance), authors);

}

Php::Value GtkAboutDialog_::get_artists()
{
	const gchar * const * c_ret = gtk_about_dialog_get_artists (GTK_ABOUT_DIALOG(instance));

	return c_ret;
}

void GtkAboutDialog_::set_artists(Php::Parameters &parameters)
{
	std::string s_artists = parameters[0];
	
	static const gchar* artists[] = { (gchar *)s_artists.c_str(), nullptr };



	gtk_about_dialog_set_artists (GTK_ABOUT_DIALOG(instance), artists);

}

Php::Value GtkAboutDialog_::get_documenters()
{
	const gchar * const * c_ret = gtk_about_dialog_get_documenters (GTK_ABOUT_DIALOG(instance));

	return c_ret;
}

void GtkAboutDialog_::set_documenters(Php::Parameters &parameters)
{
	std::string s_documenters = parameters[0];

	static const gchar* documenters[] = { (gchar *)s_documenters.c_str(), nullptr };

	gtk_about_dialog_set_documenters (GTK_ABOUT_DIALOG(instance), documenters);

}

Php::Value GtkAboutDialog_::get_translator_credits()
{
	std::string ret = gtk_about_dialog_get_translator_credits (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_translator_credits(Php::Parameters &parameters)
{
	std::string s_translator_credits = parameters[0];
	gchar *translator_credits = (gchar *)s_translator_credits.c_str();

	gtk_about_dialog_set_translator_credits (GTK_ABOUT_DIALOG(instance), translator_credits);

}

Php::Value GtkAboutDialog_::get_logo()
{
	GdkPixbuf *l_pixbuf = gtk_about_dialog_get_logo (GTK_ABOUT_DIALOG(instance));

	// Create the PHP-GTK object and set GTK object
	GdkPixbuf_ *pixbuf_ = new GdkPixbuf_();
	pixbuf_->set_instance(l_pixbuf);
	
	// Return PHP-GTK object
	return Php::Object("GdkPixbuf", pixbuf_);
}

void GtkAboutDialog_::set_logo(Php::Parameters &parameters)
{
	GdkPixbuf *logo;
	if(parameters.size() > 0) {
		Php::Value object_logo = parameters[0];
		GdkPixbuf_ *phpgtk_logo = (GdkPixbuf_ *)object_logo.implementation();
		logo = phpgtk_logo->get_instance();
	}

	gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG(instance), logo);

}

Php::Value GtkAboutDialog_::get_logo_icon_name()
{
	std::string ret = gtk_about_dialog_get_logo_icon_name (GTK_ABOUT_DIALOG(instance));

	return ret;
}

void GtkAboutDialog_::set_logo_icon_name(Php::Parameters &parameters)
{
	std::string s_icon_name = parameters[0];
	gchar *icon_name = (gchar *)s_icon_name.c_str();

	gtk_about_dialog_set_logo_icon_name (GTK_ABOUT_DIALOG(instance), icon_name);

}

void GtkAboutDialog_::add_credit_section(Php::Parameters &parameters)
{
	std::string s_section_name = parameters[0];
	gchar *section_name = (gchar *)s_section_name.c_str();

	std::string s_people = parameters[1];
	static const gchar* people[] = { (gchar *)s_people.c_str(), nullptr };

	gtk_about_dialog_add_credit_section (GTK_ABOUT_DIALOG(instance), section_name, people);

}

void GtkAboutDialog_::gtk_show_about_dialog(Php::Parameters &parameters)
{
	// https://stackoverflow.com/questions/21693960/gtkaboutdialog-icon-not-loading
	
	// std::string s_first_property_name = parameters[0];
	// gchar *first_property_name = (gchar *)s_first_property_name.c_str();


	// gtk_show_about_dialog (GTK_ABOUT_DIALOG(instance), first_property_name, );

	throw Php::Exception("GtkAboutDialog_::gtk_show_about_dialog not implemented");

}

