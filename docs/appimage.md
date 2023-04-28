# AppImage of PHP-GTK3

## Index

 - [Download](https://github.com/scorninpc/php-gtk3/blob/master/docs/appimage.md#download)
 - [Tested on](https://github.com/scorninpc/php-gtk3/blob/master/docs/appimage.md#tested-on)
 - [Create AppImage](https://github.com/scorninpc/php-gtk3/blob/master/docs/appimage.md#create-appimage)

## Download

You can find all PHP + GTK extension in AppImage package on [releases](https://github.com/scorninpc/php-gtk3/releases) page

Just download the last release, make it executable and run your PHP scripts

```sh
:$ chmod +x php-gtk3-x86_64-0.14-beta.AppImage
:$ sudo ln -s ~/Downloads/php-gtk3-x86_64-0.14-beta.AppImage /usr/bin/php-gtk
:$ php-gtk myapp.php
```

## Tested on

_Please, let we know if this appimage run fine on your system openning a [issue](https://github.com/scorninpc/php-gtk3/issues)._



AppImage 0.14

- [x] Deepin Linux 20
- [x] Debian 11
- [x] Ubuntu 22.04

AppImage 0.13

- [x] Deepin Linux 20
- [x] Debian 11

AppImage 0.12

- [x] Deepin Linux 20
- [x] Debian 11

AppImage 0.11

- [x] Debian 10
- [x] Debian 11
- [x] Ubuntu 22.04
- [x] Ubuntu 21.10


## Create AppImage

_This is for my reference only._

add libs to PHP in ./lib

- PHP
```
libldap_r-2.4.so.2
liblber-2.4.so.2
libonig.so.5
libffi.so.7
libcrypto.so.1.1
libssl.so.1.1
```

- PHP-GTK
```
libphpcpp.so.2.3
```

`appimagetool-x86_64.AppImage php-gtk3.AppDir`


- References to test

download:

> wget -c "https://raw.githubusercontent.com/linuxdeploy/linuxdeploy-plugin-gtk/master/linuxdeploy-plugin-gtk.sh"
> wget -c "https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage"
> chmod +x linuxdeploy-x86_64.AppImage linuxdeploy-plugin-gtk.sh

```
DEPLOY_GTK_VERSION=3 ./linuxdeploy-x86_64.AppImage  \
	--appdir AppDir \
	--plugin gtk \
	--library /usr/lib/x86_64-linux-gnu/libreadline.so.7 \
	--library /usr/lib/x86_64-linux-gnu/libonig.so.5 \
	--library /usr/lib/x86_64-linux-gnu/libncurses.so.6 \
	--library /usr/lib/x86_64-linux-gnu/libgladeui-2.so.6 \
	--library /usr/lib/libphpcpp.so.2.3
```
