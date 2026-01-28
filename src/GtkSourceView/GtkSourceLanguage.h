
#ifndef _PHPGTK_GTKSOURCELANGUAGE_H_
#define _PHPGTK_GTKSOURCELANGUAGE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
	#include "../G/GObject.h"
    #include <gtksourceview/gtksource.h>
    
    /**
     * GtkSourceLanguage
     * 
     * https://gnome.pages.gitlab.gnome.org/gtksourceview/gtksourceview5/class.Language.html
     */
    class GtkSourceLanguage_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSourceLanguage_();
            ~GtkSourceLanguage_();
    };

#endif
