## Process this file with autoconf to produce a configure script.
##
## (Note:  Use double-comments with autoconf files.)
##
## $Id$
#############

AC_PREREQ([2.65])
AC_INIT([%%The-Package-Name%%],
        [%%Initial-Version:%%0.1%%],
        [jpwcandide@sourceforge.net],
        [%%The-Tarball-Name--PackageName=~s/_/-/g%%],
        [http://sourceforge.net/projects/%%Project-Name%%/])
AC_CONFIG_HEADERS([config.h])

# [jpw]  My licensing and SVN revision variable.
AC_COPYRIGHT([Artistic License])
AC_REVISION([ $Revision$ ])

# [jpw] Pull in my custom macros.
# 
m4_include([ax_jpwTools.m4])


# FIXME::[jpw]  Remove if not true:
# [jpw] We're building on Linux only.  Follow the FHS layout.
AX_JPW_USE_FHS_DEFAULTS

# FIXME::[jpw]  Remove if not true:
# [jpw] We're building Debian and RPM packaging files.
AX_JPW_CREATING_DEB_RPM([pkgTemplates],
                        [debian.control], 
                        [%%ProjectName%%.spec])


# [jpw] Example of how to define a custom variable.
#AX_JPW_ARG_MAKEFILE_VAR([CUSTOM_PATH], 
#                        [/etc/some/custom/path],
#                        [Documentation/Description to appear in the 
#                         `configure' --help output])


# [jpw]  Automake
AM_INIT_AUTOMAKE([-Wall color-tests])

# Checks for programs.
AC_PROG_CXX
## FIXME::[jpw] This is if you have C to build:
AC_PROG_CC
## FIXME::[jpw] ...and for C99, specifically:
AC_PROG_CC_C99
## FIXME::[jpw] This is if you have FORTRAN to build:
AC_PROG_FC # (there is also AC_PROG_F77)
## FIXME::[jpw] You can also check for/require AC_PROG_AWK, AC_PROG_EGREP,
## AC_PROG_SED, AC_PROG_LN_S, AC_PROG_MKDIR_P,


# Checks for libraries.
#AC_CHECK_LIB([Example], [ExampleDiscard], [],
#             [AC_MSG_ERROR([Failed to find the Example extension library.
#                            Cannot continue.]) ])

# Checks for header files.
AC_PATH_X
AC_CHECK_HEADERS([ fcntl.h stdint.h sys/time.h unistd.h \
                   X11/extensions/XTest.h X11/Xlib.h ],
                   [], [AX_JPW_HEADER_ERROR])

# [jpw] Check for required Boost headers that are part of header-only
#       libraries.
#
AX_JPW_REQUIRE_CXX_HEADERS([ boost/algorithm/string/case_conv.hpp \
                             boost/algorithm/string/classification.hpp \
                             boost/algorithm/string/predicate.hpp ])


# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_MODE_T
AC_TYPE_PID_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T

# Checks for library functions.
AC_FUNC_FORK
## FIXME::[jpw]  Uncomment the next two if using Daemonize.{h,cc}
#AX_JPW_REQUIRE([FUNC_FORK], [the fork() function])
#AC_CHECK_FUNCS([dup2 strerror], [], [AX_JPW_FUNC_ERROR])
## FIXME::[jpw]  Just use this if _not_ using Daemonize.{h,cc}
#AC_CHECK_FUNCS([strerror], [], [AX_JPW_FUNC_ERROR])


# [jpw] Common checks
AC_CXX_HEADER_STDCXX_TR1
AX_JPW_REQUIRE([CXX_STDCXX_TR1], [the C++ TR1 headers])
AX_BOOST_BASE
AX_BOOST_PROGRAM_OPTIONS
AX_JPW_REQUIRE([BOOST_PROGRAM_OPTIONS], [boost::program_options], [ax])


## FIXME::[jpw]  Any files that contain things like @bindir@ and @sysconfdir@
## should have the *.in suffix and should be placed in the list of files
## below:
AC_CONFIG_FILES([Makefile
                 src/Makefile
                 #%custom-file-without-the-.in-suffix%#
                 ])
AC_OUTPUT


##################
## Local Variables:
## mode: autoconf
## End:
