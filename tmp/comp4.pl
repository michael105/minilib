#!/bin/perl
#

my $in="";

while (<>){
		$in .= $_;
}

#use Data::Dumper::Simple;

my $dt = "";

sub comp{
		my $len = shift;
		my $token = shift;
		my $s = shift;

		my %tupels;
				for my $a ( 0..(length($s)-$len )){
						#print substr( $w, $a, 2 ),"\n";
						$tupels{substr( $s, $a, $len )}++;

				}
				#	 	print Dumper( %tupels );
		my $c = 0;
		my $kk = "";

		foreach my $k ( keys(%tupels) ){
				#if ( (length( $k ) <$len) || ( $k =~ /\[|\)|\(|\]|\{|\}/ ) ){
				if ( (length( $k ) <$len)  ){
						next;
				}
				if ( $tupels{$k} > $c ){
						$c = $tupels{$k};
						$kk = $k;
				}
		}
		#$kk=~s/(\W)/\\$1/g;
		my $kn=$kk;
		$kk="";
		map { $kk.="[$_]" } split("", $kn);
			print "ccomp: $c   -$kk-    x$token\n";
	 #	print "   ", ord(substr($kk,0,1) ), " - ", ord(substr($kk,1,1) ),"\n";
		if ( $c<=$len ){
				return($s,$c);
		}
 
	 $s =~ s/$kk/$token/g;
	 $dt.=$kk;
	 #print $s;
		return( $s, $c );

}

print "len: ", length($in),"\n";

my $z = 255;
for my $a ( 128..$z ){
		($in,$c) = comp( 2, chr($a), $in );
}

print "len: ", length($in),"\n";

for my $a ( ($z+1)..255 ){
		for my $b(1..255){
				#print "b:$b\n";
				($in,$c) = comp( 3, chr($a).chr($b), $in );
				if ( $c<=3 ){
						print "Stop.\na:$a, b:$b\n";
						goto outA;
				}
		}
}

outA:
print "len: ", length($in),"\n";


open F, ">", "compr2.cm";
print F $dt;
print F $in;
close F;
