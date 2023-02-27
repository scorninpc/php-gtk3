
#ifndef _PHPGTK_GTKTREEPATH_H_
#define _PHPGTK_GTKTREEPATH_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
	#include "GtkTreeView.h"
	#include "GtkTreeIter.h"
	#include "GtkTreeModel.h"

    /**
     * GtkTreePathn_
     * 
     * https://docs.gtk.org/gtk3/struct.TreePath.html
     */
    class GtkTreePath_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkTreePath_();
            ~GtkTreePath_();

            Php::Value get_indices();
    };
#endif
