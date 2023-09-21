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


AppImage 0.16

- [x] Deepin Linux 20.9
- [x] Debian 11.6 (stable)
- [x] Debian 12.0 (sid)
- [x] Ubuntu 22.04

AppImage 0.15

- [x] Deepin Linux 20
- [x] Debian 11
- [x] Ubuntu 22.04

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


## Create AppImage (old one)

_This is for my reference only._

- Compile PHP to the prefix `/usr/local/php-gtk3`
- Create dir like `AppDir` and copy this to same path  like `AppDir/usr/local/php-gtk3`
- Create lib dir like `AppDir/lib`
- Find the dependency libs with

`ldd usr/local/php-gtk3/bin/php`
or
`LD_DEBUG=libs usr/local/php-gtk3/bin/php`

- Add this libs to in `./usr/lib/` with

```
cp `readlink -f /usr/lib/x86_64-linux-gnu/librt.so.1` usr/lib/librt.so.1
```

- Create AppImage with

`appimagetool-x86_64.AppImage php-gtk3.AppDir`

- References to test with linuxdeploy and gtk plugin

download:

> wget -c "https://raw.githubusercontent.com/linuxdeploy/linuxdeploy-plugin-gtk/master/linuxdeploy-plugin-gtk.sh"
> wget -c "https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage"
> chmod +x linuxdeploy-x86_64.AppImage linuxdeploy-plugin-gtk.sh

```
DEPLOY_GTK_VERSION=3 ./linuxdeploy-x86_64.AppImage \
	--appdir AppDir \
	--plugin gtk \
	--library /usr/lib/x86_64-linux-gnu/libreadline.so.8 \
	--library /usr/lib/x86_64-linux-gnu/libonig.so.5 \
	--library /usr/lib/x86_64-linux-gnu/libncurses.so.6 \
	--library /usr/lib/x86_64-linux-gnu/libgladeui-2.so \
	--library /usr/lib/x86_64-linux-gnu/gvfs/libgvfscommon.so \
	--library /usr/lib/libphpcpp.so.2.3 \
	--desktop-file=AppDir/php-gtk3.desktop \
	--icon-file=AppDir/php-gtk3.png

```


## Create AppImage

_This is for my reference only._

prepare:

- Compile PHP to the prefix `/usr/local/php-gtk3`
- If updating only, verify requerid libs of `php-gtk3.so` and `php` compiled. For exemplo, `php` can be compiled with `libreadline7` and new `php-gtk3.so` with `libreadline8`
- Create dir like `AppDir` and copy this to same path  like `AppDir/usr/local/php-gtk3`
- Copy default `AppRun`, `php-gtk3.desktop`, `php-gtk3.png` and `php-gtk3.png.png`. This last, are because deploy need a .png and tool need without .png

download:

> wget -c "https://raw.githubusercontent.com/linuxdeploy/linuxdeploy-plugin-gtk/master/linuxdeploy-plugin-gtk.sh"
> wget -c "https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage"
> chmod +x linuxdeploy-x86_64.AppImage linuxdeploy-plugin-gtk.sh


run: 

```
DEPLOY_GTK_VERSION=3 ./linuxdeploy-x86_64.AppImage \
	--appdir AppDir \
	--plugin gtk \
	--library /usr/lib/x86_64-linux-gnu/libreadline.so.8 \
	--library /usr/lib/x86_64-linux-gnu/libonig.so.5 \
	--library /usr/lib/x86_64-linux-gnu/libncurses.so.6 \
	--library /usr/lib/x86_64-linux-gnu/libgladeui-2.so \
	--library /usr/lib/x86_64-linux-gnu/gvfs/libgvfscommon.so \
	--library /usr/lib/libphpcpp.so.2.3 \
	--desktop-file=AppDir/php-gtk3.desktop \
	--icon-file=AppDir/php-gtk3.png

```

create:

```
./appimagetool-x86_64.AppImage AppDir
```