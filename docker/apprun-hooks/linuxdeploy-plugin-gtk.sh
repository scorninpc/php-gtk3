#! /usr/bin/env bash

COLOR_SCHEME="$(dbus-send --session --dest=org.freedesktop.portal.Desktop --type=method_call --print-reply --reply-timeout=1000 /org/freedesktop/portal/desktop org.freedesktop.portal.Settings.Read 'string:org.freedesktop.appearance' 'string:color-scheme' 2>/dev/null | tail -n1 | cut -b35- | cut -d' ' -f2)"
if [ -z "$COLOR_SCHEME" ]; then
    COLOR_SCHEME="$(gsettings get org.gnome.desktop.interface color-scheme 2> /dev/null)"
fi
case "$COLOR_SCHEME" in
    "1"|"'prefer-dark'")  GTK_THEME_VARIANT="dark";;
    "2"|"'prefer-light'") GTK_THEME_VARIANT="light";;
    *)                    GTK_THEME_VARIANT="light";;
esac
# APPIMAGE_GTK_THEME="${APPIMAGE_GTK_THEME:-"Adwaita:$GTK_THEME_VARIANT"}" # Allow user to override theme (discouraged)

export APPDIR="${APPDIR:-"$(dirname "$(realpath "$0")")"}" # Workaround to run extracted AppImage
export GTK_DATA_PREFIX="$APPDIR"
# export GTK_THEME="$APPIMAGE_GTK_THEME" # Custom themes are broken
export GDK_BACKEND=x11 # Crash with Wayland backend on Wayland
export XDG_DATA_DIRS="$APPDIR/usr/share:/usr/share:$XDG_DATA_DIRS" # g_get_system_data_dirs() from GLib
export GSETTINGS_SCHEMA_DIR="$APPDIR//usr/share/glib-2.0/schemas"
export GI_TYPELIB_PATH="$APPDIR//usr/lib/girepository-1.0"
export GTK_EXE_PREFIX="$APPDIR//usr"
export GTK_PATH="$APPDIR//usr/lib/gtk-3.0"
export GTK_IM_MODULE_FILE="$APPDIR//usr/lib/gtk-3.0/3.0.0/immodules.cache"
export GDK_PIXBUF_MODULE_FILE="$APPDIR//usr/lib/gdk-pixbuf-2.0/2.10.0/loaders.cache"
