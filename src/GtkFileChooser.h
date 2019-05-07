
#ifndef _PHPGTK_GTKFILECHOOSER_H_
#define _PHPGTK_GTKFILECHOOSER_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GObject.h"

    /**
     * GtkFileChooser_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFileChooser.html
     */
    class GtkFileChooser_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFileChooser_();
            ~GtkFileChooser_();

            Php::Value get_filename();
    };

#endif
