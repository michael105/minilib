#!/bin/perl -w

BEGIN {
		$MLDIR="..";
		push @INC, "$MLDIR/scripts/perl";
}
use Data::Dumper::Simple;


open A,"<","$MLDIR/doc/build/minilib-reference.sortme.1";

my $api;
my $categorized;
my $cat = 'unsorted';

# read the infile(s)
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
				if ( $l =~ /\|D:(.*?)\|/ ){
						$api->{$f}->{D} = $1;
				}
				if ( $l =~ /\|x:(.*?)\|/ ){
						$api->{$f}->{x} = $1;
				}


		}
}
close A;
print Dumper($api);
print Dumper($categorized);


open F,"<","$MLDIR/doc/build/minilib-reference.in";

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

my $tr = `cat $MLDIR/test/generated/sizeoftrue.txt`;
$tr -= 32;
open A,"<","$MLDIR/test/generated/sizes.txt";
my $sizes;
foreach my $l( <A> ){
		$l=~/(.*?):(\d*)/;
		$sizes->{$1}=$2-$tr;
}
close A;

sub stripdesc{
		my $d = shift;
		 $d=~s/.*\\- //; 
		 $d=~s/\n.SH.*//;
		 $d=~s/\\\n//g;
		 $d=~s/\n.*//g;
		 return $d;
 }

sub print2{
		my $F =shift;
		my $F2 =shift;
		print $F @_;
		print $F2 @_;
}

# write docu
open A,">","$MLDIR/doc/build/minilib-reference.in.2";
system("cp $MLDIR/doc/templates/configuration.asc reference/configuration.asc");
system("cp $MLDIR/doc/templates/minilib-reference.asc.top minilib-reference.asc");
system("cat $MLDIR/doc/templates/configuration.asc >> minilib-reference.asc");
system("cp $MLDIR/doc/templates/reference-index.asc.top reference/index.asc");
open B, ">>", "$MLDIR/doc/minilib-reference.asc";

open INDEX, ">>", "$MLDIR/doc/reference/index.asc";

foreach my $cat ( sort(keys(%{$categorized}))){
		print INDEX "\n\n=== link:$cat.asc[$cat]\n\n";
		open CAT, ">","$MLDIR/doc/reference/$cat.asc"; 
		print A "\n#$cat\n\n";
		print B "\n\n\n\n---\n\n== $cat\n\n";
		print CAT "== $cat\n\n";

		if ( -e "$MLDIR/doc/templates/$cat.asc.in" ){
				open F, "<", "$MLDIR/doc/templates/$cat.asc.in";
				print CAT $_ while(<F>);
				close F;
		}

		#print B "-" for ( 0.. length($cat)+1 );
		# print B "\n";

		# Iterate over functions of the curent categorie
		foreach my $f ( sort( keys(%{$categorized->{$cat}}) ) ) {
				my $desc = "";
				my $fn = $f;
				$fn =~ s/^sys_//;
				if ( !exists( $api->{$f}->{x} ) ){
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
				} else {
						$desc = $api->{$f}->{x};
				}
				chomp $desc;
				$api->{$f}->{D} =~ s/\s*$//;
				$api->{$f}->{D} =~ s/;$//;
				$api->{$f}->{D} =~ s/static//;
				$api->{$f}->{D} =~ s/inline//;
				$api->{$f}->{D} =~ s/__attribute.*\)\)//;
				$api->{$f}->{D} =~ s/^\s*//;
				$f =~ s/\s*$//;

				print A "f:$f|D:$api->{$f}->{D}|c:$api->{$f}->{c}|x:$desc|\n";
				if ( exists(  $api->{$f}->{o} ) ){
						$api->{$f}->{o} =~ s/:\+:/\n/g;
						#$api->{$f}->{o} =~ s/:\+:/ + \n /g;
				}
				print2( B,CAT, "\n\n[[$f]]\n$f"."::\n\n  _$api->{$f}->{D}_ + \n".
						($api->{$f}->{d}? " *Defines:* $api->{$f}->{d} + \n" :"").
						($desc?" *$desc*\n":"").(  $api->{$f}->{o}?"-----\n$api->{$f}->{o}\n-----\n":"") . 
						($sizes->{$f}? "Size: ~$sizes->{$f}B ":"").
						($api->{$f}->{l}? "link:$api->{$f}->{l} " :"").
						($api->{$f}->{m}? "manpage: link:$api->{$f}->{m} +\n" :""));

				print INDEX "link:$cat.asc#$f\[$f\] ";
				if ( 0 ){
					print2( B,CAT, "\n\n$f"."::\n\n  _$api->{$f}->{D}_ + \n ".($api->{$f}->{d}? " Defines: $api->{$f}->{d} + \n" :"").
						($desc?" $desc +\n":"").(  $api->{$f}->{o}?" $api->{$f}->{o} +\n ":"") . 
						($sizes->{$f}? "Size: ~$sizes->{$f}B ":"").
						($api->{$f}->{l}? "link:$api->{$f}->{l} " :"").
						($api->{$f}->{m}? "manpage: link:$api->{$f}->{m} +\n" :""));
				}
	
				print "f: $f  desc: $desc\n";
		}
		print INDEX "\n";
		close CAT;
}
close A;
close B;
close INDEX;

system("cat $MLDIR/doc/templates/reference-index.asc.bottom >> reference/index.asc");





