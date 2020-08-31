
#ifndef _PHPGTK_GDKVISUAL_H_
#define _PHPGTK_GDKVISUAL_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

	#include "../G/GObject.h"
	// #include "GdkScreen.h"

    /**
     * GdkVisual_
     * 
     * https://developer.gnome.org/gtk3/stable/GdkVisual.html
     */
    class GdkVisual_ : public GObject_
    {
        /**
         * Publics
         */
        public:

            // GdkVisual *instance;

            /**
             *  C++ constructor and destructor
             */
            GdkVisual_();
            ~GdkVisual_();

            // /**
            //  * Set and Get the original GdkVisual
            //  */
            // void set_instance(GdkVisual visual);
            // GdkVisual *get_instance();

            Php::Value get_blue_pixel_details(Php::Parameters &parameters);

            Php::Value get_green_pixel_details(Php::Parameters &parameters);

            Php::Value get_red_pixel_details(Php::Parameters &parameters);

            Php::Value get_depth();

            Php::Value get_visual_type();

            Php::Value get_screen();
    };

#endif
