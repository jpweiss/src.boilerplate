# -*- Makefile -*-
#
# Variables that are compiler- and architecture-specific.  This includes any
# optimization flags, since these usually differ from platform to platform.
#
#
# Copyright (C) 2014 by John P. Weiss
#
# This package is free software; you can redistribute it and/or modify
# it under the terms of the Artistic License, included as the file
# "LICENSE" in the source code archive.
#
# This package is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# You should have received a copy of the file "LICENSE", containing
# the License John Weiss originally placed this program under.
#
# $Id$
##########
#
# Architecture.  Not used by all compilers.
#
##########


ARCH:=generic
#ARCH:=pentium4
#ARCH:=athlon #athlon-4 #athlon-xp #athlon-mp
#ARCH:=core2
#ARCH:=athlon64-sse3 #opteron-sse3
#ARCH:=pentium-m


# General architecture-specific compiler flags.
ARCHFLAGS:= # -m128bit-long-double
# Others, possibly set by "-march" or "-mtune":
# -m3dnow -mmmx

# Use non-expanding defn. for the language flags.  Set them to the special
# variable, $(COMPILE_TYPE), which we'll define in the main makefile
CFLAGS = $(COMPILE_TYPE)
CXXFLAGS = # Leave empty
# Remove C/C++-specific options.
FFLAGS = $(filter-out -fno-default-inline, $(COMPILE_TYPE))


##########
#
# Compilers
#
##########


CC:=gcc
CXX:=g++
CCC:=$(CXX)
CPP:=cpp
##FC:=gfortran
GCOV:=gcov
GCOV_OPTS:=

# GNU-make special:  These next two variables are part of every implicit
# command.
TARGET_ARCH:=-march=$(ARCH) #-mtune=$(ARCH) <- Redundant
#							 -march implies & sets -mtune
ifeq ($(ARCH), generic)
#    'generic' is not a valid value for -march, but does work with -mtune.
TARGET_ARCH:=-mtune=$(ARCH)
endif
TARGET_MACH:=$(TARGET_ARCH)

# Some aliases.
##F77=$(FC)
##F90=$(FC) -ff90

# Cross-linking libraries
##F_LIBS:=-lg2c # Linux g77, compat-gcc v3.2
##F_LIBS:=-static-libgfortran -lgfortran # Linux gfortran, gcc v4.
##F_LIBS:=-lfortran # Solaris; IRIX


##########
#
# Definitons:  Optimization/Debugging/Profiling Flags
#
##########


OPTIMIZE:=-O3 -mieee-fp -malign-double \
	-fexpensive-optimizations -fprefetch-loop-arrays \
	-funroll-loops -fpeel-loops -funswitch-loops -frerun-loop-opt \
	-fno-caller-saves
# Other optimizations:
#     -mfpmath=sse
#     -msse2
#     -msse3                          # for -march=core2 only
#     -maccumulate-outgoing-args
#     -minline-all-stringops
#  We'd need to try these out, one by one, and see how they improve
#  performance.
# Agressive Inlining:
#     -finline-limit=N #Default==600
#     --param large-function-growth=M #Default 100
#     --param inline-unit-growth=L #Default 50

DEBUG:=-g3 -ggdb3 -DDEBUG
DISABLE_INLINE:=-fno-inline -fno-default-inline
#Other GCC debugging options: -save-temps -time
#Those last two return information about the compilation.

# Disable all optimizations for (most) regression-testing.
REGRESSION:=-O0 $(DISABLE_INLINE)

GPROF_GCC:=-pg
GCOV_GCC:=-fprofile-arcs -ftest-coverage
PROFILE:=$(GPROF_GCC) $(GCOV_GCC)

# Google Perftools Support:
CFLAGS_TCMALLOC=-fno-builtin-malloc -fno-builtin-calloc \
	-fno-builtin-realloc -fno-builtin-free
LIB_TCMALLOC=-ltcmalloc

# Add the architecture-specific flags to each compiler that takes them.  We
# will append "CFLAGS" onto "CXXFLAGS" later.
CFLAGS += $(ARCHFLAGS)
FFLAGS += $(ARCHFLAGS)

#
# Warnings (Per-Language)
#

CFLAGS += -Wall -W -Wformat-security -Wshadow
# What this does:
#     -Wall: Use all warnings,
#     -W: use some additional ones
#     All remaining -Wxxx options are not included in "-Wall"
# Other useful C/C++ flags:
#     -pedantic
# This next one can get very noisy:
#     -Winline
# Other Useful non"-Wall" options:
#     -Wunreachable-code -Wno-deprecated-declarations
# Uncomment this for applications in which we need to treat the floating point
# types as approximations.
#CFLAGS += -Wfloat-equal

CXXFLAGS += -felide-constructors \
	-Wreorder -Wold-style-cast -Woverloaded-virtual
# What this does:
#     -Wreorder: Make sure construction order matches declaration order.
#     -Wold-style-cast:  Warn if we use C-casts in C++ code.
#     -Woverloaded-virtual: Self-explanatory.
#     -felide-constructors:  Snip out temporaries created by the compiler
#                            (like in return values to the RHS of op=(), etc.)
#                            On by default in the present g++, but let's just
#                            make sure...
# Other g++ flags:
#     -Wno-deprecated:  Disable warnings about older, non-std-compliant
#                       G++-ism.
# May not work well with STL implementations (makes too much noise)
#	-fhonor-std -Weffc++

#
# Other Per-Language Options
#

# Used to generate the *.d  dependency files (under gcc):
C_DEPFLAGS:=-MM -MP
# Use this to generate a *.d file as a side-effect of normal compliation
#CFLAGS += -MMD -MP

# Make C++ include the same flags as C.
CXXFLAGS += $(CFLAGS)

# Integer default size in FORTRAN
# [jpw; 201002]  This now appears deprecated, and INT is now 4 bytes by
# 				 default.  For now.
##FFLAGS += -i4


# Flags for building static libraries
ARFLAGS=crv
# Meaning:
#     r:  Insert or replace the member into the archive.
#     c:  Create the archive as needed.
#     v:  Be verbose.


##########
#
# How to compile?  Debug mode?  Optimized?  With or without profiling?
#
##########


#DEBUG_FLAGS:=#-DDEBUG
#COMPILE_TYPE:=
#LDFLAGS += $(PROFILE)
#COMPILE_TYPE:=$(DEBUG) #$(PROFILE) #$(DEBUG_FLAGS)
#COMPILE_TYPE:=$(DEBUG) $(DISABLE_INLINE) #$(DEBUG_FLAGS)
#LDFLAGS += -lefence
#LDFLAGS += -ldmalloc -ldmallocxx
#CFLAGS += $(CFLAGS_TCMALLOC)
#LDFLAGS += $(LIB_TCMALLOC)
#COMPILE_TYPE:=$(OPTIMIZE)
#WARNING# Use this for the regression tests:
COMPILE_TYPE:=$(REGRESSION)


#################
#
#  End
