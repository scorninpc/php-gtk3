
# Table of contents

- [How to install PHP-GTK on Windows](#how-to-install-php-gtk-on-windows)
- [How to Build PHP-GTK on Windows](#how-to-build-php-gtk-on-windows)
	- [Preparing Visual Studio](#preparing-visual-studio)
	- [Compiling PHP on Windows](#compiling-php-on-windows)
	- [Preparing PHP, PHP-CPP and PHP-GTK code](#preparing-php-php-cpp-and-php-gtk-code)
	- [Downloading GTK on windows](#downloading-gtk-on-windows)
	- [Creating Visual Studio project](#creating-visual-studio-project)
	- [Running and packing](#running-and-packing)

# How to install PHP-GTK on Windows

1. You will need install [Visual C++ Redistributable](https://aka.ms/vs/17/release/vc_redist.x64.exe);

2. Download the last release for Windows of [PHP-GTK](https://github.com/scorninpc/php-gtk3/releases);

3. Extract it to root, to be like `C:\PHP-GTK\php.exe`;

4. Create your first PHP script on Desktop called `simple.php`;

```php
<?php

Gtk::init();

$window = new \GtkWindow();
$window->show_all();

Gtk::main();
```

5. Open cmd.exe and run your script;

```bash
C:\PHP-GTK\php.exe Desktop\simple.php
```

# How to Build PHP-GTK on Windows

## Preparing Visual Studio;

1. Determining the Visual Studio version

First of all, you need to know what version of Visual Studio do you need. Go to URL https://windows.php.net/downloads/php-sdk/deps/series/ and see what version of PHP are compiled on what version of Visual Studio. For example, you can see that PHP 8.2 can be compiled on VS16 only, because the file called `packages-8.2-vs16-x64-stable.txt`

2. Downloading and installing Visual Studio

For PHP 8.1, all you need is install VS16 too, wich are included on VS 2019. So you can download Visual Studio 2019 from [here](https://visualstudio.microsoft.com/pt-br/thank-you-downloading-visual-studio/?sku=Community&rel=16&src=myvs&utm_medium=microsoft&utm_source=my.visualstudio.com&utm_campaign=download&utm_content=vs+community+2019)

Open the installer, and install Visual Studio Community 2019 and "C++ Desktop Development"

If when you are reading that you cannot install Visual Studio 2019, try to install the current version of "C++ Desktop Development" and after that, click in modify "Visual Studio Community", and on "Individual Componentes" tab, look for "Build Tools MSVC v142 (VS 2019 C++)" and "Windows 10 SDK".

3. Install [Visual C++ Redistributable](https://aka.ms/vs/17/release/vc_redist.x64.exe);

## Compiling PHP on Windows;

1. Download SDK Binary Tools

	SDK Binary Tools is a various scripts that make work easy

	Download binary tools from `https://github.com/php/php-sdk-binary-tools`

2. Create a folder to work with codes

	Create a folder like `C:\php-dev` to extract PHP SDK

3. Prepare environment

	Open `cmd.exe` as admin, and go to `c:\php-dev\php-sdk`

	Run `phpsdk-vs16-x64.bat` to prepare PHP environment

	Build tree source dir running `phpsdk_buildtree phpdev`

	This will create some folders like `C:\php-dev\php-sdk\phpdev\vs16\x64`

4. Preparing the PHP source

	Now download the [PHP source](https://windows.php.net/downloads/releases), if you want to use another versions, go to [archives](https://windows.php.net/downloads/releases/archives/)

	Extract the source code inside de `C:\php-dev\php-sdk\phpdev\vs16\x64`, and rename it to be like `C:\php-dev\php-sdk\phpdev\vs16\x64\php-8.1.14-src`

5. Downloading dependencies

	Back to the `cmd.exe` opend, go to `C:\php-dev\php-sdk\phpdev\vs16\x64\php-8.1.14-src`, and run the command `phpsdk_deps -u` to download dependencies

6. Build and compile PHP from source code

	Inside the source code `C:\php-dev\php-sdk\phpdev\vs16\x64\php-8.1.14-src`, run `buildconf`

	Now you can create the config running `configure --disable-all --enable-cli --enable-$remains --disable-zts`. You may want to run `configure --help` to see options and what you need to enable

	If `ERROR: mc is required` appear, run command `set PATH=%PATH%;C:\Program Files (x86)\Windows Kits\10\bin\10.0.16299.0\x64` to add `mc.exe` to the PATH

	So now you can build with `nmake`

	It will compile PHP on `C:\php-gtk3\php-sdk\phpdev\vs16\x64\php-8.1.14-src\x64\Release`. You can run `x64\Release\php.exe -m` to confirm that is working

## Preparing PHP, PHP-CPP and PHP-GTK code;

1. Preparing PHP-CPP

	This is the poor part of this processes, becase there is alot PR unmerged on this repo. So, what you need is verify this [pull requests](https://github.com/CopernicaMarketingSoftware/PHP-CPP/pulls) looking for changes to work on windows, and do some changes manualy. ex: clone repository, and look for PR to make that work on php 8.1 and look for PR to make this work on windows, and do some changes manualy

	After do the changes, put this code into folder that we are using to store sources, to be like `C:\php-dev\php-cpp`

2. Preparing PHP-GTK

	Get the last source of [php-gtk](https://github.com/scorninpc/php-gtk3), and extract it on the same folder, to be like `C:\php-dev\php-gtk3`

3. Preparing PHP

	Download the [PHP binary](https://windows.php.net/downloads/releases) of the same version of source code, if you want to use another versions, go to [archives](https://windows.php.net/downloads/releases/archives/) to get the binaries. Pay attention to versions with NTS (non-threaed safe) or with out NTS according with your configure options

	Extract it inside our working folder to be like `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64`

## Downloading GTK on windows;

1. Download MSYS2

	Get the last version of [MSYS2](https://www.msys2.org/) and install it

- Downloading libs

2. Open MSYS2 bash and download the libs with commands

	```bash
	$ pacman -S mingw-w64-x86_64-gtk3
	$ pacman -S mingw-w64-x86_64-libglade
	$ pacman -S mingw-w64-x86_64-gtksourceview3
	$ pacman -S mingw-w64-x86_64-glade
	$ pacman -S mingw-w64-x86_64-gdk-pixbuf2
	$ pacman -S mingw-w64-x86_64-glib2
	```

3. Preparing the libs

	Copy the file `C:\msys2\mingw64\lib\glib-2.0\include\glibconfig.h` to the folder `C:\msys2\mingw64\include\glib-2.0`

## Creating Visual Studio project;

1. Creating project

	Open Visual Studio and `Create a new project` of type a `Blank C++ project`. You can add any name and any place to save the project

2. Importing files

	Right click on project name, go to "Add" -> "Existing Item" and add all `.cpp` from PHP-CPP and PHP-GTK projects, or you can drag'n drop from explorer to Visual Studio, on project name. Import files:

	```
	C:\php-dev\php-cpp\zend\*.cpp
	C:\php-dev\php-cpp\common\*.cpp
	C:\php-dev\php-gtk3\src\**\*.cpp
	C:\php-dev\php-gtk3\*.cpp
	```

	You will need to remove the files

	```
	C:\php-dev\php-gtk3\src\Gtk\GtkosxApplication.cpp
	C:\php-dev\php-gtk3\src\libwnck\*.cpp
	```

3. Configure VS project 

	Rigth click on project name, and go to properties

	Configure to `Release` and `x64` platform

	i. Under "General":

	- Configuration Type: as dynamic library (.dll)

	ii. Under "C/C++" -> "General"

	- Additional Include Directories:
	```
	C:\php-gtk3\php-sdk\phpdev\vs16\x64\php-8.1.14-src
	C:\php-gtk3\php-sdk\phpdev\vs16\x64\php-8.1.14-src\TSRM
	C:\php-gtk3\php-sdk\phpdev\vs16\x64\php-8.1.14-src\Zend
	C:\php-gtk3\php-sdk\phpdev\vs16\x64\php-8.1.14-src\main
	C:\php-dev\php-cpp
	C:\msys2\mingw64\include\libgladeui-2.0
	C:\msys2\mingw64\include\harfbuzz
	C:\msys2\mingw64\include\gtk-3.0
	C:\msys2\mingw64\include\cairo
	C:\msys2\mingw64\include\gtksourceview-3.0
	C:\msys2\mingw64\include\glib-2.0
	C:\msys2\mingw64\include\gdk-pixbuf-3.0
	C:\msys2\mingw64\include\atk-1.0
	C:\msys2\mingw64\include\pango-1.0
	```
	- Warning Level: Turn Off All Warnings (/W0)
	- SDL checks: No (/sdl-)
	- Multi-processor Compilation: Yes (/MP)
	- Runtime Library: Multi-threaded (/MT)

	iii. Under "C/C++" -> "Language"

	- C++ Language Standard: ISO C++17 Standard (/std:c++17)
	- C Language Standard: ISO C/17 Standard (/std:c17)

	iv. Under "C/C++" -> "Preprocessor"

	- Preprocessor definitions: 
	```
	_WINDOWS
	_WIN32
	NDEBUG
	ZEND_DEBUG=0
	_CRT_SECURE_NO_WARNINGS
	PHP_WIN32
	ZEND_WIN32
	_MSC_VER=1929  			(look the version of MSC)
	PHP_COMPILER_ID="VS16" 	(look the version of vs code)
	_CRT_NONSTDC_NO_DEPRECATE
	_NOEXCEPT=noexcept
	G_PLATFORM_WIN32
	GIO_COMPILATION
	BUILDING_PHPCPP
	PHP_VERSION_ID=80114 	(Following your PHP version of choice, you can find on C:\php-gtk3\php-sdk\phpdev\vs16\x64\php-8.1.14-src\main\php_version.h)
	GDK_PIXBUF_COMPILATION
	GDK_COMPILATION
	GTK_COMPILATION
	GLIB_COMPILATION
	```

	v. Under "Linker" -> "General"

	- Additional Library Directories:
	```
	C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\dev
	C:\msys2\mingw64\lib
	```

	vi. Under "Linker" -> "Input"

	- Additional Dependencies:
	```
	libgtk-3.dll.a
	libgobject-2.0.dll.a
	libgio-2.0.dll.a
	libgdk-3.dll.a
	php8.lib				(pay attention to the version of lib inside C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\dev)
	libgdk_pixbuf-2.0.dll.a
	libglib-2.0.dll.a
	libgladeui-2.dll.a
	libgtksourceview-3.0.dll.a
	```

4. Build everything

	Now you can compile the solution. Go to `Build` menu and `Build Solution`

## Running and packing;

1. PHP-GTK3 extension

	After build without errors, on project folder will create `Release\php-gtk3.dll` file. Copy this to `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\ext\php_php-gtk3.dll`

	Rename file `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\php.ini-develpment` to `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\php.ini`

	Edit `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\php.ini` adding on end of file `extension=php-gtk3`

2. Dependent libs

	Copy these files from `C:\msys2\mingw64\bin` to the root directory of your ``C:\php-dev\php-8.1.14-nts-Win32-vs16-x64` folder:

	```
	libatk-1.0-0.dll
	libbrotlicommon.dll
	libbrotlidec.dll
	libbrotlienc.dll
	libbz2-1.dll 
	libcairo-2.dll
	libcairo-gobject-2.dll
	libdatrie-1.dll
	libepoxy-0.dll
	libexpat-1.dll
	libffi-8.dll
	libfontconfig-1.dll
	libfreetype-6.dll 
	libfribidi-0.dll
	libgcc_s_seh-1.dll
	libgdk-3-0.dll
	libgdk-win32-2.0-0.dll
	libgdk_pixbuf-2.0-0.dll
	libgio-2.0-0.dll
	libglade-2.0-0.dll
	libgladeui-2-13.dll
	libglib-2.0-0.dll
	libgmodule-2.0-0.dll
	libgmpxx-4.dll
	libgobject-2.0-0.dll
	libgraphite2.dll
	libgthread-2.0-0.dll
	libgtk-3-0.dll
	libgtk-win32-2.0-0.dll
	libgtksourceview-3.0-1.dll
	libharfbuzz-0.dll
	libharfbuzz-gobject-0.dll
	libiconv-2.dll
	libintl-8.dll
	liblzma-5.dll
	libpango-1.0-0.dll
	libpangocairo-1.0-0.dll
	libpangoft2-1.0-0.dll
	libpangowin32-1.0-0.dll
	libpcre2-8-0.dll
	libpixman-1-0.dll
	libpng16-16.dll
	libproxy-1.dll
	librsvg-2-2.dll
	libssl-1_1-x64.dll
	libstdc++-6.dll
	libsystre-0.dll
	libtasn1-6.dll
	libtermcap-0.dll
	libthai-0.dll 
	libunistring-2.dll
	libwinpthread-1.dll
	libxml2-2.dll
	libzstd.dll
	zlib1.dll
	```

3. Fixing GTK icons and themes

	Copy these files from `C:\msys2\mingw64\share` to the root directory of your `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\share` folder

	Open `cmd.exe` and go to folder ``C:\msys2\mingw64\bin`

	Run command `gdk-pixbuf-query-loaders.exe --update-cache` to create a pixbuf cache

	Now copy `C:\msys64\mingw64\lib\gdk-pixbuf-2.0` to `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\lib\`

4. Running 

	Now you are able to run php with gtk extension. Open `cmd.exe` and try `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\php.exe -m`

	Create your first PHP script on Desktop called `simple.php`;

	```
	<?php

	Gtk::init();

	$window = new \GtkWindow();
	$window->show_all();

	Gtk::main();
	```

	And run `C:\php-dev\php-8.1.14-nts-Win32-vs16-x64\php.exe Desktop\simple.php`