#!/bin/perl 
## template.pl [-insert] templatefile template-tagpraefix [file to insert]
## 
## Opens a template (param1), 
## and fills in at the location of "param2" 
## (between the lines containing "param2-start: TMPL" and
##  "param2-end: TMPL")
## the contents of either the file, submitted in "param3",
## or the data received in stdio.
##

BEGIN{
		use File::Basename;
		($name,$path,$suffix) = fileparse ($0);
		push @INC, "$path";
}

require "template.pm";
require "ansicolors.pm";



my $fn = shift;
my $insert = 0;
if ( $fn eq "-insert" ){
		$insert = 1;
		$fn = shift;
}

if ( !-e $fn ){
		die "No such file: $fn\n";
}

my $tmplpraefix = shift;

my $success = 0;

my $INPUTFH;

if ( my $inf = shift ){
		open $INPUTFH, "<", $inf or die "Couldn't open $inf for reading\n";
} else {
		$INPUTFH = *STDIN;
		#open $INPUTFH, "<", *STDIO;
}


sub handler{
		my $F = shift;
		$success = 1;
		print $F $_ while ( <$INPUTFH> ); 
		return(1);
}

print("fn: $fn\npraefix: $tmplpraefix\n");

template( $fn, $tmplpraefix, { TMPL=>\&handler }, $insert );


if ( !$success ){
		print STDERR $RED."Warning: Couldn't find \"$tmplpraefix-start: TMPL\" within $fn\n";
		exit(1);
}
exit(0);


