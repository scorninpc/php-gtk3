
#ifndef _PHPGTK_GTKSOURCELANGUAGEMANAGER_H_
#define _PHPGTK_GTKSOURCELANGUAGEMANAGER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
	#include "../G/GObject.h"
	#include "GtkSourceLanguage.h"
    #include <gtksourceview/gtksource.h>
    /**
     * GtkSourceLanguageManager
     * 
     * https://gnome.pages.gitlab.gnome.org/gtksourceview/gtksourceview5/class.LanguageManager.html
     */
    class GtkSourceLanguageManager_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSourceLanguageManager_();
            ~GtkSourceLanguageManager_();

            void __construct();

			static Php::Value get_default();

			void set_search_path(Php::Parameters &parameters);

			Php::Value get_search_path();

			Php::Value get_language_ids();

			Php::Value get_language(Php::Parameters &parameters);

			// Php::Value guess_language(Php::Parameters &parameters);
    };

#endif
