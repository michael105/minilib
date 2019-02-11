#!/usr/bin/perl -w
# TODO: #ifdef inclusion
#exit 0;

my $i = $ARGV[0];
#$i =~ /(.*)\.asm$/;
#my $o = "$1.c" or die "No input file?";
my $o = $ARGV[1];

print "Convert $i to $o\n";

open I,"<$i";
open O,">$o";
my @a;

push @a, "__asm__ volatile (\n";
my %symbols;

while ( my $l = <I> ){
	chomp $l;
	$l =~ s/^\s*//;
	$l =~ s/\s*\#.*$//;
	next if ( !($l =~ /\S\S/ ) );
	if ( $l =~ /.global (\S*)/ ){
		unshift @a, "void $1(){\n";
		$symbols{$1} = 1;
	} else{
		if ( !(($l =~ /(\S*):/ ) && exists($symbols{$1}) ) ){
			if ( $l =~ /^#/ ){
				push @a, $l."\n";
			} else {
				push @a, "\t\t".'"'.$l.'\n\t"'."\n";
			}
		}
	}
}
push @a, "\t);\n};";


print O @a,"\n";

close O;
close I;
