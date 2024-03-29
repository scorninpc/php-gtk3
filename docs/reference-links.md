compile with:

	yaml

-- Stackoverflow
https://stackoverflow.com/questions/tagged/php-cpp

-- Namespace e otimo tutorial PHP-CPP
https://www.sitepoint.com/php-extension-development-php-cpp-object-oriented-code/

-- Link as static 
https://stackoverflow.com/questions/37875642/how-can-i-compile-program-in-static-library

-- Convert C++ object to PHP ou PHP Object to C++
https://stackoverflow.com/questions/32550304/convert-a-phpobject-back-to-a-c-object-in-php-cpp

-- Tutorial avançado GTK3
https://pt.wikibooks.org/wiki/GTK%2B/Avan%C3%A7ando

-- Metodos magicos
http://www.php-cpp.com/documentation/magic-methods

-- Verificando tipos dos parametros e resources
https://github.com/CopernicaMarketingSoftware/PHP-CPP/issues/346
https://stackoverflow.com/a/50470108/1935882

-- Iterators
https://github.com/CopernicaMarketingSoftware/PHP-CPP/issues/46

-- Outros links e códigos interessantes
http://qaru.site/questions/10714729/convert-a-phpobject-back-to-a-c-object-in-php-cpp

-- Enums value
https://lazka.github.io/pgi-docs/Gtk-3.0/enums.html#Gtk.Orientation

-- GObject reference
https://developer.gnome.org/gobject/stable/gobject-The-Base-Object-Type.html

-- Interfaces
http://www.php-cpp.com/documentation/inheritance

-- Icon nameing spec
https://developer.gnome.org/icon-naming-spec/


-- GTK++ codes
https://source.puri.sm/dorota.czaplejewicz/gtk/commit/8e69f87a4695631b62a74740880e89d30aa10d0f?view=inline&w=1


-- GdkAtom
https://developer.gnome.org/gdk3/stable/gdk3-Properties-and-Atoms.html#gdk-atom-intern
https://github.com/adobe/webkit/blob/master/Source/WebCore/platform/gtk/PasteboardHelper.cpp


-- is_subclass_of
https://github.com/CopernicaMarketingSoftware/PHP-CPP/blob/b50838c0bc5a3eae8b65f7d969172def30fd2ea9/include/call.h

-- Refs

// Exception
throw Php::Exception("GtkMenuShell_::bind_model not implemented");

// Deprecated
Php::deprecated << "GtkColorButton_::get_color is deprecated on Gtk 3.24" << std::endl;

// Cria o retorno
Php::Value arr;
arr[0] = arr["width"] = (int)width;
arr[1] = arr["height"] = (int)height;

// Retorna um objeto
	// Create the PHP-GTK object and set GTK object
	GtkButton_ *widget_ = new GtkButton_();
	widget_->set_instance((gpointer *)widget);
	return Php::Object("GtkButton", widget_);