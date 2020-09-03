# Params:
#
# WITH_MAC_INTEGRATION=1 
#	create a mac integration with lib gtk-mac-integration-gtk3
#
# WITH_LIBWNCK=1
#	create a libwnck bind
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
INI_DIR     =   /etc/php/7.3/mods-available/

#
#   The extension dirs
#
#   This is normally a directory like /usr/lib/php5/20121221 (based on the 
#   PHP version that you use. We make use of the command line 'php-config' 
#   instruction to find out what the extension directory is, you can override
#   this with a different fixed directory
#

EXTENSION_DIR       =   $(shell php-config --extension-dir)

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
# With gtk3 mac integration
#

ifdef WITH_MAC_INTEGRATION
	MAC_INTEGRATIONFLAGS = gtk-mac-integration-gtk3
	MAC_INTEGRATIONLIBS = gtk-mac-integration-gtk3

	COMPILER_FLAGS += -DWITH_MAC_INTEGRATION
endif


#
# All flags
#

GTKFLAGS            =   `pkg-config --cflags gtk+-3.0 gladeui-2.0 gtksourceview-3.0 ${MAC_INTEGRATIONFLAGS} ${LIBWNCKFLAGS}`
GTKLIBS             =   `pkg-config --libs gtk+-3.0 gladeui-2.0 gtksourceview-3.0 ${MAC_INTEGRATIONLIBS} ${LIBWNCKLIBS}`

COMPILER_FLAGS      +=   -Wall -Wno-inconsistent-missing-override -c -std=c++11 -fpic -o 
LINKER_FLAGS        =   -shared ${GTKLIBS}
LINKER_DEPENDENCIES =   -lphpcpp

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

ifdef WITH_MAC_INTEGRATION
	SOURCES = $(wildcard *.cpp src/G/*.cpp src/Gdk/*.cpp src/Gtk/*.cpp src/Glade/*.cpp src/GtkSourceView/*.cpp src/libwnck/*.cpp)
else
	SOURCES = $(filter-out src/Gtk/GtkosxApplication.cpp, $(wildcard *.cpp src/*.cpp src/libwnck/*.cpp src/G/*.cpp src/Gdk/*.cpp src/Gtk/*.cpp src/Glade/*.cpp src/GtkSourceView/*.cpp))
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
						${RM} ${EXTENSION} ${OBJECTS}