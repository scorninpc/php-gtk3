
#ifndef _PHPGTK_GTKFILECHOOSERDIALOG_H_
#define _PHPGTK_GTKFILECHOOSERDIALOG_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GtkDialog.h"
    #include "GtkFileFilter.h"
    
	#include "../../php-gtk.h"

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

            void set_action(Php::Parameters &parameters);

            Php::Value get_action();

            void set_local_only(Php::Parameters &parameters);

            Php::Value get_local_only();

            void set_select_multiple(Php::Parameters &parameters);

            Php::Value get_select_multiple();

            void set_show_hidden(Php::Parameters &parameters);

            Php::Value get_show_hidden();

            void set_do_overwrite_confirmation(Php::Parameters &parameters);

            Php::Value get_do_overwrite_confirmation();

            void set_create_folders(Php::Parameters &parameters);

            Php::Value get_create_folders();

            void set_current_name(Php::Parameters &parameters);

            Php::Value get_current_name();

            Php::Value set_filename(Php::Parameters &parameters);

            Php::Value get_filename();

            Php::Value select_filename(Php::Parameters &parameters);

            void unselect_filename(Php::Parameters &parameters);

            void select_all();

            void unselect_all();

            Php::Value get_filenames();

            Php::Value set_current_folder(Php::Parameters &parameters);

            Php::Value get_current_folder();

            Php::Value get_uri();

            Php::Value set_uri(Php::Parameters &parameters);

            Php::Value select_uri(Php::Parameters &parameters);

            void unselect_uri(Php::Parameters &parameters);

            Php::Value get_uris();

            Php::Value set_current_folder_uri(Php::Parameters &parameters);

            Php::Value get_current_folder_uri();

            void set_preview_widget(Php::Parameters &parameters);

            Php::Value get_preview_widget();

            void set_preview_widget_active(Php::Parameters &parameters);

            Php::Value get_preview_widget_active();

            void set_use_preview_label(Php::Parameters &parameters);

            Php::Value get_use_preview_label();

            Php::Value get_preview_uri();

            void set_extra_widget(Php::Parameters &parameters);

            Php::Value get_extra_widget();

            void add_filter(Php::Parameters &parameters);

            void remove_filter(Php::Parameters &parameters);

            Php::Value list_filters();

            void set_filter(Php::Parameters &parameters);

            Php::Value get_filter();
    };

#endif
