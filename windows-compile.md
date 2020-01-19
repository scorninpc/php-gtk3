# NOT WORKING YET

-- Some references
[1] - https://wiki.php.net/internals/windows/stepbystepbuild_sdk_2
[2] - https://jojokahanding.wordpress.com/2014/05/26/writing-php-extensions-for-windowsbuilding-a-compile-environment/
[3] - https://blog.benoitblanchon.fr/build-php-extension-on-windows/

-- php-cpp
[FAILED: PHP-CPP TRY 2]

Download msys2
Download php source
	- Run ./buildconfig
	- Run ./configure --disable-all --enable-cli
Download phpcpp source
Apply phpcpp 7.4 path
Make changes of Makefile
	- Error main/config.w32.h no such file or directory
		[2][Solve: copy php-src\win32\build\config.w32.h.in to php-src\main\config.w32.h]
	- Error php_config.h no such file or directory 
		[Solve: copy php-src\main\php_config.h.in to php-src\main\php_config.h]


-- Root php ext
configure php-sdk
configure php-src
build php
	.\buildconfig
	.\configure --disable-all --enable-cli --enable-gtk3
	nmake
set include of GTK
	set CL=/IC:\vcpkg\installed\x64-windows\include

