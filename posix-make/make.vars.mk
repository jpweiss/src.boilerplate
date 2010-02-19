# -*- Makefile -*-
#
# WARNING WARNING WARNING
# This file has not been modified from its GNU-make version!  It is not
# guaranteed to work AT ALL with other "make" variants.  Someday, it will.
# Just not today.
# WARNING WARNING WARNING
#
# Basic variables, like names of directories, flags for header/library
# locations, installation directories, and the like.
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
# RCS $Id$
##########


# For components, submodules, and other deeply-nested directory structures,
# use this:

#include ../make.vars.mk
## Uncomment for relative directories
##BASEDIR:=../$(BASEDIR)

# For the version of this file in $(BASEDIR), use one of these:

#relative#
BASEDIR:=.
#gnu-make#BASEDIR:=$(shell pwd)
#sh#BASEDIR:=${PWD}
SRCDOCDIR:=$(BASEDIR)/srcdoc
BINDIR:=$(BASEDIR)/bin
INCDIR:=$(BASEDIR)/include
LIBDIR:=$(BASEDIR)/lib
#BOOST:=${HOME}/src/boost

#CPPFLAGS += -I $(BOOST)
CPPFLAGS += -I . -I $(BASEDIR) -I $(INCDIR)

#LDFLAGS += -L$(LIBDIR) -L.

LIBS=


#################
#
#  End
