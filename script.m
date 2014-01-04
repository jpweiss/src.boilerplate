#!/usr/bin/octave -qf
##
## Copyright (C) 2014 by John P. Weiss
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
## $Id: script.m 2339 2012-01-05 01:17:22Z candide $
#############
1; # Required to distinguish this from a function-file


#############
##
## Script Startup Boilerplate
##
#############


## Get the script's name from the program name.
myName = program_invocation_name ();
psep_idx = rindex (myName, "/");
myPath = "";
if (psep_idx)
  if (psep_idx > 1)
    myPath = myName(1:psep_idx-1);
  endif
  myName = substr (myName, psep_idx+1);
endif
clear psep_idx;
##Add its path to the search path.
if (length (myPath) && !strcmp (myPath, "."))
  addpath (genpath (myPath));
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


global \
usageMesg = [ myName, " myArgs [Opts....]\n", \
             "\nOptions:\n", \
             "-a:\n", \
             "\tDescr.\n", \
             "\nUsage.\n", \
             "\n\n(This is a usage message.  You can ignore the code ", \
             " trace below.)" ];


#############
##
## Functions
##
#############


function [cmdopts] = process_cmdline (g_argv, g_nargin)
  global usageMesg;

  cmdopts.verbose=0;
  cmdopts.remaining = cell ();

  ## Edit to suit your needs
  ##
  opt_val = "";
  for i = 1 : g_nargin
    cur_arg = nth (g_argv, i);
    if (!strcmp (opt_val, "") || strcmp (opt_val, cur_arg))
      opt_val = "";
      continue;
    endif

    ## nargin == argc
    ## list argv ==  cmdline arg
    ## Use nth (argv, i) to extract args into string variables.  argv (i)
    ## pulls out a single-element list variable.
    if (strcmp (cur_arg, "-h") || strcmp(cur_arg, "--help"))
      usage (usageMesg);
    elseif (strcmp(cur_arg, "-v") || strcmp(cur_arg, "--verbose"))
      cmdopts.verbose = 1;
    else
      ## Process this as a non-option arg.
      cmdopts.remaining = [cmdopts.remaining; cellstr(cur_arg)];
    endif
  endfor
endfunction


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
if (strcmp (myName, "octave"))
  return;
endif


## Check argc for valid size
if (nargin < 1)
  usage (usageMesg);
endif


opts = process_cmdline (argv, nargin);


#############
##
## Main Command Set
##
#############




##################
## Local Variables:
## mode: octave
## End:
