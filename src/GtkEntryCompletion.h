
#ifndef _PHPGTK_GTKENTRYCOMPLETION_H_
#define _PHPGTK_GTKENTRYCOMPLETION_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GObject.h"
	#include "GtkEntry.h"
	#include "GtkTreeModel.h"

    /**
     * GtkEntryCompletion_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkEntryCompletion.html
     */
    class GtkEntryCompletion_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkEntryCompletion_();
            ~GtkEntryCompletion_();

            void __construct();

            static Php::Value new_with_area();

            Php::Value get_entry();

            void set_model(Php::Parameters &parameters);

            Php::Value get_model();

            void set_match_func(Php::Parameters &parameters);

            void set_minimum_key_length(Php::Parameters &parameters);

            Php::Value get_minimum_key_length();

            Php::Value compute_prefix(Php::Parameters &parameters);

            void complete();

            Php::Value get_completion_prefix();

            void insert_prefix();

            void insert_action_text(Php::Parameters &parameters);

            void insert_action_markup(Php::Parameters &parameters);

            void delete_action(Php::Parameters &parameters);

            void set_text_column(Php::Parameters &parameters);

            Php::Value get_text_column();

            void set_inline_completion(Php::Parameters &parameters);

            Php::Value get_inline_completion();

            void set_inline_selection(Php::Parameters &parameters);

            Php::Value get_inline_selection();

            void set_popup_completion(Php::Parameters &parameters);

            Php::Value get_popup_completion();

            void set_popup_set_width(Php::Parameters &parameters);

            Php::Value get_popup_set_width();

            void set_popup_single_match(Php::Parameters &parameters);

            Php::Value get_popup_single_match();
    };

#endif
