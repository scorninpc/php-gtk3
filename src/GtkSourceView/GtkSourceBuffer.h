
#ifndef _PHPGTK_GTKSOURCEBUFFER_H_
#define _PHPGTK_GTKSOURCEBUFFER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>
	#include "../Gtk/GtkTextBuffer.h"
	#include "GtkSourceLanguage.h"
    #include <gtksourceview/gtksource.h>
    
    /**
     * GtkSourceBuffer
     * 
     * https://gnome.pages.gitlab.gnome.org/gtksourceview/gtksourceview5/class.Buffer.html
     */
    class GtkSourceBuffer_ : public GtkTextBuffer_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkSourceBuffer_();
            ~GtkSourceBuffer_();

            void __construct();
            
            static Php::Value new_with_language(Php::Parameters &parameters);
            
            void change_case(Php::Parameters &parameters);

            void set_language(Php::Parameters &parameters);
    };

#endif
