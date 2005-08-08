#!/usr/bin/octave -qf
##
## Copyright (C) 2005 by John P. Weiss
##
## This package is free software; you can redistribute it and/or modify
## it under the terms of the Artistic License, included as the file
## "LICENSE" in the source code archive.
##
## This package is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
##
## You should have received a copy of the file "LICENSE", containing
## the License John Weiss originally placed this program under.
##
## RCS $Id$
#############
1; # Required to distinguish this from a function-file


#############
##
## Script Startup Boilerplate
##
#############


# Get the script's name from the program name.
psep_idx = rindex(program_invocation_name, "/");
myPath = "";
if (psep_idx)
  myName = substr(program_invocation_name, psep_idx+1);
  if (psep_idx > 1)
    myPath = program_invocation_name(1:psep_idx-1);
  endif
else
  myName = program_invocation_name;
endif
clear psep_idx;
##Add its path to the search path.
if (length(myPath) && !strcmp(myPath, "."))
  LOADPATH = [LOADPATH, ":", myPath, "//"]; # Search its subdirs, too!
endif


#############
##
## Includes
##
#############


##source (file_in_loadpath("somefile.octave"));


#############
##
## Global Variables
##
#############


usageMesg = [ myName, " myArgs [Opts....]\n",
             "\nOptions:\n",
             "-a:\n",
             "\tDescr.\n",
             "\nUsage.\n"
             ];


#############
##
## Functions
##
#############


function retval = bar (x, y, z)
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
  retval = x * y ** z;
endfunction


#############
##
## Init & Arg Processing
##
#############


## Stop if this file was sourced
if (strcmp(myName, "octave"))
  return;
endif


## Check argc for valid size
if (nargin < 1)
  usage (usageMesg);
endif

## nargin == argc
## list argv ==  cmdline arg
## Use nth(argv, i) to extract args into string variables.  argv(i)
## pulls out a single-element list variable.


#############
##
## Main Command Set
##
#############




##################
## Local Variables:
## mode: octave
## End:
