AC_PREREQ([2.69])
AC_INIT([sunxi-tools], [m4_esyscmd([./version-gen version])], [https://github.com/armStrapTools/sunxi-tools/issues], [], [https://www.armstrap.net])
m4_include([sunxi-baremetal/ax_cc_for_build.m4])
AC_COPYRIGHT([Copyright (C) 2015-2016  Eddy Beaupre <eddy@beaupre.biz>])
AC_REVISION([Revision: 1.2])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([.])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([subdir-objects foreign])
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_INSTALL
AC_PROG_LN_S
AX_CC_FOR_BUILD

AC_DEFINE([PACKAGE_COPYRIGHT], ["Copyright (C) 2015-2016  Eddy Beaupre"], [Package Copyright])
AC_DEFINE([PACKAGE_EMAIL], ["eddy@beaupre.biz"], [Package Email])
AC_DEFINE([PACKAGE_LICENCE_NAME], ["GPLv2+"], [Package Licence Name])
AC_DEFINE([PACKAGE_LICENCE_DESCRIPTION], ["GNU GPL version 2 or later"], [Package Licence Description])
AC_DEFINE([PACKAGE_LICENCE_URL], ["http://gnu.org/licenses/gpl-2.0.html"], [Package Licence URL])
AC_DEFINE_UNQUOTED([PACKAGE_BUILD_DATE], ["`date -R`"], [Package Date])

# Checks if we are building for the arm target
AC_MSG_CHECKING([whether we are building for the arm target])
AS_IF([test x$host_cpu == xarm], [armbuild=true])
AS_IF([test x$host_cpu == xarmv7l], [armbuild=true])
AS_IF([test x$armbuild = xtrue], [AC_MSG_RESULT([yes])], [AC_MSG_RESULT([no])])
AM_CONDITIONAL([ARM_BUILD], [test x$armbuild = xtrue])

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

# Checks if we can build the bare-metal tools.
AC_PATH_PROG([ARM_GCC], [arm-none-eabi-gcc])
AC_PATH_PROG([ARM_CPY], [arm-none-eabi-objcopy])
AC_PATH_PROG([ARM_NM], [arm-none-eabi-nm])
AC_MSG_CHECKING([whether we can build the bare metal tools])
AS_IF([test -z "$ARM_NM"], [baremetal=false], AS_IF([test -z "$ARM_CPY"], [baremetal=false], AS_IF([test -z "$ARM_GCC"], [baremetal=false], [baremetal=true])))
AS_IF([test x$baremetal = xtrue], [AC_MSG_RESULT([yes])], [AC_MSG_RESULT([no])])
AM_CONDITIONAL([BUILD_BAREMETAL], [test x$baremetal = xtrue])
AC_SUBST([ARM_GCC])
AC_SUBST([ARM_CPY])
AC_SUBST([ARM_NM])

AC_CONFIG_FILES([Makefile sunxi-bootinfo/Makefile sunxi-fexc/Makefile sunxi-fel/Makefile sunxi-meminfo/Makefile sunxi-nand-part/Makefile sunxi-phoenix_info/Makefile sunxi-pio/Makefile sunxi-script_extractor/Makefile sunxi-baremetal/Makefile])
AC_OUTPUT
