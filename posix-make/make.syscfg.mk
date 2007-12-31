# -*- Makefile -*-
#
# WARNING WARNING WARNING
# This file has not been modified from its GNU-make version!  It is not
# guaranteed to work AT ALL with other "make" variants.  Someday, it will.
# Just not today.
# WARNING WARNING WARNING
# 
# Variables that are compiler- and architecture-specific.  This includes any
# optimization flags, since these usually differ from platform to platform.
# 
#
# Copyright (C) 2008 by John P. Weiss
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
# RCS $Id$
##########
#
# Architecture.  Not used by all compilers.
#
##########


ARCH:=k6-2
ARCH:=i586
ARCH:=athlon-xp

# General architecture-specific compiler flags.
ARCHFLAGS:= # -m128bit-long-double 
# Others, possibly set by "-march" or "-mcpu":
# -m3dnow -mmmx


#------
# Note:
# 
# This file uses the following GNU-make features:
#
# '='  does not expand any RHS variables until LHS usage.  This is the default
#      behavior for most "make" variants.
# ':=' expands RHS variables immediately.
# '+=' appends, using whatever behavior the LHS was first assigned with.
# 
#------

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
CCC:=g++
CPP:=cpp
##FC:=g77

# Add the compiler architecture flags to all compilers that use it.
CC += -mcpu=$(ARCH) -march=$(ARCH)
CCC += -mcpu=$(ARCH) -march=$(ARCH)
FC += -mcpu=$(ARCH) -march=$(ARCH)

## GNU-make special:  These next two variables are part of every implicit
## command. 
##TARGET_ARCH:=-mcpu=$(ARCH) -march=$(ARCH)
##TARGET_MACH:=$(TARGET_ARCH)

# Some aliases.
##F77=$(FC)
##F90=$(FC) -ff90


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

DEBUG:=-ggdb3
#Other GCC debugging options: -save-temps -time

GPROF:=-pg
GCOV:=-ftest-coverage
PROFILE:=$(GPROF) $(GCOV)

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
#                            On by default in the present G++, but let's just
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
C_DEPFLAGS:=-MMD -MP

# Integer default size
##FFLAGS += -i4

# Make C++ include the same flags as C.
CXXFLAGS += $(CFLAGS)


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
COMPILE_TYPE:=$(DEBUG) # $(PROFILE)
COMPILE_TYPE:=$(OPTIMIZE) # $(PROFILE)


#################
#
#  End
