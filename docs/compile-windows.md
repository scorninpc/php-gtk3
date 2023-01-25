# Compile PHP-GTK3 on Windows

Thanks to [subabrain](https://github.com/subabrain) for make this possible ([#24](https://github.com/scorninpc/php-gtk3/issues/24))

## Index

 - [Install and configure MSYS2](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#install-and-configure-msys2)
 - [Install Visual Studio and Redistributables](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#install-visual-studio-and-redistributables)
 - [Prepare sources](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#prepare-sources)
 - [Compile PHP](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#compile-PHP)
 - [Fix PHP-CPP for Visual Studio](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#fix-php-cpp-for-visual-studio)
 - [Setup Visual Studio project](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#setup-visual-studio-project)
 - [Visual Studio general Properties](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#Visual-Studio-general-Properties)
 - [Visual Studio C/C++ Properties](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#Visual-Studio-C/C++-Properties)
 - [Visual Studio Linker Properties](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-windows.md#Visual-Studio-Linker-Properties)
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
- Copy the file `mingw64\lib\glib-2.0\include\glibconfig.h` to the folder `mingw64\include\glib-2.0`
- For 32bit, replace the "mingw64" with "mingw32"

## Install Visual Studio and Redistributables

Install newest Windows Redistributables for [64bit here](https://aka.ms/vs/17/release/vc_redist.x64.exe) and/or for [32bit here](https://aka.ms/vs/17/release/vc_redist.x86.exe) 

Install Visual Studio 2022 from [here](https://visualstudio.microsoft.com/)

## Prepare sources

- Create a directory anywere to do some organization.

- Get PHP sources and binaries of choice from [https://windows.php.net/download](https://windows.php.net/download). E.g.: 7.4.33

Extract both into your working directory.

- Get [PHP-CPP-win](https://github.com/apss-pohl/PHP-CPP-win) source (Original code: [PHP-CPP-win](https://github.com/CopernicaMarketingSoftware/PHP-CPP)).

- Get [PHP-GTK3](https://github.com/scorninpc/php-gtk3) source.

The directory should look similar to :

```sh
:$ php-7.4.33-nts-Win32-vc15-x64
:$ php-7.4.33-src
:$ PHP-CPP-win
:$ php-gtk3
```
## Compile PHP
Following the [PHP-SDK-Binary-Tools] (https://github.com/Microsoft/php-sdk-binary-tools/tree/php-sdk-2.2.0).
Version must follow your intended compilation type.
Once done, copy "config.w32.h" from "php-sdk\phpmaster\vc15\x64\php-src\main" to "php-7.4.33-src\main"

## Fix PHP-CPP for Visual Studio

We have a file named `zend\string.h` in the PHP-CPP folder. So on Windows there is a conflict because the `string.h` is already in the System File, so we have to rename it. I took `strings.h`, so rename `zend\string.h` to `zend\strings.h` with the `s`.

Now you have to make this to correct in the other files of PHP-CPP, just by searching for `#include "string.h"` and replace it with `#include "strings.h"` in all files.

This should be done if you used [PHP-CPP-win](https://github.com/apss-pohl/PHP-CPP-win) source.

## Setup Visual Studio project

Create a new Project in Visual Studio. We will take a `Empty C++ Project` here. You can name it as you decide to.

Add "*.cpp" sources from:

- PHP-CPP-win\zend\
- PHP-CPP-win\common\
- php-gtk3\src\\**\
- php-gtk3\

##  Visual Studio general Properties
Configure project as follows:

- Set the Build Settings (I use "Release" with "X64")

General:
- Windows SDK Version: 10.0.17763.0
- Platform Toolset: Visual Studio 2017 (v141)
- Configuration Type: `dynamic library`

##  Visual Studio C/C++ Properties
- Additional Include Directories:
```
<extracted_folder_of_php_source>\
<extracted_folder_of_php_source>\TSRM
<extracted_folder_of_php_source\Zend
<extracted_folder_of_php_source>\main
<extracted_folder_of_php_cpp>\
<mysys64_location>mingw64\include\libgladeui-2.0
<mysys64_location>mingw64\include\harfbuzz
<mysys64_location>mingw64\include\gtk-3.0
<mysys64_location>mingw64\include\cairo
<mysys64_location>mingw64\include\gtksourceview-3.0
<mysys64_location>mingw64\include\glib-2.0
<mysys64_location>mingw64\include\gdk-pixbuf-3.0
<mysys64_location>mingw64\include\atk-1.0
<mysys64_location>mingw64\include\pango-1.0
```
- Warning Level: Turn Off All Warnings (/W0)
- SDL checks: No (/sdl-)
- Multi-processor Compilation: Yes (/MP)
- Runtime Library: Multi-threaded (/MT)
- C++ Language Standard: ISO C++17 Standard (/std:c++17)
- Preprocessor definitions:

```
_WINDOWS
_WIN32
NDEBUG
ZEND_DEBUG=0
_CRT_SECURE_NO_WARNINGS
PHP_WIN32
ZEND_WIN32
_MSC_VER=1934
PHP_COMPILER_ID="VC15"
_CRT_NONSTDC_NO_DEPRECATE
_NOEXCEPT=noexcept
G_PLATFORM_WIN32
GIO_COMPILATION
BUILDING_PHPCPP
PHP_VERSION_ID=70433 (Following your PHP version of choice)
GDK_PIXBUF_COMPILATION
GDK_COMPILATION
GTK_COMPILATION
GLIB_COMPILATION
If you want to compile in 32bit you must set the definition:
_USE_32BIT_TIME_T
```

##  Visual Studio Linker Properties
- Additional Library Directories:
```
<extracted_folder_of_php_binaries>\dev
<mysys64_location>mingw64\lib
```
- Additional Dependencies:
```
libgtk-3.dll.a
libgobject-2.0.dll.a
libgio-2.0.dll.a
libgdk-3.dll.a
php7.lib
libgdk_pixbuf-2.0.dll.a
libglib-2.0.dll.a
libgladeui-2.dll.a
libgtksourceview-3.0.dll.a
```

## Compile PHP-GTK3
You should now be able to compile PHP-GTK3. Hit "Build/ Build Solution"

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

To fix icons problem, you'll need create a pixbuf cache, running `gdk-pixbuf-query-loaders.exe --update-cache` and copy `c:\msys64\mingw64\lib\gdk-pixbuf-2.0` to `PHP_DIR/lib/`

Rename the `php.ini-development` to `php.ini` and change the following stuff:

```
...
extension_dir = "ext"
...
extension=php-gtk3
...
```

Open the cmd console in Windows, go to your "<extracted_folder_of_php_binaries>\" and now you can run the PHP-GTK3 examples
