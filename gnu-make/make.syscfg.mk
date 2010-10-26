# -*- Makefile -*-
#
# Variables that are compiler- and architecture-specific.  This includes any
# optimization flags, since these usually differ from platform to platform.
#
#
# Copyright (C) 2010 by John P. Weiss
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


ARCH:=i586
#ARCH:=k6-2
#ARCH:=athlon-xp
#ARCH:=pentium-m


# General architecture-specific compiler flags.
ARCHFLAGS:= # -m128bit-long-double
# Others, possibly set by "-march" or "-mcpu":
# -m3dnow -mmmx

# Use non-expanding defn. for the language flags.  Set them to the special
# variable, $(COMPILE_TYPE), which we'll define in the main makefile
CFLAGS = $(COMPILE_TYPE)
CXXFLAGS = $(COMPILE_TYPE)
##FFLAGS = $(COMPILE_TYPE)


##########
#
# Compilers
#
##########


CC:=gcc
CXX:=g++
CCC:=$(CXX)
CPP:=cpp
##FC:=g77
GCOV:=gcov
GCOV_OPTS:=

# GNU-make special:  These next two variables are part of every implicit
# command.
TARGET_ARCH:=-mcpu=$(ARCH) -march=$(ARCH)
TARGET_MACH:=$(TARGET_ARCH)

# Some aliases.
##F77=$(FC)
##F90=$(FC) -ff90

# Cross-linking libraries
F_LIBS:=-lg2c #g77
#F_LIBS:=-lfortran # Solaris; IRIX


##########
#
# Definitons:  Optimization/Debugging/Profiling Flags
#
##########


OPTIMIZE:=#-O3 -funroll-loops -fmerge-constants
# Flags for faster math.  Place after the "-O".
#     -mieee-fp -malign-double -mwide-multiply $(ARCHFLAGS)
#
# Agressive Inlining:
#     -finline-functions -finline-limit=N #Default==600
# Some other useful optimizations:
#	-fexpensive-optimizations -fprefetch-loop-arrays \
#	-funroll-loops -frerun-loop-opt

DEBUG:=-ggdb3 -DDEBUG
#Other GCC debugging options: -save-temps -time

GPROF_GCC:=-pg
GCOV_GCC:=-fprofile-arcs -ftest-coverage
PROFILE:=$(GPROF_GCC) $(GCOV_GCC)

# Add the architecture-specific flags to each compiler that takes them.  We
# will append "CFLAGS" onto "CXXFLAGS" later.
CFLAGS += $(ARCHFLAGS)
##FFLAGS += $(ARCHFLAGS)

#
# Warnings (Per-Language)
#

CFLAGS += -Wall -W -Wformat-security -Wshadow -Winline
# What this does:
#     -Wall: Use all warnings,
#     -W: use some additional ones
#     All remaining -Wxxx options are not included in "-Wall"
# Other useful C/C++ flags:
#     -pedantic
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

# Integer default size
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


COMPILE_TYPE:=
#COMPILE_TYPE:=$(DEBUG) # $(PROFILE)
#LDFLAGS += $(PROFILE)
#COMPILE_TYPE:=$(OPTIMIZE) # $(PROFILE)


#################
#
#  End
