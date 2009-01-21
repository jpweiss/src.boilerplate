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
# Configuration Variables
#
############


############
#
# Precompilation Init
#
############
# Before anything else, split the script's name into directory/file.  We
# want to add the script's directory to the set of include-dirs.  This way, we
# get any packages living in the script's directory.
my $_MyName;
BEGIN {
    if ($0 =~ m|\A(.*)/([^/]+\Z)|) {
        if ($1 ne ".") { push @INC, $1; }
        $_MyName = $2;
    } else { $_MyName = $0; }  # No path; only the script name.
}


############
#
# Includes/Packages
#
############


require 5;
use strict;
use bytes;           # Overrides Unicode support
use Getopt::Long;    # For options.
#use Foo::Bar;       # Other required modules.
#use jpwTools;


############
#
# Other Global Variables
#
############


my $_Verbose = 0;
my $_UnitTest = 0;
my %usg_DefaultVals = ();
my %usg_OptNames = ();
my @usg_UniqOptName = ();


############
#
# Functions
#
############


#
# Prototypes
#

sub usage_builder(\@;\%@);

#
# Usage & Options Processing
#

sub usage {
    my %documented_opts = ("help"=>1, "verbose"=>1, "man"=>1);
    my @documented_variants = ("help|h", "verbose|v", "man",
                               # Others...
                              );

    # Add to the global %usg_* maps:
    usage_builder(@documented_variants, %documented_opts);

    # The Usage Proper.

    print "usage: $_MyName <Options> ...\n";

    print <<EOF; # Usage as here-doc.
    Options:

    $usg_OptNames{"help"}:
        This message.
        $usg_DefaultVals{"help"}
    $usg_OptNames{"verbose"}:
        Makes $_MyName noiser about what it\'s doing.
        $usg_DefaultVals{"verbose"}
    $usg_OptNames{"man"}:
        Print out the internal manual.  Read it for full details of how to use
        $_MyName.
    $usg_OptNames{"otheropts"}:
        Boilerplate for documenting other opts.
        $usg_DefaultVals{"otheropts"}

    Parameters:

    <Describe further.>

Rerun using the "--man" option for a full description of the Options and
Parameters that $_MyName uses.
EOF
    1;
    exit 1;
}


sub usage_builder(\@;\%@) {
    # Calltype #1:  Make sure all options documented in usage() have entries
    # in the %usg_* maps.
    if (scalar(@_) < 2) {
        my $ref_documented_opts = shift();

        foreach my $opt (@$ref_documented_opts) {
            unless (defined($usg_DefaultVals{$opt})) {
                $usg_DefaultVals{$opt} = '';
            }
            unless (defined($usg_OptNames{$opt})) {
                $usg_OptNames{$opt} = "--$opt";
            }
        }
        return;
    } # else

    # Calltype #2: Build the %usg_* maps.
    my $ref_valid_opts = shift();
    my $ref_optmap = shift();
    my @optname_hasdefl = @_;

    # Default vals.
    # 
    foreach (@optname_hasdefl) {
        next unless (defined($ref_optmap->{$_}));
        $usg_DefaultVals{$_} = "Default: \"";
        if (ref($ref_optmap->{$_})) {
            $usg_DefaultVals{$_} .= ${$ref_optmap->{$_}};
        } else {
            $usg_DefaultVals{$_} .= $ref_optmap->{$_};
        }
        $usg_DefaultVals{$_} .= "\"\n";
    }

    # Alternate names
    #
    my %cannonical_names = ();
    @cannonical_names{keys(%$ref_optmap)} = ();
    foreach (@$ref_valid_opts) {
        my $opt = $_; # This prevents the elements of @valid_opts from being
                      # modified. 
        $opt =~ s/=[^=]+$//;
        my @alts = ();
        my $cannonical='';
        foreach my $alt (split(/\|/, $opt)) {
            if (defined($ref_optmap->{$alt})) {
                $cannonical = $alt;
                delete $cannonical_names{$cannonical};
            } else {
                push (@alts, $alt);
            }
        }
        my $names_string = "--" . join("\n    --", sort(@alts), $cannonical);
        $names_string =~ s/--(\w\n)/-$1/g;
        $usg_OptNames{$cannonical} = $names_string;
    }
    @usg_UniqOptName = keys(%cannonical_names);
}


sub process_options($\%@) {
    my $argc = shift;
    my $ref_optmap = shift;
    my @valid_opts = @_;

    # Internal Defaults
    #
    my $help = 0;
    $ref_optmap->{'help'} = \$help;
    push(@valid_opts, "help|h");
    $ref_optmap->{'verbose'} = \$_Verbose;
    # Append a '+' for multiple verbosity levels
    push(@valid_opts, "verbose|v");
    $ref_optmap->{'man'} = 0;
    push(@valid_opts, "man");
    $ref_optmap->{'unit_test'} = \$_UnitTest;
    push(@valid_opts, "unit_test|unitTest");

    # Preparse checks.
    # 
    #if ($argc < 1) {
    #    usage;
    #}

    unless (scalar(@usg_UniqOptName)) {
        @usg_UniqOptName = keys(%$ref_optmap);
    }
    @valid_opts = sort(@valid_opts, @usg_UniqOptName);

    # Parse the commandline
    #
    unless (GetOptions($ref_optmap, @valid_opts)) {
        print "Invalid commandline.\n";
        usage;
    }
    if ($help) {
        usage;
    }

    # Let's have a looksie at the options before proceeding.
    if ($_UnitTest) {
#        print_hash "optmap", %$ref_optmap;
    }

    # Special Unit Testing Options.  They run their appointed tests, then
    # exit. 
    #
    if ($_UnitTest) {
        # Do unit testing here.
        1;
    } #end if(unit test)

    # Just check and see "--man" was there.  Otherwise, we have to wait
    # until we read & merge in the configfile before validating anything.
    if ($ref_optmap->{"man"}) {
        exec "perldoc", "-F", "$0";
    }

    # Additional processing goes here
    # :
    # :
}


#
# Other Functions
#



############
#
# Main
#
############


sub main {
    # my $optvars
    # ...go here, along with their defaults, if any.

    my %optmap=(#'optvar' => \$optvar,
                # Keep the variables and cannonical options the same.
                );
    my @optspec=(# Reminders:
                 # elt . "=i" => integer arg required.
                 # elt . "=s" => string arg required.
                 # Each ''elt'' is a '|'-separated list of option aliases,
                 # starting with the cannonical one.
                 );

    # Document the options.
    usage_builder(@optspec, %optmap,
                  # Options with predefined defaults get listed here:
                  # (the cannonical name, not the default value).
                  # 'eg_1', 'eg_2'
                  );

    # Process options.
    process_options(scalar(@ARGV), %optmap, @optspec);
}


main;
exit 0;
## POD STARTS HERE ##
__END__

=head1 NAME

>>xMYNAMEx<< - >>xMYDESCRx<<

=head1 SYNOPSIS

=over 0

=item >>xMYNAMEx<< I<Options> {I<Param>} [{I<Param>} ...]

=back

=head1 DESCRIPTION

<General description goes here.>

=head1 Commandline Options

=over 2

=item --option-in-cannonical-form I<any_args>

Description Goes Here.

=back

=head1 Positional Parameters

=over 2

=item * I<item_name>

Description Goes Here.

=back

=cut


#################
# Local Variables:
# coding: utf-8-unix
# End:
