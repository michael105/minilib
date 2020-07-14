#!/bin/perl -w




while (my $l = <>){
		if ( $l =~ /^#if 0/ ){
				my $c=1;
				do {
						$l=<>;
						if ( $l =~ /^#endif/ ){
								$c--;
						} elsif ( $l=~ /^#if/ ) {
								$c++;
						}
				} while ( $c > 0 );
		} else {
				print $l;
		}
}


