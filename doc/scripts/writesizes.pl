#!/bin/perl
#

BEGIN {
		$MLDIR="../..";
		push @INC, "$MLDIR/scripts/perl";
}



open F, "<", "$MLDIR/test/generated/sizes.txt";

my $h;
map { /(.*):(.*)/; $h->{$1} = $2 } <F>;

use Data::Dumper::Simple;

print Dumper( $h );





