
#ifndef _PHPGTK_GTKPAPERSIZE_H_
#define _PHPGTK_GTKPAPERSIZE_H_

    #include <phpcpp.h>
    #include <gtk/gtk.h>

    /**
     * GtkPaperSize_
     * 
     * https://developer.gnome.org/gtk3/stable/GtkPaperSize.html
     */
    class GtkPaperSize_ : public Php::Base
    {
        /**
         * Publics
         */
        public:

            GtkPaperSize *instance;
            
            GtkPaperSize *get_instance();
            void set_instance(GtkPaperSize *pased_instance);

            /**
             *  C++ constructor and destructor
             */
            GtkPaperSize_();
            ~GtkPaperSize_();

            void __construct(Php::Parameters &parameters);

            static Php::Value new_from_ppd(Php::Parameters &parameters);

            static Php::Value new_from_ipp(Php::Parameters &parameters);

            static Php::Value new_custom(Php::Parameters &parameters);

            Php::Value copy();

            void free();

            Php::Value is_equal(Php::Parameters &parameters);

            Php::Value get_paper_sizes();

            Php::Value get_name();

            Php::Value get_display_name();

            Php::Value get_ppd_name();

            Php::Value get_width(Php::Parameters &parameters);

            Php::Value get_height(Php::Parameters &parameters);

            Php::Value is_ipp();

            Php::Value is_custom();

            void set_size(Php::Parameters &parameters);

            Php::Value get_default_top_margin(Php::Parameters &parameters);

            Php::Value get_default_bottom_margin(Php::Parameters &parameters);

            Php::Value get_default_left_margin(Php::Parameters &parameters);

            Php::Value get_default_right_margin(Php::Parameters &parameters);

            Php::Value get_default();

            Php::Value new_from_key_file(Php::Parameters &parameters);

            void to_key_file(Php::Parameters &parameters);
    };

#endif
