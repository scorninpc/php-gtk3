
#ifndef _PHPGTK_GTKTEXTTAG_H_
#define _PHPGTK_GTKTEXTTAG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
    #include "../Gdk/GdkEvent.h"
	#include "GtkTextIter.h"

    /**
     * GtkTextTag_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkTextTag.html
     */
    class GtkTextTag_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            GtkTextTag *tag;

            GtkTextTag *get_tag();
            void set_tag(GtkTextTag *passed_tag);

            /**
             *  C++ constructor and destructor
             */
            GtkTextTag_();
            ~GtkTextTag_();

            void __construct(Php::Parameters &parameters);

            Php::Value get_priority();

            void set_priority(Php::Parameters &parameters);

            Php::Value event(Php::Parameters &parameters);

            void tag_changed(Php::Parameters &parameters);
    };

#endif
