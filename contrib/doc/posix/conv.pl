#!/bin/perl -w
#
#



my $header;
my $function;

while ( my $l = <> ){
		if ( $l =~ /(\S*\.h)/ ){
				$h = $1;
		} else {
				if ( $l =~ /\s\s\s\s(\S*)/ ){
						my $f = $1;
						push @{$header->{$h}}, $f;
						$function->{$f}->{header} = $h;
						$function->{$f}->{desc} = "";
						while ( ($l = <> ) && ( $l=~/\s\s\s\s(\S.*)/ )){
								my $m = $1;
								$m =~ s/\<.*\>//;
								$function->{$f}->{desc} .= "$m ";
						}
				}
		}
}


use Data::Dumper::Simple;


print Dumper ($header);
print Dumper ($function);





