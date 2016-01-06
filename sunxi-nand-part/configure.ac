AC_PREREQ([2.69])
AC_INIT([sunxi-nand-part], [1.4.3], [https://github.com/armStrapTools/sunxi-tools/issues], [], [https://www.armstrap.net])
AC_COPYRIGHT([Copyright (C) 2015-2016  Eddy Beaupre <eddy@beaupre.biz>])
AC_REVISION([Revision: 1.2])
AC_CONFIG_SRCDIR([sunxi-nand.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AM_INIT_AUTOMAKE([subdir-objects foreign])
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_INSTALL

AC_DEFINE([PACKAGE_COPYRIGHT], ["Copyright (C) 2015-2016  Eddy Beaupre"], [Package Copyright])
AC_DEFINE([PACKAGE_EMAIL], ["eddy@beaupre.biz"], [Package Email])
AC_DEFINE([PACKAGE_LICENCE_NAME], ["GPLv2+"], [Package Licence Name])
AC_DEFINE([PACKAGE_LICENCE_DESCRIPTION], ["GNU GPL version 2 or later"], [Package Licence Description])
AC_DEFINE([PACKAGE_LICENCE_URL], ["http://gnu.org/licenses/gpl-2.0.html"], [Package Licence URL])
AC_DEFINE_UNQUOTED([PACKAGE_GIT_VERSION], ["`git describe --always`"], [Package Git Version])
AC_DEFINE_UNQUOTED([PACKAGE_BUILD_DATE], ["`date -R`"], [Package Date])
 
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
