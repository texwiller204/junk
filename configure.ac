#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(junk, 0.0.0, don@na.rim.or.jp)
AC_CONFIG_SRCDIR([test_main.cpp])
AC_CONFIG_HEADER([config.h])
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE

SYSTEMNAME=`uname -s`

AC_ARG_ENABLE([opengl], [AS_HELP_STRING([--enable-opengl], [Enable OpenGL feature @<:@default=no@:>@])], [enable_opengl=$enableval], [enable_opengl=no])
if test "x$enable_opengl" != xno; then
  AC_DEFINE([ENABLE_OPENGL], [1], [Define 1 to you use OpenGL])
  case "$SYSTEMNAME" in
    Darwin)
      OPENGL_FRAMEWORK="-framework OpenGL"
      AC_SUBST(OPENGL_FRAMEWORK)
      ;;
  esac
fi

AC_ARG_ENABLE([coverage], [AS_HELP_STRING([--enable-coverage], [use gcov and lcov (default is no)])], [use_coverage=$withval], [use_coverage=no])
if test "x$use_coverage" != xno; then
  COVERAGE_CFLAGS="-coverage"
  COVERAGE_CXXFLAGS="-coverage"
  COVERAGE_LIBS="-lgcov"
  AC_SUBST(COVERAGE_CFLAGS)
  AC_SUBST(COVERAGE_CXXFLAGS)
  AC_SUBST(COVERAGE_LIBS)
fi

# Checks for programs.
AC_PROG_AWK
AC_PROG_OBJC
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_RANLIB
AC_PROG_CPP
AC_PROG_MKDIR_P

AC_PATH_PROG([RUBY],[ruby])
AC_PATH_PROG([NASM],[nasm])

AC_CHECK_PROGS(DOXYGEN, [doxygen])
AC_CHECK_PROGS(PCAP_CONFIG, [pcap-config])

# Checks for libraries.
AM_PATH_SDL2(2.0.0)
SDL_LIBS="$SDL_LIBS -lSDL2_image"
#AC_CHECK_LIB([pcap], [pcap_lookupdev])
if test x$PCAP_CONFIG != x; then
    PCAP_LIBS=`$PCAP_CONFIG --libs`
else
    PCAP_LIBS=-lpcap
fi
AC_SUBST(PCAP_LIBS)

case "$SYSTEMNAME" in
  Darwin)
    COCOA_FRAMEWORK="-framework Cocoa"
    AC_SUBST(COCOA_FRAMEWORK)
    ;;
esac

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h mach/mach_time.h netinet/in.h pcap.h pcap/pcap.h stdint.h sys/socket.h unistd.h])
AC_LANG_PUSH(C++)
AC_CHECK_HEADERS([tr1/cstdint tr1/unordered_map ext/hash_map])
AC_LANG_POP

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_HEADER_STDC
AC_CXX_HEADER_STDCXX_98
AC_FUNC_MEMCMP
AC_CHECK_FUNCS([memset socket])

AC_CONFIG_FILES([Doxyfile Makefile build.ninja.yaml.erb])
AC_CONFIG_FILES([net_test.sh], [chmod +x net_test.sh])
AC_CONFIG_FILES([peg_test.sh], [chmod +x peg_test.sh])
AC_OUTPUT
