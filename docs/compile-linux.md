# Compile PHP-GTK3 on Linux

## Index

 - [Compile PHP from source](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-linux.md#compile-php-from-source)
 - [Compile PHP-CPP from source](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-linux.md#compile-php-cpp-from-source)
 - [Compile PHP-GTK from source](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-linux.md#compile-php-gtk3-from-source)
 - [Make a manual instalation](https://github.com/scorninpc/php-gtk3/blob/master/docs/compile-linux.md#make-a-manual-instalation)

## Compile PHP from source
	
Install dependencies for php and extensions. On deb packages for example:
```sh
:$ sudo apt-get install postgresql-server-dev-11 bison libreadline-dev git build-essential autoconf automake libtool re2c libxml2-dev libcurl4-openssl-dev libssl-dev libbz2-dev  libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev libzip-dev libsqlite3-dev libonig-dev libxslt1-dev
```

Clone php souce
```sh
:$ git clone -b PHP-8.1.14 https://github.com/php/php-src.git PHP-8.1.14
:$ cd PHP-8.1.14
```

Build the config
```sh
:$ ./buildconf --force
```

Configure
```sh
:$ ./configure --prefix=/opt/php/php-8.1.14 --disable-cgi --disable-shared --enable-static --with-pgsql --with-pdo-mysql --with-pdo-pgsql --with-pgsql --with-ffi --with-readline --with-openssl --enable-soap --enable-sockets --with-bz2 --with-zlib --enable-mbstring --with-curl --with-xsl
```

Compile and install
```sh
:$ make -j 4 && sudo make install 
```

## Compile PHP-CPP from source

This will create and install libphpcpp.so.2.3

Clone source
```sh
:$ git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git
:$ cd PHP-GTK
```

Merge PR 497 for PHP 8.1 support
```sh
:$ git fetch origin pull/497/head:MASTER
```

If you compiling on PHP7.4, maybe occur some errors on thoweble.h, so look that [issue](https://github.com/CopernicaMarketingSoftware/PHP-CPP/pull/440/commits/86d3624857a4d6a5ca8f760bb233ed083079e462) appear to be fix it

Edit `PHP-CPP/Makefile` to use `/opt/php/php-8.1.14/bin/php-config`.

`NOTE:` this path can be changed when you compile PHP-SRC.

Compile and install
```sh
:$ make -j 4 && sudo make install
```

## Compile PHP-GTK3 from source

This will create php-gtk3.so php module

Get GTK dependencies, on deb systems, like:
```sh
:$ sudo apt-get install pkg-config libgtk-3-dev libgladeui-dev libgtksourceview-3.0-dev libwnck-dev
```

Clone source
```sh
:$ git clone https://github.com/scorninpc/php-gtk3.git PHP-GTK3
:$ cd PHP-GTK3
```

Edit `PHP-CPP/Makefile` to use `/opt/php/php-8.1.14/bin/php-config`.

`NOTE:` this path can be changed when you compile PHP-SRC.

Compile
```sh
:$ make -j 4 
```

You can test with
```sh
:$ /opt/php/php-8.1.14/bin/php -dextension=./php-gtk3.so examples/test1.php 
```

## Make a manual instalation

Copy module to compiled PHP
```sh
:$ sudo cp php-gtk3.so /opt/php/php-8.1.14/lib/php/extensions/no-debug-non-zts-20210902/php-gtk3.so
```

Create a script that will execute all
```sh
:$ sudo nano /usr/bin/php-gtk3
```

With content
```
#!/bin/bash
/opt/php/phpPHP-8.1.14/bin/php -dextension=php-gtk3.so $@
```

Make it executable
```sh
:$ sudo chmod +x /usr/bin/php-gtk3
```

Done!
```sh
:$ php-gtk3 test1.php
```
