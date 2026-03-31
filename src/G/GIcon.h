

#ifndef _PHPGTK_GICON_H_
#define _PHPGTK_GICON_H_

	#include <phpcpp.h>
	#include <gtk/gtk.h>
	#include <gio/gio.h>

	/**
	 * GIcon wrapper class
	 * 
	 * GIcon is an interface for icons in GIO. It provides a way to 
	 * represent icons independently of how they're displayed.
	 */
	class GIcon_ : public Php::Base
	{
		public:
			GIcon *instance;

			/**
			 * C++ constructor and destructor
			 */
			GIcon_();
			~GIcon_();

			/**
			 * Return original GIcon
			 */
			GIcon *get_instance() const;

			/**
			 * Set the original GIcon
			 * 
			 * @param passed_gicon The GIcon to set
			 * @param add_reference If true, adds a reference (default). If false, takes ownership without adding reference.
			 */
			void set_instance(GIcon *passed_gicon, bool add_reference = true);

			/**
			 * PHP Constructor
			 */
			void __construct();

			/**
			 * Create a GIcon from a GdkPixbuf
			 * This is a convenience method for creating image-based icons from pixbufs
			 */
			static Php::Value new_from_pixbuf(Php::Parameters &parameters);

			/**
			 * Create a GIcon from a stock ID
			 * Creates a themed icon that can be used with gtk_status_icon_set_from_gicon
			 */
			static Php::Value new_from_stock(Php::Parameters &parameters);
	};

#endif
