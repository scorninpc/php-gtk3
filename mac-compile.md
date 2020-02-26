# Compilar o PHP

$ brew install bison@3.5

$ echo 'export PATH="/usr/local/opt/bison/bin:$PATH"' >> ~/.zshrc

$ export PATH="/usr/local/opt/bison/bin:$PATH"

$ brew install autoconf automake libtool re2c bison flex git

$ git clone -b PHP-7.4 https://github.com/php/php-src.git php7.4

$ ./buildconf --force

$ ./configure --disable-all --enable-cli --prefix=/opt/php7.4

$ make

$ sudo make install








# Compilar PHP-CPP

$ git clone https://github.com/scorninpc/PHP-CPP php-cpp

# Change php-config on Makefile to /opt/php/bin/php-config

$ make 

$ sudo make install






# Compilar Gtk 

$ brew install gtk+3 gtksourceview3 gtk-mac-integration libglade pkg-config





# Compilar PHP-GTK3

$ git clone https://github.com/scorninpc/php-gtk3.git

# Change php-config on Makefile to /opt/php/bin/php-config

# The Cellar still including gtk2 on cflags as dependency of libglade. So you need to remove glade from main.h and main.cpp; Remove libglade from GTKFLAGS and GTKLIBS from Makefile; And remove Glade src from SOURCES of Makefile

$ make

