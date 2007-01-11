# -*- Makefile -*-
#
# Special GNU-make file of installation rules.
# 
#
# Copyright (C) 2007 by John P. Weiss
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

# Expected vars:

# The installation directories:
#   BINDIR
#   LIBDIR
#   INCDIR

# List of C/C++ headers
#   HEADERS

# Target library
#   TARG_LIB

# Target Binaries
#   TARG_BINS


#
# The Rules
#


$(BINDIR):
	mkdir -p $(BINDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(INCDIR):
	mkdir -p $(INCDIR)

# Header Installation Rules.
install_headers: $(INCDIR) install_headers.parts

install_headers.parts: $(HEADERS)
	if [ -n "$?" ]; then \
		cp $? $(INCDIR)/; \
	fi

#T# Example: Alternate version
#T#install_headers.parts: $(call finder,$(SRC_INCLUDEPATH)/)
#T#	cd $(SRC_INCLUDEPATH); \
#T#	for targ in $?; do \
#T# For bash/ksh, use this:
#T#		targ2=$${src\#$(SRC_INCLUDEPATH)/}; \
#T# Otherwise, use this:
#T#		targ2=`echo $${src} | sed 's|^$(SRC_INCLUDEPATH)/||'`; \
#T#		cp -dP --parents $${targ2} $(INCDIR)/; \
#T#	done

# Installation rules for binaries.  Remove if building a lib.
install_bin: $(BINDIR) install_bin.parts

install_bin.parts: $(TARG_BINS)
	if [ -n "$?" ]; then \
		cp -a $? $(BINDIR)/; \
	fi

# Installation rules for libs.  Remove if building executables.
install_libs: $(LIBDIR) install_libs.parts

install_libs.parts: $(TARG_LIB).a $(TARG_LIB).so
	if [ -n "$?" ]; then \
		cp -a $? $(LIBDIR)/; \
	fi


#################
#
#  End
