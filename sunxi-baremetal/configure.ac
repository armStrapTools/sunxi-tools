AC_PREREQ([2.69])
AC_INIT([sunxi-baremetal], [1.4], [https://github.com/linux-sunxi/sunxi-tools])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_SRCDIR([mksunxiboot.c])

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([subdir-objects foreign])

AC_PROG_CC
AC_PROG_CC_STDC
AC_PROG_INSTALL
AC_PROG_LN_S

AC_MSG_CHECKING([whether we are building for the arm target])
AS_IF([test x$host_cpu == xarm], [armbuild=true])
AS_IF([test x$host_cpu == xarmv7l], [armbuild=true])
AS_IF([test x$armbuild = xtrue], [AC_MSG_RESULT([yes])], [AC_MSG_RESULT([no])])
AM_CONDITIONAL([ARM_BUILD], [test x$armbuild = xtrue])

# Checks if we can build the bare-metal tools.
AC_PATH_PROG([ARM_GCC], [arm-none-eabi-gcc])
AC_PATH_PROG([ARM_CPY], [arm-none-eabi-objcopy])
AC_PATH_PROG([ARM_NM], [arm-none-eabi-nm])
AC_MSG_CHECKING([whether we can build the bare metal tools])
AS_IF([test x$cross_compiling = xyes], [baremetal=false], AS_IF([test -z "$ARM_NM"], [baremetal=false], AS_IF([test -z "$ARM_CPY"], [baremetal=false], AS_IF([test -z "$ARM_GCC"], [baremetal=false], [baremetal=true]))))
AM_CONDITIONAL([BUILD_BAREMETAL], [test x$baremetal = xtrue])

AC_SUBST([ARM_GCC]) 
AC_SUBST([ARM_CPY])
AC_SUBST([ARM_NM])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
