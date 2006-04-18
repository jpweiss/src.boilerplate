# -*- Makefile -*-
#
# Special GNU-make file for cleanup rules.
# 
#
# Copyright (C) 2006 by John P. Weiss
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
#   SRCDOCDIR

# Target library
#   TARG_LIB

# Target Binaries
#   TARG_BINS

# List of *.o files:
#   OBJS


#
# The Rules
#


clean:
	-rm -f $(OBJS) *.bb *.bbg

gprofclean:
	-rm -f *.gc*

veryclean: clean gprofclean
	cd utests; $(MAKE) clean gprofclean
	-rm -f $(TARG_LIB).a  $(TARG_LIB).so $(TARG_BINS)
#T#	-rm -f $(OTHERSTUFF)

depclean: 
	find . -name '*.d' -exec rm -v \{\} \;

distclean_toplevel: veryclean depclean
	-rm -fr $(BINDIR)/* $(LIBDIR)/* $(INCDIR)/* $(SRCDOCDIR)/*


#################
#
#  End
