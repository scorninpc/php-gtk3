
#ifndef _PHPGTK_GTKTEXTBUFFER_H_
#define _PHPGTK_GTKTEXTBUFFER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkContainer.h"
	#include "GtkTextIter.h"

    /**
     * GtkTextBuffer_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextBuffer.html
     */
    class GtkTextBuffer_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTextBuffer_();
            ~GtkTextBuffer_();

            void __construct();

            Php::Value get_line_count();

            Php::Value get_char_count();

            void insert(Php::Parameters &parameters);
    };

#endif
