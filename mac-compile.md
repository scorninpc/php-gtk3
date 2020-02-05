# Compilar o PHP

$ brew install bison@3.5

$ brew install autoconf automake libtool re2c bison flex git

$ git clone -b PHP-7.4 https://github.com/php/php-src.git php7.4

$ ./buildconf

$ ./configure --disable-all --enable-cli --prefix=/opt/php

$ sudo make install








# Compilar PHP-CPP

$ git clone https://github.com/scorninpc/PHP-CPP php-cpp

# Change php-config on Makefile to /opt/php/bin/php-config

$ make 

$ sudo make install






# Compilar Gtk 

$ brew install gtk+3 gtksourceview3 libglade pkg-config





# Compilar PHP-GTK3

$ git clone https://github.com/scorninpc/php-gtk3.git

# Change php-config on Makefile

	#include "../Gtk/GtkWidget.h"
# THe Cellar still including gtk2 o cflags. So you need to run `pkg-config --cflags gtk+-3.0 gladeui-2.0 gtksourceview-3.0` and replace on Makefile

$ make
