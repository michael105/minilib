#!/bin/perl



my %c;
my $s="";

while(my $l = <>){
		$s.=$l;
		foreach my $k ( split("",$l) ){
				$c{ord($k)}++;
		}
}


print "chars:\n";
my @ar = sort( { $c{$a} <=> $c{$b} } keys(%c) );

my $diff = 0;

foreach my $w ( @ar ){
		printf "%3d  -",$w;
		if($w>21 && $w<127 ){
				print chr($w)."-  ";
		} else {
				print " -  ";
		}
		print "$c{$w}\n";
		$diff++;
}
print "*************\n";

foreach my $w ( sort( { $a<=> $b }  keys(%c)) ){
		printf "%3d   -",$w;
		if($w>21 && $w<127 ){
				print chr($w)."-  ";
		} else {
				print " -  ";
		}
		print "$c{$w}\n";
}
print "Different chars: $diff\n";
print "free:"; 
my $free=0;
for ( 0..255 ){
		if ( !defined($c{$_}) ){
				print " $_,";
				$free++;
		}
}
print " ($free)\n";
my $len = 4;
my %tupels;
for my $a ( 0..(length($s)-$len )){
		#print substr( $w, $a, 2 ),"\n";
		$tupels{substr( $s, $a, $len )}++;
}
my $bytes = 0;
my $saved = 0;
my $tablecount = 0;
my $a = 65;
my $b = 65;

print "length s: ",length($s),"\n";
map { 
		my $k = $_; 
		#		print "$tupels{$k}: $k\n"; 
		$bytes+=$tupels{$k};
		if ( $tupels{$k} > $len ){
				$saved += $tupels{$k} *($len-2) -$len;
		
				$tablecount++;
		
		#		print "$k\n";
	my $c = chr($a).chr($b++);
	if ( $b>125 ){
			$a++;
			$b=65;
	}
	$k=~s/(\W)/\\$1/g;

	$s=~s/$k/$c/g;
	}
} sort( { $tupels{$a} <=> $tupels{$b} } keys(%tupels) );

print "\nbytes: $bytes\nSaved: $saved\nTablecount: $tablecount\n";


#open F, ">","z.z4";

print "length s: ",length($s),"\n";



