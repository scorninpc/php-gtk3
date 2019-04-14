#include <phpcpp.h>
#include <iostream>

#include <gtk/gtk.h>

/**
 *  
 */
class GtkApplication_ : public Php::Base, public GtkApplication
{
	private:
		/**
		 *  The initial value
		 */
		int _value = 0;

	public:
		/**
		 *  C++ constructor and destructor
		 */
		GtkApplication_(const gchar *application_id, GApplicationFlags flags)
		{
			Php::out << "construtor: OK 1" << std::flush;
		}

		/**
		 *  C++ destructor
		 */
		~GtkApplication_() 
		{
			
		}

		/**
		 *  
		 */
		Php::Value new_()
		{ 
			GtkApplication *app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
			
			Php::out << "new: OK 1" << std::flush;

			Php::Value object = app;

			return object;
		}
};