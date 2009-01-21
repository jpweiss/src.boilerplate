#!/usr/bin/perl 
#
# Copyright (C) 2009 by John P. Weiss
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
############


############
#
# Std. Package Boilerplate
#
############


package pFOOp;
require 5;
use strict;

BEGIN {
    use Exporter ();
    our ($VERSION, @ISA, @EXPORT, @EXPORT_OK, %EXPORT_TAGS);

    # if using RCS/CVS, this may be preferred
    $VERSION = do { my @r = (q$Revision: 1401 $ =~ /\d+/g); sprintf "%d."."%02d" x $#r, @r }; # must be all one line, for MakeMaker

    @ISA         = qw(Exporter);

    # Default exports.
    @EXPORT = qw(xx $x);
    # Permissable exports.
    # your exported package globals go here,
    # as well as any optionally exported functions
    @EXPORT_OK = qw($_Verbose $_UnitTest);

    # Tagged groups of exports.
    %EXPORT_TAGS = qw();
}
our @EXPORT_OK;

# Other Imported Packages/requirements.
use Foo::Bar;


############
#
# Global Variables
#
############


our $_Verbose;  $_Verbose = 0;
our $_UnitTest; $_UnitTest = 0;
our $x;  $x = 1;


############
#
# Internal Variables
#
############


my $y = 2;


############
#
# Internal Functions
#
############


sub yy {
}


############
#
# Exported Functions
#
############


sub xx {
    print "usage: $_MyName [args...]\n";
    exit 1;
}


1;  # don't forget to return a true value from the file
## POD STARTS HERE ##
__END__

=head1 NAME

pFOOp - Package doing FOO.

=head1 SYNOPSIS

=over 0

=item sub

=back

=head1 DESCRIPTION

=over 2

=item *

sub

Descr.

=back

=cut

#################
#
#  End
