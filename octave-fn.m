## Copyright (C) 2010 by John P. Weiss
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the Artistic License, included as the file
## "LICENSE" in the source code archive.
##
## This package is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
##
## You should have received a copy of the file "LICENSE", containing
## the License John Weiss originally placed this program under.
#########################################################################

#########################################################################
##
## usage: [a, b, c] = xFOOx (arg1, arg2)
##
## Usage description.
##
## Example:
##
## it goes here.
##
#########################################################################

## Author: John P. Weiss
## Created: 5/2003
## Keywords: this that
## Version: RCS $Id$

function [a, b, c] = xFOOx (arg1, arg2)
  ## nargin == number of args actuallly specified
  ## nargout == number of return values specified in this particular
  ## call to the function.
  ## nargchk(min, max, argVar) == true if 'argVar' is in the specified
  ## (inclusive) range.
  ## default_return_value == internal variable; defines what should be
  ## returned if the return variable is never set.  See the info page
  ## for the (nargout > 1) version of this.
  ## return: takes no args.  Just returns from the function.
  ##
  ## Omit ';' to have the result of that line print out when the
  ## function is called.
  ##
  ## all_va_args: used to pass all of the optional args onward to another
  ## function.
endfunction


##################
## Local Variables:
## mode: octave
## End:
