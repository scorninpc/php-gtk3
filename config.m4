dnl $Id$
dnl config.m4 for extension gtk

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(bah, for gtk support,
dnl Make sure that the comment is aligned:
dnl [  --with-gtk             Include gtk support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(gtk, whether to enable gtk support,
dnl Make sure that the comment is aligned:
[  --enable-gtk           Enable gtk support])

if test "$PHP_GTK" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-gtk -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/gtk.h"  # you most likely want to change this
  dnl if test -r $PHP_GTK/$SEARCH_FOR; then # path given as parameter
  dnl   GTK_DIR=$PHP_GTK
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for gtk files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       GTK_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$GTK_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the gtk distribution])
  dnl fi

  dnl # --with-gtk -> add include path
  dnl PHP_ADD_INCLUDE($GTK_DIR/include)

  dnl # --with-gtk -> check for lib and symbol presence
  dnl LIBNAME=gtk # you may want to change this
  dnl LIBSYMBOL=gtk # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $BGTK_DIR/lib, GTK_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_GTKLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong gtk lib version or lib not found])
  dnl ],[
  dnl   -L$GTK_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(GTK_SHARED_LIBADD)
  
  CFLAGS="$CFLAGS `pkg-config --cflags gtk+-2.0`"
  INCLUDES="$INCLUDES `pkg-config --libs gtk+-2.0`"

  PHP_NEW_EXTENSION(gtk, gtk.c gtk/gtkwindow.c, $ext_shared)
fi
