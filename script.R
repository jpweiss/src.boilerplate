#!/usr/bin/Rscript
##{ FIXME:  Remove the line above if this file is part of a library }##
##
## Copyright (C) 2012 by John P. Weiss
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
## $Id: script.R 2339 2012-01-05 01:17:22Z candide $
############################################################################


################
##
## Common Setup
##
################


##| ## Get the environment and commandline arguments at this point.
##| my.sysenv <- as.list(Sys.getenv())
##| ## Get the script's name from the program name.
##| my.argv <- commandArgs()
##| my.argv[1] <- sub("--file=", "", grep("^--file=", my.argv, value=TRUE))
##| my.name <- basename(my.argv[1])
##| my.path <- dirname(my.argv[1])
##| if ((length(my.path) == 0) || (nchar(my.path) == 0)) { my.path <- "." }
##| ## Get the actual args, w/o the stuff before the "--args" option.
##| my.argv <- commandArgs(TRUE)


#############
##
## Imports
##
#############


##library(LibName)
##if(file.exists(ScriptName)) { source(ScriptName) }


####################
##
## Global Variables
##
####################


usageMesg <- "" #???


##############
##
## Functions
##
##############


## Descr.
##
myfn.name <- function(opt1, opt2) {

}


## Descr.
##
myfn.zero <- function(opt) {
  return(0)
}


#########################
##
## Init & Arg Processing
##
#########################


##{ FIXME:  Remove this section if this file is part of a library }##
## args <- commandArgs(TRUE)


#############
##
## Main
##
#############


##{ FIXME:  Remove this section if this file is part of a library }##
##{ This statement is just a crude example }##
ls()

##{ FIXME:  'status' is the exit status code }
q(status=1)


####################
## Local Variables:
## mode: ess
## End:
