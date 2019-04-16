php-gtk3-tests
==============

Repositório para alguns testes com bind php-gtk3
Repositoty to do some tests with php-gtk3 bind


Compile
==============
Primeiro de tudo, é necessário copilar o PHP-CPP

:$ phpize
:$ ./configure

On Makefile created, add in the end of CFLAGS: `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0` (fix it on config.m4 ou something)

:$ make

Copy modules/gtk.so to the php library folder
Add extension=gtk.so at the end of file /etc/php5/cli/php.ini (Fix it on make install)
