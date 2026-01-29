
#include "GtkSourceLanguageManager.h"

/**
 * Constructor
 */
GtkSourceLanguageManager_::GtkSourceLanguageManager_() = default;

/**
 * Destructor
 */
GtkSourceLanguageManager_::~GtkSourceLanguageManager_() = default;


void GtkSourceLanguageManager_::__construct()
{
	instance = (gpointer *)gtk_source_language_manager_new();
}

Php::Value GtkSourceLanguageManager_::get_language(Php::Parameters &parameters)
{
	std::string param_id = parameters[0];
    gchar* id = (gchar*)param_id.c_str();

	GtkSourceLanguage *ret = gtk_source_language_manager_get_language(GTK_SOURCE_LANGUAGE_MANAGER(instance), id);

	GtkSourceLanguage_ *return_parsed = new GtkSourceLanguage_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkSourceLanguage", return_parsed);
}

Php::Value GtkSourceLanguageManager_::get_default()
{
	GtkSourceLanguageManager *ret = gtk_source_language_manager_get_default();

	GtkSourceLanguageManager_ *return_parsed = new GtkSourceLanguageManager_();
	return_parsed->set_instance((gpointer *)ret);
	return Php::Object("GtkSourceLanguageManager", return_parsed);
}

Php::Value GtkSourceLanguageManager_::get_language_ids()
{
	Php::Value ret_arr;

	const gchar* const* languages = gtk_source_language_manager_get_language_ids(GTK_SOURCE_LANGUAGE_MANAGER(instance));
	for (int i = 0; languages[i] != NULL; i++) {
		ret_arr[i] = languages[i];
	}

	return ret_arr;
}


Php::Value GtkSourceLanguageManager_::get_search_path()
{
	Php::Value ret_arr;

	const gchar* const* paths = gtk_source_language_manager_get_search_path(GTK_SOURCE_LANGUAGE_MANAGER(instance));
	for (int i = 0; paths[i] != NULL; i++) {
		ret_arr[i] = paths[i];
	}

	return ret_arr;
}

void GtkSourceLanguageManager_::set_search_path(Php::Parameters &parameters)
{

	// get the array param
	Php::Value arr = parameters[0];
	gchar *dirs[arr.size() + 1];

	// loop indexes of param
	for(int index=0; index < (int)arr.size(); index++) {

		// convert to gchar and add to dirs
		std::string s = arr[index];
		dirs[index] = g_strdup(s.c_str());
	}

	// finalize last post with null
	dirs[arr.size()] = NULL;

	gtk_source_language_manager_set_search_path(GTK_SOURCE_LANGUAGE_MANAGER(instance), dirs);

	// free pointers
	for (int i = 0; i < arr.size(); i++)
		g_free(dirs[i]);
}

Php::Value GtkSourceLanguageManager_::guess_language(Php::Parameters &parameters)
{
	// inicialize the C params
	gchar* filename = NULL;
	gchar* content_type = NULL;

	// if has filename
	if(parameters.size() > 0 && !parameters[0].isNull()) {
		std::string s_filename = parameters[0];
		filename = (gchar*)s_filename.c_str();
	}

	// if has content_type
	if(parameters.size() > 1 && !parameters[1].isNull()) {
		std::string s_content_type = parameters[1];
		content_type = (gchar*)s_content_type.c_str();
	}

	// do the call
	GtkSourceLanguage *ret = gtk_source_language_manager_guess_language(
		GTK_SOURCE_LANGUAGE_MANAGER(instance),
		filename,
		content_type
	);

	// return null if not find
	if(ret == NULL) {
		return Php::Value();
	}

	// cast the object and return
	GtkSourceLanguage_ *return_parsed = new GtkSourceLanguage_();
	return_parsed->set_instance((gpointer *)ret);

	return Php::Object("GtkSourceLanguage", return_parsed);
}
