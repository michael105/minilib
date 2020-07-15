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



open A,">","minilib-api.ref";

foreach my $cat ( sort(keys(%{$categorized}))){
		print A "\n#$cat\n\n";
		foreach my $f ( sort( keys(%{$categorized->{$cat}}) ) ) {
				my $desc = "";
				my $mp = `man -w 3p $f`;
				if ( $mp ){
						chomp $mp;
						$desc = `bunzip2 -c $mp | grep NAME -A 2 | sed -E '1,2d; s/\\\(em\s*(.*)$/\1/'`;
				} else {
						$mp = `man -w 3 $f`;
						if ( $mp ){
								chomp $mp;
								$desc = ` bunzip2 -c $mp | grep NAME -A 1 | sed -E '1d; s/.*-\s*(.*)$/\1/'`;
						} else {
								$mp = `man -w 2 $f`;
								if ( $mp ){
										chomp $mp;
										$desc = ` bunzip2 -c $mp | grep NAME -A 1 | sed -E '1d; s/.*-\s*(.*)$/\1/'`;
								} else {
										print "no manpage for $f\n";
								}
						}
				}

				print A "f:$f|D:$api->{$f}->{D}|c:$api->{$f}->{c}|\n";
				print "f: $f  desc: $desc\n";
		}
}
close A;








