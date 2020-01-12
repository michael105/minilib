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
		print "ccomp: $c   -".ord(substr($kk,0,1))."-".ord(substr($kk,1,1)) ."-    x".ord($token)."\n";
	 #if ( $c<=2 ){
	 #		return($s,$c);
	 #}
	 my $p=0;
	 while( ($p=index($s,$kk,$p))!=-1 ){
			 substr($s,$p,2)=$token;
	 }
	 $dt.=$kk;
	 #print $s;
		return( $s, $c );

}

print "len: ", length($in),"\n";

my $z = 255;
for my $a ( 128..$z ){
		($in,$c) = comp( 2, chr($a), $in );
}
#for my $a ( $z+1..244 ){
#		($in,$c) = comp( 2, chr($a), $in );
#}


print "len: ", length($in),"\n";


#for my $a ( 0..8,11..31 ){
#			($in,$c) = comp( 4, chr($a), $in );
#}

print "len: ", length($in),"\n";


open F, ">", "compr2.cm";
print F $dt;
print F $in;
close F;
