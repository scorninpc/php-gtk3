
#ifndef _PHPGTK_GTKTEXTTAGTABLE_H_
#define _PHPGTK_GTKTEXTTAGTABLE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
	#include "GtkTextTag.h"

    /**
     * GtkTextTagTable_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextTagTable.html
     */
    class GtkTextTagTable_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTextTagTable_();
            ~GtkTextTagTable_();

            void __construct();

            Php::Value add(Php::Parameters &parameters);

            void remove(Php::Parameters &parameters);

            Php::Value lookup(Php::Parameters &parameters);

            Php::Value foreach(Php::Parameters &parameters);

            Php::Value get_size();
    };

#endif
