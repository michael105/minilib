#!/bin/perl -w

BEGIN {
		push @INC, "../scripts/perl";
}
use Data::Dumper::Simple;


open A,"<","minilib-api.ref";

my $api;
my $categorized;
my $cat = 'unsorted';

foreach my $l ( <A> ){
		if ( $l =~ /^#(.*)$/ ){
				$cat = $1;
				next;
		}
		my $h;
		if ( $l =~ /^f:(.*?)\|/ ){
				my $f = $1;
				if ( ($l =~ /\|c:(.*?)\|/) && ( $1 ne "unsorted") && ( $1 ne "u" ) ){
						$api->{$f}->{c} = $1;
						$categorized->{$1}->{$f} = 1;
				} else {
						$api->{$f}->{c} = $cat;
						$categorized->{$cat}->{$f} = 1;
				}
				if ( $l =~ /\|D:(.*?)/ ){
						$api->{$f}->{D} = $1;
				}

		}
}
close A;
print Dumper($api);
print Dumper($categorized);


open F,"<","minilib-api.in";

my $funcs;

foreach my $l ( <F> ){
		$l=~/^(.).(.*?)\|/;
		my $f = $2;
		print $2,"\n";
		my $h;
		foreach my $m ( qw/S D d l m o/ ){
				$l=~/\|$m:(.*?)\|/;
			if (defined($1) && $1 ne "f" ){
					$h->{$m} = $1;
					$api->{$f}->{$m} = $1;
			} 

		}
		$l=~/\|c:(.*?)\|/; # todo: tag in genheaders.pl
			if (defined($1) && $1 ne "f" ){
					$h->{c} = $1;
					$api->{$f}->{c} = $1;
					if ( exists( $categorized->{unsorted}->{$f} ) ){
							delete $categorized->{unsorted}->{$f};
					}
					$categorized->{$1}->{$f} = 1;
			} else {
					if ( !exists( $api->{$f}->{c} ) ){
							$categorized->{unsorted}->{$f} = 1;
							$api->{$f}->{c} = "unsorted";
					}
			}


		$funcs->{$f} = $h;
}

print Dumper($funcs);
close F;
print Dumper($api);
print Dumper($categorized);

sub stripdesc{
		my $d = shift;
		 $d=~s/.*\\- //; 
		 $d=~s/\n.SH.*//;
		 $d=~s/\\\n//g;
		 $d=~s/\n.*//g;
		 return $d;
 }

open A,">","minilib-api.ref.2";

foreach my $cat ( sort(keys(%{$categorized}))){
		print A "\n#$cat\n\n";
		foreach my $f ( sort( keys(%{$categorized->{$cat}}) ) ) {
				my $desc = "";
				my $fn = $f;
				$fn =~ s/^ksys_//;
				my $mp = `man -w 3p $fn`;
				if ( $mp ){
						chomp $mp;
						my $tmp = "\\\(em";
						$desc = `bunzip2 -c $mp | grep 'SH NAME' -A 3 | sed -E '/$tmp/!d'`;
						$desc =~ s/.*\\\(em\s*//;
				} else {
						$mp = `man -w 3 $fn`;
						if ( $mp ){
								chomp $mp;
								$desc = ` bunzip2 -c $mp | grep 'SH NAME' -A 3 | sed '1d'`;
								$desc = stripdesc($desc);
						} else {
								$mp = `man -w 2 $fn`;
								if ( $mp ){
										chomp $mp;
										$desc = ` bunzip2 -c $mp | grep 'SH NAME' -A 3 | sed '1d'`;
										$desc = stripdesc($desc);
								} else {
										print "no manpage for $f\n";
								}
						}
				}
				chomp $desc;
				print A "f:$f|D:$api->{$f}->{D}|c:$api->{$f}->{c}|x:$desc|\n";
				print "f: $f  desc: $desc\n";
		}
}
close A;








