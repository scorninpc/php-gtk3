# PHP

## Install PHP from souce
	
### dependencies for php and extensions
sudo apt-get install postgresql-server-dev-11 bison libreadline-dev git build-essential autoconf automake libtool re2c libxml2-dev libcurl4-openssl-dev libssl-dev libbz2-dev  libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev libzip-dev libsqlite3-dev libonig-dev libxslt1-dev

### clone souce
git clone -b PHP-8.1.14 https://github.com/php/php-src.git PHP-8.1.14
cd PHP-8.1.14

### build
./buildconf --force

### configure
./configure --prefix=/opt/php/php-8.1.14 --disable-cgi --disable-shared --enable-static --with-pgsql --with-pdo-mysql --with-pdo-pgsql --with-pgsql --with-ffi --with-readline --with-openssl --enable-soap --enable-sockets --with-bz2 --with-zlib --enable-mbstring --with-curl --with-xsl

### compile and install
make -j 4 && sudo make install 


# PHP-CPP

## Create libphpcpp.so.2.3

### clone source
git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git
cd PHP-GTK

### merge PR 497 for PHP 8.1 support
git fetch origin pull/497/head:MASTER

edit PHP-CPP/Makefile to use /opt/php/php-8.1.14/bin/php-config

### compile and install
make -j 4 && sudo make install

# PHP-GTK3

## Create php-gtk3.so php module

### get gtk dependencies	
sudo apt-get install pkg-config libgtk-3-dev libgladeui-dev libgtksourceview-3.0-dev libwnck-dev

### clone source
git clone https://github.com/scorninpc/php-gtk3.git PHP-GTK3
cd PHP-GTK3
	
edit PHP-GTK3/Makefile to use /opt/php/php-8.1.14/bin/php-config

### compile
make -j 4 

### test
/opt/php/php-8.1.14/bin/php -dextension=./php-gtk3.so test1.php 

# Make a script to run easily

## copy module to PHP
sudo cp php-gtk3.so /opt/php/php-8.1.14/lib/php/extensions/no-debug-non-zts-20210902/php-gtk3.so

## create a script

`sudo nano /usr/bin/php-gtk3`

with content

```
#!/bin/bash
/opt/php/phpPHP-8.1.14/bin/php -dextension=php-gtk3.so $@
```

make it executable
`sudo chmod +x /usr/bin/php-gtk3`

done

`php-gtk3 test1.php`

# Create AppImage (just for my reference)

add libs to PHP in ./lib

- PHP
	libldap_r-2.4.so.2
	liblber-2.4.so.2
	libonig.so.5
	libffi.so.7
	libcrypto.so.1.1
	libssl.so.1.1

- PHP-GTK
	libphpcpp.so.2.3

`appimagetool-x86_64.AppImage php-gtk3.AppDir`