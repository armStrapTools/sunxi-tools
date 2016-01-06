AC_PREREQ([2.69])
AC_INIT([sunxi-fel], [1.4.3], [https://github.com/linux-sunxi/sunxi-tools])
AC_CONFIG_SRCDIR([fel.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AM_INIT_AUTOMAKE([subdir-objects foreign])
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_INSTALL

# Checks if we can build sunxi-fel
CPPFLAGS_SAVE="$CPPFLAGS"
LIBS_SAVE="$LIBS"
CPPFLAGS="$CPPFLAGS -I/usr/include/libusb-1.0"
AC_SEARCH_LIBS([libusb_bulk_transfer], [usb-1.0], [USB_LDFLAGS="-lusb-1.0"])
AS_IF([test x$USB_LDFLAGS != x], [AC_CHECK_HEADERS([libusb.h], [USB_CFLAGS="-I/usr/include/libusb-1.0"])])
CPPFLAGS="$CPPFLAGS_SAVE"
LIBS="$LIBS_SAVE"
AC_MSG_CHECKING([whether we can build sunxi-fel])
AS_IF([test x$USB_CFLAGS != x], [AC_MSG_RESULT([yes])], [AC_MSG_RESULT([no])])
AM_CONDITIONAL([BUILD_SUNXIFEL], [test x$USB_CFLAGS != x])

AC_SUBST([USB_LDFLAGS])
AC_SUBST([USB_CFLAGS])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
