##args: 
## file: filename
## tmplpraefix: Name of the tmpl ( "name"-start and "name"-end )
## handler: ref to hash, { "tmplname"=>sub }
##   if the handler doesn't return 1, parsing is aborted
sub template{
		my $fn = shift;
		my $tmplpraefix = shift;
		my $handler = shift;


		open FH2 , "<", "$fn" or die;#return(0);


		open TMP, "+>", "$fn.tmp" or return(0);
	
		while ( (my $l = <FH2>) ){
				print TMP $l;
				if ( $l =~ /$tmplpraefix-start: (\S*)/ ){
						my $m = $1;
						if ( exists($handler->{$m}) ){
								if ( ! (&{$handler->{$m}}( TMP ) )){
										print "handler ret != 0\n";
										return(0);
								}
						} else {
								print "no handler for $m\nin file $fn, line: $ln\n";
								return(0);
						}
						while ( ($l = <FH2>) && !( $l =~ /$tmplpraefix-end: (\S*)/ )){};
						$l =~ /$tmplpraefix-end: (\S*)/;
						my $e=$1;
						print "e: $e      m: $m\n"; 
						if ( $m ne $e ){
								print "$tmplpraefix-end doesn't match.\n";
								return(0);
						}
						print TMP $l;
				}
		}
		seek(TMP,0,0);
		close FH2;
		open FH2 , ">", "$fn" or die;#return(0);
		print FH2 $l while ( $l=<TMP> );




		return(1);
}













1;

