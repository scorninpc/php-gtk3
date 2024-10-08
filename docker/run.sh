#!/bin/bash

# mount the working dir when run with -v

# execute php command
# $ docker run --rm -v ~/Desktop/php-gtk3:/app php-gtk3 php -m
if [ "$1" == "php" ]; then
	shift
	/usr/local/php-gtk3/bin/php -dextension=/app/php-gtk3-source/php-gtk3.so "$@"
fi

# copy compiled php to ~/Desktop/php-gtk3/php-bin
# $ docker run --rm -v ~/Desktop/php-gtk3:/app php-gtk3 php-copy
# give user permission back on host with 
# $ chwon user:user -R ~/Desktop/php-gtk3/usr/local/php-gtk3
if [ "$1" == "php-copy" ]; then
	cp /lib/x86_64-linux-gnu/libgladeui-2.so.13 /app
	mkdir /app/usr/local/php-gtk3 -p
	cp /lib/libphpcpp.so.2.3 /app
	cp /lib/x86_64-linux-gnu/libgtksourceview-3.0.so.1 /app
	cp /usr/local/php-gtk3 "/app/usr/local/" -r
fi

# compile php-gtk3 source. checkout PHP-GTK3 source on ~/Desktop before compile
# $ docker run --rm -v ~/Desktop/php-gtk3:/app php-gtk3 build
# teste with 
# $ docker run --rm -v ~/Desktop/php-gtk3:/app php-gtk3 php -m
if [ "$1" == "build" ]; then
	shift
	cd /app/php-gtk3-source && make clean && make -j "$@"
	
	cp /app/php-gtk3-source/php-gtk3.so $(php-config --extension-dir)/
	echo "extension=php-gtk3.so" >> $(php-config --ini-path)/php.ini
fi

# tests to copy dependencies
if [ "$1" == "ldd" ]; then

	/usr/local/php-gtk3/bin/php -dextension=/app/php-gtk3-source/php-gtk3.so -m

	/app/copy.ldd.sh /usr/local/php-gtk3/bin/php -dextension=/app/php-gtk3-source/php-gtk3.so -m
fi