
#ifndef _PHPGTK_GTKCLIPBOARD_H_
#define _PHPGTK_GTKCLIPBOARD_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "GObject.h"
	#include "GdkSelection.h"
	#include "GdkPixbuf.h"
	#include "GtkTextBuffer.h"

    /**
     * GtkClipboard_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkClipboard.html
     */
    class GtkClipboard_ : public GObject_
    {
       /**
         * Privates
         */
        private:
            struct st_request_callback;

        /**
         * Publics
         */
        public:

            /**
             *  C++ constructor and destructor
             */
            GtkClipboard_();
            ~GtkClipboard_();

            static void request_text_callback(GtkClipboard *clipboard, const gchar *user_text, gpointer user_data);

            void __construct(Php::Parameters &parameters);

            Php::Value get_for_display(Php::Parameters &parameters);

            Php::Value get_display();

            Php::Value set_with_data(Php::Parameters &parameters);

            Php::Value set_with_owner(Php::Parameters &parameters);

            Php::Value get_owner();

            void clear();

            void set_text(Php::Parameters &parameters);

            void set_image(Php::Parameters &parameters);

            void request_contents(Php::Parameters &parameters);

            void request_text(Php::Parameters &parameters);

            void request_image(Php::Parameters &parameters);

            void request_targets(Php::Parameters &parameters);

            void request_rich_text(Php::Parameters &parameters);

            void request_uris(Php::Parameters &parameters);

            Php::Value wait_for_contents(Php::Parameters &parameters);

            Php::Value wait_for_text();

            Php::Value wait_for_image();

            Php::Value wait_for_rich_text(Php::Parameters &parameters);

            Php::Value wait_for_uris();

            Php::Value wait_is_text_available();

            Php::Value wait_is_image_available(Php::Parameters &parameters);

            Php::Value wait_is_uris_available();

            Php::Value wait_is_target_available(Php::Parameters &parameters);

            void set_can_store();

            Php::Value get_selection();
    };

#endif
