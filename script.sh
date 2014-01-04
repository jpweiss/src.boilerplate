#!/bin/bash
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
############


############
#
# Configuration Variables
#
############


############
#
# Includes & Other Global Variables
#
############


#. some.include.sh

GREP=grep
SED=sed
AWK=awk
LS=ls


############
#
# Functions
#
############


############
#
# Main
#
############


case "$0" in
    *bash)
        file_was_sourced='y'
        ;;
    *)
        if [ ${#BASH_SOURCE[*]} -gt 1 ]; then
            file_was_sourced='y'
        fi
        ;;
esac


if [ -n "$file_was_sourced" ]; then
    # Was sourced.  Remove the temporary variable created during the startup
    # checks.
    unset file_was_sourced
else
    # Was run as a script.  Perform any execution-specific tasks here (rather
    # than pulling an unneeded "main" function into the environment.
    :
fi


#################
#
#  End
