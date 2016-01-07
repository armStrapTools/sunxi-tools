AC_PREREQ([2.69])
AC_INIT([sunxi-script_extractor], [m4_esyscmd([../version-gen ../version])], [https://github.com/linux-sunxi/sunxi-tools])
AC_CONFIG_SRCDIR([script_extractor.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AM_INIT_AUTOMAKE([subdir-objects foreign])
AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_INSTALL

# Checks if we are building for the arm target
AC_MSG_CHECKING([whether we are building for the arm target])
AS_IF([test x$host_cpu == xarm], [armbuild=true])
AS_IF([test x$host_cpu == xarmv7l], [armbuild=true])
AS_IF([test x$armbuild = xtrue], [AC_MSG_RESULT([yes])], [AC_MSG_RESULT([no])])
AM_CONDITIONAL([ARM_BUILD], [test x$armbuild = xtrue])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
