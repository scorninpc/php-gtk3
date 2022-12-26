# Compile PHP-GTK3 on Windows

Thanks to [subabrain](https://github.com/subabrain) for make this possible ([#24](https://github.com/scorninpc/php-gtk3/issues/24))

## Index

 - [Install and configure MSYS2](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#install-and-configure-msys2)
 - [Install Visual Studio and Redistributables](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#install-visual-studio-and-redistributables)
 - [Prepare sources](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#prepare-sources)
 - [Fix PHP-CPP for Visual Studio](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#fix-php-cpp-for-visual-studio)
 - [Setup Visual Studio project](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#setup-visual-studio-project)
 - [Compile PHP-CPP](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#compile-php-cpp)
 - [GTK Dependencies](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#gtk-dependencies)
 - [Compile PHP-GTK3](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#testing-the-extension)
 - [Testing the extension](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#testing-the-extension)


## Install and configure MSYS2
	
Install newest Version from [here](https://www.msys2.org/)

Prepare MSYS2 for 64bit:
```sh
:$ pacman -S mingw-w64-x86_64-gtk3
:$ pacman -S mingw-w64-x86_64-libglade
:$ pacman -S mingw-w64-x86_64-gtksourceview3
:$ pacman -S mingw-w64-x86_64-glade
:$ pacman -S mingw-w64-x86_64-gdk-pixbuf2
:$ pacman -S mingw-w64-x86_64-glib2
```

Prepare MSYS2 for 32bit:
```sh
:$ pacman -S mingw-w64-i686-gtk3
:$ pacman -S mingw-w64-i686-libglade
:$ pacman -S mingw-w64-i686-gtksourceview3
:$ pacman -S mingw-w64-i686-glade
:$ pacman -S mingw-w64-i686-gdk-pixbuf2
:$ pacman -S mingw-w64-i686-glib2
```

## Install Visual Studio and Redistributables

Install newest Windows Redistributables for [64bit here](https://aka.ms/vs/17/release/vc_redist.x64.exe) and/or for [32bit here](https://aka.ms/vs/17/release/vc_redist.x86.exe) 

Install Visual Studio 2022 from [here](https://visualstudio.microsoft.com/)

## Prepare sources

Create a directory anywere to do some organization

Extract PHP source inside. Here we tested with [PHP 7.3.0](https://github.com/php/php-src/tree/PHP-7.3.0)

Extract PHP-CPP source inside. The code can be downloaded from [here](https://github.com/CopernicaMarketingSoftware/PHP-CPP)

## Fix PHP-CPP for Visual Studio

We have a file named `zend\string.h` in the PHP-CPP folder. So on Windows there is a conflict because the `string.h` is already in the System File, so we have to rename it. I took `strings.h`, so rename `zend\string.h` to `zend\strings.h` with the `s`.

Now you have to make this to correct in the other files of PHP-CPP, just by searching for `#include "string.h"` and replace it with `#include "strings.h"` in all files.

## Setup Visual Studio project

Create a new Project in Visual Studio. We will take a `Empty C++ Project` here. You can name it as you decide to.

Set the Build Settings (I use "Release" with "X64")

Set the Preprocessor definitions to:

```
_WINDOWS
_WIN32
NDEBUG
ZEND_DEBUG=0
_CRT_SECURE_NO_WARNINGS
ZEND_WIN32_KEEP_INLINE
PHP_WIN32
ZEND_WIN32
_MSC_VER=1934
PHP_COMPILER_ID="VC15"
_CRT_NONSTDC_NO_DEPRECATE
_NOEXCEPT=noexcept
G_PLATFORM_WIN32
GIO_COMPILATION
BUILDING_PHPCPP
PHP_VERSION_ID=70300
INTERNAL_FUNCTION_PARAMETERS
```

If you want to compile in 32bit you must set the definition:

```
_USE_32BIT_TIME_T
```

Add the include paths to:

```
<extracted_folder_of_php_source>\
<extracted_folder_of_php_source>\TSRM
<extracted_folder_of_php_source\Zend
<extracted_folder_of_php_source>\main
<extracted_folder_of_php_cpp>\
```

And set the libraries path to:

```
<extracted_folder_of_php_binaries>\dev
```

And the library to:

```
php7.lib
```

Set the buildtype to `dynamic library`

Set the C++ Lanaguage Version to `c++17`

Set the C Language Version to `c17`

Set the Runtime Library to `Multithreaded`

## Compile PHP-CPP

Now you can compile PHP-CPP, but you might get some syntax errors, so you can fix that, or you can see the PHP-CPP repository to get some PR, but it's easy to fix

## GTK Dependencies

Now we just have to set the linker libraries to get it run.

Add the additional dependencies as follows (add them to the `php7.lib`):

```
libgtk-3.dll.a
libgobject-2.0.dll.a
libgio-2.0.dll.a
libgdk-3.dll.a
libgdk_pixbuf-2.0.dll.a
libglib-2.0.dll.a
libgladeui-2.dll.a
libgtksourceview-3.0.dll.a
```

And add additional dependencies paths to (to the "dev folder" that already exists):

```
<folder_of_msys2>\mingw64\lib
```

And now add the following paths to the include paths of your Project (add them to the existing ones):

```
<extracted_folder_of_phpcpp>\
<extracted_folder_of_php_source>\ 
<extracted_folder_of_php_source>\TSRM
<extracted_folder_of_php_source>\Zend
<extracted_folder_of_php_source>\main
<folder_of_msys2>\mingw64\include\libgladeui-2.0
<folder_of_msys2>\mingw64\include\harfbuzz
<folder_of_msys2>\mingw64\include\gtk-3.0
<folder_of_msys2>\mingw64\include\cairo
<folder_of_msys2>\mingw64\include\gtksourceview-3.0
<folder_of_msys2>\mingw64\include\glib-2.0
<folder_of_msys2>\mingw64\include\gdk-pixbuf-2.0
<folder_of_msys2>\mingw64\include\atk-1.0
<folder_of_msys2>\mingw64\include\pango-1.0
```

For 32bit, replace the "mingw64" with "mingw32"

## Compile PHP-GTK3

With PHP-CPP compiled, now you can compile PHP-GTK3

You need to add .cpp files to Visual Studio

Add .cpp files from `src\G` `src\Gdk` `src\Glade` `src\Gtk` `src\GtkSourceView` `php-gtk.cpp` and `main.cpp` to your source code folder of Visual Studio using `Add Existing Files`

Now, if all is correct, it should compile without errors!

## Testing the extension

Copy these files from `<folder_of_msys2>\mingw64\bin` to the root directory of your `<extracted_folder_of_php_binaries>\` folder:

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

I don’t know, maybe there are some redundancies but this should work for the moment. And then of course, we add our .dll from the compilation into the `ext` folder of our `<extracted_folder_of_php_binaries>\` folder.

Rename the `php.ini-development` to `php.ini` and change the following stuff:

```
...
extension_dir = "ext"
...
extension=php-gtk3
...
```

Open the cmd console in Windows, go to your "<extracted_folder_of_php_binaries>\" and now you can run the PHP-GTK3 examples
