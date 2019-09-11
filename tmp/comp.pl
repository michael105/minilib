#!/bin/perl



my @f;

while ( <> ){
		chomp;
		my $s = $_;
		$s =~ s/"//g;
		$s =~ s/,//g;
		$s =~ s/^\s*//;
		$s =~ s/\s*$//;
		$s =~ /^(.)/;
		my $c= lc($1);
		#$s=~ s/^./$c/;
		push @f, $s;
}


use Data::Dumper::Simple;

#goto LABEL;
#print Dumper( @f );

my %h;

my $words = 0;
my $spaces = 0;

foreach my $l ( @f ){
			foreach my $w ( split (" ", $l ) ){
					#$h{$w} ++ ;
					$words++;
					$h{lc($w)} ++ ;
					$spaces++;
			}
			$spaces--;
	}


#print Dumper(%h);

my $n = 1;
my $w2 = 0;
my $w2len = 0;

foreach my $w ( sort {$h{$a} <=> $h{$b}} keys(%h) ){
		#print "$w\n";
		print "$h{$w}: $w\n";
		$h->{$w} = $n;
		$n++;
		if ( $h{$w} >= 2 ){
				$w2++;
				$w2len += ( ($h{$w} -1) * length( $w ) );
		}
		#$a+=$h{$w} if ( $h{$w} > 2 );
}

print "\n";
print "Words: $words\n";
print "Different words: $n\n";
print "More than once: $w2\n";
print "Bytes less: $w2len\n";
print "Spaces: $spaces\n";

print "\n";

use List::Util qw/min max/;

my %trippels;

my $nt = "";

foreach my $w ( keys(%h) ){
		for my $a ( 0..(length($w)-3 )){
				#print substr( $w, $a, 2 ),"\n";
				$trippels{substr( $w, $a, 3 )}++;
	
}
}

foreach my $k (sort {$trippels{$a} <=> $trippels{$b} } keys(%trippels)){
		print "$trippels{$k}: $k\n";
}

sub two{
		my $token = shift;

		my %pairs;
		foreach my $w ( @_ ){
				for my $a ( 0..(length($w)-2 )){
						#print substr( $w, $a, 2 ),"\n";
						$pairs{substr( $w, $a, 2 )}++;

				}
		}
		my $c = 0;
		my $kk = "";

		foreach my $k ( keys(%pairs) ){
				if ( $pairs{$k} > $c ){
						$c = $pairs{$k};
						$kk = $k;
				}
		}
		print "c: $c   $kk\n";
		if ( $c<=2 ){
				return(@_);
		}

		return ( map { $s=$_; $s=~s/$kk/$token/g; $s; } @_  );

}


sub comp{
		my $len = shift;
		my $token = shift;
		my $arr = shift;

		my %tupels;
		foreach my $w ( @{$arr} ){
				for my $a ( 0..(length($w)-$len )){
						#print substr( $w, $a, 2 ),"\n";
						$tupels{substr( $w, $a, $len )}++;

				}
		}
		#print Dumper( %tupels );
		my $c = 0;
		my $kk = "";

		foreach my $k ( keys(%tupels) ){
				if ( (length( $k ) <$len) || ( $k =~ /\[|\)|\(|\]|\{|\}/ ) ){
						next;
				}
				if ( $tupels{$k} > $c ){
						$c = $tupels{$k};
						$kk = $k;
				}
		}
			print "ccomp: $c   -$kk-\n";
	 #	print "   ", ord(substr($kk,0,1) ), " - ", ord(substr($kk,1,1) ),"\n";
		if ( $c<=2 ){
				return($arr,$c);
		}

	 #	my @ar = map { $_=~s/$kk/$token/g; } @{$arr};
		my @ar = map { my $s=$_; $s=~s/$kk/$token/g; $s; } @{$arr};
		return( \@ar, $c );

}


sub arrlen{
		my $l=0;
		map{ $l+=length($_) } @_;
		print "l: $l\n";
}

arrlen( keys(%h) );
arrlen( @f );

my @dwords = two( 'A', @f );
my $cwords, $count;
foreach my $ab ( 6..30 ){
		print "a: $ab\n";
		#	($cwords,$count) = comp( $ab, 'A', \@f );
}
my @rr = keys(%h);
#($cwords,$count) = comp( 2, 'A', \@f );
$cwords = \@f;
	
#exit 0;
#my @cwords = two( 'A', keys(%h) );
LABEL:
print join ("\n", @f );
print join ("\n", @{$cwords} );
print "\n\nXXXXXX\n";
arrlen( @f );
arrlen( @dwords );
arrlen( @{$cwords} );
#exit 0;
#my @cwords = two( 'A', @f );
#print join ("\n", @cwords );
my $z = 127;
for my $c ( 128 .. $z ){
		#($cwords, $count) = comp( 3, chr($c), $cwords );
}

for my $c ( ($z+1)..255 ){
		($cwords, $count) = comp( 2, chr($c), $cwords );
		if ($count <3 ){
				print "Breaking. c: $c\n";
				last;
		}
}


for my $c ( 1..31 ){
		#		($cwords, $count) = comp( 2, chr($c), $cwords );
}


arrlen @{$cwords};

open F, ">", "compressed.cm";
print F join("\n", @{$cwords} );

#perprint Dumper( @cwords );

#print join ("\n", @$cwords );

exit 0;

print 'char *words[] = { "", "', join('","', keys(%h) ), '" };', "\n";


exit 0;



print "char *comp[] = {\n  { 0x0 },\n";
foreach my $l ( @f ){
		print "  { ";
		foreach my $w( split (" ", lc($l) )){
				printf "0x%X, ",$h->{$w};
		}
		print "0x0 },\n";
}
			
print "  { 0x0 } };\n";






