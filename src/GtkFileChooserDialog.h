
#ifndef _PHPGTK_GTKFILECHOOSERDIALOG_H_
#define _PHPGTK_GTKFILECHOOSERDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"

    /**
     * GtkFileChooserDialog_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkFileChooserDialog.html
     */
    class GtkFileChooserDialog_ : public GtkDialog_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkFileChooserDialog_();
            ~GtkFileChooserDialog_();

            void __construct(Php::Parameters &parameters);
    };

#endif
