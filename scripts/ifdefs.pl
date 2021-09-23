#!/bin/perl
# show #if and #else / #endif definitions within
# a c source file (arg1), with according
# linenumbers and depth of nesting.
# (Did need it for debugging)





my $ln = 0;
my $ifs = 0;

open F, $ARGV[0];


while ( my $l = <F> ){
	$ln++;
	#print "$ln: $l";
	if ( $l =~ /^#if/ ){
		$ifs++;
		print "$ifs: $ln : $l";
	} elsif ( $l =~ /^#endif/ ){
		print "$ifs: $ln : $l";
		$ifs--;
	} elsif ( $l =~ /^#else/ ){
		print "$ifs: $ln : $l";
	}



}



