# Params:
#
# WITH_MAC_INTEGRATION=1
#	create a mac integration with lib gtk-mac-integration-gtk3
#
# WITH_LIBWNCK=1
#	create a libwnck bind
#
# WITH_GLADEUI=1
#	create a gladeui bind to use glade widgets
#
# WITH_WEBKIT=1
#	create a WebView bind for web browsing in GTK widgets
#	- Linux/macOS: Uses WebKit2GTK
#	- Windows: Uses Microsoft Edge WebView2
#
# WEBVIEW2_SDK=C:/path/to/sdk (Windows only)
#	specify custom WebView2 SDK location (default: C:/WebView2SDK)
#

#
#   Makefile template
#
#   This is an example Makefile that can be used by anyone who is building
#   his or her own PHP extensions using the PHP-CPP library.
#
#   In the top part of this file we have included variables that can be
#   altered to fit your configuration, near the bottom the instructions and
#   dependencies for the compiler are defined. The deeper you get into this
#   file, the less likely it is that you will have to change anything in it.
#

#
#   Name of your extension
#
#   This is the name of your extension. Based on this extension name, the
#   name of the library file (name.so) and the name of the config file (name.ini)
#   are automatically generated
#


NAME                =   php-gtk3

#
#   Php.ini directories
#
#   In the past, PHP used a single php.ini configuration file. Today, most
#   PHP installations use a conf.d directory that holds a set of config files,
#   one for each extension. Use this variable to specify this directory.
#
#   In Ubuntu 14.04 Apache 2.4 is used, which uses the mods-available directory
#   instead of a conf.d directory. In 16.04 the directory changed yet again.
#   This has to be checked.
#
INI_DIR     =   /opt/php/php-8.2.22/mods-available/

#
#   The extension dirs
#
#   This is normally a directory like /usr/lib/php5/20121221 (based on the
#   PHP version that you use. We make use of the command line '/opt/php/php7.4.29/bin/php-config'
#   instruction to find out what the extension directory is, you can override
#   this with a different fixed directory
#

EXTENSION_DIR       =   $(shell /opt/php/php-8.2.22/bin/php-config --extension-dir)

#
#   The name of the extension and the name of the .ini file
#
#   These two variables are based on the name of the extension. We simply add
#   a certain extension to them (.so or .ini)
#

EXTENSION           =   ${NAME}.so
INI                 =   ${NAME}.ini

#
#   Compiler
#
#   By default, the GNU C++ compiler is used. If you want to use a different
#   compiler, you can change that here. You can change this for both the
#   compiler (the program that turns the c++ files into object files) and for
#   the linker (the program that links all object files into the single .so
#   library file. By default, g++ (the GNU C++ compiler) is used for both.
#

COMPILER            =   g++
LINKER              =   g++


#
# With libwnck
#

ifdef WITH_LIBWNCK
	LIBWNCKFLAGS = libwnck-3.0
	LIBWNCKLIBS = libwnck-3.0
	LIBWNCKPATH = $(wildcard src/libwnck/*.cpp)

	COMPILER_FLAGS += -DWITH_LIBWNCK -DWNCK_I_KNOW_THIS_IS_UNSTABLE
endif

#
# With WebKit2GTK / WebView2
#
# On Unix/Linux/macOS: Uses WebKit2GTK (pkg-config)
# On Windows: Uses Microsoft Edge WebView2 SDK
#

ifdef WITH_WEBKIT
	# Detect platform
	ifeq ($(OS),Windows_NT)
		# Windows: Use WebView2 (no pkg-config needed)
		WEBKITPATH = $(wildcard src/WebKit/*.cpp)
		
		# WebView2 SDK paths (can be overridden via environment variables)
		WEBVIEW2_SDK ?= C:/WebView2SDK
		WEBVIEW2_INCLUDE ?= $(WEBVIEW2_SDK)/build/native/include
		WEBVIEW2_LIB ?= $(WEBVIEW2_SDK)/build/native/x64
		
		# Add WebView2 include and library paths
		COMPILER_FLAGS += -DWITH_WEBKIT -I$(WEBVIEW2_INCLUDE)
		WEBVIEW2_LDFLAGS = -L$(WEBVIEW2_LIB) -lWebView2LoaderStatic
	else
		# Unix/Linux/macOS: Use WebKit2GTK
		WEBKITFLAGS = webkit2gtk-4.1
		WEBKITLIBS = webkit2gtk-4.1
		WEBKITPATH = $(wildcard src/WebKit/*.cpp)
		
		COMPILER_FLAGS += -DWITH_WEBKIT
		WEBVIEW2_LDFLAGS =
	endif
endif

#
# With gtk3 mac integration
#

ifdef WITH_MAC_INTEGRATION
	MAC_INTEGRATIONFLAGS = gtk-mac-integration-gtk3
	MAC_INTEGRATIONLIBS = gtk-mac-integration-gtk3
	MAC_INTEGRATIONPATH = $(wildcard src/libwnck/*.cpp)

	COMPILER_FLAGS += -DWITH_MAC_INTEGRATION
endif

# 
# With gladeui integration
# 
ifdef WITH_GLADEUI

	GLADEUIFLAGS = gladeui-2.0
	GLADEUILIBS = gladeui-2.0

	COMPILER_FLAGS += -DWITH_GLADEUI

endif

#
# All flags
#

GTKFLAGS            =   `pkg-config --cflags gtk+-3.0 ${GLADEUIFLAGS} gtksourceview-3.0 ${MAC_INTEGRATIONFLAGS} ${LIBWNCKFLAGS} ${WEBKITFLAGS}`
GTKLIBS             =   `pkg-config --libs gtk+-3.0 ${GLADEUILIBS} gtksourceview-3.0 ${MAC_INTEGRATIONLIBS} ${LIBWNCKLIBS} ${WEBKITLIBS}`

COMPILER_FLAGS      +=   -Wall -Wdeprecated-declarations -Woverloaded-virtual -c -std=c++11 -fpic -o
LINKER_FLAGS        =   -shared ${GTKLIBS}
LINKER_DEPENDENCIES =   -lphpcpp ${GTKLIBS} ${WEBVIEW2_LDFLAGS}

#
#   Command to remove files, copy files and create directories.
#
#   I've never encountered a *nix environment in which these commands do not work.
#   So you can probably leave this as it is
#

RM                  =   rm -f
CP                  =   cp -f
MKDIR               =   mkdir -p

#
#   All source files are simply all *.cpp files found in the current directory
#
#   A built-in Makefile macro is used to scan the current directory and find
#   all source files. The object files are all compiled versions of the source
#   file, with the .cpp extension being replaced by .o.
#

# Core source directories (always included)
CORE_SOURCES = *.cpp src/G/*.cpp src/Gdk/*.cpp src/Gtk/*.cpp src/Glade/*.cpp \
               src/GtkSourceView/*.cpp src/Pango/*.cpp src/libwnck/*.cpp

# Conditionally add WebKit sources
ifdef WITH_WEBKIT
	CORE_SOURCES := $(CORE_SOURCES) src/WebKit/*.cpp
endif

# Build final source list
# Exclude platform-specific implementation files that are included directly in WebKitWebView.cpp
PLATFORM_SPECIFIC_IMPLS = src/WebKit/WebKitWebView_Unix.cpp src/WebKit/WebKitWebView_Windows.cpp

ifdef WITH_MAC_INTEGRATION
	SOURCES = $(filter-out $(PLATFORM_SPECIFIC_IMPLS), $(wildcard $(CORE_SOURCES)))
else
	SOURCES = $(filter-out src/Gtk/GtkosxApplication.cpp $(PLATFORM_SPECIFIC_IMPLS), $(wildcard src/*.cpp $(CORE_SOURCES)))
endif

OBJECTS         = $(SOURCES:%.cpp=%.o)


#
#   From here the build instructions start
#

all:                    ${OBJECTS} ${EXTENSION}

${EXTENSION}:           ${OBJECTS}
						${LINKER} ${LINKER_FLAGS} -o $@ ${OBJECTS} ${LINKER_DEPENDENCIES}

${OBJECTS}:
						${COMPILER} ${GTKFLAGS} ${COMPILER_FLAGS} $@ ${@:%.o=%.cpp}

install:
						${CP} ${EXTENSION} ${EXTENSION_DIR}
						${CP} ${INI} ${INI_DIR}

clean:
						${RM} ${EXTENSION}
						find . -name "*.o" -type f -exec ${RM} {} +

						${RM} ${EXTENSION}
						${RM} ${OBJECTS}
						${RM} src/WebKit/*.o