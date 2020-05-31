#!/bin/perl
#



open F, "<", "../test/generated/sizes.txt";

my $h;
map { /(.*):(.*)/; $h->{$1} = $2 } <F>;

use Data::Dumper::Simple;

print Dumper( $h );





