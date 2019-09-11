#!/bin/perl




my $hlp = <<HLP;
comptxt.pl infile outfile

HLP

my @in;

if ( $ARGV[0] eq '-' ){
		@in = <>;
} else {
		open F, "<", $ARGV[0] or die "Couldn't open: $infile\n";
		@in = <F>;
		close F;
}

sub arrlen{
		my $len = 0;
		map { $len += length($_) } @_;
		return($len);
}

print "Bytes in: ",arrlen(@in),"\n";

map { chomp } @in;
#print @in;


my %h;
my $words = 0;
my $spaces = 0;

foreach my $l ( @in ){
		foreach my $w ( split (" ", $l ) ){
				#$h{$w} ++ ;
				$words++;
				$w=~s/^(.)//;
				$w=lc($1).$w;
				#print "w:$w\n";
				#if ( !exists( $h{$w} )){
				#		$c++;
				#		$h{$w} = $c;
				#}
				$h{$w}++;
				$spaces++;
		}
		$spaces--;
}


my $cp="";
my @cpindex;
my @cpwords;
my $dt="";

my $c=0;
foreach my $k ( keys(%h) ){
		$c++;
		$h{$k} = $c;
		push @cpwords, $k;
}

#@cpwords = join("\n",@cpwords) ;
#print $cpwords[0],"\n","XXXXXYYYYY\n";
print "Words: $words\nSpaces: $spaces\nDifferent words: ".keys(%h)." ($c)\n";
#print join("\n", @cpwords),"\n";
print "Bytes wordtable: ",arrlen(@cpwords),"\n";

my $ccount;
foreach $n ( 128..255 ){
		my %tupels;

		foreach my $w ( @cpwords ){
				for my $a ( 0..(length($w)-2 )){
						$tupels{substr( $w, $a, 2 )}++;
				}
		}

		$c = 0;
		my $kk = "";

		foreach my $k ( keys(%tupels) ){
				if ( $tupels{$k} > $c ){
						$c = $tupels{$k};
						$kk = $k;
				}
		}
	 	#print "ccomp: $c   -$kk-    x $n\n";
		if ( $c<=2 ){
				$ccount = $n-129;
				last;
		}
		$k1=substr( $kk, 0, 1 );
	 	$k2=substr( $kk, 1, 1 );
		my $to = chr( $n );
	 
	 	map { s/[$k1][$k2]/$to/g } @cpwords;
	 	$dt.=$kk;
}

print "Compressed wordtable: ",arrlen(@cpwords),"\n";
print "Size charlist: ", $ccount*2,"\n";



open F, ">", $ARGV[1] or die "Coduln't open $ARGV[1] for writing";

print F chr(length($dt));

print F $dt;

push @cpwords, "";
for (my $a=0; $a<=@cpwords; $a+=2) {
		print F chr((length($cpwords[$a])<<4 & length($cpwords[$a+1])) );
}
#print F chr(255);

print F @cpwords;

push @in, "";

for (my $a=0; $a<=@in; $a+=2) {
		print F chr((split(" ",($in[$a]))<<4) & split(" ",$in[$a+1]) );
}

foreach my $l ( @in ){
		foreach my $w ( split (" ", $l ) ){
				print F chr($h{$w});
		}
}
close F;
	
